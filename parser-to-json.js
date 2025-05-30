const { getBoolFieldForAction } = require('./parser-bytecode-info.js');
const {
	inverseOpMap,
} = require('./parser-utilities.js');
const printAction = (data) => {
	if (data.mathlang === 'comment') {
		return `// ${data.comment}`;
	}
	if (data.action) {
		const fn = printActionFns[data.action];
		if (!fn) throw new Error ('Fn needed for ' + data.action);
		const print = fn(data);
		const comment = data.comment ? ' // ' + data.comment : '';
		return print + comment;
	}
	if (data.mathlang) {
		const fn = mathlang[data.mathlang];
		if (!fn) throw new Error ('Fn needed for ' + data.mathlang);
		const print = fn(data);
		const comment = data.comment ? ' // ' + data.comment : '';
		return print + comment;
	}
	if (data.error) {
		return `// ERROR: ${data.debug.text.replace(/[\t\n\s]+/g, ' ')}`
	}
	throw new Error ('Fn needed for ???')
};

const mathlang = {
	if_branch_goto_label: (data) => `${printGotoSegment(data)};`,
	goto_label: (data) => `${printGotoSegment(data)};`,
	label_definition: (data) => `${sanitizeLabel(data.label)}:`,
};

const printActionFns = {
	// Branch on bool equality (==)
	CHECK_DEBUG_MODE: (v) => printCheckAction(v, 'debug_mode', true),
	CHECK_SERIAL_DIALOG_OPEN: (v) => printCheckAction(v, `serial_dialog ${v.expected_bool ? 'open' : 'closed'}`),
	CHECK_DIALOG_OPEN: (v) => printCheckAction(v, `dialog ${v.expected_bool ? 'open' : 'closed'}`),
	CHECK_SAVE_FLAG: (v) => printCheckAction(v, `"${v.save_flag}"`, true),
	CHECK_FOR_BUTTON_PRESS: (v) => printCheckAction(v, `button ${v.button_id} pressed`, true),
	CHECK_FOR_BUTTON_STATE: (v) => printCheckAction(v, `button ${v.button_id} ${v.expected_bool ? 'down' : 'up'}`),
	CHECK_IF_ENTITY_IS_IN_GEOMETRY: (v) => printCheckAction(v, `${printEntityIdentifier(v.entity)} intersects ${printGeometry(v.geometry)}`, true),
	CHECK_ENTITY_GLITCHED: (v) => printCheckAction(v, `${printEntityIdentifier(v.entity)} glitched`, true),
	
	// Branch on int equality (==)
	CHECK_ENTITY_X: (v) => printEntityFieldEquality(v, 'x', v.expected_u2),
	CHECK_ENTITY_Y: (v) => printEntityFieldEquality(v, 'y', v.expected_u2),
	CHECK_ENTITY_PRIMARY_ID: (v) => printEntityFieldEquality(v, 'primary_id', v.expected_u2),
	CHECK_ENTITY_SECONDARY_ID: (v) => printEntityFieldEquality(v, 'secondary_id', v.expected_u2),
	CHECK_ENTITY_PRIMARY_ID_TYPE: (v) => printEntityFieldEquality(v, 'primary_id_type', v.expected_byte),
	CHECK_ENTITY_CURRENT_ANIMATION: (v) => printEntityFieldEquality(v, 'current_animation', v.expected_byte),
	CHECK_ENTITY_CURRENT_FRAME: (v) => printEntityFieldEquality(v, 'animation_frame', v.expected_byte),
	
	// Branch on int comparison (== < <= => >)
	CHECK_VARIABLE: (v) => {
		const op = v.expected_bool
			? v.comparison
			: inverseOpMap[v.comparison];
		return printCheckAction(v, `"${v.variable}" ${op} ${v.value}`);
	},
	CHECK_VARIABLES: (v) => {
		const op = v.expected_bool
			? v.comparison
			: inverseOpMap[v.comparison];
		return printCheckAction(v, `"${v.variable}" ${op} "${v.source}"`);
	},

	// Branch on string equality (==)
	CHECK_WARP_STATE: (v) => v.expected_bool
		? printCheckAction(v, `warp_state == "${v.string}"`)
		: printCheckAction(v, `warp_state != "${v.string}"`),
	CHECK_ENTITY_NAME: (v) => printEntityFieldEquality(v, 'name', `"${v.string}"`),
	CHECK_ENTITY_TYPE: (v) => printEntityFieldEquality(v, 'type', `"${v.entity_type}"`),
	CHECK_ENTITY_INTERACT_SCRIPT: (v) => printEntityFieldEquality(v, 'on_interact', `"${v.expected_script}"`),
	CHECK_ENTITY_TICK_SCRIPT: (v) => printEntityFieldEquality(v, 'on_tick', `"${v.expected_script}"`),
	CHECK_ENTITY_LOOK_SCRIPT: (v) => printEntityFieldEquality(v, 'on_look', `"${v.expected_script}"`),
	CHECK_ENTITY_DIRECTION: (v) => printEntityFieldEquality(v, 'direction', `"${v.direction}"`),
	CHECK_ENTITY_PATH: (v) => printEntityFieldEquality(v, 'path', `"${v.geometry}"`),

	// Set bool (expressions OK)
	SET_SAVE_FLAG: (v) => printSetBoolAction(v, `"${v.save_flag}"`),
	SET_HEX_EDITOR_STATE: (v) => printSetBoolAction(v, `hex_editor`),
	SET_HEX_EDITOR_DIALOG_MODE: (v) => printSetBoolAction(v, `hex_dialog_mode`),
	SET_HEX_EDITOR_CONTROL: (v) => printSetBoolAction(v, `hex_control`),
	SET_HEX_EDITOR_CONTROL_CLIPBOARD: (v) => printSetBoolAction(v, `hex_clipboard`),
	SET_SERIAL_DIALOG_CONTROL: (v) => printSetBoolAction(v, `serial_control`),
	SET_PLAYER_CONTROL: (v) => printSetBoolAction(v, `player_control`),
	SET_LIGHTS_CONTROL: (v) => printSetBoolAction(v, `lights_control`),
	SET_LIGHTS_STATE: (v) => printSetBoolAction(v, `light ${v.lights}`),
	SET_ENTITY_GLITCHED: (v) => printSetBoolAction(v, `${printEntityIdentifier(v.entity)} glitched`),

	// Set int (expressions OK)
	MUTATE_VARIABLE: (v) => `"${v.variable}" ${stringIntoOpMap[v.operation]}= ${v.value};`,
	MUTATE_VARIABLES: (v) => `"${v.variable}" ${stringIntoOpMap[v.operation]}= "${v.source}";`,
	COPY_VARIABLE: (v) => v.inbound
		? `"${v.variable}" = ${printEntityIdentifier(v.entity)} ${v.field};`
		: `${printEntityIdentifier(v.entity)} ${v.field} = "${v.variable}";`,

	// Set int (expressions not allowed)
	SET_ENTITY_X: (v) => `${printEntityIdentifier(v.entity)} x = ${v.u2_value};`,
	SET_ENTITY_Y: (v) => `${printEntityIdentifier(v.entity)} y = ${v.u2_value};`,
	SET_ENTITY_PRIMARY_ID: (v) => `${printEntityIdentifier(v.entity)} primary_id = ${v.u2_value};`,
	SET_ENTITY_SECONDARY_ID: (v) => `${printEntityIdentifier(v.entity)} secondary_id = ${v.u2_value};`,
	SET_ENTITY_PRIMARY_ID_TYPE: (v) => `${printEntityIdentifier(v.entity)} primary_id_type = ${v.byte_value};`,
	SET_ENTITY_CURRENT_ANIMATION: (v) => `${printEntityIdentifier(v.entity)} current_animation = ${v.byte_value};`,
	SET_ENTITY_CURRENT_FRAME: (v) => `${printEntityIdentifier(v.entity)} animation_frame = ${v.byte_value};`,
	SET_ENTITY_MOVEMENT_RELATIVE: (v) => `${printEntityIdentifier(v.entity)} strafe = ${v.relative_direction};`,
	SET_ENTITY_DIRECTION_RELATIVE: (v) => {
		if (v.relative_direction < 0) {
			return `${printEntityIdentifier(v.entity)} direction -= ${v.relative_direction};`
		} else {
			return `${printEntityIdentifier(v.entity)} direction += ${v.relative_direction};`
		}
	},

	// Set string
	SET_WARP_STATE: (v) => `warp_state = "${v.string}";`,
	SET_ENTITY_NAME: (v) => `${printEntityIdentifier(v.entity)} name = "${v.string}";`,
	SET_ENTITY_TYPE: (v) => `${printEntityIdentifier(v.entity)} type = "${v.entity_type}";`,
	SET_ENTITY_PATH: (v) => `${printEntityIdentifier(v.entity)} path = "${v.geometry}";`,
	SET_ENTITY_DIRECTION: (v) => `${printEntityIdentifier(v.entity)} direction = "${v.direction}";`,
	SET_ENTITY_LOOK_SCRIPT: (v) => `${printEntityIdentifier(v.entity)} on_look = "${v.script}";`,
	SET_ENTITY_INTERACT_SCRIPT: (v) => `${printEntityIdentifier(v.entity)} on_interact = "${v.script}";`,
	SET_ENTITY_TICK_SCRIPT: (v) => `${printEntityIdentifier(v.entity)} on_tick = "${v.script}";`,
	SET_MAP_TICK_SCRIPT: (v) => `map on_tick = "${v.script}";`,

	// Set position
	SET_CAMERA_TO_FOLLOW_ENTITY: (v) => `camera = ${printEntityIdentifier(v.entity)} position;`,
	TELEPORT_CAMERA_TO_GEOMETRY: (v) => `camera = ${printGeometry(v.geometry)};`,
	TELEPORT_ENTITY_TO_GEOMETRY: (v) => `${printEntityIdentifier(v.entity)} position = ${printGeometry(v.geometry)};`,
	SET_ENTITY_DIRECTION_TARGET_ENTITY: (v) => `${printEntityIdentifier(v.entity)} direction = ${printEntityIdentifier(v.target_entity)};`,
	SET_ENTITY_DIRECTION_TARGET_GEOMETRY: (v) => `${printEntityIdentifier(v.entity)} direction = ${printGeometry(v.target_geometry)};`,

	// Set position over time
	WALK_ENTITY_TO_GEOMETRY: (v) => `${printEntityIdentifier(v.entity)} position -> ${printGeometry(v.geometry)} origin over ${printDuration(v.duration)};`,
	WALK_ENTITY_ALONG_GEOMETRY: (v) => `${printEntityIdentifier(v.entity)} position -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)};`,
	LOOP_ENTITY_ALONG_GEOMETRY: (v) => `${printEntityIdentifier(v.entity)} position -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)} forever;`,
	PAN_CAMERA_TO_ENTITY: (v) => `camera -> ${printEntityIdentifier(v.entity)} position over ${printDuration(v.duration)};`,
	PAN_CAMERA_TO_GEOMETRY: (v) => `camera -> ${printGeometry(v.geometry)} origin over ${printDuration(v.duration)};`,
	PAN_CAMERA_ALONG_GEOMETRY: (v) => `camera -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)};`,
	LOOP_CAMERA_ALONG_GEOMETRY: (v) => `camera -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)} forever;`,
	
	// Other do over time
	SET_SCREEN_SHAKE: (v) => `camera shake -> ${v.amplitude}ms ${v.distance}px over ${printDuration(v.duration)};`,
	SCREEN_FADE_IN: (v) => `camera fade in -> ${v.color} over ${printDuration(v.duration)};`,
	SCREEN_FADE_OUT: (v) => `camera fade out -> ${v.color} over ${printDuration(v.duration)};`,
	PLAY_ENTITY_ANIMATION: (v) => `${printEntityIdentifier(v.entity)} animation -> ${v.animation} ${v.count}x;`,

	// Commands and aliases
	REGISTER_SERIAL_DIALOG_COMMAND: (v) => v.is_fail
		? `command "${v.command}" fail = "${v.script}";`
		: `command "${v.command}" = "${v.script}";`,
	UNREGISTER_SERIAL_DIALOG_COMMAND: (v) => `delete command "${v.command}";`,
	REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: (v) => `command "${v.command}" + "${v.argument}" = "${v.script}";`,
	UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: (v) => `delete command "${v.command}" + "${v.argument}";`,
	REGISTER_SERIAL_DIALOG_COMMAND_ALIAS: (v) => `alias "${v.alias}" = "${v.command}";`,
	UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS: (v) => `delete alias "${v.alias}";`,
	SET_SERIAL_DIALOG_COMMAND_VISIBILITY: (v) => `${v.is_visible ? 'un' : ''}hide command "${v.command}";`,

	// Miscellaneous
	SLOT_SAVE: (v) => `save slot;`,
	SLOT_LOAD: (v) => `load slot ${v.slot};`,
	SLOT_ERASE: (v) => `erase slot ${v.slot};`,
	LOAD_MAP: (v) => `load map "${v.map}";`,
	BLOCKING_DELAY: (v) => `block ${printDuration(v.duration)};`,
	NON_BLOCKING_DELAY: (v) => `wait ${printDuration(v.duration)};`,
	SHOW_DIALOG: (v) => `show dialog ${v.dialog};`,
	CLOSE_DIALOG: (v) => `close dialog;`,
	SHOW_SERIAL_DIALOG: (v) => `show serial_dialog "${v.serial_dialog}";`,
	CLOSE_SERIAL_DIALOG: (v) => `close serial_dialog;`,
	SET_CONNECT_SERIAL_DIALOG: (v) => `serial_connect = "${v.serial_dialog}";`,
	SET_SCRIPT_PAUSE: (v) => `${v.bool_value ? '' : 'un'}pause ${printEntityIdentifier(v.entity)} ${v.script_slot};`,
	GOTO_ACTION_INDEX: (v) => `goto index ${v.action_index};`,
	RUN_SCRIPT: (v) => `goto "${v.script}";`,
	COPY_SCRIPT: (v) => `copy!("${v.scriptName}")`,
};

