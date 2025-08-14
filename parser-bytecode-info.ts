import { Node as TreeSitterNode } from 'web-tree-sitter';
import {
	LabelDefinition,
	ReturnStatement,
	CopyMacro,
	AnyNode,
	GotoLabel,
	CommentNode,
	MathlangLocation,
} from './parser-types.ts';
import { type GenericActionish } from './parser-actions.ts';
import { type FileState } from './parser-file.ts';
import { simpleBranchMaker } from './parser-utilities.ts';

const opIntoStringMap: Record<string, string> = {
	'=': 'SET',
	'+': 'ADD',
	'-': 'SUB',
	'*': 'MUL',
	'/': 'DIV',
	'%': 'MOD',
	'?': 'RNG',
};

export class Action extends AnyNode {
	action: string;
	clone() {
		const fn = actionConstructorLookup[this.action];
		if (!fn) throw new Error('no action constructor for ' + this.action);
		return fn();
	}
}

// ---------------------------------- SUPER TYPES ---------------------------------- \\

export class BoolGetable extends Action {
	mathlang: 'bool_getable';
	comment?: string;
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	expected_bool: boolean;
	invert() {
		this.expected_bool = !this.expected_bool;
	}
}
export class StringCheckable extends Action {
	mathlang: 'string_checkable';
	comment?: string;
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	expected_bool: boolean;
	constructor() {
		super();
		this.expected_bool = true;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	updateProp(_prop: string) {}
}
export class NumberComparison extends Action {
	mathlang: 'number_comparison';
	comment?: string;
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	expected_bool: boolean;
	constructor() {
		super();
		this.expected_bool = true;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	updateProp(prop: boolean) {
		// to make squiggles go away; not used
		this.expected_bool = prop;
	}
}
export class NumberCheckableEquality extends Action {
	mathlang: 'number_checkable_equality';
	comment?: string;
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	expected_bool: boolean;
	constructor() {
		super();
		this.mathlang = 'number_checkable_equality';
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	updateProp(prop: string | number) {
		// to make squiggles go away; not used
		this.jump_index = prop;
	}
}

// ---------------------------------- ACTUAL BYTECODE JSON ---------------------------------- \\

// Todo: might not need the "debug" stuff; if actual action, errors would be reported at generation.
// No need to keep tree sitter nodes around, perhaps?

// not in encoder, but in old-style output
export class NULL_ACTION extends Action {
	action: 'NULL_ACTION';
	constructor() {
		super();
		this.action = 'NULL_ACTION';
	}
}
export class LABEL extends Action {
	action: 'LABEL';
	value: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'LABEL';
		this.value = breakIfNotString(args.value);
	}
}
export class RUN_SCRIPT extends Action {
	action: 'RUN_SCRIPT';
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'RUN_SCRIPT';
		this.script = breakIfNotString(args.script);
	}
	static quick(script: string) {
		return new RUN_SCRIPT({ script });
	}
}
export class BLOCKING_DELAY extends Action {
	action: 'BLOCKING_DELAY';
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'BLOCKING_DELAY';
		this.duration = breakIfNotNumber(args.duration);
	}
}
export class NON_BLOCKING_DELAY extends Action {
	action: 'NON_BLOCKING_DELAY';
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'NON_BLOCKING_DELAY';
		this.duration = breakIfNotNumber(args.duration);
	}
}

export class SET_ENTITY_NAME extends Action {
	action: 'SET_ENTITY_NAME';
	entity: string;
	string: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_NAME';
		this.entity = breakIfNotString(args.entity);
		this.string = breakIfNotString(args.string);
	}
	static quick(entity: string, string: string) {
		return new SET_ENTITY_NAME({ entity, string });
	}
}
export class SET_ENTITY_X extends Action {
	action: 'SET_ENTITY_X';
	entity: string;
	u2_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_X';
		this.entity = breakIfNotString(args.entity);
		this.u2_value = breakIfNotNumber(args.u2_value);
	}
	static quick(entity: string, u2_value: number) {
		return new SET_ENTITY_X({ entity, u2_value });
	}
}
export class SET_ENTITY_Y extends Action {
	action: 'SET_ENTITY_Y';
	entity: string;
	u2_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_Y';
		this.entity = breakIfNotString(args.entity);
		this.u2_value = breakIfNotNumber(args.u2_value);
	}
	static quick(entity: string, u2_value: number) {
		return new SET_ENTITY_Y({ entity, u2_value });
	}
}
export class SET_ENTITY_INTERACT_SCRIPT extends Action {
	action: 'SET_ENTITY_INTERACT_SCRIPT';
	entity: string;
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_INTERACT_SCRIPT';
		this.entity = breakIfNotString(args.entity);
		this.script = breakIfNotString(args.script);
	}
	static quick(entity: string, script: string) {
		return new SET_ENTITY_INTERACT_SCRIPT({ entity, script });
	}
}
export class SET_ENTITY_TICK_SCRIPT extends Action {
	action: 'SET_ENTITY_TICK_SCRIPT';
	entity: string;
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_TICK_SCRIPT';
		this.entity = breakIfNotString(args.entity);
		this.script = breakIfNotString(args.script);
	}
	static quick(entity: string, script: string) {
		return new SET_ENTITY_TICK_SCRIPT({ entity, script });
	}
}
export class SET_ENTITY_TYPE extends Action {
	action: 'SET_ENTITY_TYPE';
	entity: string;
	entity_type: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_TYPE';
		this.entity = breakIfNotString(args.entity);
		this.entity_type = breakIfNotString(args.entity_type);
	}
	static quick(entity: string, entity_type: string) {
		return new SET_ENTITY_TYPE({ entity, entity_type });
	}
}
export class SET_ENTITY_PRIMARY_ID extends Action {
	action: 'SET_ENTITY_PRIMARY_ID';
	entity: string;
	u2_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_PRIMARY_ID';
		this.entity = breakIfNotString(args.entity);
		this.u2_value = breakIfNotNumber(args.u2_value);
	}
	static quick(entity: string, u2_value: number) {
		return new SET_ENTITY_PRIMARY_ID({ entity, u2_value });
	}
}
export class SET_ENTITY_SECONDARY_ID extends Action {
	action: 'SET_ENTITY_SECONDARY_ID';
	entity: string;
	u2_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_SECONDARY_ID';
		this.entity = breakIfNotString(args.entity);
		this.u2_value = breakIfNotNumber(args.u2_value);
	}
	static quick(entity: string, u2_value: number) {
		return new SET_ENTITY_SECONDARY_ID({ entity, u2_value });
	}
}
export class SET_ENTITY_PRIMARY_ID_TYPE extends Action {
	action: 'SET_ENTITY_PRIMARY_ID_TYPE';
	entity: string;
	byte_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_PRIMARY_ID_TYPE';
		this.entity = breakIfNotString(args.entity);
		this.byte_value = breakIfNotNumber(args.byte_value);
	}
	static quick(entity: string, byte_value: number) {
		return new SET_ENTITY_PRIMARY_ID_TYPE({ entity, byte_value });
	}
}
export class SET_ENTITY_CURRENT_ANIMATION extends Action {
	action: 'SET_ENTITY_CURRENT_ANIMATION';
	entity: string;
	byte_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_CURRENT_ANIMATION';
		this.entity = breakIfNotString(args.entity);
		this.byte_value = breakIfNotNumber(args.byte_value);
	}
	static quick(entity: string, byte_value: number) {
		return new SET_ENTITY_CURRENT_ANIMATION({ entity, byte_value });
	}
}
export class SET_ENTITY_CURRENT_FRAME extends Action {
	action: 'SET_ENTITY_CURRENT_FRAME';
	entity: string;
	byte_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_CURRENT_FRAME';
		this.entity = breakIfNotString(args.entity);
		this.byte_value = breakIfNotNumber(args.byte_value);
	}
	static quick(entity: string, byte_value: number) {
		return new SET_ENTITY_CURRENT_FRAME({ entity, byte_value });
	}
}
export class SET_ENTITY_DIRECTION_RELATIVE extends Action {
	action: 'SET_ENTITY_DIRECTION_RELATIVE';
	entity: string;
	relative_direction: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_DIRECTION_RELATIVE';
		this.entity = breakIfNotString(args.entity);
		this.relative_direction = breakIfNotNumber(args.relative_direction);
	}
	static quick(entity: string, relative_direction: number) {
		return new SET_ENTITY_DIRECTION_RELATIVE({ entity, relative_direction });
	}
}
export class SET_ENTITY_DIRECTION extends Action {
	action: 'SET_ENTITY_DIRECTION';
	entity: string;
	direction: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_DIRECTION';
		this.entity = breakIfNotString(args.entity);
		this.direction = breakIfNotString(args.direction);
	}
	static quick(entity: string, direction: string) {
		return new SET_ENTITY_DIRECTION({ entity, direction });
	}
}
export class SET_ENTITY_DIRECTION_TARGET_ENTITY extends Action {
	action: 'SET_ENTITY_DIRECTION_TARGET_ENTITY';
	entity: string;
	target_entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_DIRECTION_TARGET_ENTITY';
		this.entity = breakIfNotString(args.entity);
		this.target_entity = breakIfNotString(args.target_entity);
	}
	static quick(entity: string, target_entity: string) {
		return new SET_ENTITY_DIRECTION_TARGET_ENTITY({ entity, target_entity });
	}
}
export class SET_ENTITY_DIRECTION_TARGET_GEOMETRY extends Action {
	action: 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY';
	entity: string;
	target_geometry: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY';
		this.entity = breakIfNotString(args.entity);
		this.target_geometry = breakIfNotString(args.target_geometry);
	}
	static quick(entity: string, target_geometry: string) {
		return new SET_ENTITY_DIRECTION_TARGET_GEOMETRY({ entity, target_geometry });
	}
}
export class SET_ENTITY_GLITCHED extends Action {
	action: 'SET_ENTITY_GLITCHED';
	entity: string;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_GLITCHED';
		this.entity = breakIfNotString(args.entity);
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
	static quick(entity: string, bool_value: boolean) {
		return new SET_ENTITY_GLITCHED({ entity, bool_value });
	}
}
export class SET_ENTITY_PATH extends Action {
	action: 'SET_ENTITY_PATH';
	entity: string;
	geometry: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_PATH';
		this.entity = breakIfNotString(args.entity);
		this.geometry = breakIfNotString(args.geometry);
	}
	static quick(entity: string, geometry: string) {
		return new SET_ENTITY_PATH({ entity, geometry });
	}
}

