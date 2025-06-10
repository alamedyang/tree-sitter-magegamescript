import { parseProject } from './parser.js';
import { ansiTags } from './parser-dialogs.js';

const actionArrayToScript = (scriptName, actionArray, autoAddEOF) => {
	const ret = [`"${scriptName}" {`, ...actionArray.map((v) => '\t' + v)];
	if (autoAddEOF) {
		ret.push(`\tend_of_script_***:`);
	}
	ret.push('}');
	return ret.join('\n');
};

// will do all tests if empty
// if not empty, also won't do any file-level tests
const onlyDoTheseActionTests = [
	// 'mainframe_watchbox', 'if_single', 'bool_exp_branch_debug_mode'
	'branch_on_string_equality_direction',
];

const skipTheseTests = new Set(['set_int_exp_ok']);

// --------------------------- ACTION TESTS ---------------------------
const actionTests = {
	mainframe_watchbox: {
		input: [
			`if (player intersects geometry "mainframe-watchbox") {`,
			`	// :3 -- empty body!`,
			`} else if (player intersects geometry "mainframe-watchdonut") {`,
			`	player position -> geometry "mainframe-look-spot" origin over 300ms;`,
			`} else {`,
			`	player position -> geometry "mainframe-look-spot" origin over 500ms;`,
			`}`,
		],
		expected: [
			`if player intersects geometry "mainframe-watchbox" then goto label *A*;`,
			`if player intersects geometry "mainframe-watchdonut" then goto label *B*;`,
			`player position -> geometry "mainframe-look-spot" origin over 500ms;`,
			`goto label *C*;`,
			`*B*:`,
			`player position -> geometry "mainframe-look-spot" origin over 300ms;`,
			`goto label *C*;`,
			`*A*:`,
			`*C*:`,
			``,
		],
	},
	simple_copy: {
		input: ['wait 1;', 'copy!(no_arg_actions)', 'wait 2;'],
		expected: [
			'wait 1ms;',
			'save slot;',
			'close dialog;',
			'close serial_dialog;',
			'end_of_script_***',
			'wait 2ms;',
		],
	},
	if_single: {
		input: [
			'asdf:',
			'if debug_mode then goto script destinationScript;',
			'if debug_mode then goto destinationScript;',
			'if debug_mode then goto label asdf;',
			'if debug_mode then goto index 99;',
			'if true then goto index 99;',
			'if false then goto index 99;',
			'if 6 < 7 then goto index 99;',
			'if intName < 7 then goto index 99;',
			'if !debug_mode then goto index 99;',
			'if player glitched then goto index 99;',
			'if !player glitched then goto index 99;',
			'if player intersects geometry stick then goto index 99;',
			'if !player intersects geometry stick then goto index 99;',
			'if dialog open then goto index 99;',
			'if !dialog open then goto index 99;', // I'll allow it (preventing it is hard)
			'if serial_dialog open then goto index 99;',
			'if !serial_dialog open then goto index 99;', // I'll allow it
			'if button HAX pressed then goto index 99;',
			'if !button HAX pressed then goto index 99;',
			'if button HAX up then goto index 99;',
			'if button HAX down then goto index 99;',
			'if !button HAX up then goto index 99;', // I'll allow it
			'if !button HAX down then goto index 99;', // I'll allow it
		],
		expected: [
			'asdf:',
			'if debug_mode then goto script destinationScript;',
			'if debug_mode then goto script destinationScript;',
			'if debug_mode then goto label asdf;',
			'if debug_mode then goto index 99;',
			'goto index 99;',
			// (skip)
			'goto index 99;',
			'if "intName" < 7 then goto index 99;',
			'if !debug_mode then goto index 99;',
			'if player glitched then goto index 99;',
			'if !player glitched then goto index 99;',
			'if player intersects geometry "stick" then goto index 99;',
			'if !player intersects geometry "stick" then goto index 99;',
			'if dialog open then goto index 99;',
			'if dialog closed then goto index 99;',
			'if serial_dialog open then goto index 99;',
			'if serial_dialog closed then goto index 99;',
			'if button HAX pressed then goto index 99;',
			'if !button HAX pressed then goto index 99;',
			'if button HAX up then goto index 99;',
			'if button HAX down then goto index 99;',
			'if button HAX down then goto index 99;',
			'if button HAX up then goto index 99;',
		],
	},
	no_arg_actions: {
		input: [
			// SLOT_SAVE
			'save slot;',
			// CLOSE_DIALOG
			'close dialog;',
			// CLOSE_SERIAL_DIALOG
			'close serial_dialog;',
		],
	},
	simple_actions: {
		input: [
			// BLOCKING_DELAY
			'wait 1000ms;',
			// NON_BLOCKING_DELAY
			'block 999ms;',
			// SLOT_LOAD
			'load slot 0;',
			// SLOT_ERASE
			'erase slot 0;',
			// LOAD_MAP
			'load map goatMap;',
		],
	},
	SET_SCRIPT_PAUSE: {
		input: [
			// SET_SCRIPT_PAUSE
			'pause player on_look;',
			'pause self on_look;',
			'pause entity Bob on_look;',
			'pause entity "Bob" on_look;',
			'unpause player on_look;',
			'unpause self on_look;',
			'unpause entity Bob on_look;',
			'unpause entity "Bob" on_look;',
			'pause player on_interact;',
			'pause self on_interact;',
			'pause entity Bob on_interact;',
			'pause entity "Bob" on_interact;',
			'unpause player on_interact;',
			'unpause self on_interact;',
			'unpause entity Bob on_interact;',
			'unpause entity "Bob" on_interact;',
			'pause player on_tick;',
			'pause self on_tick;',
			'pause entity Bob on_tick;',
			'pause entity "Bob" on_tick;',
			'unpause player on_tick;',
			'unpause self on_tick;',
			'unpause entity Bob on_tick;',
			'unpause entity "Bob" on_tick;',
			'pause map on_tick;',
			'unpause map on_tick;',
			'pause map on_load;',
			'unpause map on_load;',
			'pause map on_command;',
			'unpause map on_command;',
		],
	},
	commands_and_aliases: {
		input: [
			// REGISTER_SERIAL_DIALOG_COMMAND
			'command callGoat = goatScript;',
			'command callGoat fail = goatScript;',
			// UNREGISTER_SERIAL_DIALOG_COMMAND
			'delete command callGoat;',
			// TODO: how to delete the fail though?
			// REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
			'command callGoat + billy = billyScript;',
			// UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
			'delete command callGoat + billy;',
			// REGISTER_SERIAL_DIALOG_COMMAND_ALIAS
			'alias g = callGoat;',
			// UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS
			'delete alias g;',
			// SET_SERIAL_DIALOG_COMMAND_VISIBILITY
			'hide command callGoat;',
			'unhide command callGoat;',
		],
	},
	set_position: {
		input: [
			// SET_CAMERA_TO_FOLLOW_ENTITY
			'camera = player position;',
			// TELEPORT_CAMERA_TO_GEOMETRY
			'camera = geometry stick;',
			// TELEPORT_ENTITY_TO_GEOMETRY
			'player position = geometry stick;',
			// SET_ENTITY_DIRECTION_TARGET_ENTITY
			'self direction = player;',
			'entity Bender direction = player;',
			'player direction = player;',
			'player direction = self;',
			'self direction = self;',
			'entity Bender direction = self;',
			'player direction = entity Bob;',
			'self direction = entity Bob;',
			'entity Bender direction = entity Bob;',
			// SET_ENTITY_DIRECTION_TARGET_GEOMETRY
			'player direction = geometry stick;',
			'self direction = geometry stick;',
			'entity Bender direction = geometry stick;',
		],
	},
	set_position_over_time: {
		input: [
			// WALK_ENTITY_TO_GEOMETRY
			'player position -> geometry stick origin over 1ms;',
			'self position -> geometry stick origin over 1ms;',
			'entity Oscar position -> geometry stick origin over 1ms;',
			// WALK_ENTITY_ALONG_GEOMETRY
			'player position -> geometry stick length over 1ms;',
			'self position -> geometry stick length over 1ms;',
			'entity Oscar position -> geometry stick length over 1ms;',
			// LOOP_ENTITY_ALONG_GEOMETRY
			'player position -> geometry stick length over 1ms forever;',
			'self position -> geometry stick length over 1ms forever;',
			'entity Oscar position -> geometry stick length over 1ms forever;',
			// PAN_CAMERA_TO_ENTITY
			'camera -> player position over 1ms;',
			'camera -> self position over 1ms;',
			'camera -> entity Bob position over 1ms;',
			// PAN_CAMERA_TO_GEOMETRY
			'camera -> geometry stick origin over 1ms;',
			// PAN_CAMERA_ALONG_GEOMETRY
			'camera -> geometry stick length over 1ms;',
			// LOOP_CAMERA_ALONG_GEOMETRY
			'camera -> geometry stick length over 1ms forever;',
		],
	},
	other_do_over_time: {
		input: [
			// SET_SCREEN_SHAKE
			'camera shake -> 20ms 50px over 100ms;',
			// SCREEN_FADE_IN
			'camera fade in -> #000000 over 100ms;',
			// SCREEN_FADE_OUT
			'camera fade out -> #FFFFFF over 100ms;',
			// PLAY_ENTITY_ANIMATION
			'player animation -> 0 4x;',
			'self animation -> 0 4x;',
			'entity George animation -> 0 4x;',
		],
	},
	simpleTranslations: {
		input: [
			// seconds -> milliseconds
			`wait 1s;`,
			// color words -> hex
			'camera fade in -> white over 1s;',
			'camera fade in -> black over 1s;',
			'camera fade in -> red over 1s;',
			'camera fade in -> green over 1s;',
			'camera fade in -> blue over 1s;',
			'camera fade in -> magenta over 1s;',
			'camera fade in -> cyan over 1s;',
			'camera fade in -> yellow over 1s;',
			'camera fade in -> #ABC over 1;',
			'camera fade in -> #def over 1;',
			// counts
			'player animation -> 0 once;',
			'player animation -> 0 twice;',
			'player animation -> 0 thrice;',
			// pix -> px
			'camera shake -> 2s 50pix over 1000;',
		],
		expected: [
			`wait 1000ms;`,
			'camera fade in -> #FFFFFF over 1000ms;',
			'camera fade in -> #000000 over 1000ms;',
			'camera fade in -> #FF0000 over 1000ms;',
			'camera fade in -> #00FF00 over 1000ms;',
			'camera fade in -> #0000FF over 1000ms;',
			'camera fade in -> #FF00FF over 1000ms;',
			'camera fade in -> #00FFFF over 1000ms;',
			'camera fade in -> #FFFF00 over 1000ms;',
			'camera fade in -> #AABBCC over 1ms;',
			'camera fade in -> #ddeeff over 1ms;',
			'player animation -> 0 1x;',
			'player animation -> 0 2x;',
			'player animation -> 0 3x;',
			'camera shake -> 2000ms 50px over 1000ms;',
		],
	},
	set_string: {
		input: [
			// SET_WARP_STATE
			'warp_state = goat;',
			// SET_ENTITY_NAME
			'player name = goat;',
			'self name = goat;',
			'entity Billy name = goat;',
			// SET_ENTITY_TYPE
			'player type = goat;',
			'self type = goat;',
			'entity Billy type = goat;',
			// SET_ENTITY_PATH
			'player path = goat;',
			'self path = goat;',
			'entity Billy path = goat;',
			// SET_ENTITY_DIRECTION
			'player direction = north;',
			'self direction = north;',
			'entity Billy direction = north;',
			// SET_ENTITY_LOOK_SCRIPT
			'player on_look = goatScript;',
			'self on_look = goatScript;',
			'entity Billy on_look = goatScript;',
			// SET_ENTITY_INTERACT_SCRIPT
			'player on_interact = goatScript;',
			'self on_interact = goatScript;',
			'entity Billy on_interact = goatScript;',
			// SET_ENTITY_TICK_SCRIPT
			'player on_tick = goatScript;',
			'self on_tick = goatScript;',
			'entity Billy on_tick = goatScript;',
			// SET_MAP_TICK_SCRIPT
			'map on_tick = goatScript;',
		],
	},
	set_bool_exp_ok: {
		input: [
			// SET_SAVE_FLAG
			'flagName = true;',
			// SET_HEX_EDITOR_STATE
			'hex_editor = true;',
			// SET_HEX_EDITOR_DIALOG_MODE
			'hex_dialog_mode = true;',
			// SET_HEX_EDITOR_CONTROL
			'hex_control = true;',
			// SET_HEX_EDITOR_CONTROL_CLIPBOARD
			'hex_clipboard = false;',
			// SET_SERIAL_DIALOG_CONTROL
			'serial_control = false;',
			// SET_PLAYER_CONTROL
			'player_control = false;',
			// SET_LIGHTS_CONTROL
			'lights_control = false;',
			// SET_LIGHTS_STATE
			'light MEM1 = true;',
			// SET_ENTITY_GLITCHED
			'entity Bob glitched = false;',
		],
	},
	set_bool_exp_ok_translations: {
		input: [
			'flagName = true;',
			'hex_editor = on;',
			'hex_dialog_mode = down;',
			'hex_control = open;',
			'hex_clipboard = false;',
			'serial_control = off;',
			'player_control = up;',
			'lights_control = closed;',
			'light MEM1 = on;',
			'entity Bob glitched = true;',
		],
		expected: [
			'flagName = true;',
			'hex_editor = true;',
			'hex_dialog_mode = true;',
			'hex_control = true;',
			'hex_clipboard = false;',
			'serial_control = false;',
			'player_control = false;',
			'lights_control = false;',
			'light MEM1 = true;',
			'entity Bob glitched = true;',
		],
	},
	bool_exp_branch_debug_mode: {
		input: [
			// CHECK_DEBUG_MODE
			'entity Bob glitched = debug_mode;',
			'entity Bob glitched = !debug_mode;',
			'entity Bob glitched = !(debug_mode);',
		],
		expected: [
			'if debug_mode then goto label if_*A*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity Bob glitched = true;',
			'rendezvous_*A*:',

			'if !debug_mode then goto label if_*B*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity Bob glitched = true;',
			'rendezvous_*B*:',

			'if !debug_mode then goto label if_*C*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity Bob glitched = true;',
			'rendezvous_*C*:',
		],
	},
	bool_exp_branch_dialog_open: {
		input: [
			// CHECK_DIALOG_OPEN
			'entity Bob glitched = dialog open;',
			'entity Bob glitched = !dialog open;',
			'entity Bob glitched = !(dialog open);',
			'entity Bob glitched = dialog closed;',
			'entity Bob glitched = !dialog closed;',
			'entity Bob glitched = !(dialog closed);',
		],
		expected: [
			'if dialog open then goto label if_*A*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity Bob glitched = true;',
			'rendezvous_*A*:',

			'if dialog closed then goto label if_*B*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity Bob glitched = true;',
			'rendezvous_*B*:',

			'if dialog closed then goto label if_*C*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity Bob glitched = true;',
			'rendezvous_*C*:',

			'if dialog closed then goto label if_*D*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*D*;',
			'if_*D*:',
			'entity Bob glitched = true;',
			'rendezvous_*D*:',

			'if dialog open then goto label if_*E*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*E*;',
			'if_*E*:',
			'entity Bob glitched = true;',
			'rendezvous_*E*:',

			'if dialog open then goto label if_*F*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*F*;',
			'if_*F*:',
			'entity Bob glitched = true;',
			'rendezvous_*F*:',
		],
	},
	bool_exp_branch_serial_dialog_open: {
		input: [
			// CHECK_SERIAL_DIALOG_OPEN
			'entity Bob glitched = serial_dialog open;',
			'entity Bob glitched = !serial_dialog open;',
			'entity Bob glitched = !(serial_dialog open);',
			'entity Bob glitched = serial_dialog closed;',
			'entity Bob glitched = !serial_dialog closed;',
			'entity Bob glitched = !(serial_dialog closed);',
		],
		expected: [
			'if serial_dialog open then goto label if_*A*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity Bob glitched = true;',
			'rendezvous_*A*:',

			'if serial_dialog closed then goto label if_*B*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity Bob glitched = true;',
			'rendezvous_*B*:',

			'if serial_dialog closed then goto label if_*C*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity Bob glitched = true;',
			'rendezvous_*C*:',

			'if serial_dialog closed then goto label if_*D*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*D*;',
			'if_*D*:',
			'entity Bob glitched = true;',
			'rendezvous_*D*:',

			'if serial_dialog open then goto label if_*E*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*E*;',
			'if_*E*:',
			'entity Bob glitched = true;',
			'rendezvous_*E*:',

			'if serial_dialog open then goto label if_*F*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*F*;',
			'if_*F*:',
			'entity Bob glitched = true;',
			'rendezvous_*F*:',
		],
	},
	bool_exp_branch_check_flag: {
		input: [
			// CHECK_SAVE_FLAG
			'entity Bob glitched = flagName;',
			'entity Bob glitched = !flagName;',
			'entity Bob glitched = !(flagName);',
		],
		expected: [
			'if "flagName" then goto label if_*A*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity Bob glitched = true;',
			'rendezvous_*A*:',

			'if !"flagName" then goto label if_*B*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity Bob glitched = true;',
			'rendezvous_*B*:',

			'if !"flagName" then goto label if_*C*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity Bob glitched = true;',
			'rendezvous_*C*:',
		],
	},
	bool_exp_branch_button_press: {
		input: [
			// CHECK_FOR_BUTTON_PRESS
			'entity Bob glitched = button MEM1 pressed;',
			'entity Bob glitched = !button MEM1 pressed;',
			'entity Bob glitched = !(button MEM1 pressed);',
		],
		expected: [
			'if button MEM1 pressed then goto label if_*A*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity Bob glitched = true;',
			'rendezvous_*A*:',

			'if !button MEM1 pressed then goto label if_*B*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity Bob glitched = true;',
			'rendezvous_*B*:',

			'if !button MEM1 pressed then goto label if_*C*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity Bob glitched = true;',
			'rendezvous_*C*:',
		],
	},
	bool_exp_branch_button_state: {
		input: [
			// CHECK_FOR_BUTTON_STATE
			'entity Bob glitched = button MEM1 down;',
			'entity Bob glitched = !button MEM1 down;',
			'entity Bob glitched = !(button MEM1 down);',
			'entity Bob glitched = button MEM1 up;',
			'entity Bob glitched = !button MEM1 up;',
			'entity Bob glitched = !(button MEM1 up);',
		],
		expected: [
			'if button MEM1 down then goto label if_*A*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity Bob glitched = true;',
			'rendezvous_*A*:',

			'if button MEM1 up then goto label if_*B*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity Bob glitched = true;',
			'rendezvous_*B*:',

			'if button MEM1 up then goto label if_*C*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity Bob glitched = true;',
			'rendezvous_*C*:',

			'if button MEM1 up then goto label if_*D*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*D*;',
			'if_*D*:',
			'entity Bob glitched = true;',
			'rendezvous_*D*:',

			'if button MEM1 down then goto label if_*E*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*E*;',
			'if_*E*:',
			'entity Bob glitched = true;',
			'rendezvous_*E*:',

			'if button MEM1 down then goto label if_*F*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*F*;',
			'if_*F*:',
			'entity Bob glitched = true;',
			'rendezvous_*F*:',
		],
	},
	bool_exp_branch_intersects: {
		input: [
			// CHECK_IF_ENTITY_IS_IN_GEOMETRY
			'entity Bob glitched = player intersects geometry BOX;',
			'entity Bob glitched = !player intersects geometry BOX;',
			'entity Bob glitched = !(player intersects geometry BOX);',
		],
		expected: [
			'if player intersects geometry "BOX" then goto label if_*A*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity Bob glitched = true;',
			'rendezvous_*A*:',

			'if !player intersects geometry "BOX" then goto label if_*B*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity Bob glitched = true;',
			'rendezvous_*B*:',

			'if !player intersects geometry "BOX" then goto label if_*C*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity Bob glitched = true;',
			'rendezvous_*C*:',
		],
	},
	bool_exp_branch_glitched: {
		input: [
			// CHECK_ENTITY_GLITCHED
			'entity Bob glitched = player glitched;',
			'entity Bob glitched = !player glitched;',
			'entity Bob glitched = !(player glitched);',
		],
		expected: [
			'if player glitched then goto label if_*A*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity Bob glitched = true;',
			'rendezvous_*A*:',

			'if !player glitched then goto label if_*B*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity Bob glitched = true;',
			'rendezvous_*B*:',

			'if !player glitched then goto label if_*C*;',
			'entity Bob glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity Bob glitched = true;',
			'rendezvous_*C*:',
		],
	},
	bool_exp_simple_or: {
		input: ['entity Bob glitched = debug_mode || isGoatGrumpy;'],
		expected: [
			'if debug_mode then goto label if_***;',
			'if "isGoatGrumpy" then goto label if_***;',
			'entity Bob glitched = false;',
			'goto label rendezvous_***;',
			'if_***:',
			'entity Bob glitched = true;',
			'rendezvous_***:',
		],
	},
	bool_exp_simple_and: {
		input: ['entity Bob glitched = debug_mode && isGoatGrumpy;'],
		expected: [
			'if debug_mode then goto label if_true_*A*;',
			'goto label rendezvous_*A*;',
			'if_true_*A*:',
			'if "isGoatGrumpy" then goto label if_true_*B*;',
			'rendezvous_*A*:',
			"entity 'Bob' glitched = false;",
			'goto label rendezvous_*Y*;',
			'if_true_*B*:',
			"entity 'Bob' glitched = true;",
			'rendezvous_*Y*:',
		],
	},
	bool_exp_invert_or: {
		input: ['entity Bob glitched = !(debug_mode || isGoatGrumpy);'],
		expected: [
			'if !debug_mode then goto label if_true_*A*;',
			'goto label rendezvous_*A*;',
			'if_true_*A*:',
			'if !"isGoatGrumpy" then goto label if_true_*B*;',
			'rendezvous_*A*:',
			"entity 'Bob' glitched = false;",
			'goto label rendezvous_*Y*;',
			'if_true_*B*:',
			"entity 'Bob' glitched = true;",
			'rendezvous_*Y*:',
		],
	},
	bool_exp_invert_and: {
		input: ['entity Bob glitched = !(debug_mode && isGoatGrumpy);'],
		expected: [
			'if !debug_mode then goto label if_true_*A*;',
			'if !"isGoatGrumpy" then goto label if_true_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*Y*;',
			'if_true_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*Y*:',
		],
	},
	set_int_exp_not_ok: {
		input: [
			// SET_ENTITY_X
			'player x = 1;',
			// SET_ENTITY_Y
			'player y = 1;',
			// SET_ENTITY_PRIMARY_ID
			'player primary_id = 1;',
			// SET_ENTITY_SECONDARY_ID
			'player secondary_id = 1;',
			// SET_ENTITY_PRIMARY_ID_TYPE
			'player primary_id_type = 1;',
			// SET_ENTITY_CURRENT_ANIMATION
			'player current_animation = 1;',
			// SET_ENTITY_CURRENT_FRAME
			'player animation_frame = 1;',
			// SET_ENTITY_MOVEMENT_RELATIVE
			'player strafe = 1;',
			// SET_ENTITY_DIRECTION_RELATIVE
			// TODO: ??????????????
		],
	},
	set_int_exp_ok: {
		input: [
			// MUTATE_VARIABLES
			'"bothVarsAre" = "ambiguous";', // and that's ok

			// MUTATE_VARIABLE
			'"goatCount" = 0;',

			// COPY_VARIABLE
			'"goatCount" = player x;',
			'player y = "goatCount";',
		],
	},
	int_exp_chain_literal_getable: {
		input: ['goatCount = 1 + player x;'],
		expected: [
			'goatCount = 1;',
			'*A* = player x;',
			'goatCount += *A*;',
			// '*A* = 1;',
			// '*B* = player x;',
			// '*A* += *B*;',
			// '"goatCount" = *A*;',
		],
	},
	int_exp_chain_getable_getable: {
		input: ['goatCount = player y + player x;'],
		expected: [
			'"goatCount" = player y;',
			'*A* = player x;',
			'"goatCount" += *A*;',
			// '*A* = player y;',
			// '*B* = player x;',
			// '*A* += *B*;',
			// '"goatCount" = *A*;',
		],
	},
	int_exp_chain_literal_getable_mult: {
		input: ['goatCount = 1 + player x * 99;'],
		expected: [
			'"goatCount = 1;',
			'*A* = player x;',
			'*A* *= 99;',
			'"goatCount += *B*;',
			// '*A* = 1;',
			// '*B* = player x;',
			// '*B* *= 99;',
			// '*A* += *B*;',
			// '"goatCount" = *A*;',
		],
	},
	int_exp_chain_literal_getable_mult_parens: {
		input: ['goatCount = (1 + player x) * 99;'],
		expected: [
			'"goatCount" = 1;',
			'*A* = player x;',
			'"goatCount" += *A*;',
			'"goatCount" *= 99;',
		],
	},
	ambiguous_bool_single_invert: {
		input: ['goatCount = !notAmbiguous;'],
		expected: [
			'if !"notAmbiguous" then goto label if_***;',
			'"goatCount" = false;',
			'goto label rendezvous_***;',
			'if_***:',
			'"goatCount" = true;',
			'rendezvous_***:',
		],
	},
	ambiguous_bool_disambiguate: {
		input: ['goatCount = !!notAmbiguous;'],
		expected: [
			'if "notAmbiguous" then goto label if_***;',
			'"goatCount" = false;',
			'goto label rendezvous_***;',
			'if_***:',
			'"goatCount" = true;',
			'rendezvous_***:',
		],
	},
	int_expression_invert_comparison_lt: {
		input: ['entity Bob glitched = intName < 6;', 'entity Bob glitched = !(intName < 6);'],
		expected: [
			'if "intName" < 6 then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if "intName" >= 6 then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',
		],
	},
	int_expression_invert_comparison_lteq: {
		input: ['entity Bob glitched = intName <= 6;', 'entity Bob glitched = !(intName <= 6);'],
		expected: [
			'if "intName" <= 6 then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if "intName" > 6 then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',
		],
	},
	int_expression_invert_comparison_gt: {
		input: ['entity Bob glitched = intName > 6;', 'entity Bob glitched = !(intName > 6);'],
		expected: [
			'if "intName" > 6 then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if "intName" <= 6 then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',
		],
	},
	int_expression_invert_comparison_gteq: {
		input: ['entity Bob glitched = intName >= 6;', 'entity Bob glitched = !(intName >= 6);'],
		expected: [
			'if "intName" >= 6 then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if "intName" < 6 then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',
		],
	},
	int_expression_invert_comparison_eq: {
		input: ['entity Bob glitched = intName == 6;', 'entity Bob glitched = !(intName == 6);'],
		expected: [
			'if "intName" == 6 then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if "intName" != 6 then goto label if_*C*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*C*:',
		],
	},
	int_expression_invert_comparison_noteq: {
		input: ['entity Bob glitched = intName != 6;', 'entity Bob glitched = !(intName != 6);'],
		expected: [
			'if "intName" != 6 then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',

			'if "intName" == 6 then goto label if_*D*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*D*;',
			'if_*D*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*D*:',
		],
	},
	branch_on_string_equality_warp_state: {
		input: [
			'entity Bob glitched = warp_state == "landing";',
			'entity Bob glitched = !(warp_state == "landing");',
			'entity Bob glitched = warp_state != "landing";',
		],
		expected: [
			'if warp_state == "landing" then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if warp_state != "landing" then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',

			'if warp_state != "landing" then goto label if_*C*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*C*:',
		],
	},
	branch_on_string_equality_name: {
		input: [
			'entity Bob glitched = player name == goat;',
			'entity Bob glitched = !(player name == goat);',
			'entity Bob glitched = player name != goat;',
		],
		expected: [
			'if player name == "goat" then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if player name != "goat" then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',

			'if player name != "goat" then goto label if_*C*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*C*:',
		],
	},
	branch_on_string_equality_type: {
		input: [
			'entity Bob glitched = player type == goat;',
			'entity Bob glitched = !(player type == goat);',
			'entity Bob glitched = player type != goat;',
		],
		expected: [
			'if player type == "goat" then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if player type != "goat" then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',

			'if player type != "goat" then goto label if_*C*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*C*:',
		],
	},
	branch_on_string_equality_interact: {
		input: [
			'entity Bob glitched = player on_interact == goat;',
			'entity Bob glitched = !(player on_interact == goat);',
			'entity Bob glitched = player on_interact != goat;',
		],
		expected: [
			'if player on_interact == "goat" then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if player on_interact != "goat" then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',

			'if player on_interact != "goat" then goto label if_*C*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*C*:',
		],
	},
	branch_on_string_equality_tick: {
		input: [
			'entity Bob glitched = player on_tick == goat;',
			'entity Bob glitched = !(player on_tick == goat);',
			'entity Bob glitched = player on_tick != goat;',
		],
		expected: [
			'if player on_tick == "goat" then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if player on_tick != "goat" then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',

			'if player on_tick != "goat" then goto label if_*C*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*C*:',
		],
	},
	branch_on_string_equality_look: {
		input: [
			'entity Bob glitched = player on_look == goat;',
			'entity Bob glitched = !(player on_look == goat);',
			'entity Bob glitched = player on_look != goat;',
		],
		expected: [
			'if player on_look == "goat" then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if player on_look != "goat" then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',

			'if player on_look != "goat" then goto label if_*C*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*C*:',
		],
	},
	branch_on_string_equality_direction: {
		input: [
			'entity Bob glitched = player direction == north;',
			'entity Bob glitched = !(player direction == east);',
			'entity Bob glitched = player direction != south;',
		],
		expected: [
			'if player direction == north then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if player direction != east then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',

			'if player direction != south then goto label if_*C*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*C*:',
		],
	},
	branch_on_string_equality_direction: {
		input: [
			'entity Bob glitched = player path == longWalk;',
			'entity Bob glitched = !(player path == longWalk);',
			'entity Bob glitched = player path != longWalk;',
		],
		expected: [
			'if player path == "longWalk" then goto label if_*A*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*A*;',
			'if_*A*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*A*:',

			'if player path != "longWalk" then goto label if_*B*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*B*;',
			'if_*B*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*B*:',

			'if player path != "longWalk" then goto label if_*C*;',
			'entity "Bob" glitched = false;',
			'goto label rendezvous_*C*;',
			'if_*C*:',
			'entity "Bob" glitched = true;',
			'rendezvous_*C*:',
		],
	},
	while_simple: {
		input: ['while (player glitched) { wait 1; }'],
		expected: [
			'while_condition_***:',
			'if player glitched then goto label while_body_***;',
			'goto label while_rendezvous_***;',
			'while_body_***:',
			'wait 1ms;',
			'goto label while_condition_***;',
			'while_rendezvous_***:',
		],
	},
	number_comparison: {
		input: ['player_control = 7 < 5;', 'player_control = 7 == 7;', 'player_control = 7 != 5;'],
		expected: ['player_control = false;', 'player_control = true;', 'player_control = true;'],
	},
	spread_simple: {
		input: ['wait [1ms, 2ms];', '[player x, self y] = [10, intName];'],
		expected: ['wait 1ms;', 'wait 2ms;', 'player x = 10;', 'self y = intName;'],
	},
	rand_simple: {
		input: [
			'rand!(',
			'	wait [1ms, 2ms];',
			'	close dialog;',
			'	[player x, self y] = [10, intName];',
			')',
		],
		expected: [
			'"__TEMP_0" ?= 2;',
			'if "__TEMP_0" == 0 then goto label if_RNG_*A*;',
			'if "__TEMP_0" == 1 then goto label if_RNG_*B*;',
			'if_RNG_*B*:',
			'wait 2ms;',
			'close dialog',
			'self y = intName;',
			'goto label rendezvous_*C*;',
			'if_RNG_*A*:',
			'wait 1ms;',
			'close dialog',
			'player x = 10;',
			'rendezvous_*C*:',
		],
	},
	silence_warning_bodge: {
		input: [
			'intName = intName2+0;',
			'intName = intName2-0;',
			'intName = intName2*1;',
			'intName = intName2/1;',
		],
		expected: [
			// originally yielded:
			// '"__TEMP_0" = "intName2";',
			// '"__TEMP_0" += 0;',
			// '"intName" = "__TEMP_0";',
			'"intName" = "intName2";',
			'"intName" = "intName2";',
			'"intName" = "intName2";',
			'"intName" = "intName2";',
		],
	},
};

