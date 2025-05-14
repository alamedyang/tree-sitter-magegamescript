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
	// 		'unary',
	// 		'mul_div',
	// 		'add_sub',
	// 		'comparison',
	// 		'equality',
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
		$.color, $.color_expandable,
		$.bool, $.bool_expandable,
		$.CONSTANT_VALUE,
		$.entity_identifier_expandable,
		$.entity_or_map_identifier_expandable,
		// $.geometry_identifier_expandable,
		$.movable_identifier_expandable,
		$.coordinate_identifier_expandable,
		$.ambiguous_identifier_expandable,
		$.bool_expression_expandable,
		$.bool_setable_expandable,
		$.int_setable_expandable,
		// $.entity_property_string_expandable,
	],
	rules: {
		document: $ => repeat($._root),

		block_comment: $ => token(seq('/*', repeat(/./), '*/',)),
		line_comment: $ => token(repeat1(seq('//', repeat(/[^\n]/)))),
	
		BOOL: $ => token(prec(1,/true|false|on|off|open|closed/)),
		BAREWORD: $ => token(/[_a-zA-Z][_a-zA-Z0-9]*/),
		QUOTED_STRING: $ => token(/"(?:[^"\\]|\\.)*"/),
		STRING: $ => choice($.QUOTED_STRING, $.BAREWORD),
		NUMBER: $ => token(/-?[0-9]+/),
		DURATION: $ => prec.right(seq(
			$.NUMBER,
			optional(field('suffix', token.immediate(/m?s/)))
		)),
		DISTANCE: $ => prec.right(seq(
			$.NUMBER,
			optional(field('suffix', token.immediate(/pix|px/)))
		)),
		QUANTITY: $ => choice(
			token(prec(1, choice('once', 'twice', 'thrice'))),
			prec.right(seq(
				$.NUMBER,
				optional(field('suffix', token.immediate(/x/)))
			)),
		),
		COLOR: $ => token(prec(1, /white|black|red|green|blue|magenta|cyan|yellow|#[0-9A-F]{3,6}/)),
		CONSTANT: $ => token(/\$[_a-zA-Z0-9]+/),
		CONSTANT_VALUE: $ => choice(
			$.NUMBER, $.DURATION, $.DISTANCE, $.QUANTITY,
			$.BOOL, $.CONSTANT,
			$.COLOR, $.QUOTED_STRING, $.BAREWORD,
		),

		bool: $ => choice($.BOOL, $.CONSTANT),
		bool_expandable: $ => choice($.bool, $.bool_expansion),
		bool_expansion: $ => seq(
			'[',
			seq($.bool, repeat(seq(',', $.bool)), optional(',')),
			']'
		),
		
		bareword: $ => choice($.BAREWORD, $.CONSTANT),
		bareword_expandable: $ => choice($.bareword, $.bareword_expansion),
		bareword_expansion: $ => seq(
			'[',
			optional(seq($.bareword, repeat(seq(',', $.bareword)), optional(','))),
			']'
		),

		quoted_string: $ => choice($.QUOTED_STRING, $.CONSTANT),
		quoted_string_expandable: $ => choice($.quoted_string, $.quoted_string_expansion),
		quoted_string_expansion: $ => seq(
			'[',
			optional(seq($.quoted_string, repeat(seq(',', $.quoted_string)), optional(','))),
			']'
		),

		string: $ => choice($.STRING, $.CONSTANT),
		string_expandable: $ => choice($.string, $.string_expansion),
		string_expansion: $ => seq(
			'[',
			optional(seq($.string, repeat(seq(',', $.string)), optional(','))),
			']'
		),

		number: $ => choice($.NUMBER, $.CONSTANT),
		number_expandable: $ => choice($.number, $.number_expansion),
		number_expansion: $ => seq(
			'[',
			optional(seq($.number, repeat(seq(',', $.number)), optional(','))),
			']'
		),

		duration: $ => choice($.DURATION, $.CONSTANT),
		duration_expandable: $ => choice($.duration, $.duration_expansion),
		duration_expansion: $ => seq(
			'[',
			seq($.duration, repeat(seq(',', $.duration)), optional(',')),
			']'
		),

		distance: $ => choice($.DISTANCE, $.CONSTANT),
		distance_expandable: $ => choice($.distance, $.distance_expansion),
		distance_expansion: $ => seq(
			'[',
			optional(seq($.distance, repeat(seq(',', $.distance)), optional(','))),
			']'
		),
		

		quantity: $ => choice($.QUANTITY, $.CONSTANT),
		quantity_expandable: $ => choice($.quantity, $.quantity_expansion),
		quantity_expansion: $ => seq(
			'[',
			optional(seq($.quantity, repeat(seq(',', $.quantity)), optional(','))),
			']'
		),

		color: $ => choice($.COLOR, $.CONSTANT),
		color_expandable: $ => choice($.color, $.color_expansion),
		color_expansion: $ => seq(
			'[',
			optional(seq($.color, repeat(seq(',', $.color)), optional(','))),
			']'
		),

		semicolon: $ => token(';'),

		_root: $ => choice(
			$.script_definition,
			$.constant_assignment,
			$.include_macro,
			$.add_serial_dialog_settings,
			$.serial_dialog_definition,
			$.add_dialog_settings,
			$.dialog_definition,
		),

		include_macro: $ => seq(
			'include', field('fileName', $.quoted_string_expandable), $.semicolon,
		),
		constant_assignment: $ => seq(
			field('label', $.CONSTANT),
			$.assignment_operator,
			field('value', $.CONSTANT_VALUE),
			$.semicolon,
		),
		add_serial_dialog_settings: $ => seq(
			'add', 'serial_dialog', 'settings', '{',
			repeat($.serial_dialog_parameter),
			'}'
		),
		serial_dialog_parameter: $ => choice(
			seq(
				field('property', 'wrap'), // can add more later
				field('value', $.number),
			),
		),
		add_dialog_settings: $ => seq(
			'add', 'dialog', 'settings', '{',
				repeat($.add_dialog_settings_target),
			'}',
		),
		add_dialog_settings_target: $ => seq(
			choice(
				field('type', 'default'),
				seq(field('type', 'label'), field('target', $.bareword)),
				seq(field('type', 'entity'), field('target', $.string)),
			),
			'{', repeat(field('dialog_parameter', $.dialog_parameter)), '}'
		),
		dialog_parameter: $ => choice(
			seq(
				field('property', choice(
					'wrap', 'emote',
				)),
				field('value', $.number),
			),
			seq(
				field('property', choice(
					'entity', 'name', 'portrait', 'alignment', 'border_tileset'
				)),
				field('value', $.string),
			),
		),
		dialog_definition: $ => seq(
			'dialog',
			field('dialog_name', $.string),
			$._dialog_block,
		),
		_dialog_block: $ => seq(
			'{',
			repeat(field('dialog', $.dialog)),
			'}'
		),
		dialog: $ => seq(
			field('dialog_identifier', $.dialog_identifier),
			repeat(field('dialog_parameter', $.dialog_parameter)),
			repeat1(field('message', $.QUOTED_STRING)),
			repeat(field('dialog_option', $.dialog_option)),
		),
		dialog_identifier: $ => choice(
			field('label', $.BAREWORD),
			seq(
				field('type', choice('entity', 'name')),
				field('value', $.STRING)
			),
		),
		dialog_option: $ => seq(
			'>',
			field('label', $.QUOTED_STRING),
			$.assignment_operator,
			field('script', $.string),
		),
		serial_dialog_definition: $ => seq(
			'serial_dialog',
			field('serial_dialog_name', $.STRING),
			$._serial_dialog_block,
		),
		_serial_dialog_block: $ => seq(
			'{',
			field('serial_dialog', optional($.serial_dialog)),
			'}'
		),
		serial_dialog: $ => seq(
			repeat(field('serial_dialog_parameter',$.serial_dialog_parameter)),
			repeat1(field('serial_message', $.QUOTED_STRING)),
			repeat(field('serial_dialog_option', $.serial_dialog_option)),
		),
		serial_dialog_option: $ => seq(
			field('option_type', choice('_', '#')),
			field('label', $.QUOTED_STRING),
			$.assignment_operator,
			field('script', $.string),
		),
		script_definition: $ => seq(
			optional('script'),
			field('script_name', $.STRING),
			field('script_block', $.script_block),
		),
		script_block: $ => seq('{', repeat($._script_item), '}'),
		_script_item: $ => choice(
			$.rand_macro,
			$.label_definition,
			$._action_item,
			$.json_literal,
			// $.debug_macro,
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

	// 	debug_macro: $ => seq(
	// 		'debug', '!', '(',
	// 		optional(choice(
	// 			field('serial_dialog', $.serial_dialog),
	// 			field('serial_dialog_name', $.bareword),
	// 		)),

	// 		')',
	// 	),
		rand_macro: $ => seq(
			'rand', '!', '(',
			repeat($._script_item),
			')',
		),
		label_definition: $ => seq(field('label', $.BAREWORD), ':'),

		_action_item: $ => choice(
			$.action_return_statement,
			$.action_close_dialog,
			$.action_close_serial_dialog,
			$.action_save_slot,
			$.action_load_slot,
			$.action_erase_slot,
			$.action_load_map,
			$.action_run_script,
			$.action_goto_label,
			$.action_goto_index,
			$.action_non_blocking_delay,
			$.action_blocking_delay,
			$.action_show_dialog,
			$.action_show_serial_dialog,
			$.action_concat_serial_dialog,
			$.action_delete_command,
			$.action_delete_command_arg,
			$.action_delete_alias,
			$.action_hide_command,
			$.action_unhide_command,
			$.action_pause_script,
			$.action_unpause_script,
			$.action_camera_shake,
			$.action_camera_fade_in,
			$.action_camera_fade_out,
			$.action_play_entity_animation,
			$.action_move_over_time,
			$.action_set_position,
			$.action_set_ambiguous,
			$.action_set_int,
			$.action_set_bool,
			// $.action_set_string,
			// $.if_chain,
			// $.while_block,
			// $.for_block,
		),
		action_return_statement: $ => seq('return', $.semicolon), 
		action_close_dialog: $ => seq('close', 'dialog', $.semicolon),
		action_close_serial_dialog: $ => seq('close', 'serial_dialog', $.semicolon),
		action_save_slot: $ => seq('save', 'slot', $.semicolon),
		action_load_slot: $ => seq('load', 'slot', field('slot', $.number_expandable), $.semicolon),
		action_erase_slot: $ => seq('erase', 'slot', field('slot', $.number_expandable), $.semicolon),
		action_load_map: $ => seq('load', 'map', field('map', $.string_expandable), $.semicolon),
		action_run_script: $ => seq('goto', field('script', $.string_expandable), $.semicolon),
		action_goto_label: $ => seq('goto', 'label', field('label', $.bareword_expandable), $.semicolon),
		action_goto_index: $ => seq('goto', 'index', field('index', $.number_expandable), $.semicolon),
		action_non_blocking_delay: $ => seq('wait', field('duration', $.duration_expandable), $.semicolon),
		action_blocking_delay: $ => seq('block', field('duration', $.duration_expandable), $.semicolon),

		action_show_dialog: $ => seq(
			'show', 'dialog', choice(
				seq(field('dialog_name', $.STRING), $._dialog_block),
				field('dialog_name', $.STRING),
				$._dialog_block,
			),
			$.semicolon
		),
		action_show_serial_dialog: $ => seq(
			'show', 'serial_dialog', choice(
				seq(field('serial_dialog_name', $.STRING), $._serial_dialog_block),
				field('serial_dialog_name', $.STRING),
				$._serial_dialog_block,
			),
			$.semicolon
		),
		action_concat_serial_dialog: $ => seq(
			'concat', 'serial_dialog', choice(
				seq(field('serial_dialog_name', $.STRING), $._serial_dialog_block),
				field('serial_dialog_name', $.STRING),
				$._serial_dialog_block,
			),
			$.semicolon
		),
		
		action_delete_command: $ => seq('delete', 'command', field('command', $.string_expandable), $.semicolon),
		action_delete_command_arg: $ => seq(
			'delete', 'command', field('command', $.string_expandable),
			'+', field('argument', $.string_expandable), $.semicolon,
		),
		action_delete_alias: $ => seq('delete', 'alias', field('alias', $.string_expandable), $.semicolon),
		action_hide_command: $ => seq('hide', 'command', field('command', $.string_expandable), $.semicolon),
		action_unhide_command: $ => seq('unhide', 'command', field('command', $.string_expandable), $.semicolon),

		entity_identifier: $ => choice(
			field('type', 'player'),
			field('type', 'self'),
			seq(field('type', 'entity'), field('entity', $.string))
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
		entity_or_map_identifier: $ => choice(
			field('type', 'map'),
			field('type', 'player'),
			field('type', 'self'),
			seq(field('type', 'entity'), field('entity', $.string))
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
			field('entity_or_map', $.entity_or_map_identifier_expandable),
			field('script', $.string_expandable),
			$.semicolon
		),
		action_unpause_script: $ => seq(
			'unpause',
			field('entity_or_map', $.entity_or_map_identifier_expandable),
			field('script', $.string_expandable),
			$.semicolon
		),

		action_camera_fade_in: $ => seq(
			'camera', 'fade', 'in', '->',
			field('color', $.color_expandable),
			'over',
			field('duration', $.duration_expandable),
			$.semicolon
		),
		action_camera_fade_out: $ => seq(
			'camera', 'fade', 'out', '->',
			field('color', $.color_expandable),
			'over',
			field('duration', $.duration_expandable),
			$.semicolon
		),
		
		action_camera_shake: $ => seq(
			'camera', 'shake', '->',
			field('amplitude', $.duration_expandable),
			field('distance', $.distance_expandable),
			'over',
			field('duration', $.duration_expandable),
			$.semicolon
		),

		action_play_entity_animation: $ => seq(
			field('entity_identifier', $.entity_identifier_expandable),
			'animation', '->',
			field('animation', $.number_expandable),
			field('count', $.quantity_expandable),
			$.semicolon
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

		movable_identifier: $ => choice(
			field('type', 'camera'),
			seq(field('type', 'player'), 'position'),
			seq(field('type', 'self'), 'position'),
			seq(field('type', 'entity'), field('entity', $.string), 'position'),
		),
		movable_identifier_expandable: $ => choice(
			$.movable_identifier,
			$.movable_identifier_expansion,
		),
		movable_identifier_expansion: $ => prec(1, seq(
			'[',
			optional(seq(
				$.movable_identifier,
				repeat(seq(',', $.movable_identifier)),
				optional(','),
			)),
			']'
		)),

		origin: $ => 'origin',
		length: $ => 'length',
		geometry: $ => 'geometry',
		coordinate_identifier: $ => choice(
			seq(field('type', 'player'), 'position'),
			seq(field('type', 'self'), 'position'),
			seq(field('type', 'entity'), field('entity', $.string), 'position'),
			seq(
				field('type', $.geometry),
				field('geometry', $.string),
				optional(choice(
					field('polygon_type', $.origin),
					field('polygon_type', $.length),
				))
			),
		),
		coordinate_identifier_expandable: $ => choice(
			$.coordinate_identifier,
			$.coordinate_identifier_expansion,
		),
		coordinate_identifier_expansion: $ => prec(1, seq(
			'[',
			optional(seq(
				$.coordinate_identifier,
				repeat(seq(',', $.coordinate_identifier)),
				optional(','),
			)),
			']'
		)),
		
		over_time_operator: $ => '->',
		forever: $ => 'forever',
		action_move_over_time: $ => seq(
			field('movable', $.movable_identifier_expandable),
			$.over_time_operator,
			field('coordinate', $.coordinate_identifier_expandable),
			'over',
			field('duration', $.duration_expandable),
			optional(field('forever', $.forever)),
			$.semicolon
		),
		
		assignment_operator: $ => '=',
		action_set_position: $ => seq(
			field('movable', $.movable_identifier_expandable),
			$.assignment_operator,
			field('coordinate', $.coordinate_identifier_expandable),
			$.semicolon
		),

		ambiguous_identifier: $ => prec(2, choice(
			$.STRING,
			$.CONSTANT
		)),
		ambiguous_identifier_expandable: $ => choice(
			$.ambiguous_identifier,
			$.ambiguous_identifier_expansion,
		),
		ambiguous_identifier_expansion: $ => seq(
			'[',
			optional(seq(
				$.ambiguous_identifier,
				repeat(seq(',', $.ambiguous_identifier)),
				optional(','),
			)),
			']'
		),

		action_set_ambiguous: $ => seq(
			field('ambiguous_lhs', $.ambiguous_identifier_expandable),
			$.assignment_operator,
			choice(
				field('int_exp_rhs', $._int_expression),
				field('bool_exp_rhs', $.bool_expression_expandable),
				field('ambiguous_rhs', $.ambiguous_identifier_expandable),
			),
			$.semicolon
		),

		identifier: $ => $.string,
		AND: $ => '&&',
		OR: $ => '||',
		BANG: $ => '!',
		// COMPARISON: $ => choice('>', '>=', '<', '<='),
		// EQUALITY: $ => choice('==', '!='),
		_bool_unit: $ => choice(
			$.BOOL,
			$.CONSTANT,
			$.bool_getable,
			$.bool_unary_expression,
			seq('(', $._bool_expression, ')'),
			$.STRING,
		),

		_bool_expression: $ => choice(
			$.bool_binary_expression,
			$._bool_unit,
		),
		bool_expression_expandable: $ => choice(
			$._bool_expression,
			$.bool_expression_expansion,
		),
		bool_expression_expansion: $ => prec(1,seq(
			'[',
			optional(seq(
				$._bool_expression,
				repeat(seq(',', $._bool_expression)),
				optional(','),
			)),
			']'
		)),

		bool_unary_expression: $ => prec.right(6, seq(field('unary_operator', "!"), $._bool_unit)),
		bool_binary_expression: $ => choice(
			// prec.left(5, seq($._expression, field('binary_operator', $.COMPARISON), $._expression)),
			// prec.left(4, seq($._expression, field('binary_operator', $.EQUALITY), $._expression)),
			prec.left(3, seq($._bool_expression, field('binary_operator', $.AND), $._bool_expression)),
			prec.left(2, seq($._bool_expression, field('binary_operator', $.OR), $._bool_expression)),
		),

		action_set_bool: $ => seq(
			field('bool_exp_lhs', $.bool_setable_expandable), 
			$.assignment_operator,
			field('bool_exp_rhs', $.bool_expression_expandable),
			$.semicolon,
		),
		bool_setable: $ => choice(
			field('type', 'player_control'),
			field('type', 'lights_control'),
			field('type', 'hex_editor'),
			field('type', 'hex_dialog_mode'),
			field('type', 'hex_control'),
			field('type', 'hex_clipboard'),
			field('type', 'serial_control'),
			seq(
				field('entity_identifier', $.entity_identifier),
				field('type', 'glitched')
			),
			seq(
				field('type', 'light'),
				field('light', $.string_expandable)
			),
			field('flag', $.string),
		),
		bool_setable_expandable: $ => choice(
			$.bool_setable,
			$.bool_setable_expansion,
		),
		bool_setable_expansion: $ => seq(
			'[',
			optional(seq(
				$.bool_setable,
				repeat(seq(',', $.bool_setable)),
				optional(','),
			)),
			']'
		),

		bool_getable: $ => choice(
			field('type', 'debug_mode'),
			seq(
				field('entity_identifier', $.entity_identifier),
				field('type', 'glitched'),
			),
			seq(
				field('type', 'dialog'),
				'open'
			),
			seq(
				field('type', 'serial_dialog'),
				'open'
			),
			seq(
				field('type', 'button'),
				field('button', $.string),
				field('state', choice($.bool, 'pressed')),
			),
			seq(
				field('entity_identifier', $.entity_identifier),
				field('type', 'intersects'),
				field('geometry_identifier', $.geometry_identifier),
			),
		),

		MUL_DIV_MOD: $ => choice('*', '/', '%'),
		ADD_SUB: $ => choice('+', '-'),
		_int_unit: $ => prec(1, choice(
			$.entity_int_getable,
			$.NUMBER,
			$.CONSTANT,
			$.STRING,
			seq('(', $._int_expression, ')'),
		)),

		_int_expression: $ => choice(
			$.int_binary_expression,
			$._int_unit,
		),
		int_expression_expandable: $ => choice(
			$._int_expression,
			$.int_expression_expansion,
		),
		int_expression_expansion: $ => seq(
			'[',
			optional(seq(
				$._int_expression,
				repeat(seq(',', $._int_expression)),
				optional(','),
			)),
			']'
		),

		int_binary_expression: $ => choice(
			prec.left(3, seq($._int_expression, field('binary_operator', $.MUL_DIV_MOD), $._int_expression)),
			prec.left(2, seq($._int_expression, field('binary_operator', $.ADD_SUB), $._int_expression)),
		),

		action_set_int: $ => seq(
			field('int_exp_lhs', $.int_setable_expandable), 
			$.assignment_operator,
			field('int_exp_rhs', $._int_expression),
			$.semicolon,
		),
		int_setable: $ => choice( // BOOLINT
			seq(
				field('entity_identifier', $.entity_identifier),
				field('property', $.entity_property_int)
			),
			field('variable', $.string),
		),
		int_setable_expandable: $ => choice(
			$.int_setable,
			$.int_setable_expansion,
		),
		int_setable_expansion: $ => seq(
			'[',
			optional(seq(
				$.int_setable,
				repeat(seq(',', $.int_setable)),
				optional(','),
			)),
			']'
		),
		entity_int_getable: $ => choice(
			seq(
				field('entity_identifier', $.entity_identifier),
				field('property', $.entity_property_int)
			),
		),

	// 	if_chain: $ => seq( $.if_block, repeat($.if_else_block), optional($.else_block)),
	// 	if_block: $ => seq('if', '(', $.condition, ')', alias($.script_block, $.if_body)),
	// 	if_else_block: $ => seq('else', 'if', '(', $.condition, ')', alias($.script_block, $.if_else_body)),
	// 	else_block: $ => seq('else', alias($.script_block, $.else_body)),
	// 	condition: $ => choice(
	// 		$.bool_expression,
	// 	),
	// 	looping_block: $ => seq(
	// 		'{',
	// 		repeat(choice(
	// 			$._script_item,
	// 			seq('break', $.semicolon),
	// 			seq('continue', $.semicolon),
	// 		)),
	// 		'}'
	// 	),
	// 	while_block: $ => seq('while', '(', $.condition, ')', alias($.looping_block, $.while_body)),
	// 	do_while_block: $ => seq(
	// 		'do', alias($.looping_block, $.do_while_body),
	// 		'while', '(', $.condition, ')'
	// 	),
	// 	for_block: $ => seq(
	// 		'for',
	// 		'(',
	// 		$._action_item,
	// 		$.semicolon,
	// 		$.bool_expression,
	// 		$.semicolon,
	// 		$._action_item,
	// 		')',
	// 		alias($.looping_block, $.for_body)
	// 	),

	entity_property_int: $ => choice(
		'x', 'y', 'primary_id', 'secondary_id', 'primary_id_type',
		'current_animation', 'animation_frame', 'strafe'
	),

	// 	entity_property_string: $ => choice(
	// 		'name', 'path', 'on_tick', 'on_look', 'on_interact'
	// 	),
	// 	entity_property_string_expandable: $ => choice(
	// 		$.entity_property_string,
	// 		$.entity_property_string_expansion,
	// 	),
	// 	entity_property_string_expansion: $ => seq(
	// 		'[',
	// 		optional(seq(
	// 			$.entity_property_string,
	// 			repeat(seq(',', $.entity_property_string)),
	// 			optional(','),
	// 		)),
	// 		']'
	// 	),

	// 	fail: $ => 'fail',
	// 	string_setable: $ => choice(
	// 		seq('alias', field('alias', $.string_expandable)),
	// 		'serial_connect',
	// 		'warp_state',
	// 		seq($.entity_or_map_identifier, field('property', $.entity_property_string_expandable)),
	// 		seq(
	// 			'command', field('command', $.string_expandable),
	// 			optional(choice(
	// 				$.fail,
	// 				seq('+', field('argument', $.string_expandable))
	// 			)),
	// 		)
	// 	),
	// 	string_setable_expandable: $ => choice(
	// 		$.string_setable,
	// 		$.string_setable_expansion,
	// 	),
	// 	string_setable_expansion: $ => seq(
	// 		'[',
	// 		optional(seq(
	// 			$.string_setable,
	// 			repeat(seq(',', $.string_setable)),
	// 			optional(','),
	// 		)),
	// 		']'
	// 	),
	// 	action_set_string: $ => seq(
	// 		$.string_setable, 
	// 		$.assignment_operator,
	// 		$.string_expandable,
	// 	),

	// 	direction: $ => choice('north','south','east','west','n','e','s','w','N','E','S','W'),
	// 	action_set_entity_direction: $=> seq(
	// 		$.entity_identifier_expandable,
	// 		'direction',
	// 		$.assignment_operator, // and also math operators
	// 		choice(
	// 			field('toward_entity', $.entity_identifier_expandable),
	// 			$.geometry_identifier_expandable,
	// 			$.direction,
	// 			$._int_expression
	// 			// and also numbers
	// 		)
	// 	)
	},



});