export class COPY_SCRIPT extends Action {
	action: 'COPY_SCRIPT';
	script: string;
	search_and_replace?: Record<string, string>;
	constructor(args: GenericActionish) {
		super();
		this.action = 'COPY_SCRIPT';
		this.script = breakIfNotString(args.script);
		if (args.search_and_replace) {
			const search_and_replace = {};
			Object.entries(args.search_and_replace).forEach(([k, v]) => {
				if (typeof k === 'string' && typeof v === 'string') search_and_replace[k] = v;
			});
			this.search_and_replace = search_and_replace;
		}
	}
}

export class SET_SAVE_FLAG extends Action {
	action: 'SET_SAVE_FLAG';
	save_flag: string;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SAVE_FLAG';
		this.save_flag = breakIfNotString(args.save_flag);
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
	static toValue(save_flag: string, bool_value: boolean) {
		return new SET_SAVE_FLAG({ save_flag, bool_value });
	}
	static toFlag(
		f: FileState,
		node: TreeSitterNode,
		save_flag: string,
		source: string,
		invert?: boolean,
	) {
		const actionIfTrue = SET_SAVE_FLAG.toValue(save_flag, true);
		const actionIfFalse = SET_SAVE_FLAG.toValue(save_flag, false);
		return simpleBranchMaker(
			f,
			node,
			new CHECK_SAVE_FLAG({ save_flag: source, expected_bool: !invert }),
			[actionIfTrue],
			[actionIfFalse],
		);
	}
}
export class SET_PLAYER_CONTROL extends Action {
	action: 'SET_PLAYER_CONTROL';
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_PLAYER_CONTROL';
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
	static quick(bool_value: boolean) {
		return new SET_PLAYER_CONTROL({ bool_value });
	}
}
export class SET_MAP_TICK_SCRIPT extends Action {
	action: 'SET_MAP_TICK_SCRIPT';
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_MAP_TICK_SCRIPT';
		this.script = breakIfNotString(args.script);
	}
	static quick(script: string) {
		return new SET_MAP_TICK_SCRIPT({ script });
	}
}
export class SET_HEX_CURSOR_LOCATION extends Action {
	action: 'SET_HEX_CURSOR_LOCATION';
	address: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_CURSOR_LOCATION';
		this.address = breakIfNotNumber(args.address);
	}
}
export class SET_WARP_STATE extends Action {
	action: 'SET_WARP_STATE';
	string: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_WARP_STATE';
		this.string = breakIfNotString(args.string);
	}
}
export class SET_HEX_EDITOR_STATE extends Action {
	action: 'SET_HEX_EDITOR_STATE';
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_EDITOR_STATE';
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
	static quick(bool_value: boolean) {
		return new SET_HEX_EDITOR_STATE({ bool_value });
	}
}
export class SET_HEX_EDITOR_DIALOG_MODE extends Action {
	action: 'SET_HEX_EDITOR_DIALOG_MODE';
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_EDITOR_DIALOG_MODE';
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
	static quick(bool_value: boolean) {
		return new SET_HEX_EDITOR_DIALOG_MODE({ bool_value });
	}
}
export class SET_HEX_EDITOR_CONTROL extends Action {
	action: 'SET_HEX_EDITOR_CONTROL';
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_EDITOR_CONTROL';
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	static quick(bool_value: boolean) {
		return new SET_HEX_EDITOR_CONTROL({ bool_value });
	}
}
export class SET_HEX_EDITOR_CONTROL_CLIPBOARD extends Action {
	action: 'SET_HEX_EDITOR_CONTROL_CLIPBOARD';
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_EDITOR_CONTROL_CLIPBOARD';
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
	static quick(bool_value: boolean) {
		return new SET_HEX_EDITOR_CONTROL_CLIPBOARD({ bool_value });
	}
}
export class LOAD_MAP extends Action {
	action: 'LOAD_MAP';
	map: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'LOAD_MAP';
		this.map = breakIfNotString(args.map);
	}
	static quick(map: string) {
		return new LOAD_MAP({ map });
	}
}
export class SHOW_DIALOG extends Action {
	action: 'SHOW_DIALOG';
	dialog: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SHOW_DIALOG';
		this.dialog = breakIfNotString(args.dialog);
	}
	static quick(dialog: string) {
		return new SHOW_DIALOG({ dialog });
	}
}
export class PLAY_ENTITY_ANIMATION extends Action {
	action: 'PLAY_ENTITY_ANIMATION';
	entity: string;
	animation: number;
	play_count: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'PLAY_ENTITY_ANIMATION';
		this.entity = breakIfNotString(args.entity);
		this.animation = breakIfNotNumber(args.animation);
		this.play_count = breakIfNotNumber(args.play_count);
	}
}
export class TELEPORT_ENTITY_TO_GEOMETRY extends Action {
	action: 'TELEPORT_ENTITY_TO_GEOMETRY';
	geometry: string;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'TELEPORT_ENTITY_TO_GEOMETRY';
		this.entity = breakIfNotString(args.entity);
		this.geometry = breakIfNotString(args.geometry);
	}
	static quick(entity: string, geometry: string) {
		return new TELEPORT_ENTITY_TO_GEOMETRY({ entity, geometry });
	}
}
export class WALK_ENTITY_TO_GEOMETRY extends Action {
	action: 'WALK_ENTITY_TO_GEOMETRY';
	geometry: string;
	entity: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'WALK_ENTITY_TO_GEOMETRY';
		this.geometry = breakIfNotString(args.geometry);
		this.entity = breakIfNotString(args.entity);
		this.duration = breakIfNotNumber(args.duration);
	}
	static quick(entity: string, geometry: string, duration: number) {
		return new WALK_ENTITY_TO_GEOMETRY({ entity, geometry, duration });
	}
}
export class WALK_ENTITY_ALONG_GEOMETRY extends Action {
	action: 'WALK_ENTITY_ALONG_GEOMETRY';
	geometry: string;
	entity: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'WALK_ENTITY_ALONG_GEOMETRY';
		this.geometry = breakIfNotString(args.geometry);
		this.entity = breakIfNotString(args.entity);
		this.duration = breakIfNotNumber(args.duration);
	}
	static quick(entity: string, geometry: string, duration: number) {
		return new WALK_ENTITY_ALONG_GEOMETRY({ entity, geometry, duration });
	}
}
export class LOOP_ENTITY_ALONG_GEOMETRY extends Action {
	action: 'LOOP_ENTITY_ALONG_GEOMETRY';
	geometry: string;
	entity: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'LOOP_ENTITY_ALONG_GEOMETRY';
		this.geometry = breakIfNotString(args.geometry);
		this.entity = breakIfNotString(args.entity);
		this.duration = breakIfNotNumber(args.duration);
	}
	static quick(entity: string, geometry: string, duration: number) {
		return new LOOP_ENTITY_ALONG_GEOMETRY({ entity, geometry, duration });
	}
}
export class SET_CAMERA_TO_FOLLOW_ENTITY extends Action {
	action: 'SET_CAMERA_TO_FOLLOW_ENTITY';
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_CAMERA_TO_FOLLOW_ENTITY';
		this.entity = breakIfNotString(args.entity);
	}
	static quick(entity: string) {
		return new SET_CAMERA_TO_FOLLOW_ENTITY({ entity });
	}
}
export class TELEPORT_CAMERA_TO_GEOMETRY extends Action {
	action: 'TELEPORT_CAMERA_TO_GEOMETRY';
	geometry: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'TELEPORT_CAMERA_TO_GEOMETRY';
		this.geometry = breakIfNotString(args.geometry);
	}
	static quick(geometry: string) {
		return new TELEPORT_CAMERA_TO_GEOMETRY({ geometry });
	}
}
export class PAN_CAMERA_TO_ENTITY extends Action {
	action: 'PAN_CAMERA_TO_ENTITY';
	entity: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'PAN_CAMERA_TO_ENTITY';
		this.entity = breakIfNotString(args.entity);
		this.duration = breakIfNotNumber(args.duration);
	}
	static quick(entity: string, duration: number) {
		return new PAN_CAMERA_TO_ENTITY({ duration, entity });
	}
}
export class PAN_CAMERA_TO_GEOMETRY extends Action {
	action: 'PAN_CAMERA_TO_GEOMETRY';
	geometry: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'PAN_CAMERA_TO_GEOMETRY';
		this.geometry = breakIfNotString(args.geometry);
		this.duration = breakIfNotNumber(args.duration);
	}
	static quick(geometry: string, duration: number) {
		return new PAN_CAMERA_TO_GEOMETRY({ geometry, duration });
	}
}
export class PAN_CAMERA_ALONG_GEOMETRY extends Action {
	action: 'PAN_CAMERA_ALONG_GEOMETRY';
	geometry: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'PAN_CAMERA_ALONG_GEOMETRY';
		this.geometry = breakIfNotString(args.geometry);
		this.duration = breakIfNotNumber(args.duration);
	}
	static quick(geometry: string, duration: number) {
		return new PAN_CAMERA_ALONG_GEOMETRY({ geometry, duration });
	}
}
export class LOOP_CAMERA_ALONG_GEOMETRY extends Action {
	action: 'LOOP_CAMERA_ALONG_GEOMETRY';
	geometry: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'LOOP_CAMERA_ALONG_GEOMETRY';
		this.geometry = breakIfNotString(args.geometry);
		this.duration = breakIfNotNumber(args.duration);
	}
	static quick(geometry: string, duration: number) {
		return new LOOP_CAMERA_ALONG_GEOMETRY({ geometry, duration });
	}
}
export class SET_SCREEN_SHAKE extends Action {
	action: 'SET_SCREEN_SHAKE';
	duration: number;
	frequency: number;
	amplitude: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SCREEN_SHAKE';
		this.duration = breakIfNotNumber(args.duration);
		this.frequency = breakIfNotNumber(args.frequency);
		this.amplitude = breakIfNotNumber(args.amplitude);
	}
}
export class SCREEN_FADE_OUT extends Action {
	action: 'SCREEN_FADE_OUT';
	duration: number;
	color: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SCREEN_FADE_OUT';
		this.duration = breakIfNotNumber(args.duration);
		this.color = breakIfNotString(args.color);
	}
}
export class SCREEN_FADE_IN extends Action {
	action: 'SCREEN_FADE_IN';
	duration: number;
	color: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SCREEN_FADE_IN';
		this.duration = breakIfNotNumber(args.duration);
		this.color = breakIfNotString(args.color);
	}
}
export class MUTATE_VARIABLE extends Action {
	action: 'MUTATE_VARIABLE';
	variable: string;
	operation: string;
	value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'MUTATE_VARIABLE';
		this.variable = breakIfNotString(args.variable);
		this.operation = breakIfNotString(args.operation);
		this.value = breakIfNotNumber(args.value);
	}
	static set(variable: string, value: number) {
		return new MUTATE_VARIABLE({ operation: 'SET', value, variable });
	}
	static change(debug: MathlangLocation, variable: string, value: number, op: string) {
		if (op === '+' && value === 0) {
			return CommentNode.quick(debug, 'This action was optimized out (+ 0)');
		}
		if (op === '*' && value === 1) {
			return CommentNode.quick(debug, 'This action was optimized out (* 1)');
		}
		if (op === '/' && value === 1) {
			return CommentNode.quick(debug, 'This action was optimized out (/ 1)');
		}
		if (op === '-' && value === 0) {
			return CommentNode.quick(debug, 'This action was optimized out (- 0)');
		}
		return new MUTATE_VARIABLE({ operation: opIntoStringMap[op] || op, value, variable });
	}
}
export class MUTATE_VARIABLES extends Action {
	action: 'MUTATE_VARIABLES';
	variable: string;
	operation: string;
	source: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'MUTATE_VARIABLES';
		this.variable = breakIfNotString(args.variable);
		this.operation = breakIfNotString(args.operation);
		this.source = breakIfNotString(args.source);
	}
	static set(f: FileState, node: TreeSitterNode, variable: string, source: string) {
		if (variable === source) {
			const debug = new MathlangLocation(f, node);
			return CommentNode.quick(
				debug,
				`This action was optimized out (setting '${variable}' to itself)`,
			);
		}
		return new MUTATE_VARIABLES({ operation: 'SET', source, variable });
	}
	static change(variable: string, source: string, op: string) {
		return new MUTATE_VARIABLES({
			variable,
			source,
			operation: opIntoStringMap[op] || op,
		});
	}
}
export class COPY_VARIABLE extends Action {
	action: 'COPY_VARIABLE';
	variable: string;
	entity: string;
	field: string;
	inbound: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'COPY_VARIABLE';
		this.variable = breakIfNotString(args.variable);
		this.entity = breakIfNotString(args.entity);
		this.field = breakIfNotString(args.field);
		this.inbound = breakIfNotBool(args.inbound);
	}
	static intoField(variable: string, entity: string, field: string) {
		return new COPY_VARIABLE({ entity, field, inbound: false, variable });
	}
	static intoVariable(entity: string, field: string, variable: string) {
		return new COPY_VARIABLE({ entity, field, inbound: true, variable });
	}
}
export class SLOT_SAVE extends Action {
	action: 'SLOT_SAVE';
	constructor() {
		super();
		this.action = 'SLOT_SAVE';
	}
}
export class SLOT_LOAD extends Action {
	action: 'SLOT_LOAD';
	slot: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SLOT_LOAD';
		this.slot = breakIfNotNumber(args.slot);
	}
}
export class SLOT_ERASE extends Action {
	action: 'SLOT_ERASE';
	slot: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SLOT_ERASE';
		this.slot = breakIfNotNumber(args.slot);
	}
}
export class SET_CONNECT_SERIAL_DIALOG extends Action {
	action: 'SET_CONNECT_SERIAL_DIALOG';
	serial_dialog: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_CONNECT_SERIAL_DIALOG';
		this.serial_dialog = breakIfNotString(args.serial_dialog);
	}
}
export class SHOW_SERIAL_DIALOG extends Action {
	action: 'SHOW_SERIAL_DIALOG';
	serial_dialog: string;
	disable_newline?: boolean; // might be absent on old stuff
	constructor(args: GenericActionish) {
		super();
		this.action = 'SHOW_SERIAL_DIALOG';
		this.serial_dialog = breakIfNotString(args.serial_dialog);
		if (args.disable_newline) {
			this.disable_newline = true;
		}
	}
	static quick(serial_dialog: string, disable_newline?: boolean) {
		return new SHOW_SERIAL_DIALOG({ serial_dialog, disable_newline: !!disable_newline });
	}
}
export class SET_MAP_LOOK_SCRIPT extends Action {
	action: 'SET_MAP_LOOK_SCRIPT';
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_MAP_LOOK_SCRIPT';
		this.script = breakIfNotString(args.script);
	}
	static quick(script: string) {
		return new SET_MAP_LOOK_SCRIPT({ script });
	}
}
export class SET_ENTITY_LOOK_SCRIPT extends Action {
	action: 'SET_ENTITY_LOOK_SCRIPT';
	script: string;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_LOOK_SCRIPT';
		this.script = breakIfNotString(args.script);
		this.entity = breakIfNotString(args.entity);
	}
	static quick(entity: string, script: string) {
		return new SET_ENTITY_LOOK_SCRIPT({ entity, script });
	}
}
export class SET_TELEPORT_ENABLED extends Action {
	action: 'SET_TELEPORT_ENABLED';
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_TELEPORT_ENABLED';
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class SET_BLE_FLAG extends Action {
	action: 'SET_BLE_FLAG';
	ble_flag: string;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_BLE_FLAG';
		this.ble_flag = breakIfNotString(args.ble_flag);
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class SET_SERIAL_DIALOG_CONTROL extends Action {
	action: 'SET_SERIAL_DIALOG_CONTROL';
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SERIAL_DIALOG_CONTROL';
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
	static quick(bool_value: boolean) {
		return new SET_SERIAL_DIALOG_CONTROL({ bool_value });
	}
}
export class REGISTER_SERIAL_DIALOG_COMMAND extends Action {
	action: 'REGISTER_SERIAL_DIALOG_COMMAND';
	command: string;
	script: string;
	is_fail?: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'REGISTER_SERIAL_DIALOG_COMMAND';
		this.command = breakIfNotString(args.command);
		this.script = breakIfNotString(args.script);
		if (args.is_fail) this.is_fail = true;
	}
}
export class REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT extends Action {
	action: 'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
	command: string;
	script: string;
	argument: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
		this.command = breakIfNotString(args.command);
		this.script = breakIfNotString(args.script);
		this.argument = breakIfNotString(args.argument);
	}
}
export class UNREGISTER_SERIAL_DIALOG_COMMAND extends Action {
	action: 'UNREGISTER_SERIAL_DIALOG_COMMAND';
	command: string;
	is_fail?: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'UNREGISTER_SERIAL_DIALOG_COMMAND';
		this.command = breakIfNotString(args.command);
		if (args.is_fail !== undefined) {
			this.is_fail = breakIfNotBool(args.is_fail);
		}
	}
}
export class UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT extends Action {
	action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
	command: string;
	argument: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
		this.command = breakIfNotString(args.command);
		this.argument = breakIfNotString(args.argument);
	}
}
export class SET_ENTITY_MOVEMENT_RELATIVE extends Action {
	action: 'SET_ENTITY_MOVEMENT_RELATIVE';
	relative_direction: number;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_MOVEMENT_RELATIVE';
		this.relative_direction = breakIfNotNumber(args.relative_direction);
		this.entity = breakIfNotString(args.entity);
	}
	static quick(entity: string, relative_direction: number) {
		return new SET_ENTITY_MOVEMENT_RELATIVE({ entity, relative_direction });
	}
}
export class CLOSE_DIALOG extends Action {
	action: 'CLOSE_DIALOG';
	constructor() {
		super();
		this.action = 'CLOSE_DIALOG';
	}
}
export class CLOSE_SERIAL_DIALOG extends Action {
	action: 'CLOSE_SERIAL_DIALOG';
	constructor() {
		super();
		this.action = 'CLOSE_SERIAL_DIALOG';
	}
}
export class SET_LIGHTS_CONTROL extends Action {
	action: 'SET_LIGHTS_CONTROL';
	enabled: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_LIGHTS_CONTROL';
		this.enabled = breakIfNotBool(args.enabled);
	}
	invert() {
		this.enabled = !this.enabled;
	}
	static quick(enabled: boolean) {
		return new SET_LIGHTS_CONTROL({ enabled });
	}
}
export class SET_LIGHTS_STATE extends Action {
	action: 'SET_LIGHTS_STATE';
	lights: string | string[];
	enabled: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_LIGHTS_STATE';
		this.enabled = breakIfNotBool(args.enabled);
		this.lights = breakIfNotStringOrStringArray(args.lights);
	}
	invert() {
		this.enabled = !this.enabled;
	}
	static quick(lights: string, enabled: boolean) {
		return new SET_LIGHTS_STATE({ lights, enabled });
	}
}
export class GOTO_ACTION_INDEX extends Action {
	action: 'GOTO_ACTION_INDEX';
	action_index: number | string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'GOTO_ACTION_INDEX';
		this.action_index = breakIfNotStringOrNumber(args.action_index);
	}
	static quick(action_index: string | number) {
		return new GOTO_ACTION_INDEX({ action_index });
	}
}
export class SET_SCRIPT_PAUSE extends Action {
	action: 'SET_SCRIPT_PAUSE';
	entity: string;
	script_slot: string;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SCRIPT_PAUSE';
		this.entity = breakIfNotString(args.entity);
		this.script_slot = breakIfNotString(args.script_slot);
		this.bool_value = breakIfNotBool(args.bool_value);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class REGISTER_SERIAL_DIALOG_COMMAND_ALIAS extends Action {
	action: 'REGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
	command: string;
	alias: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'REGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
		this.command = breakIfNotString(args.command);
		this.alias = breakIfNotString(args.alias);
	}
}
export class UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS extends Action {
	action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
	alias: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
		this.alias = breakIfNotString(args.alias);
	}
}
export class SET_SERIAL_DIALOG_COMMAND_VISIBILITY extends Action {
	action: 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY';
	command: string;
	is_visible: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY';
		this.command = breakIfNotString(args.command);
		this.is_visible = breakIfNotBool(args.is_visible);
	}
}

