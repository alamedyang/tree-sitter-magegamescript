import { Node as TreeSitterNode } from 'web-tree-sitter';
import { LabelDefinition, ReturnStatement, CopyMacro } from './parser-types.ts';
import { type GenericActionish } from './parser-actions.ts';
import { type FileState } from './parser-file.ts';

// For intermediate data types and MGS-specific nodes
export class MGSDebug {
	node: TreeSitterNode;
	f: FileState;
	fileName: string;
	comment?: string;
	constructor(f: FileState, node: TreeSitterNode, comment?: string) {
		this.f = f;
		this.fileName = f.fileName;
		this.node = node;
		if (comment) this.comment = comment;
	}
}

export class Action {
	action: string;
	debug?: MGSDebug;
	clone() {
		const fn = constructorLookup[this.action];
		if (!fn) throw new Error('no action constructor for ' + this.action);
		return fn({ ...this });
	}
}

export class GotoLabel {
	mathlang: 'goto_label';
	label: string;
	debug: MGSDebug;
	comment?: string;
	constructor(f: FileState, node: TreeSitterNode, label: unknown, comment?: string) {
		this.mathlang = 'goto_label';
		this.label = breakIfNotString(label, 'GotoLabel label');
		this.debug = new MGSDebug(f, node);
		if (comment) this.comment = comment;
	}
	clone(prev: GotoLabel) {
		return new GotoLabel(prev.debug.f, prev.debug.node, prev.label, prev.comment);
	}
}

// ---------------------------------- SUPER TYPES ---------------------------------- \\

export class BoolGetable extends Action {
	mathlang: 'bool_getable';
	debug?: MGSDebug;
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
	debug?: MGSDebug;
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
	// updateProp(_prop: string) {}
}
export class NumberComparison extends Action {
	mathlang: 'number_comparison';
	debug?: MGSDebug;
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
	debug?: MGSDebug;
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
	debug?: MGSDebug;
	constructor() {
		super();
		this.action = 'NULL_ACTION';
	}
}
export class LABEL extends Action {
	action: 'LABEL';
	debug?: MGSDebug;
	value: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'LABEL';
		this.value = breakIfNotString(args?.value, 'LABEL value');
	}
}
export class RUN_SCRIPT extends Action {
	action: 'RUN_SCRIPT';
	debug?: MGSDebug;
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'RUN_SCRIPT';
		this.script = breakIfNotString(args?.script, 'RUN_SCRIPT script');
	}
}
export class BLOCKING_DELAY extends Action {
	action: 'BLOCKING_DELAY';
	debug?: MGSDebug;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'BLOCKING_DELAY';
		this.duration = breakIfNotNumber(args?.duration, 'BLOCKING_DELAY duration');
	}
}
export class NON_BLOCKING_DELAY extends Action {
	action: 'NON_BLOCKING_DELAY';
	debug?: MGSDebug;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'NON_BLOCKING_DELAY';
		this.duration = breakIfNotNumber(args?.duration, 'NON_BLOCKING_DELAY duration');
	}
}

