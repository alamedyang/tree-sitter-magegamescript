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
#define STATE_COUNT 230
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 129
#define ALIAS_COUNT 0
#define TOKEN_COUNT 58
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 26
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 49

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
  anon_sym_wrap = 24,
  anon_sym_dialog = 25,
  sym_target_default = 26,
  anon_sym_label = 27,
  anon_sym_entity = 28,
  anon_sym_emote = 29,
  anon_sym_name = 30,
  anon_sym_portrait = 31,
  anon_sym_alignment = 32,
  anon_sym_border_tileset = 33,
  anon_sym_GT = 34,
  sym_serial_dialog_option_type = 35,
  anon_sym_script = 36,
  anon_sym_json = 37,
  anon_sym_COLON = 38,
  sym_json_number = 39,
  anon_sym_true = 40,
  anon_sym_false = 41,
  anon_sym_null = 42,
  anon_sym_rand = 43,
  anon_sym_BANG = 44,
  anon_sym_LPAREN = 45,
  anon_sym_RPAREN = 46,
  sym_action_return_statement = 47,
  anon_sym_close = 48,
  anon_sym_save = 49,
  anon_sym_slot = 50,
  anon_sym_load = 51,
  anon_sym_erase = 52,
  anon_sym_map = 53,
  anon_sym_goto = 54,
  anon_sym_index = 55,
  anon_sym_wait = 56,
  anon_sym_block = 57,
  sym_document = 58,
  sym_bareword_expansion = 59,
  sym_quoted_string_expansion = 60,
  sym_string_expansion = 61,
  sym_number_expansion = 62,
  sym_DURATION = 63,
  sym_duration_expansion = 64,
  sym_DISTANCE = 65,
  sym_QUANTITY = 66,
  sym__root = 67,
  sym_include_macro = 68,
  sym_constant_assignment = 69,
  sym_add_serial_dialog_settings = 70,
  sym_serial_dialog_parameter_int = 71,
  sym_serial_dialog_parameter = 72,
  sym_add_dialog_settings = 73,
  sym_target_label = 74,
  sym_target_entity = 75,
  sym_add_dialog_settings_target = 76,
  sym__dialog_parameter_int = 77,
  sym__dialog_parameter_string = 78,
  sym_dialog_parameter = 79,
  sym_dialog_definition = 80,
  sym__dialog_block = 81,
  sym_dialog = 82,
  sym_dialog_identifier = 83,
  sym_dialog_option = 84,
  sym_serial_dialog_definition = 85,
  sym__serial_dialog_block = 86,
  sym_serial_dialog = 87,
  sym_serial_dialog_option = 88,
  sym_script_definition = 89,
  sym_script_block = 90,
  sym__script_item = 91,
  sym_json_literal = 92,
  sym_json_array = 93,
  sym_json_object = 94,
  sym_json_name_value_pair = 95,
  sym__json_item = 96,
  sym_rand_macro = 97,
  sym_label_definition = 98,
  sym__action_item = 99,
  sym_action_close_dialog = 100,
  sym_action_close_serial_dialog = 101,
  sym_action_save_slot = 102,
  sym_action_load_slot = 103,
  sym_action_erase_slot = 104,
  sym_action_load_map = 105,
  sym_action_run_script = 106,
  sym_action_goto_label = 107,
  sym_action_goto_index = 108,
  sym_action_non_blocking_delay = 109,
  sym_action_blocking_delay = 110,
  aux_sym_document_repeat1 = 111,
  aux_sym_bareword_expansion_repeat1 = 112,
  aux_sym_quoted_string_expansion_repeat1 = 113,
  aux_sym_string_expansion_repeat1 = 114,
  aux_sym_number_expansion_repeat1 = 115,
  aux_sym_duration_expansion_repeat1 = 116,
  aux_sym_add_serial_dialog_settings_repeat1 = 117,
  aux_sym_add_dialog_settings_repeat1 = 118,
  aux_sym_add_dialog_settings_target_repeat1 = 119,
  aux_sym__dialog_block_repeat1 = 120,
  aux_sym_dialog_repeat1 = 121,
  aux_sym_dialog_repeat2 = 122,
  aux_sym_serial_dialog_repeat1 = 123,
  aux_sym_serial_dialog_repeat2 = 124,
  aux_sym_serial_dialog_repeat3 = 125,
  aux_sym_script_block_repeat1 = 126,
  aux_sym_json_array_repeat1 = 127,
  aux_sym_json_object_repeat1 = 128,
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
  [anon_sym_wrap] = "wrap",
  [anon_sym_dialog] = "dialog",
  [sym_target_default] = "target_default",
  [anon_sym_label] = "label",
  [anon_sym_entity] = "entity",
  [anon_sym_emote] = "emote",
  [anon_sym_name] = "name",
  [anon_sym_portrait] = "portrait",
  [anon_sym_alignment] = "alignment",
  [anon_sym_border_tileset] = "border_tileset",
  [anon_sym_GT] = ">",
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
  [sym_serial_dialog_parameter_int] = "BAREWORD",
  [sym_serial_dialog_parameter] = "serial_dialog_parameter",
  [sym_add_dialog_settings] = "add_dialog_settings",
  [sym_target_label] = "target_label",
  [sym_target_entity] = "target_entity",
  [sym_add_dialog_settings_target] = "add_dialog_settings_target",
  [sym__dialog_parameter_int] = "_dialog_parameter_int",
  [sym__dialog_parameter_string] = "_dialog_parameter_string",
  [sym_dialog_parameter] = "dialog_parameter",
  [sym_dialog_definition] = "dialog_definition",
  [sym__dialog_block] = "_dialog_block",
  [sym_dialog] = "dialog",
  [sym_dialog_identifier] = "dialog_identifier",
  [sym_dialog_option] = "dialog_option",
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
  [sym_label_definition] = "label_definition",
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
  [aux_sym__dialog_block_repeat1] = "_dialog_block_repeat1",
  [aux_sym_dialog_repeat1] = "dialog_repeat1",
  [aux_sym_dialog_repeat2] = "dialog_repeat2",
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
  [anon_sym_wrap] = anon_sym_wrap,
  [anon_sym_dialog] = anon_sym_dialog,
  [sym_target_default] = sym_target_default,
  [anon_sym_label] = anon_sym_label,
  [anon_sym_entity] = anon_sym_entity,
  [anon_sym_emote] = anon_sym_emote,
  [anon_sym_name] = anon_sym_name,
  [anon_sym_portrait] = anon_sym_portrait,
  [anon_sym_alignment] = anon_sym_alignment,
  [anon_sym_border_tileset] = anon_sym_border_tileset,
  [anon_sym_GT] = anon_sym_GT,
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
  [sym_serial_dialog_parameter_int] = sym_BAREWORD,
  [sym_serial_dialog_parameter] = sym_serial_dialog_parameter,
  [sym_add_dialog_settings] = sym_add_dialog_settings,
  [sym_target_label] = sym_target_label,
  [sym_target_entity] = sym_target_entity,
  [sym_add_dialog_settings_target] = sym_add_dialog_settings_target,
  [sym__dialog_parameter_int] = sym__dialog_parameter_int,
  [sym__dialog_parameter_string] = sym__dialog_parameter_string,
  [sym_dialog_parameter] = sym_dialog_parameter,
  [sym_dialog_definition] = sym_dialog_definition,
  [sym__dialog_block] = sym__dialog_block,
  [sym_dialog] = sym_dialog,
  [sym_dialog_identifier] = sym_dialog_identifier,
  [sym_dialog_option] = sym_dialog_option,
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
  [sym_label_definition] = sym_label_definition,
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
  [aux_sym__dialog_block_repeat1] = aux_sym__dialog_block_repeat1,
  [aux_sym_dialog_repeat1] = aux_sym_dialog_repeat1,
  [aux_sym_dialog_repeat2] = aux_sym_dialog_repeat2,
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
  [anon_sym_wrap] = {
    .visible = true,
    .named = false,
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
  [anon_sym_entity] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_emote] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_name] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_portrait] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alignment] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_border_tileset] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
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
  [sym_serial_dialog_parameter_int] = {
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
  [sym_target_entity] = {
    .visible = true,
    .named = true,
  },
  [sym_add_dialog_settings_target] = {
    .visible = true,
    .named = true,
  },
  [sym__dialog_parameter_int] = {
    .visible = false,
    .named = true,
  },
  [sym__dialog_parameter_string] = {
    .visible = false,
    .named = true,
  },
  [sym_dialog_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__dialog_block] = {
    .visible = false,
    .named = true,
  },
  [sym_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_dialog_option] = {
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
  [sym_label_definition] = {
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
  [aux_sym__dialog_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dialog_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dialog_repeat2] = {
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
  field_dialog = 1,
  field_dialog_name = 2,
  field_dialog_option = 3,
  field_dialog_parameter = 4,
  field_duration = 5,
  field_entity = 6,
  field_fileName = 7,
  field_index = 8,
  field_label = 9,
  field_map = 10,
  field_message = 11,
  field_name = 12,
  field_option_type = 13,
  field_property = 14,
  field_script = 15,
  field_script_name = 16,
  field_serial_dialog = 17,
  field_serial_dialog_name = 18,
  field_serial_dialog_option = 19,
  field_serial_dialog_parameter = 20,
  field_serial_message = 21,
  field_slot = 22,
  field_suffix = 23,
  field_target = 24,
  field_type = 25,
  field_value = 26,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_dialog] = "dialog",
  [field_dialog_name] = "dialog_name",
  [field_dialog_option] = "dialog_option",
  [field_dialog_parameter] = "dialog_parameter",
  [field_duration] = "duration",
  [field_entity] = "entity",
  [field_fileName] = "fileName",
  [field_index] = "index",
  [field_label] = "label",
  [field_map] = "map",
  [field_message] = "message",
  [field_name] = "name",
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
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 1},
  [6] = {.index = 7, .length = 1},
  [7] = {.index = 8, .length = 1},
  [8] = {.index = 9, .length = 1},
  [9] = {.index = 10, .length = 2},
  [10] = {.index = 12, .length = 1},
  [11] = {.index = 13, .length = 1},
  [12] = {.index = 14, .length = 1},
  [13] = {.index = 15, .length = 1},
  [14] = {.index = 16, .length = 1},
  [15] = {.index = 17, .length = 1},
  [16] = {.index = 18, .length = 1},
  [17] = {.index = 19, .length = 1},
  [18] = {.index = 20, .length = 1},
  [19] = {.index = 21, .length = 2},
  [20] = {.index = 23, .length = 1},
  [21] = {.index = 24, .length = 2},
  [22] = {.index = 26, .length = 2},
  [23] = {.index = 28, .length = 1},
  [24] = {.index = 29, .length = 2},
  [25] = {.index = 31, .length = 2},
  [26] = {.index = 33, .length = 1},
  [27] = {.index = 34, .length = 1},
  [28] = {.index = 35, .length = 1},
  [29] = {.index = 36, .length = 1},
  [30] = {.index = 37, .length = 1},
  [31] = {.index = 38, .length = 1},
  [32] = {.index = 39, .length = 2},
  [33] = {.index = 41, .length = 3},
  [34] = {.index = 44, .length = 2},
  [35] = {.index = 46, .length = 2},
  [36] = {.index = 48, .length = 2},
  [37] = {.index = 50, .length = 1},
  [38] = {.index = 51, .length = 2},
  [39] = {.index = 53, .length = 2},
  [40] = {.index = 55, .length = 1},
  [41] = {.index = 56, .length = 3},
  [42] = {.index = 59, .length = 2},
  [43] = {.index = 61, .length = 2},
  [44] = {.index = 63, .length = 2},
  [45] = {.index = 65, .length = 2},
  [46] = {.index = 67, .length = 3},
  [47] = {.index = 70, .length = 3},
  [48] = {.index = 73, .length = 2},
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
    {field_dialog, 2, .inherited = true},
    {field_dialog_name, 1},
  [6] =
    {field_script_name, 1},
  [7] =
    {field_label, 0},
  [8] =
    {field_script, 1},
  [9] =
    {field_duration, 1},
  [10] =
    {field_label, 0},
    {field_value, 2},
  [12] =
    {field_suffix, 1},
  [13] =
    {field_serial_message, 0},
  [14] =
    {field_serial_dialog_parameter, 0},
  [15] =
    {field_serial_message, 0, .inherited = true},
  [16] =
    {field_dialog, 0},
  [17] =
    {field_slot, 2},
  [18] =
    {field_map, 2},
  [19] =
    {field_label, 2},
  [20] =
    {field_index, 2},
  [21] =
    {field_property, 0},
    {field_value, 1},
  [23] =
    {field_serial_dialog, 1},
  [24] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_dialog_parameter, 1, .inherited = true},
  [26] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [28] =
    {field_serial_dialog_option, 0},
  [29] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [31] =
    {field_serial_dialog_option, 1, .inherited = true},
    {field_serial_message, 0, .inherited = true},
  [33] =
    {field_entity, 1},
  [34] =
    {field_name, 1},
  [35] =
    {field_message, 0},
  [36] =
    {field_dialog_parameter, 0},
  [37] =
    {field_message, 1, .inherited = true},
  [38] =
    {field_dialog, 1, .inherited = true},
  [39] =
    {field_dialog, 0, .inherited = true},
    {field_dialog, 1, .inherited = true},
  [41] =
    {field_serial_dialog_option, 2, .inherited = true},
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [44] =
    {field_serial_dialog_option, 0, .inherited = true},
    {field_serial_dialog_option, 1, .inherited = true},
  [46] =
    {field_dialog_parameter, 0, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
  [48] =
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [50] =
    {field_dialog_option, 0},
  [51] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [53] =
    {field_dialog_option, 2, .inherited = true},
    {field_message, 1, .inherited = true},
  [55] =
    {field_type, 0},
  [56] =
    {field_dialog_option, 3, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [59] =
    {field_dialog_option, 0, .inherited = true},
    {field_dialog_option, 1, .inherited = true},
  [61] =
    {field_property, 0},
    {field_value, 2},
  [63] =
    {field_dialog_parameter, 2, .inherited = true},
    {field_type, 0},
  [65] =
    {field_target, 1},
    {field_type, 0},
  [67] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [70] =
    {field_dialog_parameter, 3, .inherited = true},
    {field_target, 1},
    {field_type, 0},
  [73] =
    {field_label, 1},
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
  [200] = 200,
  [201] = 201,
  [202] = 202,
  [203] = 203,
  [204] = 204,
  [205] = 205,
  [206] = 206,
  [207] = 207,
  [208] = 208,
  [209] = 209,
  [210] = 210,
  [211] = 211,
  [212] = 212,
  [213] = 213,
  [214] = 214,
  [215] = 215,
  [216] = 216,
  [217] = 217,
  [218] = 218,
  [219] = 219,
  [220] = 220,
  [221] = 221,
  [222] = 222,
  [223] = 223,
  [224] = 224,
  [225] = 225,
  [226] = 226,
  [227] = 227,
  [228] = 228,
  [229] = 229,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(190);
      ADVANCE_MAP(
        '!', 375,
        '"', 7,
        '#', 362,
        '$', 186,
        '(', 376,
        ')', 377,
        ',', 321,
        '-', 13,
        '/', 9,
        ':', 367,
        ';', 337,
        '=', 338,
        '>', 360,
        'I', 114,
        '[', 320,
        ']', 322,
        '_', 361,
        'a', 41,
        'b', 97,
        'c', 98,
        'd', 60,
        'e', 111,
        'f', 16,
        'g', 130,
        'i', 115,
        'j', 150,
        'l', 17,
        'm', 19,
        'n', 20,
        'o', 116,
        'p', 80,
        'r', 30,
        's', 326,
        't', 78,
        'w', 26,
        'x', 328,
        'y', 68,
        '{', 344,
        '}', 345,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(188);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(324);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 7,
        '#', 183,
        '$', 186,
        '/', 9,
        'b', 263,
        'c', 269,
        'f', 208,
        'g', 297,
        'm', 205,
        'o', 243,
        'r', 238,
        't', 248,
        'w', 249,
        'y', 237,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(324);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(7);
      if (lookahead == '$') ADVANCE(186);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '[') ADVANCE(320);
      if (lookahead == ']') ADVANCE(322);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(7);
      if (lookahead == '$') ADVANCE(186);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '[') ADVANCE(320);
      if (lookahead == 'i') ADVANCE(281);
      if (lookahead == 'l') ADVANCE(200);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 7,
        ',', 321,
        '-', 13,
        '/', 9,
        ';', 337,
        'I', 114,
        '[', 320,
        ']', 322,
        'f', 16,
        'm', 148,
        'n', 172,
        'p', 81,
        's', 325,
        't', 139,
        'x', 328,
        '{', 344,
        '}', 345,
        '#', 361,
        '_', 361,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(369);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '"', 7,
        ',', 321,
        '-', 13,
        '/', 9,
        ';', 337,
        'I', 114,
        '[', 320,
        ']', 322,
        'f', 16,
        'n', 172,
        't', 139,
        '{', 344,
        '}', 345,
        '#', 361,
        '_', 361,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(369);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(7);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == '>') ADVANCE(360);
      if (lookahead == 'e') ADVANCE(280);
      if (lookahead == 'n') ADVANCE(199);
      if (lookahead == '}') ADVANCE(345);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 7:
      if (lookahead == '"') ADVANCE(323);
      if (lookahead == '\\') ADVANCE(187);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        ')', 377,
        ',', 321,
        '/', 9,
        ']', 322,
        'b', 265,
        'c', 266,
        'e', 296,
        'g', 287,
        'j', 301,
        'l', 290,
        'r', 201,
        's', 198,
        'w', 202,
        '}', 345,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(11);
      if (lookahead == '/') ADVANCE(192);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == 'd') ADVANCE(92);
      if (lookahead == 'm') ADVANCE(29);
      if (lookahead == 's') ADVANCE(49);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      END_STATE();
    case 13:
      if (lookahead == 'I') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(369);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(48);
      END_STATE();
    case 15:
      if (lookahead == '_') ADVANCE(167);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(110);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(77);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(77);
      if (lookahead == 's') ADVANCE(325);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(112);
      if (lookahead == 'u') ADVANCE(103);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(177);
      if (lookahead == 'c') ADVANCE(144);
      if (lookahead == 'e') ADVANCE(145);
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(330);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(137);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(37);
      if (lookahead == 'o') ADVANCE(38);
      if (lookahead == 'u') ADVANCE(50);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(44);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(84);
      if (lookahead == 'h') ADVANCE(86);
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(174);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(136);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(121);
      if (lookahead == 'e') ADVANCE(43);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(117);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(101);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(152);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(106);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 36:
      if (lookahead == 'b') ADVANCE(64);
      END_STATE();
    case 37:
      if (lookahead == 'c') ADVANCE(95);
      END_STATE();
    case 38:
      if (lookahead == 'c') ADVANCE(96);
      END_STATE();
    case 39:
      if (lookahead == 'c') ADVANCE(102);
      if (lookahead == 'd') ADVANCE(61);
      END_STATE();
    case 40:
      if (lookahead == 'c') ADVANCE(52);
      END_STATE();
    case 41:
      if (lookahead == 'd') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 42:
      if (lookahead == 'd') ADVANCE(339);
      END_STATE();
    case 43:
      if (lookahead == 'd') ADVANCE(330);
      if (lookahead == 't') ADVANCE(173);
      END_STATE();
    case 44:
      if (lookahead == 'd') ADVANCE(385);
      END_STATE();
    case 45:
      if (lookahead == 'd') ADVANCE(373);
      END_STATE();
    case 46:
      if (lookahead == 'd') ADVANCE(65);
      END_STATE();
    case 47:
      if (lookahead == 'd') ADVANCE(59);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(94);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(145);
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(330);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(355);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(329);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(382);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(370);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(380);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(354);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(387);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(371);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(335);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(72);
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(180);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(117);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(100);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(140);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(122);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(162);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(109);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(123);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(154);
      END_STATE();
    case 71:
      if (lookahead == 'f') ADVANCE(85);
      END_STATE();
    case 72:
      if (lookahead == 'f') ADVANCE(28);
      END_STATE();
    case 73:
      if (lookahead == 'g') ADVANCE(347);
      END_STATE();
    case 74:
      if (lookahead == 'g') ADVANCE(341);
      END_STATE();
    case 75:
      if (lookahead == 'g') ADVANCE(149);
      END_STATE();
    case 76:
      if (lookahead == 'g') ADVANCE(124);
      END_STATE();
    case 77:
      if (lookahead == 'g') ADVANCE(66);
      if (lookahead == 'p') ADVANCE(389);
      END_STATE();
    case 78:
      if (lookahead == 'h') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(175);
      if (lookahead == 'w') ADVANCE(79);
      END_STATE();
    case 79:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 80:
      if (lookahead == 'i') ADVANCE(179);
      if (lookahead == 'o') ADVANCE(143);
      if (lookahead == 'x') ADVANCE(327);
      END_STATE();
    case 81:
      if (lookahead == 'i') ADVANCE(179);
      if (lookahead == 'x') ADVANCE(327);
      END_STATE();
    case 82:
      if (lookahead == 'i') ADVANCE(76);
      END_STATE();
    case 83:
      if (lookahead == 'i') ADVANCE(138);
      END_STATE();
    case 84:
      if (lookahead == 'i') ADVANCE(156);
      END_STATE();
    case 85:
      if (lookahead == 'i') ADVANCE(125);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(164);
      END_STATE();
    case 87:
      if (lookahead == 'i') ADVANCE(157);
      END_STATE();
    case 88:
      if (lookahead == 'i') ADVANCE(108);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(120);
      END_STATE();
    case 90:
      if (lookahead == 'i') ADVANCE(163);
      END_STATE();
    case 91:
      if (lookahead == 'i') ADVANCE(160);
      END_STATE();
    case 92:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 93:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 94:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 95:
      if (lookahead == 'k') ADVANCE(330);
      END_STATE();
    case 96:
      if (lookahead == 'k') ADVANCE(396);
      END_STATE();
    case 97:
      if (lookahead == 'l') ADVANCE(24);
      if (lookahead == 'o') ADVANCE(141);
      END_STATE();
    case 98:
      if (lookahead == 'l') ADVANCE(128);
      if (lookahead == 'y') ADVANCE(31);
      END_STATE();
    case 99:
      if (lookahead == 'l') ADVANCE(372);
      END_STATE();
    case 100:
      if (lookahead == 'l') ADVANCE(350);
      END_STATE();
    case 101:
      if (lookahead == 'l') ADVANCE(14);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(176);
      END_STATE();
    case 103:
      if (lookahead == 'l') ADVANCE(99);
      END_STATE();
    case 104:
      if (lookahead == 'l') ADVANCE(131);
      END_STATE();
    case 105:
      if (lookahead == 'l') ADVANCE(127);
      END_STATE();
    case 106:
      if (lookahead == 'l') ADVANCE(133);
      END_STATE();
    case 107:
      if (lookahead == 'l') ADVANCE(159);
      END_STATE();
    case 108:
      if (lookahead == 'l') ADVANCE(70);
      END_STATE();
    case 109:
      if (lookahead == 'l') ADVANCE(105);
      END_STATE();
    case 110:
      if (lookahead == 'l') ADVANCE(153);
      END_STATE();
    case 111:
      if (lookahead == 'm') ADVANCE(132);
      if (lookahead == 'n') ADVANCE(171);
      if (lookahead == 'r') ADVANCE(33);
      END_STATE();
    case 112:
      if (lookahead == 'm') ADVANCE(51);
      END_STATE();
    case 113:
      if (lookahead == 'm') ADVANCE(69);
      END_STATE();
    case 114:
      if (lookahead == 'n') ADVANCE(71);
      END_STATE();
    case 115:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 116:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 117:
      if (lookahead == 'n') ADVANCE(330);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(365);
      END_STATE();
    case 119:
      if (lookahead == 'n') ADVANCE(378);
      END_STATE();
    case 120:
      if (lookahead == 'n') ADVANCE(75);
      END_STATE();
    case 121:
      if (lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 122:
      if (lookahead == 'n') ADVANCE(168);
      END_STATE();
    case 123:
      if (lookahead == 'n') ADVANCE(161);
      END_STATE();
    case 124:
      if (lookahead == 'n') ADVANCE(113);
      END_STATE();
    case 125:
      if (lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 126:
      if (lookahead == 'o') ADVANCE(390);
      END_STATE();
    case 127:
      if (lookahead == 'o') ADVANCE(178);
      END_STATE();
    case 128:
      if (lookahead == 'o') ADVANCE(151);
      END_STATE();
    case 129:
      if (lookahead == 'o') ADVANCE(143);
      END_STATE();
    case 130:
      if (lookahead == 'o') ADVANCE(166);
      if (lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 131:
      if (lookahead == 'o') ADVANCE(73);
      END_STATE();
    case 132:
      if (lookahead == 'o') ADVANCE(169);
      END_STATE();
    case 133:
      if (lookahead == 'o') ADVANCE(74);
      END_STATE();
    case 134:
      if (lookahead == 'o') ADVANCE(155);
      END_STATE();
    case 135:
      if (lookahead == 'o') ADVANCE(118);
      END_STATE();
    case 136:
      if (lookahead == 'p') ADVANCE(389);
      END_STATE();
    case 137:
      if (lookahead == 'p') ADVANCE(346);
      END_STATE();
    case 138:
      if (lookahead == 'p') ADVANCE(158);
      END_STATE();
    case 139:
      if (lookahead == 'r') ADVANCE(175);
      END_STATE();
    case 140:
      if (lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 141:
      if (lookahead == 'r') ADVANCE(46);
      END_STATE();
    case 142:
      if (lookahead == 'r') ADVANCE(79);
      END_STATE();
    case 143:
      if (lookahead == 'r') ADVANCE(165);
      END_STATE();
    case 144:
      if (lookahead == 'r') ADVANCE(83);
      END_STATE();
    case 145:
      if (lookahead == 'r') ADVANCE(93);
      if (lookahead == 't') ADVANCE(170);
      END_STATE();
    case 146:
      if (lookahead == 'r') ADVANCE(35);
      END_STATE();
    case 147:
      if (lookahead == 'r') ADVANCE(119);
      END_STATE();
    case 148:
      if (lookahead == 's') ADVANCE(325);
      END_STATE();
    case 149:
      if (lookahead == 's') ADVANCE(343);
      END_STATE();
    case 150:
      if (lookahead == 's') ADVANCE(135);
      END_STATE();
    case 151:
      if (lookahead == 's') ADVANCE(55);
      END_STATE();
    case 152:
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 153:
      if (lookahead == 's') ADVANCE(58);
      END_STATE();
    case 154:
      if (lookahead == 's') ADVANCE(67);
      END_STATE();
    case 155:
      if (lookahead == 't') ADVANCE(384);
      END_STATE();
    case 156:
      if (lookahead == 't') ADVANCE(394);
      END_STATE();
    case 157:
      if (lookahead == 't') ADVANCE(181);
      END_STATE();
    case 158:
      if (lookahead == 't') ADVANCE(363);
      END_STATE();
    case 159:
      if (lookahead == 't') ADVANCE(349);
      END_STATE();
    case 160:
      if (lookahead == 't') ADVANCE(357);
      END_STATE();
    case 161:
      if (lookahead == 't') ADVANCE(358);
      END_STATE();
    case 162:
      if (lookahead == 't') ADVANCE(359);
      END_STATE();
    case 163:
      if (lookahead == 't') ADVANCE(182);
      END_STATE();
    case 164:
      if (lookahead == 't') ADVANCE(50);
      END_STATE();
    case 165:
      if (lookahead == 't') ADVANCE(146);
      END_STATE();
    case 166:
      if (lookahead == 't') ADVANCE(126);
      END_STATE();
    case 167:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 168:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 169:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 170:
      if (lookahead == 't') ADVANCE(89);
      END_STATE();
    case 171:
      if (lookahead == 't') ADVANCE(87);
      END_STATE();
    case 172:
      if (lookahead == 'u') ADVANCE(103);
      END_STATE();
    case 173:
      if (lookahead == 'u') ADVANCE(147);
      END_STATE();
    case 174:
      if (lookahead == 'u') ADVANCE(107);
      END_STATE();
    case 175:
      if (lookahead == 'u') ADVANCE(54);
      END_STATE();
    case 176:
      if (lookahead == 'u') ADVANCE(47);
      END_STATE();
    case 177:
      if (lookahead == 'v') ADVANCE(53);
      END_STATE();
    case 178:
      if (lookahead == 'w') ADVANCE(330);
      END_STATE();
    case 179:
      if (lookahead == 'x') ADVANCE(327);
      END_STATE();
    case 180:
      if (lookahead == 'x') ADVANCE(392);
      END_STATE();
    case 181:
      if (lookahead == 'y') ADVANCE(352);
      END_STATE();
    case 182:
      if (lookahead == 'y') ADVANCE(368);
      END_STATE();
    case 183:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(185);
      END_STATE();
    case 184:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(333);
      END_STATE();
    case 185:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(184);
      END_STATE();
    case 186:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 187:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(7);
      END_STATE();
    case 188:
      if (eof) ADVANCE(190);
      ADVANCE_MAP(
        '!', 375,
        '"', 7,
        '#', 362,
        '$', 186,
        '(', 376,
        ')', 377,
        ',', 321,
        '-', 13,
        '/', 9,
        ':', 367,
        ';', 337,
        '=', 338,
        '>', 360,
        'I', 114,
        '[', 320,
        ']', 322,
        '_', 361,
        'a', 41,
        'b', 97,
        'c', 98,
        'd', 60,
        'e', 111,
        'f', 16,
        'g', 130,
        'i', 115,
        'j', 150,
        'l', 17,
        'm', 18,
        'n', 20,
        'o', 116,
        'p', 129,
        'r', 30,
        's', 21,
        't', 78,
        'w', 26,
        'y', 68,
        '{', 344,
        '}', 345,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(188);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(324);
      END_STATE();
    case 189:
      if (eof) ADVANCE(190);
      ADVANCE_MAP(
        '"', 7,
        '$', 186,
        '/', 9,
        '[', 320,
        ']', 322,
        'a', 223,
        'd', 250,
        'i', 274,
        's', 212,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(189);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(324);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(11);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(192);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(278);
      if (lookahead == 'e') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(215);
      if (lookahead == 'u') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(293);
      if (lookahead == 'e') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(340);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(374);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(336);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(388);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(244);
      if (lookahead == 'n') ADVANCE(193);
      if (lookahead == 'p') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(294);
      if (lookahead == 'r') ADVANCE(314);
      if (lookahead == 'w') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(291);
      if (lookahead == 'y') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(299);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(364);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(395);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(393);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(324);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(177);
      if (lookahead == 'c') ADVANCE(144);
      if (lookahead == 'e') ADVANCE(145);
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_COLOR);
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
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(332);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_target_default);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(anon_sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(185);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(369);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_action_return_statement);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_action_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(319);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 189},
  [2] = {.lex_state = 8},
  [3] = {.lex_state = 8},
  [4] = {.lex_state = 8},
  [5] = {.lex_state = 8},
  [6] = {.lex_state = 8},
  [7] = {.lex_state = 189},
  [8] = {.lex_state = 189},
  [9] = {.lex_state = 8},
  [10] = {.lex_state = 8},
  [11] = {.lex_state = 8},
  [12] = {.lex_state = 8},
  [13] = {.lex_state = 8},
  [14] = {.lex_state = 8},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 8},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 8},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 4},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 4},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 189},
  [29] = {.lex_state = 189},
  [30] = {.lex_state = 189},
  [31] = {.lex_state = 189},
  [32] = {.lex_state = 189},
  [33] = {.lex_state = 189},
  [34] = {.lex_state = 189},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 189},
  [37] = {.lex_state = 6},
  [38] = {.lex_state = 189},
  [39] = {.lex_state = 189},
  [40] = {.lex_state = 189},
  [41] = {.lex_state = 189},
  [42] = {.lex_state = 189},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 6},
  [45] = {.lex_state = 189},
  [46] = {.lex_state = 189},
  [47] = {.lex_state = 189},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 6},
  [56] = {.lex_state = 6},
  [57] = {.lex_state = 6},
  [58] = {.lex_state = 6},
  [59] = {.lex_state = 6},
  [60] = {.lex_state = 3},
  [61] = {.lex_state = 6},
  [62] = {.lex_state = 6},
  [63] = {.lex_state = 4},
  [64] = {.lex_state = 6},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 4},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 6},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 189},
  [71] = {.lex_state = 189},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 6},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 4},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 4},
  [79] = {.lex_state = 4},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 189},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 6},
  [86] = {.lex_state = 189},
  [87] = {.lex_state = 189},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 189},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 189},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 4},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 4},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 2},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 189},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 189},
  [119] = {.lex_state = 189},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 2},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 2},
  [128] = {.lex_state = 2},
  [129] = {.lex_state = 2},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 189},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 2},
  [135] = {.lex_state = 2},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 189},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 2},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 2},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 12},
  [149] = {.lex_state = 2},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 12},
  [152] = {.lex_state = 2},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 2},
  [155] = {.lex_state = 2},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 4},
  [158] = {.lex_state = 2},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 189},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 189},
  [168] = {.lex_state = 12},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 189},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 4},
  [173] = {.lex_state = 189},
  [174] = {.lex_state = 2},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 12},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 0},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 12},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 12},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 12},
  [229] = {.lex_state = 0},
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
    [anon_sym_wrap] = ACTIONS(1),
    [anon_sym_dialog] = ACTIONS(1),
    [sym_target_default] = ACTIONS(1),
    [anon_sym_label] = ACTIONS(1),
    [anon_sym_entity] = ACTIONS(1),
    [anon_sym_emote] = ACTIONS(1),
    [anon_sym_name] = ACTIONS(1),
    [anon_sym_portrait] = ACTIONS(1),
    [anon_sym_alignment] = ACTIONS(1),
    [anon_sym_border_tileset] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
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
    [sym_document] = STATE(211),
    [sym__root] = STATE(8),
    [sym_include_macro] = STATE(8),
    [sym_constant_assignment] = STATE(8),
    [sym_add_serial_dialog_settings] = STATE(8),
    [sym_add_dialog_settings] = STATE(8),
    [sym_dialog_definition] = STATE(8),
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
    [anon_sym_dialog] = ACTIONS(19),
    [anon_sym_script] = ACTIONS(21),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 15,
    ACTIONS(23), 1,
      sym_BAREWORD,
    ACTIONS(28), 1,
      anon_sym_json,
    ACTIONS(31), 1,
      anon_sym_rand,
    ACTIONS(34), 1,
      sym_action_return_statement,
    ACTIONS(37), 1,
      anon_sym_close,
    ACTIONS(40), 1,
      anon_sym_save,
    ACTIONS(43), 1,
      anon_sym_load,
    ACTIONS(46), 1,
      anon_sym_erase,
    ACTIONS(49), 1,
      anon_sym_goto,
    ACTIONS(52), 1,
      anon_sym_wait,
    ACTIONS(55), 1,
      anon_sym_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(26), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(2), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      aux_sym_script_block_repeat1,
    STATE(209), 12,
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
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(60), 1,
      anon_sym_RBRACE,
    ACTIONS(62), 1,
      anon_sym_json,
    ACTIONS(64), 1,
      anon_sym_rand,
    ACTIONS(66), 1,
      sym_action_return_statement,
    ACTIONS(68), 1,
      anon_sym_close,
    ACTIONS(70), 1,
      anon_sym_save,
    ACTIONS(72), 1,
      anon_sym_load,
    ACTIONS(74), 1,
      anon_sym_erase,
    ACTIONS(76), 1,
      anon_sym_goto,
    ACTIONS(78), 1,
      anon_sym_wait,
    ACTIONS(80), 1,
      anon_sym_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(4), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      aux_sym_script_block_repeat1,
    STATE(209), 12,
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
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(62), 1,
      anon_sym_json,
    ACTIONS(64), 1,
      anon_sym_rand,
    ACTIONS(66), 1,
      sym_action_return_statement,
    ACTIONS(68), 1,
      anon_sym_close,
    ACTIONS(70), 1,
      anon_sym_save,
    ACTIONS(72), 1,
      anon_sym_load,
    ACTIONS(74), 1,
      anon_sym_erase,
    ACTIONS(76), 1,
      anon_sym_goto,
    ACTIONS(78), 1,
      anon_sym_wait,
    ACTIONS(80), 1,
      anon_sym_block,
    ACTIONS(82), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      aux_sym_script_block_repeat1,
    STATE(209), 12,
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
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(62), 1,
      anon_sym_json,
    ACTIONS(64), 1,
      anon_sym_rand,
    ACTIONS(66), 1,
      sym_action_return_statement,
    ACTIONS(68), 1,
      anon_sym_close,
    ACTIONS(70), 1,
      anon_sym_save,
    ACTIONS(72), 1,
      anon_sym_load,
    ACTIONS(74), 1,
      anon_sym_erase,
    ACTIONS(76), 1,
      anon_sym_goto,
    ACTIONS(78), 1,
      anon_sym_wait,
    ACTIONS(80), 1,
      anon_sym_block,
    ACTIONS(84), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(6), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      aux_sym_script_block_repeat1,
    STATE(209), 12,
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
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(62), 1,
      anon_sym_json,
    ACTIONS(64), 1,
      anon_sym_rand,
    ACTIONS(66), 1,
      sym_action_return_statement,
    ACTIONS(68), 1,
      anon_sym_close,
    ACTIONS(70), 1,
      anon_sym_save,
    ACTIONS(72), 1,
      anon_sym_load,
    ACTIONS(74), 1,
      anon_sym_erase,
    ACTIONS(76), 1,
      anon_sym_goto,
    ACTIONS(78), 1,
      anon_sym_wait,
    ACTIONS(80), 1,
      anon_sym_block,
    ACTIONS(86), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      aux_sym_script_block_repeat1,
    STATE(209), 12,
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
  [311] = 11,
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
      anon_sym_dialog,
    ACTIONS(111), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(7), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [354] = 11,
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
      anon_sym_dialog,
    ACTIONS(21), 1,
      anon_sym_script,
    ACTIONS(114), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(7), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [397] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(118), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(116), 11,
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
  [421] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(122), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(120), 11,
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
  [445] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(126), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(124), 11,
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
  [469] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(130), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(128), 11,
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
  [491] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(134), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(132), 11,
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
  [513] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(138), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(136), 11,
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
  [535] = 9,
    ACTIONS(140), 1,
      sym_QUOTED_STRING,
    STATE(17), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(35), 1,
      sym_dialog_parameter,
    STATE(37), 1,
      aux_sym_dialog_repeat1,
    STATE(127), 1,
      sym__dialog_parameter_string,
    STATE(161), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(144), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [569] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(148), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(146), 11,
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
  [591] = 9,
    ACTIONS(140), 1,
      sym_QUOTED_STRING,
    STATE(18), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(35), 1,
      sym_dialog_parameter,
    STATE(44), 1,
      aux_sym_dialog_repeat1,
    STATE(127), 1,
      sym__dialog_parameter_string,
    STATE(161), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(144), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [625] = 8,
    STATE(18), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(35), 1,
      sym_dialog_parameter,
    STATE(127), 1,
      sym__dialog_parameter_string,
    STATE(161), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(150), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    ACTIONS(152), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(155), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [657] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(160), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(158), 11,
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
  [679] = 8,
    ACTIONS(162), 1,
      anon_sym_RBRACE,
    STATE(21), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(35), 1,
      sym_dialog_parameter,
    STATE(127), 1,
      sym__dialog_parameter_string,
    STATE(161), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(144), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [710] = 8,
    ACTIONS(164), 1,
      anon_sym_RBRACE,
    STATE(18), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(35), 1,
      sym_dialog_parameter,
    STATE(127), 1,
      sym__dialog_parameter_string,
    STATE(161), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(144), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [741] = 8,
    ACTIONS(166), 1,
      anon_sym_RBRACE,
    STATE(23), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(35), 1,
      sym_dialog_parameter,
    STATE(127), 1,
      sym__dialog_parameter_string,
    STATE(161), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(144), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [772] = 8,
    ACTIONS(168), 1,
      anon_sym_RBRACE,
    STATE(18), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(35), 1,
      sym_dialog_parameter,
    STATE(127), 1,
      sym__dialog_parameter_string,
    STATE(161), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(144), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [803] = 6,
    ACTIONS(170), 1,
      anon_sym_LBRACK,
    ACTIONS(172), 1,
      anon_sym_RBRACK,
    ACTIONS(176), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(117), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(174), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [829] = 6,
    ACTIONS(182), 1,
      sym_NUMBER,
    ACTIONS(184), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(178), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(180), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(214), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [854] = 5,
    ACTIONS(170), 1,
      anon_sym_LBRACK,
    ACTIONS(176), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(153), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(186), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [877] = 5,
    ACTIONS(170), 1,
      anon_sym_LBRACK,
    ACTIONS(176), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(163), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(188), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [900] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(190), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(192), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [918] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(194), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(196), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [936] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(198), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(200), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [954] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(202), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(204), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [972] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(206), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(208), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [990] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(210), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(212), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1008] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(214), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(216), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1026] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(218), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1042] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(220), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(222), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1060] = 8,
    ACTIONS(140), 1,
      sym_QUOTED_STRING,
    ACTIONS(226), 1,
      anon_sym_RBRACE,
    ACTIONS(228), 1,
      anon_sym_GT,
    STATE(57), 1,
      aux_sym_dialog_repeat1,
    STATE(59), 1,
      aux_sym_dialog_repeat2,
    STATE(68), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(224), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1088] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(230), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(232), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1106] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(234), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(236), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1124] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(238), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(240), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1142] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(242), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(244), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1160] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(246), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(248), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1178] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(250), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1194] = 8,
    ACTIONS(140), 1,
      sym_QUOTED_STRING,
    ACTIONS(228), 1,
      anon_sym_GT,
    ACTIONS(254), 1,
      anon_sym_RBRACE,
    STATE(57), 1,
      aux_sym_dialog_repeat1,
    STATE(61), 1,
      aux_sym_dialog_repeat2,
    STATE(68), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(252), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1222] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(256), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(258), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1240] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(260), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(262), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1258] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(264), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(266), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1276] = 8,
    ACTIONS(268), 1,
      anon_sym_RBRACE,
    ACTIONS(270), 1,
      sym_target_default,
    ACTIONS(272), 1,
      anon_sym_label,
    ACTIONS(274), 1,
      anon_sym_entity,
    STATE(108), 1,
      sym_target_entity,
    STATE(152), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(49), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1303] = 8,
    ACTIONS(270), 1,
      sym_target_default,
    ACTIONS(272), 1,
      anon_sym_label,
    ACTIONS(274), 1,
      anon_sym_entity,
    ACTIONS(276), 1,
      anon_sym_RBRACE,
    STATE(108), 1,
      sym_target_entity,
    STATE(152), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(50), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1330] = 8,
    ACTIONS(278), 1,
      anon_sym_RBRACE,
    ACTIONS(280), 1,
      sym_target_default,
    ACTIONS(283), 1,
      anon_sym_label,
    ACTIONS(286), 1,
      anon_sym_entity,
    STATE(108), 1,
      sym_target_entity,
    STATE(152), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(50), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1357] = 9,
    ACTIONS(289), 1,
      sym_QUOTED_STRING,
    ACTIONS(291), 1,
      anon_sym_RBRACE,
    ACTIONS(293), 1,
      anon_sym_wrap,
    STATE(65), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(66), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(143), 1,
      sym_serial_dialog_parameter,
    STATE(170), 1,
      sym_serial_dialog_parameter_int,
    STATE(226), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1386] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(295), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1401] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(297), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1416] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(299), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1431] = 8,
    ACTIONS(301), 1,
      sym_BAREWORD,
    ACTIONS(303), 1,
      anon_sym_RBRACE,
    ACTIONS(305), 1,
      anon_sym_entity,
    ACTIONS(307), 1,
      anon_sym_name,
    STATE(15), 1,
      sym_dialog_identifier,
    STATE(58), 1,
      aux_sym__dialog_block_repeat1,
    STATE(85), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1457] = 8,
    ACTIONS(301), 1,
      sym_BAREWORD,
    ACTIONS(305), 1,
      anon_sym_entity,
    ACTIONS(307), 1,
      anon_sym_name,
    ACTIONS(309), 1,
      anon_sym_RBRACE,
    STATE(15), 1,
      sym_dialog_identifier,
    STATE(55), 1,
      aux_sym__dialog_block_repeat1,
    STATE(85), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1483] = 5,
    ACTIONS(313), 1,
      sym_QUOTED_STRING,
    STATE(57), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(316), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(311), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1503] = 8,
    ACTIONS(318), 1,
      sym_BAREWORD,
    ACTIONS(321), 1,
      anon_sym_RBRACE,
    ACTIONS(323), 1,
      anon_sym_entity,
    ACTIONS(326), 1,
      anon_sym_name,
    STATE(15), 1,
      sym_dialog_identifier,
    STATE(58), 1,
      aux_sym__dialog_block_repeat1,
    STATE(85), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1529] = 6,
    ACTIONS(228), 1,
      anon_sym_GT,
    ACTIONS(331), 1,
      anon_sym_RBRACE,
    STATE(62), 1,
      aux_sym_dialog_repeat2,
    STATE(68), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(329), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1551] = 7,
    ACTIONS(333), 1,
      sym_BAREWORD,
    ACTIONS(335), 1,
      anon_sym_LBRACK,
    ACTIONS(339), 1,
      anon_sym_label,
    ACTIONS(341), 1,
      anon_sym_index,
    STATE(220), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(337), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1575] = 6,
    ACTIONS(228), 1,
      anon_sym_GT,
    ACTIONS(345), 1,
      anon_sym_RBRACE,
    STATE(62), 1,
      aux_sym_dialog_repeat2,
    STATE(68), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(343), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1597] = 6,
    ACTIONS(349), 1,
      anon_sym_RBRACE,
    ACTIONS(351), 1,
      anon_sym_GT,
    STATE(62), 1,
      aux_sym_dialog_repeat2,
    STATE(68), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(347), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1619] = 7,
    ACTIONS(289), 1,
      sym_QUOTED_STRING,
    ACTIONS(354), 1,
      anon_sym_RBRACE,
    ACTIONS(356), 1,
      sym_serial_dialog_option_type,
    STATE(79), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(84), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(157), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1642] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(358), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
    ACTIONS(360), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [1657] = 7,
    ACTIONS(289), 1,
      sym_QUOTED_STRING,
    ACTIONS(293), 1,
      anon_sym_wrap,
    STATE(63), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(72), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(143), 1,
      sym_serial_dialog_parameter,
    STATE(170), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1680] = 7,
    ACTIONS(289), 1,
      sym_QUOTED_STRING,
    ACTIONS(356), 1,
      sym_serial_dialog_option_type,
    ACTIONS(362), 1,
      anon_sym_RBRACE,
    STATE(79), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(80), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(157), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1703] = 5,
    ACTIONS(293), 1,
      anon_sym_wrap,
    ACTIONS(364), 1,
      anon_sym_RBRACE,
    STATE(170), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(73), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1721] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(368), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(366), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1735] = 5,
    ACTIONS(293), 1,
      anon_sym_wrap,
    ACTIONS(370), 1,
      anon_sym_RBRACE,
    STATE(170), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(67), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1753] = 5,
    ACTIONS(372), 1,
      anon_sym_LBRACK,
    ACTIONS(374), 1,
      sym_NUMBER,
    ACTIONS(376), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(197), 2,
      sym_DURATION,
      sym_duration_expansion,
  [1771] = 5,
    ACTIONS(372), 1,
      anon_sym_LBRACK,
    ACTIONS(374), 1,
      sym_NUMBER,
    ACTIONS(378), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(229), 2,
      sym_DURATION,
      sym_duration_expansion,
  [1789] = 6,
    ACTIONS(380), 1,
      sym_QUOTED_STRING,
    ACTIONS(382), 1,
      anon_sym_wrap,
    STATE(72), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(143), 1,
      sym_serial_dialog_parameter,
    STATE(170), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1809] = 5,
    ACTIONS(385), 1,
      anon_sym_RBRACE,
    ACTIONS(387), 1,
      anon_sym_wrap,
    STATE(170), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(73), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1827] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(392), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(390), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1841] = 4,
    ACTIONS(335), 1,
      anon_sym_LBRACK,
    STATE(218), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(394), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1857] = 5,
    ACTIONS(396), 1,
      anon_sym_RBRACE,
    ACTIONS(398), 1,
      sym_serial_dialog_option_type,
    STATE(76), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(157), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1874] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(401), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [1885] = 5,
    ACTIONS(403), 1,
      sym_duration_suffix,
    ACTIONS(405), 1,
      sym_distance_suffix,
    ACTIONS(407), 1,
      sym_quantity_suffix,
    ACTIONS(409), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1902] = 4,
    ACTIONS(411), 1,
      sym_QUOTED_STRING,
    STATE(79), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1917] = 5,
    ACTIONS(356), 1,
      sym_serial_dialog_option_type,
    ACTIONS(416), 1,
      anon_sym_RBRACE,
    STATE(76), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(157), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1934] = 4,
    ACTIONS(418), 1,
      anon_sym_LBRACK,
    STATE(219), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(420), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1949] = 3,
    ACTIONS(424), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(422), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1962] = 5,
    ACTIONS(374), 1,
      sym_NUMBER,
    ACTIONS(426), 1,
      anon_sym_RBRACK,
    ACTIONS(428), 1,
      sym_CONSTANT,
    STATE(159), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1979] = 5,
    ACTIONS(356), 1,
      sym_serial_dialog_option_type,
    ACTIONS(430), 1,
      anon_sym_RBRACE,
    STATE(76), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(157), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1996] = 3,
    ACTIONS(434), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(432), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [2009] = 4,
    ACTIONS(436), 1,
      anon_sym_LBRACK,
    STATE(217), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(438), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2024] = 4,
    ACTIONS(436), 1,
      anon_sym_LBRACK,
    STATE(227), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(440), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2039] = 3,
    ACTIONS(444), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(442), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2052] = 4,
    ACTIONS(448), 1,
      anon_sym_LBRACK,
    STATE(224), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(446), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2067] = 4,
    ACTIONS(436), 1,
      anon_sym_LBRACK,
    STATE(176), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(450), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2082] = 3,
    ACTIONS(452), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(422), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2095] = 5,
    ACTIONS(374), 1,
      sym_NUMBER,
    ACTIONS(428), 1,
      sym_CONSTANT,
    ACTIONS(454), 1,
      anon_sym_RBRACK,
    STATE(159), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2112] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(456), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2123] = 3,
    ACTIONS(403), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(458), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [2136] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(460), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2147] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(462), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2158] = 4,
    ACTIONS(464), 1,
      anon_sym_COMMA,
    ACTIONS(467), 1,
      anon_sym_RBRACK,
    STATE(97), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2172] = 4,
    ACTIONS(469), 1,
      anon_sym_COMMA,
    ACTIONS(471), 1,
      anon_sym_RBRACK,
    STATE(142), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2186] = 4,
    ACTIONS(473), 1,
      anon_sym_COMMA,
    ACTIONS(475), 1,
      anon_sym_RBRACK,
    STATE(120), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2200] = 4,
    ACTIONS(477), 1,
      anon_sym_COMMA,
    ACTIONS(479), 1,
      anon_sym_RBRACK,
    STATE(104), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2214] = 4,
    ACTIONS(424), 1,
      anon_sym_RBRACK,
    ACTIONS(481), 1,
      anon_sym_COMMA,
    STATE(122), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2228] = 4,
    ACTIONS(483), 1,
      anon_sym_COMMA,
    ACTIONS(485), 1,
      anon_sym_RBRACK,
    STATE(124), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2242] = 3,
    ACTIONS(487), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(489), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2254] = 4,
    ACTIONS(426), 1,
      anon_sym_RBRACK,
    ACTIONS(491), 1,
      anon_sym_COMMA,
    STATE(126), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2268] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(493), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2278] = 4,
    ACTIONS(495), 1,
      anon_sym_COMMA,
    ACTIONS(498), 1,
      anon_sym_RBRACK,
    STATE(106), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2292] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(500), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2302] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(502), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2312] = 4,
    ACTIONS(504), 1,
      anon_sym_COMMA,
    ACTIONS(506), 1,
      anon_sym_RBRACK,
    STATE(106), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2326] = 3,
    ACTIONS(506), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(489), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2338] = 4,
    ACTIONS(508), 1,
      sym_QUOTED_STRING,
    ACTIONS(510), 1,
      anon_sym_RBRACE,
    STATE(141), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2352] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(512), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [2362] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(514), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2372] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(516), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2382] = 4,
    ACTIONS(518), 1,
      anon_sym_COMMA,
    ACTIONS(520), 1,
      anon_sym_RBRACE,
    STATE(131), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2396] = 3,
    ACTIONS(522), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(524), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2408] = 4,
    ACTIONS(469), 1,
      anon_sym_COMMA,
    ACTIONS(526), 1,
      anon_sym_RBRACK,
    STATE(98), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2422] = 4,
    ACTIONS(374), 1,
      sym_NUMBER,
    ACTIONS(528), 1,
      sym_CONSTANT,
    STATE(100), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2436] = 3,
    ACTIONS(530), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(532), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2448] = 4,
    ACTIONS(530), 1,
      anon_sym_RBRACK,
    ACTIONS(534), 1,
      anon_sym_COMMA,
    STATE(133), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2462] = 4,
    ACTIONS(536), 1,
      anon_sym_COMMA,
    ACTIONS(538), 1,
      anon_sym_RBRACK,
    STATE(101), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2476] = 4,
    ACTIONS(540), 1,
      anon_sym_COMMA,
    ACTIONS(543), 1,
      anon_sym_RBRACK,
    STATE(122), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2490] = 3,
    ACTIONS(547), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2502] = 4,
    ACTIONS(547), 1,
      anon_sym_RBRACK,
    ACTIONS(549), 1,
      anon_sym_COMMA,
    STATE(97), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2516] = 4,
    ACTIONS(551), 1,
      anon_sym_COMMA,
    ACTIONS(553), 1,
      anon_sym_RBRACK,
    STATE(109), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2530] = 4,
    ACTIONS(555), 1,
      anon_sym_COMMA,
    ACTIONS(558), 1,
      anon_sym_RBRACK,
    STATE(126), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2544] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(560), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2554] = 3,
    ACTIONS(564), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(562), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2566] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(566), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2576] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(568), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2586] = 4,
    ACTIONS(570), 1,
      anon_sym_COMMA,
    ACTIONS(573), 1,
      anon_sym_RBRACE,
    STATE(131), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2600] = 3,
    ACTIONS(575), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(532), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2612] = 4,
    ACTIONS(577), 1,
      anon_sym_COMMA,
    ACTIONS(580), 1,
      anon_sym_RBRACK,
    STATE(133), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2626] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(422), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2636] = 3,
    ACTIONS(582), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2648] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(584), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [2658] = 4,
    ACTIONS(374), 1,
      sym_NUMBER,
    ACTIONS(428), 1,
      sym_CONSTANT,
    STATE(159), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2672] = 3,
    ACTIONS(586), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(588), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2684] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(590), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2694] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(592), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2704] = 4,
    ACTIONS(518), 1,
      anon_sym_COMMA,
    ACTIONS(594), 1,
      anon_sym_RBRACE,
    STATE(115), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2718] = 4,
    ACTIONS(596), 1,
      anon_sym_COMMA,
    ACTIONS(599), 1,
      anon_sym_RBRACK,
    STATE(142), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2732] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(601), 2,
      sym_QUOTED_STRING,
      anon_sym_wrap,
  [2741] = 3,
    ACTIONS(603), 1,
      anon_sym_LBRACE,
    STATE(29), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2752] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(605), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2761] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(489), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2770] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(498), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2779] = 3,
    ACTIONS(607), 1,
      anon_sym_serial_dialog,
    ACTIONS(609), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2790] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(611), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2799] = 3,
    ACTIONS(508), 1,
      sym_QUOTED_STRING,
    STATE(164), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2810] = 3,
    ACTIONS(613), 1,
      anon_sym_slot,
    ACTIONS(615), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2821] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(502), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2830] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(599), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2839] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(617), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2848] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(619), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2857] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(543), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2866] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(621), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2875] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(623), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2884] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(558), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2893] = 3,
    ACTIONS(625), 1,
      anon_sym_LBRACE,
    STATE(39), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2904] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(560), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2913] = 3,
    ACTIONS(627), 1,
      anon_sym_LBRACE,
    STATE(30), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2924] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(629), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [2933] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(573), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [2942] = 3,
    ACTIONS(170), 1,
      anon_sym_LBRACK,
    STATE(14), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2953] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(580), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2962] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(631), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2971] = 3,
    ACTIONS(633), 1,
      anon_sym_serial_dialog,
    ACTIONS(635), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2982] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(467), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2991] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(637), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3000] = 3,
    ACTIONS(625), 1,
      anon_sym_LBRACE,
    STATE(32), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3011] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(639), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3020] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(532), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3029] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(545), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3038] = 2,
    ACTIONS(641), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3046] = 2,
    ACTIONS(643), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3054] = 2,
    ACTIONS(645), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3062] = 2,
    ACTIONS(647), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3070] = 2,
    ACTIONS(649), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3078] = 2,
    ACTIONS(651), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3086] = 2,
    ACTIONS(653), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3094] = 2,
    ACTIONS(655), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3102] = 2,
    ACTIONS(657), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3110] = 2,
    ACTIONS(659), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3118] = 2,
    ACTIONS(661), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3126] = 2,
    ACTIONS(663), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3134] = 2,
    ACTIONS(665), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3142] = 2,
    ACTIONS(667), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3150] = 2,
    ACTIONS(669), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3158] = 2,
    ACTIONS(671), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3166] = 2,
    ACTIONS(673), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3174] = 2,
    ACTIONS(675), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3182] = 2,
    ACTIONS(677), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3190] = 2,
    ACTIONS(679), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3198] = 2,
    ACTIONS(681), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3206] = 2,
    ACTIONS(683), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3214] = 2,
    ACTIONS(685), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3222] = 2,
    ACTIONS(687), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3230] = 2,
    ACTIONS(689), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3238] = 2,
    ACTIONS(691), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3246] = 2,
    ACTIONS(693), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3254] = 2,
    ACTIONS(695), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3262] = 2,
    ACTIONS(697), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3270] = 2,
    ACTIONS(699), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3278] = 2,
    ACTIONS(701), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3286] = 2,
    ACTIONS(703), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3294] = 2,
    ACTIONS(705), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3302] = 2,
    ACTIONS(707), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3310] = 2,
    ACTIONS(709), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3318] = 2,
    ACTIONS(711), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3326] = 2,
    ACTIONS(713), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3334] = 2,
    ACTIONS(715), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3342] = 2,
    ACTIONS(717), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3350] = 2,
    ACTIONS(409), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3358] = 2,
    ACTIONS(719), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3366] = 2,
    ACTIONS(721), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3374] = 2,
    ACTIONS(723), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3382] = 2,
    ACTIONS(725), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3390] = 2,
    ACTIONS(727), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3398] = 2,
    ACTIONS(729), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3406] = 2,
    ACTIONS(731), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3414] = 2,
    ACTIONS(733), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3422] = 2,
    ACTIONS(735), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3430] = 2,
    ACTIONS(737), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3438] = 2,
    ACTIONS(739), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3446] = 2,
    ACTIONS(741), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3454] = 2,
    ACTIONS(743), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3462] = 2,
    ACTIONS(745), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3470] = 2,
    ACTIONS(747), 1,
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
  [SMALL_STATE(8)] = 354,
  [SMALL_STATE(9)] = 397,
  [SMALL_STATE(10)] = 421,
  [SMALL_STATE(11)] = 445,
  [SMALL_STATE(12)] = 469,
  [SMALL_STATE(13)] = 491,
  [SMALL_STATE(14)] = 513,
  [SMALL_STATE(15)] = 535,
  [SMALL_STATE(16)] = 569,
  [SMALL_STATE(17)] = 591,
  [SMALL_STATE(18)] = 625,
  [SMALL_STATE(19)] = 657,
  [SMALL_STATE(20)] = 679,
  [SMALL_STATE(21)] = 710,
  [SMALL_STATE(22)] = 741,
  [SMALL_STATE(23)] = 772,
  [SMALL_STATE(24)] = 803,
  [SMALL_STATE(25)] = 829,
  [SMALL_STATE(26)] = 854,
  [SMALL_STATE(27)] = 877,
  [SMALL_STATE(28)] = 900,
  [SMALL_STATE(29)] = 918,
  [SMALL_STATE(30)] = 936,
  [SMALL_STATE(31)] = 954,
  [SMALL_STATE(32)] = 972,
  [SMALL_STATE(33)] = 990,
  [SMALL_STATE(34)] = 1008,
  [SMALL_STATE(35)] = 1026,
  [SMALL_STATE(36)] = 1042,
  [SMALL_STATE(37)] = 1060,
  [SMALL_STATE(38)] = 1088,
  [SMALL_STATE(39)] = 1106,
  [SMALL_STATE(40)] = 1124,
  [SMALL_STATE(41)] = 1142,
  [SMALL_STATE(42)] = 1160,
  [SMALL_STATE(43)] = 1178,
  [SMALL_STATE(44)] = 1194,
  [SMALL_STATE(45)] = 1222,
  [SMALL_STATE(46)] = 1240,
  [SMALL_STATE(47)] = 1258,
  [SMALL_STATE(48)] = 1276,
  [SMALL_STATE(49)] = 1303,
  [SMALL_STATE(50)] = 1330,
  [SMALL_STATE(51)] = 1357,
  [SMALL_STATE(52)] = 1386,
  [SMALL_STATE(53)] = 1401,
  [SMALL_STATE(54)] = 1416,
  [SMALL_STATE(55)] = 1431,
  [SMALL_STATE(56)] = 1457,
  [SMALL_STATE(57)] = 1483,
  [SMALL_STATE(58)] = 1503,
  [SMALL_STATE(59)] = 1529,
  [SMALL_STATE(60)] = 1551,
  [SMALL_STATE(61)] = 1575,
  [SMALL_STATE(62)] = 1597,
  [SMALL_STATE(63)] = 1619,
  [SMALL_STATE(64)] = 1642,
  [SMALL_STATE(65)] = 1657,
  [SMALL_STATE(66)] = 1680,
  [SMALL_STATE(67)] = 1703,
  [SMALL_STATE(68)] = 1721,
  [SMALL_STATE(69)] = 1735,
  [SMALL_STATE(70)] = 1753,
  [SMALL_STATE(71)] = 1771,
  [SMALL_STATE(72)] = 1789,
  [SMALL_STATE(73)] = 1809,
  [SMALL_STATE(74)] = 1827,
  [SMALL_STATE(75)] = 1841,
  [SMALL_STATE(76)] = 1857,
  [SMALL_STATE(77)] = 1874,
  [SMALL_STATE(78)] = 1885,
  [SMALL_STATE(79)] = 1902,
  [SMALL_STATE(80)] = 1917,
  [SMALL_STATE(81)] = 1934,
  [SMALL_STATE(82)] = 1949,
  [SMALL_STATE(83)] = 1962,
  [SMALL_STATE(84)] = 1979,
  [SMALL_STATE(85)] = 1996,
  [SMALL_STATE(86)] = 2009,
  [SMALL_STATE(87)] = 2024,
  [SMALL_STATE(88)] = 2039,
  [SMALL_STATE(89)] = 2052,
  [SMALL_STATE(90)] = 2067,
  [SMALL_STATE(91)] = 2082,
  [SMALL_STATE(92)] = 2095,
  [SMALL_STATE(93)] = 2112,
  [SMALL_STATE(94)] = 2123,
  [SMALL_STATE(95)] = 2136,
  [SMALL_STATE(96)] = 2147,
  [SMALL_STATE(97)] = 2158,
  [SMALL_STATE(98)] = 2172,
  [SMALL_STATE(99)] = 2186,
  [SMALL_STATE(100)] = 2200,
  [SMALL_STATE(101)] = 2214,
  [SMALL_STATE(102)] = 2228,
  [SMALL_STATE(103)] = 2242,
  [SMALL_STATE(104)] = 2254,
  [SMALL_STATE(105)] = 2268,
  [SMALL_STATE(106)] = 2278,
  [SMALL_STATE(107)] = 2292,
  [SMALL_STATE(108)] = 2302,
  [SMALL_STATE(109)] = 2312,
  [SMALL_STATE(110)] = 2326,
  [SMALL_STATE(111)] = 2338,
  [SMALL_STATE(112)] = 2352,
  [SMALL_STATE(113)] = 2362,
  [SMALL_STATE(114)] = 2372,
  [SMALL_STATE(115)] = 2382,
  [SMALL_STATE(116)] = 2396,
  [SMALL_STATE(117)] = 2408,
  [SMALL_STATE(118)] = 2422,
  [SMALL_STATE(119)] = 2436,
  [SMALL_STATE(120)] = 2448,
  [SMALL_STATE(121)] = 2462,
  [SMALL_STATE(122)] = 2476,
  [SMALL_STATE(123)] = 2490,
  [SMALL_STATE(124)] = 2502,
  [SMALL_STATE(125)] = 2516,
  [SMALL_STATE(126)] = 2530,
  [SMALL_STATE(127)] = 2544,
  [SMALL_STATE(128)] = 2554,
  [SMALL_STATE(129)] = 2566,
  [SMALL_STATE(130)] = 2576,
  [SMALL_STATE(131)] = 2586,
  [SMALL_STATE(132)] = 2600,
  [SMALL_STATE(133)] = 2612,
  [SMALL_STATE(134)] = 2626,
  [SMALL_STATE(135)] = 2636,
  [SMALL_STATE(136)] = 2648,
  [SMALL_STATE(137)] = 2658,
  [SMALL_STATE(138)] = 2672,
  [SMALL_STATE(139)] = 2684,
  [SMALL_STATE(140)] = 2694,
  [SMALL_STATE(141)] = 2704,
  [SMALL_STATE(142)] = 2718,
  [SMALL_STATE(143)] = 2732,
  [SMALL_STATE(144)] = 2741,
  [SMALL_STATE(145)] = 2752,
  [SMALL_STATE(146)] = 2761,
  [SMALL_STATE(147)] = 2770,
  [SMALL_STATE(148)] = 2779,
  [SMALL_STATE(149)] = 2790,
  [SMALL_STATE(150)] = 2799,
  [SMALL_STATE(151)] = 2810,
  [SMALL_STATE(152)] = 2821,
  [SMALL_STATE(153)] = 2830,
  [SMALL_STATE(154)] = 2839,
  [SMALL_STATE(155)] = 2848,
  [SMALL_STATE(156)] = 2857,
  [SMALL_STATE(157)] = 2866,
  [SMALL_STATE(158)] = 2875,
  [SMALL_STATE(159)] = 2884,
  [SMALL_STATE(160)] = 2893,
  [SMALL_STATE(161)] = 2904,
  [SMALL_STATE(162)] = 2913,
  [SMALL_STATE(163)] = 2924,
  [SMALL_STATE(164)] = 2933,
  [SMALL_STATE(165)] = 2942,
  [SMALL_STATE(166)] = 2953,
  [SMALL_STATE(167)] = 2962,
  [SMALL_STATE(168)] = 2971,
  [SMALL_STATE(169)] = 2982,
  [SMALL_STATE(170)] = 2991,
  [SMALL_STATE(171)] = 3000,
  [SMALL_STATE(172)] = 3011,
  [SMALL_STATE(173)] = 3020,
  [SMALL_STATE(174)] = 3029,
  [SMALL_STATE(175)] = 3038,
  [SMALL_STATE(176)] = 3046,
  [SMALL_STATE(177)] = 3054,
  [SMALL_STATE(178)] = 3062,
  [SMALL_STATE(179)] = 3070,
  [SMALL_STATE(180)] = 3078,
  [SMALL_STATE(181)] = 3086,
  [SMALL_STATE(182)] = 3094,
  [SMALL_STATE(183)] = 3102,
  [SMALL_STATE(184)] = 3110,
  [SMALL_STATE(185)] = 3118,
  [SMALL_STATE(186)] = 3126,
  [SMALL_STATE(187)] = 3134,
  [SMALL_STATE(188)] = 3142,
  [SMALL_STATE(189)] = 3150,
  [SMALL_STATE(190)] = 3158,
  [SMALL_STATE(191)] = 3166,
  [SMALL_STATE(192)] = 3174,
  [SMALL_STATE(193)] = 3182,
  [SMALL_STATE(194)] = 3190,
  [SMALL_STATE(195)] = 3198,
  [SMALL_STATE(196)] = 3206,
  [SMALL_STATE(197)] = 3214,
  [SMALL_STATE(198)] = 3222,
  [SMALL_STATE(199)] = 3230,
  [SMALL_STATE(200)] = 3238,
  [SMALL_STATE(201)] = 3246,
  [SMALL_STATE(202)] = 3254,
  [SMALL_STATE(203)] = 3262,
  [SMALL_STATE(204)] = 3270,
  [SMALL_STATE(205)] = 3278,
  [SMALL_STATE(206)] = 3286,
  [SMALL_STATE(207)] = 3294,
  [SMALL_STATE(208)] = 3302,
  [SMALL_STATE(209)] = 3310,
  [SMALL_STATE(210)] = 3318,
  [SMALL_STATE(211)] = 3326,
  [SMALL_STATE(212)] = 3334,
  [SMALL_STATE(213)] = 3342,
  [SMALL_STATE(214)] = 3350,
  [SMALL_STATE(215)] = 3358,
  [SMALL_STATE(216)] = 3366,
  [SMALL_STATE(217)] = 3374,
  [SMALL_STATE(218)] = 3382,
  [SMALL_STATE(219)] = 3390,
  [SMALL_STATE(220)] = 3398,
  [SMALL_STATE(221)] = 3406,
  [SMALL_STATE(222)] = 3414,
  [SMALL_STATE(223)] = 3422,
  [SMALL_STATE(224)] = 3430,
  [SMALL_STATE(225)] = 3438,
  [SMALL_STATE(226)] = 3446,
  [SMALL_STATE(227)] = 3454,
  [SMALL_STATE(228)] = 3462,
  [SMALL_STATE(229)] = 3470,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(187),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(165),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(178),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(209),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(148),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(207),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(151),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(183),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(187),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(178),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(209),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(207),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(183),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(160),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(160),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(208),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [102] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(168),
  [105] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(113),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(158),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_definition, 2, 0, 6),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_definition, 2, 0, 6),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 35),
  [152] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 35), SHIFT_REPEAT(161),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 35), SHIFT_REPEAT(127),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(214),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 20),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 20),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 1, 0, 29),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 30),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 30),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 3, 0, 31),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 3, 0, 31),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 19),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 36),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 36),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 9),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 9),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [280] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(221),
  [283] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(149),
  [286] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 26),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 27),
  [301] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [305] = {.entry = {.count = 1, .reusable = false}}, SHIFT(154),
  [307] = {.entry = {.count = 1, .reusable = false}}, SHIFT(155),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [311] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 38),
  [313] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 38), SHIFT_REPEAT(64),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 38),
  [318] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 32), SHIFT_REPEAT(52),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 32),
  [323] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 32), SHIFT_REPEAT(154),
  [326] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 32), SHIFT_REPEAT(155),
  [329] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 39),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 39),
  [333] = {.entry = {.count = 1, .reusable = false}}, SHIFT(220),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [339] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [341] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [343] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 41),
  [345] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 41),
  [347] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 42),
  [349] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 42),
  [351] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 42), SHIFT_REPEAT(212),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 22),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [358] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 28),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 28),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 13),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [366] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 37),
  [368] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 37),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 21),
  [382] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 21), SHIFT_REPEAT(167),
  [385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [387] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(167),
  [390] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 48),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 48),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 34),
  [398] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 34), SHIFT_REPEAT(175),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 5, 0, 47),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [411] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 24), SHIFT_REPEAT(105),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 24),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 25),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 33),
  [432] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 14),
  [434] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 14),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [456] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 3, 0, 40),
  [458] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 44),
  [462] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 45),
  [464] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(174),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [489] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [493] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 11),
  [495] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(146),
  [498] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [500] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_entity, 1, 0, 0),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [512] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 19),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [516] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [536] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [538] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [540] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [555] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(137),
  [558] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [562] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [564] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [566] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [568] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [570] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(150),
  [573] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [577] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(173),
  [580] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [582] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [584] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 10),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [590] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [592] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [596] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [599] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [601] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 12),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [611] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_label, 1, 0, 0),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [619] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [621] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 23),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [629] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 43),
  [631] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter_int, 1, 0, 0),
  [633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [639] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 46),
  [641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [643] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 18),
  [645] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [649] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [651] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 10),
  [653] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [655] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [659] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [661] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [663] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [669] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [671] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [673] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [675] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [677] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [679] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 10),
  [681] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [683] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [685] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 8),
  [687] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [689] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [691] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [693] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
  [695] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [699] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [703] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [707] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [711] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [713] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [717] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [721] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [723] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 15),
  [725] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 16),
  [727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [729] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 7),
  [731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [735] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [737] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 17),
  [739] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [741] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [743] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 15),
  [745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [747] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 8),
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