// CHECK_ACTIONS

export class CHECK_ENTITY_NAME extends StringCheckable {
	action: 'CHECK_ENTITY_NAME';
	entity: string;
	string: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_NAME';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.string = breakIfNotString(args.string);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.string = value;
	}
	static quick(entity: string, string: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_NAME({ entity, string, expected_bool });
	}
}
export class CHECK_ENTITY_X extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_X';
	entity: string;
	expected_u2: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_X';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_u2 = breakIfNotNumber(args.expected_u2);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: number) {
		this.expected_u2 = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	static quick(entity: string, expected_u2: number, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_X({ entity, expected_u2, expected_bool });
	}
}
export class CHECK_ENTITY_Y extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_Y';
	entity: string;
	expected_u2: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_Y';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_u2 = breakIfNotNumber(args.expected_u2);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: number) {
		this.expected_u2 = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	static quick(entity: string, expected_u2: number, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_Y({ entity, expected_u2, expected_bool });
	}
}
export class CHECK_ENTITY_INTERACT_SCRIPT extends StringCheckable {
	action: 'CHECK_ENTITY_INTERACT_SCRIPT';
	entity: string;
	expected_script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_INTERACT_SCRIPT';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_script = breakIfNotString(args.expected_script);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.expected_script = value;
	}
	static quick(entity: string, expected_script: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_INTERACT_SCRIPT({ entity, expected_script, expected_bool });
	}
}
export class CHECK_ENTITY_TICK_SCRIPT extends StringCheckable {
	action: 'CHECK_ENTITY_TICK_SCRIPT';
	entity: string;
	expected_script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_TICK_SCRIPT';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_script = breakIfNotString(args.expected_script);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.expected_script = value;
	}
	static quick(entity: string, expected_script: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_TICK_SCRIPT({ entity, expected_script, expected_bool });
	}
}
export class CHECK_ENTITY_LOOK_SCRIPT extends StringCheckable {
	action: 'CHECK_ENTITY_LOOK_SCRIPT';
	entity: string;
	expected_script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_LOOK_SCRIPT';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_script = breakIfNotString(args.expected_script);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.expected_script = value;
	}
	static quick(entity: string, expected_script: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_LOOK_SCRIPT({ entity, expected_script, expected_bool });
	}
}
export class CHECK_ENTITY_TYPE extends StringCheckable {
	action: 'CHECK_ENTITY_TYPE';
	entity: string;
	entity_type: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_TYPE';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.entity_type = breakIfNotString(args.entity_type);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.entity_type = value;
	}
	static quick(entity: string, entity_type: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_TYPE({ entity, entity_type, expected_bool });
	}
}
export class CHECK_ENTITY_PRIMARY_ID extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_PRIMARY_ID';
	entity: string;
	expected_u2: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_PRIMARY_ID';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_u2 = breakIfNotNumber(args.expected_u2);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: number) {
		this.expected_u2 = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	static quick(entity: string, expected_u2: number, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_PRIMARY_ID({ entity, expected_u2, expected_bool });
	}
}
export class CHECK_ENTITY_SECONDARY_ID extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_SECONDARY_ID';
	entity: string;
	expected_u2: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_SECONDARY_ID';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_u2 = breakIfNotNumber(args.expected_u2);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: number) {
		this.expected_u2 = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	static quick(entity: string, expected_u2: number, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_SECONDARY_ID({ entity, expected_u2, expected_bool });
	}
}
export class CHECK_ENTITY_PRIMARY_ID_TYPE extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_PRIMARY_ID_TYPE';
	entity: string;
	expected_byte: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_PRIMARY_ID_TYPE';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_byte = breakIfNotNumber(args.expected_byte);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: number) {
		this.expected_byte = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	static quick(entity: string, expected_byte: number, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_PRIMARY_ID_TYPE({ entity, expected_byte, expected_bool });
	}
}
export class CHECK_ENTITY_CURRENT_ANIMATION extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_CURRENT_ANIMATION';
	entity: string;
	expected_byte: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_CURRENT_ANIMATION';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_byte = breakIfNotNumber(args.expected_byte);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: number) {
		this.expected_byte = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	static quick(entity: string, expected_byte: number, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_CURRENT_ANIMATION({ entity, expected_byte, expected_bool });
	}
}
export class CHECK_ENTITY_CURRENT_FRAME extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_CURRENT_FRAME';
	entity: string;
	expected_byte: number;
	expected_bool: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_CURRENT_FRAME';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_byte = breakIfNotNumber(args.expected_byte);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: number) {
		this.expected_byte = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
	static quick(entity: string, expected_byte: number, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_CURRENT_FRAME({ entity, expected_byte, expected_bool });
	}
}
export class CHECK_ENTITY_DIRECTION extends StringCheckable {
	action: 'CHECK_ENTITY_DIRECTION';
	entity: string;
	direction: string; // north, south, east, west
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_DIRECTION';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.direction = breakIfNotString(args.direction);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.direction = value;
	}
	static quick(entity: string, direction: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_DIRECTION({ entity, direction, expected_bool });
	}
}
export class CHECK_ENTITY_GLITCHED extends BoolGetable {
	action: 'CHECK_ENTITY_GLITCHED';
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_ENTITY_GLITCHED';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(entity: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_GLITCHED({ entity, expected_bool });
	}
}
export class CHECK_ENTITY_PATH extends StringCheckable {
	action: 'CHECK_ENTITY_PATH';
	geometry: string;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_PATH';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.entity = breakIfNotString(args.entity);
		this.geometry = breakIfNotString(args.geometry);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.geometry = value;
	}
	static quick(entity: string, geometry: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_ENTITY_PATH({ entity, geometry, expected_bool });
	}
}
export class CHECK_SAVE_FLAG extends BoolGetable {
	action: 'CHECK_SAVE_FLAG';
	save_flag: string;
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_SAVE_FLAG';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.save_flag = breakIfNotString(args.save_flag);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(save_flag: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_SAVE_FLAG({ save_flag, expected_bool });
	}
}
export class CHECK_IF_ENTITY_IS_IN_GEOMETRY extends BoolGetable {
	action: 'CHECK_IF_ENTITY_IS_IN_GEOMETRY';
	geometry: string;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_IF_ENTITY_IS_IN_GEOMETRY';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.geometry = breakIfNotString(args.geometry);
		this.entity = breakIfNotString(args.entity);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(entity: string, geometry: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_IF_ENTITY_IS_IN_GEOMETRY({ entity, geometry, expected_bool });
	}
}
export class CHECK_FOR_BUTTON_PRESS extends BoolGetable {
	action: 'CHECK_FOR_BUTTON_PRESS';
	button_id: string;
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_FOR_BUTTON_PRESS';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.button_id = breakIfNotString(args.button_id);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(button_id: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_FOR_BUTTON_PRESS({ button_id, expected_bool });
	}
}
export class CHECK_FOR_BUTTON_STATE extends BoolGetable {
	action: 'CHECK_FOR_BUTTON_STATE';
	button_id: string;
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_FOR_BUTTON_STATE';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.button_id = breakIfNotString(args.button_id);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(button_id: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_FOR_BUTTON_STATE({ button_id, expected_bool });
	}
}
export class CHECK_WARP_STATE extends StringCheckable {
	action: 'CHECK_WARP_STATE';
	string: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_WARP_STATE';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.string = breakIfNotString(args.string);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.string = value;
	}
	static quick(string: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_WARP_STATE({ string, expected_bool });
	}
}
export class CHECK_VARIABLE extends NumberComparison {
	action: 'CHECK_VARIABLE';
	variable: string;
	comparison: string;
	value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_VARIABLE';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.variable = breakIfNotString(args.variable);
		this.comparison = breakIfNotString(args.comparison);
		this.value = breakIfNotNumber(args.value);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(variable: string, value: number, comparison: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_VARIABLE({
			variable,
			value,
			comparison,
			expected_bool,
		});
	}
}
export class CHECK_VARIABLES extends NumberComparison {
	action: 'CHECK_VARIABLES';
	variable: string;
	comparison: string;
	source: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_VARIABLES';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.variable = breakIfNotString(args.variable);
		this.comparison = breakIfNotString(args.comparison);
		this.source = breakIfNotString(args.source);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(variable: string, source: string, comparison: string, provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_VARIABLES({
			variable,
			source,
			comparison,
			expected_bool,
		});
	}
}
export class CHECK_MAP extends StringCheckable {
	// TODO: is this even in the engine? O.o
	action: 'CHECK_MAP';
	map: string;
	expected_bool: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_MAP';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.map = breakIfNotString(args.map);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.map = value;
	}
}
export class CHECK_BLE_FLAG extends StringCheckable {
	action: 'CHECK_BLE_FLAG';
	ble_flag: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_BLE_FLAG';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.ble_flag = breakIfNotString(args.ble_flag);
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	updateProp(value: string) {
		this.ble_flag = value;
	}
}
export class CHECK_DIALOG_OPEN extends BoolGetable {
	action: 'CHECK_DIALOG_OPEN';
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_DIALOG_OPEN';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_DIALOG_OPEN({ expected_bool });
	}
}
export class CHECK_SERIAL_DIALOG_OPEN extends BoolGetable {
	action: 'CHECK_SERIAL_DIALOG_OPEN';
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_SERIAL_DIALOG_OPEN';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_SERIAL_DIALOG_OPEN({ expected_bool });
	}
}
export class CHECK_DEBUG_MODE extends BoolGetable {
	action: 'CHECK_DEBUG_MODE';
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_DEBUG_MODE';
		if (args.success_script) {
			this.success_script = breakIfNotString(args.success_script);
		} else if (args.label) {
			this.label = breakIfNotString(args.label);
		} else if (args.jump_index) {
			this.jump_index = breakIfNotNumber(args.jump_index);
		}
		this.expected_bool = breakIfNotBool(args.expected_bool);
	}
	static quick(provided_bool?: boolean) {
		const expected_bool = provided_bool === undefined ? true : provided_bool;
		return new CHECK_DEBUG_MODE({ expected_bool });
	}
}
export type CheckAction =
	// StringCheckable
	| CHECK_ENTITY_NAME
	| CHECK_ENTITY_INTERACT_SCRIPT
	| CHECK_ENTITY_TICK_SCRIPT
	| CHECK_ENTITY_LOOK_SCRIPT
	| CHECK_ENTITY_TYPE
	| CHECK_ENTITY_DIRECTION
	| CHECK_ENTITY_PATH
	| CHECK_WARP_STATE
	| CHECK_BLE_FLAG
	| CHECK_MAP
	// NumberCheckableEquality
	| CHECK_ENTITY_X
	| CHECK_ENTITY_Y
	| CHECK_ENTITY_PRIMARY_ID
	| CHECK_ENTITY_SECONDARY_ID
	| CHECK_ENTITY_PRIMARY_ID_TYPE
	| CHECK_ENTITY_CURRENT_ANIMATION
	| CHECK_ENTITY_CURRENT_FRAME
	// BoolGetable
	| CHECK_ENTITY_GLITCHED
	| CHECK_SAVE_FLAG
	| CHECK_IF_ENTITY_IS_IN_GEOMETRY
	| CHECK_FOR_BUTTON_PRESS
	| CHECK_FOR_BUTTON_STATE
	| CHECK_DIALOG_OPEN
	| CHECK_SERIAL_DIALOG_OPEN
	| CHECK_DEBUG_MODE
	// NumberComparison
	| CHECK_VARIABLE
	| CHECK_VARIABLES;
