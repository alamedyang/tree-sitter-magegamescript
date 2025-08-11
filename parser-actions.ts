import { Node as TreeSitterNode } from 'web-tree-sitter';
import {
	coerceToNumber,
	coerceToString,
	handleCapture,
	handleChildrenForFieldName,
	mandatoryChildForFieldName,
	optionalStringCaptureForFieldName,
	type Capture,
} from './parser-capture.ts';
import {
	type MGSDebug,
	type SET_SAVE_FLAG,
	getBoolFieldForAction,
	type COPY_VARIABLE,
	type MUTATE_VARIABLE,
	type MUTATE_VARIABLES,
	isMGSDebug,
	type SET_ENTITY_DIRECTION_RELATIVE,
	type ActionSetPosition,
	type ActionSetDirection,
	type ActionSetScript,
	type ActionMoveOverTime,
	type ActionSetEntityString,
	type ActionSetEntityInt,
	type SHOW_DIALOG,
	type SHOW_SERIAL_DIALOG,
	type ActionSetBool,
} from './parser-bytecode-info.ts';
import {
	type AnyNode,
	type DialogDefinition,
	type SerialDialogDefinition,
	type CommentNode,
	type MGSMessage,
	type MathlangSequence,
	isIntGetable,
	isDialog,
	isSerialDialog,
	type IntBinaryExpression,
	isIntBinaryExpression,
	isBoolSetable,
	type BoolExpression,
	isBoolExpression,
	isMovableIdentifier,
	isCoordinateIdentifier,
	isDirectionTarget,
	isBoolGetable,
	isBoolComparison,
	newComment,
	newSequence,
	newDialogDefinition,
	newSerialDialogDefinition,
	newCheckSaveFlag,
} from './parser-types.ts';
import {
	autoIdentifierName,
	newTemporary,
	dropTemporary,
	quickTemporary,
	latestTemporary,
	simpleBranchMaker,
	autoDebug,
} from './parser-utilities.ts';
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

const invisibleMath = (op: string, operand: number): boolean => {
	if (op === '+' && operand === 0) return true;
	if (op === '-' && operand === 0) return true;
	if (op === '*' && operand === 1) return true;
	if (op === '/' && operand === 1) return true;
	return false;
};

const flattenIntBinaryExpression = (exp: IntBinaryExpression, steps: AnyNode[]): AnyNode[] => {
	const temp = latestTemporary();
	const lhs = exp.lhs;
	const op = exp.op;
	const rhs = exp.rhs;
	if (typeof lhs === 'string') {
		steps.push(setVarToVar(temp, lhs));
	} else if (typeof lhs === 'number') {
		steps.push(setVarToValue(temp, lhs));
	} else if (isIntGetable(lhs)) {
		steps.push(copyEntityFieldIntoVar(lhs.entity, lhs.field, temp));
	} else if (isIntBinaryExpression(lhs)) {
		// can use the same temporary since it's the lhs and we're going LTR
		// (and operator precedence is now baked into the AST)
		flattenIntBinaryExpression(lhs, steps);
	}
	if (typeof rhs === 'string') {
		steps.push(changeVarByVar(temp, rhs, op));
	} else if (typeof rhs === 'number') {
		if (invisibleMath(op, rhs)) {
			// invisible == *1 or +0
		} else {
			steps.push(changeVarByValue(temp, rhs, op));
		}
	} else if (isIntGetable(rhs)) {
		const quickTemp = quickTemporary();
		steps.push(
			copyEntityFieldIntoVar(rhs.entity, rhs.field, quickTemp),
			changeVarByVar(temp, quickTemp, op),
		);
	} else if (isIntBinaryExpression(rhs)) {
		const newTemp = newTemporary();
		flattenIntBinaryExpression(rhs, steps);
		steps.push(changeVarByVar(temp, newTemp, op));
		dropTemporary();
	}
	return steps;
};

// ------------------------ BOOL EXPRESSIONS ------------------------ //

