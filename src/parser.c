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
#define STATE_COUNT 200
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 113
#define ALIAS_COUNT 0
#define TOKEN_COUNT 54
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 20
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 34

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
  anon_sym_dialog = 25,
  sym_target_default = 26,
  anon_sym_label = 27,
  sym_target_entity = 28,
  sym_dialog_parameter_int = 29,
  sym_dialog_parameter_string = 30,
  sym_serial_dialog_option_type = 31,
  anon_sym_script = 32,
  anon_sym_json = 33,
  anon_sym_COLON = 34,
  sym_json_number = 35,
  anon_sym_true = 36,
  anon_sym_false = 37,
  anon_sym_null = 38,
  anon_sym_rand = 39,
  anon_sym_BANG = 40,
  anon_sym_LPAREN = 41,
  anon_sym_RPAREN = 42,
  sym_action_return_statement = 43,
  anon_sym_close = 44,
  anon_sym_save = 45,
  anon_sym_slot = 46,
  anon_sym_load = 47,
  anon_sym_erase = 48,
  anon_sym_map = 49,
  anon_sym_goto = 50,
  anon_sym_index = 51,
  anon_sym_wait = 52,
  anon_sym_block = 53,
  sym_document = 54,
  sym_bareword_expansion = 55,
  sym_quoted_string_expansion = 56,
  sym_string_expansion = 57,
  sym_number_expansion = 58,
  sym_DURATION = 59,
  sym_duration_expansion = 60,
  sym_DISTANCE = 61,
  sym_QUANTITY = 62,
  sym__root = 63,
  sym_include_macro = 64,
  sym_constant_assignment = 65,
  sym_add_serial_dialog_settings = 66,
  sym_serial_dialog_parameter = 67,
  sym_add_dialog_settings = 68,
  sym_target_label = 69,
  sym_add_dialog_settings_target = 70,
  sym_dialog_parameter = 71,
  sym_serial_dialog_definition = 72,
  sym__serial_dialog_block = 73,
  sym_serial_dialog = 74,
  sym_serial_dialog_option = 75,
  sym_script_definition = 76,
  sym_script_block = 77,
  sym__script_item = 78,
  sym_json_literal = 79,
  sym_json_array = 80,
  sym_json_object = 81,
  sym_json_name_value_pair = 82,
  sym__json_item = 83,
  sym_rand_macro = 84,
  sym_label = 85,
  sym__action_item = 86,
  sym_action_close_dialog = 87,
  sym_action_close_serial_dialog = 88,
  sym_action_save_slot = 89,
  sym_action_load_slot = 90,
  sym_action_erase_slot = 91,
  sym_action_load_map = 92,
  sym_action_run_script = 93,
  sym_action_goto_label = 94,
  sym_action_goto_index = 95,
  sym_action_non_blocking_delay = 96,
  sym_action_blocking_delay = 97,
  aux_sym_document_repeat1 = 98,
  aux_sym_bareword_expansion_repeat1 = 99,
  aux_sym_quoted_string_expansion_repeat1 = 100,
  aux_sym_string_expansion_repeat1 = 101,
  aux_sym_number_expansion_repeat1 = 102,
  aux_sym_duration_expansion_repeat1 = 103,
  aux_sym_add_serial_dialog_settings_repeat1 = 104,
  aux_sym_add_dialog_settings_repeat1 = 105,
  aux_sym_add_dialog_settings_target_repeat1 = 106,
  aux_sym_serial_dialog_repeat1 = 107,
  aux_sym_serial_dialog_repeat2 = 108,
  aux_sym_serial_dialog_repeat3 = 109,
  aux_sym_script_block_repeat1 = 110,
  aux_sym_json_array_repeat1 = 111,
  aux_sym_json_object_repeat1 = 112,
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
  [anon_sym_dialog] = "dialog",
  [sym_target_default] = "target_default",
  [anon_sym_label] = "label",
  [sym_target_entity] = "target_entity",
  [sym_dialog_parameter_int] = "BAREWORD",
  [sym_dialog_parameter_string] = "BAREWORD",
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
  [anon_sym_save] = "save",
  [anon_sym_slot] = "slot",
  [anon_sym_load] = "load",
  [anon_sym_erase] = "erase",
  [anon_sym_map] = "map",
  [anon_sym_goto] = "goto",
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
  [sym_add_dialog_settings] = "add_dialog_settings",
  [sym_target_label] = "target_label",
  [sym_add_dialog_settings_target] = "add_dialog_settings_target",
  [sym_dialog_parameter] = "dialog_parameter",
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
  [aux_sym_add_dialog_settings_repeat1] = "add_dialog_settings_repeat1",
  [aux_sym_add_dialog_settings_target_repeat1] = "add_dialog_settings_target_repeat1",
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
  [anon_sym_dialog] = anon_sym_dialog,
  [sym_target_default] = sym_target_default,
  [anon_sym_label] = anon_sym_label,
  [sym_target_entity] = sym_target_entity,
  [sym_dialog_parameter_int] = sym_BAREWORD,
  [sym_dialog_parameter_string] = sym_BAREWORD,
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
  [anon_sym_save] = anon_sym_save,
  [anon_sym_slot] = anon_sym_slot,
  [anon_sym_load] = anon_sym_load,
  [anon_sym_erase] = anon_sym_erase,
  [anon_sym_map] = anon_sym_map,
  [anon_sym_goto] = anon_sym_goto,
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
  [sym_add_dialog_settings] = sym_add_dialog_settings,
  [sym_target_label] = sym_target_label,
  [sym_add_dialog_settings_target] = sym_add_dialog_settings_target,
  [sym_dialog_parameter] = sym_dialog_parameter,
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
  [aux_sym_add_dialog_settings_repeat1] = aux_sym_add_dialog_settings_repeat1,
  [aux_sym_add_dialog_settings_target_repeat1] = aux_sym_add_dialog_settings_target_repeat1,
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
  [anon_sym_dialog] = {
    .visible = true,
    .named = false,
  },
  [sym_target_default] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_label] = {
    .visible = true,
    .named = false,
  },
  [sym_target_entity] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_parameter_int] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_parameter_string] = {
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
  [sym_add_dialog_settings] = {
    .visible = true,
    .named = true,
  },
  [sym_target_label] = {
    .visible = true,
    .named = true,
  },
  [sym_add_dialog_settings_target] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_parameter] = {
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
  [aux_sym_add_dialog_settings_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_add_dialog_settings_target_repeat1] = {
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
  field_dialog_parameter = 1,
  field_duration = 2,
  field_fileName = 3,
  field_index = 4,
  field_label = 5,
  field_map = 6,
  field_option_type = 7,
  field_property = 8,
  field_script = 9,
  field_script_name = 10,
  field_serial_dialog = 11,
  field_serial_dialog_name = 12,
  field_serial_dialog_option = 13,
  field_serial_dialog_parameter = 14,
  field_serial_message = 15,
  field_slot = 16,
  field_suffix = 17,
  field_target = 18,
  field_type = 19,
  field_value = 20,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_dialog_parameter] = "dialog_parameter",
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
  [field_target] = "target",
  [field_type] = "type",
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
  [26] = {.index = 35, .length = 1},
  [27] = {.index = 36, .length = 1},
  [28] = {.index = 37, .length = 2},
  [29] = {.index = 39, .length = 2},
  [30] = {.index = 41, .length = 2},
  [31] = {.index = 43, .length = 2},
  [32] = {.index = 45, .length = 3},
  [33] = {.index = 48, .length = 3},
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
    {field_type, 0},
  [36] =
    {field_dialog_parameter, 0},
  [37] =
    {field_property, 0},
    {field_value, 2},
  [39] =
    {field_dialog_parameter, 2, .inherited = true},
    {field_type, 0},
  [41] =
    {field_dialog_parameter, 0, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
  [43] =
    {field_target, 1},
    {field_type, 0},
  [45] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [48] =
    {field_dialog_parameter, 3, .inherited = true},
    {field_target, 1},
    {field_type, 0},
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
  [175] = 175,
  [176] = 176,
  [177] = 177,
  [178] = 178,
  [179] = 179,
  [180] = 180,
  [181] = 181,
  [182] = 182,
  [183] = 183,
  [184] = 184,
  [185] = 185,
  [186] = 186,
  [187] = 187,
  [188] = 188,
  [189] = 189,
  [190] = 190,
  [191] = 191,
  [192] = 192,
  [193] = 193,
  [194] = 194,
  [195] = 195,
  [196] = 196,
  [197] = 197,
  [198] = 198,
  [199] = 199,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(202);
      ADVANCE_MAP(
        '!', 367,
        '"', 6,
        '#', 354,
        '$', 198,
        '(', 368,
        ')', 369,
        ',', 320,
        '-', 12,
        '/', 8,
        ':', 359,
        ';', 336,
        '=', 337,
        'I', 120,
        '[', 319,
        ']', 321,
        '_', 353,
        'a', 43,
        'b', 102,
        'c', 103,
        'd', 63,
        'e', 116,
        'f', 15,
        'g', 138,
        'i', 122,
        'j', 161,
        'l', 17,
        'm', 19,
        'n', 21,
        'o', 123,
        'p', 83,
        'r', 31,
        's', 325,
        't', 81,
        'w', 27,
        'x', 327,
        'y', 71,
        '{', 343,
        '}', 344,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(200);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(323);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 6,
        '#', 195,
        '$', 198,
        '/', 8,
        'b', 269,
        'c', 274,
        'f', 219,
        'g', 300,
        'm', 213,
        'o', 252,
        'r', 246,
        't', 257,
        'w', 256,
        'y', 248,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(323);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(198);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '[') ADVANCE(319);
      if (lookahead == ']') ADVANCE(321);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(198);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '[') ADVANCE(319);
      if (lookahead == 'i') ADVANCE(284);
      if (lookahead == 'l') ADVANCE(210);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 6,
        ',', 320,
        '-', 12,
        '/', 8,
        ';', 336,
        'I', 120,
        '[', 319,
        ']', 321,
        'd', 62,
        'e', 121,
        'f', 15,
        'l', 16,
        'm', 159,
        'n', 183,
        'p', 84,
        's', 324,
        't', 148,
        'w', 153,
        'x', 327,
        '{', 343,
        '}', 344,
        '#', 353,
        '_', 353,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(361);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '"', 6,
        ',', 320,
        '-', 12,
        '/', 8,
        ';', 336,
        'I', 120,
        '[', 319,
        ']', 321,
        'd', 62,
        'e', 121,
        'f', 15,
        'l', 16,
        'n', 183,
        't', 148,
        'w', 153,
        '{', 343,
        '}', 344,
        '#', 353,
        '_', 353,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(361);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(322);
      if (lookahead == '\\') ADVANCE(199);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        ')', 369,
        ',', 320,
        '/', 8,
        ']', 321,
        'b', 271,
        'c', 272,
        'e', 299,
        'g', 289,
        'j', 303,
        'l', 292,
        'r', 211,
        's', 209,
        'w', 216,
        '}', 344,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(204);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 11:
      ADVANCE_MAP(
        '/', 8,
        'a', 101,
        'b', 133,
        'd', 96,
        'e', 117,
        'm', 30,
        'n', 20,
        'p', 137,
        's', 51,
        'w', 158,
        '}', 344,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == 'I') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(361);
      END_STATE();
    case 13:
      if (lookahead == '_') ADVANCE(50);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(177);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(115);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(38);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(38);
      if (lookahead == 'o') ADVANCE(26);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(80);
      if (lookahead == 's') ADVANCE(324);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(118);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(118);
      if (lookahead == 'u') ADVANCE(108);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(188);
      if (lookahead == 'c') ADVANCE(154);
      if (lookahead == 'e') ADVANCE(155);
      if (lookahead == 'l') ADVANCE(142);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(329);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(145);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(39);
      if (lookahead == 'o') ADVANCE(40);
      if (lookahead == 'u') ADVANCE(52);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(46);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(87);
      if (lookahead == 'h') ADVANCE(89);
      if (lookahead == 'r') ADVANCE(24);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(109);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(185);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(144);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(128);
      if (lookahead == 'e') ADVANCE(45);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(146);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(124);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(106);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(163);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(111);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(94);
      END_STATE();
    case 38:
      if (lookahead == 'b') ADVANCE(67);
      END_STATE();
    case 39:
      if (lookahead == 'c') ADVANCE(99);
      END_STATE();
    case 40:
      if (lookahead == 'c') ADVANCE(100);
      END_STATE();
    case 41:
      if (lookahead == 'c') ADVANCE(107);
      if (lookahead == 'd') ADVANCE(64);
      END_STATE();
    case 42:
      if (lookahead == 'c') ADVANCE(54);
      END_STATE();
    case 43:
      if (lookahead == 'd') ADVANCE(44);
      if (lookahead == 'l') ADVANCE(85);
      END_STATE();
    case 44:
      if (lookahead == 'd') ADVANCE(338);
      END_STATE();
    case 45:
      if (lookahead == 'd') ADVANCE(329);
      if (lookahead == 't') ADVANCE(184);
      END_STATE();
    case 46:
      if (lookahead == 'd') ADVANCE(377);
      END_STATE();
    case 47:
      if (lookahead == 'd') ADVANCE(365);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(68);
      END_STATE();
    case 49:
      if (lookahead == 'd') ADVANCE(61);
      END_STATE();
    case 50:
      if (lookahead == 'd') ADVANCE(98);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(155);
      if (lookahead == 'l') ADVANCE(142);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(329);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(352);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(328);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(374);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(362);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(372);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(351);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(379);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(363);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(334);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(75);
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(191);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(124);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(105);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(149);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(129);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(166);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(130);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(165);
      END_STATE();
    case 74:
      if (lookahead == 'f') ADVANCE(88);
      END_STATE();
    case 75:
      if (lookahead == 'f') ADVANCE(29);
      END_STATE();
    case 76:
      if (lookahead == 'g') ADVANCE(346);
      END_STATE();
    case 77:
      if (lookahead == 'g') ADVANCE(340);
      END_STATE();
    case 78:
      if (lookahead == 'g') ADVANCE(160);
      END_STATE();
    case 79:
      if (lookahead == 'g') ADVANCE(131);
      END_STATE();
    case 80:
      if (lookahead == 'g') ADVANCE(69);
      if (lookahead == 'p') ADVANCE(381);
      END_STATE();
    case 81:
      if (lookahead == 'h') ADVANCE(151);
      if (lookahead == 'r') ADVANCE(186);
      if (lookahead == 'w') ADVANCE(82);
      END_STATE();
    case 82:
      if (lookahead == 'i') ADVANCE(42);
      END_STATE();
    case 83:
      if (lookahead == 'i') ADVANCE(190);
      if (lookahead == 'o') ADVANCE(152);
      if (lookahead == 'x') ADVANCE(326);
      END_STATE();
    case 84:
      if (lookahead == 'i') ADVANCE(190);
      if (lookahead == 'x') ADVANCE(326);
      END_STATE();
    case 85:
      if (lookahead == 'i') ADVANCE(79);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(147);
      END_STATE();
    case 87:
      if (lookahead == 'i') ADVANCE(168);
      END_STATE();
    case 88:
      if (lookahead == 'i') ADVANCE(132);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(173);
      END_STATE();
    case 90:
      if (lookahead == 'i') ADVANCE(169);
      END_STATE();
    case 91:
      if (lookahead == 'i') ADVANCE(113);
      END_STATE();
    case 92:
      if (lookahead == 'i') ADVANCE(127);
      END_STATE();
    case 93:
      if (lookahead == 'i') ADVANCE(172);
      END_STATE();
    case 94:
      if (lookahead == 'i') ADVANCE(166);
      END_STATE();
    case 95:
      if (lookahead == 'i') ADVANCE(174);
      END_STATE();
    case 96:
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 97:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 98:
      if (lookahead == 'i') ADVANCE(36);
      END_STATE();
    case 99:
      if (lookahead == 'k') ADVANCE(329);
      END_STATE();
    case 100:
      if (lookahead == 'k') ADVANCE(388);
      END_STATE();
    case 101:
      if (lookahead == 'l') ADVANCE(85);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(25);
      if (lookahead == 'o') ADVANCE(150);
      END_STATE();
    case 103:
      if (lookahead == 'l') ADVANCE(136);
      if (lookahead == 'y') ADVANCE(33);
      END_STATE();
    case 104:
      if (lookahead == 'l') ADVANCE(364);
      END_STATE();
    case 105:
      if (lookahead == 'l') ADVANCE(348);
      END_STATE();
    case 106:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 107:
      if (lookahead == 'l') ADVANCE(187);
      END_STATE();
    case 108:
      if (lookahead == 'l') ADVANCE(104);
      END_STATE();
    case 109:
      if (lookahead == 'l') ADVANCE(139);
      END_STATE();
    case 110:
      if (lookahead == 'l') ADVANCE(135);
      END_STATE();
    case 111:
      if (lookahead == 'l') ADVANCE(141);
      END_STATE();
    case 112:
      if (lookahead == 'l') ADVANCE(171);
      END_STATE();
    case 113:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 114:
      if (lookahead == 'l') ADVANCE(110);
      END_STATE();
    case 115:
      if (lookahead == 'l') ADVANCE(164);
      END_STATE();
    case 116:
      if (lookahead == 'm') ADVANCE(140);
      if (lookahead == 'n') ADVANCE(181);
      if (lookahead == 'r') ADVANCE(35);
      END_STATE();
    case 117:
      if (lookahead == 'm') ADVANCE(140);
      if (lookahead == 'n') ADVANCE(182);
      END_STATE();
    case 118:
      if (lookahead == 'm') ADVANCE(53);
      END_STATE();
    case 119:
      if (lookahead == 'm') ADVANCE(72);
      END_STATE();
    case 120:
      if (lookahead == 'n') ADVANCE(74);
      END_STATE();
    case 121:
      if (lookahead == 'n') ADVANCE(181);
      END_STATE();
    case 122:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 123:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 124:
      if (lookahead == 'n') ADVANCE(329);
      END_STATE();
    case 125:
      if (lookahead == 'n') ADVANCE(357);
      END_STATE();
    case 126:
      if (lookahead == 'n') ADVANCE(370);
      END_STATE();
    case 127:
      if (lookahead == 'n') ADVANCE(78);
      END_STATE();
    case 128:
      if (lookahead == 'n') ADVANCE(47);
      END_STATE();
    case 129:
      if (lookahead == 'n') ADVANCE(178);
      END_STATE();
    case 130:
      if (lookahead == 'n') ADVANCE(166);
      END_STATE();
    case 131:
      if (lookahead == 'n') ADVANCE(119);
      END_STATE();
    case 132:
      if (lookahead == 'n') ADVANCE(93);
      END_STATE();
    case 133:
      if (lookahead == 'o') ADVANCE(150);
      END_STATE();
    case 134:
      if (lookahead == 'o') ADVANCE(382);
      END_STATE();
    case 135:
      if (lookahead == 'o') ADVANCE(189);
      END_STATE();
    case 136:
      if (lookahead == 'o') ADVANCE(162);
      END_STATE();
    case 137:
      if (lookahead == 'o') ADVANCE(152);
      END_STATE();
    case 138:
      if (lookahead == 'o') ADVANCE(176);
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 139:
      if (lookahead == 'o') ADVANCE(76);
      END_STATE();
    case 140:
      if (lookahead == 'o') ADVANCE(179);
      END_STATE();
    case 141:
      if (lookahead == 'o') ADVANCE(77);
      END_STATE();
    case 142:
      if (lookahead == 'o') ADVANCE(167);
      END_STATE();
    case 143:
      if (lookahead == 'o') ADVANCE(125);
      END_STATE();
    case 144:
      if (lookahead == 'p') ADVANCE(381);
      END_STATE();
    case 145:
      if (lookahead == 'p') ADVANCE(345);
      END_STATE();
    case 146:
      if (lookahead == 'p') ADVANCE(351);
      END_STATE();
    case 147:
      if (lookahead == 'p') ADVANCE(170);
      END_STATE();
    case 148:
      if (lookahead == 'r') ADVANCE(186);
      END_STATE();
    case 149:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 150:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 151:
      if (lookahead == 'r') ADVANCE(82);
      END_STATE();
    case 152:
      if (lookahead == 'r') ADVANCE(175);
      END_STATE();
    case 153:
      if (lookahead == 'r') ADVANCE(24);
      END_STATE();
    case 154:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 155:
      if (lookahead == 'r') ADVANCE(97);
      if (lookahead == 't') ADVANCE(180);
      END_STATE();
    case 156:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 157:
      if (lookahead == 'r') ADVANCE(126);
      END_STATE();
    case 158:
      if (lookahead == 'r') ADVANCE(32);
      END_STATE();
    case 159:
      if (lookahead == 's') ADVANCE(324);
      END_STATE();
    case 160:
      if (lookahead == 's') ADVANCE(342);
      END_STATE();
    case 161:
      if (lookahead == 's') ADVANCE(143);
      END_STATE();
    case 162:
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 163:
      if (lookahead == 's') ADVANCE(59);
      END_STATE();
    case 164:
      if (lookahead == 's') ADVANCE(60);
      END_STATE();
    case 165:
      if (lookahead == 's') ADVANCE(70);
      END_STATE();
    case 166:
      if (lookahead == 't') ADVANCE(352);
      END_STATE();
    case 167:
      if (lookahead == 't') ADVANCE(376);
      END_STATE();
    case 168:
      if (lookahead == 't') ADVANCE(386);
      END_STATE();
    case 169:
      if (lookahead == 't') ADVANCE(193);
      END_STATE();
    case 170:
      if (lookahead == 't') ADVANCE(355);
      END_STATE();
    case 171:
      if (lookahead == 't') ADVANCE(347);
      END_STATE();
    case 172:
      if (lookahead == 't') ADVANCE(194);
      END_STATE();
    case 173:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 174:
      if (lookahead == 't') ADVANCE(192);
      END_STATE();
    case 175:
      if (lookahead == 't') ADVANCE(156);
      END_STATE();
    case 176:
      if (lookahead == 't') ADVANCE(134);
      END_STATE();
    case 177:
      if (lookahead == 't') ADVANCE(91);
      END_STATE();
    case 178:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 179:
      if (lookahead == 't') ADVANCE(58);
      END_STATE();
    case 180:
      if (lookahead == 't') ADVANCE(92);
      END_STATE();
    case 181:
      if (lookahead == 't') ADVANCE(90);
      END_STATE();
    case 182:
      if (lookahead == 't') ADVANCE(95);
      END_STATE();
    case 183:
      if (lookahead == 'u') ADVANCE(108);
      END_STATE();
    case 184:
      if (lookahead == 'u') ADVANCE(157);
      END_STATE();
    case 185:
      if (lookahead == 'u') ADVANCE(112);
      END_STATE();
    case 186:
      if (lookahead == 'u') ADVANCE(56);
      END_STATE();
    case 187:
      if (lookahead == 'u') ADVANCE(49);
      END_STATE();
    case 188:
      if (lookahead == 'v') ADVANCE(55);
      END_STATE();
    case 189:
      if (lookahead == 'w') ADVANCE(329);
      END_STATE();
    case 190:
      if (lookahead == 'x') ADVANCE(326);
      END_STATE();
    case 191:
      if (lookahead == 'x') ADVANCE(384);
      END_STATE();
    case 192:
      if (lookahead == 'y') ADVANCE(352);
      END_STATE();
    case 193:
      if (lookahead == 'y') ADVANCE(350);
      END_STATE();
    case 194:
      if (lookahead == 'y') ADVANCE(360);
      END_STATE();
    case 195:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(197);
      END_STATE();
    case 196:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(332);
      END_STATE();
    case 197:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(196);
      END_STATE();
    case 198:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(333);
      END_STATE();
    case 199:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 200:
      if (eof) ADVANCE(202);
      ADVANCE_MAP(
        '!', 367,
        '"', 6,
        '#', 354,
        '$', 198,
        '(', 368,
        ')', 369,
        ',', 320,
        '-', 12,
        '/', 8,
        ':', 359,
        ';', 336,
        '=', 337,
        'I', 120,
        '[', 319,
        ']', 321,
        '_', 353,
        'a', 43,
        'b', 102,
        'c', 103,
        'd', 63,
        'e', 116,
        'f', 15,
        'g', 138,
        'i', 122,
        'j', 161,
        'l', 17,
        'm', 18,
        'n', 21,
        'o', 123,
        'p', 137,
        'r', 31,
        's', 22,
        't', 81,
        'w', 27,
        'y', 71,
        '{', 343,
        '}', 344,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(200);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(323);
      END_STATE();
    case 201:
      if (eof) ADVANCE(202);
      ADVANCE_MAP(
        '"', 6,
        '$', 198,
        '/', 8,
        '[', 319,
        ']', 321,
        'a', 233,
        'i', 278,
        's', 222,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(201);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(323);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(204);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(282);
      if (lookahead == 'e') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(225);
      if (lookahead == 'u') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(295);
      if (lookahead == 'e') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(266);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(339);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(378);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(335);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(375);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(373);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(281);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(253);
      if (lookahead == 'n') ADVANCE(205);
      if (lookahead == 'p') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(341);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(298);
      if (lookahead == 'r') ADVANCE(314);
      if (lookahead == 'w') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(389);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(349);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(293);
      if (lookahead == 'y') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(371);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(385);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(323);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(188);
      if (lookahead == 'c') ADVANCE(154);
      if (lookahead == 'e') ADVANCE(155);
      if (lookahead == 'l') ADVANCE(142);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(329);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(330);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(331);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(333);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_serial_dialog_parameter_int);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_target_default);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_target_entity);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_dialog_parameter_int);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_dialog_parameter_string);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(197);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(361);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_action_return_statement);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_action_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(318);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 201},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 7},
  [5] = {.lex_state = 7},
  [6] = {.lex_state = 7},
  [7] = {.lex_state = 201},
  [8] = {.lex_state = 201},
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
  [21] = {.lex_state = 201},
  [22] = {.lex_state = 201},
  [23] = {.lex_state = 201},
  [24] = {.lex_state = 201},
  [25] = {.lex_state = 201},
  [26] = {.lex_state = 201},
  [27] = {.lex_state = 201},
  [28] = {.lex_state = 201},
  [29] = {.lex_state = 201},
  [30] = {.lex_state = 201},
  [31] = {.lex_state = 201},
  [32] = {.lex_state = 201},
  [33] = {.lex_state = 201},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 3},
  [39] = {.lex_state = 4},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 4},
  [42] = {.lex_state = 201},
  [43] = {.lex_state = 11},
  [44] = {.lex_state = 201},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 11},
  [47] = {.lex_state = 11},
  [48] = {.lex_state = 11},
  [49] = {.lex_state = 11},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 201},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 201},
  [55] = {.lex_state = 4},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 4},
  [61] = {.lex_state = 4},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 201},
  [64] = {.lex_state = 4},
  [65] = {.lex_state = 4},
  [66] = {.lex_state = 4},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 201},
  [69] = {.lex_state = 4},
  [70] = {.lex_state = 4},
  [71] = {.lex_state = 201},
  [72] = {.lex_state = 4},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 4},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 201},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 4},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 2},
  [95] = {.lex_state = 201},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 2},
  [105] = {.lex_state = 11},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 201},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 2},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 201},
  [115] = {.lex_state = 11},
  [116] = {.lex_state = 201},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 11},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 4},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 201},
  [124] = {.lex_state = 2},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 2},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 4},
  [134] = {.lex_state = 11},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 2},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 11},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 2},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 4},
  [144] = {.lex_state = 201},
  [145] = {.lex_state = 2},
  [146] = {.lex_state = 201},
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
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 11},
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
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 11},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 11},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 11},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
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
    [anon_sym_dialog] = ACTIONS(1),
    [sym_target_default] = ACTIONS(1),
    [anon_sym_label] = ACTIONS(1),
    [sym_target_entity] = ACTIONS(1),
    [sym_dialog_parameter_int] = ACTIONS(1),
    [sym_dialog_parameter_string] = ACTIONS(1),
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
    [anon_sym_save] = ACTIONS(1),
    [anon_sym_slot] = ACTIONS(1),
    [anon_sym_load] = ACTIONS(1),
    [anon_sym_erase] = ACTIONS(1),
    [anon_sym_map] = ACTIONS(1),
    [anon_sym_goto] = ACTIONS(1),
    [anon_sym_index] = ACTIONS(1),
    [anon_sym_wait] = ACTIONS(1),
    [anon_sym_block] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(184),
    [sym__root] = STATE(7),
    [sym_include_macro] = STATE(7),
    [sym_constant_assignment] = STATE(7),
    [sym_add_serial_dialog_settings] = STATE(7),
    [sym_add_dialog_settings] = STATE(7),
    [sym_serial_dialog_definition] = STATE(7),
    [sym_script_definition] = STATE(7),
    [aux_sym_document_repeat1] = STATE(7),
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
    STATE(177), 12,
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
    STATE(177), 12,
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
    STATE(177), 12,
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
    STATE(177), 12,
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
    STATE(177), 12,
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
    ACTIONS(86), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(8), 8,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [350] = 10,
    ACTIONS(88), 1,
      ts_builtin_sym_end,
    ACTIONS(90), 1,
      sym_BAREWORD,
    ACTIONS(93), 1,
      sym_QUOTED_STRING,
    ACTIONS(96), 1,
      sym_CONSTANT,
    ACTIONS(99), 1,
      anon_sym_include,
    ACTIONS(102), 1,
      anon_sym_add,
    ACTIONS(105), 1,
      anon_sym_serial_dialog,
    ACTIONS(108), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(8), 8,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [389] = 3,
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
  [413] = 3,
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
  [437] = 3,
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
  [461] = 3,
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
  [483] = 3,
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
  [505] = 3,
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
  [527] = 3,
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
  [549] = 3,
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
  [571] = 6,
    ACTIONS(143), 1,
      anon_sym_LBRACK,
    ACTIONS(145), 1,
      anon_sym_RBRACK,
    ACTIONS(149), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(103), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(147), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [597] = 6,
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
    STATE(195), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [622] = 5,
    ACTIONS(143), 1,
      anon_sym_LBRACK,
    ACTIONS(149), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(126), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(159), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [645] = 5,
    ACTIONS(143), 1,
      anon_sym_LBRACK,
    ACTIONS(149), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(127), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(161), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [668] = 3,
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
  [685] = 3,
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
  [702] = 3,
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
  [719] = 3,
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
  [736] = 3,
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
  [753] = 3,
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
  [770] = 3,
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
  [787] = 3,
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
  [804] = 3,
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
  [821] = 3,
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
  [838] = 3,
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
  [855] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(207), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(209), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [872] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(211), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(213), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [889] = 7,
    ACTIONS(215), 1,
      anon_sym_RBRACE,
    ACTIONS(217), 1,
      sym_target_default,
    ACTIONS(219), 1,
      anon_sym_label,
    ACTIONS(221), 1,
      sym_target_entity,
    STATE(137), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(36), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [913] = 8,
    ACTIONS(223), 1,
      sym_QUOTED_STRING,
    ACTIONS(225), 1,
      anon_sym_RBRACE,
    ACTIONS(227), 1,
      sym_serial_dialog_parameter_int,
    STATE(40), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(41), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(121), 1,
      sym_serial_dialog_parameter,
    STATE(199), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [939] = 7,
    ACTIONS(217), 1,
      sym_target_default,
    ACTIONS(219), 1,
      anon_sym_label,
    ACTIONS(221), 1,
      sym_target_entity,
    ACTIONS(229), 1,
      anon_sym_RBRACE,
    STATE(137), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(37), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [963] = 7,
    ACTIONS(231), 1,
      anon_sym_RBRACE,
    ACTIONS(233), 1,
      sym_target_default,
    ACTIONS(236), 1,
      anon_sym_label,
    ACTIONS(239), 1,
      sym_target_entity,
    STATE(137), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(37), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [987] = 7,
    ACTIONS(242), 1,
      sym_BAREWORD,
    ACTIONS(244), 1,
      anon_sym_LBRACK,
    ACTIONS(248), 1,
      anon_sym_label,
    ACTIONS(250), 1,
      anon_sym_index,
    STATE(191), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(246), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1011] = 7,
    ACTIONS(223), 1,
      sym_QUOTED_STRING,
    ACTIONS(252), 1,
      anon_sym_RBRACE,
    ACTIONS(254), 1,
      sym_serial_dialog_option_type,
    STATE(60), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(65), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(133), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1034] = 7,
    ACTIONS(223), 1,
      sym_QUOTED_STRING,
    ACTIONS(254), 1,
      sym_serial_dialog_option_type,
    ACTIONS(256), 1,
      anon_sym_RBRACE,
    STATE(60), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(61), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(133), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1057] = 6,
    ACTIONS(223), 1,
      sym_QUOTED_STRING,
    ACTIONS(227), 1,
      sym_serial_dialog_parameter_int,
    STATE(39), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(59), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(121), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1077] = 5,
    ACTIONS(258), 1,
      anon_sym_LBRACK,
    ACTIONS(260), 1,
      sym_NUMBER,
    ACTIONS(262), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(197), 2,
      sym_DURATION,
      sym_duration_expansion,
  [1095] = 6,
    ACTIONS(264), 1,
      anon_sym_RBRACE,
    ACTIONS(266), 1,
      sym_dialog_parameter_int,
    ACTIONS(268), 1,
      sym_dialog_parameter_string,
    STATE(46), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(105), 1,
      sym_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1115] = 5,
    ACTIONS(258), 1,
      anon_sym_LBRACK,
    ACTIONS(260), 1,
      sym_NUMBER,
    ACTIONS(270), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(153), 2,
      sym_DURATION,
      sym_duration_expansion,
  [1133] = 4,
    ACTIONS(244), 1,
      anon_sym_LBRACK,
    STATE(150), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(272), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1149] = 6,
    ACTIONS(266), 1,
      sym_dialog_parameter_int,
    ACTIONS(268), 1,
      sym_dialog_parameter_string,
    ACTIONS(274), 1,
      anon_sym_RBRACE,
    STATE(48), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(105), 1,
      sym_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1169] = 6,
    ACTIONS(266), 1,
      sym_dialog_parameter_int,
    ACTIONS(268), 1,
      sym_dialog_parameter_string,
    ACTIONS(276), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(105), 1,
      sym_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1189] = 6,
    ACTIONS(278), 1,
      anon_sym_RBRACE,
    ACTIONS(280), 1,
      sym_dialog_parameter_int,
    ACTIONS(283), 1,
      sym_dialog_parameter_string,
    STATE(48), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(105), 1,
      sym_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1209] = 6,
    ACTIONS(266), 1,
      sym_dialog_parameter_int,
    ACTIONS(268), 1,
      sym_dialog_parameter_string,
    ACTIONS(286), 1,
      anon_sym_RBRACE,
    STATE(48), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(105), 1,
      sym_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1229] = 4,
    ACTIONS(227), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(288), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(64), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1244] = 4,
    ACTIONS(290), 1,
      anon_sym_LBRACK,
    STATE(151), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(292), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1259] = 3,
    ACTIONS(296), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(294), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1272] = 4,
    ACTIONS(300), 1,
      anon_sym_LBRACK,
    STATE(157), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(298), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1287] = 4,
    ACTIONS(290), 1,
      anon_sym_LBRACK,
    STATE(162), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(302), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1302] = 3,
    ACTIONS(306), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(304), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [1315] = 4,
    ACTIONS(227), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(308), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(50), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1330] = 4,
    ACTIONS(310), 1,
      anon_sym_LBRACK,
    STATE(187), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(312), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1345] = 5,
    ACTIONS(306), 1,
      sym_duration_suffix,
    ACTIONS(314), 1,
      sym_distance_suffix,
    ACTIONS(316), 1,
      sym_quantity_suffix,
    ACTIONS(318), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1362] = 5,
    ACTIONS(320), 1,
      sym_QUOTED_STRING,
    ACTIONS(322), 1,
      sym_serial_dialog_parameter_int,
    STATE(59), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(121), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1379] = 4,
    ACTIONS(325), 1,
      sym_QUOTED_STRING,
    STATE(60), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(328), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1394] = 5,
    ACTIONS(254), 1,
      sym_serial_dialog_option_type,
    ACTIONS(330), 1,
      anon_sym_RBRACE,
    STATE(66), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(133), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1411] = 3,
    ACTIONS(334), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(332), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1424] = 5,
    ACTIONS(260), 1,
      sym_NUMBER,
    ACTIONS(336), 1,
      anon_sym_RBRACK,
    ACTIONS(338), 1,
      sym_CONSTANT,
    STATE(142), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1441] = 4,
    ACTIONS(340), 1,
      anon_sym_RBRACE,
    ACTIONS(342), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(64), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1456] = 5,
    ACTIONS(254), 1,
      sym_serial_dialog_option_type,
    ACTIONS(345), 1,
      anon_sym_RBRACE,
    STATE(66), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(133), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1473] = 5,
    ACTIONS(347), 1,
      anon_sym_RBRACE,
    ACTIONS(349), 1,
      sym_serial_dialog_option_type,
    STATE(66), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(133), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1490] = 3,
    ACTIONS(352), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(332), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1503] = 5,
    ACTIONS(260), 1,
      sym_NUMBER,
    ACTIONS(338), 1,
      sym_CONSTANT,
    ACTIONS(354), 1,
      anon_sym_RBRACK,
    STATE(142), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1520] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(356), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      sym_target_entity,
  [1531] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(358), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      sym_target_entity,
  [1542] = 4,
    ACTIONS(290), 1,
      anon_sym_LBRACK,
    STATE(171), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(360), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1557] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(362), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      sym_target_entity,
  [1568] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(364), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      sym_target_entity,
  [1579] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(366), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [1589] = 3,
    ACTIONS(368), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(370), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1601] = 4,
    ACTIONS(372), 1,
      anon_sym_COMMA,
    ACTIONS(375), 1,
      anon_sym_RBRACK,
    STATE(76), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1615] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(377), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1625] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(379), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_parameter_int,
  [1635] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(381), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [1645] = 3,
    ACTIONS(383), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(370), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1657] = 4,
    ACTIONS(383), 1,
      anon_sym_RBRACK,
    ACTIONS(385), 1,
      anon_sym_COMMA,
    STATE(76), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1671] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(387), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [1681] = 4,
    ACTIONS(389), 1,
      anon_sym_COMMA,
    ACTIONS(391), 1,
      anon_sym_RBRACE,
    STATE(93), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1695] = 4,
    ACTIONS(393), 1,
      anon_sym_COMMA,
    ACTIONS(395), 1,
      anon_sym_RBRACK,
    STATE(81), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1709] = 4,
    ACTIONS(397), 1,
      anon_sym_COMMA,
    ACTIONS(399), 1,
      anon_sym_RBRACK,
    STATE(118), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1723] = 4,
    ACTIONS(401), 1,
      anon_sym_COMMA,
    ACTIONS(403), 1,
      anon_sym_RBRACK,
    STATE(96), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1737] = 4,
    ACTIONS(260), 1,
      sym_NUMBER,
    ACTIONS(405), 1,
      sym_CONSTANT,
    STATE(97), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1751] = 4,
    ACTIONS(334), 1,
      anon_sym_RBRACK,
    ACTIONS(407), 1,
      anon_sym_COMMA,
    STATE(98), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1765] = 4,
    ACTIONS(409), 1,
      anon_sym_COMMA,
    ACTIONS(411), 1,
      anon_sym_RBRACK,
    STATE(100), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1779] = 4,
    ACTIONS(336), 1,
      anon_sym_RBRACK,
    ACTIONS(413), 1,
      anon_sym_COMMA,
    STATE(102), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1793] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(415), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1803] = 3,
    ACTIONS(417), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(419), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1815] = 4,
    ACTIONS(389), 1,
      anon_sym_COMMA,
    ACTIONS(421), 1,
      anon_sym_RBRACE,
    STATE(108), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1829] = 3,
    ACTIONS(425), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(423), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1841] = 3,
    ACTIONS(427), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(429), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1853] = 4,
    ACTIONS(427), 1,
      anon_sym_RBRACK,
    ACTIONS(431), 1,
      anon_sym_COMMA,
    STATE(110), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1867] = 4,
    ACTIONS(433), 1,
      anon_sym_COMMA,
    ACTIONS(435), 1,
      anon_sym_RBRACK,
    STATE(90), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1881] = 4,
    ACTIONS(437), 1,
      anon_sym_COMMA,
    ACTIONS(440), 1,
      anon_sym_RBRACK,
    STATE(98), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1895] = 3,
    ACTIONS(444), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(442), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1907] = 4,
    ACTIONS(444), 1,
      anon_sym_RBRACK,
    ACTIONS(446), 1,
      anon_sym_COMMA,
    STATE(113), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1921] = 4,
    ACTIONS(448), 1,
      sym_QUOTED_STRING,
    ACTIONS(450), 1,
      anon_sym_RBRACE,
    STATE(83), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1935] = 4,
    ACTIONS(452), 1,
      anon_sym_COMMA,
    ACTIONS(455), 1,
      anon_sym_RBRACK,
    STATE(102), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1949] = 4,
    ACTIONS(397), 1,
      anon_sym_COMMA,
    ACTIONS(457), 1,
      anon_sym_RBRACK,
    STATE(85), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1963] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(459), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1973] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(461), 3,
      anon_sym_RBRACE,
      sym_dialog_parameter_int,
      sym_dialog_parameter_string,
  [1983] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(463), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1993] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(465), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2003] = 4,
    ACTIONS(467), 1,
      anon_sym_COMMA,
    ACTIONS(470), 1,
      anon_sym_RBRACE,
    STATE(108), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2017] = 3,
    ACTIONS(472), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(429), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2029] = 4,
    ACTIONS(474), 1,
      anon_sym_COMMA,
    ACTIONS(477), 1,
      anon_sym_RBRACK,
    STATE(110), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2043] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(332), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2053] = 3,
    ACTIONS(479), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(442), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2065] = 4,
    ACTIONS(481), 1,
      anon_sym_COMMA,
    ACTIONS(484), 1,
      anon_sym_RBRACK,
    STATE(113), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2079] = 4,
    ACTIONS(260), 1,
      sym_NUMBER,
    ACTIONS(338), 1,
      sym_CONSTANT,
    STATE(142), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2093] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(486), 3,
      anon_sym_RBRACE,
      sym_dialog_parameter_int,
      sym_dialog_parameter_string,
  [2103] = 3,
    ACTIONS(488), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(490), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2115] = 4,
    ACTIONS(492), 1,
      anon_sym_COMMA,
    ACTIONS(494), 1,
      anon_sym_RBRACK,
    STATE(88), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2129] = 4,
    ACTIONS(496), 1,
      anon_sym_COMMA,
    ACTIONS(499), 1,
      anon_sym_RBRACK,
    STATE(118), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2143] = 3,
    ACTIONS(501), 1,
      anon_sym_slot,
    ACTIONS(503), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2154] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(375), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2163] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(505), 2,
      sym_QUOTED_STRING,
      sym_serial_dialog_parameter_int,
  [2172] = 3,
    ACTIONS(448), 1,
      sym_QUOTED_STRING,
    STATE(128), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2183] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(459), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2192] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(507), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2201] = 3,
    ACTIONS(143), 1,
      anon_sym_LBRACK,
    STATE(13), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2212] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(499), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2221] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(509), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [2230] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(470), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [2239] = 3,
    ACTIONS(511), 1,
      anon_sym_LBRACE,
    STATE(23), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2250] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(513), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2259] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(477), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2268] = 3,
    ACTIONS(515), 1,
      anon_sym_LBRACE,
    STATE(28), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2279] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(517), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2288] = 3,
    ACTIONS(519), 1,
      anon_sym_serial_dialog,
    ACTIONS(521), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2299] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(484), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2308] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(440), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2317] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(377), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2326] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(370), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2335] = 3,
    ACTIONS(523), 1,
      anon_sym_serial_dialog,
    ACTIONS(525), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2346] = 3,
    ACTIONS(515), 1,
      anon_sym_LBRACE,
    STATE(32), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2357] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(527), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2366] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(455), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2375] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(529), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2384] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(429), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2393] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(442), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2402] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(531), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2411] = 2,
    ACTIONS(533), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2419] = 2,
    ACTIONS(535), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2427] = 2,
    ACTIONS(537), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2435] = 2,
    ACTIONS(539), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2443] = 2,
    ACTIONS(541), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2451] = 2,
    ACTIONS(543), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2459] = 2,
    ACTIONS(545), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2467] = 2,
    ACTIONS(547), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2475] = 2,
    ACTIONS(549), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2483] = 2,
    ACTIONS(551), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2491] = 2,
    ACTIONS(553), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2499] = 2,
    ACTIONS(555), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2507] = 2,
    ACTIONS(557), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2515] = 2,
    ACTIONS(559), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2523] = 2,
    ACTIONS(561), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2531] = 2,
    ACTIONS(563), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2539] = 2,
    ACTIONS(565), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2547] = 2,
    ACTIONS(567), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2555] = 2,
    ACTIONS(569), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2563] = 2,
    ACTIONS(571), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2571] = 2,
    ACTIONS(573), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2579] = 2,
    ACTIONS(575), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2587] = 2,
    ACTIONS(577), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2595] = 2,
    ACTIONS(579), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2603] = 2,
    ACTIONS(581), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2611] = 2,
    ACTIONS(583), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2619] = 2,
    ACTIONS(585), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2627] = 2,
    ACTIONS(587), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2635] = 2,
    ACTIONS(589), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2643] = 2,
    ACTIONS(591), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2651] = 2,
    ACTIONS(593), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2659] = 2,
    ACTIONS(595), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2667] = 2,
    ACTIONS(597), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2675] = 2,
    ACTIONS(599), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2683] = 2,
    ACTIONS(601), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2691] = 2,
    ACTIONS(603), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2699] = 2,
    ACTIONS(605), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2707] = 2,
    ACTIONS(607), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2715] = 2,
    ACTIONS(609), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2723] = 2,
    ACTIONS(611), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2731] = 2,
    ACTIONS(613), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2739] = 2,
    ACTIONS(615), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2747] = 2,
    ACTIONS(617), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2755] = 2,
    ACTIONS(619), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2763] = 2,
    ACTIONS(621), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2771] = 2,
    ACTIONS(623), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2779] = 2,
    ACTIONS(625), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2787] = 2,
    ACTIONS(627), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2795] = 2,
    ACTIONS(318), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2803] = 2,
    ACTIONS(629), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2811] = 2,
    ACTIONS(631), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2819] = 2,
    ACTIONS(633), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2827] = 2,
    ACTIONS(635), 1,
      anon_sym_RBRACE,
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
  [SMALL_STATE(8)] = 350,
  [SMALL_STATE(9)] = 389,
  [SMALL_STATE(10)] = 413,
  [SMALL_STATE(11)] = 437,
  [SMALL_STATE(12)] = 461,
  [SMALL_STATE(13)] = 483,
  [SMALL_STATE(14)] = 505,
  [SMALL_STATE(15)] = 527,
  [SMALL_STATE(16)] = 549,
  [SMALL_STATE(17)] = 571,
  [SMALL_STATE(18)] = 597,
  [SMALL_STATE(19)] = 622,
  [SMALL_STATE(20)] = 645,
  [SMALL_STATE(21)] = 668,
  [SMALL_STATE(22)] = 685,
  [SMALL_STATE(23)] = 702,
  [SMALL_STATE(24)] = 719,
  [SMALL_STATE(25)] = 736,
  [SMALL_STATE(26)] = 753,
  [SMALL_STATE(27)] = 770,
  [SMALL_STATE(28)] = 787,
  [SMALL_STATE(29)] = 804,
  [SMALL_STATE(30)] = 821,
  [SMALL_STATE(31)] = 838,
  [SMALL_STATE(32)] = 855,
  [SMALL_STATE(33)] = 872,
  [SMALL_STATE(34)] = 889,
  [SMALL_STATE(35)] = 913,
  [SMALL_STATE(36)] = 939,
  [SMALL_STATE(37)] = 963,
  [SMALL_STATE(38)] = 987,
  [SMALL_STATE(39)] = 1011,
  [SMALL_STATE(40)] = 1034,
  [SMALL_STATE(41)] = 1057,
  [SMALL_STATE(42)] = 1077,
  [SMALL_STATE(43)] = 1095,
  [SMALL_STATE(44)] = 1115,
  [SMALL_STATE(45)] = 1133,
  [SMALL_STATE(46)] = 1149,
  [SMALL_STATE(47)] = 1169,
  [SMALL_STATE(48)] = 1189,
  [SMALL_STATE(49)] = 1209,
  [SMALL_STATE(50)] = 1229,
  [SMALL_STATE(51)] = 1244,
  [SMALL_STATE(52)] = 1259,
  [SMALL_STATE(53)] = 1272,
  [SMALL_STATE(54)] = 1287,
  [SMALL_STATE(55)] = 1302,
  [SMALL_STATE(56)] = 1315,
  [SMALL_STATE(57)] = 1330,
  [SMALL_STATE(58)] = 1345,
  [SMALL_STATE(59)] = 1362,
  [SMALL_STATE(60)] = 1379,
  [SMALL_STATE(61)] = 1394,
  [SMALL_STATE(62)] = 1411,
  [SMALL_STATE(63)] = 1424,
  [SMALL_STATE(64)] = 1441,
  [SMALL_STATE(65)] = 1456,
  [SMALL_STATE(66)] = 1473,
  [SMALL_STATE(67)] = 1490,
  [SMALL_STATE(68)] = 1503,
  [SMALL_STATE(69)] = 1520,
  [SMALL_STATE(70)] = 1531,
  [SMALL_STATE(71)] = 1542,
  [SMALL_STATE(72)] = 1557,
  [SMALL_STATE(73)] = 1568,
  [SMALL_STATE(74)] = 1579,
  [SMALL_STATE(75)] = 1589,
  [SMALL_STATE(76)] = 1601,
  [SMALL_STATE(77)] = 1615,
  [SMALL_STATE(78)] = 1625,
  [SMALL_STATE(79)] = 1635,
  [SMALL_STATE(80)] = 1645,
  [SMALL_STATE(81)] = 1657,
  [SMALL_STATE(82)] = 1671,
  [SMALL_STATE(83)] = 1681,
  [SMALL_STATE(84)] = 1695,
  [SMALL_STATE(85)] = 1709,
  [SMALL_STATE(86)] = 1723,
  [SMALL_STATE(87)] = 1737,
  [SMALL_STATE(88)] = 1751,
  [SMALL_STATE(89)] = 1765,
  [SMALL_STATE(90)] = 1779,
  [SMALL_STATE(91)] = 1793,
  [SMALL_STATE(92)] = 1803,
  [SMALL_STATE(93)] = 1815,
  [SMALL_STATE(94)] = 1829,
  [SMALL_STATE(95)] = 1841,
  [SMALL_STATE(96)] = 1853,
  [SMALL_STATE(97)] = 1867,
  [SMALL_STATE(98)] = 1881,
  [SMALL_STATE(99)] = 1895,
  [SMALL_STATE(100)] = 1907,
  [SMALL_STATE(101)] = 1921,
  [SMALL_STATE(102)] = 1935,
  [SMALL_STATE(103)] = 1949,
  [SMALL_STATE(104)] = 1963,
  [SMALL_STATE(105)] = 1973,
  [SMALL_STATE(106)] = 1983,
  [SMALL_STATE(107)] = 1993,
  [SMALL_STATE(108)] = 2003,
  [SMALL_STATE(109)] = 2017,
  [SMALL_STATE(110)] = 2029,
  [SMALL_STATE(111)] = 2043,
  [SMALL_STATE(112)] = 2053,
  [SMALL_STATE(113)] = 2065,
  [SMALL_STATE(114)] = 2079,
  [SMALL_STATE(115)] = 2093,
  [SMALL_STATE(116)] = 2103,
  [SMALL_STATE(117)] = 2115,
  [SMALL_STATE(118)] = 2129,
  [SMALL_STATE(119)] = 2143,
  [SMALL_STATE(120)] = 2154,
  [SMALL_STATE(121)] = 2163,
  [SMALL_STATE(122)] = 2172,
  [SMALL_STATE(123)] = 2183,
  [SMALL_STATE(124)] = 2192,
  [SMALL_STATE(125)] = 2201,
  [SMALL_STATE(126)] = 2212,
  [SMALL_STATE(127)] = 2221,
  [SMALL_STATE(128)] = 2230,
  [SMALL_STATE(129)] = 2239,
  [SMALL_STATE(130)] = 2250,
  [SMALL_STATE(131)] = 2259,
  [SMALL_STATE(132)] = 2268,
  [SMALL_STATE(133)] = 2279,
  [SMALL_STATE(134)] = 2288,
  [SMALL_STATE(135)] = 2299,
  [SMALL_STATE(136)] = 2308,
  [SMALL_STATE(137)] = 2317,
  [SMALL_STATE(138)] = 2326,
  [SMALL_STATE(139)] = 2335,
  [SMALL_STATE(140)] = 2346,
  [SMALL_STATE(141)] = 2357,
  [SMALL_STATE(142)] = 2366,
  [SMALL_STATE(143)] = 2375,
  [SMALL_STATE(144)] = 2384,
  [SMALL_STATE(145)] = 2393,
  [SMALL_STATE(146)] = 2402,
  [SMALL_STATE(147)] = 2411,
  [SMALL_STATE(148)] = 2419,
  [SMALL_STATE(149)] = 2427,
  [SMALL_STATE(150)] = 2435,
  [SMALL_STATE(151)] = 2443,
  [SMALL_STATE(152)] = 2451,
  [SMALL_STATE(153)] = 2459,
  [SMALL_STATE(154)] = 2467,
  [SMALL_STATE(155)] = 2475,
  [SMALL_STATE(156)] = 2483,
  [SMALL_STATE(157)] = 2491,
  [SMALL_STATE(158)] = 2499,
  [SMALL_STATE(159)] = 2507,
  [SMALL_STATE(160)] = 2515,
  [SMALL_STATE(161)] = 2523,
  [SMALL_STATE(162)] = 2531,
  [SMALL_STATE(163)] = 2539,
  [SMALL_STATE(164)] = 2547,
  [SMALL_STATE(165)] = 2555,
  [SMALL_STATE(166)] = 2563,
  [SMALL_STATE(167)] = 2571,
  [SMALL_STATE(168)] = 2579,
  [SMALL_STATE(169)] = 2587,
  [SMALL_STATE(170)] = 2595,
  [SMALL_STATE(171)] = 2603,
  [SMALL_STATE(172)] = 2611,
  [SMALL_STATE(173)] = 2619,
  [SMALL_STATE(174)] = 2627,
  [SMALL_STATE(175)] = 2635,
  [SMALL_STATE(176)] = 2643,
  [SMALL_STATE(177)] = 2651,
  [SMALL_STATE(178)] = 2659,
  [SMALL_STATE(179)] = 2667,
  [SMALL_STATE(180)] = 2675,
  [SMALL_STATE(181)] = 2683,
  [SMALL_STATE(182)] = 2691,
  [SMALL_STATE(183)] = 2699,
  [SMALL_STATE(184)] = 2707,
  [SMALL_STATE(185)] = 2715,
  [SMALL_STATE(186)] = 2723,
  [SMALL_STATE(187)] = 2731,
  [SMALL_STATE(188)] = 2739,
  [SMALL_STATE(189)] = 2747,
  [SMALL_STATE(190)] = 2755,
  [SMALL_STATE(191)] = 2763,
  [SMALL_STATE(192)] = 2771,
  [SMALL_STATE(193)] = 2779,
  [SMALL_STATE(194)] = 2787,
  [SMALL_STATE(195)] = 2795,
  [SMALL_STATE(196)] = 2803,
  [SMALL_STATE(197)] = 2811,
  [SMALL_STATE(198)] = 2819,
  [SMALL_STATE(199)] = 2827,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(124),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(172),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(125),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(198),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(177),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(160),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(119),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(179),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(44),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(172),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(198),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(177),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(179),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(140),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(140),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(174),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [102] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(139),
  [105] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(124),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 5),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 5),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [151] = {.entry = {.count = 1, .reusable = false}}, SHIFT(195),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 18),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 18),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 4),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 4),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [233] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(182),
  [236] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(141),
  [239] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [242] = {.entry = {.count = 1, .reusable = false}}, SHIFT(191),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [250] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 20),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 12),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 30),
  [280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 30), SHIFT_REPEAT(123),
  [283] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 30), SHIFT_REPEAT(104),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 19),
  [322] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 19), SHIFT_REPEAT(146),
  [325] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 22), SHIFT_REPEAT(91),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 22),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 23),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [342] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(146),
  [345] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 24),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 25),
  [349] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 25), SHIFT_REPEAT(149),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 3, 0, 26),
  [358] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 29),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 31),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 5, 0, 33),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [372] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(138),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 17),
  [381] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 9),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [415] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 10),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [437] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(111),
  [440] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [452] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(114),
  [455] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [461] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 1, 0, 27),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [465] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [467] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [470] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [474] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(144),
  [477] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [481] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 17),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [496] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [499] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [505] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 11),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [509] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 28),
  [511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [517] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 21),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [527] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_label, 1, 0, 0),
  [529] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 32),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [533] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [535] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 14),
  [541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 13),
  [543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 7),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [549] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [551] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [553] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 15),
  [555] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [557] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [561] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 16),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 9),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [569] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [571] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [573] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 9),
  [575] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [581] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 13),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [585] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [589] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [591] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [595] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [599] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [601] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [605] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [607] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [611] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [617] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [621] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 6),
  [623] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [627] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [629] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [631] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 7),
  [633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
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