export const isCheckAction = (v: unknown): v is CheckAction => {
	// if (v instanceof StringCheckable) return true;
	// if (v instanceof NumberCheckableEquality) return true;
	// if (v instanceof BoolGetable) return true;
	// if (v instanceof NumberComparison) return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_NAME') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_X') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_Y') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_INTERACT_SCRIPT') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_TICK_SCRIPT') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_LOOK_SCRIPT') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_TYPE') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_PRIMARY_ID') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_SECONDARY_ID') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_PRIMARY_ID_TYPE') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_CURRENT_ANIMATION') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_CURRENT_FRAME') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_DIRECTION') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_GLITCHED') return true;
	if ((v as CheckAction).action === 'CHECK_ENTITY_PATH') return true;
	if ((v as CheckAction).action === 'CHECK_SAVE_FLAG') return true;
	if ((v as CheckAction).action === 'CHECK_IF_ENTITY_IS_IN_GEOMETRY') return true;
	if ((v as CheckAction).action === 'CHECK_FOR_BUTTON_PRESS') return true;
	if ((v as CheckAction).action === 'CHECK_FOR_BUTTON_STATE') return true;
	if ((v as CheckAction).action === 'CHECK_WARP_STATE') return true;
	if ((v as CheckAction).action === 'CHECK_VARIABLE') return true;
	if ((v as CheckAction).action === 'CHECK_VARIABLES') return true;
	if ((v as CheckAction).action === 'CHECK_MAP') return true;
	if ((v as CheckAction).action === 'CHECK_BLE_FLAG') return true;
	if ((v as CheckAction).action === 'CHECK_DIALOG_OPEN') return true;
	if ((v as CheckAction).action === 'CHECK_SERIAL_DIALOG_OPEN') return true;
	if ((v as CheckAction).action === 'CHECK_DEBUG_MODE') return true;
	return false;
};

