const fs = require('node:fs');

const file = `include!("header.mgs")

man-look {
	show serial dialog spacer;
	show serial dialog {
		"<c><bold>MGE GENERAL COMMANDS MANUAL - LOOK</>"
		" "
		"Describes the room you're in. Will describe entities instead if an entity name is provided after the word <c>LOOK</>."
		" "
		"Importantly, it can list a room's exits, even if they are invisible."
		" "
		"This command may also be triggered with the alias <c>EXAMINE</> or the abbreviations <c>L</> or <c>X</>."
	}
}

man-go {
	show serial dialog spacer;
	show serial dialog {
		"<c><bold>MGE GENERAL COMMANDS MANUAL - GO</>"
		" "
		"Lets you travel to an adjacent room, even if the actual, physical door is blocked, locked, or hidden. Type <c>GO</> followed by the name of the exit, e.g. <c>GO NORTH</>"
		" "
		"To learn the names of the current room's exits, use <c>LOOK</>."
	}
}

man-help {
	show serial dialog spacer;
	show serial dialog {
		"<c><bold>MGE GENERAL COMMANDS MANUAL - HELP</>"
		" "
		"Provides general information for the serial terminal, including a list of valid serial commands."
	}
}
`;

const replaced = file
	.replace(/include!\((.+?)\)/g, 'include $1;') // include_macro

	// generic or preparatory
	.replace(/goto( script)? ("?)([^\n;]+)(\2)/g, 'goto "$3"') // goto (script)
	.replace(/serial dialog/g, 'serial_dialog') // serial dialog -> serial_dialog
	.replace( // scriptName { -> "scriptName" {
		/(^|\n)([-_A-Z0-9a-z]+) {/g,
		'$1"$2" {'
	)
	.replace( // dialog bareword { -> dialog "bareword" {
		/dialog ([-_A-Z0-9a-z]+?)( {\n|;)/g,
		'dialog "$1"$2'
	)
	.replace( // (serial) dialog options
		/(>|_|#) (.+?) :( goto)?( script)? ("?)([^\n]+)(\5)/g,
		'$1 $2 = "$6"'
	)
	.replace(
		/(\t+)if (.+)[\s]+then (goto [^;\n]+)(;?)(\n|$)/g,
		`$1if ($2) {\n$1\t$3;\n$1}$5`
	)

	// Miscellaneous
	// SLOT_SAVE -- ok as is
	// SLOT_LOAD -- ok as is
	// SLOT_ERASE -- ok as is
	.replace( // LOAD_MAP
		/load map ("?)([^;\n]+)(\1)/g,
		`load map "$2"`
	)
	// BLOCKING_DELAY -- ok as is
	// NON_BLOCKING_DELAY -- ok as is
	// SHOW_DIALOG
	.replace(
		/show dialog {([^}]+)}/g,
		'show dialog {$1};'
	)
	.replace(
		/show dialog ("[-_a-zA-Z0-9]+"){([^}]+)}/g,
		'show dialog $1 {$2};'
	)
	// CLOSE_DIALOG
	.replace(
		/end dialog/g,
		'close dialog'
	)
	.replace( // SHOW_SERIAL_DIALOG
		/(show|concat) serial_dialog {([^}]+)}/g,
		'$1 serial_dialog {$2};'
	)
	.replace(
		/(show|concat) serial_dialog ("[-_a-zA-Z0-9]+") {([^}]+)}/g,
		'$1 serial_dialog $2 {$3};'
	)
	.replace( // CLOSE_SERIAL_DIALOG
		/end serial_dialog/g,
		'close serial dialog'
	)
	// SET_SCRIPT_PAUSE
	// [TODO]
	// GOTO_ACTION_INDEX -- ok as is? (todo: check)
	// RUN_SCRIPT -- ok as is

	// Commands and aliases
	.replace( // REGISTER_SERIAL_DIALOG_COMMAND
		/register ("?)([-_a-zA-Z0-9]+)(\1)( fail)? -> ("?)([^\n;]+)(\5)/g,
		'command "$2"$4 = "$6"'
	)
	.replace( // UNREGISTER_SERIAL_DIALOG_COMMAND
		/unregister ("?)([-_a-zA-Z0-9]+)(\1)( fail)?/g,
		'delete command "$2" $4'
	)
	.replace( // REGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
		/register ("?)([-_a-zA-Z0-9]+)(\1) \+ ("?)([-_a-zA-Z0-9 ']+)(\4) -> ("?)([^\n;]+)(\7)/g,
		'command "$2" + "$5" = "$8"'
	)
	.replace( // UNREGISTER_SERIAL_DIALOG_COMMAND_ARGUMENT
		/unregister ("?)([-_a-zA-Z0-9]+)(\1) \+ ("?)([^\n;]+)(\4)/g,
		'delete command "$2" + "$5"'
	)
	.replace( // REGISTER_SERIAL_DIALOG_COMMAND_ALIAS
		/register alias ("?)([-_a-zA-Z0-9]+)(\1) = ("?)([^\n;]+)(\4)/g,
		'alias "$2" = "$5"'
	)
	.replace( // UNREGISTER_SERIAL_DIALOG_COMMAND_ALIAS
		/unregister alias ("?)([^\n;]+)(\1)/g,
		'delete alias "$2"'
	)
	// SET_SERIAL_DIALOG_COMMAND_VISIBILITY -- ok as is


	// Set position
	.replace( // SET_CAMERA_TO_FOLLOW_ENTITY
		/make camera follow entity ("?)([^;\n]+)(\1)/g,
		'camera = entity $2 position'
	)
	.replace( // TELEPORT_CAMERA_TO_GEOMETRY
		/teleport camera to geometry ("?)([^;\n]+)(\1)/g,
		'camera = geometry $2'
	)
	.replace( // TELEPORT_ENTITY_TO_GEOMETRY
		/teleport entity ("?)(.+?)(\1) to geometry ("?)([^;\n]+)(\4)/g,
		'entity $2 position = geometry $5'
	)
	.replace( // SET_ENTITY_DIRECTION_TARGET_ENTITY
		/turn entity ("?)(.+?)(\1) toward entity ("?)([^;\n]+)(\4)/g,
		'entity $2 direction = entity $5'
	)
	.replace( // SET_ENTITY_DIRECTION_TARGET_GEOMETRY
		/turn entity ("?)(.+?)(\1) toward geometry ("?)([^;\n]+)(\4)/g,
		'entity $2 direction = geometry $5'
	)
	
	// Set position over time
	.replace( // WALK_ENTITY_TO_GEOMETRY
		/walk entity ("?)(.+?)(\1) to geometry ("?)(.+?)(\4) over ([0-9ms]+)/g,
		'entity $2 position -> geometry $5 origin over $7'
	)
	.replace( // WALK_ENTITY_ALONG_GEOMETRY
		/walk entity ("?)(.+?)(\1) along geometry ("?)(.+?)(\4) over ([0-9ms]+)/g,
		'entity $2 position -> geometry $5 length over $7'
	)
	.replace( // LOOP_ENTITY_ALONG_GEOMETRY
		/loop entity ("?)(.+?)(\1) along geometry ("?)(.+?)(\4) over ([0-9ms]+)/g,
		'entity $2 position -> geometry $5 length over $7 forever'
	)
	.replace( // PAN_CAMERA_TO_ENTITY
		/pan camera to entity ("?)(.+?)(\1) over ([0-9ms]+)/g,
		'camera -> entity $2 position over $4'
	)
	.replace( // PAN_CAMERA_TO_GEOMETRY
		/pan camera to geometry ("?)(.+?)(\1) over ([0-9ms]+)/g,
		'camera -> geometry $2 origin over $4'
	)
	.replace( // PAN_CAMERA_ALONG_GEOMETRY
		/pan camera along geometry ("?)(.+?)(\1) over ([0-9ms]+)/g,
		'camera -> geometry $2 length over $4'
	)
	.replace( // LOOP_CAMERA_ALONG_GEOMETRY
		/loop camera along geometry ("?)(.+?)(\1) over ([0-9ms]+)/g,
		'camera -> geometry $2 length over $4 forever'
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
		/play entity ("?)(.+?)(\1) animation ([0-9]+) ([0-9]+x?|once|twice|thrice)/g,
		'entity $2 animation -> $4 $5'
	)

	// Set string
	.replace( // SET_WARP_STATE
		/set warp state to ("?)([^\n;]+)(\1)/g,
		'warp_state = "$2"'
	)
	.replace( // SET_ENTITY_DIRECTION
		/turn entity ("?)(.+?)(\1) (north|south|east|west)/g,
		'entity $2 direction = $4'
	)
	// SET_ENTITY_NAME
	// SET_ENTITY_TYPE
	// SET_ENTITY_PATH
	// SET_ENTITY_LOOK_SCRIPT
	// SET_ENTITY_INTERACT_SCRIPT
	// SET_ENTITY_TICK_SCRIPT
	.replace(
		/set entity ("?)(.+?)(\1) (name|type|path|on_interact|on_tick|on_look) to ("?)([^;\n]+)(\5)/g,
		'entity $2 $4 = "$5"'
	)
	// SET_MAP_TICK_SCRIPT
	.replace(
		/set map ("?)(.+?)(\1) on_tick to ("?)([^;\n]+)(\4)/g,
		'map $2 on_tick = "$6"'
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
		/set entity ("?)(.+?)(\1) (x|y|primary_id|secondary_id|primary_id_type|current_animation|animation_frame|strafe) to ([^;\n]+)/g,
		'entity $2 $4 = "$6"'
	)
	// SET_ENTITY_DIRECTION_RELATIVE
	.replace(
		/rotate entity ("?)(.+?)(\1) -([0-9]+)/g,
		'entity $2 direction -= $4'
	)
	.replace(
		/rotate entity ("?)(.+?)(\1) ([0-9]+)/g,
		'entity $2 direction += $4'
	)
	
	// Set int (expressions OK)
	.replace( // MUTATE_VARIABLE
		/mutate ("?)(.+?)(\1) (\+|-|\*|\/|\%|\?) ([0-9]+)/g,
		'"$2" $4= $5'
	)
	.replace( // ditto
		/mutate ("?)(.+?)(\1) = ([0-9]+)/g,
		'"$2" = $4'
	)
	.replace( // MUTATE_VARIABLES
		/mutate ("?)(.+?)(\1) (\+|-|\*|\/|\%|\?) ("?)([^;\n]+)(\5)/g,
		'"$2" $4= "$6"'
	)
	.replace( // ditto
		/mutate ("?)(.+?)(\1) = ("?)([^;\n]+)(\4)/g,
		'"$2" = "$5"'
	)
	// COPY_VARIABLE
	.replace(
		/copy entity ("?)(.+?)(\1) ([_a-z]+) from variable ([^;\n]+)/g,
		'entity $2 $4 = $5'
	)
	.replace(
		/copy entity ("?)(.+?)(\1) ([_a-z]+) into variable ([^;\n]+)/g,
		'$5 = entity $2 $4'
	)
	.replace(
		/copy variable (.+?) from entity ("?)(.+?)(\2) ([_a-z]+)/g,
		'$2 = entity $4 $5'
	)
	.replace(
		/copy variable (.+?) into entity ("?)(.+?)(\2) ([_a-z]+)/g,
		'entity $4 $5 = $2'
	)

	// Set bool (expressions OK)
	.replace( // SET_SAVE_FLAG
		/set flag ("?)(.+)(\1) to ([^;\n]+)/g,
		'"$2" = $4'
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
		/make entity ("?)(.+?)(\1) glitched/g,
		'entity $2 glitched = true'
	)
	.replace( // ditto
		/make entity ("?)(.+?)(\1) unglitched/g,
		'entity $2 glitched = false'
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
		/entity ("?)(.+?)(\1) (name|type|path|on_interact|on_tick|on_look) is not ("?)([^)]+)(\5)/g,
		'entity $2 $4 != "$6"'
	)
	.replace(
		/entity ("?)(.+?)(\1) (name|type|path|on_interact|on_tick|on_look) is ("?)([^)]+)(\5)/g,
		'entity $2 $4 == "$6"'
	)
	// CHECK_ENTITY_DIRECTION
	.replace(
		/entity ("?)(.+?)(\1) direction is not (north|south|east|west)/g,
		'entity $2 direction != $4'
	)
	.replace(
		/entity ("?)(.+?)(\1) direction is (north|south|east|west)/g,
		'entity $2 direction == $4'
	)
	
	// Branch on int comparison (== < <= => >)
	// CHECK_VARIABLE
	.replace(
		/variable ("?)(.+?)(\1) is not ([0-9]+)/g,
		'"$2" != $4'
	)
	.replace(
		/variable ("?)(.+?)(\1) is ([0-9]+)/g,
		'"$2" == $4'
	)
	.replace(
		/variable ("?)(.+?)(\1) is ([<=>]+) ([0-9]+)/g,
		'"$2" $4 $5'
	)
	// CHECK_VARIABLES
	.replace(
		/variable ("?)(.+?)(\1) is not ("?)([-_0-9A-Za-z]+)(\4)/g,
		'"$2" != "$5"'
	)
	.replace(
		/variable ("?)(.+?)(\1) is ("?)([-_0-9A-Za-z]+)(\4)/g,
		'"$2" == "$5"'
	)
	.replace(
		/variable ("?)(.+?)(\1) is ([<=>]+) ("?)([-_0-9A-Za-z]+)(\5)/g,
		'"$2" $4 "$6"'
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
		/entity ("?)(.+?)(\1) ([a-z]+) is not ([0-9]+)/g,
		'entity $2 $4 != $5'
	)
	.replace(
		/entity ("?)(.+?)(\1) ([a-z]+) is ([0-9]+)/g,
		'entity $2 $4 == $5'
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
	.replace(/flag (.+?) is (open|on|true|yes)/g, '"$1"')
	.replace(/flag (.+?) is (close|off|false|no)/g, '!"$1"')
	.replace(/flag (.+?) is not (open|on|true|yes)/g, '!"$1"')
	.replace(/flag (.+?) is not (close|off|false|no)/g, '"$1"')
	// CHECK_FOR_BUTTON_PRESS
	.replace(/button ([A-Z0-9]+)/g, 'button $1 pressed')
	.replace(/not button ([A-Z0-9]+)/g, '!button $1 pressed')
	// CHECK_FOR_BUTTON_STATE
	.replace(/button ([A-Z0-9]+) is currently pressed/g, 'button $1 down')
	.replace(/button ([A-Z0-9]+) is not curently pressed/g, '!button $1 up')
	// CHECK_IF_ENTITY_IS_IN_GEOMETRY
	.replace(
		/entity ("?)(.+?)(\1) is inside geometry ("?)([^\)]+)(\4)/g,
		'entity $2 intersects geometry $5'
	)
	.replace(
		/entity ("?)(.+?)(\1) is not inside geometry ("?)([^\)]+)(\4)/g,
		'!entity $2 intersects geometry $5'
	)
	// CHECK_ENTITY_GLITCHED
	.replace(
		/entity ("?)(.+?)(\1) is glitched/g,
		'entity $2 glitched'
	)
	.replace(
		/entity ("?)(.+?)(\1) is not glitched/g,
		'!entity $2 glitched'
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
	.replace(
		/settings for (serial )?dialog {/g,
		'add $1dialog settings {'
	)

	fs.writeFileSync('./comparisons/manual_export.mgs', replaced);

	console.log(replaced);