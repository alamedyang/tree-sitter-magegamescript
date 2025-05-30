const {
	captureForFieldName,
	capturesForFieldName,
	textForFieldName,
	grammarTypeForFieldName,
 } = require('./parser-capture.js');
const {
	autoIdentifierName,
	expandCondition,
	label,
	gotoLabel,
	simpleBranchMaker,
	newSequence,
	newSerialDialog,
	showSerialDialog,
	newDialog,
	showDialog,
	newTemporary,
	dropTemporary,
	quickTemporary,
	latestTemporary,
} = require('./parser-utilities.js');
const {
	getBoolFieldForAction,
} = require('./parser-bytecode-info.js');

// Cyclic dependency bodge
let handleNode;
const handleActionsInit = (handleNodeFn) => {
	handleNode = handleNodeFn;
};

const opIntoStringMap = {
	'=': 'SET',
	'+': 'ADD',
	'-': 'SUB',
	'*': 'MUL',
	'/': 'DIV',
	'%': 'MOD',
	'?': 'RNG',
};

// ------------------------ INT EXPRESSIONS ------------------------ //

const flattenIntBinaryExpression = (exp, steps) => {
	const temporary = latestTemporary();
	const lhs = exp.lhs;
	const op = exp.op;
	const rhs = exp.rhs;
	if (typeof lhs === 'number') {
		steps.push(setVarToValue(temporary, lhs));
	} else if (lhs.entity) {
		steps.push(copyEntityFieldIntoVar(lhs.entity, lhs.field, temporary));
	} else if (lhs.mathlang === 'int_binary_expression') {
		// can use the same temporary since it's the lhs and we're going LTR
		// (and operator precedence is now baked into the AST)
		flattenIntBinaryExpression(lhs, steps);
	}
	if (typeof rhs === 'number') {
		steps.push(changeVarByValue(temporary, rhs, op))
	} else if (rhs.entity) {
		const temp = quickTemporary();
		steps.push(
			copyEntityFieldIntoVar(rhs.entity, rhs.field, temp),
			changeVarByVar(temporary, temp, op)
		);
	} else if (rhs.mathlang === 'int_binary_expression') {
		// this one DOES need a new temporary
		const innerTemporary = newTemporary();
		flattenIntBinaryExpression(rhs, steps);
		steps.push(changeVarByVar(temporary, innerTemporary, op));
		dropTemporary();
	}
	return steps;
};

// ------------------------ BOOL EXPRESSIONS ------------------------ //

const actionSetBoolMaker = (f, _rhsRaw, _lhs, backupNode) => {
	// get the action JSON for the LHS
	const lhs = typeof _lhs === 'string' ? setFlag(_lhs, true) : _lhs;
	const lhsParam = getBoolFieldForAction(lhs.action);
	if (typeof _rhsRaw === 'boolean') {
		lhs[lhsParam] = _rhsRaw;
		return lhs;
	}
	// get the action JSON for the RHS
	const rhsRaw = typeof _rhsRaw === 'string' ? checkFlag(_rhsRaw, true) : _rhsRaw;
	if (
		rhsRaw.mathlang === 'bool_getable'
		|| rhsRaw.mathlang === 'bool_comparison'
		|| rhsRaw.mathlang === 'string_checkable'
		|| rhsRaw.mathlang === 'number_checkable_equality'
	) {
		const rhsParam = getBoolFieldForAction(rhsRaw.action);
		const existingValue = rhsRaw[rhsParam];
		if (existingValue === undefined) throw new Error ("Found a hole! " + rhsRaw.action);
		const baseAction = {
			...rhsRaw,
			[rhsParam]: existingValue,
		};
		return simpleBranchMaker(
			f,
			rhsRaw.debug || backupNode,
			baseAction,
			{ ...lhs, [lhsParam]: true },
			{ ...lhs, [lhsParam]: false },
		)
	}
	// Everything hereafter is a bool expression (?)
	const setLhsIfTrue = typeof lhs === 'string'
		? setFlag(lhs, true)
		: { ...lhs, [lhsParam]: true };
	const setLhsIfFalse = typeof lhs === 'string'
		? setFlag(lhs, false)
		: { ...lhs, [lhsParam]: false };
	const ifLabel = `if true #${f.p.advanceGotoSuffix()}`;
	const rendezvousLabel = `rendezvous #${f.p.advanceGotoSuffix()}`;
	const steps = [
		...expandCondition(f, rhsRaw.debug, rhsRaw, ifLabel),
		setLhsIfFalse,
		gotoLabel(f, rhsRaw.debug, rendezvousLabel),
		label(f, rhsRaw.debug, ifLabel),
		setLhsIfTrue,
		label(f, rhsRaw.debug, rendezvousLabel),
	];
	return newSequence(f, rhsRaw.debug, steps, 'set bool on');
};