// // Super union type
// export type Action =
// 	| CheckAction
// 	| ActionSetEntityString
// 	| ActionSetEntityInt
// 	| ActionSetDirection
// 	| ActionSetBool
// 	| ActionSetPosition
// 	| ActionMoveOverTime
// 	| ActionSetScript
// 	| NULL_ACTION
// 	| LABEL // for old-style parser
// 	| RUN_SCRIPT
// 	| COPY_SCRIPT
// 	| BLOCKING_DELAY
// 	| NON_BLOCKING_DELAY
// 	| SET_HEX_CURSOR_LOCATION
// 	| SET_WARP_STATE
// 	| LOAD_MAP
// 	| SHOW_DIALOG
// 	| PLAY_ENTITY_ANIMATION
// 	| SET_SCREEN_SHAKE
// 	| SCREEN_FADE_OUT
// 	| SCREEN_FADE_IN
// 	| MUTATE_VARIABLE
// 	| MUTATE_VARIABLES
// 	| COPY_VARIABLE
// 	| SLOT_SAVE
// 	| SLOT_LOAD
// 	| SLOT_ERASE
// 	| SET_CONNECT_SERIAL_DIALOG
// 	| SHOW_SERIAL_DIALOG
// 	| SET_TELEPORT_ENABLED
// 	| SET_BLE_FLAG
// 	| REGISTER_SERIAL_DIALOG_COMMAND
// 	| REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
// 	| UNREGISTER_SERIAL_DIALOG_COMMAND
// 	| UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
// 	| CLOSE_DIALOG
// 	| CLOSE_SERIAL_DIALOG
// 	| GOTO_ACTION_INDEX
// 	| SET_SCRIPT_PAUSE
// 	| REGISTER_SERIAL_DIALOG_COMMAND_ALIAS
// 	| UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS
// 	| SET_SERIAL_DIALOG_COMMAND_VISIBILITY;

export type ActionSetEntityInt =
	| SET_ENTITY_X
	| SET_ENTITY_Y
	| SET_ENTITY_PRIMARY_ID
	| SET_ENTITY_SECONDARY_ID
	| SET_ENTITY_PRIMARY_ID_TYPE
	| SET_ENTITY_CURRENT_ANIMATION
	| SET_ENTITY_CURRENT_FRAME
	| SET_ENTITY_MOVEMENT_RELATIVE
	| SET_ENTITY_DIRECTION_RELATIVE;

