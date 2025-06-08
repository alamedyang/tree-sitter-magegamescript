import * as TYPES from './parser-bytecode-info.ts';
import * as MATHLANG from './parser-types.ts';
import { inverseOpMap } from './parser-utilities.js';

type AnyNode = TYPES.Action | MATHLANG.MathlangNode;
export const isNodeAction = (node: TYPES.Action | MATHLANG.MathlangNode): node is TYPES.Action => {
	return (node as TYPES.Action).action !== undefined;
};

const printAction = (data: AnyNode) => {
	const isAction = isNodeAction(data);
	if (!isAction && data.mathlang === 'comment') {
		const abridged =
			data.comment.length > 70 ? data.comment.slice(0, 70) + '...' : data.comment;
		return `// ${abridged}`;
	} else if (isAction && data.action === 'LABEL') {
		return `${sanitizeLabel(data.value)}:`;
	}
	if (isAction && data.action) {
		const fn = printActionFns[data.action];
		if (!fn) throw new Error('Fn needed for ' + data.action);
		const print = fn(data);
		const comment = data.debug?.comment ? ' // ' + data.debug?.comment : '';
		return print + comment;
	}
	if (!isAction && data.mathlang) {
		if (data.mathlang === 'dialog_definition') {
			const sample = data.dialogs[0].messages[0].replaceAll('\n', ' ').slice(0, 40) + '...';
			return `// auto dialog: "${sample}"`;
		}
		if (data.mathlang === 'serial_dialog_definition') {
			const sample =
				data.serialDialog.serialDialog.messages[0].replaceAll('\n', ' ').slice(0, 40) +
				'...';
			return `// auto serial_dialog: "${sample}"`;
		}
		if (!isAction && data.mathlang === 'return_statement') return '// auto return label';
		const fn = mathlang[data.mathlang];
		if (!fn) throw new Error('Fn needed for ' + data.mathlang);
		const print = fn(data);
		if (isAction) {
			const comment = data.comment ? ' // ' + data.comment : '';
			return print + comment;
		}
		return print;
	}
	// if (data.error) {
	// 	return `// ERROR: ${data.debug.text.replace(/[\t\n\s]+/g, ' ')}`;
	// }
	throw new Error('Fn needed for ???');
};

const mathlang = {
	if_branch_goto_label: (data) => `${printGotoSegment(data)};`,
	goto_label: (data) => `${printGotoSegment(data)};`,
	label_definition: (data: MATHLANG.MathlangGotoLabel) => {
		if (!data.label) throw new Error('cannot print label without label');
		return `${sanitizeLabel(data.label)}:`;
	},
	copy_script: (data: MATHLANG.MathlangCopyMacro) => `copy!("${data.script}")`,
};

