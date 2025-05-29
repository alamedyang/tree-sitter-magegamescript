const fs = require('node:fs');

const file = `include!("header.mgs")

on_load-woprhouse {
	if (flag tuesdayd is true) {
		register rtfm -> command-rtfm;
	}
	if (variable current-chapter is 2) {
		// entrance text
		show serial dialog spacer;
		show serial dialog { "Entering <bold>WOPR ROOM</>..." }
		copy ch2-map-init;
	}
	if (flag wopr-backdoor-found is false) {
		turn player control off;
		set flag wopr-backdoor-found to true;
		if (warp state is not warped) {
			walk entity "%PLAYER%" along geometry walk_from-north over 600ms;
		}
		wait 400ms;
		show dialog {
			PLAYER "Whoa! It looks like I found some kind of back door."
		}
		turn player control on;
	}
}

/* ---------- ON_TICK ---------- */

on_tick-woprhouse {
	if entity "%PLAYER%" is inside geometry north-hitbox
		then goto on_walk-woprhouse-north;
}

/* ---------- EXIT STUFF ---------- */

on_walk-woprhouse-north {
	// triggered by map's on_tick
	if (variable current-chapter is 1) {
		set warp state to exit_from-woprhouse;
		load map main;
	} else if (variable current-chapter is 2) {
		set warp state to walk_from-woprhouse;
		load map ch2-town;
	} else {
		show serial dialog spacer;
		show serial dialog {
			"<r>ERROR:</> You're in chapter '$current-chapter$'??"
			"Back to the main menu for you!"
		}
		load map main_menu;
	}
}

on_go-woprhouse-north {
	copy warping-out-fade-out;
	load map ch2-town;
}

/* ---------- ENTITIES ---------- */

show_dialog-wopr-start {
	show dialog {
		SELF portrait wopr
		"SHALL WE PLAY A GAME?"

		SELF portrait wopr
		"PLAY?"
		> "DO NOT PLAY" : goto "restart-wopr"
	}
}
restart-wopr {
	set entity "%SELF%" on_interact to show_dialog-wopr-start;
}

show_dialog-woprbooks {
	show dialog {
		PLAYER "These shelves are full of Vogon poetry! What an odd sort of thing for a computer to collect."
	}
}
`;