// --------------------------- FILE-LEVEL TESTS ---------------------------
const fileMap =
	onlyDoTheseActionTests.length !== 0
		? {}
		: {
				'header.mgs': {
					fileText: `
						$magicNumber = 76;
					`,
					expected: {
						scripts: {},
						constants: {
							$magicNumber: { fileName: 'header.mgs', value: 76 },
						},
					},
				},
				'constants_include.mgs': {
					fileText: `
						include "header.mgs";
						$trombones = $magicNumber;
						$hamburgers = "steamed hams";
						"constants" {
							player x = $trombones;
							warp_state = $hamburgers;
						}
					`,
					expected: {
						scripts: {
							constants: `"constants" {
								player x = 76;
								warp_state = "steamed hams";
							}`,
						},
						constants: {
							$magicNumber: { fileName: 'header.mgs', value: 76 },
							$trombones: { fileName: 'constants_include.mgs', value: 76 },
							$hamburgers: {
								fileName: 'constants_include.mgs',
								value: 'steamed hams',
							},
						},
					},
				},
				'basic_dialog.mgs': {
					fileText: `dialog "bobIntro" {
						Bob "Well, hi there!"
						Jackob "Oh!"
					}`,
					expected: {
						dialogs: {
							bobIntro: {
								dialogs: [
									{
										entity: 'Bob',
										alignment: 'BOTTOM_LEFT',
										messages: ['Well, hi there!'],
									},
									{
										alignment: 'BOTTOM_LEFT',
										entity: 'Jackob',
										messages: ['Oh!'],
									},
								],
							},
						},
					},
				},
				// 'dialog_error_wrap.mgs': {
				// 	fileText: `dialog "tooLong" {
				// 		Bob wrap 20
				// 		"ACK!\n\nA goat! Oh, I guess I need to make sure this thing wraps. Let's see. How many chars can this be?"
				// 	}`,
				// 	expected: {
				// 		warningCount: 1,
				// 		dialogs: {
				// 			tooLong: {
				// 				dialogs: [
				// 					{
				// 						entity: "Bob",
				// 						alignment: "BOTTOM_LEFT",
				// 						messages: [
				// 							'ACK!\n\nA goat! Oh, I guess\nI need to make sure\nthis thing wraps.\nLet\'s see. How many\nchars can this be?',
				// 						],
				// 					},
				// 				],
				// 			},
				// 		},
				// 	},
				// },
				'dialog_wrapping.mgs': {
					fileText: `dialog "wrapBasics" {
						Bob wrap 20
						"12345678901234567890"
						"123456789012\\%4567890"
						"123456789012\\%45678901"
						"123456789012\\% 567890"
						"123456789012\\% 5678901"
						"%12% a b c d e f g h"
						"%1234% a b c d e f g h"
						"%123456% a b c d e f g h"
						"%12345678% a b c d e f g h"
						"%1234567890% a b c d e f g h"
						"$1$ a b c d e f g h"
						"$123$ a b c d e f g h"
						"$12345$ a b c d e f g h"
						"$1234567$ a b c d e f g h"
						"$123456789$ a b c d e f g h"
					}`,
					expected: {
						dialogs: {
							wrapBasics: {
								dialogs: [
									{
										entity: 'Bob',
										alignment: 'BOTTOM_LEFT',
										messages: [
											'12345678901234567890',
											'123456789012\\%4567890',
											'123456789012\\%45678901',
											'123456789012\\% 567890',
											'123456789012\\%\n5678901',
											'%12% a b c d\ne f g h',
											'%1234% a b c d\ne f g h',
											'%123456% a b c d\ne f g h',
											'%12345678% a b c d\ne f g h',
											'%1234567890% a b c d\ne f g h',
											'$1$ a b c d e f g\nh',
											'$123$ a b c d e f g\nh',
											'$12345$ a b c d e f g\nh',
											'$1234567$ a b c d e f g\nh',
											'$123456789$ a b c d e f g\nh',
										],
									},
								],
							},
						},
					},
				},
			};
