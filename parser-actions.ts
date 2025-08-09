import { Node as TreeSitterNode } from 'web-tree-sitter';
import { handleCapture, grammarTypeForFieldName, type Capture } from './parser-capture.ts';
import {
	type Action,
	type MGSDebug,
	type CHECK_SAVE_FLAG,
	type SET_SAVE_FLAG,
	getBoolFieldForAction,
	type COPY_VARIABLE,
	type MUTATE_VARIABLE,
	type MUTATE_VARIABLES,
} from './parser-bytecode-info.ts';
import {
	type AnyNode,
	type DialogDefinition,
	type MathlangNode,
	type CommentNode,
	type MovableIdentifier,
	type CoordinateIdentifier,
	type MGSMessage,
	type IntGetable,
	type MathlangSequence,
	isIntGetable,
	isDialog,
	isSerialDialog,
	type IntBinaryExpression,
	isIntBinaryExpression,
} from './parser-types.ts';
import {
	autoIdentifierName,
	expandCondition,
	makeLabelDefinition,
	makeGotoLabel,
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
	newComment,
} from './parser-utilities.ts';
import { handleNode } from './parser-node.ts';
import { type FileState } from './parser-file.ts';

const opIntoStringMap: Record<string, string> = {
	'=': 'SET',
	'+': 'ADD',
	'-': 'SUB',
	'*': 'MUL',
	'/': 'DIV',
	'%': 'MOD',
	'?': 'RNG',
};

// ------------------------ INT EXPRESSIONS ------------------------ //