export class SET_ENTITY_NAME extends Action {
	action: 'SET_ENTITY_NAME';
	debug?: MGSDebug;
	entity: string;
	string: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_NAME';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_NAME entity');
		this.string = breakIfNotString(args?.string, 'SET_ENTITY_NAME string');
	}
}
export class SET_ENTITY_X extends Action {
	action: 'SET_ENTITY_X';
	debug?: MGSDebug;
	entity: string;
	u2_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_X';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_X entity');
		this.u2_value = breakIfNotNumber(args?.u2_value, 'SET_ENTITY_X u2_value');
	}
}
export class SET_ENTITY_Y extends Action {
	action: 'SET_ENTITY_Y';
	debug?: MGSDebug;
	entity: string;
	u2_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_Y';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_Y entity');
		this.u2_value = breakIfNotNumber(args?.u2_value, 'SET_ENTITY_Y u2_value');
	}
}
export class SET_ENTITY_INTERACT_SCRIPT extends Action {
	action: 'SET_ENTITY_INTERACT_SCRIPT';
	debug?: MGSDebug;
	entity: string;
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_INTERACT_SCRIPT';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_INTERACT_SCRIPT entity');
		this.script = breakIfNotString(args?.script, 'SET_ENTITY_INTERACT_SCRIPT script');
	}
}
export class SET_ENTITY_TICK_SCRIPT extends Action {
	action: 'SET_ENTITY_TICK_SCRIPT';
	debug?: MGSDebug;
	entity: string;
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_TICK_SCRIPT';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_TICK_SCRIPT entity');
		this.script = breakIfNotString(args?.script, 'SET_ENTITY_TICK_SCRIPT script');
	}
}
export class SET_ENTITY_TYPE extends Action {
	action: 'SET_ENTITY_TYPE';
	debug?: MGSDebug;
	entity: string;
	entity_type: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_TYPE';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_TYPE entity');
		this.entity_type = breakIfNotString(args?.entity_type, 'SET_ENTITY_TYPE entity_type');
	}
}
export class SET_ENTITY_PRIMARY_ID extends Action {
	action: 'SET_ENTITY_PRIMARY_ID';
	debug?: MGSDebug;
	entity: string;
	u2_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_PRIMARY_ID';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_PRIMARY_ID entity');
		this.u2_value = breakIfNotNumber(args?.u2_value, 'SET_ENTITY_PRIMARY_ID u2_value');
	}
}
export class SET_ENTITY_SECONDARY_ID extends Action {
	action: 'SET_ENTITY_SECONDARY_ID';
	debug?: MGSDebug;
	entity: string;
	u2_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_SECONDARY_ID';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_SECONDARY_ID entity');
		this.u2_value = breakIfNotNumber(args?.u2_value, 'SET_ENTITY_SECONDARY_ID u2_value');
	}
}
export class SET_ENTITY_PRIMARY_ID_TYPE extends Action {
	action: 'SET_ENTITY_PRIMARY_ID_TYPE';
	debug?: MGSDebug;
	entity: string;
	byte_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_PRIMARY_ID_TYPE';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_PRIMARY_ID_TYPE entity');
		this.byte_value = breakIfNotNumber(
			args?.byte_value,
			'SET_ENTITY_PRIMARY_ID_TYPE byte_value',
		);
	}
}
export class SET_ENTITY_CURRENT_ANIMATION extends Action {
	action: 'SET_ENTITY_CURRENT_ANIMATION';
	debug?: MGSDebug;
	entity: string;
	byte_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_CURRENT_ANIMATION';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_CURRENT_ANIMATION entity');
		this.byte_value = breakIfNotNumber(
			args?.byte_value,
			'SET_ENTITY_CURRENT_ANIMATION byte_value',
		);
	}
}
export class SET_ENTITY_CURRENT_FRAME extends Action {
	action: 'SET_ENTITY_CURRENT_FRAME';
	debug?: MGSDebug;
	entity: string;
	byte_value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_CURRENT_FRAME';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_CURRENT_FRAME entity');
		this.byte_value = breakIfNotNumber(args?.byte_value, 'SET_ENTITY_CURRENT_FRAME byte_value');
	}
}
export class SET_ENTITY_DIRECTION_RELATIVE extends Action {
	action: 'SET_ENTITY_DIRECTION_RELATIVE';
	debug?: MGSDebug;
	entity: string;
	relative_direction: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_DIRECTION_RELATIVE';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_DIRECTION_RELATIVE entity');
		this.relative_direction = breakIfNotNumber(
			args?.relative_direction,
			'SET_ENTITY_DIRECTION_RELATIVE relative_direction',
		);
	}
}
// TODO: where is this one utilized??
export class SET_ENTITY_DIRECTION extends Action {
	action: 'SET_ENTITY_DIRECTION';
	debug?: MGSDebug;
	entity: string;
	direction: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_DIRECTION';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_DIRECTION entity');
		this.direction = breakIfNotString(args?.direction, 'SET_ENTITY_DIRECTION direction');
	}
}
// TODO: where is this one utilized??
export class SET_ENTITY_DIRECTION_TARGET_ENTITY extends Action {
	action: 'SET_ENTITY_DIRECTION_TARGET_ENTITY';
	debug?: MGSDebug;
	entity: string;
	target_entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_DIRECTION_TARGET_ENTITY';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_DIRECTION_TARGET_ENTITY entity');
		this.target_entity = breakIfNotString(
			args?.target_entity,
			'SET_ENTITY_DIRECTION_TARGET_ENTITY target_entity',
		);
	}
}
// TODO: where is this one utilized??
export class SET_ENTITY_DIRECTION_TARGET_GEOMETRY extends Action {
	action: 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY';
	debug?: MGSDebug;
	entity: string;
	target_geometry: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY entity');
		this.target_geometry = breakIfNotString(
			args?.target_geometry,
			'SET_ENTITY_DIRECTION_TARGET_GEOMETRY target_geometry',
		);
	}
}
export class SET_ENTITY_GLITCHED extends Action {
	action: 'SET_ENTITY_GLITCHED';
	debug?: MGSDebug;
	entity: string;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_GLITCHED';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_GLITCHED entity');
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_ENTITY_GLITCHED bool_value');
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class SET_ENTITY_PATH extends Action {
	action: 'SET_ENTITY_PATH';
	debug?: MGSDebug;
	entity: string;
	geometry: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_PATH';
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_PATH entity');
		this.geometry = breakIfNotString(args?.geometry, 'SET_ENTITY_PATH geometry');
	}
}