// ------------------------ COMMON ACTION HANDLING ------------------------ //

// Takes an object with simple values and an object with array values and "spreads" them --
// e.g. { a: b }, { c: [d,e] } -> [ {a:b, c:d}, {a:b, c:e} ]
const spreadValues = (f, commonFields, fieldsToSpread) => { // ->[]
	// count spreads
	let spreadSize = -Infinity;
	Object.values(fieldsToSpread).forEach(fieldName => {
		const len = fieldName.captures.length;
		// spreadSize won't be 1 btw, because 1s go to commonFields
		if (spreadSize === -Infinity) spreadSize = len;
		if (spreadSize !== len) {
			f.newError({
				locations: [{ node: fieldName.node }],
				message: `spreads must have the same count of items within a given action`,
			});
			spreadSize = Math.max(spreadSize, len);
		}
	});
	// if it's a single thing, pass it back whole
	if (spreadSize === -Infinity) {
		return [commonFields];
	}
	// but spread action into multiple variants
	let ret = [];
	for (let i = 0; i < spreadSize; i++) {
		const insert = { ...commonFields };
		Object.keys(fieldsToSpread).forEach(fieldName => {
			const allValues = fieldsToSpread[fieldName].captures;
			const currValue = allValues[i % allValues.length];
			insert[fieldName] = currValue;
		});
		ret.push(insert);
	}
	return ret;
};

// Takes an action node (from the TS parser) and gets associated "dictionary" data
// - Processes listed captures by field name
// - Spreads them if any of the captures are "expansions" (e.g. [a, b])
// - Once spread, the detective identifies the JSON action for each spread item (since they might be different from each toehr)
// - Adds the final JSON properties required by the encoder
// - If the result is more than one "step" (for sequences not directly supported by the engine)
// it will add the action as a "sequence", which will need to be expanded later
// (for a few reasons, the result must be a single "unit" at this stage)
// TODO: why then return an array?
const handleAction = (f, node) => { // ->[]
	// Cyclic dependency bodge
	if (!handleNode) {
		throw new Error("handleAction cannot be called until handleNode has been provided to the init function");
	}
	// From the action dictionary
	const data = actionData[node.grammarType];
	if (!data) {
		const customFn = actionFns[node.grammarType];
		if (!customFn) throw new Error(`No action data nor handler function found for action ${node.grammarType}`);
		return customFn(f, node);
	}
	let action = {
		debug: node,
		fileName: f.fileName,
		...data.values,
	};
	// Action params
	const captures = data.captures || [];
	const fieldsToSpread = {};
	captures.forEach(fieldName => {
		const capture = captureForFieldName(f, node, fieldName);
		if (capture === undefined) {
			if (data.optionalCaptures?.includes(fieldName)) {
				action[fieldName] = null;
			} else {
				throw new Error(`Capture found for field not associated with this action (${fieldName})`)
			}
			return;
		}
		if (!Array.isArray(capture)) {
			action[fieldName] = capture;
		} else {
			fieldsToSpread[fieldName] = {
				node: capture,
				captures: capture,
			};
		}
	});
	const spreads = spreadValues(f, action, fieldsToSpread);
	// Different param combinations will result in different actions,
	// so let the detective sort them out after the spreads are spread
	if (data.detective) {
		spreads.forEach((action, actionIndex) => {
			// Try the action detective
			for (let i = 0; i < data.detective.length; i++) {
				const currClueData = data.detective[i];
				const solved = currClueData.isMatch(action, f, node);
				if (solved) {
					// todo: reorder the arguments in .values()?
					const values = currClueData.finalizeValues(action, f, node, actionIndex);
					Object.entries(values)
						.forEach(([k, v]) => { action[k] = v; });
					return;
				}
			}
			// If we got here, nothing matched
			action.error = true;
			const errorFn = data.detectError;
			if (errorFn) {
				f.newError(errorFn(action));
			} else {
				f.newError({
					locations: [{ node }],
					message: `syntax error in action '${node.grammarType}'`
				});
				// console.warn(`No custom error handler found for action '${node.grammarType}' node`);
			}
		});
	}
	return spreads;
};

