/**
 * @file A custom scripting DSL for a custom game engine on a custom PCB
 * @author alamedyang <alamedyang@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
	name: "magegamescript",
	extras: $ => [
		/\s/,
		$.block_comment,
		$.line_comment,
	],
	// precedences: $ => [
	// 	[
	// 		'unary_void',
	// 		'binary_exp',
	// 		'binary_times',
	// 		'binary_plus',
	// 		'binary_compare',
	// 		'binary_relation',
	// 		'binary_equality',
	// 		'logical_and',
	// 		'logical_or',
	// 	],
	// ],
	inline: $ => [
		$.quoted_string, $.quoted_string_expandable,
		$.bareword, $.bareword_expandable,
		$.STRING,
		$.string, $.string_expandable,
		$.number, $.number_expandable,
		$.duration, $.duration_expandable,
		$.distance, $.distance_expandable,
		$.quantity, $.quantity_expandable,
		$.NUMBERISH,
		$.numberish, $.numberish_expandable,
		$.color, $.color_expandable,
		$.boolean, $.boolean_expandable,
		$.constant_expandable,
		$.constant_value, $.constant_value_expandable,
	],
	rules: {
		source_file: $ => repeat($._root),
		block_comment: $ => token(seq('/*', repeat(/./), '*/',)),
		line_comment: $ => token(repeat1(
			seq('//', repeat(/./), '\n',)
		)),
		
		BAREWORD: $ => token(/[_a-zA-Z][_a-zA-Z0-9]*/),
		bareword: $ => choice($.BAREWORD, $.CONSTANT),
		bareword_expandable: $ => choice(
			$.bareword,
			$.bareword_expansion,
		),
		bareword_expansion: $ => seq(
			'[',
			optional(seq(
				$.bareword,
				repeat(seq(',', $.bareword))
			)),
			']'
		),

		QUOTED_STRING: $ => token(/"(?:[^"\\]|\\.)*"/),
		quoted_string: $ => choice($.QUOTED_STRING, $.CONSTANT),
		quoted_string_expandable: $ => choice(
			$.quoted_string,
			$.quoted_string_expansion,
		),
		quoted_string_expansion: $ => seq(
			'[',
			optional(seq(
				$.quoted_string,
				repeat(seq(',', $.quoted_string))
			)),
			']'
		),

		STRING: $ => choice($.QUOTED_STRING, $.BAREWORD),
		string: $ => choice($.STRING, $.CONSTANT),
		string_expandable: $ => choice(
			$.string,
			$.string_expansion,
		),
		string_expansion: $ => seq(
			'[',
			optional(seq(
				$.string,
				repeat(seq(',', $.string))
			)),
			']'
		),

		NUMBER: $ => token(/[0-9]+/),
		number: $ => choice($.NUMBER, $.CONSTANT),
		number_expandable: $ => choice(
			$.number,
			$.number_expansion,
		),
		number_expansion: $ => seq(
			'[',
			optional(seq(
				$.number,
				repeat(seq(',', $.number))
			)),
			']'
		),

		DURATION: $ => token(/[0-9]+(m?s)?/),
		duration: $ => choice($.DURATION, $.CONSTANT),
		duration_expandable: $ => choice(
			$.duration,
			$.duration_expansion,
		),
		duration_expansion: $ => seq(
			'[',
			optional(seq(
				$.duration,
				repeat(seq(',', $.duration))
			)),
			']'
		),

		DISTANCE: $ => token(/[0-9]+(px|pix)?/),
		distance: $ => choice($.DISTANCE, $.CONSTANT),
		distance_expandable: $ => choice(
			$.distance,
			$.distance_expansion,
		),
		distance_expansion: $ => seq(
			'[',
			optional(seq(
				$.distance,
				repeat(seq(',', $.distance))
			)),
			']'
		),
				
		QUANTITY: $ => token(/once|twice|thrice|[0-9]+(x)?/),
		quantity: $ => choice($.QUANTITY, $.CONSTANT),
		quantity_expandable: $ => choice(
			$.quantity,
			$.quantity_expansion,
		),
		quantity_expansion: $ => seq(
			'[',
			optional(seq(
				$.quantity,
				repeat(seq(',', $.quantity))
			)),
			']'
		),

		NUMBERISH: $ => choice($.NUMBER, $.DURATION, $.DISTANCE, $.QUANTITY),
		numberish: $ => choice(
			$.NUMBERISH,
			$.CONSTANT
		),
		numberish_expandable: $ => choice(
			$.numberish,
			$.numberish_expansion,
		),
		numberish_expansion: $ => seq(
			'[',
			optional(seq(
				$.numberish,
				repeat(seq(',', $.numberish))
			)),
			']'
		),

		COLOR: $ => token(/white|black|red|green|blue|magenta|cyan|yellow|#[0-9]{3,6}/),
		color: $ => choice($.COLOR, $.CONSTANT),
		color_expandable: $ => choice(
			$.color,
			$.color_expansion,
		),
		color_expansion: $ => seq(
			'[',
			optional(seq(
				$.color,
				repeat(seq(',', $.color))
			)),
			']'
		),
	
		BOOLEAN: $ => token(/true|false|on|off|open|closed/),
		boolean: $ => choice($.BOOLEAN, $.CONSTANT),
		boolean_expandable: $ => choice(
			$.boolean,
			$.boolean_expansion,
		),
		boolean_expansion: $ => seq(
			'[',
			optional(seq(
				$.boolean,
				repeat(seq(',', $.boolean))
			)),
			']'
		),

		CONSTANT: $ => token(/\$[_a-zA-Z0-9]+/),
		constant_expandable: $ => choice(
			$.CONSTANT,
			$.constant_expansion,
		),
		constant_expansion: $ => seq(
			'[',
			optional(seq(
				$.CONSTANT,
				repeat(seq(',', $.CONSTANT))
			)),
			']'
		),
		constant_value: $ => choice(
			$.STRING,
			$.NUMBERISH,
			$.BOOLEAN,
			$.COLOR,
			$.CONSTANT,
		),
		constant_value_expandable: $ => choice(
			$.constant_value,
			$.constant_value_expansion,
		),
		constant_value_expansion: $ => seq(
			'[',
			seq(
				$.constant_value,
				repeat(seq(',', $.constant_value))
			),
			']'
		),
		// OPERATOR: $ => /[\{\}\[\]\(\)<>\+-=\]|[!=><]=|\|\||&&|\->/,
		// ENUM_ALIGNMENT: $ => token(choice(
		// 	'TR', 'TL', 'TOP_RIGHT', 'TOP_LEFT',
		// 	'BR', 'BL', 'BOTTOM_RIGHT', 'BOTTOM_LEFT',
		// )),
		// _enum_alignment: $ => choice(
		// 	$.ENUM_ALIGNMENT,
		// 	$.CONSTANT,
		// 	seq(
		// 		'[',
		// 		optional(seq($._enum_alignment, repeat(seq(',', $._enum_alignment)))),
		// 		']'
		// 	),
		// ),
		// ENUM_MAP_SCRIPT: $ => token(choice(
		// 	'on_load',
		// 	'on_tick',
		// 	'on_look',
		// )),
		// _enum_map_script: $ => choice(
		// 	$.ENUM_MAP_SCRIPT,
		// 	$.CONSTANT,
		// 	seq(
		// 		'[',
		// 		optional(seq($._enum_map_script, repeat(seq(',', $._enum_map_script)))),
		// 		']'
		// 	),
		// ),
		// ENUM_ENTITY_SCRIPT: $ => token(choice(
		// 	'on_interact',
		// 	'on_tick',
		// 	'on_look',
		// )),
		// _enum_entity_script: $ => choice(
		// 	$.ENUM_ENTITY_SCRIPT,
		// 	$.CONSTANT,
		// 	seq(
		// 		'[',
		// 		optional(seq($._enum_entity_script, repeat(seq(',', $._enum_entity_script)))),
		// 		']'
		// 	),
		// ),
		_root: $ => choice(
			$.include_macro,
			$.constant_assignment,
			$.add_serial_dialog_settings,
			// $.add_dialog_settings,
			// $.dialog_definition,
			// $.serial_dialog_definition,
			// $.script_definition,
		),
		include_macro: $ => seq(
			'include', field('fileName', $.quoted_string_expandable), ';',
		),
		constant_assignment: $ => seq(
			field('label', $.constant_expandable),
			'=',
			field('value', $.constant_value_expandable),
			';',
		),
		add_serial_dialog_settings: $ => seq(
			'add', 'serial_dialog', 'settings', '{',
			repeat($.serial_dialog_parameter),
			'}'
		),
		serial_dialog_parameter: $ => choice(
			seq('wrap', field('wrap', $.number)),
		),
		// add_dialog_settings: $ => seq(
		// 	'add', 'dialog', 'settings', '{',
		// 		repeat(choice(
		// 			seq(
		// 				'default',
		// 				alias($.dialog_settings_block, $.default_settings)
		// 			),
		// 			seq(
		// 				'label',
		// 				field('target_label', $.bareword),
		// 				alias($.dialog_settings_block, $.label_settings)
		// 			),
		// 			seq('entity',
		// 				field('target_entity', $.string),
		// 				alias($.dialog_settings_block, $.entity_settings)
		// 			),
		// 		)),
		// 	'}',
		// ),
		// dialog_settings_block: $ => seq(
		// 	'{', repeat($.dialog_parameter), '}'
		// ),
		// dialog_parameter: $ => choice(
		// 	seq('entity', field('entity', $.string)),
		// 	seq('name', field('name', $.string)),
		// 	seq('portrait', field('portrait', $.string)),
		// 	seq('alignment', field('alignment', $.string)),
		// 	seq('border_tileset', field('border_tileset', $.string)),
		// 	seq('emote', field('emote', $.number)),
		// 	seq('wrap', field('wrap', $.number)),
		// ),
		// dialog_definition: $ => seq(
		// 	'dialog',
		// 	field('dialog_name', $._string),
		// 	$.dialog_block,
		// ),
		// dialog_block: $ => seq(
		// 	'{',
		// 	repeat($.dialog),
		// 	'}'
		// ),
		// dialog: $ => seq(
		// 	$.dialog_identifier,
		// 	repeat($.dialog_parameter),
		// 	repeat1(field('message', $.QUOTED_STRING)),
		// 	repeat($.dialog_option),
		// ),
		// dialog_identifier: $ => choice(
		// 	field('label', $.BAREWORD),
		// 	seq('entity', field('entity', $._STRING)),
		// 	seq('name', field('name', $._STRING)),
		// ),
		// dialog_option: $ => seq(
		// 	'>',
		// 	field('label', $.QUOTED_STRING),
		// 	'=',
		// 	field('script', $._string),
		// ),
		// serial_dialog_definition: $ => seq(
		// 	'serial_dialog',
		// 	field('serial_dialog_name', $._STRING),
		// 	$.serial_dialog_block,
		// ),
		// serial_dialog_block: $ => seq(
		// 	'{',
		// 	optional($.serial_dialog),
		// 	'}'
		// ),
		// serial_dialog: $ => seq(
		// 	repeat($.serial_dialog_parameter),
		// 	repeat1(field('serial_message', $.QUOTED_STRING)),
		// 	repeat($.serial_dialog_option),
		// ),
		// serial_dialog_option: $ => seq(
		// 	field('option_type', $.serial_dialog_option_type),
		// 	field('label', $.QUOTED_STRING),
		// 	'=',
		// 	field('script', $._string),
		// ),
		// serial_dialog_option_type: $ => token(/_|#/),
		// script_definition: $ => seq(
		// 	optional('script'),
		// 	field('script_name', $.BAREWORD),
		// 	$.script_block,
		// ),
		// script_block: $ => seq(
		// 	'{',
		// 	repeat($._script_item),
		// 	'}'
		// ),
		// _script_item: $ => choice(
		// 	$.json_block,
		// 	$.label,
		// 	$.debug_macro,
		// 	$.rand_macro,
		// 	seq($._action_item, ';'),
		// ),
		// rand_macro: $ => seq(
		// 	'rand', '!', '(',
		// 	repeat($._script_item),
		// 	')',
		// ),
		// debug_macro: $ => seq(
		// 	'debug', '!', '(',
		// 	optional(choice(
		// 		$.serial_dialog,
		// 		field('dialog_name', $._bareword),
		// 	)),
		// 	')',
		// ),
		// label: $ => seq(field('label', $.BAREWORD), ':'),
		// json_block: $ => seq(
		// 	'json',
		// 	$.json_array,
		// ),
		// json_array: $ => seq(
		// 	'[',
		// 	optional(seq( $._json_item, repeat(seq(',', $._json_item)))),
		// 	']'
		// ),
		// json_number: $ => token(choice(
		// 	'Infinity',
		// 	'-Infinity',
		// 	/-?[0-9]+(\.[0-9]+)?/
		// )),
		// _json_item: $ => choice(
		// 	$.QUOTED_STRING,
		// 	$.json_number,
		// 	$.json_array,
		// 	$.json_object,
		// 	$.json_language_constant,
		// ),
		// json_language_constant: $ => choice(
		// 	token('true'),
		// 	token('false'),
		// 	token('null'),
		// ),
		// json_object: $ => seq(
		// 	'{',
		// 	optional(seq($.json_name_value_pair, repeat(seq(',', $.json_name_value_pair)))),
		// 	'}'
		// ),
		// json_name_value_pair: $ => seq(
		// 	field('property', $.QUOTED_STRING),
		// 	':',
		// 	field('value', $._json_item),
		// ),
		// return_statement: $ => 'return',
		// action_load_map: $ => seq(
		// 	'load', 'map', field('map', $._string),
		// ),
		// action_run_script: $ => seq(
		// 	'goto', field('script', $._string),
		// ),
		// action_goto_action_label: $ => seq(
		// 	'goto', 'label', field('label', $._bareword),
		// ),
		// action_goto_action_index: $ => seq(
		// 	'goto', 'index', field('index', $._number),
		// ),
		// action_show_dialog: $ => seq(
		// 	'show',
		// 	'dialog',
		// 	choice(
		// 		seq(
		// 			field('dialog_name', $._STRING),
		// 			$.dialog_block,
		// 		),
		// 		field('dialog_name', $._STRING),
		// 		$.dialog_block,
		// 	),
		// ),
		// action_show_serial_dialog: $ => seq(
		// 	'show',
		// 	'serial_dialog',
		// 	choice(
		// 		seq(
		// 			field('serial_dialog_name', $._STRING),
		// 			$.serial_dialog_block,
		// 		),
		// 		field('serial_dialog_name', $._STRING),
		// 		$.serial_dialog_block,
		// 	),
		// ),
		// action_concat_serial_dialog: $ => seq(
		// 	'concat',
		// 	'serial_dialog',
		// 	choice(
		// 		seq(
		// 			field('serial_dialog_name', $._STRING),
		// 			$.serial_dialog_block,
		// 		),
		// 		field('serial_dialog_name', $._STRING),
		// 		$.serial_dialog_block,
		// 	),
		// ),
		// action_delete_command: $ => seq(
		// 	'delete', 'command',
		// 	field('command', $._string),
		// ),
		// action_delete_command_arg: $ => seq(
		// 	'delete', 'command',
		// 	field('command', $._string), '+', field('argument', $._string),
		// ),
		// action_delete_alias: $ => seq(
		// 	'delete', 'alias', field('alias', $._string),
		// ),
		// action_hide_command: $ => seq(
		// 	'hide', 'command', field('command', $._string),
		// ),
		// action_unhide_command: $ => seq(
		// 	'unhide', 'command', field('command', $._string),
		// ),
		// action_save_slot: $ => seq(
		// 	'save', 'slot',
		// ),
		// action_load_slot: $ => seq(
		// 	'load', 'slot', field('slot', $._number),
		// ),
		// action_erase_slot: $ => seq(
		// 	'erase', 'slot', field('slot', $._number),
		// ),
		// action_blocking_delay: $ => seq(
		// 	'block', field('duration', $._duration),
		// ),
		// action_non_blocking_delay: $ => seq(
		// 	'wait', field('duration', $._duration),
		// ),
		// action_close_dialog: $ => seq(
		// 	'close', 'dialog',
		// ),
		// action_close_serial_dialog: $ => seq(
		// 	'close', 'serial_dialog',
		// ),
		// action_pause_script: $ => seq(
		// 	'pause',
		// 	$._map_or_entity_script,
		// ),
		// action_unpause_script: $ => seq(
		// 	'unpause',
		// 	$._map_or_entity_script,
		// ),
		// _map_or_entity_script: $ => choice(
		// 	seq('map', field('map_script', $._enum_map_script)),
		// 	seq('player', field('player_script', $._enum_entity_script)),
		// 	seq('self', field('self_script', $._enum_entity_script)),
		// 	seq(
		// 		'entity',
		// 		field('entity', $._string),
		// 		field('entity_script', $._enum_entity_script)
		// 	),
		// ),
		// in_or_out: $ => choice('in','out'),
		// action_camera_fade: $ => seq(
		// 	'camera', 'fade',
		// 	field('fade', $.in_or_out),
		// 	'->',
		// 	field('color', $._color),
		// 	'over',
		// 	field('duration', $._duration),
		// ),
		// action_camera_shake: $ => seq(
		// 	'camera', 'shake', '->',
		// 	field('amplitude', $._duration),
		// 	field('distance', $._distance),
		// 	'over',
		// 	field('duration', $._duration),
		// ),
		// _geometry_identifier: $ => seq(
		// 	'geometry',
		// 	field('geometry', $._string),
		// ),
		// player: $ => token('player'),
		// self: $ => token('self'),
		// _entity_identifier: $ => choice(
		// 	field('entity_special', choice($.player, $.self)),
		// 	seq('entity', field('entity', $._string)),
		// ),
		// action_pan_camera_to_entity: $ => seq(
		// 	'camera', '->',
		// 	field('entity_type', $._entity_identifier),
		// 	'position', 'over',
		// 	field('duration', $._duration),
		// ),
		// action_pan_camera_to_geometry: $ => seq(
		// 	'camera', '->',
		// 	$._geometry_identifier,
		// 	'origin', 'over',
		// 	field('duration', $._duration),
		// ),
		// action_pan_camera_along_geometry: $ => seq(
		// 	'camera', '->',
		// 	$._geometry_identifier,
		// 	'length', 'over',
		// 	field('duration', $._duration),
		// ),
		// action_loop_camera_along_geometry: $ => seq(
		// 	'camera', '->',
		// 	$._geometry_identifier,
		// 	'length', 'forever',
		// ),
		// action_walk_entity_to_geometry: $ => seq(
		// 	$._entity_identifier,
		// 	'position', '->',
		// 	$._geometry_identifier,
		// 	'origin', 'over',
		// 	field('duration', $._duration),
		// ),
		// action_walk_entity_along_geometry: $ => seq(
		// 	$._entity_identifier,
		// 	'position', '->',
		// 	$._geometry_identifier,
		// 	'length', 'over',
		// 	field('duration', $._duration),
		// ),
		// action_loop_entity_along_geometry: $ => seq(
		// 	$._entity_identifier,
		// 	'position', '->',
		// 	$._geometry_identifier,
		// 	'length', 'forever',
		// ),
		// action_play_entity_animation: $ => seq(
		// 	$._entity_identifier,
		// 	'animation', '->',
		// 	field('animation', $._number),
		// 	field('count', $._quantity),
		// ),
		// action_teleport_camera: $ => seq(
		// 	'camera', '=',
		// 	choice(
		// 		$._geometry_identifier,
		// 		$._entity_identifier,
		// 	),
		// 	'position',
		// ),
		// action_teleport_entity: $ => seq(
		// 	$._entity_identifier,
		// 	'position', '=',
		// 	$._geometry_identifier,
		// ),
		// setables: $ => choice(
		// 	seq($._entity_identifier, 'glitched'),
		// 	'player_control',
		// 	'lights_control',
		// 	'hex_editor',
		// 	'hex_dialog_mode',
		// 	'hex_control',
		// 	'hex_clipboard',
		// 	'serial_control',
		// 	'flagName',
		// ),
		// action_set_bool: $ => seq(
		// 	field('setable', $.setables),
		// 	'=',
		// 	choice(
		// 		$.boolean_expandable,
		// 		$.bool_expression
		// 	),
		// ),
		// bool_expression: $ => choice(
		// 	field('bool', $._boolean),
		// 	$.bool_unary_expression,
		// 	$.bool_binary_expression,
		// 	$.bool_grouping,
		// ),
		// bool_grouping: $ => seq(
		// 	'(', $.bool_expression, ')',
		// ),
		// bool_unary_expression: $ => seq(
		// 	field('operator', $.bool_unary_operator),
		// 	$._bool_unit,
		// ),
		// bool_binary_expression: $ => seq(
		// 	$._bool_unit,
		// 	field('operator', $.bool_binary_operator),
		// 	$._bool_unit,
		// ),
		// bool_unary_operator: $ => '!',
		// bool_binary_operator: $ => choice(
		// 	prec.left(2, seq($._bool_unit, '&&', $._bool_unit)),
		// 	prec.left(1, seq($._bool_unit, '||', $._bool_unit)),
		// ),





		// _action_item: $ => choice(
		// 	$.action_set_bool,
		// 	$.action_teleport_entity,
		// 	$.action_teleport_camera,
		// 	$.action_play_entity_animation,
		// 	$.action_loop_entity_along_geometry,
		// 	$.action_walk_entity_along_geometry,
		// 	$.action_walk_entity_to_geometry,
		// 	$.action_loop_camera_along_geometry,
		// 	$.action_pan_camera_along_geometry,
		// 	$.action_pan_camera_to_geometry,
		// 	$.action_pan_camera_to_entity,
		// 	$.action_camera_shake,
		// 	$.action_camera_fade,
		// 	$.action_pause_script,
		// 	$.action_unpause_script,
		// 	$.action_close_serial_dialog,
		// 	$.action_close_dialog,
		// 	$.action_non_blocking_delay,
		// 	$.action_blocking_delay,
		// 	$.action_erase_slot,
		// 	$.action_load_slot,
		// 	$.action_save_slot,
		// 	$.action_unhide_command,
		// 	$.action_hide_command,
		// 	$.action_delete_alias,
		// 	$.action_delete_command_arg,
		// 	$.action_delete_command,
		// 	$.action_concat_serial_dialog,
		// 	$.action_show_serial_dialog,
		// 	$.action_show_dialog,
		// 	$.action_goto_action_index,
		// 	$.action_goto_action_label,
		// 	$.action_run_script,
		// 	$.action_load_map,
		// 	$.return_statement,
		// ),
	},
});

const makeTokenComplex = (tokenName) => {
	const lowerCase = tokenName.toLocaleLowerCase();
	
};
