import { Node } from 'web-tree-sitter';
import { isNodeAction, type AnyNode } from './parser-types.ts';

// For intermediate data types and MGS-specific nodes
export type MGSDebug = {
	node: Node;
	data?: Record<string, unknown>;
	fileName?: string;
	comment?: string;
};

// ---------------------------------- ACTUAL BYTECODE JSON ---------------------------------- \\

// Todo: might not need the "debug" stuff; if actual action, errors would be reported at generation.
// No need to keep tree sitter nodes around, perhaps?

export type NULL_ACTION = {
	action: 'NULL_ACTION';
	debug?: MGSDebug;
};
export type LABEL = {
	action: 'LABEL';
	value: string;
	debug?: MGSDebug;
};
export type RUN_SCRIPT = {
	action: 'RUN_SCRIPT';
	script: string;
	debug?: MGSDebug;
};
export type COPY_SCRIPT = {
	action: 'COPY_SCRIPT';
	script: string;
	search_and_replace?: Record<string, string>;
	debug?: MGSDebug;
};
export const isActionCopyScript = (node: AnyNode): node is COPY_SCRIPT => {
	return (node as Action).action === 'COPY_SCRIPT';
};

export type BLOCKING_DELAY = {
	action: 'BLOCKING_DELAY';
	duration: number;
	debug?: MGSDebug;
};
export type NON_BLOCKING_DELAY = {
	action: 'NON_BLOCKING_DELAY';
	duration: number;
	debug?: MGSDebug;
};
export type SET_ENTITY_NAME = {
	action: 'SET_ENTITY_NAME';
	entity: string;
	string: string;
	debug?: MGSDebug;
};
export type SET_ENTITY_X = {
	action: 'SET_ENTITY_X';
	entity: string;
	u2_value: number;
	debug?: MGSDebug;
};
export type SET_ENTITY_Y = {
	action: 'SET_ENTITY_Y';
	entity: string;
	u2_value: number;
	debug?: MGSDebug;
};
export type SET_ENTITY_INTERACT_SCRIPT = {
	action: 'SET_ENTITY_INTERACT_SCRIPT';
	entity: string;
	script: string;
	debug?: MGSDebug;
};
export type SET_ENTITY_TICK_SCRIPT = {
	action: 'SET_ENTITY_TICK_SCRIPT';
	entity: string;
	script: string;
	debug?: MGSDebug;
};
export type SET_ENTITY_TYPE = {
	action: 'SET_ENTITY_TYPE';
	entity: string;
	entity_type: string;
	debug?: MGSDebug;
};
export type SET_ENTITY_PRIMARY_ID = {
	action: 'SET_ENTITY_PRIMARY_ID';
	entity: string;
	u2_value: number;
	debug?: MGSDebug;
};
export type SET_ENTITY_SECONDARY_ID = {
	action: 'SET_ENTITY_SECONDARY_ID';
	entity: string;
	u2_value: number;
	debug?: MGSDebug;
};
export type SET_ENTITY_PRIMARY_ID_TYPE = {
	action: 'SET_ENTITY_PRIMARY_ID_TYPE';
	entity: string;
	byte_value: number;
	debug?: MGSDebug;
};
export type SET_ENTITY_CURRENT_ANIMATION = {
	action: 'SET_ENTITY_CURRENT_ANIMATION';
	entity: string;
	byte_value: number;
	debug?: MGSDebug;
};
export type SET_ENTITY_CURRENT_FRAME = {
	action: 'SET_ENTITY_CURRENT_FRAME';
	entity: string;
	byte_value: number;
	debug?: MGSDebug;
};
export type SET_ENTITY_DIRECTION = {
	action: 'SET_ENTITY_DIRECTION';
	entity: string;
	direction: string;
	debug?: MGSDebug;
};
export type SET_ENTITY_DIRECTION_RELATIVE = {
	action: 'SET_ENTITY_DIRECTION_RELATIVE';
	entity: string;
	relative_direction: number;
	debug?: MGSDebug;
};
export type SET_ENTITY_DIRECTION_TARGET_ENTITY = {
	action: 'SET_ENTITY_DIRECTION_TARGET_ENTITY';
	entity: string;
	target_entity: string;
	debug?: MGSDebug;
};
export type SET_ENTITY_DIRECTION_TARGET_GEOMETRY = {
	action: 'SET_ENTITY_DIRECTION_TARGET_GEOMETRY';
	entity: string;
	target_geometry: string;
	debug?: MGSDebug;
};
export type SET_ENTITY_GLITCHED = {
	action: 'SET_ENTITY_GLITCHED';
	entity: string;
	bool_value: boolean;
	debug?: MGSDebug;
};
export type SET_ENTITY_PATH = {
	action: 'SET_ENTITY_PATH';
	entity: string;
	geometry: string;
	debug?: MGSDebug;
};
export type SET_SAVE_FLAG = {
	action: 'SET_SAVE_FLAG';
	save_flag: string;
	bool_value: boolean;
	debug?: MGSDebug;
};
export type SET_PLAYER_CONTROL = {
	action: 'SET_PLAYER_CONTROL';
	bool_value: boolean;
	debug?: MGSDebug;
};
export type SET_MAP_TICK_SCRIPT = {
	action: 'SET_MAP_TICK_SCRIPT';
	script: string;
	debug?: MGSDebug;
};
export type SET_HEX_CURSOR_LOCATION = {
	action: 'SET_HEX_CURSOR_LOCATION';
	address: number;
	debug?: MGSDebug;
};
export type SET_WARP_STATE = {
	action: 'SET_WARP_STATE';
	string: string;
	debug?: MGSDebug;
};
export type SET_HEX_EDITOR_STATE = {
	action: 'SET_HEX_EDITOR_STATE';
	bool_value: boolean;
	debug?: MGSDebug;
};
export type SET_HEX_EDITOR_DIALOG_MODE = {
	action: 'SET_HEX_EDITOR_DIALOG_MODE';
	bool_value: boolean;
	debug?: MGSDebug;
};
export type SET_HEX_EDITOR_CONTROL = {
	action: 'SET_HEX_EDITOR_CONTROL';
	bool_value: boolean;
	debug?: MGSDebug;
};
export type SET_HEX_EDITOR_CONTROL_CLIPBOARD = {
	action: 'SET_HEX_EDITOR_CONTROL_CLIPBOARD';
	bool_value: boolean;
	debug?: MGSDebug;
};
export type LOAD_MAP = {
	action: 'LOAD_MAP';
	map: string;
	debug?: MGSDebug;
};
export type SHOW_DIALOG = {
	action: 'SHOW_DIALOG';
	dialog: string;
	debug?: MGSDebug;
};
export type PLAY_ENTITY_ANIMATION = {
	action: 'PLAY_ENTITY_ANIMATION';
	entity: string;
	animation: number;
	play_count: number;
	debug?: MGSDebug;
};
export type TELEPORT_ENTITY_TO_GEOMETRY = {
	action: 'TELEPORT_ENTITY_TO_GEOMETRY';
	geometry: string;
	entity: string;
	debug?: MGSDebug;
};
export type WALK_ENTITY_TO_GEOMETRY = {
	action: 'WALK_ENTITY_TO_GEOMETRY';
	geometry: string;
	entity: string;
	duration: number;
	debug?: MGSDebug;
};
export type WALK_ENTITY_ALONG_GEOMETRY = {
	action: 'WALK_ENTITY_ALONG_GEOMETRY';
	geometry: string;
	entity: string;
	duration: number;
	debug?: MGSDebug;
};
export type LOOP_ENTITY_ALONG_GEOMETRY = {
	action: 'LOOP_ENTITY_ALONG_GEOMETRY';
	geometry: string;
	entity: string;
	duration: number;
	debug?: MGSDebug;
};
export type SET_CAMERA_TO_FOLLOW_ENTITY = {
	action: 'SET_CAMERA_TO_FOLLOW_ENTITY';
	entity: string;
	debug?: MGSDebug;
};
export type TELEPORT_CAMERA_TO_GEOMETRY = {
	action: 'TELEPORT_CAMERA_TO_GEOMETRY';
	geometry: string;
	debug?: MGSDebug;
};
export type PAN_CAMERA_TO_ENTITY = {
	action: 'PAN_CAMERA_TO_ENTITY';
	entity: string;
	duration: number;
	debug?: MGSDebug;
};
export type PAN_CAMERA_TO_GEOMETRY = {
	action: 'PAN_CAMERA_TO_GEOMETRY';
	geometry: string;
	duration: number;
	debug?: MGSDebug;
};
export type PAN_CAMERA_ALONG_GEOMETRY = {
	action: 'PAN_CAMERA_ALONG_GEOMETRY';
	entity: string; // ?? really?
	geometry: string;
	duration: number;
	debug?: MGSDebug;
};
export type LOOP_CAMERA_ALONG_GEOMETRY = {
	action: 'LOOP_CAMERA_ALONG_GEOMETRY';
	entity: string; // ?? really?
	geometry: string;
	duration: number;
	debug?: MGSDebug;
};
export type SET_SCREEN_SHAKE = {
	action: 'SET_SCREEN_SHAKE';
	duration: number;
	frequency: number;
	amplitude: number;
	debug?: MGSDebug;
};
export type SCREEN_FADE_OUT = {
	action: 'SCREEN_FADE_OUT';
	duration: number;
	color: string;
	debug?: MGSDebug;
};
export type SCREEN_FADE_IN = {
	action: 'SCREEN_FADE_IN';
	duration: number;
	color: string;
	debug?: MGSDebug;
};
export type MUTATE_VARIABLE = {
	action: 'MUTATE_VARIABLE';
	variable: string;
	operation: string;
	value: number;
	debug?: MGSDebug;
};
export type MUTATE_VARIABLES = {
	action: 'MUTATE_VARIABLES';
	variable: string;
	operation: string;
	source: string;
	debug?: MGSDebug;
};
export type COPY_VARIABLE = {
	action: 'COPY_VARIABLE';
	variable: string;
	entity: string;
	field: string;
	inbound: boolean;
	debug?: MGSDebug;
};
export type SLOT_SAVE = {
	action: 'SLOT_SAVE';
	debug?: MGSDebug;
};
export type SLOT_LOAD = {
	action: 'SLOT_LOAD';
	slot: number;
	debug?: MGSDebug;
};
export type SLOT_ERASE = {
	action: 'SLOT_ERASE';
	slot: number;
	debug?: MGSDebug;
};
export type SET_CONNECT_SERIAL_DIALOG = {
	action: 'SET_CONNECT_SERIAL_DIALOG';
	serial_dialog: string;
	debug?: MGSDebug;
};
export type SHOW_SERIAL_DIALOG = {
	action: 'SHOW_SERIAL_DIALOG';
	serial_dialog: string;
	disable_newline?: boolean; // might be absent on old stuff
	debug?: MGSDebug;
};
export type SET_MAP_LOOK_SCRIPT = {
	action: 'SET_MAP_LOOK_SCRIPT';
	script: string;
	debug?: MGSDebug;
};
export type SET_ENTITY_LOOK_SCRIPT = {
	action: 'SET_ENTITY_LOOK_SCRIPT';
	script: string;
	entity: string;
	debug?: MGSDebug;
};
export type SET_TELEPORT_ENABLED = {
	action: 'SET_TELEPORT_ENABLED';
	bool_value: boolean;
	debug?: MGSDebug;
};
export type SET_BLE_FLAG = {
	action: 'SET_BLE_FLAG';
	ble_flag: string | boolean; // idk what this is lol
	bool_value: boolean;
	debug?: MGSDebug;
};
export type SET_SERIAL_DIALOG_CONTROL = {
	action: 'SET_SERIAL_DIALOG_CONTROL';
	bool_value: boolean;
	debug?: MGSDebug;
};
export type REGISTER_SERIAL_DIALOG_COMMAND = {
	action: 'REGISTER_SERIAL_DIALOG_COMMAND';
	command: string;
	script: string;
	is_fail?: boolean;
	debug?: MGSDebug;
};
export type REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT = {
	action: 'REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
	command: string;
	script: string;
	argument: string;
	debug?: MGSDebug;
};
export type UNREGISTER_SERIAL_DIALOG_COMMAND = {
	action: 'UNREGISTER_SERIAL_DIALOG_COMMAND';
	command: string;
	is_fail?: boolean;
	debug?: MGSDebug;
};
export type UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT = {
	action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT';
	command: string;
	argument: string;
	debug?: MGSDebug;
};
export type SET_ENTITY_MOVEMENT_RELATIVE = {
	action: 'SET_ENTITY_MOVEMENT_RELATIVE';
	relative_direction: number;
	entity: string;
	debug?: MGSDebug;
};
export type CLOSE_DIALOG = {
	action: 'CLOSE_DIALOG';
	debug?: MGSDebug;
};
export type CLOSE_SERIAL_DIALOG = {
	action: 'CLOSE_SERIAL_DIALOG';
	debug?: MGSDebug;
};
export type SET_LIGHTS_CONTROL = {
	action: 'SET_LIGHTS_CONTROL';
	enabled: boolean;
	debug?: MGSDebug;
};
export type SET_LIGHTS_STATE = {
	action: 'SET_LIGHTS_STATE';
	lights: string | string[];
	enabled: boolean;
	debug?: MGSDebug;
};
export type GOTO_ACTION_INDEX = {
	action: 'GOTO_ACTION_INDEX';
	action_index: number | string;
	debug?: MGSDebug;
};
export type SET_SCRIPT_PAUSE = {
	action: 'SET_SCRIPT_PAUSE';
	entity: string;
	script_slot: string;
	bool_value: boolean;
	debug?: MGSDebug;
};
export type REGISTER_SERIAL_DIALOG_COMMAND_ALIAS = {
	action: 'REGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
	command: string;
	alias: string;
	debug?: MGSDebug;
};
export type UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS = {
	action: 'UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS';
	alias: string;
	debug?: MGSDebug;
};
export type SET_SERIAL_DIALOG_COMMAND_VISIBILITY = {
	action: 'SET_SERIAL_DIALOG_COMMAND_VISIBILITY';
	command: string;
	is_visible: boolean;
	debug?: MGSDebug;
};