const replaced = file
	.replace(/include!\((.+?)\)/g, 'include $1;') // include_macro

	// generic or preparatory
	.replace(/goto( script)? ("?)([^;]+)(\2)/g, 'goto "$3"') // goto (script)
	.replace(/serial dialog/g, 'serial_dialog') // serial dialog -> serial_dialog
	// .replace(/(->|:) (goto)?("?)([^;]+)(\3)/g, '= "$4"') // other script refs
	.replace( // bareword -> "bareword"
		/(entity|geometry|map|flag|variable|mutate) ("?)([-_a-zA-Z0-9]+)(\2)/g,
		'$1 "$3"'
	)
	.replace( // scriptName { -> "scriptName" {
		/(^|\n)([-_A-Z0-9a-z]+) {\n/g,
		'$1"$2" {\n'
	)
	.replace( // dialog bareword { -> dialog "bareword" {
		/dialog ([-_A-Z0-9a-z]+?)( {\n|;)/g,
		'dialog "$1"$2'
	)
	.replace( // (serial) dialog options
		/(>|_|#) (.+?) :( goto)?( script)? ([^\n]+)/g,
		'$1 $2 = $5'
	)
	.replace(
		/(\t+)if (.+)[\s]+then (goto [^;\n]+)(;?)(\n|$)/g,
		`$1if ($2) {\n$1\t$3;\n$1}$5`
	)

	// Miscellaneous
	// SLOT_SAVE -- ok as is
	// SLOT_LOAD -- ok as is
	// SLOT_ERASE -- ok as is
	// LOAD_MAP -- ok as is
	// BLOCKING_DELAY -- ok as is
	// NON_BLOCKING_DELAY -- ok as is
	.replace( // SHOW_DIALOG
		/show dialog ([^}]+)}/g,
		'show dialog $1};'
	)
	// CLOSE_DIALOG -- ok as is
	.replace( // SHOW_SERIAL_DIALOG
		/show serial_dialog ([^}]+)}/g,
		'show serial_dialog $1};'
	)
	// CLOSE_SERIAL_DIALOG -- ok as is
	// SET_SCRIPT_PAUSE
	// [TODO]
	// GOTO_ACTION_INDEX -- ok as is? (todo: check)
	// RUN_SCRIPT -- ok as is

	// Commands and aliases
	.replace( // REGISTER_SERIAL_DIALOG_COMMAND
		/register ("?)([^\n;]+)(\1)( fail)? ->( goto)?( script)? ("?)([^\n;]+)(\7)/g,
		'command "$2" $4= "$8"'
	)
	.replace( // UNREGISTER_SERIAL_DIALOG_COMMAND
		/unregister ("?)([^\n;]+)(\1)( fail)?/g,
		'delete command "$2" $4'
	)
	.replace( // REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
		/register ("?)(.+?)(\1) + ("?)([^\n;]+)(\4) ->( goto)?( script)? ("?)([^\n;]+)(\7)/g,
		'command "$2" + "$5" = "$8"'
	)
	.replace( // UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
		/unregister ("?)(.+?)(\1) + ("?)([^\n;]+)(\4)/g,
		'delete command "$2" + "$5"'
	)
	// REGISTER_SERIAL_DIALOG_COMMAND_ALIAS -- ok as is
	.replace( // REGISTER_SERIAL_DIALOG_COMMAND_ALIAS
		/unregister alias ("?)([^\n;])(\1)/g,
		'delete alias "$2"'
	)
	// SET_SERIAL_DIALOG_COMMAND_VISIBILITY -- ok as is


	// Set position
	.replace( // SET_CAMERA_TO_FOLLOW_ENTITY
		/make camera follow entity ([^;\n]+)/g,
		'camera = entity $1 position'
	)
	.replace( // TELEPORT_CAMERA_TO_GEOMETRY
		/teleport camera to geometry ([^;\n]+)/g,
		'camera = geometry $1'
	)
	.replace( // TELEPORT_ENTITY_TO_GEOMETRY
		/teleport entity (.+?) to geometry ([^;\n]+)/g,
		'entity $1 position = geometry $2'
	)
	.replace( // SET_ENTITY_DIRECTION_TARGET_ENTITY
		/turn entity (.+?) toward entity ([^;\n]+)/g,
		'entity $1 direction = entity $2'
	)
	.replace( // SET_ENTITY_DIRECTION_TARGET_GEOMETRY
		/turn entity (.+?) toward geometry ([^;\n]+)/g,
		'entity $1 direction = geometry $2'
	)
	
	// Set position over time
	.replace( // WALK_ENTITY_TO_GEOMETRY
		/walk entity (.+?) to geometry (.+?) over ([0-9ms]+)/g,
		'entity $1 position -> geometry $2 origin over $3'
	)
	.replace( // WALK_ENTITY_ALONG_GEOMETRY
		/walk entity (.+?) along geometry (.+?) over ([0-9ms]+)/g,
		'entity $1 position -> geometry $2 length over $3'
	)
	.replace( // LOOP_ENTITY_ALONG_GEOMETRY
		/loop entity (.+?) along geometry (.+?) over ([0-9ms]+)/g,
		'entity $1 position -> geometry $2 length over $3 forever'
	)
	.replace( // PAN_CAMERA_TO_ENTITY
		/pan camera to entity (.+?) over ([0-9ms]+)/g,
		'camera -> entity $1 position over $2'
	)
	.replace( // PAN_CAMERA_TO_GEOMETRY
		/pan camera to geometry (.+?) over ([0-9ms]+)/g,
		'camera -> geometry $1 origin over $2'
	)
	.replace( // PAN_CAMERA_ALONG_GEOMETRY
		/pan camera along geometry (.+?) over ([0-9ms]+)/g,
		'camera -> geometry $1 length over $2'
	)
	.replace( // LOOP_CAMERA_ALONG_GEOMETRY
		/loop camera along geometry (.+?) over ([0-9ms]+)/g,
		'camera -> geometry $1 length over $2 forever'
	)
	
	// Other do over time
	.replace( // SET_SCREEN_SHAKE
		/shake camera ([0-9ms]+) ([0-9pix]+) for ([0-9ms]+)/g,
		'camera shake -> $1 $2 over $3;'
	)
	.replace( // SCREEN_FADE_IN, SCREEN_FADE_OUT
		/fade (out|in) camera (to|from) (.+?) over ([0-9ms]+)/g,
		'camera fade $1 -> $3 over $4'
	)
	.replace( // PLAY_ENTITY_ANIMATION
		/play entity (.+?) animation ([0-9]+) ([0-9]+x?|once|twice|thrice)/g,
		'entity $1 animation -> $2 $3'
	)

	// Set string
	.replace( // SET_WARP_STATE
		/set warp state to ("?)([^\n;]+)(\1)/g,
		'warp_state = "$2"'
	)
	.replace( // SET_ENTITY_DIRECTION
		/turn entity (.+?) (north|south|east|west)/g,
		'entity $1 direction = $2'
	)
	// SET_ENTITY_NAME
	// SET_ENTITY_TYPE
	// SET_ENTITY_PATH
	// SET_ENTITY_LOOK_SCRIPT
	// SET_ENTITY_INTERACT_SCRIPT
	// SET_ENTITY_TICK_SCRIPT
	.replace(
		/set entity (.+?) (name|type|path|on_interact|on_tick|on_look) to ("?)([^;\n]+)(\3)/g,
		'entity $1 $2 = "$4"'
	)
	// SET_MAP_TICK_SCRIPT
	.replace(
		/set map (.+?) on_tick to ("?)([^;\n]+)(\3)/g,
		'map $1 on_tick = "$4"'
	)
	
	// Set int (expressions not allowed)
	// SET_ENTITY_X
	// SET_ENTITY_Y
	// SET_ENTITY_PRIMARY_ID
	// SET_ENTITY_SECONDARY_ID
	// SET_ENTITY_PRIMARY_ID_TYPE
	// SET_ENTITY_CURRENT_ANIMATION
	// SET_ENTITY_CURRENT_FRAME
	// SET_ENTITY_MOVEMENT_RELATIVE
	.replace(
		/set entity (.+?) (x|y|primary_id|secondary_id|primary_id_type|current_animation|animation_frame|strafe) to ([^;\n]+)/g,
		'entity $1 $2 = "$4"'
	)
	// SET_ENTITY_DIRECTION_RELATIVE
	.replace(
		/rotate entity (.+?) -([0-9]+)/g,
		'entity $1 direction -= $2'
	)
	.replace(
		/rotate entity (.+?) ([0-9]+)/g,
		'entity $1 direction += $2'
	)
	
	// Set int (expressions OK)
	.replace( // MUTATE_VARIABLE, MUTATE_VARIABLES
		/mutate (.+?) (\+|-|\*|\/|\%|\?) ([^;\n]+)/g,
		'$1 $2= $3'
	)
	.replace( // ditto
		/mutate (.+?) = ([^;\n]+)/g,
		'$1 = $2'
	)
	// COPY_VARIABLE
	.replace(
		/copy entity (.+?) ([_a-z]+) from variable ([^;\n]+)/g,
		'entity $1 $2 = $3'
	)
	.replace(
		/copy entity (.+?) ([_a-z]+) into variable ([^;\n]+)/g,
		'$3 = entity $1 $2'
	)
	.replace(
		/copy variable (.+?) from entity (.+?) ([_a-z]+)/g,
		'$1 = entity $2 $3'
	)
	.replace(
		/copy variable (.+?) into entity (.+?) ([_a-z]+)/g,
		'entity $2 $3 = $1'
	)

	// Set bool (expressions OK)
	.replace( // SET_SAVE_FLAG
		/set flag (.+?) to ([^;\n]+)/g,
		'$1 = $2'
	)
	.replace( // SET_HEX_EDITOR_STATE
		/(on|off|true|false|open|close|yes|no) hex editor/g,
		'hex_editor = $1'
	)
	.replace( // SET_HEX_EDITOR_DIALOG_MODE
		/turn (.+?) hex dialog mode|turn hex dialog mode ([^;\n]+)/g,
		'hex_dialog_mode = $2'
	)
	.replace( // SET_HEX_EDITOR_CONTROL
		/turn (.+?) hex control|turn hex control ([^;\n]+)/g,
		'hex_control = $1$2'
	)
	.replace( // SET_HEX_EDITOR_CONTROL_CLIPBOARD
		/turn (.+?) hex clipboard|turn hex clipboard ([^;\n]+)/g,
		'hex_clipboard = $1$2'
	)
	.replace( // SET_SERIAL_DIALOG_CONTROL
		/turn (.+?) serial control|turn serial control ([^;\n]+)/g,
		'serial_control = $1$2'
	)
	.replace( // SET_PLAYER_CONTROL
		/turn (.+?) player control|turn player control ([^;\n]+)/g,
		'player_control = $1$2'
	)
	.replace( // SET_LIGHTS_CONTROL
		/turn (.+?) lights control|turn lights control ([^;\n]+)/g,
		'lights_control = $1$2'
	)
	.replace( // SET_LIGHTS_STATE
		/turn (.+?) light ([A-Z0-9]+)|turn light ([A-Z0-9]+) ([^;\n]+)/g,
		'light $2$3 = $1$4'
	)
	.replace( // SET_ENTITY_GLITCHED
		/make entity (.+?) glitched/g,
		'entity $1 glitched = true'
	)
	.replace( // ditto
		/make entity (.+?) unglitched/g,
		'entity $1 glitched = false'
	)
	
	// Branch on string equality
	// CHECK_WARP_STATE
	.replace(
		/warp state is not ("?)([-_a-zA-Z0-9]+)(\1)/g,
		'warp_state != "$2"'
	)
	.replace(
		/warp state is ("?)([-_a-zA-Z0-9]+)(\1)/g,
		'warp_state == "$2"'
	)
	.replace(
		/warp state is not (")([^"]+)(")/g,
		'warp_state != "$2"'
	)
	.replace(
		/warp state is (")([^"]+)(")/g,
		'warp_state == "$2"'
	)
	// CHECK_ENTITY_NAME
	// CHECK_ENTITY_TYPE
	// CHECK_ENTITY_INTERACT_SCRIPT
	// CHECK_ENTITY_TICK_SCRIPT
	// CHECK_ENTITY_LOOK_SCRIPT
	// CHECK_ENTITY_PATH
	.replace(
		/entity (.+?) (name|type|path|on_interact|on_tick|on_look) is not ("?)([^)]+)(\3)/g,
		'entity $1 $2 != "$4"'
	)
	.replace(
		/entity (.+?) (name|type|path|on_interact|on_tick|on_look) is ("?)([^)]+)(\3)/g,
		'entity $1 $2 == "$4"'
	)
	// CHECK_ENTITY_DIRECTION
	.replace(
		/entity (.+?) direction is not (north|south|east|west)/g,
		'entity $1 direction != $2'
	)
	.replace(
		/entity (.+?) direction is (north|south|east|west)/g,
		'entity $1 direction == $2'
	)
	
	// Branch on int comparison (== < <= => >)
	// CHECK_VARIABLE, CHECK_VARIABLES
	.replace(
		/variable (.+?) is not ([-_0-9A-Za-z]+)/g,
		'$1 != $2'
	)
	.replace(
		/variable (.+?) is ([-_0-9A-Za-z]+)/g,
		'$1 == $2'
	)
	// CHECK_VARIABLE, CHECK_VARIABLES
	.replace(
		/variable (.+?) is ([<=>]+) ([-_0-9A-Za-z]+)/g,
		'$1 $2 $3'
	)

	// Branch on int equality (==)
	// CHECK_ENTITY_X
	// CHECK_ENTITY_Y
	// CHECK_ENTITY_PRIMARY_ID
	// CHECK_ENTITY_SECONDARY_ID
	// CHECK_ENTITY_PRIMARY_ID_TYPE
	// CHECK_ENTITY_CURRENT_ANIMATION
	// CHECK_ENTITY_CURRENT_FRAME
	.replace(
		/entity (.+?) ([a-z]+) is not ([0-9]+)/g,
		'entity $1 $2 != $3'
	)
	.replace(
		/entity (.+?) ([a-z]+) is ([0-9]+)/g,
		'entity $1 $2 == $3'
	)
	
	// Branch on bool equality (==)
	// CHECK_DEBUG_MODE
	.replace(/debug mode is (open|on|true|yes)/g, 'debug_mode')
	.replace(/debug mode is not (open|on|true|yes)/g, '!debug_mode')
	.replace(/debug mode is (close|off|false|no)/g, '!debug_mode')
	.replace(/debug mode is not (close|off|false|no)/g, 'debug_mode')
	// CHECK_DIALOG_OPEN
	.replace(/dialog is (open|on|true|yes)/g, 'dialog open')
	.replace(/dialog is not (open|on|true|yes)/g, 'dialog closed')
	.replace(/dialog is (close|off|false|no)/g, 'dialog closed')
	.replace(/dialog is not (close|off|false|no)/g, 'dialog open')
	// CHECK_SERIAL_DIALOG_OPEN
	.replace(/serial_dialog is (open|on|true|yes)/g, 'serial_dialog open')
	.replace(/serial_dialog is not (open|on|true|yes)/g, 'serial_dialog closed')
	.replace(/serial_dialog is (close|off|false|no)/g, 'serial_dialog closed')
	.replace(/serial_dialog is not (close|off|false|no)/g, 'serial_dialog open')
	// CHECK_SAVE_FLAG
	.replace(/flag (.+?) is (open|on|true|yes)/g, '$1')
	.replace(/flag (.+?) is (close|off|false|no)/g, '!$1')
	.replace(/flag (.+?) is not (open|on|true|yes)/g, '!$1')
	.replace(/flag (.+?) is not (close|off|false|no)/g, '$1')
	// CHECK_FOR_BUTTON_PRESS
	.replace(/button ([A-Z0-9]+)/g, 'button $1 pressed')
	.replace(/not button ([A-Z0-9]+)/g, '!button $1 pressed')
	// CHECK_FOR_BUTTON_STATE
	.replace(/button ([A-Z0-9]+) is currently pressed/g, 'button $1 down')
	.replace(/button ([A-Z0-9]+) is not curently pressed/g, '!button $1 up')
	// CHECK_IF_ENTITY_IS_IN_GEOMETRY
	.replace(
		/entity (.+?) is inside geometry ([^\)]+)/g,
		'entity $1 intersects geometry $2'
	)
	.replace(
		/entity (.+?) is not inside geometry ([^\)]+)/g,
		'!entity $1 intersects geometry $2'
	)
	// CHECK_ENTITY_GLITCHED
	.replace(
		/entity (.+?) is glitched/g,
		'entity $1 glitched'
	)
	.replace(
		/entity (.+?) is not glitched/g,
		'!entity $1 glitched'
	)

	// Has to be last
	.replace( // COPY_SCRIPT
		/copy ("?)([^;\n ]+?)(\1);?(\n)/g,
		'copy!("$2")\n'
	)
	// Final common stuff
	.replace(/entity "%PLAYER%"/g, 'player')
	.replace(/entity "%SELF%"/g, 'self')
	.replace(/"(\$[_-a-zA-Z0-9]+)"/g, '$1')

	fs.writeFileSync('./comparisons/manual_export.mgs', replaced);

	console.log(replaced);