const fileTestNames = onlyDoTheseActionTests.length === 0 ? Object.keys(fileMap) : [];

// --------------------------- Putting all the tests into a "project" ---------------------------

const actionTestNames = (
	onlyDoTheseActionTests.length === 0 ? Object.keys(actionTests) : onlyDoTheseActionTests
).filter((testName) => !skipTheseTests.has(testName));

fileMap['actionTests.mgs'] = {
	fileText: actionTestNames
		.filter((testName) => !skipTheseTests.has(testName))
		.map((testName) => {
			const v = actionTests[testName];
			return actionArrayToScript(testName, v.input);
		})
		.join('\n\n'),
	expected: {
		scripts: {},
	},
};
actionTestNames.forEach((testName) => {
	const data = actionTests[testName];
	const expectedArr = data.expected ? data.expected : data.input;
	const expectedPrint = actionArrayToScript(testName, expectedArr, true);
	fileMap['actionTests.mgs'].expected.scripts[testName] = expectedPrint;
});

const colorDifferentStrings = (expected, found) => {
	const diff = [];
	const foundChars = found.split('');
	let colored = false;
	for (let i = 0; i < foundChars.length; i++) {
		const c = foundChars[i];
		if (c !== expected[i] && !colored) {
			diff.push(ansiTags.yellow);
			colored = true;
		}
		diff.push(c);
	}
	return diff.join('') + ansiTags.reset;
};
const sanitize = (str) => str.replace(/([\{\}\[\]\(\)\.\$\|\+\-\*\/])/g, '\\$1');
const makeTextUniform = (text) =>
	text
		.trim()
		.replace(/[\t ]+/g, ' ')
		.replace(/\/\/.*?[\n$]/g, '');