const actionSetBoolMaker = (
	f: FileState,
	_lhsSetAction: ActionSetBool,
	_rhsBoolExp: BoolExpression,
	backupNode: TreeSitterNode,
): MathlangSequence | ActionSetBool => {
	if (typeof _lhsSetAction === 'string' && typeof _rhsBoolExp === 'string') {
		// not sure if this case will ever happen on its own due to the ambiguity dance
		// (and the typing we've got set up) but it's here if we need it
		return setFlagToFlag(f, backupNode, _lhsSetAction, _rhsBoolExp);
	}

	const lhsSetAction =
		typeof _lhsSetAction === 'string' ? setFlag(_lhsSetAction, true) : _lhsSetAction;
	const lhsBoolField = getBoolFieldForAction(lhsSetAction.action);

	// player glitched = true;
	if (typeof _rhsBoolExp === 'boolean') {
		lhsSetAction[lhsBoolField] = _rhsBoolExp;
		return lhsSetAction;
	}

	// player glitched = self glitched;
	// ->
	// if (self glitched) { player glitched = true; } else { player glitched = false; }
	const rhsBoolExp: BoolExpression =
		typeof _rhsBoolExp === 'string'
			? newCheckSaveFlag(f, backupNode, _rhsBoolExp, true)
			: _rhsBoolExp;
	if (isBoolGetable(rhsBoolExp) || isBoolComparison(rhsBoolExp)) {
		return simpleBranchMaker(
			f,
			rhsBoolExp.debug?.node || backupNode,
			rhsBoolExp,
			[lhsSetAction],
			[{ ...lhsSetAction, [lhsBoolField]: false }],
		);
	}

	return simpleBranchMaker(
		f,
		rhsBoolExp.debug?.node || backupNode,
		rhsBoolExp,
		[lhsSetAction],
		[{ ...lhsSetAction, [lhsBoolField]: false }],
	);
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

// TODO: why then return an array? Don't multis return MathlangSequence?
type FieldToSpread = {
	node: TreeSitterNode;
	captures: Capture[];
};
export const handleAction = (f: FileState, node: TreeSitterNode): AnyNode[] => {
	// From the action dictionary
	const data = actionData[node.grammarType];
	if (!data) {
		const customFn = actionFns[node.grammarType];
		if (!customFn)
			throw new Error(
				`no action data nor handler function found for action ${node.grammarType}`,
			);
		const customed = customFn(f, node);
		return customed;
	}
	const action = {
		debug: autoDebug(f, node),
		...data.values,
	};
	// Action params
	const captures: string[] = data.captures || [];
	const fieldsToSpread: Record<string, FieldToSpread> = {};
	captures.forEach((fieldName) => {
		const captureNode = node.childForFieldName(fieldName);
		if (captureNode === null) {
			if (!data.optionalCaptures || !data.optionalCaptures.includes(fieldName)) {
				throw new Error(
					`capture found for field not associated with action ${node.grammarType} (${fieldName})`,
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
				return;
			}
		});
	}
	return spreads as AnyNode[];
};

type ShowDialogOutput = (SHOW_DIALOG | DialogDefinition)[];
type ShowSerialDialogOutput = (SHOW_SERIAL_DIALOG | SerialDialogDefinition)[];

// Put things here if you don't care about auto-spreading them; otherwise they should go in actionData
type ActionFn = (f: FileState, node: TreeSitterNode, isConcat?: boolean) => AnyNode[];
const actionFns: Record<string, ActionFn> = {
	action_show_dialog: (f: FileState, node: TreeSitterNode): ShowDialogOutput => {
		const tryName = optionalStringCaptureForFieldName(f, node, 'dialog_name');
		const name = tryName !== null ? tryName : autoIdentifierName(f, node);
		const dialogs = handleChildrenForFieldName(f, node, 'dialog');
		const shownDialog: SHOW_DIALOG = {
			action: 'SHOW_DIALOG',
			dialog: name,
		};
		if (dialogs.length) {
			if (!dialogs.every(isDialog)) throw new Error('parsed dialogs not all of type Dialog');
			const dialogDefinition = newDialogDefinition(f, node, name, dialogs);
			return [dialogDefinition, shownDialog];
		}
		return [shownDialog];
	},
	action_concat_serial_dialog: (f: FileState, node: TreeSitterNode): ShowSerialDialogOutput => {
		return actionShowSerialDialog(f, node, true);
	},
	action_show_serial_dialog: (f: FileState, node: TreeSitterNode): ShowSerialDialogOutput => {
		return actionShowSerialDialog(f, node, false);
	},
};

// This is the only way the return type is preserved? Otherwise it gets genericized to AnyNode[]? That can't be right....
const actionShowSerialDialog = (
	f: FileState,
	node: TreeSitterNode,
	disable_newline: boolean = false,
): ShowSerialDialogOutput => {
	const tryName = optionalStringCaptureForFieldName(f, node, 'serial_dialog_name');
	const name = tryName !== null ? tryName : autoIdentifierName(f, node);
	const serialDialogs = handleChildrenForFieldName(f, node, 'serial_dialog');
	const shownSerialDialog: SHOW_SERIAL_DIALOG = {
		action: 'SHOW_SERIAL_DIALOG',
		serial_dialog: name,
		disable_newline,
	};
	if (serialDialogs.length) {
		if (!isSerialDialog(serialDialogs[0])) {
			throw new Error('parsed serial dialogs not all of type SerialDialog');
		}
		const serialDialoDefinition = newSerialDialogDefinition(f, node, name, serialDialogs[0]);
		return [serialDialoDefinition, shownSerialDialog];
	}
	return [shownSerialDialog];
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
		// if the LHS is ambiguous (a variable name)
		values: {},
		captures: ['lhs', 'rhs'],
		handle: (v, f, node, i): AnyNode => {
			const lhs = coerceToString(f, node, v.lhs, 'action_set_ambiguous lhs');

			// simple cases first (easy to check for)

			// varName = false;
			if (typeof v.rhs === 'boolean') return setFlag(lhs, v.rhs);

			// varName = 255;
			if (typeof v.rhs === 'number') return setVarToValue(lhs, v.rhs);

			// AMBIGUITY DANCE PARTY
			// varName = varName;
			if (typeof v.rhs == 'string') {
				if (i === undefined) throw new Error('undefined index');
				// For expansions, we only want to print one ambiguous identifier at a time in an error/warning message.
				// `i` is from the caller, who knows which one of the set we're looking at now.
				// Basically, the whole spread might not be ambiguous, so we need to report
				// only once the action is identified in an individual spread, not all the time.
				const lhsSquiggliesNode =
					node.childForFieldName('lhs')?.namedChildren?.[i] ||
					node.childForFieldName('lhs');
				const rhsSquiggliesNode =
					node.childForFieldName('rhs')?.namedChildren?.[i] ||
					node.childForFieldName('rhs');
				if (!lhsSquiggliesNode || !rhsSquiggliesNode) {
					throw new Error(`couldn't find nodes to squiggle`);
				}
				const printNodes = [lhsSquiggliesNode, rhsSquiggliesNode];
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
				return setVarToVar(lhs, v.rhs);
			}

			// varName = player x;
			if (isIntGetable(v.rhs)) {
				return copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, lhs);
			}

			// varName = (255 + player x);
			if (isIntBinaryExpression(v.rhs)) {
				const temporary = newTemporary(lhs);
				const steps = flattenIntBinaryExpression(v.rhs, []);
				dropTemporary();
				steps.push(setVarToVar(lhs, temporary));
				return newSequence(f, node, steps, 'parser-actions: action_set_ambiguous');
			}

			// varName = (debug_mode || player glitched);
			if (isBoolExpression(v.rhs)) {
				return actionSetBoolMaker(f, setFlag(lhs, true), v.rhs, node);
			}

			throw new Error('failed to parse');
		},
	},
	action_set_int: {
		// If we've matched this, we know the LHS is not a variable name.
		// Only option is an entity field.
		values: {},
		captures: ['lhs', 'rhs'],
		handle: (v, f, node): ActionSetEntityInt | MathlangSequence | COPY_VARIABLE => {
			if (!isIntGetable(v.lhs)) {
				throw new Error('LHS not int_getable');
			}
			const entity = coerceToString(f, node, v.lhs.entity, 'action_set_int entity');

			// player x = 0;
			if (typeof v.rhs === 'number') {
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
				throw new Error('unidentified int_getable, field: ' + v.lhs.field);
			}

			// player x = varName;
			if (typeof v.rhs === 'string') {
				return copyVarIntoEntityField(v.rhs, v.lhs.entity, v.lhs.field);
			}

			// player x = player y;
			if (isIntBinaryExpression(v.rhs)) {
				const temporary = newTemporary();
				const steps = flattenIntBinaryExpression(v.rhs, []);
				dropTemporary();
				steps.push(copyVarIntoEntityField(temporary, v.lhs.entity, v.lhs.field));
				return newSequence(f, node, steps, 'parser-actions: action_set_int');
			}

			throw new Error('unknown RHS type');
		},
	},
	action_set_bool: {
		// If we've matched this, we know the LHS is not a variable name.
		values: {},
		captures: ['lhs', 'rhs'],
		handle: (v, f, node): MathlangSequence | ActionSetBool => {
			if (!isBoolSetable(v.lhs)) {
				throw new Error('LHS not a bool_setable');
			}
			if (!isBoolExpression(v.rhs)) {
				throw new Error('RHS not a bool_expression');
			}
			if (v.lhs.type === 'entity') {
				const lhs: ActionSetBool = {
					action: 'SET_ENTITY_GLITCHED',
					bool_value: true,
					entity: coerceToString(
						f,
						node,
						v.lhs.value,
						'SET_ENTITY_GLITCHED field entity',
					),
				};
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'light') {
				const lhs: ActionSetBool = {
					action: 'SET_LIGHTS_STATE',
					lights: coerceToString(f, node, v.lhs.value, 'SET_LIGHTS_STATE field lights'),
					enabled: true,
				};
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'player_control') {
				const lhs: ActionSetBool = { action: 'SET_PLAYER_CONTROL', bool_value: true };
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'lights_control') {
				const lhs: ActionSetBool = {
					action: 'SET_LIGHTS_CONTROL',
					enabled: true,
				};
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'hex_editor') {
				const lhs: ActionSetBool = {
					action: 'SET_HEX_EDITOR_STATE',
					bool_value: true,
				};
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'hex_dialog_mode') {
				const lhs: ActionSetBool = {
					action: 'SET_HEX_EDITOR_DIALOG_MODE',
					bool_value: true,
				};
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'hex_control') {
				const lhs: ActionSetBool = {
					action: 'SET_HEX_EDITOR_CONTROL',
					bool_value: true,
				};
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'hex_clipboard') {
				const lhs: ActionSetBool = {
					action: 'SET_HEX_EDITOR_CONTROL_CLIPBOARD',
					bool_value: true,
				};
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'serial_control') {
				const lhs: ActionSetBool = {
					action: 'SET_SERIAL_DIALOG_CONTROL',
					bool_value: true,
				};
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			throw new Error('unknown LHS type');
		},
	},
	action_set_position: {
		values: {},
		captures: ['movable', 'coordinate'],
		handle: (v, f, node): ActionSetPosition | MathlangSequence => {
			if (!isMovableIdentifier(v.movable)) {
				throw new Error('invalid MovableIdentifier');
			}
			if (!isCoordinateIdentifier(v.coordinate)) {
				throw new Error('invalid CoordinateIdentifier');
			}
			if (v.movable.type === 'camera') {
				if (v.coordinate.type === 'geometry' && v.coordinate.polygonType !== 'length') {
					return {
						action: 'TELEPORT_CAMERA_TO_GEOMETRY',
						geometry: v.coordinate.value,
					};
				}
				if (v.coordinate.type === 'entity') {
					return {
						action: 'SET_CAMERA_TO_FOLLOW_ENTITY',
						entity: v.coordinate.value,
					};
				}
			} else if (v.movable.type === 'entity') {
				if (v.coordinate.type === 'geometry' && v.coordinate.polygonType !== 'length') {
					return {
						action: 'TELEPORT_ENTITY_TO_GEOMETRY',
						entity: v.movable.value,
						geometry: v.coordinate.value,
					};
				}
				if (v.coordinate.type === 'entity') {
					const variable = quickTemporary();
					const copyFrom = v.coordinate.value;
					const copyTo = v.movable.value;
					const steps = [
						copyVarIntoEntityField(variable, copyFrom, 'x'),
						copyEntityFieldIntoVar(copyTo, 'x', variable),
						copyVarIntoEntityField(variable, copyFrom, 'y'),
						copyEntityFieldIntoVar(copyTo, 'y', variable),
					];
					return newSequence(f, node, steps, 'parser-actions: action_set_position');
				}
			}
			throw new Error('invalid everything');
		},
	},
	action_move_over_time: {
		values: {},
		captures: ['movable', 'coordinate', 'duration', 'forever'],
		optionalCaptures: ['forever'],
		handle: (v, f, node): ActionMoveOverTime | undefined => {
			if (!isMovableIdentifier(v.movable)) {
				throw new Error('invalid MovableIdentifier');
			}
			if (!isCoordinateIdentifier(v.coordinate)) {
				throw new Error('invalid CoordinateIdentifier');
			}
			if (!isMGSDebug(v.debug)) {
				throw new Error('invalid debug node');
			}
			const duration = coerceToNumber(f, node, v.duration, 'duration');
			const error: MGSMessage = {
				locations: [{ node: v.debug.node }],
				message: '',
			};
			if (v.movable.type === 'camera') {
				// Moving the camera
				if (v.coordinate.type === 'entity') {
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
							entity: v.coordinate.value,
						};
					}
				}
				if (v.coordinate.type === 'geometry') {
					// ... to a geometry
					if (v.coordinate.polygonType === 'length') {
						// ... length
						if (v.forever) {
							// ... forever
							return {
								action: 'LOOP_CAMERA_ALONG_GEOMETRY',
								entity: v.coordinate.value,
								duration: duration,
								geometry: v.coordinate.value,
							};
						} else {
							// ... not forever
							return {
								action: 'PAN_CAMERA_ALONG_GEOMETRY',
								entity: v.coordinate.value,
								duration: duration,
								geometry: v.coordinate.value,
							};
						}
					} else if (v.coordinate.polygonType === 'origin') {
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
								geometry: v.coordinate.value,
							};
						}
					}
				}
			}

			if (v.movable.type === 'entity') {
				// Moving an entity
				if (v.coordinate.type === 'entity') {
					// ... to another entity (ILLEGAL)
					error.message = `cannot move an entity to another entity's position over time`;
					f.newError(error);
					return;
				}
				if (v.coordinate.type === 'geometry') {
					// ... to a geometry
					if (v.coordinate.polygonType === 'length') {
						// ... length
						if (v.forever) {
							// ... forever
							return {
								action: 'LOOP_ENTITY_ALONG_GEOMETRY',
								entity: v.movable.value,
								duration: duration,
								geometry: v.coordinate.value,
							};
						} else {
							// ... not forever
							return {
								action: 'WALK_ENTITY_ALONG_GEOMETRY',
								entity: v.movable.value,
								duration: duration,
								geometry: v.coordinate.value,
							};
						}
					}
					if (v.coordinate.polygonType === 'origin') {
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
								entity: v.movable.value,
								duration: duration,
								geometry: v.coordinate.value,
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
		handle: (v, f, node): ActionSetDirection => {
			const entity = coerceToString(f, node, v.entity, 'entity');
			if (!isDirectionTarget(v.target)) {
				throw new Error('invalid target');
			}
			return {
				...v.target,
				entity,
			};
		},
	},
	action_set_script: {
		values: {},
		captures: ['entity', 'script_slot', 'script'],
		handle: (v, f, node): ActionSetScript | undefined => {
			const entity = coerceToString(f, node, v.entity, 'entity');
			const script_slot = coerceToString(f, node, v.script_slot, 'script_slot');
			const script = coerceToString(f, node, v.script, 'script');
			if (entity === '%MAP%') {
				if (script_slot === 'on_tick') {
					return {
						action: 'SET_MAP_TICK_SCRIPT',
						script,
					};
				} else if (script_slot === 'on_tick') {
					return {
						action: 'SET_MAP_LOOK_SCRIPT',
						script,
					};
				}
				const errorNode = mandatoryChildForFieldName(f, node, 'script_slot');
				f.newError({
					message: `invalid map script slot`,
					locations: [{ node: errorNode }],
					footer: `You can only set a map's 'on_tick' or 'on_look' slot`,
				});
				return;
			}
			// not a map; must be an entity
			if (v.script_slot === 'on_tick') {
				return {
					action: 'SET_ENTITY_TICK_SCRIPT',
					entity,
					script,
				};
			}
			if (v.script_slot === 'on_interact') {
				return {
					action: 'SET_ENTITY_INTERACT_SCRIPT',
					entity,
					script,
				};
			}
			if (v.script_slot === 'on_look') {
				return {
					action: 'SET_ENTITY_LOOK_SCRIPT',
					entity,
					script,
				};
			}
			const errorNode = mandatoryChildForFieldName(f, node, 'script_slot');
			f.newError({
				message: `invalid entity script slot`,
				locations: [{ node: errorNode }],
				footer: `Valid entity script slots: 'on_tick', 'on_interact', 'on_look'`,
			});
		},
	},
	action_set_entity_string: {
		values: {},
		captures: ['entity', 'field', 'value'],
		handle: (v, f, node): ActionSetEntityString => {
			const entity = coerceToString(f, node, v.entity, 'entity');
			const value = coerceToString(f, node, v.value, 'value');
			if (v.field === 'name') {
				return {
					action: 'SET_ENTITY_NAME',
					string: value,
					entity: entity,
				};
			} else if (v.field === 'type') {
				return {
					action: 'SET_ENTITY_TYPE',
					entity_type: value,
					entity: entity,
				};
			} else if (v.field === 'path') {
				return {
					action: 'SET_ENTITY_PATH',
					entity: entity,
					geometry: value,
				};
			}
			throw new Error('invalid field?');
		},
	},
	action_op_equals: {
		values: {},
		captures: ['lhs', 'operator', 'rhs'],
		handle: (v, f, node): AnyNode => {
			const op = coerceToString(f, node, v.operator, 'op');

			// LHS is a string, meaning we're doing a thing to an integer variable
			if (typeof v.lhs === 'string') {
				// varName += 1
				if (typeof v.rhs === 'number') {
					return changeVarByValue(v.lhs, v.rhs, op);
				}
				// varName += var2
				if (typeof v.rhs === 'string') {
					return changeVarByVar(v.lhs, v.rhs, op);
				}
				// varName += player x
				if (isIntGetable(v.rhs)) {
					const temp = quickTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, temp),
						changeVarByVar(v.lhs, temp, op),
					];
					return newSequence(
						f,
						node,
						steps,
						'parser-actions: action_op_equals (LHS: string, RHS: IntGetable)',
					);
				}
				// varName += (var2 * 7)
				if (isIntBinaryExpression(v.rhs)) {
					const temporary = newTemporary();
					if (!isIntBinaryExpression(v.rhs)) throw new Error('not IntBinaryExpression');
					const steps = flattenIntBinaryExpression(v.rhs, []);
					dropTemporary();
					steps.push(changeVarByVar(v.lhs, temporary, op));
					return newSequence(
						f,
						node,
						steps,
						'action_op_equals (LHS: string, RHS: IntBinaryExpression)',
					);
				}
				throw new Error('unknown op equals type');
			}

			// LHS is an int getable, like `player y`
			// Can only set these to set values; cannot do math to them.
			// First put the value into a temporary, then do the math to that, then set it back.
			if (isIntGetable(v.lhs)) {
				// player x = 1;
				if (typeof v.rhs === 'number') {
					const temporary = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary),
						changeVarByValue(temporary, v.rhs, op),
						copyVarIntoEntityField(temporary, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					return newSequence(
						f,
						node,
						steps,
						'parser-actions: action_op_equals (LHS: IntGetable, RHS: number)',
					);
				}
				// player x = varName;
				if (typeof v.rhs === 'string') {
					const temporary = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary),
						changeVarByVar(temporary, v.rhs, op),
						copyVarIntoEntityField(temporary, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					return newSequence(
						f,
						node,
						steps,
						'parser-actions: action_op_equals (LHS: IntGetable, RHS: string)',
					);
				}
				// player x = (varName * 7);
				if (isIntBinaryExpression(v.rhs)) {
					const temporary1 = newTemporary();
					const temporary2 = newTemporary();
					if (!isIntBinaryExpression(v.rhs)) throw new Error('not IntBinaryExpression');
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary1),
						...flattenIntBinaryExpression(v.rhs, []),
						changeVarByVar(temporary1, temporary2, op),
						copyVarIntoEntityField(temporary1, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					dropTemporary();
					return newSequence(
						f,
						node,
						steps,
						'parser-actions: action_op_equals (LHS: IntGetable, RHS: IntBinaryExpression)',
					);
				}
				// player x = self y;
				if (isIntGetable(v.rhs)) {
					const temporary1 = newTemporary();
					const temporary2 = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary1),
						copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, temporary2),
						changeVarByVar(temporary1, temporary2, op),
						copyVarIntoEntityField(temporary1, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					dropTemporary();
					return newSequence(
						f,
						node,
						steps,
						'parser-actions: action_op_equals (LHS: IntGetable, RHS: IntGetable)',
					);
				}
			}
			throw new Error('unknown op equals type');
		},
	},
	action_plus_minus_equals_ables: {
		values: {},
		captures: ['entity', 'operator', 'value'],
		handle: (v, f, node): SET_ENTITY_DIRECTION_RELATIVE => {
			const entity = coerceToString(f, node, v.entity, 'entity');
			const op = coerceToString(f, node, v.operator, 'operator');
			if (op !== '-=' && op !== '+=') {
				throw new Error('invalid op: ' + op);
			}
			const value = coerceToNumber(f, node, v.value, 'value');
			const sign = op === '-=' ? -1 : 1;
			return {
				action: 'SET_ENTITY_DIRECTION_RELATIVE',
				entity,
				relative_direction: sign * value,
			};
		},
	},
};

// ------------------------ MAKE JSON ACTIONS ------------------------ //

export const showSerialDialog = (
	name: string,
	disable_newline: boolean = false,
): SHOW_SERIAL_DIALOG => ({
	action: 'SHOW_SERIAL_DIALOG',
	serial_dialog: name,
	disable_newline,
});
const setVarToValue = (variable: string, value: number): MUTATE_VARIABLE => ({
	action: 'MUTATE_VARIABLE',
	operation: 'SET',
	value,
	variable,
});
const setVarToVar = (variable: string, source: string): MUTATE_VARIABLES | CommentNode => {
	if (variable === source) {
		return newComment(`This action was optimized out (setting '${variable}' to itself)`);
	}
	return {
		action: 'MUTATE_VARIABLES',
		operation: 'SET',
		source,
		variable,
	};
};
export const changeVarByValue = (
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
		newCheckSaveFlag(f, node, source, !invert),
		[{ ...action, bool_value: true }], // if true
		[{ ...action, bool_value: false }], // if false
	);
};
