const JUMP_SPECIAL = [ 'success_script', 'label', 'jump_index' ];

const actionFields = {
	NULL_ACTION: [],
	CHECK_ENTITY_NAME: [
		'JUMP_SPECIAL',
		'string',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_X: [
		'JUMP_SPECIAL',
		'expected_u2',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_Y: [
		'JUMP_SPECIAL',
		'expected_u2',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_INTERACT_SCRIPT: [
		'JUMP_SPECIAL',
		'expected_script',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_TICK_SCRIPT: [
		'JUMP_SPECIAL',
		'expected_script',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_LOOK_SCRIPT: [
		'JUMP_SPECIAL',
		'expected_script',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_TYPE: [
		'JUMP_SPECIAL',
		'entity_type',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_PRIMARY_ID: [
		'JUMP_SPECIAL',
		'expected_u2',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_SECONDARY_ID: [
		'JUMP_SPECIAL',
		'expected_u2',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_PRIMARY_ID_TYPE: [
		'JUMP_SPECIAL',
		'entity',
		'expected_byte',
		'expected_bool',
	],
	CHECK_ENTITY_CURRENT_ANIMATION: [
		'JUMP_SPECIAL',
		'entity',
		'expected_byte',
		'expected_bool',
	],
	CHECK_ENTITY_CURRENT_FRAME: [
		'JUMP_SPECIAL',
		'entity',
		'expected_byte',
		'expected_bool',
	],
	CHECK_ENTITY_DIRECTION: [
		'JUMP_SPECIAL',
		'entity',
		'direction',
		'expected_bool',
	],
	CHECK_ENTITY_GLITCHED: [
		'JUMP_SPECIAL',
		'entity',
		'expected_bool',
	],
	CHECK_ENTITY_PATH: [
		'JUMP_SPECIAL',
		'geometry',
		'entity',
		'expected_bool',
	],
	CHECK_SAVE_FLAG: [
		'JUMP_SPECIAL',
		'save_flag',
		'expected_bool',
	],
	CHECK_IF_ENTITY_IS_IN_GEOMETRY: [
		'JUMP_SPECIAL',
		'geometry',
		'entity',
		'expected_bool',
	],
	CHECK_FOR_BUTTON_PRESS: [
		'JUMP_SPECIAL',
		'button_id',
		'expected_bool',
	],
	CHECK_FOR_BUTTON_STATE: [
		'JUMP_SPECIAL',
		'button_id',
		'expected_bool',
	],
	CHECK_WARP_STATE: [
		'JUMP_SPECIAL',
		'string',
		'expected_bool',
	],
	RUN_SCRIPT: [
		'script',
	],
	BLOCKING_DELAY: [
		'duration',
	],
	NON_BLOCKING_DELAY: [
		'duration',
	],
	SET_ENTITY_NAME: [
		'string',
		'entity',
	],
	SET_ENTITY_X: [
		'u2_value',
		'entity',
	],
	SET_ENTITY_Y: [
		'u2_value',
		'entity',
	],
	SET_ENTITY_INTERACT_SCRIPT: [
		'script',
		'entity',
	],
	SET_ENTITY_TICK_SCRIPT: [
		'script',
		'entity',
	],
	SET_ENTITY_TYPE: [
		'entity_type',
		'entity',
	],
	SET_ENTITY_PRIMARY_ID: [
		'u2_value',
		'entity',
	],
	SET_ENTITY_SECONDARY_ID: [
		'u2_value',
		'entity',
	],
	SET_ENTITY_PRIMARY_ID_TYPE: [
		'byte_value',
		'entity',
	],
	SET_ENTITY_CURRENT_ANIMATION: [
		'byte_value',
		'entity',
	],
	SET_ENTITY_CURRENT_FRAME: [
		'byte_value',
		'entity',
	],
	SET_ENTITY_DIRECTION: [
		'direction',
		'entity',
	],
	SET_ENTITY_DIRECTION_RELATIVE: [
		'relative_direction',
		'entity',
	],
	SET_ENTITY_DIRECTION_TARGET_ENTITY: [
		'target_entity',
		'entity',
	],
	SET_ENTITY_DIRECTION_TARGET_GEOMETRY: [
		'target_geometry',
		'entity',
	],
	SET_ENTITY_GLITCHED: [
		'entity',
		'bool_value',
	],
	SET_ENTITY_PATH: [
		'geometry',
		'entity',
	],
	SET_SAVE_FLAG: [
		'save_flag',
		'bool_value',
	],
	SET_PLAYER_CONTROL: [
		'bool_value',
	],
	SET_MAP_TICK_SCRIPT: [
		'script',
	],
	SET_HEX_CURSOR_LOCATION: [
		'address',
	],
	SET_WARP_STATE: [
		{propertyName: 'string', size: 2}
	],
	SET_HEX_EDITOR_STATE: [
		'bool_value',
	],
	SET_HEX_EDITOR_DIALOG_MODE: [
		'bool_value',
	],
	SET_HEX_EDITOR_CONTROL: [
		'bool_value',
	],
	SET_HEX_EDITOR_CONTROL_CLIPBOARD: [
		'bool_value',
	],
	LOAD_MAP: [
		'map',
	],
	SHOW_DIALOG: [
		'dialog',
	],
	PLAY_ENTITY_ANIMATION: [
		'entity',
		'animation',
		'play_count',
	],
	TELEPORT_ENTITY_TO_GEOMETRY: [
		'geometry',
		'entity',
	],
	WALK_ENTITY_TO_GEOMETRY: [
		'duration',
		'geometry',
		'entity',
	],
	WALK_ENTITY_ALONG_GEOMETRY: [
		'duration',
		'geometry',
		'entity',
	],
	LOOP_ENTITY_ALONG_GEOMETRY: [
		'duration',
		'geometry',
		'entity',
	],
	SET_CAMERA_TO_FOLLOW_ENTITY: [
		'entity',
	],
	TELEPORT_CAMERA_TO_GEOMETRY: [
		'geometry',
	],
	PAN_CAMERA_TO_ENTITY: [
		'duration',
		'entity',
	],
	PAN_CAMERA_TO_GEOMETRY: [
		'duration',
		'geometry',
	],
	PAN_CAMERA_ALONG_GEOMETRY: [
		'duration',
		'geometry',
		'entity',
	],
	LOOP_CAMERA_ALONG_GEOMETRY: [
		'duration',
		'geometry',
		'entity',
	],
	SET_SCREEN_SHAKE: [
		'duration',
		'frequency',
		'amplitude',
	],
	SCREEN_FADE_OUT: [
		'duration',
		'color',
	],
	SCREEN_FADE_IN: [
		'duration',
		'color',
	],
	MUTATE_VARIABLE: [
		'value',
		'variable',
		'operation',
	],
	MUTATE_VARIABLES: [
		'variable',
		'source',
		'operation',
	],
	COPY_VARIABLE: [
		'variable',
		'entity',
		'field',
		'inbound',
	],
	CHECK_VARIABLE: [
		'JUMP_SPECIAL',
		'value',
		'variable',
		'comparison',
		'expected_bool',
	],
	CHECK_VARIABLES: [
		'JUMP_SPECIAL',
		'variable',
		'source',
		'comparison',
		'expected_bool',
	],
	SLOT_SAVE: [],
	SLOT_LOAD: [
		'slot',
	],
	SLOT_ERASE: [
		'slot',
	],
	SET_CONNECT_SERIAL_DIALOG: [
		'serial_dialog',
	],
	SHOW_SERIAL_DIALOG: [
		'serial_dialog',
		'disable_newline',
	],
	SET_MAP_LOOK_SCRIPT: [
		'script',
	],
	SET_ENTITY_LOOK_SCRIPT: [
		'script',
		'entity',
	],
	SET_TELEPORT_ENABLED: [
		'bool_value',
	],
	CHECK_MAP: [
		'JUMP_SPECIAL',
		'map',
		'expected_bool',
	],
	SET_BLE_FLAG: [
		'ble_flag',
		'bool_value',
	],
	CHECK_BLE_FLAG: [
		'JUMP_SPECIAL',
		'ble_flag',
		'expected_bool',
	],
	SET_SERIAL_DIALOG_CONTROL: [
		'bool_value',
	],
	REGISTER_SERIAL_DIALOG_COMMAND: [
		'command',
		'script',
		'is_fail',
	],
	REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: [
		'command',
		'argument',
		'script',
	],
	UNREGISTER_SERIAL_DIALOG_COMMAND: [
		'command',
		'is_fail',
	],
	UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: [
		'command',
		'argument',
	],
	SET_ENTITY_MOVEMENT_RELATIVE: [
		'relative_direction',
		'entity',
	],
	CHECK_DIALOG_OPEN: [
		'JUMP_SPECIAL',
		'expected_bool',
	],
	CHECK_SERIAL_DIALOG_OPEN: [
		'JUMP_SPECIAL',
		'expected_bool',
	],
	CHECK_DEBUG_MODE: [
		'JUMP_SPECIAL',
		'expected_bool',
	],
	CLOSE_DIALOG: [],
	CLOSE_SERIAL_DIALOG: [],
	SET_LIGHTS_CONTROL: [
		'enabled',
	],
	SET_LIGHTS_STATE: [
		'lights',
		'enabled',
	],
	GOTO_ACTION_INDEX: [
		'action_index',
	],
	SET_SCRIPT_PAUSE: [
		'entity',
		'script_slot',
		'bool_value',
	],
	REGISTER_SERIAL_DIALOG_COMMAND_ALIAS: [
		'command',
		'alias',
	],
	UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS: [
		'alias',
	],
	SET_SERIAL_DIALOG_COMMAND_VISIBILITY: [
		'command',
		'is_visible',
	],
};

const isFieldForAction = (field, action) => {
	const fields = actionFields[action];
	if (fields.includes(field)) return true;
	if (fields.includes('JUMP_SPECIAL')) {
		return JUMP_SPECIAL.includes(field);
	}
}
const getBoolFieldForAction = (action) => {
	const fields = actionFields[action];
	if (fields.includes('bool_value')) return 'bool_value';
	if (fields.includes('expected_bool')) return 'expected_bool';
	if (fields.includes('enabled')) return 'enabled';
	const filtered = fields.filter(s=>s.includes('bool'));
	if (filtered.length === 1) return filtered[0];
	if (filtered.length === 0) return null;
	throw new Error ("multiple possible bool params: " + filtered.join(', '));
}

module.exports = {
	actionFields,
	isFieldForAction,
	getBoolFieldForAction,
}