const stringIntoOpMap = {
	ADD: '+',
	SUB: '-',
	MUL: '*',
	DIV: '/',
	MOD: '%',
	RNG: '?',
	SET: '',
};

// Auto labels are illegal (contain spaces) on purpose to prevent collisions
// But that means we don't get round-trip translations unless we sanitze them thus:
const sanitizeLabel = label => label.includes(' ')
	? label
		.replaceAll(' ', '_')
		.replaceAll('-', '_')
		.replaceAll('#', '')
	: label;

const printGotoSegment = (data) => {
	if (data.jump_index) {
		return `goto index ${data.jump_index}`;
	} else if (data.success_script) {
		return `goto script "${data.success_script}"`;
	} else {
		return `goto label ${sanitizeLabel(data.label)}`;
	}
	// if (
	// 	data.mathlang?.includes('goto_label')
	// 	|| data.mathlang === 'bool_getable'
	// 	|| data.mathlang === 'bool_comparison'
	// 	|| data.mathlang === 'string_checkable'
	// 	|| data.mathlang === 'number_checkable_equality'
	// 	|| data.action === 'CHECK_SAVE_FLAG'
	// ) {
	// }
};
const printCheckAction = (data, lhs, smartInvert) => {
	const param = getBoolFieldForAction(data.action);
	const bang = smartInvert && !data[param] ? '!' : '';
	const goto = printGotoSegment(data);
	return `if ${bang}${lhs} then ${goto};`;
};
const printSetBoolAction = (data, lhs) => {
	const param = getBoolFieldForAction(data.action);
	return `${lhs} = ${data[param]};`
};
const printDuration = (duration) => duration + 'ms';
const printGeometry = (geometry) => `geometry "${geometry}"`;
const printEntityIdentifier = (entity) => {
	if (entity === '%PLAYER%') return 'player';
	if (entity === '%SELF%') return 'self';
	if (entity === '%MAP%') return 'map';
	if (entity === '%CAMERA%') return 'camera';
	return `entity "${entity}"`;
};
const printEntityFieldEquality = (v, param, value) => {
	const lhs = `${printEntityIdentifier(v.entity)} ${param}`;
	return v.expected_bool
		? printCheckAction(v, `${lhs} == ${value}`)
		: printCheckAction(v, `${lhs} != ${value}`);
};

const printScript = (scriptName, actions) => {
	const printedActions = actions
		.map(printAction)
		.filter(v=>v!==undefined)
		.map(v=>`   ${v}`);
	return [
		`"${scriptName}" {`,
		...printedActions,
		'}'
	].join('\n');
};

module.exports = {
	printScript,
}