// Put things here if you don't care about auto-spreading them; otherwise they should go in actionData
const actionFns = {
	action_show_dialog: (f, node) => {
		const nameNode = node.childForFieldName('dialog_name');
		const name = nameNode ? nameNode.text : autoIdentifierName(f, node);
		const dialogs = (node.childrenForFieldName('dialog') || [])
			.map(child => handleNode(f, child))
			.flat();
		const ret = [ showDialog(f, node, name) ];
		if (dialogs.length) {
			ret.unshift(newDialog(f, node, name, dialogs));
		}
		return ret;
	},
	action_concat_serial_dialog: (f, node) => actionFns.action_show_serial_dialog(f, node, true),
	action_show_serial_dialog: (f, node, isConcat) => {
		const nameNode = node.childForFieldName('serial_dialog_name');
		const name = nameNode ? nameNode.text : autoIdentifierName(f, node);
		const serialDialogs = (node.childrenForFieldName('serial_dialog') || [])
			.map(child => handleNode(f, child))
			.flat();
		const ret = [ showSerialDialog(f, node, name, false) ];
		if (serialDialogs.length) {
			ret.unshift(newSerialDialog(f, node, name, serialDialogs[0]));
		}
		return ret;
	},
};

// TODO: why use an action detective? Why not put it all the logic and process values stuff in the same function?
const actionData = {
	action_return_statement: {
		// TODO: everything after is unreachable
		// Ditto some other actions, too
		values: { mathlang: 'return_statement' },
	},
	action_continue_statement: {
		values: { mathlang: 'continue_statement' },
	},
	action_break_statement: {
		values: { mathlang: 'break_statement' },
	},
	action_close_dialog: {
		values: { action: 'CLOSE_DIALOG' },
	},
	action_close_serial_dialog: {
		values: { action: 'CLOSE_SERIAL_DIALOG' },
	},
	action_save_slot: {
		values: { action: 'SLOT_SAVE' },
	},
	action_load_slot: {
		values: { action: 'SLOT_LOAD' },
		captures: ['slot'],
	},
	action_erase_slot: {
		values: { action: 'SLOT_ERASE' },
		captures: ['slot'],
	},
	action_load_map: {
		values: { action: 'LOAD_MAP' },
		captures: ['map'],
	},
	action_goto_label: {
		values: { mathlang: 'goto_label' },
		captures: ['label'],
	},
	action_goto_index: {
		values: { action: 'GOTO_ACTION_INDEX' },
		captures: ['action_index'],
	},
	action_run_script: {
		values: { action: 'RUN_SCRIPT' },
		captures: ['script'],
	},
	action_non_blocking_delay: {
		values: { action: 'NON_BLOCKING_DELAY' },
		captures: ['duration'],
	},
	action_blocking_delay: {
		values: { action: 'BLOCKING_DELAY' },
		captures: ['duration'],
	},
	action_delete_command: {
		values: { action: 'UNREGISTER_SERIAL_DIALOG_COMMAND' },
		captures: ['command'],
	},
	action_delete_command_arg: {
		values: { action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT' },
		captures: ['command', 'argument'],
	},
	action_delete_alias: {
		values: { action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS' },
		captures: ['alias'],
	},
	action_hide_command: {
		values: {
			action: 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY',
			is_visible: false,
		},
		captures: ['command'],
	},
	action_unhide_command: {
		values: {
			action: 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY',
			is_visible: true,
		},
		captures: ['command'],
	},
	action_camera_shake: {
		values: { action: 'SET_SCREEN_SHAKE' },
		captures: ['amplitude', 'distance', 'duration'],
	},
	action_camera_fade_in: {
		values: { action: 'SCREEN_FADE_IN' },
		captures: ['color', 'duration'],
	},
	action_camera_fade_out: {
		values: { action: 'SCREEN_FADE_OUT' },
		captures: ['color', 'duration'],
	},
	action_pause_script: {
		values: { action: 'SET_SCRIPT_PAUSE', bool_value: true },
		captures: ['script_slot', 'entity' ],
	},
	action_unpause_script: {
		values: { action: 'SET_SCRIPT_PAUSE', bool_value: false },
		captures: ['script_slot', 'entity' ],
	},
	action_play_entity_animation: {
		values: { action: 'PLAY_ENTITY_ANIMATION' },
		captures: ['entity', 'animation', 'count'],
	},
	action_set_warp_state: {
		values: { action: 'SET_WARP_STATE' },
		captures: [ 'string' ]
	},
	action_set_serial_connect: {
		values: { action: 'SET_CONNECT_SERIAL_DIALOG' },
		captures: [ 'serial_dialog' ]
	},
	action_set_alias: {
		values: { action: 'REGISTER_SERIAL_DIALOG_COMMAND_ALIAS' },
		captures: [ 'alias', 'command' ]
	},
	action_set_command: {
		values: {
			action: 'REGISTER_SERIAL_DIALOG_COMMAND',
			is_fail: false
		},
		captures: [ 'command', 'script' ]
	},
	action_set_command_fail: {
		values: {
			action: 'REGISTER_SERIAL_DIALOG_COMMAND',
			is_fail: true
		},
		captures: [ 'command', 'script' ]
	},
	action_set_command_arg: {
		values: {
			action: 'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT',
			is_fail: true
		},
		captures: [ 'command', 'argument', 'script' ]
	},
	action_set_ambiguous: {
		values: {},
		captures: ['lhs', 'rhs'],
		detective: [
			{
				isMatch: (v, f, node) => {
					const type = grammarTypeForFieldName(f, node, 'rhs');
					return type === 'ambiguous_identifier_expansion'
						|| type === 'BAREWORD'
						|| type === 'QUOTED_STRING'
				},
				finalizeValues: (v, f, node, i) => {
					const ident = v.rhs;
					// For expansions, we only want to print one ambiguous identifier at a time in an error/warning message.
					// `i` is from the caller, who knows which one of the set we're looking at now.
					// Basically, the whole spread might not be ambiguous, so we need to report
					// only once the action is identified (with isMatch()), not all the time.
					const lhsNode = node.childForFieldName('lhs').namedChildren?.[i] || node.childForFieldName('lhs');
					const rhsNode = node.childForFieldName('rhs').namedChildren?.[i] || node.childForFieldName('rhs');
					// These are the nodes that will get squigglies
					const printNodes = [lhsNode, rhsNode];
					const suggestion = v.rhs.includes(' ')
						? '"' + ident + '"'
						: ident;
					f.newWarning({
						locations: printNodes.map(v => ({ node: v })),
						message: 'these identifiers could be ints or bools',
						footer: `Both identifiers will be interpreted as ints unless you coerce the right-hand side to a bool expression, like this:\n`
							+ `    !!${suggestion}`,
					});
					return setVarToVar(v.lhs, v.rhs);
				}
			},
			{
				// We know the RHS is a number
				// ... but it's a simple case, so use a simple action for this
				isMatch: (v) => typeof v.rhs === 'number',
				finalizeValues: (v) => setVarToValue(v.lhs, v.rhs),
			},
			{
				// We know the RHS is a number
				// ... but it's a simple "getable" so use a simple action for this
				isMatch: (v, f, node) => grammarTypeForFieldName(f, node, 'rhs') === 'int_getable',
				finalizeValues: (v) => copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, v.lhs),
			},
			{
				// We know the RHS is a int expression
				isMatch: (v, f, node) => grammarTypeForFieldName(f, node, 'rhs').includes('int'),
				finalizeValues: (v, f, node) => {
					// Make a temporary variable to store the value of the expression
					newTemporary();
					// Play out the expression
					const steps = flattenIntBinaryExpression(v.rhs, []);
					// Clean up the temporary (but retain the variable name)
					const temporary = dropTemporary();
					// do `LHS = temporary`
					steps.push(setVarToVar(v.lhs, temporary));
					return newSequence(f, node, steps, 'set int (ambiguous lhs)');
				}
			},
			{
				// We know the RHS is a boolean
				// ... but it's a simple case, so use a simple action for this
				isMatch: (v) => typeof v.rhs === 'boolean',
				finalizeValues: (v) => setFlag(v.lhs, v.rhs),
			},
			{
				// We know the RHS is a boolean
				// ... and RHS is a simple bool getable
				isMatch: (v) => v.rhs.mathlang === 'bool_getable',
				finalizeValues: (v, f, node) => {
					const param = getBoolFieldForAction(v.rhs.action);
					return setFlagToFlag(f, node, v.lhs, v.rhs.value, !v.rhs[param]);
				},
			},
			{
				// We know the RHS is a bool expression
				// ... it's complicated.
				isMatch: (v, f, node) => grammarTypeForFieldName(f, node, 'rhs').includes('bool'),
				finalizeValues: (v, f, node) => {
					// TODO: review this fn
					const ret = actionSetBoolMaker(f, v.rhs, v.lhs);
					const setFlagSteps = setFlagToFlag(f, node, v.lhs, quickTemporary());
					ret.steps.push(...setFlagSteps.steps);
					return ret;
				}
			},
		],
	},
	action_set_int: {
		// If we've matched this, we know the LHS is not a variable name. Only other option is an entity field.
		values: {},
		captures: ['lhs', 'rhs'],
		detective: [
			{
				// RHS is number, simple case
				// Different LHSs need different actions, though
				isMatch: (v) => typeof v.rhs === 'number',
				finalizeValues: (v) => {
					const ret = { entity: v.lhs.entity };
					if (v.lhs.field === 'x') {
						ret.action = 'SET_ENTITY_X';
						ret.u2_value = v.rhs;
					} else if (v.lhs.field === 'y') {
						ret.action = 'SET_ENTITY_Y';
						ret.u2_value = v.rhs;
					} else if (v.lhs.field === 'primary_id') {
						ret.action = 'SET_ENTITY_PRIMARY_ID';
						ret.u2_value = v.rhs;
					} else if (v.lhs.field === 'secondary_id') {
						ret.action = 'SET_ENTITY_SECONDARY_ID';
						ret.u2_value = v.rhs;
					} else if (v.lhs.field === 'primary_id_type') {
						ret.action = 'SET_ENTITY_PRIMARY_ID_TYPE';
						ret.byte_value = v.rhs;
					} else if (v.lhs.field === 'current_animation') {
						ret.action = 'SET_ENTITY_CURRENT_ANIMATION';
						ret.byte_value = v.rhs;
					} else if (v.lhs.field === 'animation_frame') {
						ret.action = 'SET_ENTITY_CURRENT_FRAME';
						ret.byte_value = v.rhs;
					} else if (v.lhs.field === 'strafe') {
						ret.action = 'SET_ENTITY_MOVEMENT_RELATIVE';
						ret.relative_direction = v.rhs;
					} else if (v.lhs.field === 'relative_direction') {
						ret.action = 'SET_ENTITY_DIRECTION_RELATIVE';
						ret.relative_direction = v.rhs;
					} 
					return ret;
				}
			},
			{
				// RHS is variable name, simple case
				// The field is part of the JSON action
				isMatch: (v) => typeof v.rhs === 'string',
				finalizeValues: (v, f, node) => copyVarIntoEntityField(v.rhs, v.lhs.entity, v.lhs.field),
			},
			{
				// RHS is something more complex (everything else)
				// Do the expression thing, like above, but the final step is different
				// (It's going into an entity field, not a variable)
				isMatch: (v) => true,
				finalizeValues: (v, f, node) => {
					newTemporary();
					const steps = flattenIntBinaryExpression(v.rhs, []);
					const temporary = dropTemporary();
					steps.push(copyVarIntoEntityField(temporary, v.lhs.entity, v.lhs.field));
					return newSequence(f, node, steps, 'set int');
				},
			},
		],
	},
	action_set_bool: {
		// If we've matched this, we know the LHS is not a variable name.
		values: {},
		captures: ['lhs', 'rhs'],
		detective: [
			{
				isMatch: (v) => v.lhs.type === 'entity',
				finalizeValues: (v, f, node) => {
					const lhsAction = {
						action: 'SET_ENTITY_GLITCHED',
						entity: v.lhs.value,
						bool_value: true,
					};
					return actionSetBoolMaker(f, v.rhs, lhsAction, node);
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'light',
				finalizeValues: (v, f, node) => {
					const lhsAction = {
						action: 'SET_LIGHTS_STATE',
						lights: v.lhs.value,
						enabled: true,
					};
					return actionSetBoolMaker(f, v.rhs, lhsAction);
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'player_control',
				finalizeValues: (v, f, node) => {
					const lhsAction = {
						action: 'SET_PLAYER_CONTROL',
						bool_value: true,
					};
					return actionSetBoolMaker(f, v.rhs, lhsAction);
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'lights_control',
				finalizeValues: (v, f, node) => {
					const lhsAction = {
						action: 'SET_LIGHTS_CONTROL',
						enabled: true,
					};
					return actionSetBoolMaker(f, v.rhs, lhsAction);
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'hex_editor',
				finalizeValues: (v, f, node) => {
					const lhsAction = {
						action: 'SET_HEX_EDITOR_STATE',
						bool_value: true,
					};
					return actionSetBoolMaker(f, v.rhs, lhsAction);
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'hex_dialog_mode',
				finalizeValues: (v, f, node) => {
					const lhsAction = {
						action: 'SET_HEX_EDITOR_DIALOG_MODE',
						bool_value: true,
					};
					return actionSetBoolMaker(f, v.rhs, lhsAction);
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'hex_control',
				finalizeValues: (v, f, node) => {
					const lhsAction = {
						action: 'SET_HEX_EDITOR_CONTROL',
						bool_value: true,
					};
					return actionSetBoolMaker(f, v.rhs, lhsAction);
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'hex_clipboard',
				finalizeValues: (v, f, node) => {
					const lhsAction = {
						action: 'SET_HEX_EDITOR_CONTROL_CLIPBOARD',
						bool_value: true,
					};
					return actionSetBoolMaker(f, v.rhs, lhsAction);
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'serial_control',
				finalizeValues: (v, f, node) => {
					const lhsAction = {
						action: 'SET_SERIAL_DIALOG_CONTROL',
						bool_value: true,
					};
					return actionSetBoolMaker(f, v.rhs, lhsAction);
				},
			},
		],
	},
	action_set_position: {
		values: {},
		captures: ['movable', 'coordinate'],
		detective: [
			{
				isMatch: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType !== 'length',
				finalizeValues: (v) => ({
					action: 'TELEPORT_CAMERA_TO_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				isMatch: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'entity',
				finalizeValues: (v) => ({
					action: 'SET_CAMERA_TO_FOLLOW_ENTITY',
					entity: v.coordinate.value,
				}),
			},
			{
				isMatch: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType !== 'length',
				finalizeValues: (v) => ({
					action: 'TELEPORT_ENTITY_TO_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
			{
				isMatch: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'entity',
				finalizeValues: (v, f, node) => {
					const variable = quickTemporary();
					const copyFrom = v.coordinate.value;
					const copyTo = v.movable.value;
					const steps = [
						copyVarIntoEntityField(variable, copyFrom, 'x'),
						copyEntityFieldIntoVar(copyTo, 'x', variable),
						copyVarIntoEntityField(variable, copyFrom, 'y'),
						copyEntityFieldIntoVar(copyTo, 'y', variable),
					];
					return newSequence(f, node, steps, 'set position');
				},
			},
		],
		detectError: (v) => ({
			locations: [{ node: v.debug }],
			message: `incompatible movable identifier and position identifier`,
		}),
	},
	action_move_over_time: {
		values: {},
		captures: ['movable', 'coordinate', 'duration', 'forever'],
		optionalCaptures: ['forever'],
		detective: [
			{
				isMatch: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'origin'
					&& !v.forever,
				finalizeValues: (v) => ({
					action: 'PAN_CAMERA_TO_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				isMatch: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !v.forever,
				finalizeValues: (v) => ({
					action: 'PAN_CAMERA_ALONG_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				isMatch: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !!v.forever,
				finalizeValues: (v) => ({
					action: 'LOOP_CAMERA_ALONG_GEOMETRY',
					geometry: v.coordinate.value,
				}),
			},
			{
				isMatch: (v) => v.movable.type === 'camera'
					&& v.coordinate.type === 'entity'
					&& !v.forever,
				finalizeValues: (v) => ({
					action: 'PAN_CAMERA_TO_ENTITY',
					entity: v.coordinate.value,
				}),
			},
			{
				isMatch: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'origin'
					&& !v.forever,
				finalizeValues: (v) => ({
					action: 'WALK_ENTITY_TO_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
			{
				isMatch: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !v.forever,
				finalizeValues: (v) => ({
					action: 'WALK_ENTITY_ALONG_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
			{
				isMatch: (v) => v.movable.type === 'entity'
					&& v.coordinate.type === 'geometry'
					&& v.coordinate.polygonType === 'length'
					&& !!v.forever,
				finalizeValues: (v) => ({
					action: 'LOOP_ENTITY_ALONG_GEOMETRY',
					entity: v.movable.value,
					geometry: v.coordinate.value,
				}),
			},
		],
		detectError: (v) => {
			let message = `incompatible movable identifier and position identifier`;
			let node = v.debug;
			if (v.coordinate.type === 'entity') {
				if (v.movable.type === 'entity') {
					message = `cannot move an entity to another entity's position over time`;
					node = v.coordinate.debug;
				} else if (v.movable.type === 'camera') {
					message = `cannot move camera to an entity's position forever`;
					node = v.coordinate.debug;
				}
			} else if (!!v.forever) {
				message = `'forever' can only be used with geometry lengths, not single points`;
				node = v.coordinate.debug;
			}
			return {
				message,
				locations: [{ node }],
			};
		},
	},
	action_set_direction: {
		values: {},
		captures: [ 'entity', 'target' ],
		detective: [
			{
				isMatch: (v) => true,
				finalizeValues: (v) => {
					return {
						...v.target,
						entity: v.entity,
					};
				},
			},
		],
	},
	action_set_script: {
		values: {},
		captures: [ 'entity', 'script_slot', 'script' ],
		detective: [
			{
				isMatch: (v) => v.entity === '%MAP%'
					&& v.script_slot === 'on_tick',
				finalizeValues: (v) => {
					return {
						action: 'SET_MAP_TICK_SCRIPT',
						script: v.script,
					};
				},
			},
			{
				isMatch: (v) => v.entity !== '%MAP%'
					&& v.script_slot === 'on_tick',
				finalizeValues: (v) => {
					return {
						action: 'SET_ENTITY_TICK_SCRIPT',
						entity: v.entity,
						script: v.script,
					};
				},
			},
			{
				isMatch: (v) => v.entity !== '%MAP%'
					&& v.script_slot === 'on_interact',
				finalizeValues: (v) => {
					return {
						action: 'SET_ENTITY_INTERACT_SCRIPT',
						entity: v.entity,
						script: v.script,
					};
				},
			},
			{
				isMatch: (v) => v.entity !== '%MAP%'
					&& v.script_slot === 'on_look',
				finalizeValues: (v) => {
					return {
						action: 'SET_ENTITY_LOOK_SCRIPT',
						entity: v.entity,
						script: v.script,
					};
				},
			},
		],
		detectError: (v) => {
			if (v.entity === '%MAP%') {
				return  {
					message: `invalid map script slot`,
					locations: [{ node: v.debug.childForFieldName('script_slot') }],
					footer: `You can only set a map's 'on_tick' slot`
				};
			} else if (
				v.script_slot !== 'on_tick'
				|| v.script_slot !== 'on_interact'
				|| v.script_slot !== 'on_look'
			) {
				return  {
					message: `invalid entity script slot`,
					locations: [{ node: v.debug.childForFieldName('script_slot') }],
					footer: `Valid entity script slots: 'on_tick', 'on_interact', 'on_look'`,
				}
			} else {
				return  {
					message: `set script slot syntax error`,
					locations: [{ node: v.debug }],
				}
			}
		},
	},
	action_set_entity_string: {
		values: {},
		captures: [ 'entity', 'field', 'value' ],
		detective: [
			{
				isMatch: (v) => v.field === 'name',
				finalizeValues: (v) => ({
					action: 'SET_ENTITY_NAME',
					entity: v.entity,
					string: v.value,
				})
			},
			{
				isMatch: (v) => v.field === 'type',
				finalizeValues: (v) => ({
					action: 'SET_ENTITY_TYPE',
					entity: v.entity,
					entity_type: v.value,
				})
			},
			{
				isMatch: (v) => v.field === 'path',
				finalizeValues: (v) => ({
					action: 'SET_ENTITY_PATH',
					entity: v.entity,
					geometry: v.value,
				})
			},
		]
	},
	action_op_equals: {
		values: {},
		captures: [ 'lhs', 'operator', 'rhs' ],
		detective: [
			{
				isMatch: (v) => typeof v.rhs === 'number' && typeof v.lhs === 'string',
				finalizeValues: (v) => changeVarByValue(v.lhs, v.rhs, v.operator),
			},
			{
				isMatch: (v) => typeof v.rhs === 'number' && v.lhs.mathlang === 'int_getable',
				finalizeValues: (v, f, node) => {
					const temporary = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary),
						changeVarByValue(temporary, v.rhs, v.operator),
						copyVarIntoEntityField(temporary, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					return newSequence(f, v.debug, steps, 'set op-equals with number');
				},
			},
			{
				isMatch: (v) => typeof v.rhs === 'string' && typeof v.lhs === 'string',
				finalizeValues: (v) => changeVarByVar(v.lhs, v.rhs, v.operator),
			},
			{
				isMatch: (v) => typeof v.rhs === 'string' && v.lhs.mathlang === 'int_getable',
				finalizeValues: (v, f, node) => {
					const temporary = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary),
						changeVarByVar(temporary, v.rhs, v.operator),
						copyVarIntoEntityField(temporary, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					return newSequence(f, v.debug, steps, 'set op-equals with string (identifier)');
				},
			},
			{
				isMatch: (v) => v.rhs.mathlang === 'int_binary_expression' && typeof v.lhs === 'string',
				finalizeValues: (v, f, node) => {
					const temporary = newTemporary();
					const steps = flattenIntBinaryExpression(v.rhs, []);
					dropTemporary();
					steps.push(changeVarByVar(v.lhs, temporary, v.operator))
					return newSequence(f, node, steps, 'set op-equals with int binary expression');
				},
			},
			{
				isMatch: (v) => v.rhs.mathlang === 'int_binary_expression' && v.lhs.mathlang === 'int_getable',
				finalizeValues: (v, f, node) => {
					const temporary1 = newTemporary();
					const temporary2 = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary1),
						...flattenIntBinaryExpression(v.rhs, []),
						changeVarByVar(temporary1, temporary2, v.operator),
						copyVarIntoEntityField(temporary1, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					dropTemporary();
					return newSequence(f, node, steps, 'set op-equals with int binary expression');
				},
			},
			{
				isMatch: (v) => v.rhs.mathlang === 'int_getable' && typeof v.lhs === 'string',
				finalizeValues: (v, f, node) => {
					const temp = quickTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, temp),
						changeVarByVar(v.identifier, temp, v.operator)
					]
					return newSequence(f, node, steps, 'set op-equals with int getable');
				},
			},
			{
				isMatch: (v) => v.rhs.mathlang === 'int_getable' && v.lhs.mathlang === 'int_getable',
				finalizeValues: (v, f, node) => {
					const temporary1 = newTemporary();
					const temporary2 = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary1),
						copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, temporary2),
						changeVarByVar(temporary1, temporary2, v.operator),
						copyVarIntoEntityField(temporary1, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					dropTemporary();
					return newSequence(f, node, steps, 'set op-equals with int getable');
				},
			},
			{
				isMatch: (v) => true,
				finalizeValues: (v) => {
					console.log("WHAT WAS THIS AGAIN")
				},
			},
		],
	},
	action_plus_minus_ables: {
		values: {},
		captures: [ 'entity', 'operator', 'value' ],
		detective: [
			{
				isMatch: (v) => true,
				finalizeValues: (v) => {
					const sign = v.operator === '-=' ? -1 : 1;
					return {
						'action': "SET_ENTITY_DIRECTION_RELATIVE",
						'entity': v.entity,
						'relative_direction': sign * v.value,
					};
				}
			}
		]
	},
};

// ------------------------ MAKE JSON ACTIONS ------------------------ //

const setVarToValue = (variable, value) => ({
	action: 'MUTATE_VARIABLE',
	operation: 'SET',
	value,
	variable,
});
const setVarToVar = (variable, source) => ({
	action: 'MUTATE_VARIABLES',
	operation: 'SET',
	source,
	variable,
});
const changeVarByValue = (variable, value, op) => ({
	action: 'MUTATE_VARIABLE',
	operation: opIntoStringMap[op] || op,
	value,
	variable,
});
const changeVarByVar = (variable, source, op) => ({
	action: 'MUTATE_VARIABLES',
	operation: opIntoStringMap[op] || op,
	source,
	variable,
});
const copyVarIntoEntityField = (variable, entity, field) => ({
	action: "COPY_VARIABLE",
	entity,
	field,
	inbound: false,
	variable,
});
const copyEntityFieldIntoVar = (entity, field, variable) => ({
	action: "COPY_VARIABLE",
	entity,
	field,
	inbound: true,
	variable,
});
const setFlag = (save_flag, bool_value) => {
	return {
		action: "SET_SAVE_FLAG",
		bool_value,
		save_flag,
	};
};
const checkFlag = (save_flag, expected_bool) => ({
	mathlang: 'bool_getable',
	action: 'CHECK_SAVE_FLAG',
	expected_bool,
	save_flag,
});
const setFlagToFlag = (f, node, save_flag, source, invert) => {
	const action = setFlag(save_flag, null);
	return simpleBranchMaker(
		f,
		node,
		checkFlag(source, !invert),
		{ ...action, bool_value: true }, // if true
		{ ...action, bool_value: false } // if false
	);
};

module.exports = { handleAction, handleActionsInit };
