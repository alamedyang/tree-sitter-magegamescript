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
		$.entity_identifier, $.entity_identifier_expandable,
		$.entity_or_map_identifier, $.entity_or_map_identifier_expandable,
		$.in_or_out_expandable,
		$.geometry_identifier, $.geometry_identifier_expandable,
		$.movable_identifier, $.movable_identifier_expandable,
		$.polygon_identifier, $.polygon_identifier_expandable,
		$.complex_duration, $.complex_duration_expandable,
		$.setable, $.setable_expandable,
	],
	rules: {
		source_file: $ => repeat($._root),

		block_comment: $ => token(seq('/*', repeat(/./), '*/',)),
		line_comment: $ => token(repeat1(
			seq('//', repeat(/[^\n]/))
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
				repeat(seq(',', $.bareword)),
				optional(','),
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
				repeat(seq(',', $.quoted_string)),
				optional(','),
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
				repeat(seq(',', $.string)),
				optional(','),
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
				repeat(seq(',', $.number)),
				optional(','),
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
				repeat(seq(',', $.duration)),
				optional(','),
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
				repeat(seq(',', $.distance)),
				optional(','),
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
				repeat(seq(',', $.quantity)),
				optional(','),
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
				repeat(seq(',', $.numberish)),
				optional(','),
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
				repeat(seq(',', $.color)),
				optional(','),
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
				repeat(seq(',', $.boolean)),
				optional(','),
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
				repeat(seq(',', $.CONSTANT)),
				optional(','),
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
				repeat(seq(',', $.constant_value)),
				optional(','),
			),
			']'
		),

		_root: $ => choice(
			$.include_macro,
			$.constant_assignment,
			$.add_serial_dialog_settings,
			$.add_dialog_settings,
			$.dialog_definition,
			$.serial_dialog_definition,
			$.script_definition,
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
		add_dialog_settings: $ => seq(
			'add', 'dialog', 'settings', '{',
				repeat(choice(
					seq(
						'default',
						alias($.dialog_settings_block, $.default_settings)
					),
					seq(
						'label',
						field('target_label', $.bareword),
						alias($.dialog_settings_block, $.label_settings)
					),
					seq('entity',
						field('target_entity', $.string),
						alias($.dialog_settings_block, $.entity_settings)
					),
				)),
			'}',
		),
		dialog_settings_block: $ => seq(
			'{', repeat($.dialog_parameter), '}'
		),
		dialog_parameter: $ => choice(
			seq('entity', field('entity', $.string)),
			seq('name', field('name', $.string)),
			seq('portrait', field('portrait', $.string)),
			seq('alignment', field('alignment', $.string)),
			seq('border_tileset', field('border_tileset', $.string)),
			seq('emote', field('emote', $.number)),
			seq('wrap', field('wrap', $.number)),
		),
		dialog_definition: $ => seq(
			'dialog',
			field('dialog_name', $.string),
			$.dialog_block,
		),
		dialog_block: $ => seq(
			'{',
			repeat($.dialog),
			'}'
		),
		dialog: $ => seq(
			$.dialog_identifier,
			repeat($.dialog_parameter),
			repeat1(field('message', $.QUOTED_STRING)),
			repeat($.dialog_option),
		),
		dialog_identifier: $ => choice(
			field('label', $.BAREWORD),
			seq('entity', field('entity', $.STRING)),
			seq('name', field('name', $.STRING)),
		),
		dialog_option: $ => seq(
			'>',
			field('label', $.QUOTED_STRING),
			'=',
			field('script', $.string),
		),
		serial_dialog_definition: $ => seq(
			'serial_dialog',
			field('serial_dialog_name', $.STRING),
			$.serial_dialog_block,
		),
		serial_dialog_block: $ => seq(
			'{',
			optional($.serial_dialog),
			'}'
		),
		serial_dialog: $ => seq(
			repeat($.serial_dialog_parameter),
			repeat1(field('serial_message', $.QUOTED_STRING)),
			repeat($.serial_dialog_option),
		),
		serial_dialog_option: $ => seq(
			field('option_type', $.serial_dialog_option_type),
			field('label', $.QUOTED_STRING),
			'=',
			field('script', $.string),
		),
		serial_dialog_option_type: $ => token(/_|#/),
		script_definition: $ => seq(
			optional('script'),
			field('script_name', $.BAREWORD),
			$.script_block,
		),
		script_block: $ => seq(
			'{',
			repeat($._script_item),
			'}'
		),
		_script_item: $ => choice(
			$.json_literal,
			$.label,
			$.debug_macro,
			$.rand_macro,
			$.spread_macro,
			seq($._action_item, token(';')),
		),

		json_literal: $ => seq(
			'json',
			$.json_array,
		),
		json_array: $ => seq(
			'[',
			optional(seq( $._json_item, repeat(seq(',', $._json_item)))),
			']'
		),
		json_object: $ => seq(
			'{',
			optional(seq($.json_name_value_pair, repeat(seq(',', $.json_name_value_pair)))),
			'}'
		),
		json_name_value_pair: $ => seq(
			field('property', $.QUOTED_STRING),
			':',
			field('value', $._json_item),
		),
		json_number: $ => token(choice(
			'Infinity',
			'-Infinity',
			/-?[0-9]+?/
		)),
		_json_item: $ => choice(
			$.QUOTED_STRING,
			$.json_number,
			$.json_array,
			$.json_object,
			token('true'),
			token('false'),
			token('null'),
		),

		label: $ => seq(field('label', $.BAREWORD), ':'),

		debug_macro: $ => seq(
			'debug', '!', '(',
			optional(choice(
				$.serial_dialog,
				field('dialog_name', $.bareword),
			)),
			')',
		),
		rand_macro: $ => seq(
			'rand', '!', '(',
			repeat($._script_item),
			')',
		),
		spread_macro: $ => seq(
			'spread', '!', '(',
			repeat($._script_item),
			')',
		),

		_action_item: $ => choice(
			$.return_statement,
			$.action_load_map,
			$.action_run_script,
			$.action_goto_label,
			$.action_goto_index,
			$.action_show_dialog,
			$.action_show_serial_dialog,
			$.action_concat_serial_dialog,
			$.action_delete_command,
			$.action_delete_command_arg,
			$.action_delete_alias,
			$.action_hide_command,
			$.action_unhide_command,
			$.action_save_slot,
			$.action_load_slot,
			$.action_erase_slot,
			$.action_blocking_delay,
			$.action_non_blocking_delay,
			$.action_close_dialog,
			$.action_close_serial_dialog,
			$.action_pause_script,
			$.action_unpause_script,
			$.action_camera_shake,
			$.action_camera_fade,
			$.action_play_entity_animation,
			$.action_move_over_time,
			$.action_set_position,

			// $.action_set_bool,
		),

		return_statement: $ => 'return',
		action_load_map: $ => seq('load', 'map', field('map', $.string_expandable),),
		action_run_script: $ => seq('goto', field('script', $.string_expandable),),
		action_goto_label: $ => seq('goto', 'label', field('label', $.bareword_expandable),),
		action_goto_index: $ => seq('goto', 'index', field('index', $.number_expandable),),

		action_show_dialog: $ => seq(
			'show', 'dialog', choice(
				seq(field('dialog_name', $.STRING), $.dialog_block),
				field('dialog_name', $.STRING),
				$.dialog_block,
			),
		),
		action_show_serial_dialog: $ => seq(
			'show', 'serial_dialog', choice(
				seq(field('serial_dialog_name', $.STRING), $.serial_dialog_block),
				field('serial_dialog_name', $.STRING),
				$.serial_dialog_block,
			),
		),
		action_concat_serial_dialog: $ => seq(
			'concat', 'serial_dialog', choice(
				seq(field('serial_dialog_name', $.STRING), $.serial_dialog_block),
				field('serial_dialog_name', $.STRING),
				$.serial_dialog_block,
			),
		),
		
		action_delete_command: $ => seq('delete', 'command', field('command', $.string_expandable)),
		action_delete_command_arg: $ => seq(
			'delete', 'command', field('command', $.string_expandable),
			'+', field('argument', $.string_expandable),
		),
		action_delete_alias: $ => seq('delete', 'alias', field('alias', $.string_expandable)),
		action_hide_command: $ => seq('hide', 'command', field('command', $.string_expandable)),
		action_unhide_command: $ => seq('unhide', 'command', field('command', $.string_expandable)),

		action_save_slot: $ => seq('save', 'slot',),
		action_load_slot: $ => seq('load', 'slot', field('slot', $.number_expandable),),
		action_erase_slot: $ => seq('erase', 'slot', field('slot', $.number_expandable),),

		action_blocking_delay: $ => seq('block', field('duration', $.duration_expandable),),
		action_non_blocking_delay: $ => seq('wait', field('duration', $.duration_expandable),),

		action_close_dialog: $ => seq('close', 'dialog'),
		action_close_serial_dialog: $ => seq('close', 'serial_dialog'),

		player: $ => 'player',
		self: $ => 'self',
		entity_identifier: $ => choice(
			$.player,
			$.self,
			seq('entity', field('entity', $.string))
		),
		entity_identifier_expandable: $ => choice(
			$.entity_identifier,
			$.entity_identifier_expansion
		),
		entity_identifier_expansion: $ => seq(
			'[',
			optional(seq(
				$.entity_identifier,
				repeat(seq(',', $.entity_identifier)),
				optional(','),
			)),
			']'
		),
		map: $ => 'map',
		entity_or_map_identifier: $ => choice(
			$.map,
			$.player,
			$.self,
			seq('entity', field('entity', $.string))
		),
		entity_or_map_identifier_expandable: $ => choice(
			$.entity_or_map_identifier,
			$.entity_or_map_identifier_expansion
		),
		entity_or_map_identifier_expansion: $ => seq(
			'[',
			optional(seq(
				$.entity_or_map_identifier,
				repeat(seq(',', $.entity_or_map_identifier)),
				optional(','),
			)),
			']'
		),

		action_pause_script: $ => seq(
			'pause',
			$.entity_or_map_identifier_expandable,
			field('script', $.string_expandable),
		),
		action_unpause_script: $ => seq(
			'unpause',
			$.entity_or_map_identifier_expandable,
			field('script', $.string_expandable),
		),

		action_camera_fade: $ => seq(
			'camera', 'fade', field('fade', $.in_or_out_expandable),
			'->', field('color', $.color_expandable),
			'over', field('duration', $.duration_expandable),
		),
		in_or_out: $ => choice('in','out'),
		in_or_out_expandable: $ => choice(
			$.in_or_out,
			$.in_or_out_expansion,
		),
		in_or_out_expansion: $ => seq(
			'[',
			optional(seq(
				$.in_or_out,
				repeat(seq(',', $.in_or_out)),
				optional(','),
			)),
			']'
		),
		
		action_camera_shake: $ => seq(
			'camera', 'shake', '->',
			field('amplitude', $.duration_expandable),
			field('distance', $.distance_expandable),
			'over', field('duration', $.duration_expandable),
		),

		action_play_entity_animation: $ => seq(
			$.entity_identifier_expandable,
			'animation', '->',
			field('animation', $.number_expandable),
			field('count', $.quantity_expandable),
		),

		geometry_identifier: $ => seq(
			'geometry', field('geometry', $.string),
		),
		geometry_identifier_expandable: $ => seq(
			$.geometry_identifier,
			$.geometry_identifier_expansion,
		),
		geometry_identifier_expansion: $ => seq(
			'[',
			optional(seq(
				$.geometry_identifier,
				repeat(seq(',', $.geometry_identifier)),
				optional(','),
			)),
			']'
		),

		camera: $ => 'camera',
		origin: $ => 'origin',
		length: $ => 'length',
		forever: $ => 'forever',
		_origin_or_length: $ => choice($.origin, $.length),

		movable_identifier: $ => choice(
			field('camera', $.camera),
			seq($.entity_identifier, 'position'),
		),
		movable_identifier_expandable: $ => choice(
			$.movable_identifier,
			$.movable_identifier_expansion,
		),
		movable_identifier_expansion: $ => seq(
			'[',
			optional(seq(
				$.movable_identifier,
				repeat(seq(',', $.movable_identifier)),
				optional(','),
			)),
			']'
		),

		polygon_identifier: $ => choice(
			seq($.entity_identifier, 'position'),
			seq($.geometry_identifier, field('target', $._origin_or_length)),
		),
		polygon_identifier_expandable: $ => choice(
			$.polygon_identifier,
			$.polygon_identifier_expansion,
		),
		polygon_identifier_expansion: $ => seq(
			'[',
			optional(seq(
				$.polygon_identifier,
				repeat(seq(',', $.polygon_identifier)),
				optional(','),
			)),
			']'
		),

		complex_duration: $ => choice(
			field('forever', $.forever),
			seq('over', field('duration', $.duration_expandable))
		),
		complex_duration_expandable: $ => choice(
			$.complex_duration,
			$.complex_duration_expansion,
		),
		complex_duration_expansion: $ => seq(
			'[',
			optional(seq(
				$.complex_duration,
				repeat(seq(',', $.complex_duration)),
				optional(','),
			)),
			']'
		),

		action_move_over_time: $ => seq(
			$.movable_identifier_expandable,
			'->',
			$.polygon_identifier_expandable,
			$.complex_duration_expandable
		),
		action_set_position: $ => seq(
			$.movable_identifier_expandable,
			'=',
			$.polygon_identifier_expandable
		),

		setable: $ => choice(
			seq($.entity_identifier, 'glitched'),
			'player_control',
			'lights_control',
			'hex_editor',
			'hex_dialog_mode',
			'hex_control',
			'hex_clipboard',
			'serial_control',
			'flagName',
		),
		setable_expandable: $ => choice(
			$.setable,
			$.setable_expansion,
		),
		setable_expansion: $ => seq(
			'[',
			optional(seq(
				field('setable', $.setable),
				repeat(seq(',', $.setable)),
				optional(','),
			)),
			']'
		),
		// action_set_bool: $ => seq(
		// 	field('setable', $.setable), 
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





	},
});

const makeTokenComplex = (tokenName) => {
	const lowerCase = tokenName.toLocaleLowerCase();
	
};
