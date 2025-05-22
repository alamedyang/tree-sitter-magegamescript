let indent = '  ';

const translateOne = (data) => {
	if (data.mathlang === 'comment') {
		return `// ${data.comment}`;
	}
	if (data.action) {
		const fn = actions[data.action];
		if (!fn) throw new Error ('Fn needed for ' + data.action);
		return fn(data);
	}
	if (data.mathlang) {
		const fn = mathlang[data.mathlang];
		if (!fn) throw new Error ('Fn needed for ' + data.mathlang);
		return fn(data);
	}
	if (data.error) {
		return `// ERROR: ${data.debug.text.replace(/[\t\n\s]+/g, ' ')}`
	}
	throw new Error ('Fn needed for ???')
}

const sanitizeLabel = label => {
	if (label.includes(' ')) {
		return '_'+label.replaceAll(' ', '_').replaceAll('#', '');
	} else {
		return '_'+label;
	}
}

const validateGoto = (data) => {
	if (data.mathlang === 'goto_label') {
		if (!data.label || typeof data.label !== 'string') {
			throw new Error ('Goto not a label jump?', data);
		}
		return `goto label ${sanitizeLabel(data.label)}`;
	}
	if (!data.jump_index) {
		throw new Error ('Goto not a index jump?', data);
	}
	return `goto index ${data.jump_index}`;
}
const setBool = (data, lhs) => {
	const param = data.boolParamName || 'expected_bool';
	return `${lhs} = ${data[param]};`
}

const check = (data, lhs, smartInvert) => {
	const param = data.boolParamName || 'expected_bool';
	const bang = smartInvert && !data[param] ? '!' : '';
	const goto = validateGoto(data);
	return `if (${bang}${lhs}) { ${goto}; }`;
}