export class COPY_SCRIPT extends Action {
	action: 'COPY_SCRIPT';
	debug?: MGSDebug;
	script: string;
	search_and_replace?: Record<string, string>;
	constructor(args: GenericActionish) {
		super();
		this.action = 'COPY_SCRIPT';
		this.script = breakIfNotString(args?.script, 'COPY_SCRIPT script');
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
	debug?: MGSDebug;
	save_flag: string;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SAVE_FLAG';
		this.save_flag = breakIfNotString(args?.save_flag, 'SET_SAVE_FLAG save_flag');
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_SAVE_FLAG bool_value');
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class SET_PLAYER_CONTROL extends Action {
	action: 'SET_PLAYER_CONTROL';
	debug?: MGSDebug;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_PLAYER_CONTROL';
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_PLAYER_CONTROL bool_value');
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class SET_MAP_TICK_SCRIPT extends Action {
	action: 'SET_MAP_TICK_SCRIPT';
	debug?: MGSDebug;
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_MAP_TICK_SCRIPT';
		this.script = breakIfNotString(args?.script, 'SET_MAP_TICK_SCRIPT script');
	}
}
export class SET_HEX_CURSOR_LOCATION extends Action {
	action: 'SET_HEX_CURSOR_LOCATION';
	debug?: MGSDebug;
	address: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_CURSOR_LOCATION';
		this.address = breakIfNotNumber(args?.address, 'SET_HEX_CURSOR_LOCATION address');
	}
}
export class SET_WARP_STATE extends Action {
	action: 'SET_WARP_STATE';
	debug?: MGSDebug;
	string: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_WARP_STATE';
		this.string = breakIfNotString(args?.string, 'SET_WARP_STATE string');
	}
}
export class SET_HEX_EDITOR_STATE extends Action {
	action: 'SET_HEX_EDITOR_STATE';
	debug?: MGSDebug;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_EDITOR_STATE';
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_HEX_EDITOR_STATE bool_value');
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class SET_HEX_EDITOR_DIALOG_MODE extends Action {
	action: 'SET_HEX_EDITOR_DIALOG_MODE';
	debug?: MGSDebug;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_EDITOR_DIALOG_MODE';
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_HEX_EDITOR_DIALOG_MODE bool_value');
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class SET_HEX_EDITOR_CONTROL extends Action {
	action: 'SET_HEX_EDITOR_CONTROL';
	debug?: MGSDebug;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_EDITOR_CONTROL';
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_HEX_EDITOR_CONTROL bool_value');
	}
}
export class SET_HEX_EDITOR_CONTROL_CLIPBOARD extends Action {
	action: 'SET_HEX_EDITOR_CONTROL_CLIPBOARD';
	debug?: MGSDebug;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_HEX_EDITOR_CONTROL_CLIPBOARD';
		this.bool_value = breakIfNotBool(
			args?.bool_value,
			'SET_HEX_EDITOR_CONTROL_CLIPBOARD bool_value',
		);
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class LOAD_MAP extends Action {
	action: 'LOAD_MAP';
	debug?: MGSDebug;
	map: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'LOAD_MAP';
		this.map = breakIfNotString(args?.map, 'LOAD_MAP map');
	}
}
export class SHOW_DIALOG extends Action {
	action: 'SHOW_DIALOG';
	debug?: MGSDebug;
	dialog: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SHOW_DIALOG';
		this.dialog = breakIfNotString(args?.dialog, 'SHOW_DIALOG dialog');
	}
}
export class PLAY_ENTITY_ANIMATION extends Action {
	action: 'PLAY_ENTITY_ANIMATION';
	debug?: MGSDebug;
	entity: string;
	animation: number;
	play_count: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'PLAY_ENTITY_ANIMATION';
		this.entity = breakIfNotString(args?.entity, 'PLAY_ENTITY_ANIMATION entity');
		this.animation = breakIfNotNumber(args?.animation, 'PLAY_ENTITY_ANIMATION animation');
		this.play_count = breakIfNotNumber(args?.play_count, 'PLAY_ENTITY_ANIMATION play_count');
	}
}
export class TELEPORT_ENTITY_TO_GEOMETRY extends Action {
	action: 'TELEPORT_ENTITY_TO_GEOMETRY';
	debug?: MGSDebug;
	geometry: string;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'TELEPORT_ENTITY_TO_GEOMETRY';
		this.entity = breakIfNotString(args?.entity, 'TELEPORT_ENTITY_TO_GEOMETRY entity');
		this.geometry = breakIfNotString(args?.geometry, 'TELEPORT_ENTITY_TO_GEOMETRY geometry');
	}
}
export class WALK_ENTITY_TO_GEOMETRY extends Action {
	action: 'WALK_ENTITY_TO_GEOMETRY';
	debug?: MGSDebug;
	geometry: string;
	entity: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'WALK_ENTITY_TO_GEOMETRY';
		this.geometry = breakIfNotString(args?.geometry, 'WALK_ENTITY_TO_GEOMETRY geometry');
		this.entity = breakIfNotString(args?.entity, 'WALK_ENTITY_TO_GEOMETRY entity');
		this.duration = breakIfNotNumber(args?.duration, 'WALK_ENTITY_TO_GEOMETRY duration');
	}
}
export class WALK_ENTITY_ALONG_GEOMETRY extends Action {
	action: 'WALK_ENTITY_ALONG_GEOMETRY';
	debug?: MGSDebug;
	geometry: string;
	entity: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'WALK_ENTITY_ALONG_GEOMETRY';
		this.geometry = breakIfNotString(args?.geometry, 'WALK_ENTITY_ALONG_GEOMETRY geometry');
		this.entity = breakIfNotString(args?.entity, 'WALK_ENTITY_ALONG_GEOMETRY entity');
		this.duration = breakIfNotNumber(args?.duration, 'WALK_ENTITY_ALONG_GEOMETRY duration');
	}
}
export class LOOP_ENTITY_ALONG_GEOMETRY extends Action {
	action: 'LOOP_ENTITY_ALONG_GEOMETRY';
	debug?: MGSDebug;
	geometry: string;
	entity: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'LOOP_ENTITY_ALONG_GEOMETRY';
		this.geometry = breakIfNotString(args?.geometry, 'LOOP_ENTITY_ALONG_GEOMETRY geometry');
		this.entity = breakIfNotString(args?.entity, 'LOOP_ENTITY_ALONG_GEOMETRY entity');
		this.duration = breakIfNotNumber(args?.duration, 'LOOP_ENTITY_ALONG_GEOMETRY duration');
	}
}
export class SET_CAMERA_TO_FOLLOW_ENTITY extends Action {
	action: 'SET_CAMERA_TO_FOLLOW_ENTITY';
	debug?: MGSDebug;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_CAMERA_TO_FOLLOW_ENTITY';
		this.entity = breakIfNotString(args?.entity, 'SET_CAMERA_TO_FOLLOW_ENTITY entity');
	}
}
export class TELEPORT_CAMERA_TO_GEOMETRY extends Action {
	action: 'TELEPORT_CAMERA_TO_GEOMETRY';
	debug?: MGSDebug;
	geometry: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'TELEPORT_CAMERA_TO_GEOMETRY';
		this.geometry = breakIfNotString(args?.geometry, 'TELEPORT_CAMERA_TO_GEOMETRY geometry');
	}
}
export class PAN_CAMERA_TO_ENTITY extends Action {
	action: 'PAN_CAMERA_TO_ENTITY';
	debug?: MGSDebug;
	entity: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'PAN_CAMERA_TO_ENTITY';
		this.entity = breakIfNotString(args?.entity, 'PAN_CAMERA_TO_ENTITY entity');
		this.duration = breakIfNotNumber(args?.duration, 'PAN_CAMERA_TO_ENTITY duration');
	}
}
export class PAN_CAMERA_TO_GEOMETRY extends Action {
	action: 'PAN_CAMERA_TO_GEOMETRY';
	debug?: MGSDebug;
	geometry: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'PAN_CAMERA_TO_GEOMETRY';
		this.geometry = breakIfNotString(args?.geometry, 'PAN_CAMERA_TO_GEOMETRY geometry');
		this.duration = breakIfNotNumber(args?.duration, 'PAN_CAMERA_TO_GEOMETRY entidurationty');
	}
}
export class PAN_CAMERA_ALONG_GEOMETRY extends Action {
	action: 'PAN_CAMERA_ALONG_GEOMETRY';
	debug?: MGSDebug;
	// entity: string; // ?? really?
	geometry: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'PAN_CAMERA_ALONG_GEOMETRY';
		this.geometry = breakIfNotString(args?.geometry, 'PAN_CAMERA_ALONG_GEOMETRY geometry');
		this.duration = breakIfNotNumber(args?.duration, 'PAN_CAMERA_ALONG_GEOMETRY duration');
	}
}
export class LOOP_CAMERA_ALONG_GEOMETRY extends Action {
	action: 'LOOP_CAMERA_ALONG_GEOMETRY';
	debug?: MGSDebug;
	// entity: string; // ?? really?
	geometry: string;
	duration: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'LOOP_CAMERA_ALONG_GEOMETRY';
		this.geometry = breakIfNotString(args?.geometry, 'LOOP_CAMERA_ALONG_GEOMETRY geometry');
		this.duration = breakIfNotNumber(args?.duration, 'LOOP_CAMERA_ALONG_GEOMETRY duration');
	}
}
export class SET_SCREEN_SHAKE extends Action {
	action: 'SET_SCREEN_SHAKE';
	debug?: MGSDebug;
	duration: number;
	frequency: number;
	amplitude: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SCREEN_SHAKE';
		this.duration = breakIfNotNumber(args?.duration, 'SET_SCREEN_SHAKE duration');
		this.frequency = breakIfNotNumber(args?.frequency, 'SET_SCREEN_SHAKE frequency');
		this.amplitude = breakIfNotNumber(args?.amplitude, 'SET_SCREEN_SHAKE amplitude');
	}
}
export class SCREEN_FADE_OUT extends Action {
	action: 'SCREEN_FADE_OUT';
	debug?: MGSDebug;
	duration: number;
	color: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SCREEN_FADE_OUT';
		this.duration = breakIfNotNumber(args?.duration, 'SCREEN_FADE_OUT duration');
		this.color = breakIfNotString(args?.color, 'SCREEN_FADE_OUT color');
	}
}
export class SCREEN_FADE_IN extends Action {
	action: 'SCREEN_FADE_IN';
	debug?: MGSDebug;
	duration: number;
	color: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SCREEN_FADE_IN';
		this.duration = breakIfNotNumber(args?.duration, 'SCREEN_FADE_IN duration');
		this.color = breakIfNotString(args?.color, 'SCREEN_FADE_IN color');
	}
}
export class MUTATE_VARIABLE extends Action {
	action: 'MUTATE_VARIABLE';
	debug?: MGSDebug;
	variable: string;
	operation: string;
	value: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'MUTATE_VARIABLE';
		this.variable = breakIfNotString(args?.variable, 'MUTATE_VARIABLE variable');
		this.operation = breakIfNotString(args?.operation, 'MUTATE_VARIABLE operation');
		this.value = breakIfNotNumber(args?.value, 'MUTATE_VARIABLE value');
	}
}
export class MUTATE_VARIABLES extends Action {
	action: 'MUTATE_VARIABLES';
	debug?: MGSDebug;
	variable: string;
	operation: string;
	source: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'MUTATE_VARIABLES';
		this.variable = breakIfNotString(args?.variable, 'MUTATE_VARIABLES variable');
		this.operation = breakIfNotString(args?.operation, 'MUTATE_VARIABLES operation');
		this.source = breakIfNotString(args?.source, 'MUTATE_VARIABLES source');
	}
}
export class COPY_VARIABLE extends Action {
	action: 'COPY_VARIABLE';
	debug?: MGSDebug;
	variable: string;
	entity: string;
	field: string;
	inbound: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'COPY_VARIABLE';
		this.variable = breakIfNotString(args?.variable, 'COPY_VARIABLE variable');
		this.entity = breakIfNotString(args?.entity, 'COPY_VARIABLE entity');
		this.field = breakIfNotString(args?.field, 'COPY_VARIABLE field');
		this.inbound = breakIfNotBool(args?.inbound, 'COPY_VARIABLE inbound');
	}
}
export class SLOT_SAVE extends Action {
	action: 'SLOT_SAVE';
	debug?: MGSDebug;
	constructor() {
		super();
		this.action = 'SLOT_SAVE';
	}
}
export class SLOT_LOAD extends Action {
	action: 'SLOT_LOAD';
	debug?: MGSDebug;
	slot: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SLOT_LOAD';
		this.slot = breakIfNotNumber(args?.slot, 'SLOT_LOAD slot');
	}
}
export class SLOT_ERASE extends Action {
	action: 'SLOT_ERASE';
	debug?: MGSDebug;
	slot: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SLOT_ERASE';
		this.slot = breakIfNotNumber(args?.slot, 'SLOT_ERASE slot');
	}
}
export class SET_CONNECT_SERIAL_DIALOG extends Action {
	action: 'SET_CONNECT_SERIAL_DIALOG';
	debug?: MGSDebug;
	serial_dialog: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_CONNECT_SERIAL_DIALOG';
		this.serial_dialog = breakIfNotString(
			args?.serial_dialog,
			'SET_CONNECT_SERIAL_DIALOG serial_dialog',
		);
	}
}
export class SHOW_SERIAL_DIALOG extends Action {
	action: 'SHOW_SERIAL_DIALOG';
	debug?: MGSDebug;
	serial_dialog: string;
	disable_newline?: boolean; // might be absent on old stuff
	constructor(args: GenericActionish) {
		super();
		this.action = 'SHOW_SERIAL_DIALOG';
		this.serial_dialog = breakIfNotString(
			args?.serial_dialog,
			'SHOW_SERIAL_DIALOG serial_dialog',
		);
		if (args?.disable_newline) {
			this.disable_newline = true;
		}
	}
}
export class SET_MAP_LOOK_SCRIPT extends Action {
	action: 'SET_MAP_LOOK_SCRIPT';
	debug?: MGSDebug;
	script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_MAP_LOOK_SCRIPT';
		this.script = breakIfNotString(args?.script, 'SET_MAP_LOOK_SCRIPT script');
	}
}
export class SET_ENTITY_LOOK_SCRIPT extends Action {
	action: 'SET_ENTITY_LOOK_SCRIPT';
	debug?: MGSDebug;
	script: string;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_LOOK_SCRIPT';
		this.script = breakIfNotString(args?.script, 'SET_ENTITY_LOOK_SCRIPT script');
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_LOOK_SCRIPT entity');
	}
}
export class SET_TELEPORT_ENABLED extends Action {
	action: 'SET_TELEPORT_ENABLED';
	debug?: MGSDebug;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_TELEPORT_ENABLED';
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_TELEPORT_ENABLED bool_value');
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class SET_BLE_FLAG extends Action {
	action: 'SET_BLE_FLAG';
	debug?: MGSDebug;
	ble_flag: string;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_BLE_FLAG';
		this.ble_flag = breakIfNotString(args?.ble_flag, 'SET_BLE_FLAG ble_flag');
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_BLE_FLAG bool_value');
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class SET_SERIAL_DIALOG_CONTROL extends Action {
	action: 'SET_SERIAL_DIALOG_CONTROL';
	debug?: MGSDebug;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SERIAL_DIALOG_CONTROL';
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_SERIAL_DIALOG_CONTROL bool_value');
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class REGISTER_SERIAL_DIALOG_COMMAND extends Action {
	action: 'REGISTER_SERIAL_DIALOG_COMMAND';
	debug?: MGSDebug;
	command: string;
	script: string;
	is_fail?: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'REGISTER_SERIAL_DIALOG_COMMAND';
		this.command = breakIfNotString(args?.command, 'REGISTER_SERIAL_DIALOG_COMMAND command');
		this.script = breakIfNotString(args?.script, 'REGISTER_SERIAL_DIALOG_COMMAND script');
		if (args.is_fail) this.is_fail = true;
	}
}
export class REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT extends Action {
	action: 'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
	debug?: MGSDebug;
	command: string;
	script: string;
	argument: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
		this.command = breakIfNotString(
			args?.command,
			'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT command',
		);
		this.script = breakIfNotString(
			args?.script,
			'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT script',
		);
		this.argument = breakIfNotString(
			args?.argument,
			'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT argument',
		);
	}
}
export class UNREGISTER_SERIAL_DIALOG_COMMAND extends Action {
	action: 'UNREGISTER_SERIAL_DIALOG_COMMAND';
	debug?: MGSDebug;
	command: string;
	is_fail?: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'UNREGISTER_SERIAL_DIALOG_COMMAND';
		this.command = breakIfNotString(args?.command, 'UNREGISTER_SERIAL_DIALOG_COMMAND command');
		if (args.is_fail !== undefined) {
			this.is_fail = breakIfNotBool(args.is_fail, 'UNREGISTER_SERIAL_DIALOG_COMMAND is_fail');
		}
	}
}
export class UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT extends Action {
	action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
	debug?: MGSDebug;
	command: string;
	argument: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
		this.command = breakIfNotString(args?.command, 'UNREGISTER_SERIAL_DIALOG_COMMAND command');
		this.argument = breakIfNotString(
			args?.argument,
			'UNREGISTER_SERIAL_DIALOG_COMMAND argument',
		);
	}
}
export class SET_ENTITY_MOVEMENT_RELATIVE extends Action {
	action: 'SET_ENTITY_MOVEMENT_RELATIVE';
	debug?: MGSDebug;
	relative_direction: number;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_ENTITY_MOVEMENT_RELATIVE';
		this.relative_direction = breakIfNotNumber(
			args?.relative_direction,
			'SET_ENTITY_MOVEMENT_RELATIVE relative_direction',
		);
		this.entity = breakIfNotString(args?.entity, 'SET_ENTITY_MOVEMENT_RELATIVE entity');
	}
}
export class CLOSE_DIALOG extends Action {
	action: 'CLOSE_DIALOG';
	debug?: MGSDebug;
	constructor() {
		super();
		this.action = 'CLOSE_DIALOG';
	}
}
export class CLOSE_SERIAL_DIALOG extends Action {
	action: 'CLOSE_SERIAL_DIALOG';
	debug?: MGSDebug;
	constructor() {
		super();
		this.action = 'CLOSE_SERIAL_DIALOG';
	}
}
export class SET_LIGHTS_CONTROL extends Action {
	action: 'SET_LIGHTS_CONTROL';
	debug?: MGSDebug;
	enabled: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_LIGHTS_CONTROL';
		this.enabled = breakIfNotBool(args?.enabled, 'SET_LIGHTS_CONTROL enabled');
	}
	invert() {
		this.enabled = !this.enabled;
	}
}
export class SET_LIGHTS_STATE extends Action {
	action: 'SET_LIGHTS_STATE';
	debug?: MGSDebug;
	lights: string | string[];
	enabled: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_LIGHTS_STATE';
		this.enabled = breakIfNotBool(args?.enabled, 'SET_LIGHTS_STATE enabled');
		this.lights = breakIfNotStringOrStringArray(args?.lights, 'SET_LIGHTS_STATE lights');
	}
	invert() {
		this.enabled = !this.enabled;
	}
}
export class GOTO_ACTION_INDEX extends Action {
	action: 'GOTO_ACTION_INDEX';
	debug?: MGSDebug;
	action_index: number | string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'GOTO_ACTION_INDEX';
		this.action_index = breakIfNotStringOrNumber(
			args?.action_index,
			'GOTO_ACTION_INDEX action_index',
		);
	}
}
export class SET_SCRIPT_PAUSE extends Action {
	action: 'SET_SCRIPT_PAUSE';
	debug?: MGSDebug;
	entity: string;
	script_slot: string;
	bool_value: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SCRIPT_PAUSE';
		this.entity = breakIfNotString(args?.entity, 'SET_SCRIPT_PAUSE entity');
		this.script_slot = breakIfNotString(args?.script_slot, 'SET_SCRIPT_PAUSE script_slot');
		this.bool_value = breakIfNotBool(args?.bool_value, 'SET_SCRIPT_PAUSE bool_value');
	}
	invert() {
		this.bool_value = !this.bool_value;
	}
}
export class REGISTER_SERIAL_DIALOG_COMMAND_ALIAS extends Action {
	action: 'REGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
	debug?: MGSDebug;
	command: string;
	alias: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'REGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
		this.command = breakIfNotString(
			args?.command,
			'REGISTER_SERIAL_DIALOG_COMMAND_ALIAS command',
		);
		this.alias = breakIfNotString(args?.alias, 'REGISTER_SERIAL_DIALOG_COMMAND_ALIAS alias');
	}
}
export class UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS extends Action {
	action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
	debug?: MGSDebug;
	alias: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
		this.alias = breakIfNotString(args?.alias, 'UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS alias');
	}
}
export class SET_SERIAL_DIALOG_COMMAND_VISIBILITY extends Action {
	action: 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY';
	debug?: MGSDebug;
	command: string;
	is_visible: boolean;
	constructor(args: GenericActionish) {
		super();
		this.action = 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY';
		this.command = breakIfNotString(
			args?.command,
			'SET_SERIAL_DIALOG_COMMAND_VISIBILITY command',
		);
		this.is_visible = breakIfNotBool(
			args?.is_visible,
			'SET_SERIAL_DIALOG_COMMAND_VISIBILITY is_visible',
		);
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
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_NAME success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_NAME label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_ENTITY_NAME jump_index');
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_NAME entity');
		this.string = breakIfNotString(args?.string, 'CHECK_ENTITY_NAME string');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_ENTITY_NAME expected_bool');
	}
	updateProp(value: string) {
		this.string = value;
	}
}
export class CHECK_ENTITY_X extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_X';
	entity: string;
	expected_u2: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_X';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_X success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_X label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_ENTITY_X jump_index');
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_X entity');
		this.expected_u2 = breakIfNotNumber(args?.expected_u2, 'CHECK_ENTITY_X expected_u2');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_ENTITY_X expected_bool');
	}
	updateProp(value: number) {
		this.expected_u2 = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
}
export class CHECK_ENTITY_Y extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_Y';
	entity: string;
	expected_u2: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_Y';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_Y success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_Y label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_ENTITY_Y jump_index');
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_Y entity');
		this.expected_u2 = breakIfNotNumber(args?.expected_u2, 'CHECK_ENTITY_Y expected_u2');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_ENTITY_Y expected_bool');
	}
	updateProp(value: number) {
		this.expected_u2 = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
}
export class CHECK_ENTITY_INTERACT_SCRIPT extends StringCheckable {
	action: 'CHECK_ENTITY_INTERACT_SCRIPT';
	entity: string;
	expected_script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_INTERACT_SCRIPT';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_INTERACT_SCRIPT success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_INTERACT_SCRIPT label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_INTERACT_SCRIPT jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_INTERACT_SCRIPT entity');
		this.expected_script = breakIfNotString(
			args?.expected_script,
			'CHECK_ENTITY_INTERACT_SCRIPT expected_script',
		);
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_INTERACT_SCRIPT expected_bool',
		);
	}
	updateProp(value: string) {
		this.expected_script = value;
	}
}
export class CHECK_ENTITY_TICK_SCRIPT extends StringCheckable {
	action: 'CHECK_ENTITY_TICK_SCRIPT';
	entity: string;
	expected_script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_TICK_SCRIPT';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_TICK_SCRIPT success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_TICK_SCRIPT label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_TICK_SCRIPT jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_TICK_SCRIPT entity');
		this.expected_script = breakIfNotString(
			args?.expected_script,
			'CHECK_ENTITY_TICK_SCRIPT expected_script',
		);
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_TICK_SCRIPT expected_bool',
		);
	}
	updateProp(value: string) {
		this.expected_script = value;
	}
}
export class CHECK_ENTITY_LOOK_SCRIPT extends StringCheckable {
	action: 'CHECK_ENTITY_LOOK_SCRIPT';
	entity: string;
	expected_script: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_LOOK_SCRIPT';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_LOOK_SCRIPT success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_LOOK_SCRIPT label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_LOOK_SCRIPT jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_LOOK_SCRIPT entity');
		this.expected_script = breakIfNotString(
			args?.expected_script,
			'CHECK_ENTITY_LOOK_SCRIPT expected_script',
		);
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_LOOK_SCRIPT expected_bool',
		);
	}
	updateProp(value: string) {
		this.expected_script = value;
	}
}
export class CHECK_ENTITY_TYPE extends StringCheckable {
	action: 'CHECK_ENTITY_TYPE';
	entity: string;
	entity_type: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_TYPE';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_TYPE success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_TYPE label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_ENTITY_TYPE jump_index');
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_TYPE entity');
		this.entity_type = breakIfNotString(args?.entity_type, 'CHECK_ENTITY_TYPE entity_type');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_ENTITY_TYPE expected_bool');
	}
	updateProp(value: string) {
		this.entity_type = value;
	}
}
export class CHECK_ENTITY_PRIMARY_ID extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_PRIMARY_ID';
	entity: string;
	expected_u2: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_PRIMARY_ID';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_PRIMARY_ID success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_PRIMARY_ID label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_PRIMARY_ID jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_PRIMARY_ID entity');
		this.expected_u2 = breakIfNotNumber(
			args?.expected_u2,
			'CHECK_ENTITY_PRIMARY_ID expected_u2',
		);
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_PRIMARY_ID expected_bool',
		);
	}
	updateProp(value: number) {
		this.expected_u2 = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
}
export class CHECK_ENTITY_SECONDARY_ID extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_SECONDARY_ID';
	entity: string;
	expected_u2: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_SECONDARY_ID';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_SECONDARY_ID success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_SECONDARY_ID label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_SECONDARY_ID jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_SECONDARY_ID entity');
		this.expected_u2 = breakIfNotNumber(
			args?.expected_u2,
			'CHECK_ENTITY_SECONDARY_ID expected_u2',
		);
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_SECONDARY_ID expected_bool',
		);
	}
	updateProp(value: number) {
		this.expected_u2 = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
}
export class CHECK_ENTITY_PRIMARY_ID_TYPE extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_PRIMARY_ID_TYPE';
	entity: string;
	expected_byte: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_PRIMARY_ID_TYPE';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_PRIMARY_ID_TYPE success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_PRIMARY_ID_TYPE label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_PRIMARY_ID_TYPE jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_PRIMARY_ID_TYPE entity');
		this.expected_byte = breakIfNotNumber(
			args?.expected_byte,
			'CHECK_ENTITY_PRIMARY_ID_TYPE expected_byte',
		);
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_PRIMARY_ID_TYPE expected_bool',
		);
	}
	updateProp(value: number) {
		this.expected_byte = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
}
export class CHECK_ENTITY_CURRENT_ANIMATION extends NumberCheckableEquality {
	action: 'CHECK_ENTITY_CURRENT_ANIMATION';
	entity: string;
	expected_byte: number;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_CURRENT_ANIMATION';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_CURRENT_ANIMATION success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_CURRENT_ANIMATION label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_CURRENT_ANIMATION jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_CURRENT_ANIMATION entity');
		this.expected_byte = breakIfNotNumber(
			args?.expected_byte,
			'CHECK_ENTITY_CURRENT_ANIMATION expected_byte',
		);
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_CURRENT_ANIMATION expected_bool',
		);
	}
	updateProp(value: number) {
		this.expected_byte = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
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
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_CURRENT_FRAME success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_CURRENT_FRAME label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_CURRENT_FRAME jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_CURRENT_FRAME entity');
		this.expected_byte = breakIfNotNumber(
			args?.expected_byte,
			'CHECK_ENTITY_CURRENT_FRAME expected_byte',
		);
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_CURRENT_FRAME expected_bool',
		);
	}
	updateProp(value: number) {
		this.expected_byte = value;
	}
	invert() {
		this.expected_bool = !this.expected_bool;
	}
}
export class CHECK_ENTITY_DIRECTION extends StringCheckable {
	action: 'CHECK_ENTITY_DIRECTION';
	entity: string;
	direction: string; // north, south, east, west
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_DIRECTION';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_DIRECTION success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_DIRECTION label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_DIRECTION jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_DIRECTION entity');
		this.direction = breakIfNotString(args?.direction, 'CHECK_ENTITY_DIRECTION entity_type');
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_DIRECTION expected_bool',
		);
	}
	updateProp(value: string) {
		this.direction = value;
	}
}
export class CHECK_ENTITY_GLITCHED extends BoolGetable {
	action: 'CHECK_ENTITY_GLITCHED';
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_ENTITY_GLITCHED';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_GLITCHED success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_GLITCHED label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_ENTITY_GLITCHED jump_index',
			);
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_GLITCHED entity');
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_ENTITY_GLITCHED expected_bool',
		);
	}
}
export class CHECK_ENTITY_PATH extends StringCheckable {
	action: 'CHECK_ENTITY_PATH';
	geometry: string;
	entity: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_ENTITY_PATH';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_ENTITY_PATH success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_ENTITY_PATH label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_ENTITY_PATH jump_index');
		}
		this.entity = breakIfNotString(args?.entity, 'CHECK_ENTITY_PATH entity');
		this.geometry = breakIfNotString(args?.geometry, 'CHECK_ENTITY_PATH geometry');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_ENTITY_PATH expected_bool');
	}
	updateProp(value: string) {
		this.geometry = value;
	}
}
export class CHECK_SAVE_FLAG extends BoolGetable {
	action: 'CHECK_SAVE_FLAG';
	save_flag: string;
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_SAVE_FLAG';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_SAVE_FLAG success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_SAVE_FLAG label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_SAVE_FLAG jump_index');
		}
		this.save_flag = breakIfNotString(args?.save_flag, 'CHECK_SAVE_FLAG save_flag');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_SAVE_FLAG expected_bool');
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
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_IF_ENTITY_IS_IN_GEOMETRY success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_IF_ENTITY_IS_IN_GEOMETRY label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_IF_ENTITY_IS_IN_GEOMETRY jump_index',
			);
		}
		this.geometry = breakIfNotString(args?.geometry, 'CHECK_IF_ENTITY_IS_IN_GEOMETRY geometry');
		this.entity = breakIfNotString(args?.entity, 'CHECK_IF_ENTITY_IS_IN_GEOMETRY entity');
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_IF_ENTITY_IS_IN_GEOMETRY expected_bool',
		);
	}
}
export class CHECK_FOR_BUTTON_PRESS extends BoolGetable {
	action: 'CHECK_FOR_BUTTON_PRESS';
	button_id: string;
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_FOR_BUTTON_PRESS';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_FOR_BUTTON_PRESS success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_FOR_BUTTON_PRESS label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_FOR_BUTTON_PRESS jump_index',
			);
		}
		this.button_id = breakIfNotString(args?.button_id, 'CHECK_FOR_BUTTON_PRESS button_id');
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_FOR_BUTTON_PRESS expected_bool',
		);
	}
}
export class CHECK_FOR_BUTTON_STATE extends BoolGetable {
	action: 'CHECK_FOR_BUTTON_STATE';
	button_id: string;
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_FOR_BUTTON_STATE';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_FOR_BUTTON_STATE success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_FOR_BUTTON_STATE label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_FOR_BUTTON_STATE jump_index',
			);
		}
		this.button_id = breakIfNotString(args?.button_id, 'CHECK_FOR_BUTTON_STATE button_id');
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_FOR_BUTTON_STATE expected_bool',
		);
	}
}
export class CHECK_WARP_STATE extends StringCheckable {
	action: 'CHECK_WARP_STATE';
	string: string;
	constructor(args: GenericActionish) {
		super();
		this.action = 'CHECK_WARP_STATE';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_WARP_STATE success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_WARP_STATE label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_WARP_STATE jump_index');
		}
		this.string = breakIfNotString(args?.string, 'CHECK_WARP_STATE string');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_WARP_STATE expected_bool');
	}
	updateProp(value: string) {
		this.string = value;
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
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_VARIABLE success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_VARIABLE label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_VARIABLE jump_index');
		}
		this.variable = breakIfNotString(args?.variable, 'CHECK_VARIABLE variable');
		this.comparison = breakIfNotString(args?.comparison, 'CHECK_VARIABLE comparison');
		this.value = breakIfNotNumber(args?.value, 'CHECK_VARIABLE value');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_VARIABLE expected_bool');
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
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_VARIABLES success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_VARIABLES label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_VARIABLES jump_index');
		}
		this.variable = breakIfNotString(args?.variable, 'CHECK_VARIABLES variable');
		this.comparison = breakIfNotString(args?.comparison, 'CHECK_VARIABLES comparison');
		this.source = breakIfNotString(args?.source, 'CHECK_VARIABLES source');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_VARIABLES expected_bool');
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
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_MAP success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_MAP label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_MAP jump_index');
		}
		this.map = breakIfNotString(args?.map, 'CHECK_MAP map');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_MAP expected_bool');
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
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_BLE_FLAG success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_BLE_FLAG label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_BLE_FLAG jump_index');
		}
		this.ble_flag = breakIfNotString(args?.ble_flag, 'CHECK_BLE_FLAG ble_flag');
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_BLE_FLAG expected_bool');
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
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_DIALOG_OPEN success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_DIALOG_OPEN label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_DIALOG_OPEN jump_index');
		}
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_DIALOG_OPEN expected_bool');
	}
}
export class CHECK_SERIAL_DIALOG_OPEN extends BoolGetable {
	action: 'CHECK_SERIAL_DIALOG_OPEN';
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_SERIAL_DIALOG_OPEN';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_SERIAL_DIALOG_OPEN success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_SERIAL_DIALOG_OPEN label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(
				args?.jump_index,
				'CHECK_SERIAL_DIALOG_OPEN jump_index',
			);
		}
		this.expected_bool = breakIfNotBool(
			args?.expected_bool,
			'CHECK_SERIAL_DIALOG_OPEN expected_bool',
		);
	}
}
export class CHECK_DEBUG_MODE extends BoolGetable {
	action: 'CHECK_DEBUG_MODE';
	constructor(args: GenericActionish) {
		super();
		this.mathlang = 'bool_getable';
		this.action = 'CHECK_DEBUG_MODE';
		if (args?.success_script) {
			this.success_script = breakIfNotString(
				args?.success_script,
				'CHECK_DEBUG_MODE success_script',
			);
		} else if (args?.label) {
			this.label = breakIfNotString(args?.label, 'CHECK_DEBUG_MODE label');
		} else if (args?.jump_index) {
			this.jump_index = breakIfNotNumber(args?.jump_index, 'CHECK_DEBUG_MODE jump_index');
		}
		this.expected_bool = breakIfNotBool(args?.expected_bool, 'CHECK_DEBUG_MODE expected_bool');
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

const breakIfNotStringOrStringArray = (v: unknown, label: string): string | string[] => {
	if (typeof v === 'string') return v;
	if (Array.isArray(v) && v.every((v) => typeof v === 'string')) return v;
	throw new Error(label + ' not a string or a strng array');
};
export const breakIfNotString = (v: unknown, label: string): string => {
	if (typeof v === 'string') return v;
	throw new Error(label + ' not a string');
};
const breakIfNotStringOrNumber = (v: unknown, label: string): string | number => {
	if (typeof v === 'string') return v;
	if (typeof v === 'number') return v;
	throw new Error(label + ' not a string or number');
};
const breakIfNotNumber = (v: unknown, label: string): number => {
	if (typeof v === 'number') return v;
	throw new Error(label + ' not a number');
};
const breakIfNotBool = (v: unknown, label: string): boolean => {
	if (typeof v === 'boolean') return v;
	throw new Error(label + ' not a boolean');
};

const constructorLookup = {
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

export const standardizeAction = (v: unknown) => {
	if (typeof v !== 'object' || v === null || v === undefined) {
		throw new Error('cannot create action from ' + typeof v);
	}
	const actionName = String((v as Action).action); // todo: best practices?
	if (typeof actionName === 'string' && constructorLookup[actionName]) {
		return constructorLookup[actionName](v);
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
			script: breakIfNotString(action.script, 'script'),
		});
		return manual;
	}
	if (action instanceof LabelDefinition) {
		const value = breakIfNotString(action.label, 'label');
		return new LABEL({ value });
	}
	if (action instanceof GotoLabel) {
		const ret = new GOTO_ACTION_INDEX({
			action_index: breakIfNotString(action.label, 'label'),
		});
		return ret;
	}
	if (action instanceof ReturnStatement) {
		const ret = new GOTO_ACTION_INDEX({
			action_index: OOB,
		});
		return ret;
	}
	const actionName = breakIfNotString(action.action, 'actionName');
	Object.keys(action).forEach((field: string) => {
		if (!isFieldForAction(field, actionName) && field !== 'action') {
			delete action[field];
		}
	});
	if (constructorLookup[actionName]) {
		return constructorLookup[actionName](action);
	}
	return action;
};
