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
	getBoolFieldForAction,
	type ActionSetPosition,
	type ActionSetDirection,
	type ActionSetScript,
	type ActionMoveOverTime,
	type ActionSetEntityString,
	type ActionSetEntityInt,
	type ActionSetBool,
	MGSDebug,
	MUTATE_VARIABLE,
	MUTATE_VARIABLES,
	RUN_SCRIPT,
	NON_BLOCKING_DELAY,
	BLOCKING_DELAY,
	COPY_VARIABLE,
	SET_ENTITY_DIRECTION_RELATIVE,
	UNREGISTER_SERIAL_DIALOG_COMMAND,
	UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT,
	SET_ENTITY_X,
	SET_ENTITY_Y,
	SET_ENTITY_NAME,
	SET_ENTITY_TYPE,
	SET_ENTITY_INTERACT_SCRIPT,
	SET_ENTITY_TICK_SCRIPT,
	SET_ENTITY_PRIMARY_ID,
	SET_ENTITY_SECONDARY_ID,
	SET_ENTITY_CURRENT_FRAME,
	SET_ENTITY_CURRENT_ANIMATION,
	SET_ENTITY_PRIMARY_ID_TYPE,
	SET_ENTITY_GLITCHED,
	SET_ENTITY_PATH,
	GOTO_ACTION_INDEX,
	SET_SAVE_FLAG,
	SHOW_DIALOG,
	SHOW_SERIAL_DIALOG,
	CLOSE_DIALOG,
	CLOSE_SERIAL_DIALOG,
	SLOT_SAVE,
	SLOT_LOAD,
	SLOT_ERASE,
	LOAD_MAP,
	UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS,
	SET_SERIAL_DIALOG_COMMAND_VISIBILITY,
	SET_SCREEN_SHAKE,
	SCREEN_FADE_IN,
	SCREEN_FADE_OUT,
	SET_SCRIPT_PAUSE,
	SET_WARP_STATE,
	PLAY_ENTITY_ANIMATION,
	SET_CONNECT_SERIAL_DIALOG,
	REGISTER_SERIAL_DIALOG_COMMAND_ALIAS,
	REGISTER_SERIAL_DIALOG_COMMAND,
	REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT,
	SET_ENTITY_MOVEMENT_RELATIVE,
	TELEPORT_ENTITY_TO_GEOMETRY,
	TELEPORT_CAMERA_TO_GEOMETRY,
	SET_CAMERA_TO_FOLLOW_ENTITY,
	SET_LIGHTS_STATE,
	SET_PLAYER_CONTROL,
	SET_LIGHTS_CONTROL,
	SET_HEX_EDITOR_STATE,
	SET_HEX_EDITOR_DIALOG_MODE,
	SET_SERIAL_DIALOG_CONTROL,
	SET_HEX_EDITOR_CONTROL_CLIPBOARD,
	SET_HEX_EDITOR_CONTROL,
	PAN_CAMERA_TO_ENTITY,
	PAN_CAMERA_TO_GEOMETRY,
	PAN_CAMERA_ALONG_GEOMETRY,
	LOOP_CAMERA_ALONG_GEOMETRY,
	WALK_ENTITY_TO_GEOMETRY,
	WALK_ENTITY_ALONG_GEOMETRY,
	LOOP_ENTITY_ALONG_GEOMETRY,
	SET_MAP_LOOK_SCRIPT,
	SET_MAP_TICK_SCRIPT,
	SET_ENTITY_LOOK_SCRIPT,
	CHECK_SAVE_FLAG,
	summonActionConstructor,
	GotoLabel,
	BoolGetable,
	SET_ENTITY_DIRECTION,
	SET_ENTITY_DIRECTION_TARGET_ENTITY,
	SET_ENTITY_DIRECTION_TARGET_GEOMETRY,
} from './parser-bytecode-info.ts';
import {
	type AnyNode,
	DialogDefinition,
	CommentNode,
	IntBinaryExpression,
	type MGSMessage,
	type BoolExpression,
	SerialDialogDefinition,
	isBoolExpression,
	isBoolComparison,
	MathlangSequence,
	ReturnStatement,
	BreakStatement,
	ContinueStatement,
	BoolSetable,
	MovableIdentifier,
	CoordinateIdentifier,
	DirectionTarget,
	IntGetable,
	SerialDialog,
	Dialog,
} from './parser-types.ts';
import {
	autoIdentifierName,
	newTemporary,
	dropTemporary,
	quickTemporary,
	latestTemporary,
	simpleBranchMaker,
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

const flattenIntBinaryExpression = (
	debug: MGSDebug,
	exp: IntBinaryExpression,
	steps: AnyNode[],
): AnyNode[] => {
	const temp = latestTemporary();
	const lhs = exp.lhs;
	const op = exp.op;
	const rhs = exp.rhs;
	if (typeof lhs === 'string') {
		steps.push(setVarToVar(debug, temp, lhs));
	} else if (typeof lhs === 'number') {
		steps.push(setVarToValue(temp, lhs));
	} else if (lhs instanceof IntGetable) {
		steps.push(copyEntityFieldIntoVar(lhs.entity, lhs.field, temp));
	} else if (lhs instanceof IntBinaryExpression) {
		// can use the same temporary since it's the lhs and we're going LTR
		// (and operator precedence is now baked into the AST)
		flattenIntBinaryExpression(debug, lhs, steps);
	}
	if (typeof rhs === 'string') {
		steps.push(changeVarByVar(temp, rhs, op));
	} else if (typeof rhs === 'number') {
		if (invisibleMath(op, rhs)) {
			// invisible == *1 or +0
		} else {
			steps.push(changeVarByValue(debug, temp, rhs, op));
		}
	} else if (rhs instanceof IntGetable) {
		const quickTemp = quickTemporary();
		steps.push(
			copyEntityFieldIntoVar(rhs.entity, rhs.field, quickTemp),
			changeVarByVar(temp, quickTemp, op),
		);
	} else if (rhs instanceof IntBinaryExpression) {
		const newTemp = newTemporary();
		flattenIntBinaryExpression(debug, rhs, steps);
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
			? new CHECK_SAVE_FLAG({ save_flag: _rhsBoolExp, expected_bool: true })
			: _rhsBoolExp;
	const falseClone = summonActionConstructor(lhsSetAction);
	falseClone.invert();
	if (rhsBoolExp instanceof BoolGetable || isBoolComparison(rhsBoolExp)) {
		return simpleBranchMaker(
			f,
			rhsBoolExp.debug?.node || backupNode,
			rhsBoolExp,
			[lhsSetAction],
			[falseClone],
		);
	}

	return simpleBranchMaker(
		f,
		rhsBoolExp.debug?.node || backupNode,
		rhsBoolExp,
		[lhsSetAction],
		[falseClone],
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
		debug: new MGSDebug(f, node),
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
		spreads.forEach((v, i) => {
			const handled = handleFn(v, f, node, i) as GenericActionish;
			const realAction = handled.clone
				? handled.clone(handled)
				: summonActionConstructor(handled);
			if (realAction) {
				spreads[i] = realAction;
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
		const dialogName = tryName !== null ? tryName : autoIdentifierName(f, node);
		const dialogs = handleChildrenForFieldName(f, node, 'dialog');
		const shownDialog = new SHOW_DIALOG({ dialog: dialogName });
		if (dialogs.length) {
			if (!dialogs.every((v) => v instanceof Dialog)) {
				throw new Error('parsed dialogs not all of type Dialog');
			}
			const dialogDefinition = new DialogDefinition(new MGSDebug(f, node), {
				dialogName,
				dialogs,
			});
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
	const shownSerialDialog = new SHOW_SERIAL_DIALOG({ serial_dialog: name, disable_newline });
	if (serialDialogs.length) {
		if (!(serialDialogs[0] instanceof SerialDialog)) {
			throw new Error('parsed serial dialogs not all of type SerialDialog');
		}
		const serialDialoDefinition = new SerialDialogDefinition(new MGSDebug(f, node), {
			dialogName: name,
			serialDialog: serialDialogs[0],
		});
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
		handle: (v, f, node) => new ReturnStatement(new MGSDebug(f, node)),
	},
	action_continue_statement: {
		handle: (v, f, node) => new ContinueStatement(new MGSDebug(f, node)),
	},
	action_break_statement: {
		handle: (v, f, node) => new BreakStatement(new MGSDebug(f, node)),
	},
	action_close_dialog: {
		handle: () => new CLOSE_DIALOG(),
	},
	action_close_serial_dialog: {
		handle: () => new CLOSE_SERIAL_DIALOG(),
	},
	action_save_slot: {
		handle: () => new SLOT_SAVE(),
	},
	action_load_slot: {
		captures: ['slot'],
		handle: (v) => new SLOT_LOAD(v),
	},
	action_erase_slot: {
		captures: ['slot'],
		handle: (v) => new SLOT_ERASE(v),
	},
	action_load_map: {
		captures: ['map'],
		handle: (v) => new LOAD_MAP(v),
	},
	action_goto_label: {
		captures: ['label'],
		handle: (v, f, node) => new GotoLabel(new MGSDebug(f, node), { label: v.label }),
	},
	action_goto_index: {
		captures: ['action_index'],
		handle: (v) => new GOTO_ACTION_INDEX(v),
	},
	action_run_script: {
		captures: ['script'],
		handle: (v) => new RUN_SCRIPT(v),
	},
	action_non_blocking_delay: {
		captures: ['duration'],
		handle: (v) => new NON_BLOCKING_DELAY(v),
	},
	action_blocking_delay: {
		captures: ['duration'],
		handle: (v) => new BLOCKING_DELAY(v),
	},
	action_delete_command: {
		captures: ['command'],
		handle: (v) => new UNREGISTER_SERIAL_DIALOG_COMMAND(v),
	},
	action_delete_command_arg: {
		captures: ['command', 'argument'],
		handle: (v) => new UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT(v),
	},
	action_delete_alias: {
		captures: ['alias'],
		handle: (v) => new UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS(v),
	},
	action_hide_command: {
		values: { is_visible: false },
		captures: ['command'],
		handle: (v) => new SET_SERIAL_DIALOG_COMMAND_VISIBILITY(v),
	},
	action_unhide_command: {
		values: { is_visible: true },
		captures: ['command'],
		handle: (v) => new SET_SERIAL_DIALOG_COMMAND_VISIBILITY(v),
	},
	action_camera_shake: {
		captures: ['frequency', 'amplitude', 'duration'],
		handle: (v) => new SET_SCREEN_SHAKE(v),
	},
	action_camera_fade_in: {
		captures: ['color', 'duration'],
		handle: (v) => new SCREEN_FADE_IN(v),
	},
	action_camera_fade_out: {
		captures: ['color', 'duration'],
		handle: (v) => new SCREEN_FADE_OUT(v),
	},
	action_pause_script: {
		values: { bool_value: true },
		captures: ['script_slot', 'entity'],
		handle: (v) => new SET_SCRIPT_PAUSE(v),
	},
	action_unpause_script: {
		values: { bool_value: false },
		captures: ['script_slot', 'entity'],
		handle: (v) => new SET_SCRIPT_PAUSE(v),
	},
	action_play_entity_animation: {
		captures: ['entity', 'animation', 'play_count'],
		handle: (v) => new PLAY_ENTITY_ANIMATION(v),
	},
	action_set_warp_state: {
		captures: ['string'],
		handle: (v) => new SET_WARP_STATE(v),
	},
	action_set_serial_connect: {
		captures: ['serial_dialog'],
		handle: (v) => new SET_CONNECT_SERIAL_DIALOG(v),
	},
	action_set_alias: {
		captures: ['alias', 'command'],
		handle: (v) => new REGISTER_SERIAL_DIALOG_COMMAND_ALIAS(v),
	},
	action_set_command: {
		values: { is_fail: false },
		captures: ['command', 'script'],
		handle: (v) => new REGISTER_SERIAL_DIALOG_COMMAND(v),
	},
	action_set_command_fail: {
		values: { is_fail: true },
		captures: ['command', 'script'],
		handle: (v) => new REGISTER_SERIAL_DIALOG_COMMAND(v),
	},
	action_set_command_arg: {
		values: { is_fail: true },
		captures: ['command', 'argument', 'script'],
		handle: (v) => new REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT(v),
	},
	action_set_ambiguous: {
		// if the LHS is ambiguous (a variable name)
		values: {},
		captures: ['lhs', 'rhs'],
		handle: (v, f, node, i): AnyNode => {
			const debug = new MGSDebug(f, node);
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
				return setVarToVar(debug, lhs, v.rhs);
			}

			// varName = player x;
			if (v.rhs instanceof IntGetable) {
				return copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, lhs);
			}

			// varName = (255 + player x);
			if (v.rhs instanceof IntBinaryExpression) {
				const temporary = newTemporary(lhs);
				const steps = flattenIntBinaryExpression(debug, v.rhs, []);
				dropTemporary();
				steps.push(setVarToVar(debug, lhs, temporary));
				return new MathlangSequence(debug, {
					steps,
					type: 'parser-actions: action_set_ambiguous',
				});
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
			const debug = new MGSDebug(f, node);
			if (!(v.lhs instanceof IntGetable)) {
				throw new Error('LHS not int_getable');
			}
			const entity = coerceToString(f, node, v.lhs.entity, 'action_set_int entity');

			// player x = 0;
			if (typeof v.rhs === 'number') {
				if (v.lhs.field === 'x') {
					return new SET_ENTITY_X({ entity, u2_value: v.rhs });
				}
				if (v.lhs.field === 'y') {
					return new SET_ENTITY_Y({ entity, u2_value: v.rhs });
				}
				if (v.lhs.field === 'primary_id') {
					return new SET_ENTITY_PRIMARY_ID({ entity, u2_value: v.rhs });
				}
				if (v.lhs.field === 'secondary_id') {
					return new SET_ENTITY_SECONDARY_ID({ entity, u2_value: v.rhs });
				}
				if (v.lhs.field === 'primary_id_type') {
					return new SET_ENTITY_PRIMARY_ID_TYPE({ entity, byte_value: v.rhs });
				}
				if (v.lhs.field === 'current_animation') {
					return new SET_ENTITY_CURRENT_ANIMATION({ entity, byte_value: v.rhs });
				}
				if (v.lhs.field === 'animation_frame') {
					return new SET_ENTITY_CURRENT_FRAME({ entity, byte_value: v.rhs });
				}
				if (v.lhs.field === 'strafe') {
					return new SET_ENTITY_MOVEMENT_RELATIVE({ entity, relative_direction: v.rhs });
				}
				if (v.lhs.field === 'relative_direction') {
					return new SET_ENTITY_DIRECTION_RELATIVE({ entity, relative_direction: v.rhs });
				}
				throw new Error('unidentified int_getable, field: ' + v.lhs.field);
			}

			// player x = varName;
			if (typeof v.rhs === 'string') {
				return copyVarIntoEntityField(v.rhs, v.lhs.entity, v.lhs.field);
			}

			// player x = player y;
			if (v.rhs instanceof IntBinaryExpression) {
				const temporary = newTemporary();
				const steps = flattenIntBinaryExpression(debug, v.rhs, []);
				dropTemporary();
				steps.push(copyVarIntoEntityField(temporary, v.lhs.entity, v.lhs.field));
				return new MathlangSequence(debug, {
					steps,
					type: 'parser-actions: action_set_int',
				});
			}

			throw new Error('unknown RHS type');
		},
	},
	action_set_bool: {
		// If we've matched this, we know the LHS is not a variable name.
		values: {},
		captures: ['lhs', 'rhs'],
		handle: (v, f, node): MathlangSequence | ActionSetBool => {
			if (!(v.lhs instanceof BoolSetable)) {
				throw new Error('LHS not a bool_setable');
			}
			if (!isBoolExpression(v.rhs)) {
				throw new Error('RHS not a bool_expression');
			}
			if (v.lhs.type === 'entity') {
				const entity = coerceToString(
					f,
					node,
					v.lhs.value,
					'SET_ENTITY_GLITCHED field entity',
				);
				const lhs: ActionSetBool = new SET_ENTITY_GLITCHED({ entity, bool_value: true });
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'light') {
				const lhs = new SET_LIGHTS_STATE({
					lights: coerceToString(f, node, v.lhs.value, 'SET_LIGHTS_STATE field lights'),
					enabled: true,
				});
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'player_control') {
				const lhs = new SET_PLAYER_CONTROL({ bool_value: true });
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'lights_control') {
				const lhs = new SET_LIGHTS_CONTROL({ enabled: true });
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'hex_editor') {
				const lhs = new SET_HEX_EDITOR_STATE({ bool_value: true });
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'hex_dialog_mode') {
				const lhs = new SET_HEX_EDITOR_DIALOG_MODE({ bool_value: true });
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'hex_control') {
				const lhs = new SET_HEX_EDITOR_CONTROL({ bool_value: true });
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'hex_clipboard') {
				const lhs = new SET_HEX_EDITOR_CONTROL_CLIPBOARD({ bool_value: true });
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			if (v.lhs.type === 'serial_control') {
				const lhs = new SET_SERIAL_DIALOG_CONTROL({ bool_value: true });
				return actionSetBoolMaker(f, lhs, v.rhs, node);
			}
			throw new Error('unknown LHS type');
		},
	},
	action_set_position: {
		values: {},
		captures: ['movable', 'coordinate'],
		handle: (v, f, node): ActionSetPosition | MathlangSequence => {
			const debug = new MGSDebug(f, node);
			if (!(v.movable instanceof MovableIdentifier)) {
				throw new Error('invalid MovableIdentifier');
			}
			if (!(v.coordinate instanceof CoordinateIdentifier)) {
				throw new Error('invalid CoordinateIdentifier');
			}
			if (v.movable.type === 'camera') {
				if (v.coordinate.type === 'geometry' && v.coordinate.polygonType !== 'length') {
					return new TELEPORT_CAMERA_TO_GEOMETRY({
						geometry: v.coordinate.value,
					});
				}
				if (v.coordinate.type === 'entity') {
					return new SET_CAMERA_TO_FOLLOW_ENTITY({
						entity: v.coordinate.value,
					});
				}
			} else if (v.movable.type === 'entity') {
				if (v.coordinate.type === 'geometry' && v.coordinate.polygonType !== 'length') {
					return new TELEPORT_ENTITY_TO_GEOMETRY({
						entity: v.movable.value,
						geometry: v.coordinate.value,
					});
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
					return new MathlangSequence(debug, {
						steps,
						type: 'parser-actions: action_set_position',
					});
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
			if (!(v.movable instanceof MovableIdentifier)) {
				throw new Error('invalid MovableIdentifier');
			}
			if (!(v.coordinate instanceof CoordinateIdentifier)) {
				throw new Error('invalid CoordinateIdentifier');
			}
			if (!(v.debug instanceof MGSDebug)) {
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
						return new PAN_CAMERA_TO_ENTITY({
							duration: duration,
							entity: v.coordinate.value,
						});
					}
				}
				if (v.coordinate.type === 'geometry') {
					// ... to a geometry
					if (v.coordinate.polygonType === 'length') {
						// ... length
						if (v.forever) {
							// ... forever
							return new LOOP_CAMERA_ALONG_GEOMETRY({
								duration: duration,
								geometry: v.coordinate.value,
							});
						} else {
							// ... not forever
							return new PAN_CAMERA_ALONG_GEOMETRY({
								duration: duration,
								geometry: v.coordinate.value,
							});
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
							return new PAN_CAMERA_TO_GEOMETRY({
								duration: duration,
								geometry: v.coordinate.value,
							});
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
							return new LOOP_ENTITY_ALONG_GEOMETRY({
								entity: v.movable.value,
								duration: duration,
								geometry: v.coordinate.value,
							});
						} else {
							// ... not forever
							return new WALK_ENTITY_ALONG_GEOMETRY({
								entity: v.movable.value,
								duration: duration,
								geometry: v.coordinate.value,
							});
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
							return new WALK_ENTITY_TO_GEOMETRY({
								entity: v.movable.value,
								duration: duration,
								geometry: v.coordinate.value,
							});
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
			if (!(v.target instanceof DirectionTarget)) {
				throw new Error('action_set_direction target not a DirectionTarget');
			}
			if (v.target.type === 'nsew') {
				return new SET_ENTITY_DIRECTION({
					entity,
					direction: v.target.value,
				});
			}
			if (v.target.type === 'geometry') {
				return new SET_ENTITY_DIRECTION_TARGET_GEOMETRY({
					entity,
					target_geometry: v.target.value,
				});
			}
			if (v.target.type === 'entity') {
				return new SET_ENTITY_DIRECTION_TARGET_ENTITY({
					entity,
					target_entity: v.target.value,
				});
			}
			throw new Error('invalid type of DirectionTarget');
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
					return new SET_MAP_TICK_SCRIPT({ script });
				} else if (script_slot === 'on_tick') {
					return new SET_MAP_LOOK_SCRIPT({ script });
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
				return new SET_ENTITY_TICK_SCRIPT({ entity, script });
			}
			if (v.script_slot === 'on_interact') {
				return new SET_ENTITY_INTERACT_SCRIPT({ entity, script });
			}
			if (v.script_slot === 'on_look') {
				return new SET_ENTITY_LOOK_SCRIPT({ entity, script });
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
				return new SET_ENTITY_NAME({ string: value, entity });
			} else if (v.field === 'type') {
				return new SET_ENTITY_TYPE({ entity_type: value, entity });
			} else if (v.field === 'path') {
				return new SET_ENTITY_PATH({ entity, geometry: value });
			}
			throw new Error('invalid field?');
		},
	},
	action_op_equals: {
		values: {},
		captures: ['lhs', 'operator', 'rhs'],
		handle: (v, f, node): AnyNode => {
			const debug = new MGSDebug(f, node);
			const op = coerceToString(f, node, v.operator, 'op');

			// LHS is a string, meaning we're doing a thing to an integer variable
			if (typeof v.lhs === 'string') {
				// varName += 1
				if (typeof v.rhs === 'number') {
					return changeVarByValue(debug, v.lhs, v.rhs, op);
				}
				// varName += var2
				if (typeof v.rhs === 'string') {
					return changeVarByVar(v.lhs, v.rhs, op);
				}
				// varName += player x
				if (v.rhs instanceof IntGetable) {
					const temp = quickTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.rhs.entity, v.rhs.field, temp),
						changeVarByVar(v.lhs, temp, op),
					];
					return new MathlangSequence(debug, {
						steps,
						type: 'parser-actions: action_op_equals (LHS: string, RHS: IntGetable)',
					});
				}
				// varName += (var2 * 7)
				if (v.rhs instanceof IntBinaryExpression) {
					const temporary = newTemporary();
					if (!(v.rhs instanceof IntBinaryExpression)) {
						throw new Error('not IntBinaryExpression');
					}
					const steps = flattenIntBinaryExpression(debug, v.rhs, []);
					dropTemporary();
					steps.push(changeVarByVar(v.lhs, temporary, op));
					return new MathlangSequence(debug, {
						steps,
						type: 'action_op_equals (LHS: string, RHS: IntBinaryExpression)',
					});
				}
				throw new Error('unknown op equals type');
			}

			// LHS is an int getable, like `player y`
			// Can only set these to set values; cannot do math to them.
			// First put the value into a temporary, then do the math to that, then set it back.
			if (v.lhs instanceof IntGetable) {
				// player x = 1;
				if (typeof v.rhs === 'number') {
					const temporary = newTemporary();
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary),
						changeVarByValue(debug, temporary, v.rhs, op),
						copyVarIntoEntityField(temporary, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					return new MathlangSequence(debug, {
						steps,
						type: 'parser-actions: action_op_equals (LHS: IntGetable, RHS: number)',
					});
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
					return new MathlangSequence(debug, {
						steps,
						type: 'parser-actions: action_op_equals (LHS: IntGetable, RHS: string)',
					});
				}
				// player x = (varName * 7);
				if (v.rhs instanceof IntBinaryExpression) {
					const temporary1 = newTemporary();
					const temporary2 = newTemporary();
					if (!(v.rhs instanceof IntBinaryExpression)) {
						throw new Error('not IntBinaryExpression');
					}
					const steps = [
						copyEntityFieldIntoVar(v.lhs.entity, v.lhs.field, temporary1),
						...flattenIntBinaryExpression(debug, v.rhs, []),
						changeVarByVar(temporary1, temporary2, op),
						copyVarIntoEntityField(temporary1, v.lhs.entity, v.lhs.field),
					];
					dropTemporary();
					dropTemporary();
					return new MathlangSequence(debug, {
						steps,
						type: 'parser-actions: action_op_equals (LHS: IntGetable, RHS: IntBinaryExpression)',
					});
				}
				// player x = self y;
				if (v.rhs instanceof IntGetable) {
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
					return new MathlangSequence(debug, {
						steps,
						type: 'parser-actions: action_op_equals (LHS: IntGetable, RHS: IntGetable)',
					});
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
			return new SET_ENTITY_DIRECTION_RELATIVE({
				entity,
				relative_direction: sign * value,
			});
		},
	},
};

// ------------------------ MAKE JSON ACTIONS ------------------------ //

export const showSerialDialog = (name: string, disable_newline: boolean = false) =>
	new SHOW_SERIAL_DIALOG({
		serial_dialog: name,
		disable_newline,
	});
const setVarToValue = (variable: string, value: number): MUTATE_VARIABLE => {
	return new MUTATE_VARIABLE({ operation: 'SET', value, variable });
};
const setVarToVar = (
	debug: MGSDebug,
	variable: string,
	source: string,
): MUTATE_VARIABLES | CommentNode => {
	if (variable === source) {
		return new CommentNode(debug, {
			comment: `This action was optimized out (setting '${variable}' to itself)`,
		});
	}
	return new MUTATE_VARIABLES({ operation: 'SET', source, variable });
};
export const changeVarByValue = (
	debug: MGSDebug,
	variable: string,
	value: number,
	op: string,
): MUTATE_VARIABLE | CommentNode => {
	if (op === '+' && value === 0) {
		return new CommentNode(debug, { comment: 'This action was optimized out (+ 0)' });
	}
	if (op === '*' && value === 1) {
		return new CommentNode(debug, { comment: 'This action was optimized out (* 1)' });
	}
	if (op === '/' && value === 1) {
		return new CommentNode(debug, { comment: 'This action was optimized out (/ 1)' });
	}
	if (op === '-' && value === 0) {
		return new CommentNode(debug, { comment: 'This action was optimized out (- 0)' });
	}
	return new MUTATE_VARIABLE({ operation: opIntoStringMap[op] || op, value, variable });
};
const changeVarByVar = (variable: string, source: string, op: string) => {
	return new MUTATE_VARIABLES({
		operation: opIntoStringMap[op] || op,
		source,
		variable,
	});
};
const copyVarIntoEntityField = (variable: string, entity: string, field: string) => {
	return new COPY_VARIABLE({ entity, field, inbound: false, variable });
};
const copyEntityFieldIntoVar = (entity: string, field: string, variable: string) => {
	return new COPY_VARIABLE({ entity, field, inbound: true, variable });
};
const setFlag = (save_flag: string, bool_value: boolean) => {
	return new SET_SAVE_FLAG({ save_flag, bool_value });
};

const setFlagToFlag = (
	f: FileState,
	node: TreeSitterNode,
	save_flag: string,
	source: string,
	invert?: boolean,
): MathlangSequence => {
	const actionIfTrue = setFlag(save_flag, true);
	const actionIfFalse = setFlag(save_flag, false);
	return simpleBranchMaker(
		f,
		node,
		new CHECK_SAVE_FLAG({ save_flag: source, expected_bool: !invert }),
		[actionIfTrue],
		[actionIfFalse],
	);
};
