#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 175
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 103
#define ALIAS_COUNT 0
#define TOKEN_COUNT 50
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 17
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 28

enum ts_symbol_identifiers {
  sym_block_comment = 1,
  sym_line_comment = 2,
  sym_BOOL = 3,
  sym_BAREWORD = 4,
  anon_sym_LBRACK = 5,
  anon_sym_COMMA = 6,
  anon_sym_RBRACK = 7,
  sym_QUOTED_STRING = 8,
  sym_NUMBER = 9,
  sym_duration_suffix = 10,
  sym_distance_suffix = 11,
  sym_quantity_suffix = 12,
  aux_sym_QUANTITY_token1 = 13,
  sym_COLOR = 14,
  sym_CONSTANT = 15,
  anon_sym_include = 16,
  anon_sym_SEMI = 17,
  anon_sym_EQ = 18,
  anon_sym_add = 19,
  anon_sym_serial_dialog = 20,
  anon_sym_settings = 21,
  anon_sym_LBRACE = 22,
  anon_sym_RBRACE = 23,
  sym_serial_dialog_parameter_int = 24,
  sym_serial_dialog_option_type = 25,
  anon_sym_script = 26,
  anon_sym_json = 27,
  anon_sym_COLON = 28,
  sym_json_number = 29,
  anon_sym_true = 30,
  anon_sym_false = 31,
  anon_sym_null = 32,
  anon_sym_rand = 33,
  anon_sym_BANG = 34,
  anon_sym_LPAREN = 35,
  anon_sym_RPAREN = 36,
  sym_action_return_statement = 37,
  anon_sym_close = 38,
  anon_sym_dialog = 39,
  anon_sym_save = 40,
  anon_sym_slot = 41,
  anon_sym_load = 42,
  anon_sym_erase = 43,
  anon_sym_map = 44,
  anon_sym_goto = 45,
  anon_sym_label = 46,
  anon_sym_index = 47,
  anon_sym_wait = 48,
  anon_sym_block = 49,
  sym_document = 50,
  sym_bareword_expansion = 51,
  sym_quoted_string_expansion = 52,
  sym_string_expansion = 53,
  sym_number_expansion = 54,
  sym_DURATION = 55,
  sym_duration_expansion = 56,
  sym_DISTANCE = 57,
  sym_QUANTITY = 58,
  sym__root = 59,
  sym_include_macro = 60,
  sym_constant_assignment = 61,
  sym_add_serial_dialog_settings = 62,
  sym_serial_dialog_parameter = 63,
  sym_serial_dialog_definition = 64,
  sym__serial_dialog_block = 65,
  sym_serial_dialog = 66,
  sym_serial_dialog_option = 67,
  sym_script_definition = 68,
  sym_script_block = 69,
  sym__script_item = 70,
  sym_json_literal = 71,
  sym_json_array = 72,
  sym_json_object = 73,
  sym_json_name_value_pair = 74,
  sym__json_item = 75,
  sym_rand_macro = 76,
  sym_label = 77,
  sym__action_item = 78,
  sym_action_close_dialog = 79,
  sym_action_close_serial_dialog = 80,
  sym_action_save_slot = 81,
  sym_action_load_slot = 82,
  sym_action_erase_slot = 83,
  sym_action_load_map = 84,
  sym_action_run_script = 85,
  sym_action_goto_label = 86,
  sym_action_goto_index = 87,
  sym_action_non_blocking_delay = 88,
  sym_action_blocking_delay = 89,
  aux_sym_document_repeat1 = 90,
  aux_sym_bareword_expansion_repeat1 = 91,
  aux_sym_quoted_string_expansion_repeat1 = 92,
  aux_sym_string_expansion_repeat1 = 93,
  aux_sym_number_expansion_repeat1 = 94,
  aux_sym_duration_expansion_repeat1 = 95,
  aux_sym_add_serial_dialog_settings_repeat1 = 96,
  aux_sym_serial_dialog_repeat1 = 97,
  aux_sym_serial_dialog_repeat2 = 98,
  aux_sym_serial_dialog_repeat3 = 99,
  aux_sym_script_block_repeat1 = 100,
  aux_sym_json_array_repeat1 = 101,
  aux_sym_json_object_repeat1 = 102,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_block_comment] = "block_comment",
  [sym_line_comment] = "line_comment",
  [sym_BOOL] = "BOOL",
  [sym_BAREWORD] = "BAREWORD",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_QUOTED_STRING] = "QUOTED_STRING",
  [sym_NUMBER] = "NUMBER",
  [sym_duration_suffix] = "duration_suffix",
  [sym_distance_suffix] = "distance_suffix",
  [sym_quantity_suffix] = "quantity_suffix",
  [aux_sym_QUANTITY_token1] = "QUANTITY_token1",
  [sym_COLOR] = "COLOR",
  [sym_CONSTANT] = "CONSTANT",
  [anon_sym_include] = "include",
  [anon_sym_SEMI] = ";",
  [anon_sym_EQ] = "=",
  [anon_sym_add] = "add",
  [anon_sym_serial_dialog] = "serial_dialog",
  [anon_sym_settings] = "settings",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_serial_dialog_parameter_int] = "BAREWORD",
  [sym_serial_dialog_option_type] = "serial_dialog_option_type",
  [anon_sym_script] = "script",
  [anon_sym_json] = "json",
  [anon_sym_COLON] = ":",
  [sym_json_number] = "json_number",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_null] = "null",
  [anon_sym_rand] = "rand",
  [anon_sym_BANG] = "!",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_action_return_statement] = "action_return_statement",
  [anon_sym_close] = "close",
  [anon_sym_dialog] = "dialog",
  [anon_sym_save] = "save",
  [anon_sym_slot] = "slot",
  [anon_sym_load] = "load",
  [anon_sym_erase] = "erase",
  [anon_sym_map] = "map",
  [anon_sym_goto] = "goto",
  [anon_sym_label] = "label",
  [anon_sym_index] = "index",
  [anon_sym_wait] = "wait",
  [anon_sym_block] = "block",
  [sym_document] = "document",
  [sym_bareword_expansion] = "bareword_expansion",
  [sym_quoted_string_expansion] = "quoted_string_expansion",
  [sym_string_expansion] = "string_expansion",
  [sym_number_expansion] = "number_expansion",
  [sym_DURATION] = "DURATION",
  [sym_duration_expansion] = "duration_expansion",
  [sym_DISTANCE] = "DISTANCE",
  [sym_QUANTITY] = "QUANTITY",
  [sym__root] = "_root",
  [sym_include_macro] = "include_macro",
  [sym_constant_assignment] = "constant_assignment",
  [sym_add_serial_dialog_settings] = "add_serial_dialog_settings",
  [sym_serial_dialog_parameter] = "serial_dialog_parameter",
  [sym_serial_dialog_definition] = "serial_dialog_definition",
  [sym__serial_dialog_block] = "_serial_dialog_block",
  [sym_serial_dialog] = "serial_dialog",
  [sym_serial_dialog_option] = "serial_dialog_option",
  [sym_script_definition] = "script_definition",
  [sym_script_block] = "script_block",
  [sym__script_item] = "_script_item",
  [sym_json_literal] = "json_literal",
  [sym_json_array] = "json_array",
  [sym_json_object] = "json_object",
  [sym_json_name_value_pair] = "json_name_value_pair",
  [sym__json_item] = "_json_item",
  [sym_rand_macro] = "rand_macro",
  [sym_label] = "label",
  [sym__action_item] = "_action_item",
  [sym_action_close_dialog] = "action_close_dialog",
  [sym_action_close_serial_dialog] = "action_close_serial_dialog",
  [sym_action_save_slot] = "action_save_slot",
  [sym_action_load_slot] = "action_load_slot",
  [sym_action_erase_slot] = "action_erase_slot",
  [sym_action_load_map] = "action_load_map",
  [sym_action_run_script] = "action_run_script",
  [sym_action_goto_label] = "action_goto_label",
  [sym_action_goto_index] = "action_goto_index",
  [sym_action_non_blocking_delay] = "action_non_blocking_delay",
  [sym_action_blocking_delay] = "action_blocking_delay",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_bareword_expansion_repeat1] = "bareword_expansion_repeat1",
  [aux_sym_quoted_string_expansion_repeat1] = "quoted_string_expansion_repeat1",
  [aux_sym_string_expansion_repeat1] = "string_expansion_repeat1",
  [aux_sym_number_expansion_repeat1] = "number_expansion_repeat1",
  [aux_sym_duration_expansion_repeat1] = "duration_expansion_repeat1",
  [aux_sym_add_serial_dialog_settings_repeat1] = "add_serial_dialog_settings_repeat1",
  [aux_sym_serial_dialog_repeat1] = "serial_dialog_repeat1",
  [aux_sym_serial_dialog_repeat2] = "serial_dialog_repeat2",
  [aux_sym_serial_dialog_repeat3] = "serial_dialog_repeat3",
  [aux_sym_script_block_repeat1] = "script_block_repeat1",
  [aux_sym_json_array_repeat1] = "json_array_repeat1",
  [aux_sym_json_object_repeat1] = "json_object_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_block_comment] = sym_block_comment,
  [sym_line_comment] = sym_line_comment,
  [sym_BOOL] = sym_BOOL,
  [sym_BAREWORD] = sym_BAREWORD,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_QUOTED_STRING] = sym_QUOTED_STRING,
  [sym_NUMBER] = sym_NUMBER,
  [sym_duration_suffix] = sym_duration_suffix,
  [sym_distance_suffix] = sym_distance_suffix,
  [sym_quantity_suffix] = sym_quantity_suffix,
  [aux_sym_QUANTITY_token1] = aux_sym_QUANTITY_token1,
  [sym_COLOR] = sym_COLOR,
  [sym_CONSTANT] = sym_CONSTANT,
  [anon_sym_include] = anon_sym_include,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_add] = anon_sym_add,
  [anon_sym_serial_dialog] = anon_sym_serial_dialog,
  [anon_sym_settings] = anon_sym_settings,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_serial_dialog_parameter_int] = sym_BAREWORD,
  [sym_serial_dialog_option_type] = sym_serial_dialog_option_type,
  [anon_sym_script] = anon_sym_script,
  [anon_sym_json] = anon_sym_json,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_json_number] = sym_json_number,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_null] = anon_sym_null,
  [anon_sym_rand] = anon_sym_rand,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_action_return_statement] = sym_action_return_statement,
  [anon_sym_close] = anon_sym_close,
  [anon_sym_dialog] = anon_sym_dialog,
  [anon_sym_save] = anon_sym_save,
  [anon_sym_slot] = anon_sym_slot,
  [anon_sym_load] = anon_sym_load,
  [anon_sym_erase] = anon_sym_erase,
  [anon_sym_map] = anon_sym_map,
  [anon_sym_goto] = anon_sym_goto,
  [anon_sym_label] = anon_sym_label,
  [anon_sym_index] = anon_sym_index,
  [anon_sym_wait] = anon_sym_wait,
  [anon_sym_block] = anon_sym_block,
  [sym_document] = sym_document,
  [sym_bareword_expansion] = sym_bareword_expansion,
  [sym_quoted_string_expansion] = sym_quoted_string_expansion,
  [sym_string_expansion] = sym_string_expansion,
  [sym_number_expansion] = sym_number_expansion,
  [sym_DURATION] = sym_DURATION,
  [sym_duration_expansion] = sym_duration_expansion,
  [sym_DISTANCE] = sym_DISTANCE,
  [sym_QUANTITY] = sym_QUANTITY,
  [sym__root] = sym__root,
  [sym_include_macro] = sym_include_macro,
  [sym_constant_assignment] = sym_constant_assignment,
  [sym_add_serial_dialog_settings] = sym_add_serial_dialog_settings,
  [sym_serial_dialog_parameter] = sym_serial_dialog_parameter,
  [sym_serial_dialog_definition] = sym_serial_dialog_definition,
  [sym__serial_dialog_block] = sym__serial_dialog_block,
  [sym_serial_dialog] = sym_serial_dialog,
  [sym_serial_dialog_option] = sym_serial_dialog_option,
  [sym_script_definition] = sym_script_definition,
  [sym_script_block] = sym_script_block,
  [sym__script_item] = sym__script_item,
  [sym_json_literal] = sym_json_literal,
  [sym_json_array] = sym_json_array,
  [sym_json_object] = sym_json_object,
  [sym_json_name_value_pair] = sym_json_name_value_pair,
  [sym__json_item] = sym__json_item,
  [sym_rand_macro] = sym_rand_macro,
  [sym_label] = sym_label,
  [sym__action_item] = sym__action_item,
  [sym_action_close_dialog] = sym_action_close_dialog,
  [sym_action_close_serial_dialog] = sym_action_close_serial_dialog,
  [sym_action_save_slot] = sym_action_save_slot,
  [sym_action_load_slot] = sym_action_load_slot,
  [sym_action_erase_slot] = sym_action_erase_slot,
  [sym_action_load_map] = sym_action_load_map,
  [sym_action_run_script] = sym_action_run_script,
  [sym_action_goto_label] = sym_action_goto_label,
  [sym_action_goto_index] = sym_action_goto_index,
  [sym_action_non_blocking_delay] = sym_action_non_blocking_delay,
  [sym_action_blocking_delay] = sym_action_blocking_delay,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_bareword_expansion_repeat1] = aux_sym_bareword_expansion_repeat1,
  [aux_sym_quoted_string_expansion_repeat1] = aux_sym_quoted_string_expansion_repeat1,
  [aux_sym_string_expansion_repeat1] = aux_sym_string_expansion_repeat1,
  [aux_sym_number_expansion_repeat1] = aux_sym_number_expansion_repeat1,
  [aux_sym_duration_expansion_repeat1] = aux_sym_duration_expansion_repeat1,
  [aux_sym_add_serial_dialog_settings_repeat1] = aux_sym_add_serial_dialog_settings_repeat1,
  [aux_sym_serial_dialog_repeat1] = aux_sym_serial_dialog_repeat1,
  [aux_sym_serial_dialog_repeat2] = aux_sym_serial_dialog_repeat2,
  [aux_sym_serial_dialog_repeat3] = aux_sym_serial_dialog_repeat3,
  [aux_sym_script_block_repeat1] = aux_sym_script_block_repeat1,
  [aux_sym_json_array_repeat1] = aux_sym_json_array_repeat1,
  [aux_sym_json_object_repeat1] = aux_sym_json_object_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_block_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_BOOL] = {
    .visible = true,
    .named = true,
  },
  [sym_BAREWORD] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_QUOTED_STRING] = {
    .visible = true,
    .named = true,
  },
  [sym_NUMBER] = {
    .visible = true,
    .named = true,
  },
  [sym_duration_suffix] = {
    .visible = true,
    .named = true,
  },
  [sym_distance_suffix] = {
    .visible = true,
    .named = true,
  },
  [sym_quantity_suffix] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_QUANTITY_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_COLOR] = {
    .visible = true,
    .named = true,
  },
  [sym_CONSTANT] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_include] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_add] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_serial_dialog] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_settings] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_serial_dialog_parameter_int] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_dialog_option_type] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_script] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_json] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_json_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_null] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rand] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_action_return_statement] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_close] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_dialog] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_save] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_slot] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_load] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_erase] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_map] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_goto] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_label] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_index] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_wait] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_block] = {
    .visible = true,
    .named = false,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_bareword_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_string_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_string_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_number_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_DURATION] = {
    .visible = true,
    .named = true,
  },
  [sym_duration_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_DISTANCE] = {
    .visible = true,
    .named = true,
  },
  [sym_QUANTITY] = {
    .visible = true,
    .named = true,
  },
  [sym__root] = {
    .visible = false,
    .named = true,
  },
  [sym_include_macro] = {
    .visible = true,
    .named = true,
  },
  [sym_constant_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_add_serial_dialog_settings] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_dialog_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_dialog_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__serial_dialog_block] = {
    .visible = false,
    .named = true,
  },
  [sym_serial_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_serial_dialog_option] = {
    .visible = true,
    .named = true,
  },
  [sym_script_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_script_block] = {
    .visible = true,
    .named = true,
  },
  [sym__script_item] = {
    .visible = false,
    .named = true,
  },
  [sym_json_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_json_array] = {
    .visible = true,
    .named = true,
  },
  [sym_json_object] = {
    .visible = true,
    .named = true,
  },
  [sym_json_name_value_pair] = {
    .visible = true,
    .named = true,
  },
  [sym__json_item] = {
    .visible = false,
    .named = true,
  },
  [sym_rand_macro] = {
    .visible = true,
    .named = true,
  },
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym__action_item] = {
    .visible = false,
    .named = true,
  },
  [sym_action_close_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_action_close_serial_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_action_save_slot] = {
    .visible = true,
    .named = true,
  },
  [sym_action_load_slot] = {
    .visible = true,
    .named = true,
  },
  [sym_action_erase_slot] = {
    .visible = true,
    .named = true,
  },
  [sym_action_load_map] = {
    .visible = true,
    .named = true,
  },
  [sym_action_run_script] = {
    .visible = true,
    .named = true,
  },
  [sym_action_goto_label] = {
    .visible = true,
    .named = true,
  },
  [sym_action_goto_index] = {
    .visible = true,
    .named = true,
  },
  [sym_action_non_blocking_delay] = {
    .visible = true,
    .named = true,
  },
  [sym_action_blocking_delay] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_bareword_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_string_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_number_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_duration_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_add_serial_dialog_settings_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_serial_dialog_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_serial_dialog_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_serial_dialog_repeat3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_script_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_json_array_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_json_object_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_duration = 1,
  field_fileName = 2,
  field_index = 3,
  field_label = 4,
  field_map = 5,
  field_option_type = 6,
  field_property = 7,
  field_script = 8,
  field_script_name = 9,
  field_serial_dialog = 10,
  field_serial_dialog_name = 11,
  field_serial_dialog_option = 12,
  field_serial_dialog_parameter = 13,
  field_serial_message = 14,
  field_slot = 15,
  field_suffix = 16,
  field_value = 17,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_duration] = "duration",
  [field_fileName] = "fileName",
  [field_index] = "index",
  [field_label] = "label",
  [field_map] = "map",
  [field_option_type] = "option_type",
  [field_property] = "property",
  [field_script] = "script",
  [field_script_name] = "script_name",
  [field_serial_dialog] = "serial_dialog",
  [field_serial_dialog_name] = "serial_dialog_name",
  [field_serial_dialog_option] = "serial_dialog_option",
  [field_serial_dialog_parameter] = "serial_dialog_parameter",
  [field_serial_message] = "serial_message",
  [field_slot] = "slot",
  [field_suffix] = "suffix",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 1},
  [5] = {.index = 5, .length = 1},
  [6] = {.index = 6, .length = 1},
  [7] = {.index = 7, .length = 1},
  [8] = {.index = 8, .length = 2},
  [9] = {.index = 10, .length = 1},
  [10] = {.index = 11, .length = 1},
  [11] = {.index = 12, .length = 1},
  [12] = {.index = 13, .length = 1},
  [13] = {.index = 14, .length = 1},
  [14] = {.index = 15, .length = 1},
  [15] = {.index = 16, .length = 1},
  [16] = {.index = 17, .length = 1},
  [17] = {.index = 18, .length = 2},
  [18] = {.index = 20, .length = 1},
  [19] = {.index = 21, .length = 2},
  [20] = {.index = 23, .length = 2},
  [21] = {.index = 25, .length = 1},
  [22] = {.index = 26, .length = 2},
  [23] = {.index = 28, .length = 2},
  [24] = {.index = 30, .length = 3},
  [25] = {.index = 33, .length = 2},
  [26] = {.index = 35, .length = 2},
  [27] = {.index = 37, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_script_name, 0},
  [1] =
    {field_fileName, 1},
  [2] =
    {field_serial_dialog, 2, .inherited = true},
    {field_serial_dialog_name, 1},
  [4] =
    {field_script_name, 1},
  [5] =
    {field_label, 0},
  [6] =
    {field_script, 1},
  [7] =
    {field_duration, 1},
  [8] =
    {field_label, 0},
    {field_value, 2},
  [10] =
    {field_suffix, 1},
  [11] =
    {field_serial_message, 0},
  [12] =
    {field_serial_dialog_parameter, 0},
  [13] =
    {field_serial_message, 0, .inherited = true},
  [14] =
    {field_slot, 2},
  [15] =
    {field_map, 2},
  [16] =
    {field_label, 2},
  [17] =
    {field_index, 2},
  [18] =
    {field_property, 0},
    {field_value, 1},
  [20] =
    {field_serial_dialog, 1},
  [21] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_dialog_parameter, 1, .inherited = true},
  [23] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [25] =
    {field_serial_dialog_option, 0},
  [26] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [28] =
    {field_serial_dialog_option, 1, .inherited = true},
    {field_serial_message, 0, .inherited = true},
  [30] =
    {field_serial_dialog_option, 2, .inherited = true},
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [33] =
    {field_serial_dialog_option, 0, .inherited = true},
    {field_serial_dialog_option, 1, .inherited = true},
  [35] =
    {field_property, 0},
    {field_value, 2},
  [37] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
  [172] = 172,
  [173] = 173,
  [174] = 174,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(146);
      ADVANCE_MAP(
        '!', 304,
        '"', 6,
        '#', 291,
        '$', 142,
        '(', 305,
        ')', 306,
        ',', 264,
        '-', 12,
        '/', 8,
        ':', 296,
        ';', 280,
        '=', 281,
        'I', 89,
        '[', 263,
        ']', 265,
        '_', 290,
        'a', 40,
        'b', 77,
        'c', 78,
        'd', 72,
        'e', 112,
        'f', 20,
        'g', 99,
        'i', 90,
        'j', 118,
        'l', 14,
        'm', 16,
        'n', 130,
        'o', 91,
        'p', 65,
        'r', 25,
        's', 269,
        't', 63,
        'w', 23,
        'x', 271,
        'y', 57,
        '{', 287,
        '}', 288,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(144);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(267);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 6,
        '#', 139,
        '$', 142,
        '/', 8,
        'b', 213,
        'c', 218,
        'f', 163,
        'g', 244,
        'm', 157,
        'o', 196,
        'r', 190,
        't', 201,
        'w', 200,
        'y', 192,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(267);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(142);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '[') ADVANCE(263);
      if (lookahead == ']') ADVANCE(265);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(142);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '[') ADVANCE(263);
      if (lookahead == 'i') ADVANCE(228);
      if (lookahead == 'l') ADVANCE(154);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 6,
        ',', 264,
        '-', 12,
        '/', 8,
        ';', 280,
        'I', 89,
        '[', 263,
        ']', 265,
        'f', 20,
        'm', 116,
        'n', 130,
        'p', 65,
        's', 268,
        't', 111,
        'x', 271,
        '{', 287,
        '}', 288,
        '#', 290,
        '_', 290,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(298);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '"', 6,
        ',', 264,
        '-', 12,
        '/', 8,
        ';', 280,
        'I', 89,
        '[', 263,
        ']', 265,
        'f', 20,
        'n', 130,
        't', 111,
        '{', 287,
        '}', 288,
        '#', 290,
        '_', 290,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(298);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(266);
      if (lookahead == '\\') ADVANCE(143);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        ')', 306,
        ',', 264,
        '/', 8,
        ']', 265,
        'b', 215,
        'c', 216,
        'e', 243,
        'g', 233,
        'j', 247,
        'l', 236,
        'r', 155,
        's', 153,
        'w', 160,
        '}', 288,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(148);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == 'd') ADVANCE(72);
      if (lookahead == 'm') ADVANCE(24);
      if (lookahead == 's') ADVANCE(43);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == 'I') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(298);
      END_STATE();
    case 13:
      if (lookahead == '_') ADVANCE(42);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(31);
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(62);
      if (lookahead == 's') ADVANCE(268);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(134);
      if (lookahead == 'c') ADVANCE(113);
      if (lookahead == 'e') ADVANCE(115);
      if (lookahead == 'l') ADVANCE(104);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(273);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(108);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(88);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(32);
      if (lookahead == 'o') ADVANCE(33);
      if (lookahead == 'u') ADVANCE(44);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(38);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(67);
      if (lookahead == 'h') ADVANCE(68);
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(107);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(96);
      if (lookahead == 'e') ADVANCE(37);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(83);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(92);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(81);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(120);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(86);
      END_STATE();
    case 31:
      if (lookahead == 'b') ADVANCE(55);
      END_STATE();
    case 32:
      if (lookahead == 'c') ADVANCE(75);
      END_STATE();
    case 33:
      if (lookahead == 'c') ADVANCE(76);
      END_STATE();
    case 34:
      if (lookahead == 'c') ADVANCE(82);
      if (lookahead == 'd') ADVANCE(52);
      END_STATE();
    case 35:
      if (lookahead == 'c') ADVANCE(45);
      END_STATE();
    case 36:
      if (lookahead == 'd') ADVANCE(282);
      END_STATE();
    case 37:
      if (lookahead == 'd') ADVANCE(273);
      if (lookahead == 't') ADVANCE(131);
      END_STATE();
    case 38:
      if (lookahead == 'd') ADVANCE(315);
      END_STATE();
    case 39:
      if (lookahead == 'd') ADVANCE(302);
      END_STATE();
    case 40:
      if (lookahead == 'd') ADVANCE(36);
      END_STATE();
    case 41:
      if (lookahead == 'd') ADVANCE(51);
      END_STATE();
    case 42:
      if (lookahead == 'd') ADVANCE(74);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(115);
      if (lookahead == 'l') ADVANCE(104);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(273);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(272);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(312);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(299);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(309);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(317);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(300);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(278);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(137);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(54);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(80);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(97);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(87);
      END_STATE();
    case 58:
      if (lookahead == 'f') ADVANCE(69);
      END_STATE();
    case 59:
      if (lookahead == 'g') ADVANCE(311);
      END_STATE();
    case 60:
      if (lookahead == 'g') ADVANCE(284);
      END_STATE();
    case 61:
      if (lookahead == 'g') ADVANCE(117);
      END_STATE();
    case 62:
      if (lookahead == 'g') ADVANCE(56);
      if (lookahead == 'p') ADVANCE(319);
      END_STATE();
    case 63:
      if (lookahead == 'h') ADVANCE(110);
      if (lookahead == 'r') ADVANCE(133);
      if (lookahead == 'w') ADVANCE(64);
      END_STATE();
    case 64:
      if (lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 65:
      if (lookahead == 'i') ADVANCE(136);
      if (lookahead == 'x') ADVANCE(270);
      END_STATE();
    case 66:
      if (lookahead == 'i') ADVANCE(109);
      END_STATE();
    case 67:
      if (lookahead == 'i') ADVANCE(123);
      END_STATE();
    case 68:
      if (lookahead == 'i') ADVANCE(126);
      END_STATE();
    case 69:
      if (lookahead == 'i') ADVANCE(98);
      END_STATE();
    case 70:
      if (lookahead == 'i') ADVANCE(125);
      END_STATE();
    case 71:
      if (lookahead == 'i') ADVANCE(95);
      END_STATE();
    case 72:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 73:
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 74:
      if (lookahead == 'i') ADVANCE(30);
      END_STATE();
    case 75:
      if (lookahead == 'k') ADVANCE(273);
      END_STATE();
    case 76:
      if (lookahead == 'k') ADVANCE(328);
      END_STATE();
    case 77:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 78:
      if (lookahead == 'l') ADVANCE(103);
      if (lookahead == 'y') ADVANCE(27);
      END_STATE();
    case 79:
      if (lookahead == 'l') ADVANCE(301);
      END_STATE();
    case 80:
      if (lookahead == 'l') ADVANCE(322);
      END_STATE();
    case 81:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 82:
      if (lookahead == 'l') ADVANCE(132);
      END_STATE();
    case 83:
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 84:
      if (lookahead == 'l') ADVANCE(79);
      END_STATE();
    case 85:
      if (lookahead == 'l') ADVANCE(102);
      END_STATE();
    case 86:
      if (lookahead == 'l') ADVANCE(105);
      END_STATE();
    case 87:
      if (lookahead == 'l') ADVANCE(85);
      END_STATE();
    case 88:
      if (lookahead == 'l') ADVANCE(121);
      END_STATE();
    case 89:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 90:
      if (lookahead == 'n') ADVANCE(34);
      END_STATE();
    case 91:
      if (lookahead == 'n') ADVANCE(35);
      END_STATE();
    case 92:
      if (lookahead == 'n') ADVANCE(273);
      END_STATE();
    case 93:
      if (lookahead == 'n') ADVANCE(294);
      END_STATE();
    case 94:
      if (lookahead == 'n') ADVANCE(307);
      END_STATE();
    case 95:
      if (lookahead == 'n') ADVANCE(61);
      END_STATE();
    case 96:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 97:
      if (lookahead == 'n') ADVANCE(128);
      END_STATE();
    case 98:
      if (lookahead == 'n') ADVANCE(70);
      END_STATE();
    case 99:
      if (lookahead == 'o') ADVANCE(127);
      if (lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 100:
      if (lookahead == 'o') ADVANCE(320);
      END_STATE();
    case 101:
      if (lookahead == 'o') ADVANCE(59);
      END_STATE();
    case 102:
      if (lookahead == 'o') ADVANCE(135);
      END_STATE();
    case 103:
      if (lookahead == 'o') ADVANCE(119);
      END_STATE();
    case 104:
      if (lookahead == 'o') ADVANCE(122);
      END_STATE();
    case 105:
      if (lookahead == 'o') ADVANCE(60);
      END_STATE();
    case 106:
      if (lookahead == 'o') ADVANCE(93);
      END_STATE();
    case 107:
      if (lookahead == 'p') ADVANCE(319);
      END_STATE();
    case 108:
      if (lookahead == 'p') ADVANCE(289);
      END_STATE();
    case 109:
      if (lookahead == 'p') ADVANCE(124);
      END_STATE();
    case 110:
      if (lookahead == 'r') ADVANCE(64);
      END_STATE();
    case 111:
      if (lookahead == 'r') ADVANCE(133);
      END_STATE();
    case 112:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 113:
      if (lookahead == 'r') ADVANCE(66);
      END_STATE();
    case 114:
      if (lookahead == 'r') ADVANCE(94);
      END_STATE();
    case 115:
      if (lookahead == 'r') ADVANCE(73);
      if (lookahead == 't') ADVANCE(129);
      END_STATE();
    case 116:
      if (lookahead == 's') ADVANCE(268);
      END_STATE();
    case 117:
      if (lookahead == 's') ADVANCE(286);
      END_STATE();
    case 118:
      if (lookahead == 's') ADVANCE(106);
      END_STATE();
    case 119:
      if (lookahead == 's') ADVANCE(48);
      END_STATE();
    case 120:
      if (lookahead == 's') ADVANCE(49);
      END_STATE();
    case 121:
      if (lookahead == 's') ADVANCE(50);
      END_STATE();
    case 122:
      if (lookahead == 't') ADVANCE(314);
      END_STATE();
    case 123:
      if (lookahead == 't') ADVANCE(326);
      END_STATE();
    case 124:
      if (lookahead == 't') ADVANCE(292);
      END_STATE();
    case 125:
      if (lookahead == 't') ADVANCE(138);
      END_STATE();
    case 126:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 127:
      if (lookahead == 't') ADVANCE(100);
      END_STATE();
    case 128:
      if (lookahead == 't') ADVANCE(18);
      END_STATE();
    case 129:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 130:
      if (lookahead == 'u') ADVANCE(84);
      END_STATE();
    case 131:
      if (lookahead == 'u') ADVANCE(114);
      END_STATE();
    case 132:
      if (lookahead == 'u') ADVANCE(41);
      END_STATE();
    case 133:
      if (lookahead == 'u') ADVANCE(47);
      END_STATE();
    case 134:
      if (lookahead == 'v') ADVANCE(46);
      END_STATE();
    case 135:
      if (lookahead == 'w') ADVANCE(273);
      END_STATE();
    case 136:
      if (lookahead == 'x') ADVANCE(270);
      END_STATE();
    case 137:
      if (lookahead == 'x') ADVANCE(324);
      END_STATE();
    case 138:
      if (lookahead == 'y') ADVANCE(297);
      END_STATE();
    case 139:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(141);
      END_STATE();
    case 140:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(276);
      END_STATE();
    case 141:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(140);
      END_STATE();
    case 142:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(277);
      END_STATE();
    case 143:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 144:
      if (eof) ADVANCE(146);
      ADVANCE_MAP(
        '!', 304,
        '"', 6,
        '#', 291,
        '$', 142,
        '(', 305,
        ')', 306,
        ',', 264,
        '-', 12,
        '/', 8,
        ':', 296,
        ';', 280,
        '=', 281,
        'I', 89,
        '[', 263,
        ']', 265,
        '_', 290,
        'a', 40,
        'b', 77,
        'c', 78,
        'd', 72,
        'e', 112,
        'f', 20,
        'g', 99,
        'i', 90,
        'j', 118,
        'l', 14,
        'm', 15,
        'n', 130,
        'o', 91,
        'r', 25,
        's', 17,
        't', 63,
        'w', 23,
        'y', 57,
        '{', 287,
        '}', 288,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(144);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(267);
      END_STATE();
    case 145:
      if (eof) ADVANCE(146);
      ADVANCE_MAP(
        '"', 6,
        '$', 142,
        '/', 8,
        '[', 263,
        ']', 265,
        'a', 177,
        'i', 222,
        's', 166,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(145);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(267);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(148);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(148);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(226);
      if (lookahead == 'e') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(169);
      if (lookahead == 'u') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(174);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(239);
      if (lookahead == 'e') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(197);
      if (lookahead == 'n') ADVANCE(149);
      if (lookahead == 'p') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(242);
      if (lookahead == 'r') ADVANCE(258);
      if (lookahead == 'w') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(170);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(323);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(237);
      if (lookahead == 'y') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(293);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(327);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(325);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(267);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(134);
      if (lookahead == 'c') ADVANCE(113);
      if (lookahead == 'e') ADVANCE(115);
      if (lookahead == 'l') ADVANCE(104);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(273);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(274);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(275);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(277);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_serial_dialog_parameter_int);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(141);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(298);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_action_return_statement);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_action_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(262);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 145},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 7},
  [5] = {.lex_state = 7},
  [6] = {.lex_state = 7},
  [7] = {.lex_state = 145},
  [8] = {.lex_state = 145},
  [9] = {.lex_state = 7},
  [10] = {.lex_state = 7},
  [11] = {.lex_state = 7},
  [12] = {.lex_state = 7},
  [13] = {.lex_state = 7},
  [14] = {.lex_state = 7},
  [15] = {.lex_state = 7},
  [16] = {.lex_state = 7},
  [17] = {.lex_state = 4},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 4},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 145},
  [22] = {.lex_state = 145},
  [23] = {.lex_state = 145},
  [24] = {.lex_state = 145},
  [25] = {.lex_state = 145},
  [26] = {.lex_state = 145},
  [27] = {.lex_state = 145},
  [28] = {.lex_state = 145},
  [29] = {.lex_state = 145},
  [30] = {.lex_state = 145},
  [31] = {.lex_state = 145},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 3},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 145},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 145},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 145},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 145},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 145},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 145},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 145},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 4},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 2},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 145},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 145},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 145},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 2},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 145},
  [100] = {.lex_state = 145},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 145},
  [104] = {.lex_state = 11},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 2},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 11},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 4},
  [123] = {.lex_state = 145},
  [124] = {.lex_state = 2},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 11},
  [131] = {.lex_state = 11},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 11},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 11},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_QUOTED_STRING] = ACTIONS(1),
    [sym_NUMBER] = ACTIONS(1),
    [sym_duration_suffix] = ACTIONS(1),
    [sym_distance_suffix] = ACTIONS(1),
    [sym_quantity_suffix] = ACTIONS(1),
    [aux_sym_QUANTITY_token1] = ACTIONS(1),
    [sym_COLOR] = ACTIONS(1),
    [sym_CONSTANT] = ACTIONS(1),
    [anon_sym_include] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_add] = ACTIONS(1),
    [anon_sym_serial_dialog] = ACTIONS(1),
    [anon_sym_settings] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_serial_dialog_parameter_int] = ACTIONS(1),
    [sym_serial_dialog_option_type] = ACTIONS(1),
    [anon_sym_script] = ACTIONS(1),
    [anon_sym_json] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_json_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [anon_sym_rand] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_action_return_statement] = ACTIONS(1),
    [anon_sym_close] = ACTIONS(1),
    [anon_sym_dialog] = ACTIONS(1),
    [anon_sym_save] = ACTIONS(1),
    [anon_sym_slot] = ACTIONS(1),
    [anon_sym_load] = ACTIONS(1),
    [anon_sym_erase] = ACTIONS(1),
    [anon_sym_map] = ACTIONS(1),
    [anon_sym_goto] = ACTIONS(1),
    [anon_sym_label] = ACTIONS(1),
    [anon_sym_index] = ACTIONS(1),
    [anon_sym_wait] = ACTIONS(1),
    [anon_sym_block] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(155),
    [sym__root] = STATE(8),
    [sym_include_macro] = STATE(8),
    [sym_constant_assignment] = STATE(8),
    [sym_add_serial_dialog_settings] = STATE(8),
    [sym_serial_dialog_definition] = STATE(8),
    [sym_script_definition] = STATE(8),
    [aux_sym_document_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(7),
    [sym_QUOTED_STRING] = ACTIONS(9),
    [sym_CONSTANT] = ACTIONS(11),
    [anon_sym_include] = ACTIONS(13),
    [anon_sym_add] = ACTIONS(15),
    [anon_sym_serial_dialog] = ACTIONS(17),
    [anon_sym_script] = ACTIONS(19),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 15,
    ACTIONS(21), 1,
      sym_BAREWORD,
    ACTIONS(26), 1,
      anon_sym_json,
    ACTIONS(29), 1,
      anon_sym_rand,
    ACTIONS(32), 1,
      sym_action_return_statement,
    ACTIONS(35), 1,
      anon_sym_close,
    ACTIONS(38), 1,
      anon_sym_save,
    ACTIONS(41), 1,
      anon_sym_load,
    ACTIONS(44), 1,
      anon_sym_erase,
    ACTIONS(47), 1,
      anon_sym_goto,
    ACTIONS(50), 1,
      anon_sym_wait,
    ACTIONS(53), 1,
      anon_sym_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(24), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(2), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(136), 12,
      sym__action_item,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
  [63] = 15,
    ACTIONS(56), 1,
      sym_BAREWORD,
    ACTIONS(58), 1,
      anon_sym_RBRACE,
    ACTIONS(60), 1,
      anon_sym_json,
    ACTIONS(62), 1,
      anon_sym_rand,
    ACTIONS(64), 1,
      sym_action_return_statement,
    ACTIONS(66), 1,
      anon_sym_close,
    ACTIONS(68), 1,
      anon_sym_save,
    ACTIONS(70), 1,
      anon_sym_load,
    ACTIONS(72), 1,
      anon_sym_erase,
    ACTIONS(74), 1,
      anon_sym_goto,
    ACTIONS(76), 1,
      anon_sym_wait,
    ACTIONS(78), 1,
      anon_sym_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(136), 12,
      sym__action_item,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
  [125] = 15,
    ACTIONS(56), 1,
      sym_BAREWORD,
    ACTIONS(60), 1,
      anon_sym_json,
    ACTIONS(62), 1,
      anon_sym_rand,
    ACTIONS(64), 1,
      sym_action_return_statement,
    ACTIONS(66), 1,
      anon_sym_close,
    ACTIONS(68), 1,
      anon_sym_save,
    ACTIONS(70), 1,
      anon_sym_load,
    ACTIONS(72), 1,
      anon_sym_erase,
    ACTIONS(74), 1,
      anon_sym_goto,
    ACTIONS(76), 1,
      anon_sym_wait,
    ACTIONS(78), 1,
      anon_sym_block,
    ACTIONS(80), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(3), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(136), 12,
      sym__action_item,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
  [187] = 15,
    ACTIONS(56), 1,
      sym_BAREWORD,
    ACTIONS(60), 1,
      anon_sym_json,
    ACTIONS(62), 1,
      anon_sym_rand,
    ACTIONS(64), 1,
      sym_action_return_statement,
    ACTIONS(66), 1,
      anon_sym_close,
    ACTIONS(68), 1,
      anon_sym_save,
    ACTIONS(70), 1,
      anon_sym_load,
    ACTIONS(72), 1,
      anon_sym_erase,
    ACTIONS(74), 1,
      anon_sym_goto,
    ACTIONS(76), 1,
      anon_sym_wait,
    ACTIONS(78), 1,
      anon_sym_block,
    ACTIONS(82), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(6), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(136), 12,
      sym__action_item,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
  [249] = 15,
    ACTIONS(56), 1,
      sym_BAREWORD,
    ACTIONS(60), 1,
      anon_sym_json,
    ACTIONS(62), 1,
      anon_sym_rand,
    ACTIONS(64), 1,
      sym_action_return_statement,
    ACTIONS(66), 1,
      anon_sym_close,
    ACTIONS(68), 1,
      anon_sym_save,
    ACTIONS(70), 1,
      anon_sym_load,
    ACTIONS(72), 1,
      anon_sym_erase,
    ACTIONS(74), 1,
      anon_sym_goto,
    ACTIONS(76), 1,
      anon_sym_wait,
    ACTIONS(78), 1,
      anon_sym_block,
    ACTIONS(84), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(136), 12,
      sym__action_item,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_save_slot,
      sym_action_load_slot,
      sym_action_erase_slot,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
      sym_action_non_blocking_delay,
      sym_action_blocking_delay,
  [311] = 10,
    ACTIONS(86), 1,
      ts_builtin_sym_end,
    ACTIONS(88), 1,
      sym_BAREWORD,
    ACTIONS(91), 1,
      sym_QUOTED_STRING,
    ACTIONS(94), 1,
      sym_CONSTANT,
    ACTIONS(97), 1,
      anon_sym_include,
    ACTIONS(100), 1,
      anon_sym_add,
    ACTIONS(103), 1,
      anon_sym_serial_dialog,
    ACTIONS(106), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(7), 7,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [349] = 10,
    ACTIONS(7), 1,
      sym_BAREWORD,
    ACTIONS(9), 1,
      sym_QUOTED_STRING,
    ACTIONS(11), 1,
      sym_CONSTANT,
    ACTIONS(13), 1,
      anon_sym_include,
    ACTIONS(15), 1,
      anon_sym_add,
    ACTIONS(17), 1,
      anon_sym_serial_dialog,
    ACTIONS(19), 1,
      anon_sym_script,
    ACTIONS(109), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(7), 7,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [387] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(113), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(111), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [411] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(117), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(115), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [435] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(121), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(119), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [459] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(125), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(123), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [481] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(129), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(127), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [503] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(133), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(131), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [525] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(137), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(135), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [547] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(141), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(139), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [569] = 6,
    ACTIONS(143), 1,
      anon_sym_LBRACK,
    ACTIONS(145), 1,
      anon_sym_RBRACK,
    ACTIONS(149), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(77), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(147), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [595] = 6,
    ACTIONS(155), 1,
      sym_NUMBER,
    ACTIONS(157), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(151), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(153), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(174), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [620] = 5,
    ACTIONS(143), 1,
      anon_sym_LBRACK,
    ACTIONS(149), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(113), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(159), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [643] = 5,
    ACTIONS(143), 1,
      anon_sym_LBRACK,
    ACTIONS(149), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(101), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(161), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [666] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(163), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(165), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [683] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(167), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(169), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [700] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(171), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(173), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [717] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(175), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(177), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [734] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(179), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(181), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [751] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(183), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(185), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [768] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(187), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(189), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [785] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(191), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(193), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [802] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(195), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(197), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [819] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(199), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(201), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [836] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(203), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(205), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [853] = 8,
    ACTIONS(207), 1,
      sym_QUOTED_STRING,
    ACTIONS(209), 1,
      anon_sym_RBRACE,
    ACTIONS(211), 1,
      sym_serial_dialog_parameter_int,
    STATE(34), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(38), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(112), 1,
      sym_serial_dialog_parameter,
    STATE(150), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [879] = 7,
    ACTIONS(213), 1,
      sym_BAREWORD,
    ACTIONS(215), 1,
      anon_sym_LBRACK,
    ACTIONS(219), 1,
      anon_sym_label,
    ACTIONS(221), 1,
      anon_sym_index,
    STATE(152), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(217), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [903] = 7,
    ACTIONS(207), 1,
      sym_QUOTED_STRING,
    ACTIONS(223), 1,
      anon_sym_RBRACE,
    ACTIONS(225), 1,
      sym_serial_dialog_option_type,
    STATE(49), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(50), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(109), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [926] = 7,
    ACTIONS(207), 1,
      sym_QUOTED_STRING,
    ACTIONS(225), 1,
      sym_serial_dialog_option_type,
    ACTIONS(227), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(56), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(109), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [949] = 4,
    ACTIONS(215), 1,
      anon_sym_LBRACK,
    STATE(163), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(229), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [965] = 5,
    ACTIONS(231), 1,
      anon_sym_LBRACK,
    ACTIONS(233), 1,
      sym_NUMBER,
    ACTIONS(235), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(126), 2,
      sym_DURATION,
      sym_duration_expansion,
  [983] = 6,
    ACTIONS(207), 1,
      sym_QUOTED_STRING,
    ACTIONS(211), 1,
      sym_serial_dialog_parameter_int,
    STATE(35), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(48), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(112), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1003] = 5,
    ACTIONS(231), 1,
      anon_sym_LBRACK,
    ACTIONS(233), 1,
      sym_NUMBER,
    ACTIONS(237), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(169), 2,
      sym_DURATION,
      sym_duration_expansion,
  [1021] = 4,
    ACTIONS(211), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(239), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(46), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1036] = 5,
    ACTIONS(233), 1,
      sym_NUMBER,
    ACTIONS(241), 1,
      anon_sym_RBRACK,
    ACTIONS(243), 1,
      sym_CONSTANT,
    STATE(106), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1053] = 4,
    ACTIONS(245), 1,
      anon_sym_LBRACK,
    STATE(133), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(247), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1068] = 4,
    ACTIONS(249), 1,
      anon_sym_LBRACK,
    STATE(166), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(251), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1083] = 3,
    ACTIONS(255), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(253), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1096] = 4,
    ACTIONS(259), 1,
      anon_sym_LBRACK,
    STATE(149), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(257), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1111] = 4,
    ACTIONS(211), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(261), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(55), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1126] = 4,
    ACTIONS(249), 1,
      anon_sym_LBRACK,
    STATE(127), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(263), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1141] = 5,
    ACTIONS(265), 1,
      sym_QUOTED_STRING,
    ACTIONS(267), 1,
      sym_serial_dialog_parameter_int,
    STATE(48), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(112), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1158] = 4,
    ACTIONS(270), 1,
      sym_QUOTED_STRING,
    STATE(49), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(273), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1173] = 5,
    ACTIONS(225), 1,
      sym_serial_dialog_option_type,
    ACTIONS(275), 1,
      anon_sym_RBRACE,
    STATE(57), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(109), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1190] = 3,
    ACTIONS(279), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(277), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [1203] = 4,
    ACTIONS(249), 1,
      anon_sym_LBRACK,
    STATE(162), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(281), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1218] = 3,
    ACTIONS(285), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(283), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1231] = 5,
    ACTIONS(233), 1,
      sym_NUMBER,
    ACTIONS(243), 1,
      sym_CONSTANT,
    ACTIONS(287), 1,
      anon_sym_RBRACK,
    STATE(106), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1248] = 4,
    ACTIONS(289), 1,
      anon_sym_RBRACE,
    ACTIONS(291), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(55), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1263] = 5,
    ACTIONS(225), 1,
      sym_serial_dialog_option_type,
    ACTIONS(294), 1,
      anon_sym_RBRACE,
    STATE(57), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(109), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1280] = 5,
    ACTIONS(296), 1,
      anon_sym_RBRACE,
    ACTIONS(298), 1,
      sym_serial_dialog_option_type,
    STATE(57), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(109), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1297] = 5,
    ACTIONS(279), 1,
      sym_duration_suffix,
    ACTIONS(301), 1,
      sym_distance_suffix,
    ACTIONS(303), 1,
      sym_quantity_suffix,
    ACTIONS(305), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1314] = 3,
    ACTIONS(307), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(283), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1327] = 4,
    ACTIONS(309), 1,
      anon_sym_COMMA,
    ACTIONS(311), 1,
      anon_sym_RBRACK,
    STATE(84), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1341] = 3,
    ACTIONS(315), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(313), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1353] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(317), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [1363] = 4,
    ACTIONS(319), 1,
      anon_sym_COMMA,
    ACTIONS(321), 1,
      anon_sym_RBRACE,
    STATE(79), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1377] = 4,
    ACTIONS(323), 1,
      anon_sym_COMMA,
    ACTIONS(325), 1,
      anon_sym_RBRACK,
    STATE(73), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1391] = 4,
    ACTIONS(327), 1,
      anon_sym_COMMA,
    ACTIONS(329), 1,
      anon_sym_RBRACK,
    STATE(81), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1405] = 4,
    ACTIONS(331), 1,
      anon_sym_COMMA,
    ACTIONS(333), 1,
      anon_sym_RBRACK,
    STATE(69), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1419] = 3,
    ACTIONS(335), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(337), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1431] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(339), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [1441] = 4,
    ACTIONS(341), 1,
      anon_sym_COMMA,
    ACTIONS(344), 1,
      anon_sym_RBRACK,
    STATE(69), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1455] = 4,
    ACTIONS(285), 1,
      anon_sym_RBRACK,
    ACTIONS(346), 1,
      anon_sym_COMMA,
    STATE(86), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1469] = 4,
    ACTIONS(348), 1,
      anon_sym_COMMA,
    ACTIONS(350), 1,
      anon_sym_RBRACK,
    STATE(88), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1483] = 3,
    ACTIONS(333), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(337), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1495] = 4,
    ACTIONS(287), 1,
      anon_sym_RBRACK,
    ACTIONS(352), 1,
      anon_sym_COMMA,
    STATE(90), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1509] = 3,
    ACTIONS(354), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(356), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1521] = 4,
    ACTIONS(358), 1,
      sym_QUOTED_STRING,
    ACTIONS(360), 1,
      anon_sym_RBRACE,
    STATE(63), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1535] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(362), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_parameter_int,
  [1545] = 4,
    ACTIONS(327), 1,
      anon_sym_COMMA,
    ACTIONS(364), 1,
      anon_sym_RBRACK,
    STATE(65), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1559] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(366), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [1569] = 4,
    ACTIONS(319), 1,
      anon_sym_COMMA,
    ACTIONS(368), 1,
      anon_sym_RBRACE,
    STATE(93), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1583] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(370), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1593] = 4,
    ACTIONS(372), 1,
      anon_sym_COMMA,
    ACTIONS(375), 1,
      anon_sym_RBRACK,
    STATE(81), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1607] = 4,
    ACTIONS(377), 1,
      anon_sym_COMMA,
    ACTIONS(379), 1,
      anon_sym_RBRACK,
    STATE(66), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1621] = 3,
    ACTIONS(381), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(383), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1633] = 4,
    ACTIONS(381), 1,
      anon_sym_RBRACK,
    ACTIONS(385), 1,
      anon_sym_COMMA,
    STATE(95), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1647] = 4,
    ACTIONS(233), 1,
      sym_NUMBER,
    ACTIONS(387), 1,
      sym_CONSTANT,
    STATE(64), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1661] = 4,
    ACTIONS(389), 1,
      anon_sym_COMMA,
    ACTIONS(392), 1,
      anon_sym_RBRACK,
    STATE(86), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1675] = 3,
    ACTIONS(396), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(394), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1687] = 4,
    ACTIONS(396), 1,
      anon_sym_RBRACK,
    ACTIONS(398), 1,
      anon_sym_COMMA,
    STATE(98), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1701] = 4,
    ACTIONS(400), 1,
      anon_sym_COMMA,
    ACTIONS(402), 1,
      anon_sym_RBRACK,
    STATE(70), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1715] = 4,
    ACTIONS(404), 1,
      anon_sym_COMMA,
    ACTIONS(407), 1,
      anon_sym_RBRACK,
    STATE(90), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1729] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1739] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(411), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [1749] = 4,
    ACTIONS(413), 1,
      anon_sym_COMMA,
    ACTIONS(416), 1,
      anon_sym_RBRACE,
    STATE(93), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1763] = 3,
    ACTIONS(418), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(383), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1775] = 4,
    ACTIONS(420), 1,
      anon_sym_COMMA,
    ACTIONS(423), 1,
      anon_sym_RBRACK,
    STATE(95), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1789] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(283), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1799] = 3,
    ACTIONS(425), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(394), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1811] = 4,
    ACTIONS(427), 1,
      anon_sym_COMMA,
    ACTIONS(430), 1,
      anon_sym_RBRACK,
    STATE(98), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1825] = 4,
    ACTIONS(233), 1,
      sym_NUMBER,
    ACTIONS(243), 1,
      sym_CONSTANT,
    STATE(106), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1839] = 3,
    ACTIONS(432), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(434), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1851] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(436), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1860] = 3,
    ACTIONS(438), 1,
      anon_sym_LBRACE,
    STATE(24), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1871] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(440), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1880] = 3,
    ACTIONS(442), 1,
      anon_sym_serial_dialog,
    ACTIONS(444), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1891] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(344), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1900] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(407), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1909] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(446), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1918] = 3,
    ACTIONS(358), 1,
      sym_QUOTED_STRING,
    STATE(111), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1929] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(448), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1938] = 3,
    ACTIONS(438), 1,
      anon_sym_LBRACE,
    STATE(21), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1949] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(416), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1958] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(450), 2,
      sym_QUOTED_STRING,
      sym_serial_dialog_parameter_int,
  [1967] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(375), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1976] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(423), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1985] = 3,
    ACTIONS(143), 1,
      anon_sym_LBRACK,
    STATE(14), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1996] = 3,
    ACTIONS(452), 1,
      anon_sym_LBRACE,
    STATE(23), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2007] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(454), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2016] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(430), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2025] = 3,
    ACTIONS(456), 1,
      anon_sym_slot,
    ACTIONS(458), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2036] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(337), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2045] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(392), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2054] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(460), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2063] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(383), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2072] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(394), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2081] = 2,
    ACTIONS(462), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2089] = 2,
    ACTIONS(464), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2097] = 2,
    ACTIONS(466), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2105] = 2,
    ACTIONS(468), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2113] = 2,
    ACTIONS(470), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2121] = 2,
    ACTIONS(472), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2129] = 2,
    ACTIONS(474), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2137] = 2,
    ACTIONS(476), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2145] = 2,
    ACTIONS(478), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2153] = 2,
    ACTIONS(480), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2161] = 2,
    ACTIONS(482), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2169] = 2,
    ACTIONS(484), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2177] = 2,
    ACTIONS(486), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2185] = 2,
    ACTIONS(488), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2193] = 2,
    ACTIONS(490), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2201] = 2,
    ACTIONS(492), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2209] = 2,
    ACTIONS(494), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2217] = 2,
    ACTIONS(496), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2225] = 2,
    ACTIONS(498), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2233] = 2,
    ACTIONS(500), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2241] = 2,
    ACTIONS(502), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2249] = 2,
    ACTIONS(504), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2257] = 2,
    ACTIONS(506), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2265] = 2,
    ACTIONS(508), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2273] = 2,
    ACTIONS(510), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2281] = 2,
    ACTIONS(512), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2289] = 2,
    ACTIONS(514), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2297] = 2,
    ACTIONS(516), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2305] = 2,
    ACTIONS(518), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2313] = 2,
    ACTIONS(520), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2321] = 2,
    ACTIONS(522), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2329] = 2,
    ACTIONS(524), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2337] = 2,
    ACTIONS(526), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2345] = 2,
    ACTIONS(528), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2353] = 2,
    ACTIONS(530), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2361] = 2,
    ACTIONS(532), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2369] = 2,
    ACTIONS(534), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2377] = 2,
    ACTIONS(536), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2385] = 2,
    ACTIONS(538), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2393] = 2,
    ACTIONS(540), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2401] = 2,
    ACTIONS(542), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2409] = 2,
    ACTIONS(544), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2417] = 2,
    ACTIONS(546), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2425] = 2,
    ACTIONS(548), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2433] = 2,
    ACTIONS(550), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2441] = 2,
    ACTIONS(552), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2449] = 2,
    ACTIONS(554), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2457] = 2,
    ACTIONS(556), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2465] = 2,
    ACTIONS(558), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2473] = 2,
    ACTIONS(305), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 63,
  [SMALL_STATE(4)] = 125,
  [SMALL_STATE(5)] = 187,
  [SMALL_STATE(6)] = 249,
  [SMALL_STATE(7)] = 311,
  [SMALL_STATE(8)] = 349,
  [SMALL_STATE(9)] = 387,
  [SMALL_STATE(10)] = 411,
  [SMALL_STATE(11)] = 435,
  [SMALL_STATE(12)] = 459,
  [SMALL_STATE(13)] = 481,
  [SMALL_STATE(14)] = 503,
  [SMALL_STATE(15)] = 525,
  [SMALL_STATE(16)] = 547,
  [SMALL_STATE(17)] = 569,
  [SMALL_STATE(18)] = 595,
  [SMALL_STATE(19)] = 620,
  [SMALL_STATE(20)] = 643,
  [SMALL_STATE(21)] = 666,
  [SMALL_STATE(22)] = 683,
  [SMALL_STATE(23)] = 700,
  [SMALL_STATE(24)] = 717,
  [SMALL_STATE(25)] = 734,
  [SMALL_STATE(26)] = 751,
  [SMALL_STATE(27)] = 768,
  [SMALL_STATE(28)] = 785,
  [SMALL_STATE(29)] = 802,
  [SMALL_STATE(30)] = 819,
  [SMALL_STATE(31)] = 836,
  [SMALL_STATE(32)] = 853,
  [SMALL_STATE(33)] = 879,
  [SMALL_STATE(34)] = 903,
  [SMALL_STATE(35)] = 926,
  [SMALL_STATE(36)] = 949,
  [SMALL_STATE(37)] = 965,
  [SMALL_STATE(38)] = 983,
  [SMALL_STATE(39)] = 1003,
  [SMALL_STATE(40)] = 1021,
  [SMALL_STATE(41)] = 1036,
  [SMALL_STATE(42)] = 1053,
  [SMALL_STATE(43)] = 1068,
  [SMALL_STATE(44)] = 1083,
  [SMALL_STATE(45)] = 1096,
  [SMALL_STATE(46)] = 1111,
  [SMALL_STATE(47)] = 1126,
  [SMALL_STATE(48)] = 1141,
  [SMALL_STATE(49)] = 1158,
  [SMALL_STATE(50)] = 1173,
  [SMALL_STATE(51)] = 1190,
  [SMALL_STATE(52)] = 1203,
  [SMALL_STATE(53)] = 1218,
  [SMALL_STATE(54)] = 1231,
  [SMALL_STATE(55)] = 1248,
  [SMALL_STATE(56)] = 1263,
  [SMALL_STATE(57)] = 1280,
  [SMALL_STATE(58)] = 1297,
  [SMALL_STATE(59)] = 1314,
  [SMALL_STATE(60)] = 1327,
  [SMALL_STATE(61)] = 1341,
  [SMALL_STATE(62)] = 1353,
  [SMALL_STATE(63)] = 1363,
  [SMALL_STATE(64)] = 1377,
  [SMALL_STATE(65)] = 1391,
  [SMALL_STATE(66)] = 1405,
  [SMALL_STATE(67)] = 1419,
  [SMALL_STATE(68)] = 1431,
  [SMALL_STATE(69)] = 1441,
  [SMALL_STATE(70)] = 1455,
  [SMALL_STATE(71)] = 1469,
  [SMALL_STATE(72)] = 1483,
  [SMALL_STATE(73)] = 1495,
  [SMALL_STATE(74)] = 1509,
  [SMALL_STATE(75)] = 1521,
  [SMALL_STATE(76)] = 1535,
  [SMALL_STATE(77)] = 1545,
  [SMALL_STATE(78)] = 1559,
  [SMALL_STATE(79)] = 1569,
  [SMALL_STATE(80)] = 1583,
  [SMALL_STATE(81)] = 1593,
  [SMALL_STATE(82)] = 1607,
  [SMALL_STATE(83)] = 1621,
  [SMALL_STATE(84)] = 1633,
  [SMALL_STATE(85)] = 1647,
  [SMALL_STATE(86)] = 1661,
  [SMALL_STATE(87)] = 1675,
  [SMALL_STATE(88)] = 1687,
  [SMALL_STATE(89)] = 1701,
  [SMALL_STATE(90)] = 1715,
  [SMALL_STATE(91)] = 1729,
  [SMALL_STATE(92)] = 1739,
  [SMALL_STATE(93)] = 1749,
  [SMALL_STATE(94)] = 1763,
  [SMALL_STATE(95)] = 1775,
  [SMALL_STATE(96)] = 1789,
  [SMALL_STATE(97)] = 1799,
  [SMALL_STATE(98)] = 1811,
  [SMALL_STATE(99)] = 1825,
  [SMALL_STATE(100)] = 1839,
  [SMALL_STATE(101)] = 1851,
  [SMALL_STATE(102)] = 1860,
  [SMALL_STATE(103)] = 1871,
  [SMALL_STATE(104)] = 1880,
  [SMALL_STATE(105)] = 1891,
  [SMALL_STATE(106)] = 1900,
  [SMALL_STATE(107)] = 1909,
  [SMALL_STATE(108)] = 1918,
  [SMALL_STATE(109)] = 1929,
  [SMALL_STATE(110)] = 1938,
  [SMALL_STATE(111)] = 1949,
  [SMALL_STATE(112)] = 1958,
  [SMALL_STATE(113)] = 1967,
  [SMALL_STATE(114)] = 1976,
  [SMALL_STATE(115)] = 1985,
  [SMALL_STATE(116)] = 1996,
  [SMALL_STATE(117)] = 2007,
  [SMALL_STATE(118)] = 2016,
  [SMALL_STATE(119)] = 2025,
  [SMALL_STATE(120)] = 2036,
  [SMALL_STATE(121)] = 2045,
  [SMALL_STATE(122)] = 2054,
  [SMALL_STATE(123)] = 2063,
  [SMALL_STATE(124)] = 2072,
  [SMALL_STATE(125)] = 2081,
  [SMALL_STATE(126)] = 2089,
  [SMALL_STATE(127)] = 2097,
  [SMALL_STATE(128)] = 2105,
  [SMALL_STATE(129)] = 2113,
  [SMALL_STATE(130)] = 2121,
  [SMALL_STATE(131)] = 2129,
  [SMALL_STATE(132)] = 2137,
  [SMALL_STATE(133)] = 2145,
  [SMALL_STATE(134)] = 2153,
  [SMALL_STATE(135)] = 2161,
  [SMALL_STATE(136)] = 2169,
  [SMALL_STATE(137)] = 2177,
  [SMALL_STATE(138)] = 2185,
  [SMALL_STATE(139)] = 2193,
  [SMALL_STATE(140)] = 2201,
  [SMALL_STATE(141)] = 2209,
  [SMALL_STATE(142)] = 2217,
  [SMALL_STATE(143)] = 2225,
  [SMALL_STATE(144)] = 2233,
  [SMALL_STATE(145)] = 2241,
  [SMALL_STATE(146)] = 2249,
  [SMALL_STATE(147)] = 2257,
  [SMALL_STATE(148)] = 2265,
  [SMALL_STATE(149)] = 2273,
  [SMALL_STATE(150)] = 2281,
  [SMALL_STATE(151)] = 2289,
  [SMALL_STATE(152)] = 2297,
  [SMALL_STATE(153)] = 2305,
  [SMALL_STATE(154)] = 2313,
  [SMALL_STATE(155)] = 2321,
  [SMALL_STATE(156)] = 2329,
  [SMALL_STATE(157)] = 2337,
  [SMALL_STATE(158)] = 2345,
  [SMALL_STATE(159)] = 2353,
  [SMALL_STATE(160)] = 2361,
  [SMALL_STATE(161)] = 2369,
  [SMALL_STATE(162)] = 2377,
  [SMALL_STATE(163)] = 2385,
  [SMALL_STATE(164)] = 2393,
  [SMALL_STATE(165)] = 2401,
  [SMALL_STATE(166)] = 2409,
  [SMALL_STATE(167)] = 2417,
  [SMALL_STATE(168)] = 2425,
  [SMALL_STATE(169)] = 2433,
  [SMALL_STATE(170)] = 2441,
  [SMALL_STATE(171)] = 2449,
  [SMALL_STATE(172)] = 2457,
  [SMALL_STATE(173)] = 2465,
  [SMALL_STATE(174)] = 2473,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(132),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(151),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(136),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(104),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(158),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(119),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(129),
  [97] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [100] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [103] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [106] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 5),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 5),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [151] = {.entry = {.count = 1, .reusable = false}}, SHIFT(174),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 4),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 4),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 18),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 18),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 12),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 20),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 19),
  [267] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 19), SHIFT_REPEAT(103),
  [270] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 22), SHIFT_REPEAT(80),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 22),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 23),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [291] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(103),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 24),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 25),
  [298] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 25), SHIFT_REPEAT(141),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 9),
  [341] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(120),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 17),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 10),
  [372] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [389] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [404] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [407] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [413] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(108),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [420] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(123),
  [423] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [427] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(124),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 26),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 21),
  [450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 11),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 27),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [464] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 7),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 16),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 9),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 9),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [496] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [498] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [500] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [504] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [508] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [510] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 15),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [516] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 6),
  [518] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [522] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [524] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [526] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [532] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [534] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [536] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 13),
  [538] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 14),
  [540] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [544] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 13),
  [546] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [548] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [550] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 7),
  [552] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [554] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [556] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [558] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_magegamescript(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