export type ActionSetBool =
	| SET_ENTITY_GLITCHED
	| SET_LIGHTS_STATE
	| SET_PLAYER_CONTROL
	| SET_LIGHTS_CONTROL
	| SET_HEX_EDITOR_STATE
	| SET_HEX_EDITOR_DIALOG_MODE
	| SET_HEX_EDITOR_CONTROL
	| SET_HEX_EDITOR_CONTROL_CLIPBOARD
	| SET_SERIAL_DIALOG_CONTROL
	| SET_SAVE_FLAG;

export type ActionSetPosition =
	| TELEPORT_ENTITY_TO_GEOMETRY
	| TELEPORT_CAMERA_TO_GEOMETRY
	| SET_CAMERA_TO_FOLLOW_ENTITY;

export type ActionSetDirection =
	| SET_ENTITY_DIRECTION
	| SET_ENTITY_DIRECTION_TARGET_GEOMETRY
	| SET_ENTITY_DIRECTION_TARGET_ENTITY;

export type ActionSetScript =
	| SET_MAP_TICK_SCRIPT
	| SET_MAP_LOOK_SCRIPT
	| SET_ENTITY_TICK_SCRIPT
	| SET_ENTITY_INTERACT_SCRIPT
	| SET_ENTITY_LOOK_SCRIPT;

export type ActionMoveOverTime =
	| LOOP_CAMERA_ALONG_GEOMETRY
	| PAN_CAMERA_ALONG_GEOMETRY
	| PAN_CAMERA_TO_GEOMETRY
	| PAN_CAMERA_TO_ENTITY
	| LOOP_ENTITY_ALONG_GEOMETRY
	| WALK_ENTITY_ALONG_GEOMETRY
	| WALK_ENTITY_TO_GEOMETRY;

export type ActionSetEntityString = SET_ENTITY_NAME | SET_ENTITY_TYPE | SET_ENTITY_PATH;

// ----------------------------------- non TypeScript stuff ----------------------------------- \\

const JUMP_SPECIAL_FIELDS: string[] = ['success_script', 'label', 'jump_index'];
// copy pastad from encoder

