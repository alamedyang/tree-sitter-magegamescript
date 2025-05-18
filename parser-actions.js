const handleCapture = require('./parser-capture.js');
const { autoIdentifierName, simpleBranchMaker } = require ('./parser-utilities.js');

let handleNode;
const handleActionsInit = (handleNodeFn) => {
	handleNode = handleNodeFn;
};
const TEMP = '__TEMP_'
const intOpMap = {
	'=': 'SET',
	'+': 'ADD',
	'-': 'SUB',
	'*': 'MUL',
	'/': 'DIV',
	'%': 'MOD',
	'?': 'RNG',
}
const intOpMapReverse = {
	ADD: '+',
	SUB: '-',
	MUL: '*',
	DIV: '/',
	MOD: '%',
	RNG: '?',
	SET: ':',
};
const temporaries = [];
const newTemporary = () => {
	temporaries.unshift(TEMP + temporaries.length);
	return temporaries[0];
};
const dropTemporary = () => temporaries.shift();
const quickTemporary = () => {
	newTemporary();
	return dropTemporary();
}
const latestTemporary = () => temporaries[0];

const expandIntBinaryExpression = (exp, steps) => {
	const variable = latestTemporary();
	const lhs = exp.lhs;
	const op = exp.op;
	const rhs = exp.rhs;
	if (typeof lhs === 'number') {
		steps.push(setVarToValue(variable, lhs));
	} else if (lhs.entity) {
		steps.push(copyEntityFieldIntoVar(lhs.entity, lhs.field, variable));
	} else if (lhs.mathlang === 'int_binary_expression') {
		expandIntBinaryExpression(lhs, steps);
	}
	if (typeof rhs === 'number') {
		steps.push(changeVarByValue(variable, rhs, op))
	} else if (rhs.entity) {
		const temp = quickTemporary();
		steps.push(copyEntityFieldIntoVar(rhs.entity, rhs.field, temp));
		steps.push(changeVarByVar(variable, temp, op));
	} else if (rhs.mathlang === 'int_binary_expression') {
		const temp = newTemporary();
		expandIntBinaryExpression(rhs, steps);
		steps.push(changeVarByVar(variable, temp, op));
		dropTemporary();
	}
	return steps;
};
const expandBoolBinaryExpression = (exp, steps) => {
	const variable = latestTemporary();
	const lhs = exp.lhs;
	const op = exp.op;
	const rhs = exp.rhs;
	// if (typeof lhs === 'number') {
	// 	steps.push(setVarToValue(variable, lhs));
	// } else if (lhs.entity) {
	// 	steps.push(copyEntityFieldIntoVar(lhs.entity, lhs.field, variable));
	// } else if (lhs.mathlang === 'int_binary_expression') {
	// 	expandIntBinaryExpression(lhs, steps);
	// }
	// if (typeof rhs === 'number') {
	// 	steps.push(changeVarByValue(variable, rhs, op))
	// } else if (rhs.entity) {
	// 	const temp = quickTemporary();
	// 	steps.push(copyEntityFieldIntoVar(rhs.entity, rhs.field, temp));
	// 	steps.push(changeVarByVar(variable, temp, op));
	// } else if (rhs.mathlang === 'int_binary_expression') {
	// 	const temp = newTemporary();
	// 	expandIntBinaryExpression(rhs, steps);
	// 	steps.push(changeVarByVar(variable, temp, op));
	// 	dropTemporary();
	// }
	return steps;
};


const printMath = (a) => {
	if (a.action === 'MUTATE_VARIABLE') {
		if (a.operation === 'SET') {
			return `${a.variable} := ${a.value}`;
		} else{
			return `${a.variable} ${intOpMapReverse[a.operation]}= ${a.value}`;
		}
	} else if (a.action === 'MUTATE_VARIABLES') {
		if (a.operation === 'SET') {
			return `${a.variable} := ${a.source}`;
		} else{
			return `${a.variable} ${intOpMapReverse[a.operation]}= ${a.source}`;
		}
	} else if (a.action === 'COPY_VARIABLE') {
		if (a.inbound) {
			return `${a.variable} := ${a.entity}.${a.field}`;
		} else{
			return `${a.entity}.${a.field} := ${a.variable}`;
		}
	}
};

