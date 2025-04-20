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
		/\n/,
		/\t/,
		/\s/,
		$.block_comment,
		$.line_comment,
	],
	rules: {
		source_file: $ => repeat($._root),
		block_comment: $ => token(seq('/*', repeat(/./), '*/',)),
		line_comment: $ => token(seq('//', repeat(/./), '\n',)),
		BAREWORD: $ => token(/[_a-zA-Z][_a-zA-Z0-9]*/),
		_bareword: $ => choice($.BAREWORD, $.CONSTANT),
		QUOTED_STRING: $ => token(/"(?:[^"\\]|\\.)*"/),
		_quoted_string: $ => choice($.QUOTED_STRING, $.CONSTANT),
		_STRING: $ => choice($.QUOTED_STRING, $.BAREWORD),
		_string: $ => choice($.QUOTED_STRING, $.BAREWORD, $.CONSTANT),
		NUMBER: $ => token(/[0-9]+/),
		_number: $ => choice($.NUMBER, $.CONSTANT),
		DURATION: $ => token(/[0-9]+(m?s)?/),
		_duration: $ => choice($.DURATION, $.CONSTANT),
		DISTANCE: $ => token(/[0-9]+(px|pix)?/),
		_distance: $ => choice($.DISTANCE, $.CONSTANT),
		QUANTITY: $ => token(/once|twice|thrice|[0-9]+(x)?/),
		_quantity: $ => choice($.QUANTITY, $.CONSTANT),
		COLOR: $ => token(/white|black|red|green|blue|magenta|cyan|yellow|#[0-9]{3,6}/),
		_color: $ => choice($.COLOR, $.CONSTANT),
		_NUMBERISH: $ => choice($.NUMBER, $.DURATION, $.DISTANCE, $.QUANTITY),
		_numberish: $ => choice($._NUMBERISH, $.CONSTANT),
		BOOLEAN: $ => token(/true|false|on|off|open|closed/),
		_boolean: $ => choice($.BOOLEAN, $.CONSTANT),
		CONSTANT: $ => token(/\$[_a-zA-Z0-9]+/),
		// OPERATOR: $ => /[\{\}\[\]\(\)<>\+-=\]|[!=><]=|\|\||&&|\->/,
		ENUM_ALIGNMENT: $ => token(choice(
			'TR', 'TL', 'TOP_RIGHT', 'TOP_LEFT',
			'BR', 'BL', 'BOTTOM_RIGHT', 'BOTTOM_LEFT',
		)),
		_enum_alignment: $ => choice($.ENUM_ALIGNMENT, $.CONSTANT),
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
			'include', field('fileName', $.QUOTED_STRING), ';',
		),
		constant_assignment: $ => seq(
			field('label', $.CONSTANT), '=', field('value', choice(
				$._STRING,
				$._NUMBERISH,
				$.BOOLEAN,
				$.COLOR,
				$.CONSTANT,
			)), ';',
		),
		add_serial_dialog_settings: $ => seq(
			'add', 'serial_dialog', 'settings', '{',
			repeat($.serial_dialog_parameter),
			'}'
		),
		serial_dialog_parameter: $ => choice(
			seq(field('property', 'wrap'), field('value', $._number)),
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
						field('target_label', $._bareword),
						alias($.dialog_settings_block, $.label_settings)
					),
					seq('entity',
						field('target_entity', $._string),
						alias($.dialog_settings_block, $.entity_settings)
					),
				)),
			'}',
		),
		dialog_settings_block: $ => seq(
			'{', repeat($.dialog_parameter), '}'
		),
		dialog_parameter: $ => choice(
			seq('entity', field('entity', $._string)),
			seq('name', field('name', $._string)),
			seq('portrait', field('portrait', $._string)),
			seq('alignment', field('alignment', $._enum_alignment)),
			seq('border_tileset', field('border_tileset', $._string)),
			seq('emote', field('emote', $._number)),
			seq('wrap', field('wrap', $._number)),
		),
		dialog_definition: $ => seq(
			'dialog',
			field('dialog_name', $._string),
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
			seq('entity', field('entity', $._STRING)),
			seq('name', field('name', $._STRING)),
		),
		dialog_option: $ => seq(
			'>',
			field('label', $.QUOTED_STRING),
			'=',
			field('script', $._string),
		),
		serial_dialog_definition: $ => seq(
			'serial_dialog',
			field('serial_dialog_name', $._STRING),
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
			field('script', $._string),
		),
		serial_dialog_option_type: $ => token(/_|#/),
		// string_fancy: $ => choice(
		// 	$.string,
		// 	$.array_string,
		// 	$.constant_assignment,
		// ),
		// array_string: $ => seq(
		// 	'[', $.string, optional(seq(',', $.string)), ']',
		// ),
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
			$.json_block,
			$.label,
			seq($._action_item, ';'),
		),
		label: $ => seq(field('label', $.BAREWORD), ':'),
		json_block: $ => seq(
			'json',
			$.json_array,
		),
		json_array: $ => seq(
			'[',
			optional(seq(
				$._json_item,
				repeat(seq(',', $._json_item))
			)),
			']'
		),
		json_number: $ => token(choice(
			'Infinity',
			'-Infinity',
			/-?[0-9]+(\.[0-9]+)?/
		)),
		_json_item: $ => choice(
			$.QUOTED_STRING,
			$.json_number,
			$.json_array,
			$.json_object,
			$.json_language_constant,
		),
		json_language_constant: $ => choice(
			token('true'),
			token('false'),
			token('null'),
		),
		json_object: $ => seq(
			'{',
			optional(seq(
				$.json_name_value_pair,
				repeat(seq(',', $.json_name_value_pair)),
			)),
			'}'
		),
		json_name_value_pair: $ => seq(
			field('property', $.QUOTED_STRING),
			':',
			field('value', $._json_item),
		),
		_action_item: $ => choice(
			$.return_statement,
			$.action_load_map,
			$.action_run_script,
			$.action_goto_action_label,
			$.action_goto_action_index,
			$.action_show_dialog,
		),
		return_statement: $ => 'return',
		action_load_map: $ => seq(
			'load', 'map', field('map', $._string),
		),
		action_run_script: $ => seq(
			'goto', field('script', $._string),
		),
		action_goto_action_label: $ => seq(
			'goto', 'label', field('label', $._bareword),
		),
		action_goto_action_index: $ => seq(
			'goto', 'index', field('index', $._number),
		),
		action_show_dialog: $ => seq(
			'show',
			'dialog',
			choice(
				seq(
					field('dialog_name', $._STRING),
					$.dialog_block,
				),
				field('dialog_name', $._STRING),
				$.dialog_block,
			),
		),
	},
});