const printEntity = (entity) => {
	if (entity === '%PLAYER%') return 'player';
	if (entity === '%SELF%') return 'self';
	if (entity === '%MAP%') return 'map';
	if (entity === '%CAMERA%') return 'camera';
	return `entity "${entity}"`;
}
const printDuration = (duration) => duration + 'ms';
const printGeometry = (geometry) => `geometry "${geometry}"`;
const opIntoStringMap = {
	'=': 'SET',
	'+': 'ADD',
	'-': 'SUB',
	'*': 'MUL',
	'/': 'DIV',
	'%': 'MOD',
	'?': 'RNG',
};
const stringIntoOpMap = {
	ADD: '+',
	SUB: '-',
	MUL: '*',
	DIV: '/',
	MOD: '%',
	RNG: '?',
	SET: ':',
};
const actions = {
	// Branch on bool equality (==)
	CHECK_DEBUG_MODE: (v) => check(v, 'debug_mode', true),
	CHECK_SERIAL_DIALOG_OPEN: (v) => check(v, `serial_dialog ${v.expected_bool ? 'open' : 'closed'}`, true),
	CHECK_DIALOG_OPEN: (v) => check(v, `dialog ${v.expected_bool ? 'open' : 'closed'}`, true),
	CHECK_SAVE_FLAG: (v) => check(v, v.save_flag, true),
	CHECK_FOR_BUTTON_PRESS: (v) => check(v, `buttom ${v.button} pressed`, true),
	CHECK_FOR_BUTTON_STATE: (v) => check(v, `buttom ${v.button} ${v.expected_bool ? 'down' : 'up'}`, true),
	CHECK_IF_ENTITY_IS_IN_GEOMETRY: (v) => check(v, `${printEntity(v.entity)} intersects ${printGeometry(v.geometry)}`, true),
	CHECK_ENTITY_GLITCHED: (v) => check(v, `${printEntity(v.entity)} glitched`, true),
	
	// Branch on int equality (==)
	CHECK_ENTITY_X: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} x == ${v.expected_u2}`)
			: check(v, `${printEntity(v.entity)} x != ${v.expected_u2}`);
	},
	CHECK_ENTITY_Y: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} y == ${v.expected_u2}`)
			: check(v, `${printEntity(v.entity)} y != ${v.expected_u2}`);
	},
	CHECK_ENTITY_PRIMARY_ID: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} primary_id == ${v.expected_u2}`)
			: check(v, `${printEntity(v.entity)} primary_id != ${v.expected_u2}`);
	},
	CHECK_ENTITY_SECONDARY_ID: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} secondary_id == ${v.expected_u2}`)
			: check(v, `${printEntity(v.entity)} secondary_id != ${v.expected_u2}`);
	},
	CHECK_ENTITY_PRIMARY_ID_TYPE: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} primary_id_type == ${v.expected_byte}`)
			: check(v, `${printEntity(v.entity)} primary_id_type != ${v.expected_byte}`);
	},
	CHECK_ENTITY_CURRENT_ANIMATION: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} primary_id == ${v.expected_byte}`)
			: check(v, `${printEntity(v.entity)} primary_id != ${v.expected_byte}`);
	},
	CHECK_ENTITY_CURRENT_FRAME: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} primary_id == ${v.expected_byte}`)
			: check(v, `${printEntity(v.entity)} primary_id != ${v.expected_byte}`);
	},
	
	// Branch on int comparison (== < <= => >)
	CHECK_VARIABLE: (v) => check(v, `${v.variable} ${v.comparison} ${v.value}`),
	CHECK_VARIABLES: (v) => check(v, `${v.variable} ${v.comparison} ${v.source}`),

	// Branch on string equality (==)
	CHECK_WARP_STATE: (v) => {
		return v.expected_bool
			? check(v, `warp_state == "${v.string}"`)
			: check(v, `warp_state != "${v.string}"`);
	},
	CHECK_ENTITY_NAME: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} name == "${v.string}"`)
			: check(v, `${printEntity(v.entity)} name != "${v.string}"`);
	},
	CHECK_ENTITY_TYPE: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} type == "${v.entity_type}"`)
			: check(v, `${printEntity(v.entity)} type != "${v.entity_type}"`);
	},
	CHECK_ENTITY_INTERACT_SCRIPT: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} on_interact == "${v.expected_script}"`)
			: check(v, `${printEntity(v.entity)} on_interact != "${v.expected_script}"`);
	},
	CHECK_ENTITY_TICK_SCRIPT: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} on_tick == "${v.expected_script}"`)
			: check(v, `${printEntity(v.entity)} on_tick != "${v.expected_script}"`);
	},
	CHECK_ENTITY_LOOK_SCRIPT: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} on_look == "${v.expected_script}"`)
			: check(v, `${printEntity(v.entity)} on_look != "${v.expected_script}"`);
	},
	CHECK_ENTITY_DIRECTION: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} direction == "${v.direction}"`)
			: check(v, `${printEntity(v.entity)} direction != "${v.direction}"`);
	},
	CHECK_ENTITY_PATH: (v) => {
		return v.expected_bool
			? check(v, `${printEntity(v.entity)} direction == "${v.geometry}"`)
			: check(v, `${printEntity(v.entity)} direction != "${v.geometry}"`);
	},

	// Set bool (expressions OK)
	// Expressions are okay for all these because there are only two choices.
	// We cannot branch arbitrarily for every possible int!
	SET_SAVE_FLAG: (v) => setBool(v, v.lhs),
	SET_HEX_EDITOR_STATE: (v) => setBool(v, `hex_editor`),
	SET_HEX_EDITOR_DIALOG_MODE: (v) => setBool(v, `hex_dialog_mode`),
	SET_HEX_EDITOR_CONTROL: (v) => setBool(v, `hex_control`),
	SET_HEX_EDITOR_CONTROL_CLIPBOARD: (v) => setBool(v, `hex_clipboard`),
	SET_SERIAL_DIALOG_CONTROL: (v) => setBool(v, `serial_control`),
	SET_PLAYER_CONTROL: (v) => setBool(v, `player_control`),
	SET_LIGHTS_CONTROL: (v) => setBool(v, `lights_control`),
	SET_LIGHTS_STATE: (v) => setBool(v, `light ${v.light}`),
	SET_ENTITY_GLITCHED: (v) => setBool(v, `${printEntity(v.entity)} glitched`),

	// Set int (expressions OK)
	MUTATE_VARIABLE: (v) => `${v.variable} ${stringIntoOpMap[v.operation]}= ${v.value};`,
	MUTATE_VARIABLES: (v) => `${v.variable} ${stringIntoOpMap[v.operation]}= ${v.source};`,
	COPY_VARIABLE: (v) => v.inbound
		? `${v.variable} = ${printEntity(v.entity)} ${v.field};`
		: `${printEntity(v.entity)} ${v.field} = ${v.variable};`,

	// Set int (expressions not allowed)
	SET_ENTITY_X: (v) => `${printEntity(v.entity)} x = ${v.u2_value};`,
	SET_ENTITY_Y: (v) => `${printEntity(v.entity)} y = ${v.u2_value};`,
	SET_ENTITY_PRIMARY_ID: (v) => `${printEntity(v.entity)} primary_id = ${v.u2_value};`,
	SET_ENTITY_SECONDARY_ID: (v) => `${printEntity(v.entity)} secondary_id = ${v.u2_value};`,
	SET_ENTITY_PRIMARY_ID_TYPE: (v) => `${printEntity(v.entity)} primary_id_type = ${v.byte_value};`,
	SET_ENTITY_CURRENT_ANIMATION: (v) => `${printEntity(v.entity)} current_animation = ${v.byte_value};`,
	SET_ENTITY_CURRENT_FRAME: (v) => `${printEntity(v.entity)} animation_frame = ${v.byte_value};`,
	SET_ENTITY_MOVEMENT_RELATIVE: (v) => `${printEntity(v.entity)} strafe = ${v.relative_direction};`,
	SET_ENTITY_DIRECTION_RELATIVE: (v) => { throw new Error ('not yet implemented') },

	// Set string
	SET_WARP_STATE: (v) => `warp_state = ${v.string};`,
	SET_ENTITY_NAME: (v) => `${printEntity} ${v.string} = ${v.stringLabel}`,
	SET_ENTITY_TYPE: (v) => `${printEntity} ${v.entity_type} = ${v.stringLabel}`,
	SET_ENTITY_PATH: (v) => `${printEntity} ${v.geometry} = ${v.stringLabel}`,
	SET_ENTITY_DIRECTION: (v) => `${printEntity} ${v.direction} = ${v.stringLabel}`,
	SET_ENTITY_LOOK_SCRIPT: (v) => `${printEntity} ${v.script} = ${v.stringLabel}`,
	SET_ENTITY_INTERACT_SCRIPT: (v) => `${printEntity} ${v.script} = ${v.stringLabel}`,
	SET_ENTITY_TICK_SCRIPT: (v) => `${printEntity} ${v.script} = ${v.stringLabel}`,
	SET_MAP_TICK_SCRIPT: (v) => `${printEntity} ${v.script} = ${v.stringLabel}`,

	// Set position
	SET_CAMERA_TO_FOLLOW_ENTITY: (v) => `camera = ${printEntity(v.entity)};`,
	TELEPORT_CAMERA_TO_GEOMETRY: (v) => `camera = ${printGeometry(v.geometry)};`,
	TELEPORT_ENTITY_TO_GEOMETRY: (v) => `${printEntity(v.entity)} position = ${printGeometry(v.geometry)};`,
	SET_ENTITY_DIRECTION_TARGET_ENTITY: (v) => { throw new Error ('not yet implemented') },
	SET_ENTITY_DIRECTION_TARGET_GEOMETRY: (v) => { throw new Error ('not yet implemented') },

	// Set position over time
	WALK_ENTITY_TO_GEOMETRY: (v) => `${printEntity(v.entity)} position -> ${printGeometry(v.geometry)} origin over ${printDuration(v.duration)};`,
	WALK_ENTITY_ALONG_GEOMETRY: (v) => `${printEntity(v.entity)} position -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)};`,
	LOOP_ENTITY_ALONG_GEOMETRY: (v) => `${printEntity(v.entity)} position -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)} forever;`,
	PAN_CAMERA_TO_ENTITY: (v) => `camera -> ${printEntity(v.entity)} position over ${printDuration(v.duration)};`,
	PAN_CAMERA_TO_GEOMETRY: (v) => `camera -> ${printGeometry(v.geometry)} origin over ${printDuration(v.duration)};`,
	PAN_CAMERA_ALONG_GEOMETRY: (v) => `camera -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)};`,
	LOOP_CAMERA_ALONG_GEOMETRY: (v) => `camera -> ${printGeometry(v.geometry)} length over ${printDuration(v.duration)} forever;`,
	
	// Other do over time
	SET_SCREEN_SHAKE: (v) => `camera shake -> ${v.amplitude} ${v.distance} over ${printDuration(v.duration)};`,
	SCREEN_FADE_IN: (v) => `camera fade in -> ${v.color} over ${printDuration(v.duration)};`,
	SCREEN_FADE_OUT: (v) => `camera fade out -> ${v.color} over ${printDuration(v.duration)};`,
	PLAY_ENTITY_ANIMATION: (v) => `${printEntity(v.entity)} animation -> ${animation} ${count};`,

	// Commands and aliases
	REGISTER_SERIAL_DIALOG_COMMAND: (v) => v.is_fail
		? `command ${v.command} fail = ${v.script};`
		: `command ${v.command} = ${v.script};`,
	UNREGISTER_SERIAL_DIALOG_COMMAND: (v) => `delete command ${v.command};`,
	REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: (v) => `command ${v.command} + ${v.argument} = ${v.script};`,
	UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT: (v) => `delete command ${v.command} + ${v.argument};`,
	REGISTER_SERIAL_DIALOG_COMMAND_ALIAS: (v) => `alias ${v.alias} = ${v.command};`,
	UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS: (v) => `delete alias ${v.alias};`,
	SET_SERIAL_DIALOG_COMMAND_VISIBILITY: (v) => `${v.is_visible ? 'un' : ''}unhide command ${v.command};`,

	// Other
	SLOT_SAVE: (v) => `save slot;`,
	SLOT_LOAD: (v) => `load slot ${v.slot};`,
	SLOT_ERASE: (v) => `erase slot ${v.slot};`,
	LOAD_MAP: (v) => `load map ${v.map};`,
	BLOCKING_DELAY: (v) => `block ${printDuration(v.duration)};`,
	NON_BLOCKING_DELAY: (v) => `wait ${printDuration(v.duration)};`,
	SHOW_DIALOG: (v) => `show dialog ${v.dialog}`,
	CLOSE_DIALOG: (v) => `close dialog;`,
	SHOW_SERIAL_DIALOG: (v) => `show serial_dialog ${v.serial_dialog}`,
	CLOSE_SERIAL_DIALOG: (v) => `close serial_dialog;`,
	SET_CONNECT_SERIAL_DIALOG: (v) => `serial_connect = ${v.serial_dialog};`,
	SET_SCRIPT_PAUSE: (v) => `${v.bool_value ? '' : 'un'}pause ${printEntity(v.entity)} ${v.script_slot};`,
	GOTO_ACTION_INDEX: (v) => `goto index ${v.action_index};`,
	RUN_SCRIPT: (v) => `goto ${v.script};`,
	COPY_SCRIPT: (v) => `copy!(${v.scriptName})`
}

const mathlang = {
	goto_label: (data) => `${validateGoto(data)};`,
	label_definition: (data) => `${sanitizeLabel(data.label)}:`,
}
const translateScript = (scriptName, actions) => {
	const lines = [
		scriptName + ' {',
		...actions.map(translateOne).filter(v=>v!==undefined).map(v=>indent+v),
		'}'
	].join('\n');
	return lines;
};

module.exports = {
	translateScript,
}