// Takes an object with simple values and an object with array values and "spreads" them --
// e.g. { a: b }, { c: [d,e] } -> [ {a:b, c:d}, {a:b, c:e}]
const spreadValues = (f, commonFields, fieldsToSpread) => { // ->[]
	// count spreads
	let spreadSize = -Infinity;
	Object.values(fieldsToSpread).forEach(fieldName=>{
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
		return [ commonFields ];
	}
	// but spread action into multiple variants
	let ret = [];
	for (let i = 0; i < spreadSize; i++) {
		const insert = { ...commonFields };
		Object.keys(fieldsToSpread).forEach(fieldName=>{
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
// - Once spread, the detective identifies the JSON action for each spread item
// - Adds the final JSON properties required by the encoder
// - If the result is more than one "step" (for sequences not directly supported by the engine)
// it will add the action as a "math_sequence", which will need to be expanded later
// (for a few reasons, the result must be a single "unit" at this stage)
// TODO: why then return an array?
const handleAction = (f, node) => { // ->[]
	// cyclic dependency bodge
	if (!handleNode) {
		throw new Error("handleAction cannot be called until handleNode has been provided to the init function");
	}
	// from the action dictionary
	const data = actionData[node.grammarType];
	if (!data) {
		const customFn = actionFns[node.grammarType];
		if (!customFn) throw new Error (`No action data nor handler function found for action ${node.grammarType}`);
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
	captures.forEach(fieldName=>{
		const fieldNode = node.childForFieldName(fieldName);
		if (!fieldNode) {
			if (data.optionalCaptures?.includes(fieldName)) {
				action[fieldName] = null;
			} else {
				throw new Error(`Capture found for field not associated with this action (${fieldName})`)
			}
			return;
		}
		const capture = handleCapture(f, fieldNode);
		if (!Array.isArray(capture)) {
			action[fieldName] = capture;
		} else {
			fieldsToSpread[fieldName] = {
				node: fieldNode,
				captures: capture,
			};
		}
	});
	const spreads = spreadValues(f, action, fieldsToSpread);
	// Different param combinations will result in different actions,
	// so let the detective sort them out after the spreads are spread
	if (data.detective) {
		spreads.forEach((action, actionIndex)=>{
			// try the action detective
			for (let i = 0; i < data.detective.length; i++) {
				const currClueData = data.detective[i];
				const solved = currClueData.isMatch(action, f, node);
				if (solved) {
					// todo: reorder the arguments in .values()?
					const values = currClueData.finalizeValues(action, f, node, actionIndex);
					Object.entries(values)
						.forEach(([k,v])=>{ action[k] = v; });
					return;
				}
			}
			// if we got here, nothing matched
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

// todo: Q, should actionFns be checked first, or actionData?
// actionFns is far less likely to hit, so try the common thing first?
const actionFns = {
	action_show_dialog: (f, node) => {
		const nameNode = node.childForFieldName('dialog_name');
		const name = nameNode ? nameNode.text : autoIdentifierName(f, node);
		const dialogNodes = node.childrenForFieldName('dialog');
		const dialogs = (dialogNodes||[])
			.map(child=>handleNode(f, child))
			.flat(); // (double flat?)
		const showDialogAction = {
			action: 'SHOW_DIALOG',
			dialog: name,
			debug: node,
			fileName: f.fileName
		}
		// TODO: telling apart unnamed empty dialogs and SHOW_DIALOG w/o dialog block?
		if (dialogNodes.length === 0) {
			return [showDialogAction];
		}
		const dialogDefinition = {
			mathlang: 'dialog_definition',
			dialogName: name,
			dialogs: dialogs,
			debug: node,
			fileName: f.fileName,
		};
		return [
			dialogDefinition,
			showDialogAction
		];
	},
	action_concat_serial_dialog: (f, node) => actionFns.action_show_serial_dialog(f, node, true),
	action_show_serial_dialog: (f, node, isConcat) => {
		const nameNode = node.childForFieldName('serial_dialog_name');
		const name = nameNode ? nameNode.text : autoIdentifierName(f, node);
		const serialDialogNodes = node.childrenForFieldName('serial_dialog');
		const serialDialogs = (serialDialogNodes||[])
			.map(child=>handleNode(f, child))
			.flat();
		const showSerialDialogAction = {
			action: 'SHOW_SERIAL_DIALOG',
			disable_newline: !isConcat,
			serial_dialog: name,
			debug: node,
			fileName: f.fileName
		}
		if (serialDialogs.length === 0) {
			return [showSerialDialogAction];
		}
		const serialDialogDefinition = {
			mathlang: 'serial_dialog_definition',
			dialogName: name,
			serialDialog: serialDialogs[0],
			debug: node,
			fileName: f.fileName,
		};
		return [
			serialDialogDefinition,
			showSerialDialogAction
		];
	},
};

const actionData = {
	action_return_statement: {
		// TODO: everything after is unreachable
		// Ditto some other actions, too
		values: { mathlang: 'return_statement' },
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
		captures: [ 'slot' ],
	},
	action_erase_slot: {
		values: { action: 'SLOT_ERASE' },
		captures: [ 'slot' ],
	},
	action_load_map: {
		values: { action: 'LOAD_MAP' },
		captures: [ 'map' ],
	},
	action_goto_label: {
		values: { mathlang: 'goto_label' },
		captures: [ 'label' ],
	},
	action_goto_index: {
		values: { action: 'GOTO_ACTION_INDEX' },
		captures: [ 'action_index' ],
	},
	action_run_script: {
		values: { action: 'RUN_SCRIPT' },
		captures: [ 'script' ],
	},
	action_non_blocking_delay: {
		values: { action: 'NON_BLOCKING_DELAY' },
		captures: [ 'duration' ],
	},
	action_blocking_delay: {
		values: { action: 'BLOCKING_DELAY' },
		captures: [ 'duration' ],
	},
	action_delete_command: {
		values: { action: 'UNREGISTER_SERIAL_DIALOG_COMMAND' },
		captures: [ 'command' ],
	},
	action_delete_command_arg: {
		values: { action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT' },
		captures: [ 'command', 'argument' ],
	},
	action_delete_alias: {
		values: { action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS' },
		captures: [ 'alias' ],
	},
	action_hide_command: {
		values: {
			action: 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY',
			is_visible: false,
		},
		captures: [ 'command' ],
	},
	action_unhide_command: {
		values: {
			action: 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY',
			is_visible: true,
		},
		captures: [ 'command' ],
	},
	action_camera_shake: {
		values: { action: 'SET_SCREEN_SHAKE' },
		captures: [ 'amplitude', 'distance', 'duration' ],
	},
	action_camera_fade_in: {
		values: { action: 'SCREEN_FADE_IN' },
		captures: [ 'color', 'duration' ],
	},
	action_camera_fade_out: {
		values: { action: 'SCREEN_FADE_OUT' },
		captures: [ 'color', 'duration' ],
	},
	action_pause_script: {
		values: { action: 'SET_SCRIPT_PAUSE', bool_value: true },
		captures: [ 'script', 'entity' ],
	},
	action_unpause_script: {
		values: { action: 'SET_SCRIPT_PAUSE', bool_value: false },
		captures: [ 'script', 'entity' ],
	},
	action_play_entity_animation: {
		values: { action: 'PLAY_ENTITY_ANIMATION' },
		captures: [ 'entity', 'animation', 'count' ],
	},
	action_set_ambiguous: {
		values: {},
		captures: [ 'lhs', 'rhs' ],
		detective: [
			{
				isMatch: (v, f, node) => {
					const type = node.childForFieldName('rhs')?.grammarType;
					return type === 'ambiguous_identifier_expansion' // :/
						|| type === 'BAREWORD'
						|| type === 'QUOTED_STRING'
				},
				finalizeValues: (v, f, node, i) => {
					const ambiguousIdentifier = v.rhs;
					// For expansions, we only want to report one ambiguous identifier at a time.
					// `i` is from the caller, who knows which one we're looking at now.
					// Basically, the whole spread might not be ambiguous, so we need to report
					// only once the action is identified (with isMatch()), not all the time.
					const lhsNode = node.childForFieldName('lhs')
						.namedChildren?.[i];
					const rhsNode = node.childForFieldName('rhs')
						.namedChildren?.[i];
					// These are the nodes that will get squigglies
					const printNodes = [ lhsNode, rhsNode ];
					const suggestion = rhsNode.text.includes(' ')
						? '"' + ambiguousIdentifier + '"'
						: ambiguousIdentifier;
					f.newWarning({
						locations: printNodes.map(v=>({ node: v })),
						message: 'these identifiers could be ints or bools',
						footer: `Both identifiers will be interpreted as ints unless you coerse the right-hand side to a bool expression, like this:\n`
							+ `    !!${suggestion}`,
					});
					return {
						action: 'MUTATE_VARIABLES',
						operation: 'SET',
						source: v.rhs,
						variable: v.lhs,
					};
				}
			},
			{
				isMatch: (v) => typeof v.rhs === 'number',
				finalizeValues: (v) => setVarToValue(v.lhs, v.rhs),
			},
			{
				isMatch: (v, f, node) => {
					return node.childForFieldName('rhs')
						.grammarType
						.includes('int');
				},
				finalizeValues: (v, f, node) => {
					const steps = mathSequenceFns.intExpression(f, v.rhs, node);
					steps.push(setVarToVar(v.lhs, TEMP+0));
					return {
						mathlang: 'math_sequence',
						steps,
					};
				}
			},
			{
				isMatch: (v) => typeof v.rhs === 'bool',
				finalizeValues: (v) => setFlag(v.lhs, v.rhs),
			},
			{
				isMatch: (v) => typeof v.rhs.value === 'bool',
				finalizeValues: (v) => setFlag(
					v.lhs,
					v.rhs.invert ? !v.rhs : v.rhs
				),
			},
			{
				isMatch: (v, f, node) => {
					return node.childForFieldName('rhs')
						.grammarType
						.includes('bool');
				},
				finalizeValues: (v, f, node) => {
					const steps = mathSequenceFns.boolExpression(f, v.rhs, node);
					// this action is literally for setting a flag, so set the flag to the temporary value
					steps.push(setFlagToFlag(f, v.lhs, TEMP+0));
					return {
						mathlang: 'math_sequence',
						steps,
					};
				}
			},
			{
				isMatch: (v, f, node) => {
					const type = node.childForFieldName('rhs').grammarType;
					return type.includes('bool');
				},
				finalizeValues: (v, f, node) => {
					const steps = mathSequenceFns.boolExpression(f, v.rhs, node);
					// this action is literally for setting a flag, so set the flag to the temporary value
					steps.push(setFlagToFlag(f, v.lhs, TEMP+0));
					return {
						mathlang: 'math_sequence',
						steps,
					};
				}
			},
		],
	},
	action_set_int: {
		values: {},
		captures: [ 'lhs', 'rhs' ],
		detective: [
			{
				isMatch: (v) => typeof v.rhs === 'number',
				finalizeValues: (v) => copyVarIntoEntityField(
					v.rhs, v.lhs.entity, v.lhs.field
				),
			},
			{
				// apart from variables, only entity fields can be set as ints,
				// so entity stuff on the LHS is a given if we're here
				// (variables on the LHS is handled by the "ambiguous" stuff)
				isMatch: (v) => true,
				finalizeValues: (v, f, node) => {
					const steps = mathSequenceFns.intExpression(f, v.rhs, node);
					steps.push(copyVarIntoEntityField(
						TEMP+0, v.lhs.entity, v.lhs.field
					));
					return {
						mathlang: 'math_sequence',
						steps,
					};
				},
			},
		],
	},
	action_set_bool: {
		values: {},
		captures: [ 'lhs', 'rhs' ],
		detective: [
			{
				isMatch: (v) => v.lhs.type === 'save_flag'
					&& typeof v.rhs === 'bool',
				finalizeValues: (v) => setFlag(v.lhs, v.rhs),
			},
			{
				isMatch: (v) => v.lhs.type === 'save_flag'
					&& typeof v.rhs.value === 'bool',
				finalizeValues: (v) => setFlag(
					v.lhs,
					v.rhs.invert ? !v.rhs : v.rhs
				),
			},
			{
				isMatch: (v) => v.lhs.type === 'save_flag',
				finalizeValues: (v, f, node) => {
					const action = {
						action: 'SET_SAVE_FLAG',
						save_flag: v.lhs.value,
					};
					return actionSetBoolMaker(f, v, action, 'bool_value');
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'entity',
				finalizeValues: (v, f, node) => {
					const action = {
						action: 'SET_ENTITY_GLITCHED',
						entity: v.lhs.value,
					};
					return actionSetBoolMaker(f, v, action, 'bool_value');
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'light',
				finalizeValues: (v, f, node) => {
					const action = {
						action: 'SET_LIGHTS_STATE',
						lights: v.lhs.value,
					};
					return actionSetBoolMaker(f, v, action, 'enabled');
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'player_control',
				finalizeValues: (v, f, node) => {
					const action = { action: 'SET_PLAYER_CONTROL' };
					return actionSetBoolMaker(f, v, action, 'bool_value');
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'lights_control',
				finalizeValues: (v, f, node) => {
					const action = { action: 'SET_LIGHTS_CONTROL' };
					return actionSetBoolMaker(f, v, action, 'enabled');
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'hex_editor',
				finalizeValues: (v, f, node) => {
					const action = { action: 'SET_HEX_EDITOR_STATE' };
					return actionSetBoolMaker(f, v, action, 'bool_value');
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'hex_dialog_mode',
				finalizeValues: (v, f, node) => {
					const action = { action: 'SET_HEX_EDITOR_DIALOG_MODE' };
					return actionSetBoolMaker(f, v, action, 'bool_value');
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'hex_control',
				finalizeValues: (v, f, node) => {
					const action = { action: 'SET_HEX_EDITOR_CONTROL' };
					return actionSetBoolMaker(f, v, action, 'bool_value');
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'hex_clipboard',
				finalizeValues: (v, f, node) => {
					const action = { action: 'SET_HEX_EDITOR_CONTROL_CLIPBOARD' };
					return actionSetBoolMaker(f, v, action, 'bool_value');
				},
			},
			{
				isMatch: (v) => v.lhs.type === 'serial_control',
				finalizeValues: (v, f, node) => {
					const action = { action: 'SET_SERIAL_DIALOG_CONTROL' };
					return actionSetBoolMaker(f, v, action, 'bool_value');
				},
			},
		],
	},
	action_set_position: {
		values: {},
		captures: [ 'movable', 'coordinate' ],
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
				finalizeValues: (v) => mathSequenceFns.moveEntityPosToEntityPos(
					v.coordinate.value,
					v.movable.value,
				),
			},
		],
		detectError: (v) => ({
			locations: [{ node: v.debug }],
			message: `incompatible movable identifier and position identifier`,
		}),
	},
	action_move_over_time: {
		values: {},
		captures: [ 'movable', 'coordinate', 'duration', 'forever' ],
		optionalCaptures: [ 'forever' ],
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
};

const mathSequenceFns = {
	moveEntityPosToEntityPos: (copyFrom, copyTo) => {
		const variable = TEMP;
		return {
			mathlang: 'math_sequence',
			steps: [
				{
					mathlang: 'math_sequence', inbound: true,
					action: 'COPY_VARIABLE', variable,
					entity: copyFrom, field: 'x',
				},
				{
					mathlang: 'math_sequence', inbound: false,
					action: 'COPY_VARIABLE', variable,
					entity: copyTo, field: 'x',
				},
				{
					mathlang: 'math_sequence', inbound: true,
					action: 'COPY_VARIABLE', variable,
					entity: copyFrom, field: 'y',
				},
				{
					mathlang: 'math_sequence', inbound: false,
					action: 'COPY_VARIABLE', variable,
					entity: copyTo, field: 'y',
				},
			]
		}
	},
	intExpression: (f, expressionNode, overallNode) => {
		const steps = [];
		newTemporary();
		expandIntBinaryExpression(expressionNode, steps);
		dropTemporary();
		console.log("EXPRESSION: " + expressionNode.debug.text)
		console.log(steps.map(printMath).join('\n')+'\n')
		// don't add the final destination, since it could be a few things;
		// the caller will decide where __TEMP_0 should go
		return steps;
	},
	boolExpression: (f, expressionNode, overallNode) => {
		const steps = [];
		newTemporary();
		console.log("FINISH THIS THING")

		// expandIntBinaryExpression(expressionNode, steps);
		dropTemporary();
		console.log("EXPRESSION: " + expressionNode.debug.text)
		console.log(steps.map(printMath).join('\n')+'\n')
		// don't add the final destination, since it could be a few things;
		// the caller will decide where __TEMP_0 should go
		return steps;
	},
};

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
	operation: intOpMap[op],
	value,
	variable,
});
const changeVarByVar = (variable, source, op) => ({
	action: 'MUTATE_VARIABLES',
	operation: intOpMap[op],
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
const setFlag = (save_flag, bool_value) => ({
	action: "SET_SAVE_FLAG",
	bool_value,
	save_flag,
});

const actionSetBoolMaker = (f, v, setAction, boolLabel) => {
	if (typeof v.rhs === 'boolean') {
		setAction[boolLabel] = v.rhs;
		return setAction;
	}
	if (typeof v.rhs.value === 'boolean' && v.rhs.invert) {
		setAction[boolLabel] = !v.rhs.value;
		return setAction;
	}
	
	// TODO: redo everything below
	const branchAction = {
		action: "CHECK_SAVE_FLAG",
		expected_bool: true,
		save_flag: setAction.bool_value
	}
	const ifBody = { ...setAction, [paramName]: true };
	const elseBody = { ...setAction, [paramName]: false };
	const branchSequence = simpleBranchMaker(f, branchAction, ifBody, elseBody);
	return branchSequence;
};
const setFlagToFlag = (f, flag, source) => {
	const branchAction = {
		action: "CHECK_SAVE_FLAG",
		expected_bool: true,
		save_flag: source,
	}
	const action = {
		action: "SET_SAVE_FLAG",
		save_flag: flag,
	};
	const ifBody = { ...action, bool_value: true };
	const elseBody = { ...action, bool_value: false };
	return simpleBranchMaker(f, branchAction, ifBody, elseBody);
};

module.exports = { handleAction, handleActionsInit };