const actionFields: Record<string, string[]> = {
	NULL_ACTION: [],
	CHECK_ENTITY_NAME: ['JUMP_SPECIAL_FIELDS', 'string', 'entity', 'expected_bool'],
	CHECK_ENTITY_X: ['JUMP_SPECIAL_FIELDS', 'expected_u2', 'entity', 'expected_bool'],
	CHECK_ENTITY_Y: ['JUMP_SPECIAL_FIELDS', 'expected_u2', 'entity', 'expected_bool'],
	CHECK_ENTITY_INTERACT_SCRIPT: [
		'JUMP_SPECIAL_FIELDS',
		'expected_script',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_TICK_SCRIPT: ['JUMP_SPECIAL_FIELDS', 'expected_script', 'entity', 'expected_bool'],
	CHECK_ENTITY_LOOK_SCRIPT: ['JUMP_SPECIAL_FIELDS', 'expected_script', 'entity', 'expected_bool'],
	CHECK_ENTITY_TYPE: ['JUMP_SPECIAL_FIELDS', 'entity_type', 'entity', 'expected_bool'],
	CHECK_ENTITY_PRIMARY_ID: ['JUMP_SPECIAL_FIELDS', 'expected_u2', 'entity', 'expected_bool'],
	CHECK_ENTITY_SECONDARY_ID: ['JUMP_SPECIAL_FIELDS', 'expected_u2', 'entity', 'expected_bool'],
	CHECK_ENTITY_PRIMARY_ID_TYPE: [
		'JUMP_SPECIAL_FIELDS',
		'entity',
		'expected_byte',
		'expected_bool',
	],
	CHECK_ENTITY_CURRENT_ANIMATION: [
		'JUMP_SPECIAL_FIELDS',
		'entity',
		'expected_byte',
		'expected_bool',
	],
	CHECK_ENTITY_CURRENT_FRAME: ['JUMP_SPECIAL_FIELDS', 'entity', 'expected_byte', 'expected_bool'],
	CHECK_ENTITY_DIRECTION: ['JUMP_SPECIAL_FIELDS', 'entity', 'direction', 'expected_bool'],
	CHECK_ENTITY_GLITCHED: ['JUMP_SPECIAL_FIELDS', 'entity', 'expected_bool'],
	CHECK_ENTITY_PATH: ['JUMP_SPECIAL_FIELDS', 'geometry', 'entity', 'expected_bool'],
	CHECK_SAVE_FLAG: ['JUMP_SPECIAL_FIELDS', 'save_flag', 'expected_bool'],
	CHECK_IF_ENTITY_IS_IN_GEOMETRY: ['JUMP_SPECIAL_FIELDS', 'geometry', 'entity', 'expected_bool'],
	CHECK_FOR_BUTTON_PRESS: ['JUMP_SPECIAL_FIELDS', 'button_id', 'expected_bool'],
	CHECK_FOR_BUTTON_STATE: ['JUMP_SPECIAL_FIELDS', 'button_id', 'expected_bool'],
	CHECK_WARP_STATE: ['JUMP_SPECIAL_FIELDS', 'string', 'expected_bool'],
	RUN_SCRIPT: ['script'],
	COPY_SCRIPT: ['script', 'search_and_replace'],
	BLOCKING_DELAY: ['duration'],
	NON_BLOCKING_DELAY: ['duration'],
	SET_ENTITY_NAME: ['string', 'entity'],
	SET_ENTITY_X: ['u2_value', 'entity'],
	SET_ENTITY_Y: ['u2_value', 'entity'],
	SET_ENTITY_INTERACT_SCRIPT: ['script', 'entity'],
	SET_ENTITY_TICK_SCRIPT: ['script', 'entity'],
	SET_ENTITY_TYPE: ['entity_type', 'entity'],
	SET_ENTITY_PRIMARY_ID: ['u2_value', 'entity'],
	SET_ENTITY_SECONDARY_ID: ['u2_value', 'entity'],
	SET_ENTITY_PRIMARY_ID_TYPE: ['byte_value', 'entity'],
	SET_ENTITY_CURRENT_ANIMATION: ['byte_value', 'entity'],
	SET_ENTITY_CURRENT_FRAME: ['byte_value', 'entity'],
	SET_ENTITY_DIRECTION: ['direction', 'entity'],
	SET_ENTITY_DIRECTION_RELATIVE: ['relative_direction', 'entity'],
	SET_ENTITY_DIRECTION_TARGET_ENTITY: ['target_entity', 'entity'],
	SET_ENTITY_DIRECTION_TARGET_GEOMETRY: ['target_geometry', 'entity'],
	SET_ENTITY_GLITCHED: ['entity', 'bool_value'],
	SET_ENTITY_PATH: ['geometry', 'entity'],
	SET_SAVE_FLAG: ['save_flag', 'bool_value'],
	SET_PLAYER_CONTROL: ['bool_value'],
	SET_MAP_TICK_SCRIPT: ['script'],
	SET_HEX_CURSOR_LOCATION: ['address'],
	SET_WARP_STATE: ['string'],
	SET_HEX_EDITOR_STATE: ['bool_value'],
	SET_HEX_EDITOR_DIALOG_MODE: ['bool_value'],
	SET_HEX_EDITOR_CONTROL: ['bool_value'],
	SET_HEX_EDITOR_CONTROL_CLIPBOARD: ['bool_value'],
	LOAD_MAP: ['map'],
	SHOW_DIALOG: ['dialog'],
	PLAY_ENTITY_ANIMATION: ['entity', 'animation', 'play_count'],
	TELEPORT_ENTITY_TO_GEOMETRY: ['geometry', 'entity'],
	WALK_ENTITY_TO_GEOMETRY: ['duration', 'geometry', 'entity'],
	WALK_ENTITY_ALONG_GEOMETRY: ['duration', 'geometry', 'entity'],
	LOOP_ENTITY_ALONG_GEOMETRY: ['duration', 'geometry', 'entity'],
	SET_CAMERA_TO_FOLLOW_ENTITY: ['entity'],
	TELEPORT_CAMERA_TO_GEOMETRY: ['geometry'],
	PAN_CAMERA_TO_ENTITY: ['duration', 'entity'],
	PAN_CAMERA_TO_GEOMETRY: ['duration', 'geometry'],
	PAN_CAMERA_ALONG_GEOMETRY: ['duration', 'geometry', 'entity'],
	LOOP_CAMERA_ALONG_GEOMETRY: ['duration', 'geometry', 'entity'],
	SET_SCREEN_SHAKE: ['duration', 'frequency', 'amplitude'],
	SCREEN_FADE_OUT: ['duration', 'color'],
	SCREEN_FADE_IN: ['duration', 'color'],
	MUTATE_VARIABLE: ['value', 'variable', 'operation'],
	MUTATE_VARIABLES: ['variable', 'source', 'operation'],
	COPY_VARIABLE: ['variable', 'entity', 'field', 'inbound'],
	CHECK_VARIABLE: ['JUMP_SPECIAL_FIELDS', 'value', 'variable', 'comparison', 'expected_bool'],
	CHECK_VARIABLES: ['JUMP_SPECIAL_FIELDS', 'variable', 'source', 'comparison', 'expected_bool'],
	SLOT_SAVE: [],
	SLOT_LOAD: ['slot'],
	SLOT_ERASE: ['slot'],
	SET_CONNECT_SERIAL_DIALOG: ['serial_dialog'],
	SHOW_SERIAL_DIALOG: ['serial_dialog', 'disable_newline'],
	SET_MAP_LOOK_SCRIPT: ['script'],
	SET_ENTITY_LOOK_SCRIPT: ['script', 'entity'],
	SET_TELEPORT_ENABLED: ['bool_value'],
	CHECK_MAP: ['JUMP_SPECIAL_FIELDS', 'map', 'expected_bool'],
	SET_BLE_FLAG: ['ble_flag', 'bool_value'],
	CHECK_BLE_FLAG: ['JUMP_SPECIAL_FIELDS', 'ble_flag', 'expected_bool'],
	SET_SERIAL_DIALOG_CONTROL: ['bool_value'],
	REGISTER_SERIAL_DIALOG_COMMAND: ['command', 'script', 'is_fail'],
	REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: ['command', 'argument', 'script'],
	UNREGISTER_SERIAL_DIALOG_COMMAND: ['command', 'is_fail'],
	UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: ['command', 'argument', 'script'],
	SET_ENTITY_MOVEMENT_RELATIVE: ['relative_direction', 'entity'],
	CHECK_DIALOG_OPEN: ['JUMP_SPECIAL_FIELDS', 'expected_bool'],
	CHECK_SERIAL_DIALOG_OPEN: ['JUMP_SPECIAL_FIELDS', 'expected_bool'],
	CHECK_DEBUG_MODE: ['JUMP_SPECIAL_FIELDS', 'expected_bool'],
	CLOSE_DIALOG: [],
	CLOSE_SERIAL_DIALOG: [],
	SET_LIGHTS_CONTROL: ['enabled'],
	SET_LIGHTS_STATE: ['lights', 'enabled'],
	GOTO_ACTION_INDEX: ['action_index'],
	SET_SCRIPT_PAUSE: ['entity', 'script_slot', 'bool_value'],
	REGISTER_SERIAL_DIALOG_COMMAND_ALIAS: ['command', 'alias'],
	UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS: ['alias'],
	SET_SERIAL_DIALOG_COMMAND_VISIBILITY: ['command', 'is_visible'],
};

export const isFieldForAction = (field: string, action: string): boolean => {
	const fields = actionFields[action];
	if (fields.includes(field)) return true;
	if (fields.includes('JUMP_SPECIAL_FIELDS')) {
		return JUMP_SPECIAL_FIELDS.includes(field);
	}
	return false;
};
export const getBoolFieldForAction = (action: string): string => {
	const fields = actionFields[action];
	if (fields.includes('bool_value')) return 'bool_value';
	if (fields.includes('expected_bool')) return 'expected_bool';
	if (fields.includes('enabled')) return 'enabled';
	const filtered = fields.filter((s: string) => s.includes('bool'));
	if (filtered.length === 1) return filtered[0];
	if (filtered.length === 0) {
		throw new Error(`bool field not found for action ${action}`);
	}
	throw new Error('multiple possible bool params: ' + filtered.join(', '));
};

const breakIfNotStringOrStringArray = (v: unknown): string | string[] => {
	if (typeof v === 'string') return v;
	if (Array.isArray(v) && v.every((v) => typeof v === 'string')) return v;
	throw new Error('not a string or a strng array');
};
export const breakIfNotString = (v: unknown): string => {
	if (typeof v === 'string') return v;
	throw new Error('not a string');
};
export const breakIfNotStringOrNumber = (v: unknown): string | number => {
	if (typeof v === 'string') return v;
	if (typeof v === 'number') return v;
	throw new Error('not a string or number');
};
export const breakIfNotNumber = (v: unknown): number => {
	if (typeof v === 'number') return v;
	throw new Error('not a number');
};
export const breakIfNotBool = (v: unknown): boolean => {
	if (typeof v === 'boolean') return v;
	throw new Error('not a boolean');
};

const actionConstructorLookup = {
	NULL_ACTION: () => new NULL_ACTION(),
	COPY_SCRIPT: (args: GenericActionish) => new COPY_SCRIPT(args),
	LABEL: (args: GenericActionish) => new LABEL(args),
	RUN_SCRIPT: (args: GenericActionish) => new RUN_SCRIPT(args),
	BLOCKING_DELAY: (args: GenericActionish) => new BLOCKING_DELAY(args),
	NON_BLOCKING_DELAY: (args: GenericActionish) => new NON_BLOCKING_DELAY(args),
	UNREGISTER_SERIAL_DIALOG_COMMAND: (args: GenericActionish) => {
		return new UNREGISTER_SERIAL_DIALOG_COMMAND(args);
	},
	UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: (args: GenericActionish) => {
		return new UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT(args);
	},
	SET_ENTITY_NAME: (args: GenericActionish) => new SET_ENTITY_NAME(args),
	SET_ENTITY_X: (args: GenericActionish) => new SET_ENTITY_X(args),
	SET_ENTITY_Y: (args: GenericActionish) => new SET_ENTITY_Y(args),
	SET_ENTITY_INTERACT_SCRIPT: (args: GenericActionish) => new SET_ENTITY_INTERACT_SCRIPT(args),
	SET_ENTITY_TICK_SCRIPT: (args: GenericActionish) => new SET_ENTITY_TICK_SCRIPT(args),
	SET_ENTITY_TYPE: (args: GenericActionish) => new SET_ENTITY_TYPE(args),
	SET_ENTITY_PRIMARY_ID: (args: GenericActionish) => new SET_ENTITY_PRIMARY_ID(args),
	SET_ENTITY_SECONDARY_ID: (args: GenericActionish) => new SET_ENTITY_SECONDARY_ID(args),
	SET_ENTITY_PRIMARY_ID_TYPE: (args: GenericActionish) => new SET_ENTITY_PRIMARY_ID_TYPE(args),
	SET_ENTITY_CURRENT_ANIMATION: (args: GenericActionish) => {
		return new SET_ENTITY_CURRENT_ANIMATION(args);
	},
	SET_ENTITY_CURRENT_FRAME: (args: GenericActionish) => new SET_ENTITY_CURRENT_FRAME(args),
	SET_ENTITY_DIRECTION: (args: GenericActionish) => new SET_ENTITY_DIRECTION(args),
	SET_ENTITY_DIRECTION_RELATIVE: (args: GenericActionish) => {
		return new SET_ENTITY_DIRECTION_RELATIVE(args);
	},
	SET_ENTITY_DIRECTION_TARGET_ENTITY: (args: GenericActionish) => {
		return new SET_ENTITY_DIRECTION_TARGET_ENTITY(args);
	},
	SET_ENTITY_DIRECTION_TARGET_GEOMETRY: (args: GenericActionish) => {
		return new SET_ENTITY_DIRECTION_TARGET_GEOMETRY(args);
	},
	SET_ENTITY_GLITCHED: (args: GenericActionish) => new SET_ENTITY_GLITCHED(args),
	SET_ENTITY_PATH: (args: GenericActionish) => new SET_ENTITY_PATH(args),
	SET_SAVE_FLAG: (args: GenericActionish) => new SET_SAVE_FLAG(args),
	SET_PLAYER_CONTROL: (args: GenericActionish) => new SET_PLAYER_CONTROL(args),
	SET_MAP_TICK_SCRIPT: (args: GenericActionish) => new SET_MAP_TICK_SCRIPT(args),
	SET_HEX_CURSOR_LOCATION: (args: GenericActionish) => new SET_HEX_CURSOR_LOCATION(args),
	SET_WARP_STATE: (args: GenericActionish) => new SET_WARP_STATE(args),
	SET_HEX_EDITOR_STATE: (args: GenericActionish) => new SET_HEX_EDITOR_STATE(args),
	SET_HEX_EDITOR_DIALOG_MODE: (args: GenericActionish) => new SET_HEX_EDITOR_DIALOG_MODE(args),
	SET_HEX_EDITOR_CONTROL: (args: GenericActionish) => new SET_HEX_EDITOR_CONTROL(args),
	SET_HEX_EDITOR_CONTROL_CLIPBOARD: (args: GenericActionish) => {
		return new SET_HEX_EDITOR_CONTROL_CLIPBOARD(args);
	},
	LOAD_MAP: (args: GenericActionish) => new LOAD_MAP(args),
	SHOW_DIALOG: (args: GenericActionish) => new SHOW_DIALOG(args),
	PLAY_ENTITY_ANIMATION: (args: GenericActionish) => new PLAY_ENTITY_ANIMATION(args),
	TELEPORT_ENTITY_TO_GEOMETRY: (args: GenericActionish) => new TELEPORT_ENTITY_TO_GEOMETRY(args),
	WALK_ENTITY_TO_GEOMETRY: (args: GenericActionish) => new WALK_ENTITY_TO_GEOMETRY(args),
	WALK_ENTITY_ALONG_GEOMETRY: (args: GenericActionish) => new WALK_ENTITY_ALONG_GEOMETRY(args),
	LOOP_ENTITY_ALONG_GEOMETRY: (args: GenericActionish) => new LOOP_ENTITY_ALONG_GEOMETRY(args),
	SET_CAMERA_TO_FOLLOW_ENTITY: (args: GenericActionish) => new SET_CAMERA_TO_FOLLOW_ENTITY(args),
	TELEPORT_CAMERA_TO_GEOMETRY: (args: GenericActionish) => new TELEPORT_CAMERA_TO_GEOMETRY(args),
	PAN_CAMERA_TO_ENTITY: (args: GenericActionish) => new PAN_CAMERA_TO_ENTITY(args),
	PAN_CAMERA_TO_GEOMETRY: (args: GenericActionish) => new PAN_CAMERA_TO_GEOMETRY(args),
	PAN_CAMERA_ALONG_GEOMETRY: (args: GenericActionish) => new PAN_CAMERA_ALONG_GEOMETRY(args),
	LOOP_CAMERA_ALONG_GEOMETRY: (args: GenericActionish) => new LOOP_CAMERA_ALONG_GEOMETRY(args),
	SET_SCREEN_SHAKE: (args: GenericActionish) => new SET_SCREEN_SHAKE(args),
	SCREEN_FADE_OUT: (args: GenericActionish) => new SCREEN_FADE_OUT(args),
	SCREEN_FADE_IN: (args: GenericActionish) => new SCREEN_FADE_IN(args),
	MUTATE_VARIABLE: (args: GenericActionish) => new MUTATE_VARIABLE(args),
	MUTATE_VARIABLES: (args: GenericActionish) => new MUTATE_VARIABLES(args),
	COPY_VARIABLE: (args: GenericActionish) => new COPY_VARIABLE(args),
	SLOT_SAVE: () => new SLOT_SAVE(),
	SLOT_LOAD: (args: GenericActionish) => new SLOT_LOAD(args),
	SLOT_ERASE: (args: GenericActionish) => new SLOT_ERASE(args),
	SET_CONNECT_SERIAL_DIALOG: (args: GenericActionish) => new SET_CONNECT_SERIAL_DIALOG(args),
	SHOW_SERIAL_DIALOG: (args: GenericActionish) => new SHOW_SERIAL_DIALOG(args),
	SET_MAP_LOOK_SCRIPT: (args: GenericActionish) => new SET_MAP_LOOK_SCRIPT(args),
	SET_ENTITY_LOOK_SCRIPT: (args: GenericActionish) => new SET_ENTITY_LOOK_SCRIPT(args),
	SET_TELEPORT_ENABLED: (args: GenericActionish) => new SET_TELEPORT_ENABLED(args),
	SET_BLE_FLAG: (args: GenericActionish) => new SET_BLE_FLAG(args),
	SET_SERIAL_DIALOG_CONTROL: (args: GenericActionish) => new SET_SERIAL_DIALOG_CONTROL(args),
	REGISTER_SERIAL_DIALOG_COMMAND: (args: GenericActionish) => {
		return new REGISTER_SERIAL_DIALOG_COMMAND(args);
	},
	REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: (args: GenericActionish) => {
		return new REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT(args);
	},
	SET_ENTITY_MOVEMENT_RELATIVE: (args: GenericActionish) => {
		return new SET_ENTITY_MOVEMENT_RELATIVE(args);
	},
	CLOSE_DIALOG: () => new CLOSE_DIALOG(),
	CLOSE_SERIAL_DIALOG: () => new CLOSE_SERIAL_DIALOG(),
	SET_LIGHTS_CONTROL: (args: GenericActionish) => new SET_LIGHTS_CONTROL(args),
	SET_LIGHTS_STATE: (args: GenericActionish) => new SET_LIGHTS_STATE(args),
	GOTO_ACTION_INDEX: (args: GenericActionish) => new GOTO_ACTION_INDEX(args),
	SET_SCRIPT_PAUSE: (args: GenericActionish) => new SET_SCRIPT_PAUSE(args),
	REGISTER_SERIAL_DIALOG_COMMAND_ALIAS: (args: GenericActionish) => {
		return new REGISTER_SERIAL_DIALOG_COMMAND_ALIAS(args);
	},
	UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS: (args: GenericActionish) => {
		return new UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS(args);
	},
	SET_SERIAL_DIALOG_COMMAND_VISIBILITY: (args: GenericActionish) => {
		return new SET_SERIAL_DIALOG_COMMAND_VISIBILITY(args);
	},
	CHECK_ENTITY_NAME: (args: GenericActionish) => new CHECK_ENTITY_NAME(args),
	CHECK_ENTITY_X: (args: GenericActionish) => new CHECK_ENTITY_X(args),
	CHECK_ENTITY_Y: (args: GenericActionish) => new CHECK_ENTITY_Y(args),
	CHECK_ENTITY_INTERACT_SCRIPT: (args: GenericActionish) => {
		return new CHECK_ENTITY_INTERACT_SCRIPT(args);
	},
	CHECK_ENTITY_TICK_SCRIPT: (args: GenericActionish) => new CHECK_ENTITY_TICK_SCRIPT(args),
	CHECK_ENTITY_LOOK_SCRIPT: (args: GenericActionish) => new CHECK_ENTITY_LOOK_SCRIPT(args),
	CHECK_ENTITY_TYPE: (args: GenericActionish) => new CHECK_ENTITY_TYPE(args),
	CHECK_ENTITY_PRIMARY_ID: (args: GenericActionish) => new CHECK_ENTITY_PRIMARY_ID(args),
	CHECK_ENTITY_SECONDARY_ID: (args: GenericActionish) => new CHECK_ENTITY_SECONDARY_ID(args),
	CHECK_ENTITY_PRIMARY_ID_TYPE: (args: GenericActionish) => {
		return new CHECK_ENTITY_PRIMARY_ID_TYPE(args);
	},
	CHECK_ENTITY_CURRENT_ANIMATION: (args: GenericActionish) => {
		return new CHECK_ENTITY_CURRENT_ANIMATION(args);
	},
	CHECK_ENTITY_CURRENT_FRAME: (args: GenericActionish) => new CHECK_ENTITY_CURRENT_FRAME(args),
	CHECK_ENTITY_DIRECTION: (args: GenericActionish) => new CHECK_ENTITY_DIRECTION(args),
	CHECK_ENTITY_GLITCHED: (args: GenericActionish) => new CHECK_ENTITY_GLITCHED(args),
	CHECK_ENTITY_PATH: (args: GenericActionish) => new CHECK_ENTITY_PATH(args),
	CHECK_SAVE_FLAG: (args: GenericActionish) => new CHECK_SAVE_FLAG(args),
	CHECK_IF_ENTITY_IS_IN_GEOMETRY: (args: GenericActionish) => {
		return new CHECK_IF_ENTITY_IS_IN_GEOMETRY(args);
	},
	CHECK_FOR_BUTTON_PRESS: (args: GenericActionish) => new CHECK_FOR_BUTTON_PRESS(args),
	CHECK_FOR_BUTTON_STATE: (args: GenericActionish) => new CHECK_FOR_BUTTON_STATE(args),
	CHECK_WARP_STATE: (args: GenericActionish) => new CHECK_WARP_STATE(args),
	CHECK_VARIABLE: (args: GenericActionish) => new CHECK_VARIABLE(args),
	CHECK_VARIABLES: (args: GenericActionish) => new CHECK_VARIABLES(args),
	CHECK_MAP: (args: GenericActionish) => new CHECK_MAP(args),
	CHECK_BLE_FLAG: (args: GenericActionish) => new CHECK_BLE_FLAG(args),
	CHECK_DIALOG_OPEN: (args: GenericActionish) => new CHECK_DIALOG_OPEN(args),
	CHECK_SERIAL_DIALOG_OPEN: (args: GenericActionish) => new CHECK_SERIAL_DIALOG_OPEN(args),
	CHECK_DEBUG_MODE: (args: GenericActionish) => new CHECK_DEBUG_MODE(args),
};

export const summonActionConstructor = (v: unknown) => {
	if (typeof v !== 'object' || v === null || v === undefined) {
		throw new Error('cannot create action from ' + typeof v);
	}
	const actionName = String((v as Action).action); // todo: best practices?
	if (typeof actionName === 'string' && actionConstructorLookup[actionName]) {
		return actionConstructorLookup[actionName](v);
	}
	throw new Error('failed to create action ' + actionName);
};
// Takes the "maybe has too many properties" Mathlang object and strips all nonessential fields
// old style so the old and new output can be directly compared (I think)
export const standardizeNode = (
	action: Action | GenericActionish,
	OOB: number,
): Action | GenericActionish => {
	if (action instanceof CopyMacro) {
		const manual = new COPY_SCRIPT({
			script: breakIfNotString(action.script),
		});
		return manual;
	}
	if (action instanceof LabelDefinition) {
		const value = breakIfNotString(action.label);
		return new LABEL({ value });
	}
	if (action instanceof GotoLabel) {
		const ret = new GOTO_ACTION_INDEX({
			action_index: breakIfNotString(action.label),
		});
		return ret;
	}
	if (action instanceof ReturnStatement) {
		const ret = new GOTO_ACTION_INDEX({
			action_index: OOB,
		});
		return ret;
	}
	const actionName = breakIfNotString(action.action);
	Object.keys(action).forEach((field: string) => {
		if (!isFieldForAction(field, actionName) && field !== 'action') {
			delete action[field];
		}
	});
	if (actionConstructorLookup[actionName]) {
		return actionConstructorLookup[actionName](action);
	}
	return action;
};