const printActionFns = {
	// Branch on bool equality (==)
	CHECK_DEBUG_MODE: (v: TYPES.CHECK_DEBUG_MODE) => printCheckAction(v, 'debug_mode', true),
	CHECK_SERIAL_DIALOG_OPEN: (v: TYPES.CHECK_SERIAL_DIALOG_OPEN) =>
		printCheckAction(v, `serial_dialog ${v.expected_bool ? 'open' : 'closed'}`, false),
	CHECK_DIALOG_OPEN: (v: TYPES.CHECK_DIALOG_OPEN) =>
		printCheckAction(v, `dialog ${v.expected_bool ? 'open' : 'closed'}`, false),
	CHECK_SAVE_FLAG: (v: TYPES.CHECK_SAVE_FLAG) => printCheckAction(v, `"${v.save_flag}"`, true),
	CHECK_FOR_BUTTON_PRESS: (v: TYPES.CHECK_FOR_BUTTON_PRESS) =>
		printCheckAction(v, `button ${v.button_id} pressed`, true),
	CHECK_FOR_BUTTON_STATE: (v: TYPES.CHECK_FOR_BUTTON_STATE) =>
		printCheckAction(v, `button ${v.button_id} ${v.expected_bool ? 'down' : 'up'}`, false),
	CHECK_IF_ENTITY_IS_IN_GEOMETRY: (v: TYPES.CHECK_IF_ENTITY_IS_IN_GEOMETRY) =>
		printCheckAction(
			v,
			`${printEntityIdentifier(v.entity)} intersects ${printGeometry(v.geometry)}`,
			true,
		),
	CHECK_ENTITY_GLITCHED: (v: TYPES.CHECK_ENTITY_GLITCHED) =>
		printCheckAction(v, `${printEntityIdentifier(v.entity)} glitched`, true),

	// Branch on int equality (==)
	CHECK_ENTITY_X: (v: TYPES.CHECK_ENTITY_X) => printEntityFieldEquality(v, 'x', v.expected_u2),
	CHECK_ENTITY_Y: (v: TYPES.CHECK_ENTITY_Y) => printEntityFieldEquality(v, 'y', v.expected_u2),
	CHECK_ENTITY_PRIMARY_ID: (v: TYPES.CHECK_ENTITY_PRIMARY_ID) =>
		printEntityFieldEquality(v, 'primary_id', v.expected_u2),
	CHECK_ENTITY_SECONDARY_ID: (v: TYPES.CHECK_ENTITY_SECONDARY_ID) =>
		printEntityFieldEquality(v, 'secondary_id', v.expected_u2),
	CHECK_ENTITY_PRIMARY_ID_TYPE: (v: TYPES.CHECK_ENTITY_PRIMARY_ID_TYPE) =>
		printEntityFieldEquality(v, 'primary_id_type', v.expected_byte),
	CHECK_ENTITY_CURRENT_ANIMATION: (v: TYPES.CHECK_ENTITY_CURRENT_ANIMATION) =>
		printEntityFieldEquality(v, 'current_animation', v.expected_byte),
	CHECK_ENTITY_CURRENT_FRAME: (v: TYPES.CHECK_ENTITY_CURRENT_FRAME) =>
		printEntityFieldEquality(v, 'animation_frame', v.expected_byte),

	// Branch on int comparison (== < <= => >)
	CHECK_VARIABLE: (v: TYPES.CHECK_VARIABLE) => {
		const op = v.expected_bool ? v.comparison : inverseOpMap[v.comparison];
		return printCheckAction(v, `"${v.variable}" ${op} ${v.value}`, false);
	},
	CHECK_VARIABLES: (v: TYPES.CHECK_VARIABLES) => {
		const op = v.expected_bool ? v.comparison : inverseOpMap[v.comparison];
		return printCheckAction(v, `"${v.variable}" ${op} "${v.source}"`, false);
	},

	// Branch on string equality (==)
	CHECK_WARP_STATE: (v: TYPES.CHECK_WARP_STATE) =>
		v.expected_bool
			? printCheckAction(v, `warp_state == "${v.string}"`, false)
			: printCheckAction(v, `warp_state != "${v.string}"`, false),
	CHECK_ENTITY_NAME: (v: TYPES.CHECK_ENTITY_NAME) =>
		printEntityFieldEquality(v, 'name', `"${v.string}"`),
	CHECK_ENTITY_TYPE: (v: TYPES.CHECK_ENTITY_TYPE) =>
		printEntityFieldEquality(v, 'type', `"${v.entity_type}"`),
	CHECK_ENTITY_INTERACT_SCRIPT: (v: TYPES.CHECK_ENTITY_INTERACT_SCRIPT) =>
		printEntityFieldEquality(v, 'on_interact', `"${v.expected_script}"`),
	CHECK_ENTITY_TICK_SCRIPT: (v: TYPES.CHECK_ENTITY_TICK_SCRIPT) =>
		printEntityFieldEquality(v, 'on_tick', `"${v.expected_script}"`),
	CHECK_ENTITY_LOOK_SCRIPT: (v: TYPES.CHECK_ENTITY_LOOK_SCRIPT) =>
		printEntityFieldEquality(v, 'on_look', `"${v.expected_script}"`),
	CHECK_ENTITY_DIRECTION: (v: TYPES.CHECK_ENTITY_DIRECTION) =>
		printEntityFieldEquality(v, 'direction', `"${v.direction}"`),
	CHECK_ENTITY_PATH: (v: TYPES.CHECK_ENTITY_PATH) =>
		printEntityFieldEquality(v, 'path', `"${v.geometry}"`),

	// Set bool (expressions OK)
	SET_SAVE_FLAG: (v: TYPES.SET_SAVE_FLAG) => printSetBoolAction(v, `"${v.save_flag}"`),
	SET_HEX_EDITOR_STATE: (v: TYPES.SET_HEX_EDITOR_STATE) => printSetBoolAction(v, `hex_editor`),
	SET_HEX_EDITOR_DIALOG_MODE: (v: TYPES.SET_HEX_EDITOR_DIALOG_MODE) =>
		printSetBoolAction(v, `hex_dialog_mode`),
	SET_HEX_EDITOR_CONTROL: (v: TYPES.SET_HEX_EDITOR_CONTROL) =>
		printSetBoolAction(v, `hex_control`),
	SET_HEX_EDITOR_CONTROL_CLIPBOARD: (v: TYPES.SET_HEX_EDITOR_CONTROL_CLIPBOARD) =>
		printSetBoolAction(v, `hex_clipboard`),
	SET_SERIAL_DIALOG_CONTROL: (v: TYPES.SET_SERIAL_DIALOG_CONTROL) =>
		printSetBoolAction(v, `serial_control`),
	SET_PLAYER_CONTROL: (v: TYPES.SET_PLAYER_CONTROL) => printSetBoolAction(v, `player_control`),
	SET_LIGHTS_CONTROL: (v: TYPES.SET_LIGHTS_CONTROL) => printSetBoolAction(v, `lights_control`),
	SET_LIGHTS_STATE: (v: TYPES.SET_LIGHTS_STATE) => printSetBoolAction(v, `light ${v.lights}`),
	SET_ENTITY_GLITCHED: (v: TYPES.SET_ENTITY_GLITCHED) =>
		printSetBoolAction(v, `${printEntityIdentifier(v.entity)} glitched`),

	// Set int (expressions OK)
	MUTATE_VARIABLE: (v: TYPES.MUTATE_VARIABLE) =>
		`"${v.variable}" ${stringIntoOpMap[v.operation]}= ${v.value};`,
	MUTATE_VARIABLES: (v: TYPES.MUTATE_VARIABLES) =>
		`"${v.variable}" ${stringIntoOpMap[v.operation]}= "${v.source}";`,
	COPY_VARIABLE: (v: TYPES.COPY_VARIABLE) =>
		v.inbound
			? `"${v.variable}" = ${printEntityIdentifier(v.entity)} ${v.field};`
			: `${printEntityIdentifier(v.entity)} ${v.field} = "${v.variable}";`,

	// Set int (expressions not allowed)
	SET_ENTITY_X: (v: TYPES.SET_ENTITY_X) =>
		`${printEntityIdentifier(v.entity)} x = ${v.u2_value};`,
	SET_ENTITY_Y: (v: TYPES.SET_ENTITY_Y) =>
		`${printEntityIdentifier(v.entity)} y = ${v.u2_value};`,
	SET_ENTITY_PRIMARY_ID: (v: TYPES.SET_ENTITY_PRIMARY_ID) =>
		`${printEntityIdentifier(v.entity)} primary_id = ${v.u2_value};`,
	SET_ENTITY_SECONDARY_ID: (v: TYPES.SET_ENTITY_SECONDARY_ID) =>
		`${printEntityIdentifier(v.entity)} secondary_id = ${v.u2_value};`,
	SET_ENTITY_PRIMARY_ID_TYPE: (v) =>
		`${printEntityIdentifier(v.entity)} primary_id_type = ${v.byte_value};`,
	SET_ENTITY_CURRENT_ANIMATION: (v) =>
		`${printEntityIdentifier(v.entity)} current_animation = ${v.byte_value};`,
	SET_ENTITY_CURRENT_FRAME: (v) =>
		`${printEntityIdentifier(v.entity)} animation_frame = ${v.byte_value};`,
	SET_ENTITY_MOVEMENT_RELATIVE: (v) =>
		`${printEntityIdentifier(v.entity)} strafe = ${v.relative_direction};`,
	SET_ENTITY_DIRECTION_RELATIVE: (v) => {
		if (v.relative_direction < 0) {
			return `${printEntityIdentifier(v.entity)} direction -= ${v.relative_direction};`;
		} else {
			return `${printEntityIdentifier(v.entity)} direction += ${v.relative_direction};`;
		}
	},

	// Set string
	SET_WARP_STATE: (v: TYPES.SET_WARP_STATE) => `warp_state = "${v.string}";`,
	SET_ENTITY_NAME: (v: TYPES.SET_ENTITY_NAME) =>
		`${printEntityIdentifier(v.entity)} name = "${v.string}";`,
	SET_ENTITY_TYPE: (v: TYPES.SET_ENTITY_TYPE) =>
		`${printEntityIdentifier(v.entity)} type = "${v.entity_type}";`,
	SET_ENTITY_PATH: (v: TYPES.SET_ENTITY_PATH) =>
		`${printEntityIdentifier(v.entity)} path = "${v.geometry}";`,
	SET_ENTITY_DIRECTION: (v: TYPES.SET_ENTITY_DIRECTION) =>
		`${printEntityIdentifier(v.entity)} direction = "${v.direction}";`,
	SET_ENTITY_LOOK_SCRIPT: (v: TYPES.SET_ENTITY_LOOK_SCRIPT) =>
		`${printEntityIdentifier(v.entity)} on_look = "${v.script}";`,
	SET_ENTITY_INTERACT_SCRIPT: (v: TYPES.SET_ENTITY_INTERACT_SCRIPT) =>
		`${printEntityIdentifier(v.entity)} on_interact = "${v.script}";`,
	SET_ENTITY_TICK_SCRIPT: (v: TYPES.SET_ENTITY_TICK_SCRIPT) =>
		`${printEntityIdentifier(v.entity)} on_tick = "${v.script}";`,
	SET_MAP_TICK_SCRIPT: (v: TYPES.SET_MAP_TICK_SCRIPT) => `map on_tick = "${v.script}";`,

	// Set position
	SET_CAMERA_TO_FOLLOW_ENTITY: (v: TYPES.SET_CAMERA_TO_FOLLOW_ENTITY) =>
		`camera = ${printEntityIdentifier(v.entity)} position;`,
	TELEPORT_CAMERA_TO_GEOMETRY: (v: TYPES.TELEPORT_CAMERA_TO_GEOMETRY) =>
		`camera = ${printGeometry(v.geometry)};`,
	TELEPORT_ENTITY_TO_GEOMETRY: (v: TYPES.TELEPORT_ENTITY_TO_GEOMETRY) =>
		`${printEntityIdentifier(v.entity)} position = ${printGeometry(v.geometry)};`,
	SET_ENTITY_DIRECTION_TARGET_ENTITY: (v: TYPES.SET_ENTITY_DIRECTION_TARGET_ENTITY) =>
		`${printEntityIdentifier(v.entity)} direction = ${printEntityIdentifier(v.target_entity)};`,
	SET_ENTITY_DIRECTION_TARGET_GEOMETRY: (v: TYPES.SET_ENTITY_DIRECTION_TARGET_GEOMETRY) =>
		`${printEntityIdentifier(v.entity)} direction = ${printGeometry(v.target_geometry)};`,

	// Set position over time
	WALK_ENTITY_TO_GEOMETRY: (v: TYPES.WALK_ENTITY_TO_GEOMETRY) =>
		`${printEntityIdentifier(v.entity)} position -> ${printGeometry(v.geometry)} origin over ${printDuration(v.duration)};`,
	WALK_ENTITY_ALONG_GEOMETRY: (v: TYPES.WALK_ENTITY_ALONG_GEOMETRY) =>
		`${printEntityIdentifier(v.entity)} position -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)};`,
	LOOP_ENTITY_ALONG_GEOMETRY: (v: TYPES.LOOP_ENTITY_ALONG_GEOMETRY) =>
		`${printEntityIdentifier(v.entity)} position -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)} forever;`,
	PAN_CAMERA_TO_ENTITY: (v: TYPES.PAN_CAMERA_TO_ENTITY) =>
		`camera -> ${printEntityIdentifier(v.entity)} position over ${printDuration(v.duration)};`,
	PAN_CAMERA_TO_GEOMETRY: (v: TYPES.PAN_CAMERA_TO_GEOMETRY) =>
		`camera -> ${printGeometry(v.geometry)} origin over ${printDuration(v.duration)};`,
	PAN_CAMERA_ALONG_GEOMETRY: (v: TYPES.PAN_CAMERA_ALONG_GEOMETRY) =>
		`camera -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)};`,
	LOOP_CAMERA_ALONG_GEOMETRY: (v: TYPES.LOOP_CAMERA_ALONG_GEOMETRY) =>
		`camera -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)} forever;`,

	// Other do over time
	SET_SCREEN_SHAKE: (v: TYPES.SET_SCREEN_SHAKE) =>
		`camera shake -> ${v.frequency}ms ${v.amplitude}px over ${printDuration(v.duration)};`,
	SCREEN_FADE_IN: (v: TYPES.SCREEN_FADE_IN) =>
		`camera fade in -> ${v.color} over ${printDuration(v.duration)};`,
	SCREEN_FADE_OUT: (v: TYPES.SCREEN_FADE_OUT) =>
		`camera fade out -> ${v.color} over ${printDuration(v.duration)};`,
	PLAY_ENTITY_ANIMATION: (v: TYPES.PLAY_ENTITY_ANIMATION) =>
		`${printEntityIdentifier(v.entity)} animation -> ${v.animation} ${v.play_count}x;`,

	// Commands and aliases
	REGISTER_SERIAL_DIALOG_COMMAND: (v: TYPES.REGISTER_SERIAL_DIALOG_COMMAND) =>
		v.is_fail
			? `command "${v.command}" fail = "${v.script}";`
			: `command "${v.command}" = "${v.script}";`,
	UNREGISTER_SERIAL_DIALOG_COMMAND: (v: TYPES.UNREGISTER_SERIAL_DIALOG_COMMAND) =>
		`delete command "${v.command}";`,
	REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: (v: TYPES.REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT) =>
		`command "${v.command}" + "${v.argument}" = "${v.script}";`,
	UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: (
		v: TYPES.UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT,
	) => `delete command "${v.command}" + "${v.argument}";`,
	REGISTER_SERIAL_DIALOG_COMMAND_ALIAS: (v: TYPES.REGISTER_SERIAL_DIALOG_COMMAND_ALIAS) =>
		`alias "${v.alias}" = "${v.command}";`,
	UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS: (v: TYPES.UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS) =>
		`delete alias "${v.alias}";`,
	SET_SERIAL_DIALOG_COMMAND_VISIBILITY: (v: TYPES.SET_SERIAL_DIALOG_COMMAND_VISIBILITY) =>
		`${v.is_visible ? 'un' : ''}hide command "${v.command}";`,

	// Miscellaneous
	SLOT_SAVE: () => `save slot;`,
	SLOT_LOAD: (v: TYPES.SLOT_LOAD) => `load slot ${v.slot};`,
	SLOT_ERASE: (v: TYPES.SLOT_ERASE) => `erase slot ${v.slot};`,
	LOAD_MAP: (v: TYPES.LOAD_MAP) => `load map "${v.map}";`,
	BLOCKING_DELAY: (v: TYPES.BLOCKING_DELAY) => `block ${printDuration(v.duration)};`,
	NON_BLOCKING_DELAY: (v: TYPES.NON_BLOCKING_DELAY) => `wait ${printDuration(v.duration)};`,
	SHOW_DIALOG: (v: TYPES.SHOW_DIALOG) => `show dialog "${v.dialog}";`,
	CLOSE_DIALOG: () => `close dialog;`,
	SHOW_SERIAL_DIALOG: (v: TYPES.SHOW_SERIAL_DIALOG) => `show serial_dialog "${v.serial_dialog}";`,
	CLOSE_SERIAL_DIALOG: () => `close serial_dialog;`,
	SET_CONNECT_SERIAL_DIALOG: (v: TYPES.SET_CONNECT_SERIAL_DIALOG) =>
		`serial_connect = "${v.serial_dialog}";`,
	SET_SCRIPT_PAUSE: (v: TYPES.SET_SCRIPT_PAUSE) =>
		`${v.bool_value ? '' : 'un'}pause ${printEntityIdentifier(v.entity)} ${v.script_slot};`,
	GOTO_ACTION_INDEX: (v: TYPES.GOTO_ACTION_INDEX) => {
		if (typeof v.action_index === 'string') {
			return `goto label ${sanitizeLabel(v.action_index)};`;
		}
		return `goto index ${v.action_index};`;
	},
	RUN_SCRIPT: (v: TYPES.RUN_SCRIPT) => `goto script "${v.script}";`,
	COPY_SCRIPT: (v: TYPES.COPY_SCRIPT) => `copy!("${v.script}")`,
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
const sanitizeLabel = (label) =>
	label.includes(' ')
		? label.replaceAll(' ', '_').replaceAll('-', '_').replaceAll('#', '')
		: label;

const printGotoSegment = (data) => {
	if (data.jump_index !== undefined) {
		if (typeof data.jump_index === 'string') {
			return `goto label ${sanitizeLabel(data.jump_index)}`;
		}
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
const printCheckAction = (data: TYPES.Action, lhs: string, smartInvert: boolean): string => {
	const param = TYPES.getBoolFieldForAction(data.action);
	if (!param) throw new Error('No param for action');
	const bang = smartInvert && !data[param] ? '!' : '';
	const goto = printGotoSegment(data);
	return `if ${bang}${lhs} then ${goto};`;
};
const printSetBoolAction = (data: TYPES.Action, lhs: string) => {
	const param = TYPES.getBoolFieldForAction(data.action);
	if (!param) throw new Error('No param for action');
	return `${lhs} = ${data[param]};`;
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
		? printCheckAction(v, `${lhs} == ${value}`, false)
		: printCheckAction(v, `${lhs} != ${value}`, false);
};

export const printScript = (scriptName, actions) => {
	const printedActions = actions
		.map(printAction)
		.filter((v) => v !== undefined)
		.map((v) => `   ${v}`);
	const ret = [`"${scriptName}" {`, ...printedActions, '}'].join('\n');
	return ret;
};