const flattenIntBinaryExpression = (exp: IntBinaryExpression, steps: AnyNode[]): AnyNode[] => {
	const temporary = latestTemporary();
	const lhs = exp.lhs;
	const op = exp.op;
	const rhs = exp.rhs;
	if (typeof lhs === 'string') {
		steps.push(setVarToVar(temporary, lhs));
	} else if (typeof lhs === 'number') {
		steps.push(setVarToValue(temporary, lhs));
	} else if (isIntGetable(lhs)) {
		steps.push(copyEntityFieldIntoVar(lhs.entity, lhs.field, temporary));
	} else if (lhs.mathlang === 'int_binary_expression') {
		// can use the same temporary since it's the lhs and we're going LTR
		// (and operator precedence is now baked into the AST)
		flattenIntBinaryExpression(lhs, steps);
	}
	if (typeof rhs === 'string') {
		steps.push(changeVarByVar(temporary, rhs, op));
	} else if (typeof rhs === 'number') {
		if (
			(op === '+' && rhs === 0) ||
			(op === '-' && rhs === 0) ||
			(op === '*' && rhs === 1) ||
			(op === '/' && rhs === 1)
		) {
			// do nothing
		} else {
			steps.push(changeVarByValue(temporary, rhs, op));
		}
	} else if (isIntGetable(rhs)) {
		const temp = quickTemporary();
		if (!temp) throw new Error('TS why');
		steps.push(
			copyEntityFieldIntoVar(rhs.entity, rhs.field, temp),
			changeVarByVar(temporary, temp, op),
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

const actionSetBoolMaker = (
	f: FileState,
	_rhsRaw,
	_lhs,
	backupNode?: TreeSitterNode,
): MathlangSequence => {
	// get the action JSON for the LHS
	const lhs = typeof _lhs === 'string' ? setFlag(_lhs, true) : _lhs;
	const lhsParam = getBoolFieldForAction(lhs.action);
	if (!lhsParam) throw new Error('shoudl have been a string');
	if (typeof _rhsRaw === 'boolean') {
		lhs[lhsParam] = _rhsRaw;
		return lhs;
	}
	// get the action JSON for the RHS
	const rhsRaw = typeof _rhsRaw === 'string' ? checkFlag(_rhsRaw, true) : _rhsRaw;
	if (
		rhsRaw.mathlang === 'bool_getable' ||
		rhsRaw.mathlang === 'bool_comparison' ||
		rhsRaw.mathlang === 'string_checkable' ||
		rhsRaw.mathlang === 'number_checkable_equality'
	) {
		const rhsParam = getBoolFieldForAction(rhsRaw.action);
		if (!rhsParam) throw new Error('shoudl have been a string');
		const existingValue = rhsRaw[rhsParam];
		if (existingValue === undefined) throw new Error('Found a hole! ' + rhsRaw.action);
		const baseAction = {
			...rhsRaw,
			[rhsParam]: existingValue,
		};
		return simpleBranchMaker(
			f,
			rhsRaw.debug?.node || backupNode,
			baseAction,
			{ ...lhs, [lhsParam]: true },
			{ ...lhs, [lhsParam]: false },
		);
	}
	// Everything hereafter is a bool expression (?)
	const setLhsIfTrue =
		typeof lhs === 'string' ? setFlag(lhs, true) : { ...lhs, [lhsParam]: true };
	const setLhsIfFalse =
		typeof lhs === 'string' ? setFlag(lhs, false) : { ...lhs, [lhsParam]: false };
	const ifLabel = `if true #${f.p.advanceGotoSuffix()}`;
	const rendezvousLabel = `rendezvous #${f.p.advanceGotoSuffix()}`;
	const steps = [
		...expandCondition(f, rhsRaw.debug.node, rhsRaw, ifLabel),
		setLhsIfFalse,
		makeGotoLabel(f, rhsRaw.debug.node, rendezvousLabel),
		makeLabelDefinition(f, rhsRaw.debug.node, ifLabel),
		setLhsIfTrue,
		makeLabelDefinition(f, rhsRaw.debug.node, rendezvousLabel),
	];
	return newSequence(f, rhsRaw.debug.node, steps, 'set bool on');
};

// ------------------------ COMMON ACTION HANDLING ------------------------ //

export type GenericActionish = Record<
	string,
	boolean | number | string | MGSDebug | Record<string, unknown>
>;
// Takes an object with simple values and an object with array values and "spreads" them --
// e.g. { a: b }, { c: [d,e] } -> [ {a:b, c:d}, {a:b, c:e} ]
const spreadValues = (
	f: FileState,
	commonFields: GenericActionish,
	fieldsToSpread: Record<string, FieldToSpread>,
): GenericActionish[] => {
	// ->[]
	// count spreads
	let spreadSize = -Infinity;
	Object.values(fieldsToSpread).forEach((spreadField) => {
		const len = spreadField.captures.length;
		// spreadSize won't be 1 btw, because 1s go to commonFields
		if (spreadSize === -Infinity) spreadSize = len;
		if (spreadSize !== len) {
			f.newError({
				locations: [{ node: spreadField.node }],
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
	const ret: GenericActionish[] = [];
	for (let i = 0; i < spreadSize; i++) {
		const insert = { ...commonFields };
		Object.keys(fieldsToSpread).forEach((fieldName) => {
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
// - Once spread, the handler identifies the JSON action for each spread item (since they might be different from each toehr)
// - Adds the final JSON properties required by the encoder
// - If the result is more than one "step" (for sequences not directly supported by the engine)
// it will add the action as a "sequence", which will need to be expanded later
// (for a few reasons, the result must be a single "unit" at this stage)
// TODO: why then return an array?
type FieldToSpread = {
	node: TreeSitterNode;
	captures: Capture[];
};
export const handleAction = (f: FileState, node: TreeSitterNode): AnyNode[] => {
	if (!node) throw new Error('Missing node');
	// From the action dictionary
	const data = actionData[node.grammarType];
	if (!data) {
		const customFn = actionFns[node.grammarType];
		if (!customFn)
			throw new Error(
				`No action data nor handler function found for action ${node.grammarType}`,
			);
		return customFn(f, node);
	}
	const debug: MGSDebug = {
		node,
		fileName: f.fileName,
	};
	const action = {
		debug,
		...data.values,
	};
	// Action params
	const captures: string[] = data.captures || [];
	const fieldsToSpread: Record<string, FieldToSpread> = {};
	captures.forEach((fieldName) => {
		const captureNode = node.childForFieldName(fieldName);
		if (captureNode === null) {
			if (data.optionalCaptures?.includes(fieldName)) {
				action[fieldName] = null;
			} else {
				throw new Error(
					`Capture found for field not associated with this action (${fieldName})`,
				);
			}
			return;
		}
		const capture = handleCapture(f, captureNode);
		if (!Array.isArray(capture)) {
			action[fieldName] = capture;
		} else {
			fieldsToSpread[fieldName] = {
				node: captureNode,
				captures: capture,
			};
		}
	});
	const spreads: GenericActionish[] = spreadValues(f, action, fieldsToSpread);
	// Different param combinations will result in different actions,
	// so let the handler sort them out after the spreads are spread
	const handleFn = data.handle;
	if (handleFn) {
		spreads.forEach((actionInsideSpread, i) => {
			const handled = handleFn(actionInsideSpread, f, node, i) as GenericActionish;
			if (handled) {
				spreads[i] = handled;
				// any reason to keep the intermediate values? no? tests still pass? well then
				// spreads[i] = { ...action, ...handled };
				return;
			}
		});
	}
	return spreads as AnyNode[];
};

// Put things here if you don't care about auto-spreading them; otherwise they should go in actionData
type ActionFn = (f: FileState, node: TreeSitterNode, isConcat?: boolean) => AnyNode[];
const actionFns: Record<string, ActionFn> = {
	action_show_dialog: (f: FileState, node: TreeSitterNode): AnyNode[] => {
		const nameNode = node.childForFieldName('dialog_name');
		const name = nameNode ? handleCapture(f, nameNode) : autoIdentifierName(f, node);
		if (typeof name !== 'string') throw new Error('name not a string');
		const dialogs = (node.childrenForFieldName('dialog') || [])
			.map((child) => {
				if (child === null) throw new Error('');
				return handleNode(f, child);
			})
			.flat();
		const shownDialog = showDialog(f, node, name);
		if (dialogs.length) {
			if (!dialogs.every(isDialog)) throw new Error('');
			const dialogDefinition = newDialog(f, node, name, dialogs) as DialogDefinition;
			return [dialogDefinition, shownDialog];
		}
		return [shownDialog];
	},
	action_concat_serial_dialog: (f: FileState, node: TreeSitterNode): AnyNode[] =>
		actionFns.action_show_serial_dialog(f, node, true),
	action_show_serial_dialog: (
		f: FileState,
		node: TreeSitterNode,
		isConcat: boolean = false,
	): AnyNode[] => {
		const nameNode = node.childForFieldName('serial_dialog_name');
		const name = nameNode ? handleCapture(f, nameNode) : autoIdentifierName(f, node);
		if (typeof name !== 'string') throw new Error('name not a string');
		const serialDialogs = (node.childrenForFieldName('serial_dialog') || [])
			.map((child) => {
				if (child === null) throw new Error('');
				return handleNode(f, child);
			})
			.flat();
		const shownSerialDialog = showSerialDialog(f, node, name, isConcat || false);
		if (serialDialogs.length) {
			if (!isSerialDialog(serialDialogs[0])) throw new Error('');
			const serialDialoDefinition = newSerialDialog(f, node, name, serialDialogs[0]);
			return [serialDialoDefinition, shownSerialDialog];
		}
		return [shownSerialDialog];
	},
};

type actionDataEntry = {
	values?: Record<string, unknown>;
	captures?: string[];
	optionalCaptures?: string[];
	handle?: (
		v: Record<string, boolean | string | number | Record<string, unknown>>,
		f: FileState,
		node: TreeSitterNode,
		i?: number,
	) => unknown;
};
const actionData: Record<string, actionDataEntry> = {
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
		captures: ['frequency', 'amplitude', 'duration'],
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
		captures: ['script_slot', 'entity'],
	},
	action_unpause_script: {
		values: { action: 'SET_SCRIPT_PAUSE', bool_value: false },
		captures: ['script_slot', 'entity'],
	},
	action_play_entity_animation: {
		values: { action: 'PLAY_ENTITY_ANIMATION' },
		captures: ['entity', 'animation', 'play_count'],
	},
	action_set_warp_state: {
		values: { action: 'SET_WARP_STATE' },
		captures: ['string'],
	},
	action_set_serial_connect: {
		values: { action: 'SET_CONNECT_SERIAL_DIALOG' },
		captures: ['serial_dialog'],
	},
	action_set_alias: {
		values: { action: 'REGISTER_SERIAL_DIALOG_COMMAND_ALIAS' },
		captures: ['alias', 'command'],
	},
	action_set_command: {
		values: {
			action: 'REGISTER_SERIAL_DIALOG_COMMAND',
			is_fail: false,
		},
		captures: ['command', 'script'],
	},
	action_set_command_fail: {
		values: {
			action: 'REGISTER_SERIAL_DIALOG_COMMAND',
			is_fail: true,
		},
		captures: ['command', 'script'],
	},
	action_set_command_arg: {
		values: {
			action: 'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT',
			is_fail: true,
		},
		captures: ['command', 'argument', 'script'],
	},
	action_set_ambiguous: {
		values: {},
		captures: ['lhs', 'rhs'],
		handle: (v, f, node, i) => {
			const grammarType = grammarTypeForFieldName(f, node, 'rhs');
			if (grammarType === undefined) throw new Error('undefined grammarType');
			if (typeof v.lhs !== 'string') throw new Error('TS');
			if (
				grammarType === 'ambiguous_identifier_expansion' ||
				grammarType === 'BAREWORD' ||
				grammarType === 'QUOTED_STRING'
			) {
				if (i === undefined) throw new Error('TS');
				if (typeof v.rhs !== 'string') throw new Error('TS');
				// For expansions, we only want to print one ambiguous identifier at a time in an error/warning message.
				// `i` is from the caller, who knows which one of the set we're looking at now.
				// Basically, the whole spread might not be ambiguous, so we need to report
				// only once the action is identified in an individual spread, not all the time.
				const lhsNode =
					node.childForFieldName('lhs')?.namedChildren?.[i] ||
					node.childForFieldName('lhs');
				const rhsNode =
					node.childForFieldName('rhs')?.namedChildren?.[i] ||
					node.childForFieldName('rhs');
				// These are the nodes that will get squigglies
				if (!lhsNode || !rhsNode) throw new Error('ts!!');
				const printNodes = [lhsNode, rhsNode];
				const suggestion = v.rhs.includes(' ') ? '"' + v.rhs + '"' : v.rhs;
				f.newWarning({
					locations: printNodes.map((v) => ({ node: v })),
					message: 'these identifiers could be ints or bools',
					footer:
						`Both identifiers will be interpreted as ints unless you coerce the right-hand side to a bool expression, like this:` +
						`\n    !!${suggestion}` +
						`\nTo silence this warning, turn the RHS into a passthrough int expression (which will produce the same output), e.g.:` +
						`\n    ${suggestion} + 0` +
						`\n    ${suggestion} * 1`,
				});
				return setVarToVar(v.lhs, v.rhs);
			}

			// We know the RHS is a number
			// ... but it's a simple case, so use a simple action for this
			if (typeof v.rhs === 'number') {
				return setVarToValue(v.lhs, v.rhs);
			}
			// ... but it's a simple "getable" so use a simple action for this
			if (grammarType === 'int_getable') {
				if (
					typeof v.rhs !== 'object' ||
					typeof v.rhs.entity !== 'string' ||
					typeof v.rhs.field !== 'string'
				)
					throw new Error('ts');
				return copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, v.lhs);
			}

			// We know the RHS is a int expression
			if (grammarType.includes('int')) {
				// Make a temporary variable to store the value of the expression
				newTemporary(v.lhs);
				// Play out the expression
				if (!isIntBinaryExpression(v.rhs)) throw new Error('meep');
				const steps = flattenIntBinaryExpression(v.rhs, []);
				// Clean up the temporary (but retain the variable name)
				const temporary = dropTemporary();
				// do `LHS = temporary`
				steps.push(setVarToVar(v.lhs, temporary));
				return newSequence(f, node, steps, 'set int (ambiguous lhs)');
			}

			// We know the RHS is a boolean
			// ... but it's a simple case, so use a simple action for this
			if (typeof v.rhs === 'boolean') {
				return setFlag(v.lhs, v.rhs);
			}
			// ... and RHS is a simple bool getable
			if (typeof v.rhs === 'object' && v.rhs.mathlang === 'bool_getable') {
				if (typeof v.rhs.action !== 'string') throw new Error('ts wants a string lol');
				if (typeof v.rhs.value !== 'string') throw new Error('ts wants a string lol');
				const param = getBoolFieldForAction(v.rhs.action);
				if (typeof param !== 'string') throw new Error('ts wants a string lol');
				return setFlagToFlag(f, node, v.lhs, v.rhs.value, !v.rhs[param]);
			}

			// We know the RHS is a bool expression
			// ... it's complicated.
			if (grammarType.includes('bool')) {
				// TODO: review this fn
				if (typeof v.lhs !== 'string') throw new Error('should be string: ' + v.lhs);
				const ret = actionSetBoolMaker(f, v.rhs, v.lhs);
				const setFlagSteps = setFlagToFlag(f, node, v.lhs, quickTemporary());
				ret.steps.push(...setFlagSteps.steps);
				return ret;
			}
		},
	},
	action_set_int: {
		// If we've matched this, we know the LHS is not a variable name. Only other option is an entity field.
		values: {},
		captures: ['lhs', 'rhs'],
		handle: (v, f, node): Action | MathlangNode | undefined => {
			// RHS is number, simple case
			// Different LHSs need different actions, though
			if (typeof v.rhs === 'number') {
				if (typeof v.lhs !== 'object') throw new Error('TS SRSLY');
				const entity = v.lhs.entity;
				if (typeof entity !== 'string') throw new Error('TS SRSLY AGAIN');
				if (v.lhs.field === 'x') {
					return {
						entity,
						action: 'SET_ENTITY_X',
						u2_value: v.rhs,
					};
				}
				if (v.lhs.field === 'y') {
					return {
						entity,
						action: 'SET_ENTITY_Y',
						u2_value: v.rhs,
					};
				}
				if (v.lhs.field === 'primary_id') {
					return {
						entity,
						action: 'SET_ENTITY_PRIMARY_ID',
						u2_value: v.rhs,
					};
				}
				if (v.lhs.field === 'secondary_id') {
					return {
						entity,
						action: 'SET_ENTITY_SECONDARY_ID',
						u2_value: v.rhs,
					};
				}
				if (v.lhs.field === 'primary_id_type') {
					return {
						entity,
						action: 'SET_ENTITY_PRIMARY_ID_TYPE',
						byte_value: v.rhs,
					};
				}
				if (v.lhs.field === 'current_animation') {
					return {
						entity,
						action: 'SET_ENTITY_CURRENT_ANIMATION',
						byte_value: v.rhs,
					};
				}
				if (v.lhs.field === 'animation_frame') {
					return {
						entity,
						action: 'SET_ENTITY_CURRENT_FRAME',
						byte_value: v.rhs,
					};
				}
				if (v.lhs.field === 'strafe') {
					return {
						entity,
						action: 'SET_ENTITY_MOVEMENT_RELATIVE',
						relative_direction: v.rhs,
					};
				}
				if (v.lhs.field === 'relative_direction') {
					return {
						entity,
						action: 'SET_ENTITY_DIRECTION_RELATIVE',
						relative_direction: v.rhs,
					};
				}
				if (!v.debug && typeof v.debug !== 'object') throw new Error('TSTSTS');
				f.newError({
					locations: [{ node }],
					message: `syntax error setting int to number`,
				});
			}
			// RHS is variable name, simple case
			// The field is part of the JSON action
			if (typeof v.lhs !== 'object') throw new Error('LHS not an object');
			if (typeof v.lhs.entity !== 'string') throw new Error('LHS entity field not a string');
			if (typeof v.lhs.field !== 'string')
				throw new Error('LHS entity field "field" not a string');
			if (typeof v.rhs === 'string') {
				return copyVarIntoEntityField(v.rhs, v.lhs.entity, v.lhs.field);
			}
			// RHS is something more complex (everything else)
			// Do the expression thing, like above, but the final step is different
			// (It's going into an entity field, not a variable)
			newTemporary();
			if (!isIntBinaryExpression(v.rhs)) throw new Error('meep');
			const steps = flattenIntBinaryExpression(v.rhs, []);
			const temporary = dropTemporary();
			steps.push(copyVarIntoEntityField(temporary, v.lhs.entity, v.lhs.field));
			return newSequence(f, node, steps, 'set int') as MathlangNode;
		},
	},
	action_set_bool: {
		// If we've matched this, we know the LHS is not a variable name.
		values: {},
		captures: ['lhs', 'rhs'],
		// TODO: can the capture side put the action in?
		handle: (v, f, node) => {
			if (typeof v.lhs !== 'object') throw new Error('not making a type for this');
			if (v.lhs.type === 'entity') {
				const lhsAction = {
					action: 'SET_ENTITY_GLITCHED',
					bool_value: true,
					entity: v.lhs.value,
				};
				return actionSetBoolMaker(f, v.rhs, lhsAction, node);
			}
			if (v.lhs.type === 'light') {
				const lhsAction = {
					action: 'SET_LIGHTS_STATE',
					lights: v.lhs.value,
					enabled: true,
				};
				return actionSetBoolMaker(f, v.rhs, lhsAction, node);
			}
			if (v.lhs.type === 'player_control') {
				const lhsAction = { action: 'SET_PLAYER_CONTROL' };
				return actionSetBoolMaker(f, v.rhs, lhsAction, node);
			}
			if (v.lhs.type === 'lights_control') {
				const lhsAction = {
					action: 'SET_LIGHTS_CONTROL',
					enabled: true,
				};
				return actionSetBoolMaker(f, v.rhs, lhsAction, node);
			}
			if (v.lhs.type === 'hex_editor') {
				const lhsAction = { action: 'SET_HEX_EDITOR_STATE' };
				return actionSetBoolMaker(f, v.rhs, lhsAction, node);
			}
			if (v.lhs.type === 'hex_dialog_mode') {
				const lhsAction = { action: 'SET_HEX_EDITOR_DIALOG_MODE' };
				return actionSetBoolMaker(f, v.rhs, lhsAction, node);
			}
			if (v.lhs.type === 'hex_control') {
				const lhsAction = { action: 'SET_HEX_EDITOR_CONTROL' };
				return actionSetBoolMaker(f, v.rhs, lhsAction, node);
			}
			if (v.lhs.type === 'hex_clipboard') {
				const lhsAction = { action: 'SET_HEX_EDITOR_CONTROL_CLIPBOARD' };
				return actionSetBoolMaker(f, v.rhs, lhsAction, node);
			}
			if (v.lhs.type === 'serial_control') {
				const lhsAction = { action: 'SET_SERIAL_DIALOG_CONTROL' };
				return actionSetBoolMaker(f, v.rhs, lhsAction, node);
			}
		},
	},
	action_set_position: {
		values: {},
		captures: ['movable', 'coordinate'],
		handle: (v, f, node) => {
			const movable = v.movable as MovableIdentifier;
			const coordinate = v.coordinate as CoordinateIdentifier;
			if (movable.type === 'camera') {
				if (coordinate.type === 'geometry' && coordinate.polygonType !== 'length') {
					return {
						action: 'TELEPORT_CAMERA_TO_GEOMETRY',
						geometry: coordinate.value,
					};
				}
				if (coordinate.type === 'entity') {
					return {
						action: 'SET_CAMERA_TO_FOLLOW_ENTITY',
						entity: coordinate.value,
					};
				}
			} else if (movable.type === 'entity') {
				if (coordinate.type === 'geometry' && coordinate.polygonType !== 'length') {
					return {
						action: 'TELEPORT_ENTITY_TO_GEOMETRY',
						entity: movable.value,
						geometry: coordinate.value,
					};
				}
				if (coordinate.type === 'entity') {
					const variable = quickTemporary();
					const copyFrom = coordinate.value;
					const copyTo = movable.value;
					const steps = [
						copyVarIntoEntityField(variable, copyFrom, 'x'),
						copyEntityFieldIntoVar(copyTo, 'x', variable),
						copyVarIntoEntityField(variable, copyFrom, 'y'),
						copyEntityFieldIntoVar(copyTo, 'y', variable),
					];
					return newSequence(f, node, steps, 'set position');
				}
			}
			const debug = v.debug as MGSDebug;
			f.newError({
				locations: [{ node: debug.node }],
				message: `incompatible movable identifier and position identifier`,
			});
		},
	},
	action_move_over_time: {
		values: {},
		captures: ['movable', 'coordinate', 'duration', 'forever'],
		optionalCaptures: ['forever'],
		handle: (v, f): Action | undefined => {
			const movable = v.movable as MovableIdentifier;
			const coordinate = v.coordinate as CoordinateIdentifier;
			const debug = v.debug as MGSDebug;
			const duration = v.duration;
			if (typeof duration !== 'number') throw new Error('freak out');
			const error: MGSMessage = {
				locations: [{ node: debug.node }],
				message: '',
			};
			if (movable.type === 'camera') {
				// Moving the camera
				if (coordinate.type === 'entity') {
					// ... to an entity
					if (v.forever) {
						// ... forever (ILLEGAL)
						error.message = `cannot move camera to an entity's position forever`;
						f.newError(error);
						return;
					} else {
						// ... not forever
						return {
							action: 'PAN_CAMERA_TO_ENTITY',
							duration: duration,
							entity: coordinate.value,
						};
					}
				}
				if (coordinate.type === 'geometry') {
					// ... to a geometry
					if (coordinate.polygonType === 'length') {
						// ... length
						if (v.forever) {
							// ... forever
							return {
								action: 'LOOP_CAMERA_ALONG_GEOMETRY',
								entity: coordinate.value,
								duration: duration,
								geometry: coordinate.value,
							};
						} else {
							// ... not forever
							return {
								action: 'PAN_CAMERA_ALONG_GEOMETRY',
								entity: coordinate.value,
								duration: duration,
								geometry: coordinate.value,
							};
						}
					} else if (coordinate.polygonType === 'origin') {
						// ... origin (single point)
						if (v.forever) {
							// ... forever (ILLEGAL)
							error.message = `'forever' can only be used with geometry lengths, not single points`;
							f.newError(error);
							return;
						} else {
							// ... not forever
							return {
								action: 'PAN_CAMERA_TO_GEOMETRY',
								duration: duration,
								geometry: coordinate.value,
							};
						}
					}
				}
			}

			if (movable.type === 'entity') {
				// Moving an entity
				if (coordinate.type === 'entity') {
					// ... to another entity (ILLEGAL)
					error.message = `cannot move an entity to another entity's position over time`;
					f.newError(error);
					return;
				}
				if (coordinate.type === 'geometry') {
					// ... to a geometry
					if (coordinate.polygonType === 'length') {
						// ... length
						if (v.forever) {
							// ... forever
							return {
								action: 'LOOP_ENTITY_ALONG_GEOMETRY',
								entity: movable.value,
								duration: duration,
								geometry: coordinate.value,
							};
						} else {
							// ... not forever
							return {
								action: 'WALK_ENTITY_ALONG_GEOMETRY',
								entity: movable.value,
								duration: duration,
								geometry: coordinate.value,
							};
						}
					}
					if (coordinate.polygonType === 'origin') {
						// ... origin (single point)
						if (v.forever) {
							// ... forever (ILLEGAL)
							error.message = `'forever' can only be used with geometry lengths, not single points`;
							f.newError(error);
							return;
						} else {
							// ... not forever
							return {
								action: 'WALK_ENTITY_TO_GEOMETRY',
								entity: movable.value,
								duration: duration,
								geometry: coordinate.value,
							};
						}
					}
				}
			}
		},
	},
	action_set_direction: {
		values: {},
		captures: ['entity', 'target'],
		handle: (v) => {
			if (typeof v.target !== 'object') throw new Error('trust me');
			return {
				...v.target,
				entity: v.entity,
			};
		},
	},
	action_set_script: {
		values: {},
		captures: ['entity', 'script_slot', 'script'],
		handle: (v, f, node) => {
			if (v.entity === '%MAP%') {
				if (v.script_slot === 'on_tick') {
					return {
						action: 'SET_MAP_TICK_SCRIPT',
						script: v.script,
					};
				}
				const errorNodes = node.childForFieldName('script_slot');
				if (!errorNodes) throw new Error('LOLOL');
				f.newError({
					message: `invalid map script slot`,
					locations: [{ node: errorNodes }],
					footer: `You can only set a map's 'on_tick' slot`,
				});
				return;
			}
			// not a map; must be an entity
			const ret = {
				entity: v.entity,
				script: v.script,
			};
			if (v.script_slot === 'on_tick') {
				return {
					...ret,
					action: 'SET_ENTITY_TICK_SCRIPT',
				};
			}
			if (v.script_slot === 'on_interact') {
				return {
					...ret,
					action: 'SET_ENTITY_INTERACT_SCRIPT',
				};
			}
			if (v.script_slot === 'on_look') {
				return {
					...ret,
					action: 'SET_ENTITY_LOOK_SCRIPT',
				};
			}
			const errorNodes = node.childForFieldName('script_slot');
			if (!errorNodes) throw new Error('LOLOL');
			f.newError({
				message: `invalid entity script slot`,
				locations: [{ node: errorNodes }],
				footer: `Valid entity script slots: 'on_tick', 'on_interact', 'on_look'`,
			});
		},
	},
	action_set_entity_string: {
		values: {},
		captures: ['entity', 'field', 'value'],
		handle: (v, f, node): Action | undefined => {
			if (v.field === 'name') {
				if (typeof v.value !== 'string') throw new Error('TS');
				if (typeof v.entity !== 'string') throw new Error('TS');
				return {
					action: 'SET_ENTITY_NAME',
					string: v.value,
					entity: v.entity,
				};
			} else if (v.field === 'type') {
				if (typeof v.value !== 'string') throw new Error('TS');
				if (typeof v.entity !== 'string') throw new Error('TS');
				return {
					action: 'SET_ENTITY_TYPE',
					entity_type: v.value,
					entity: v.entity,
				};
			} else if (v.field === 'path') {
				if (typeof v.value !== 'string') throw new Error('TS');
				if (typeof v.entity !== 'string') throw new Error('TS');
				return {
					action: 'SET_ENTITY_PATH',
					entity: v.entity,
					geometry: v.value,
				};
			} else {
				f.newError({
					locations: [{ node }],
					message: `syntax error setting entity property to string`,
				});
			}
		},
	},
	action_op_equals: {
		values: {},
		captures: ['lhs', 'operator', 'rhs'],
		handle: (v, f, node) => {
			// LHS is a string, meaning we're doing a thing to an integer variable
			const op = v.operator;
			if (typeof op !== 'string') throw new Error(`Operator is not a string (${op})`);
			if (typeof v.lhs === 'string') {
				// e.g. varName += 1
				if (typeof v.rhs === 'number') {
					return changeVarByValue(v.lhs, v.rhs, op);
				}
				// e.g. varName += var2
				if (typeof v.rhs === 'string') {
					return changeVarByVar(v.lhs, v.rhs, op);
				}
				// e.g. varName += player x
				if (typeof v.rhs !== 'object') throw new Error('come on');
				if (isIntGetable(v.rhs)) {
					const temp = quickTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, temp),
						changeVarByVar(v.lhs, temp, op),
					];
					return newSequence(f, node, steps, 'set op-equals with int getable');
				}
				// e.g. varName += (var2 * 7)
				if (v.rhs.mathlang === 'int_binary_expression') {
					const temporary = newTemporary();
					if (!isIntBinaryExpression(v.rhs)) throw new Error('meep');
					const steps = flattenIntBinaryExpression(v.rhs, []);
					dropTemporary();
					steps.push(changeVarByVar(v.lhs, temporary, op));
					return newSequence(f, node, steps, 'set op-equals with int binary expression');
				}
				f.newError({
					locations: [{ node }],
					message: `syntax error setting integer variable value`,
				});
			}

			// LHS is an int getable, like `player y`
			// Can only set these to set values; cannot do math to them.
			// First put the value into a temporary, then do the math to that, then set it back.
			if (typeof v.lhs !== 'object') throw new Error('TS');
			if (isIntGetable(v.lhs)) {
				// e.g. player x = 1;
				const lhs = v.lhs as IntGetable;
				if (typeof v.rhs === 'number') {
					const temporary = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(lhs.entity, lhs.field, temporary),
						changeVarByValue(temporary, v.rhs, op),
						copyVarIntoEntityField(temporary, lhs.entity, lhs.field),
					];
					dropTemporary();
					return newSequence(f, node, steps, 'set op-equals with number');
				}
				// e.g. player x = varName;
				if (typeof v.rhs === 'string') {
					const temporary = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(lhs.entity, lhs.field, temporary),
						changeVarByVar(temporary, v.rhs, op),
						copyVarIntoEntityField(temporary, lhs.entity, lhs.field),
					];
					dropTemporary();
					return newSequence(f, node, steps, 'set op-equals with string (identifier)');
				}
				// e.g. player x = (varName * 7);
				if (typeof v.rhs !== 'object') throw new Error('not a bool');
				if (v.rhs.mathlang === 'int_binary_expression') {
					const temporary1 = newTemporary();
					const temporary2 = newTemporary();
					if (!isIntBinaryExpression(v.rhs)) throw new Error('meep');
					const steps = [
						copyEntityFieldIntoVar(lhs.entity, lhs.field, temporary1),
						...flattenIntBinaryExpression(v.rhs, []),
						changeVarByVar(temporary1, temporary2, op),
						copyVarIntoEntityField(temporary1, lhs.entity, lhs.field),
					];
					dropTemporary();
					dropTemporary();
					return newSequence(f, node, steps, 'set op-equals with int binary expression');
				}
				// e.g. player x = self y;
				if (typeof v.rhs === 'boolean') throw new Error('TS seriously trust me');
				if (isIntGetable(v.rhs)) {
					const temporary1 = newTemporary();
					const temporary2 = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(lhs.entity, lhs.field, temporary1),
						copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, temporary2),
						changeVarByVar(temporary1, temporary2, op),
						copyVarIntoEntityField(temporary1, lhs.entity, lhs.field),
					];
					dropTemporary();
					dropTemporary();
					return newSequence(f, node, steps, 'set op-equals with int getable');
				}
				f.newError({
					locations: [{ node }],
					message: `syntax error setting int property value`,
				});
			}
		},
	},
	action_plus_minus_equals_ables: {
		values: {},
		captures: ['entity', 'operator', 'value'],
		handle: (v) => {
			const sign = v.operator === '-=' ? -1 : 1;
			if (typeof v.value !== 'number') throw new Error(`Not a number: ${v.value}`);
			return {
				action: 'SET_ENTITY_DIRECTION_RELATIVE',
				entity: v.entity,
				relative_direction: sign * v.value,
			};
		},
	},
};

// ------------------------ MAKE JSON ACTIONS ------------------------ //

const setVarToValue = (variable: string, value: number): Action => ({
	action: 'MUTATE_VARIABLE',
	operation: 'SET',
	value,
	variable,
});
const setVarToVar = (variable: string, source: string): MUTATE_VARIABLES | CommentNode => {
	if (variable === source)
		return newComment(`This action was optimized out (setting '${variable}' to itself)`);
	return {
		action: 'MUTATE_VARIABLES',
		operation: 'SET',
		source,
		variable,
	};
};
const changeVarByValue = (
	variable: string,
	value: number,
	op: string,
): MUTATE_VARIABLE | CommentNode => {
	if (op === '+' && value === 0) {
		return newComment('This action was optimized out (+ 0)');
	}
	if (op === '*' && value === 1) {
		return newComment('This action was optimized out (* 1)');
	}
	if (op === '/' && value === 1) {
		return newComment('This action was optimized out (/ 1)');
	}
	if (op === '-' && value === 0) {
		return newComment('This action was optimized out (- 0)');
	}
	return {
		action: 'MUTATE_VARIABLE',
		operation: opIntoStringMap[op] || op,
		value,
		variable,
	};
};
const changeVarByVar = (variable: string, source: string, op: string): MUTATE_VARIABLES => ({
	action: 'MUTATE_VARIABLES',
	operation: opIntoStringMap[op] || op,
	source,
	variable,
});
const copyVarIntoEntityField = (
	variable: string,
	entity: string,
	field: string,
): COPY_VARIABLE => ({
	action: 'COPY_VARIABLE',
	entity,
	field,
	inbound: false,
	variable,
});
const copyEntityFieldIntoVar = (
	entity: string,
	field: string,
	variable: string,
): COPY_VARIABLE => ({
	action: 'COPY_VARIABLE',
	entity,
	field,
	inbound: true,
	variable,
});
const setFlag = (save_flag: string, bool_value: boolean): SET_SAVE_FLAG => ({
	action: 'SET_SAVE_FLAG',
	bool_value,
	save_flag,
});
const checkFlag = (save_flag: string, expected_bool: boolean): CHECK_SAVE_FLAG => ({
	mathlang: 'bool_getable',
	action: 'CHECK_SAVE_FLAG',
	expected_bool,
	save_flag,
});
const setFlagToFlag = (
	f: FileState,
	node: TreeSitterNode,
	save_flag: string,
	source: string,
	invert?: boolean,
): MathlangSequence => {
	const action = setFlag(save_flag, true);
	return simpleBranchMaker(
		f,
		node,
		checkFlag(source, !invert),
		[{ ...action, bool_value: true }], // if true
		[{ ...action, bool_value: false }], // if false
	);
};