const compareTexts = (_found, _expected, fileName, thingName) => {
	const foundLines = makeTextUniform(_found)
		.replaceAll('+=', '+\n=')
		.replaceAll('-=', '-\n=')
		.replaceAll('*=', '*\n=')
		.replaceAll('/=', '/\n=')
		.replaceAll('?=', '?\n=')
		.replaceAll('%=', '%\n=')
		.split(/\n/g)
		.map((v) => v.trim())
		.filter((v) => !!v);
	const expectedLines = makeTextUniform(_expected)
		.replaceAll('+=', '+\n=')
		.replaceAll('-=', '-\n=')
		.replaceAll('*=', '*\n=')
		.replaceAll('/=', '/\n=')
		.replaceAll('?=', '?\n=')
		.replaceAll('%=', '%\n=')
		.split(/\n/g)
		.map((v) => v.trim())
		.filter((v) => !!v);
	if (foundLines.length !== expectedLines.length) {
		expectedLines.unshift('EXPECTED');
		foundLines.unshift('FOUND');
		const maxLength = expectedLines.reduce(
			(acc, curr) => Math.max(acc, curr.length),
			-Infinity,
		);
		const flushLines = expectedLines.map((s) => '   ' + s.padEnd(maxLength + 4, ' '));
		const comboLines = flushLines.map((left, i) => {
			let right = foundLines[i] || '';
			if (expectedLines[i] !== right) {
				right = ansiTags.yellow + right + ansiTags.reset;
			}
			return left + right;
		});
		for (let i = comboLines.length; i < foundLines.length; i++) {
			const left = ' '.repeat(maxLength + 4);
			const right = foundLines[i];
			comboLines.push(left + right);
		}
		return {
			status: 'fail',
			message: thingName + ': different line counts',
			lengthDiff: comboLines,
		};
	}
	const lines = [];
	const registeredLabels = {};
	foundLines.forEach((found, i) => {
		const expected = expectedLines[i];
		if (expected === found) {
			return;
		}
		// registering specific wildcards
		const wild = expected.match(/(.*)(\*[A-Z]+\*)(.*)/);
		if (wild) {
			const sanitary = wild.map(sanitize);
			const pattern = new RegExp(`${sanitary[1]}([\\da-zA-Z_"]+)${sanitary[3]}`);
			const label = sanitary[2];
			const capture = found.match(pattern);
			if (capture) {
				if (!registeredLabels[label]) {
					registeredLabels[label] = capture[1];
				} else if (registeredLabels[label] !== capture[1]) {
					const diff = wild[1] + ansiTags.yellow + capture[1] + wild[3];
					lines.push({
						expected,
						found,
						diff,
						value: capture[1],
						fileName,
						lineIndex: i,
					});
				}
				return;
			}
		}
		// wild wildcards
		const clean = sanitize(expected).replaceAll('\\*\\*\\*', '.+?');
		const regExpected = new RegExp(clean);
		if (found.match(regExpected)) {
			return;
		}
		if (found.replace(/"|'/g, '') === expected.replaceAll(/"|'/g, '')) {
			return;
		}
		// or they really are different
		const diff = colorDifferentStrings(expected, found);
		lines.push({
			expected,
			found,
			diff,
			fileName,
			lineIndex: i,
		});
	});
	if (lines.length) {
		return {
			status: 'fail',
			message: `${thingName}: mismatched lines`,
			lines: lines.map((v) => {
				if (v.value) {
					let registered;
					Object.entries(registeredLabels).forEach(([k, val]) => {
						if (val === v.value) {
							registered = k;
						}
					});
					v.diff += ` (${registered})`;
				}
				return v;
			}),
		};
	} else {
		return {
			status: 'success',
		};
	}
};

const errors = [];

// --------------------------- Other diagnostics ---------------------------

// Borrowed from an earlier iteration of mathlang
const simplifyValues = (lh, rh) => {
	if (lh === null) return simplifyLiteral(lh, rh);
	if (Array.isArray(lh)) return simplifyArrays(lh, rh);
	if (typeof lh === 'object') return simplifyObjects(lh, rh);
	return simplifyLiteral(lh, rh);
};
const simplifyLiteral = (lh, rh) => {
	const red = ansiTags.red + JSON.stringify(rh) + ansiTags.reset;
	const diff = lh === rh ? rh : red + ` (expected ${colorDifferentStrings(rh || '', lh || '')})`;
	return { lh, rh, diff };
};
const simplifyArrays = (origLH = [], origRH = []) => {
	const newLH = [];
	const newRH = [];
	const newDiffs = [];
	origLH.forEach((left, i) => {
		const right = origRH[i];
		if (Array.isArray(left)) {
			const { lh, rh, diff } = simplifyArrays(left, right);
			newLH.push(lh);
			newRH.push(rh);
			newDiffs.push(diff);
		} else if (typeof left === 'object') {
			const { lh, rh, diff } = simplifyObjects(left, right);
			newLH.push(lh);
			newRH.push(rh);
			newDiffs.push(diff);
		} else {
			const { lh, rh, diff } = simplifyLiteral(left, right);
			newLH.push(lh);
			newRH.push(rh);
			newDiffs.push(diff);
		}
	});
	return { lh: newLH, rh: newRH, diff: newDiffs };
};
const simplifyObjects = (origLH = {}, origRH = {}) => {
	delete origLH.debug;
	delete origRH.debug;
	const sortedLH = {};
	const sortedRH = {};
	const sortedDiff = {};
	Object.keys(origLH)
		.sort()
		.forEach((k) => {
			if (origLH[k] === null) {
				const { lh, rh, diff } = simplifyLiteral(origLH[k], origRH[k]);
				sortedLH[k] = lh;
				sortedRH[k] = rh;
				sortedDiff[k] = diff;
			} else if (Array.isArray(origLH[k])) {
				const { lh, rh, diff } = simplifyArrays(origLH[k], origRH[k]);
				sortedLH[k] = lh;
				sortedRH[k] = rh;
				sortedDiff[k] = diff;
			} else if (typeof origLH[k] === 'object') {
				const { lh, rh, diff } = simplifyObjects(origLH[k], origRH[k]);
				sortedLH[k] = lh;
				sortedRH[k] = rh;
				sortedDiff[k] = diff;
			} else {
				const { lh, rh, diff } = simplifyLiteral(origLH[k], origRH[k]);
				sortedLH[k] = lh;
				sortedRH[k] = rh;
				sortedDiff[k] = diff;
			}
		});
	return { lh: sortedLH, rh: sortedRH, diff: sortedDiff };
};
const reportObjectDiffs = (expected, found) => {
	const messages = [];
	const { lh, rh, diff } = simplifyValues(expected, found);
	const jsonLeft = JSON.stringify(lh, null, '  ');
	const jsonRight = JSON.stringify(rh, null, '  ');
	if (jsonLeft !== jsonRight) {
		if (typeof lh === 'object') {
			const message = `Found ${JSON.stringify(diff, null, '  ')}`;
			messages.push(message);
		} else {
			const message = `Found ${ansiTags.red}${key}: ${jsonRight}${ansiTags.reset}, expected value ${ansiTags.yellow}${jsonLeft}${ansiTags.reset}`;
			messages.push(message);
		}
	}
	return messages.map((s) => s.replaceAll('\\u001b', '\u001b'));
};

const compareConstants = (fileName, _found, _expected) => {
	const errors = [];
	const foundKeys = Object.keys(_found);
	const expectedKeys = Object.keys(_expected);
	expectedKeys.forEach((k) => {
		if (!foundKeys.includes(k)) {
			errors.push({
				status: 'fail',
				message: `${fileName}: Did not find expected constant '${k}'`,
			});
		}
	});
	foundKeys.forEach((k) => {
		if (!expectedKeys.includes(k)) {
			errors.push({
				status: 'fail',
				message: `${fileName}: Found unexpected constant '${k}'`,
			});
			return; // quit exploring this constant
		}
		const found = _found[k];
		const expected = _expected[k];
		const comparedErrors = reportObjectDiffs(expected, found);
		comparedErrors.forEach((string) => {
			errors.push({
				status: 'fail',
				message: `${fileName} constants values do not match:\n${string}`,
			});
		});
	});
	return errors;
};
const compareDialogs = (fileName, dialogName, expectedDialogs, foundDialogs) => {
	const errors = [];
	if (expectedDialogs.length !== foundDialogs.length) {
		return [
			{
				status: 'fail',
				message: `${fileName}: differing dialog quantity for ${dialogName}`,
			},
		];
	}
	expectedDialogs.forEach((expected, i) => {
		const found = foundDialogs[i];
		const diffs = reportObjectDiffs(expected, found);
		if (diffs.length) {
			errors.push({
				type: 'fail',
				message: `${fileName}: dialog "${dialogName}" [${i}] mismatch\n${diffs.join('\n')}`,
			});
		}
	});
	return errors;
};

// --------------------------- THE OWL ---------------------------

/*
variant   | labels | indices | copyscript | flattened gotos
----------+--------+---------+------------+----------------
prePrint  |  yes   |         |            |      yes
testPrint |  yes   |         |    yes     |      yes
print     |        |   yes   |    yes     |      yes

Is there a better way?
*/

const doActionTest = (scriptName, actionExpected, actionFound) => {
	const expected = actionExpected[scriptName];
	const found = actionFound[scriptName].print;
	const compared = compareTexts(found, expected, '', scriptName);
	if (compared.status !== 'success') {
		return compared;
	}
	return null;
};

const runTests = async () => {
	parseProject(fileMap, {}).then((result) => {
		// ACTION TESTS
		const actionsExpected = fileMap['actionTests.mgs'].expected.scripts;
		const actionsFound = result.scripts;
		const actionErrors = actionTestNames
			.map((v) => doActionTest(v, actionsExpected, actionsFound))
			.filter((v) => v !== null);
		errors.push(...actionErrors);

		// FILE TESTS
		if (onlyDoTheseActionTests.length === 0) {
			fileTestNames.forEach((fileName) => {
				// Scripts
				const fileExpectedData = fileMap[fileName].expected || {};
				const fileFoundP = fileMap[fileName].parsed;
				const fileScriptNames = Object.keys(fileExpectedData.scripts || {});
				const allScripts = result.scripts;
				fileScriptNames.forEach((scriptName) => {
					const expected = fileExpectedData.scripts[scriptName].trim();
					const found = allScripts[scriptName].print.trim();
					const compared = compareTexts(found, expected, '', scriptName);
					if (compared.status !== 'success') {
						errors.push(compared);
					}
				});

				// Constants
				const constantsDiffs = compareConstants(
					fileName,
					fileFoundP.constants || {},
					fileExpectedData.constants || {},
				);
				if (constantsDiffs.length) {
					errors.push(...constantsDiffs);
				}

				// Dialogs
				const allDialogs = result.dialogs;
				const expectedDialogs = fileExpectedData.dialogs || {};
				const dialogNames = Object.keys(expectedDialogs) || {};
				dialogNames.forEach((dialogName) => {
					const expected = expectedDialogs[dialogName].dialogs || {};
					const found = allDialogs[dialogName].dialogs || {};
					const compared = compareDialogs(fileName, dialogName, expected, found);
					compared.forEach((err) => {
						errors.push(err);
					});
				});

				// Warningcount
				const foundWarningCount = fileFoundP.warningCount;
				const expectedWarningCount = fileExpectedData.warningCount || 0;

				if (foundWarningCount !== expectedWarningCount) {
					errors.push({
						status: 'fail',
						message:
							`${fileName}: Found ${foundWarningCount} warning(s), ` +
							`expected ${expectedWarningCount}`,
					});
				}
			});
		}

		// PROBLEMS
		errors.forEach((error) => {
			console.error('\n' + error.message);
			if (error.lines) {
				error.lines.forEach((v) => {
					console.error(`   Found: ${v.diff}`);
					console.error(`Expected: ${v.expected}`);
				});
			}
			if (error.lengthDiff) {
				console.error(error.lengthDiff.join('\n'));
			}
		});

		// DONE
		if (errors.length === 0) {
			console.log(`All (${actionTestNames.length}) tests good, chief!`);
		}
		console.log('BREAKPOINT HERE');
	});
};

runTests();