// CHECK_ACTIONS

export type CHECK_ENTITY_NAME = {
	action: 'CHECK_ENTITY_NAME';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	string: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_X = {
	action: 'CHECK_ENTITY_X';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_u2: number;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_Y = {
	action: 'CHECK_ENTITY_Y';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_u2: number;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_INTERACT_SCRIPT = {
	action: 'CHECK_ENTITY_INTERACT_SCRIPT';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_script: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_TICK_SCRIPT = {
	action: 'CHECK_ENTITY_TICK_SCRIPT';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_script: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_LOOK_SCRIPT = {
	action: 'CHECK_ENTITY_LOOK_SCRIPT';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_script: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_TYPE = {
	action: 'CHECK_ENTITY_TYPE';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	entity_type: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_PRIMARY_ID = {
	action: 'CHECK_ENTITY_PRIMARY_ID';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_u2: number;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_SECONDARY_ID = {
	action: 'CHECK_ENTITY_SECONDARY_ID';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_u2: number;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_PRIMARY_ID_TYPE = {
	action: 'CHECK_ENTITY_PRIMARY_ID_TYPE';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_byte: number;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_CURRENT_ANIMATION = {
	action: 'CHECK_ENTITY_CURRENT_ANIMATION';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_byte: number;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_CURRENT_FRAME = {
	action: 'CHECK_ENTITY_CURRENT_FRAME';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_byte: number;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_DIRECTION = {
	action: 'CHECK_ENTITY_DIRECTION';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	direction: string; // north, south, east, west
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_GLITCHED = {
	action: 'CHECK_ENTITY_GLITCHED';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	entity: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_ENTITY_PATH = {
	action: 'CHECK_ENTITY_PATH';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	geometry: string;
	entity: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_SAVE_FLAG = {
	mathlang?: 'bool_getable' | 'if_branch_goto_label'; // TODO: what
	action: 'CHECK_SAVE_FLAG';
	success_script?: string;
	label?: string;
	value?: string;
	jump_index?: number | string;
	save_flag: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_IF_ENTITY_IS_IN_GEOMETRY = {
	action: 'CHECK_IF_ENTITY_IS_IN_GEOMETRY';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	geometry: string;
	entity: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_FOR_BUTTON_PRESS = {
	action: 'CHECK_FOR_BUTTON_PRESS';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	button_id: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_FOR_BUTTON_STATE = {
	action: 'CHECK_FOR_BUTTON_STATE';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	button_id: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_WARP_STATE = {
	action: 'CHECK_WARP_STATE';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	string: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_VARIABLE = {
	action: 'CHECK_VARIABLE';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	variable: string;
	comparison: string;
	value: number;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_VARIABLES = {
	action: 'CHECK_VARIABLES';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	variable: string;
	comparison: string;
	source: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_MAP = {
	// TODO: is this even in the engine? O.o
	action: 'CHECK_MAP';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	map: string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_BLE_FLAG = {
	action: 'CHECK_BLE_FLAG';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	ble_flag: string | boolean; // idk what this is lol
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_DIALOG_OPEN = {
	action: 'CHECK_DIALOG_OPEN';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_SERIAL_DIALOG_OPEN = {
	action: 'CHECK_SERIAL_DIALOG_OPEN';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CHECK_DEBUG_MODE = {
	action: 'CHECK_DEBUG_MODE';
	success_script?: string;
	label?: string;
	jump_index?: number | string;
	expected_bool: boolean;
	debug?: MGSDebug;
};
export type CheckAction =
	| CHECK_ENTITY_NAME
	| CHECK_ENTITY_X
	| CHECK_ENTITY_Y
	| CHECK_ENTITY_INTERACT_SCRIPT
	| CHECK_ENTITY_TICK_SCRIPT
	| CHECK_ENTITY_LOOK_SCRIPT
	| CHECK_ENTITY_TYPE
	| CHECK_ENTITY_PRIMARY_ID
	| CHECK_ENTITY_SECONDARY_ID
	| CHECK_ENTITY_PRIMARY_ID_TYPE
	| CHECK_ENTITY_CURRENT_ANIMATION
	| CHECK_ENTITY_CURRENT_FRAME
	| CHECK_ENTITY_DIRECTION
	| CHECK_ENTITY_GLITCHED
	| CHECK_ENTITY_PATH
	| CHECK_SAVE_FLAG
	| CHECK_IF_ENTITY_IS_IN_GEOMETRY
	| CHECK_FOR_BUTTON_PRESS
	| CHECK_FOR_BUTTON_STATE
	| CHECK_WARP_STATE
	| CHECK_VARIABLE
	| CHECK_VARIABLES
	| CHECK_MAP
	| CHECK_BLE_FLAG
	| CHECK_DIALOG_OPEN
	| CHECK_SERIAL_DIALOG_OPEN
	| CHECK_DEBUG_MODE;
export const isCheckAction = (node: AnyNode): node is CheckAction => {
	if (!isNodeAction(node)) return false;
	if (node.action === 'CHECK_ENTITY_NAME') return true;
	if (node.action === 'CHECK_ENTITY_X') return true;
	if (node.action === 'CHECK_ENTITY_Y') return true;
	if (node.action === 'CHECK_ENTITY_INTERACT_SCRIPT') return true;
	if (node.action === 'CHECK_ENTITY_TICK_SCRIPT') return true;
	if (node.action === 'CHECK_ENTITY_LOOK_SCRIPT') return true;
	if (node.action === 'CHECK_ENTITY_TYPE') return true;
	if (node.action === 'CHECK_ENTITY_PRIMARY_ID') return true;
	if (node.action === 'CHECK_ENTITY_SECONDARY_ID') return true;
	if (node.action === 'CHECK_ENTITY_PRIMARY_ID_TYPE') return true;
	if (node.action === 'CHECK_ENTITY_CURRENT_ANIMATION') return true;
	if (node.action === 'CHECK_ENTITY_CURRENT_FRAME') return true;
	if (node.action === 'CHECK_ENTITY_DIRECTION') return true;
	if (node.action === 'CHECK_ENTITY_GLITCHED') return true;
	if (node.action === 'CHECK_ENTITY_PATH') return true;
	if (node.action === 'CHECK_SAVE_FLAG') return true;
	if (node.action === 'CHECK_IF_ENTITY_IS_IN_GEOMETRY') return true;
	if (node.action === 'CHECK_FOR_BUTTON_PRESS') return true;
	if (node.action === 'CHECK_FOR_BUTTON_STATE') return true;
	if (node.action === 'CHECK_WARP_STATE') return true;
	if (node.action === 'CHECK_VARIABLE') return true;
	if (node.action === 'CHECK_VARIABLES') return true;
	if (node.action === 'CHECK_MAP') return true;
	if (node.action === 'CHECK_BLE_FLAG') return true;
	if (node.action === 'CHECK_DIALOG_OPEN') return true;
	if (node.action === 'CHECK_SERIAL_DIALOG_OPEN') return true;
	if (node.action === 'CHECK_DEBUG_MODE') return true;
	return false;
};

// Super union type
export type Action =
	| CheckAction
	| NULL_ACTION
	| LABEL
	| RUN_SCRIPT
	| COPY_SCRIPT
	| BLOCKING_DELAY
	| NON_BLOCKING_DELAY
	| SET_ENTITY_NAME
	| SET_ENTITY_X
	| SET_ENTITY_Y
	| SET_ENTITY_INTERACT_SCRIPT
	| SET_ENTITY_TICK_SCRIPT
	| SET_ENTITY_TYPE
	| SET_ENTITY_PRIMARY_ID
	| SET_ENTITY_SECONDARY_ID
	| SET_ENTITY_PRIMARY_ID_TYPE
	| SET_ENTITY_CURRENT_ANIMATION
	| SET_ENTITY_CURRENT_FRAME
	| SET_ENTITY_DIRECTION
	| SET_ENTITY_DIRECTION_RELATIVE
	| SET_ENTITY_DIRECTION_TARGET_ENTITY
	| SET_ENTITY_DIRECTION_TARGET_GEOMETRY
	| SET_ENTITY_GLITCHED
	| SET_ENTITY_PATH
	| SET_SAVE_FLAG
	| SET_PLAYER_CONTROL
	| SET_MAP_TICK_SCRIPT
	| SET_HEX_CURSOR_LOCATION
	| SET_WARP_STATE
	| SET_HEX_EDITOR_STATE
	| SET_HEX_EDITOR_DIALOG_MODE
	| SET_HEX_EDITOR_CONTROL
	| SET_HEX_EDITOR_CONTROL_CLIPBOARD
	| LOAD_MAP
	| SHOW_DIALOG
	| PLAY_ENTITY_ANIMATION
	| TELEPORT_ENTITY_TO_GEOMETRY
	| WALK_ENTITY_TO_GEOMETRY
	| WALK_ENTITY_ALONG_GEOMETRY
	| LOOP_ENTITY_ALONG_GEOMETRY
	| SET_CAMERA_TO_FOLLOW_ENTITY
	| TELEPORT_CAMERA_TO_GEOMETRY
	| PAN_CAMERA_TO_ENTITY
	| PAN_CAMERA_TO_GEOMETRY
	| PAN_CAMERA_ALONG_GEOMETRY
	| LOOP_CAMERA_ALONG_GEOMETRY
	| SET_SCREEN_SHAKE
	| SCREEN_FADE_OUT
	| SCREEN_FADE_IN
	| MUTATE_VARIABLE
	| MUTATE_VARIABLES
	| COPY_VARIABLE
	| SLOT_SAVE
	| SLOT_LOAD
	| SLOT_ERASE
	| SET_CONNECT_SERIAL_DIALOG
	| SHOW_SERIAL_DIALOG
	| SET_MAP_LOOK_SCRIPT
	| SET_ENTITY_LOOK_SCRIPT
	| SET_TELEPORT_ENABLED
	| SET_BLE_FLAG
	| SET_SERIAL_DIALOG_CONTROL
	| REGISTER_SERIAL_DIALOG_COMMAND
	| REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
	| UNREGISTER_SERIAL_DIALOG_COMMAND
	| UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
	| SET_ENTITY_MOVEMENT_RELATIVE
	| CLOSE_DIALOG
	| CLOSE_SERIAL_DIALOG
	| SET_LIGHTS_CONTROL
	| SET_LIGHTS_STATE
	| GOTO_ACTION_INDEX
	| SET_SCRIPT_PAUSE
	| REGISTER_SERIAL_DIALOG_COMMAND_ALIAS
	| UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS
	| SET_SERIAL_DIALOG_COMMAND_VISIBILITY;

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
	COPY_SCRIPT: ['script'],
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
export const getBoolFieldForAction = (action: string): string | null => {
	const fields = actionFields[action];
	if (fields.includes('bool_value')) return 'bool_value';
	if (fields.includes('expected_bool')) return 'expected_bool';
	if (fields.includes('enabled')) return 'enabled';
	const filtered = fields.filter((s: string) => s.includes('bool'));
	if (filtered.length === 1) return filtered[0];
	if (filtered.length === 0) return null;
	throw new Error('multiple possible bool params: ' + filtered.join(', '));
};

// Takes the "maybe has too many properties" Mathlang object and strips all nonessential fields
export const standardizeAction = (action: Record<string, unknown>, OOB: number): Action => {
	const ret = {};
	if (action.mathlang === 'copy_script') {
		const manual = {
			action: 'COPY_SCRIPT',
			script: action.script,
		};
		return manual as Action;
	}
	if (action.mathlang === 'label_definition') {
		const copy = {
			action: 'LABEL',
			value: action.label,
		};
		return copy as Action;
	}
	if (action.mathlang === 'goto_label') {
		const copy = {
			action: 'GOTO_ACTION_INDEX',
			action_index: action.label,
		};
		return copy as Action;
	}
	if (action.mathlang === 'return_statement') {
		const copy = {
			action: 'GOTO_ACTION_INDEX',
			action_index: OOB,
		};
		return copy as Action;
	}
	const actionName = action.action;
	if (typeof actionName !== 'string') throw new Error('ts');
	Object.keys(action).forEach((field: string) => {
		if (isFieldForAction(field, actionName)) {
			ret[field] = action[field];
		}
	});
	return action as Action;
};
