/**
 * @file A custom scripting DSL for a custom game engine on a custom PCB
 * @author alamedyang <alamedyang@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
	name: "magegamescript",
	rules: {
		source_file: $ => repeat($._root),
		_STRING: $ => choice($.QUOTED_STRING, $.BAREWORD),
		QUOTED_STRING: $ => token(/"(?:[^"\\]|\\.)*"/),
		CONSTANT: $ => token(/\$[_a-zA-Z0-9]+/),
		BAREWORD: $ => token(/[_a-zA-Z][_a-zA-Z0-9]*/),
		NUMBER: $ => token(/[0-9]+/),
		DURATION: $ => token(/[0-9]+(m?s)?/),
		DISTANCE: $ => token(/[0-9]+(px|pix)?/),
		QUANTITY: $ => token(/once|twice|thrice|[0-9]+(x)?/),
		COLOR: $ => token(/white|black|red|green|blue|magenta|cyan|yellow|#[0-9]{3,6}/),
		_NUMBERISH: $ => choice($.NUMBER, $.DURATION, $.DISTANCE, $.QUANTITY),
		BOOLEAN: $ => token(/true|false|on|off|open|closed/),
		// OPERATOR: $ => /[\{\}\[\]\(\)<>\+-=\]|[!=><]=|\|\||&&|\->/,
		_root: $ => choice(
			$.include_macro,
			$.constant_assignment,
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
		// string_fancy: $ => choice(
		// 	$.string,
		// 	$.array_string,
		// 	$.constant_assignment,
		// ),
		// array_string: $ => seq(
		// 	'[', $.string, optional(seq(',', $.string)), ']',
		// ),
	}
});
