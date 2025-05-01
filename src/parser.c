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
#define STATE_COUNT 228
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 130
#define ALIAS_COUNT 0
#define TOKEN_COUNT 59
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 25
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 48

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
  sym_identifier_type = 34,
  anon_sym_GT = 35,
  sym_serial_dialog_option_type = 36,
  anon_sym_script = 37,
  anon_sym_json = 38,
  anon_sym_COLON = 39,
  sym_json_number = 40,
  anon_sym_true = 41,
  anon_sym_false = 42,
  anon_sym_null = 43,
  anon_sym_rand = 44,
  anon_sym_BANG = 45,
  anon_sym_LPAREN = 46,
  anon_sym_RPAREN = 47,
  sym_action_return_statement = 48,
  anon_sym_close = 49,
  anon_sym_save = 50,
  anon_sym_slot = 51,
  anon_sym_load = 52,
  anon_sym_erase = 53,
  anon_sym_map = 54,
  anon_sym_goto = 55,
  anon_sym_index = 56,
  anon_sym_wait = 57,
  anon_sym_block = 58,
  sym_document = 59,
  sym_bareword_expansion = 60,
  sym_quoted_string_expansion = 61,
  sym_string_expansion = 62,
  sym_number_expansion = 63,
  sym_DURATION = 64,
  sym_duration_expansion = 65,
  sym_DISTANCE = 66,
  sym_QUANTITY = 67,
  sym__root = 68,
  sym_include_macro = 69,
  sym_constant_assignment = 70,
  sym_add_serial_dialog_settings = 71,
  sym_serial_dialog_parameter_int = 72,
  sym_serial_dialog_parameter = 73,
  sym_add_dialog_settings = 74,
  sym_target_label = 75,
  sym_target_entity = 76,
  sym_add_dialog_settings_target = 77,
  sym__dialog_parameter_int = 78,
  sym__dialog_parameter_string = 79,
  sym_dialog_parameter = 80,
  sym_dialog_definition = 81,
  sym__dialog_block = 82,
  sym_dialog = 83,
  sym_dialog_identifier = 84,
  sym_dialog_option = 85,
  sym_serial_dialog_definition = 86,
  sym__serial_dialog_block = 87,
  sym_serial_dialog = 88,
  sym_serial_dialog_option = 89,
  sym_script_definition = 90,
  sym_script_block = 91,
  sym__script_item = 92,
  sym_json_literal = 93,
  sym_json_array = 94,
  sym_json_object = 95,
  sym_json_name_value_pair = 96,
  sym__json_item = 97,
  sym_rand_macro = 98,
  sym_label_definition = 99,
  sym__action_item = 100,
  sym_action_close_dialog = 101,
  sym_action_close_serial_dialog = 102,
  sym_action_save_slot = 103,
  sym_action_load_slot = 104,
  sym_action_erase_slot = 105,
  sym_action_load_map = 106,
  sym_action_run_script = 107,
  sym_action_goto_label = 108,
  sym_action_goto_index = 109,
  sym_action_non_blocking_delay = 110,
  sym_action_blocking_delay = 111,
  aux_sym_document_repeat1 = 112,
  aux_sym_bareword_expansion_repeat1 = 113,
  aux_sym_quoted_string_expansion_repeat1 = 114,
  aux_sym_string_expansion_repeat1 = 115,
  aux_sym_number_expansion_repeat1 = 116,
  aux_sym_duration_expansion_repeat1 = 117,
  aux_sym_add_serial_dialog_settings_repeat1 = 118,
  aux_sym_add_dialog_settings_repeat1 = 119,
  aux_sym_add_dialog_settings_target_repeat1 = 120,
  aux_sym__dialog_block_repeat1 = 121,
  aux_sym_dialog_repeat1 = 122,
  aux_sym_dialog_repeat2 = 123,
  aux_sym_serial_dialog_repeat1 = 124,
  aux_sym_serial_dialog_repeat2 = 125,
  aux_sym_serial_dialog_repeat3 = 126,
  aux_sym_script_block_repeat1 = 127,
  aux_sym_json_array_repeat1 = 128,
  aux_sym_json_object_repeat1 = 129,
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
  [sym_identifier_type] = "identifier_type",
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
  [sym_identifier_type] = sym_identifier_type,
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
  [sym_identifier_type] = {
    .visible = true,
    .named = true,
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
  field_dialog_identifier = 2,
  field_dialog_name = 3,
  field_dialog_option = 4,
  field_dialog_parameter = 5,
  field_duration = 6,
  field_fileName = 7,
  field_index = 8,
  field_label = 9,
  field_map = 10,
  field_message = 11,
  field_option_type = 12,
  field_property = 13,
  field_script = 14,
  field_script_name = 15,
  field_serial_dialog = 16,
  field_serial_dialog_name = 17,
  field_serial_dialog_option = 18,
  field_serial_dialog_parameter = 19,
  field_serial_message = 20,
  field_slot = 21,
  field_suffix = 22,
  field_target = 23,
  field_type = 24,
  field_value = 25,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_dialog] = "dialog",
  [field_dialog_identifier] = "dialog_identifier",
  [field_dialog_name] = "dialog_name",
  [field_dialog_option] = "dialog_option",
  [field_dialog_parameter] = "dialog_parameter",
  [field_duration] = "duration",
  [field_fileName] = "fileName",
  [field_index] = "index",
  [field_label] = "label",
  [field_map] = "map",
  [field_message] = "message",
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
  [26] = {.index = 33, .length = 2},
  [27] = {.index = 35, .length = 1},
  [28] = {.index = 36, .length = 1},
  [29] = {.index = 37, .length = 2},
  [30] = {.index = 39, .length = 1},
  [31] = {.index = 40, .length = 2},
  [32] = {.index = 42, .length = 3},
  [33] = {.index = 45, .length = 2},
  [34] = {.index = 47, .length = 2},
  [35] = {.index = 49, .length = 3},
  [36] = {.index = 52, .length = 1},
  [37] = {.index = 53, .length = 2},
  [38] = {.index = 55, .length = 3},
  [39] = {.index = 58, .length = 1},
  [40] = {.index = 59, .length = 4},
  [41] = {.index = 63, .length = 2},
  [42] = {.index = 65, .length = 2},
  [43] = {.index = 67, .length = 2},
  [44] = {.index = 69, .length = 2},
  [45] = {.index = 71, .length = 3},
  [46] = {.index = 74, .length = 3},
  [47] = {.index = 77, .length = 2},
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
    {field_type, 0},
    {field_value, 1},
  [35] =
    {field_message, 0},
  [36] =
    {field_dialog_parameter, 0},
  [37] =
    {field_dialog_identifier, 0},
    {field_message, 1, .inherited = true},
  [39] =
    {field_dialog, 1, .inherited = true},
  [40] =
    {field_dialog, 0, .inherited = true},
    {field_dialog, 1, .inherited = true},
  [42] =
    {field_serial_dialog_option, 2, .inherited = true},
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [45] =
    {field_serial_dialog_option, 0, .inherited = true},
    {field_serial_dialog_option, 1, .inherited = true},
  [47] =
    {field_dialog_parameter, 0, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
  [49] =
    {field_dialog_identifier, 0},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [52] =
    {field_dialog_option, 0},
  [53] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [55] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 2, .inherited = true},
    {field_message, 1, .inherited = true},
  [58] =
    {field_type, 0},
  [59] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 3, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [63] =
    {field_dialog_option, 0, .inherited = true},
    {field_dialog_option, 1, .inherited = true},
  [65] =
    {field_property, 0},
    {field_value, 2},
  [67] =
    {field_dialog_parameter, 2, .inherited = true},
    {field_type, 0},
  [69] =
    {field_target, 1},
    {field_type, 0},
  [71] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [74] =
    {field_dialog_parameter, 3, .inherited = true},
    {field_target, 1},
    {field_type, 0},
  [77] =
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(193);
      ADVANCE_MAP(
        '!', 376,
        '"', 6,
        '#', 363,
        '$', 189,
        '(', 377,
        ')', 378,
        ',', 324,
        '-', 12,
        '/', 8,
        ':', 368,
        ';', 340,
        '=', 341,
        '>', 361,
        'I', 116,
        '[', 323,
        ']', 325,
        '_', 362,
        'a', 41,
        'b', 98,
        'c', 99,
        'd', 61,
        'e', 113,
        'f', 15,
        'g', 133,
        'i', 117,
        'j', 154,
        'l', 17,
        'm', 19,
        'n', 20,
        'o', 118,
        'p', 81,
        'r', 30,
        's', 329,
        't', 79,
        'w', 26,
        'x', 331,
        'y', 69,
        '{', 347,
        '}', 348,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(191);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(327);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 6,
        '#', 186,
        '$', 189,
        '/', 8,
        'b', 266,
        'c', 272,
        'f', 211,
        'g', 300,
        'm', 208,
        'o', 246,
        'r', 241,
        't', 251,
        'w', 252,
        'y', 240,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(327);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 6,
        '$', 189,
        '/', 8,
        '>', 361,
        '[', 323,
        ']', 325,
        'e', 283,
        'n', 202,
        '}', 348,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(189);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '[') ADVANCE(323);
      if (lookahead == 'i') ADVANCE(284);
      if (lookahead == 'l') ADVANCE(203);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 6,
        ',', 324,
        '-', 12,
        '/', 8,
        ';', 340,
        'I', 116,
        '[', 323,
        ']', 325,
        'a', 97,
        'b', 128,
        'd', 60,
        'e', 112,
        'f', 15,
        'l', 16,
        'm', 152,
        'n', 20,
        'p', 81,
        's', 328,
        't', 142,
        'w', 147,
        'x', 331,
        '{', 347,
        '}', 348,
        '#', 362,
        '_', 362,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(370);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '"', 6,
        ',', 324,
        '-', 12,
        '/', 8,
        ';', 340,
        'I', 116,
        '[', 323,
        ']', 325,
        'a', 97,
        'b', 128,
        'd', 60,
        'e', 112,
        'f', 15,
        'l', 16,
        'n', 20,
        'p', 132,
        't', 142,
        'w', 147,
        '{', 347,
        '}', 348,
        '#', 362,
        '_', 362,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(370);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(326);
      if (lookahead == '\\') ADVANCE(190);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        ')', 378,
        ',', 324,
        '/', 8,
        ']', 325,
        'b', 268,
        'c', 269,
        'e', 299,
        'g', 290,
        'j', 304,
        'l', 293,
        'r', 204,
        's', 201,
        'w', 205,
        '}', 348,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(195);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(194);
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
      if (lookahead == 'd') ADVANCE(92);
      if (lookahead == 'm') ADVANCE(29);
      if (lookahead == 's') ADVANCE(49);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == 'I') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(370);
      END_STATE();
    case 13:
      if (lookahead == '_') ADVANCE(48);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(171);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(111);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(78);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(78);
      if (lookahead == 's') ADVANCE(328);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(114);
      if (lookahead == 'u') ADVANCE(104);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(180);
      if (lookahead == 'c') ADVANCE(148);
      if (lookahead == 'e') ADVANCE(149);
      if (lookahead == 'l') ADVANCE(137);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(333);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(140);
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
      if (lookahead == 'a') ADVANCE(105);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(177);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(139);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(123);
      if (lookahead == 'e') ADVANCE(43);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(119);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(102);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(156);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(107);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 36:
      if (lookahead == 'b') ADVANCE(65);
      END_STATE();
    case 37:
      if (lookahead == 'c') ADVANCE(95);
      END_STATE();
    case 38:
      if (lookahead == 'c') ADVANCE(96);
      END_STATE();
    case 39:
      if (lookahead == 'c') ADVANCE(103);
      if (lookahead == 'd') ADVANCE(62);
      END_STATE();
    case 40:
      if (lookahead == 'c') ADVANCE(52);
      END_STATE();
    case 41:
      if (lookahead == 'd') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 42:
      if (lookahead == 'd') ADVANCE(342);
      END_STATE();
    case 43:
      if (lookahead == 'd') ADVANCE(333);
      if (lookahead == 't') ADVANCE(176);
      END_STATE();
    case 44:
      if (lookahead == 'd') ADVANCE(386);
      END_STATE();
    case 45:
      if (lookahead == 'd') ADVANCE(374);
      END_STATE();
    case 46:
      if (lookahead == 'd') ADVANCE(66);
      END_STATE();
    case 47:
      if (lookahead == 'd') ADVANCE(59);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(94);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(149);
      if (lookahead == 'l') ADVANCE(137);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(333);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(357);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(332);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(383);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(371);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(381);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(356);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(388);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(372);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(338);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(73);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(73);
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(183);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(119);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(101);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(124);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(166);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(110);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(125);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(158);
      END_STATE();
    case 72:
      if (lookahead == 'f') ADVANCE(85);
      END_STATE();
    case 73:
      if (lookahead == 'f') ADVANCE(28);
      END_STATE();
    case 74:
      if (lookahead == 'g') ADVANCE(350);
      END_STATE();
    case 75:
      if (lookahead == 'g') ADVANCE(344);
      END_STATE();
    case 76:
      if (lookahead == 'g') ADVANCE(153);
      END_STATE();
    case 77:
      if (lookahead == 'g') ADVANCE(126);
      END_STATE();
    case 78:
      if (lookahead == 'g') ADVANCE(67);
      if (lookahead == 'p') ADVANCE(390);
      END_STATE();
    case 79:
      if (lookahead == 'h') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(178);
      if (lookahead == 'w') ADVANCE(80);
      END_STATE();
    case 80:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 81:
      if (lookahead == 'i') ADVANCE(182);
      if (lookahead == 'o') ADVANCE(146);
      if (lookahead == 'x') ADVANCE(330);
      END_STATE();
    case 82:
      if (lookahead == 'i') ADVANCE(77);
      END_STATE();
    case 83:
      if (lookahead == 'i') ADVANCE(141);
      END_STATE();
    case 84:
      if (lookahead == 'i') ADVANCE(160);
      END_STATE();
    case 85:
      if (lookahead == 'i') ADVANCE(127);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(168);
      END_STATE();
    case 87:
      if (lookahead == 'i') ADVANCE(161);
      END_STATE();
    case 88:
      if (lookahead == 'i') ADVANCE(109);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(122);
      END_STATE();
    case 90:
      if (lookahead == 'i') ADVANCE(167);
      END_STATE();
    case 91:
      if (lookahead == 'i') ADVANCE(164);
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
      if (lookahead == 'k') ADVANCE(333);
      END_STATE();
    case 96:
      if (lookahead == 'k') ADVANCE(397);
      END_STATE();
    case 97:
      if (lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 98:
      if (lookahead == 'l') ADVANCE(24);
      if (lookahead == 'o') ADVANCE(144);
      END_STATE();
    case 99:
      if (lookahead == 'l') ADVANCE(131);
      if (lookahead == 'y') ADVANCE(31);
      END_STATE();
    case 100:
      if (lookahead == 'l') ADVANCE(373);
      END_STATE();
    case 101:
      if (lookahead == 'l') ADVANCE(353);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 103:
      if (lookahead == 'l') ADVANCE(179);
      END_STATE();
    case 104:
      if (lookahead == 'l') ADVANCE(100);
      END_STATE();
    case 105:
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 106:
      if (lookahead == 'l') ADVANCE(130);
      END_STATE();
    case 107:
      if (lookahead == 'l') ADVANCE(136);
      END_STATE();
    case 108:
      if (lookahead == 'l') ADVANCE(163);
      END_STATE();
    case 109:
      if (lookahead == 'l') ADVANCE(71);
      END_STATE();
    case 110:
      if (lookahead == 'l') ADVANCE(106);
      END_STATE();
    case 111:
      if (lookahead == 'l') ADVANCE(157);
      END_STATE();
    case 112:
      if (lookahead == 'm') ADVANCE(135);
      if (lookahead == 'n') ADVANCE(175);
      END_STATE();
    case 113:
      if (lookahead == 'm') ADVANCE(135);
      if (lookahead == 'n') ADVANCE(175);
      if (lookahead == 'r') ADVANCE(33);
      END_STATE();
    case 114:
      if (lookahead == 'm') ADVANCE(51);
      END_STATE();
    case 115:
      if (lookahead == 'm') ADVANCE(70);
      END_STATE();
    case 116:
      if (lookahead == 'n') ADVANCE(72);
      END_STATE();
    case 117:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 119:
      if (lookahead == 'n') ADVANCE(333);
      END_STATE();
    case 120:
      if (lookahead == 'n') ADVANCE(366);
      END_STATE();
    case 121:
      if (lookahead == 'n') ADVANCE(379);
      END_STATE();
    case 122:
      if (lookahead == 'n') ADVANCE(76);
      END_STATE();
    case 123:
      if (lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 124:
      if (lookahead == 'n') ADVANCE(172);
      END_STATE();
    case 125:
      if (lookahead == 'n') ADVANCE(165);
      END_STATE();
    case 126:
      if (lookahead == 'n') ADVANCE(115);
      END_STATE();
    case 127:
      if (lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 128:
      if (lookahead == 'o') ADVANCE(144);
      END_STATE();
    case 129:
      if (lookahead == 'o') ADVANCE(391);
      END_STATE();
    case 130:
      if (lookahead == 'o') ADVANCE(181);
      END_STATE();
    case 131:
      if (lookahead == 'o') ADVANCE(155);
      END_STATE();
    case 132:
      if (lookahead == 'o') ADVANCE(146);
      END_STATE();
    case 133:
      if (lookahead == 'o') ADVANCE(170);
      if (lookahead == 'r') ADVANCE(63);
      END_STATE();
    case 134:
      if (lookahead == 'o') ADVANCE(74);
      END_STATE();
    case 135:
      if (lookahead == 'o') ADVANCE(173);
      END_STATE();
    case 136:
      if (lookahead == 'o') ADVANCE(75);
      END_STATE();
    case 137:
      if (lookahead == 'o') ADVANCE(159);
      END_STATE();
    case 138:
      if (lookahead == 'o') ADVANCE(120);
      END_STATE();
    case 139:
      if (lookahead == 'p') ADVANCE(390);
      END_STATE();
    case 140:
      if (lookahead == 'p') ADVANCE(349);
      END_STATE();
    case 141:
      if (lookahead == 'p') ADVANCE(162);
      END_STATE();
    case 142:
      if (lookahead == 'r') ADVANCE(178);
      END_STATE();
    case 143:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 144:
      if (lookahead == 'r') ADVANCE(46);
      END_STATE();
    case 145:
      if (lookahead == 'r') ADVANCE(80);
      END_STATE();
    case 146:
      if (lookahead == 'r') ADVANCE(169);
      END_STATE();
    case 147:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 148:
      if (lookahead == 'r') ADVANCE(83);
      END_STATE();
    case 149:
      if (lookahead == 'r') ADVANCE(93);
      if (lookahead == 't') ADVANCE(174);
      END_STATE();
    case 150:
      if (lookahead == 'r') ADVANCE(35);
      END_STATE();
    case 151:
      if (lookahead == 'r') ADVANCE(121);
      END_STATE();
    case 152:
      if (lookahead == 's') ADVANCE(328);
      END_STATE();
    case 153:
      if (lookahead == 's') ADVANCE(346);
      END_STATE();
    case 154:
      if (lookahead == 's') ADVANCE(138);
      END_STATE();
    case 155:
      if (lookahead == 's') ADVANCE(55);
      END_STATE();
    case 156:
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 157:
      if (lookahead == 's') ADVANCE(58);
      END_STATE();
    case 158:
      if (lookahead == 's') ADVANCE(68);
      END_STATE();
    case 159:
      if (lookahead == 't') ADVANCE(385);
      END_STATE();
    case 160:
      if (lookahead == 't') ADVANCE(395);
      END_STATE();
    case 161:
      if (lookahead == 't') ADVANCE(184);
      END_STATE();
    case 162:
      if (lookahead == 't') ADVANCE(364);
      END_STATE();
    case 163:
      if (lookahead == 't') ADVANCE(352);
      END_STATE();
    case 164:
      if (lookahead == 't') ADVANCE(358);
      END_STATE();
    case 165:
      if (lookahead == 't') ADVANCE(359);
      END_STATE();
    case 166:
      if (lookahead == 't') ADVANCE(360);
      END_STATE();
    case 167:
      if (lookahead == 't') ADVANCE(185);
      END_STATE();
    case 168:
      if (lookahead == 't') ADVANCE(50);
      END_STATE();
    case 169:
      if (lookahead == 't') ADVANCE(150);
      END_STATE();
    case 170:
      if (lookahead == 't') ADVANCE(129);
      END_STATE();
    case 171:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 172:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 173:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 174:
      if (lookahead == 't') ADVANCE(89);
      END_STATE();
    case 175:
      if (lookahead == 't') ADVANCE(87);
      END_STATE();
    case 176:
      if (lookahead == 'u') ADVANCE(151);
      END_STATE();
    case 177:
      if (lookahead == 'u') ADVANCE(108);
      END_STATE();
    case 178:
      if (lookahead == 'u') ADVANCE(54);
      END_STATE();
    case 179:
      if (lookahead == 'u') ADVANCE(47);
      END_STATE();
    case 180:
      if (lookahead == 'v') ADVANCE(53);
      END_STATE();
    case 181:
      if (lookahead == 'w') ADVANCE(333);
      END_STATE();
    case 182:
      if (lookahead == 'x') ADVANCE(330);
      END_STATE();
    case 183:
      if (lookahead == 'x') ADVANCE(393);
      END_STATE();
    case 184:
      if (lookahead == 'y') ADVANCE(355);
      END_STATE();
    case 185:
      if (lookahead == 'y') ADVANCE(369);
      END_STATE();
    case 186:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(188);
      END_STATE();
    case 187:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(336);
      END_STATE();
    case 188:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(187);
      END_STATE();
    case 189:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(337);
      END_STATE();
    case 190:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 191:
      if (eof) ADVANCE(193);
      ADVANCE_MAP(
        '!', 376,
        '"', 6,
        '#', 363,
        '$', 189,
        '(', 377,
        ')', 378,
        ',', 324,
        '-', 12,
        '/', 8,
        ':', 368,
        ';', 340,
        '=', 341,
        '>', 361,
        'I', 116,
        '[', 323,
        ']', 325,
        '_', 362,
        'a', 41,
        'b', 98,
        'c', 99,
        'd', 61,
        'e', 113,
        'f', 15,
        'g', 133,
        'i', 117,
        'j', 154,
        'l', 17,
        'm', 18,
        'n', 20,
        'o', 118,
        'p', 132,
        'r', 30,
        's', 21,
        't', 79,
        'w', 26,
        'y', 69,
        '{', 347,
        '}', 348,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(191);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(327);
      END_STATE();
    case 192:
      if (eof) ADVANCE(193);
      ADVANCE_MAP(
        '"', 6,
        '$', 189,
        '/', 8,
        '[', 323,
        ']', 325,
        'a', 226,
        'd', 253,
        'i', 277,
        's', 215,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(192);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(327);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(195);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(281);
      if (lookahead == 'e') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(218);
      if (lookahead == 'u') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(274);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(296);
      if (lookahead == 'e') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(343);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(375);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(332);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(339);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(384);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(382);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(389);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(247);
      if (lookahead == 'n') ADVANCE(196);
      if (lookahead == 'p') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(297);
      if (lookahead == 'r') ADVANCE(317);
      if (lookahead == 'w') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(398);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(354);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(294);
      if (lookahead == 'y') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(367);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(314);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(392);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(319);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(278);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(327);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(180);
      if (lookahead == 'c') ADVANCE(148);
      if (lookahead == 'e') ADVANCE(149);
      if (lookahead == 'l') ADVANCE(137);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(333);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(334);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(335);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(337);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_target_default);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(188);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(370);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_action_return_statement);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_action_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(322);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 192},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 7},
  [5] = {.lex_state = 7},
  [6] = {.lex_state = 7},
  [7] = {.lex_state = 192},
  [8] = {.lex_state = 192},
  [9] = {.lex_state = 7},
  [10] = {.lex_state = 7},
  [11] = {.lex_state = 7},
  [12] = {.lex_state = 7},
  [13] = {.lex_state = 7},
  [14] = {.lex_state = 7},
  [15] = {.lex_state = 4},
  [16] = {.lex_state = 4},
  [17] = {.lex_state = 7},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 7},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 4},
  [22] = {.lex_state = 4},
  [23] = {.lex_state = 4},
  [24] = {.lex_state = 4},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 4},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 192},
  [29] = {.lex_state = 192},
  [30] = {.lex_state = 192},
  [31] = {.lex_state = 192},
  [32] = {.lex_state = 192},
  [33] = {.lex_state = 192},
  [34] = {.lex_state = 192},
  [35] = {.lex_state = 192},
  [36] = {.lex_state = 192},
  [37] = {.lex_state = 192},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 192},
  [40] = {.lex_state = 192},
  [41] = {.lex_state = 192},
  [42] = {.lex_state = 192},
  [43] = {.lex_state = 192},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 192},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 4},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 3},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 4},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 2},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 192},
  [66] = {.lex_state = 192},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 192},
  [74] = {.lex_state = 4},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 192},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 192},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 4},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 192},
  [88] = {.lex_state = 4},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 192},
  [91] = {.lex_state = 4},
  [92] = {.lex_state = 4},
  [93] = {.lex_state = 4},
  [94] = {.lex_state = 4},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 192},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 2},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 4},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 192},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 192},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 2},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 2},
  [128] = {.lex_state = 2},
  [129] = {.lex_state = 2},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 192},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 2},
  [135] = {.lex_state = 2},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 192},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 2},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 2},
  [144] = {.lex_state = 192},
  [145] = {.lex_state = 2},
  [146] = {.lex_state = 11},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 2},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 11},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 192},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 192},
  [157] = {.lex_state = 2},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 11},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 4},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 2},
  [168] = {.lex_state = 4},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 192},
  [171] = {.lex_state = 2},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 11},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 11},
  [191] = {.lex_state = 11},
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
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 0},
  [211] = {.lex_state = 0},
  [212] = {.lex_state = 11},
  [213] = {.lex_state = 0},
  [214] = {.lex_state = 0},
  [215] = {.lex_state = 0},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 0},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
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
    [sym_identifier_type] = ACTIONS(1),
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
    [sym_document] = STATE(215),
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
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(60), 1,
      anon_sym_json,
    ACTIONS(62), 1,
      anon_sym_rand,
    ACTIONS(64), 1,
      anon_sym_RPAREN,
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
    STATE(6), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
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
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(60), 1,
      anon_sym_json,
    ACTIONS(62), 1,
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
    STATE(5), 5,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
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
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(60), 1,
      anon_sym_json,
    ACTIONS(62), 1,
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
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(60), 1,
      anon_sym_json,
    ACTIONS(62), 1,
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
    STATE(16), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(44), 1,
      sym_dialog_parameter,
    STATE(46), 1,
      aux_sym_dialog_repeat1,
    STATE(106), 1,
      sym__dialog_parameter_string,
    STATE(144), 1,
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
  [569] = 9,
    ACTIONS(140), 1,
      sym_QUOTED_STRING,
    STATE(18), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(44), 1,
      sym_dialog_parameter,
    STATE(53), 1,
      aux_sym_dialog_repeat1,
    STATE(106), 1,
      sym__dialog_parameter_string,
    STATE(144), 1,
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
  [603] = 3,
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
  [625] = 8,
    STATE(18), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(44), 1,
      sym_dialog_parameter,
    STATE(106), 1,
      sym__dialog_parameter_string,
    STATE(144), 1,
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
    STATE(18), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(44), 1,
      sym_dialog_parameter,
    STATE(106), 1,
      sym__dialog_parameter_string,
    STATE(144), 1,
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
    STATE(20), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(44), 1,
      sym_dialog_parameter,
    STATE(106), 1,
      sym__dialog_parameter_string,
    STATE(144), 1,
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
    STATE(44), 1,
      sym_dialog_parameter,
    STATE(106), 1,
      sym__dialog_parameter_string,
    STATE(144), 1,
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
    STATE(44), 1,
      sym_dialog_parameter,
    STATE(106), 1,
      sym__dialog_parameter_string,
    STATE(144), 1,
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
    STATE(139), 3,
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
    STATE(182), 3,
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
    STATE(154), 3,
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
    STATE(165), 3,
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
  [1026] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(218), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(220), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1044] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(222), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(224), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1062] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(226), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(228), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1080] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(230), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1096] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(232), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(234), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1114] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(236), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(238), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1132] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(240), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(242), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1150] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(244), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(246), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1168] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(248), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(250), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1186] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(252), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1202] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(254), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(256), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1220] = 8,
    ACTIONS(140), 1,
      sym_QUOTED_STRING,
    ACTIONS(260), 1,
      sym_identifier_type,
    ACTIONS(262), 1,
      anon_sym_GT,
    STATE(60), 1,
      aux_sym_dialog_repeat1,
    STATE(61), 1,
      aux_sym_dialog_repeat2,
    STATE(89), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(258), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1247] = 9,
    ACTIONS(264), 1,
      sym_QUOTED_STRING,
    ACTIONS(266), 1,
      anon_sym_RBRACE,
    ACTIONS(268), 1,
      anon_sym_wrap,
    STATE(56), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(57), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(156), 1,
      sym_serial_dialog_parameter_int,
    STATE(159), 1,
      sym_serial_dialog_parameter,
    STATE(219), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1276] = 8,
    ACTIONS(270), 1,
      anon_sym_RBRACE,
    ACTIONS(272), 1,
      sym_target_default,
    ACTIONS(274), 1,
      anon_sym_label,
    ACTIONS(276), 1,
      anon_sym_entity,
    STATE(103), 1,
      sym_target_entity,
    STATE(145), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(50), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1303] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(278), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1318] = 8,
    ACTIONS(272), 1,
      sym_target_default,
    ACTIONS(274), 1,
      anon_sym_label,
    ACTIONS(276), 1,
      anon_sym_entity,
    ACTIONS(280), 1,
      anon_sym_RBRACE,
    STATE(103), 1,
      sym_target_entity,
    STATE(145), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(52), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1345] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(282), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1360] = 8,
    ACTIONS(284), 1,
      anon_sym_RBRACE,
    ACTIONS(286), 1,
      sym_target_default,
    ACTIONS(289), 1,
      anon_sym_label,
    ACTIONS(292), 1,
      anon_sym_entity,
    STATE(103), 1,
      sym_target_entity,
    STATE(145), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(52), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1387] = 8,
    ACTIONS(140), 1,
      sym_QUOTED_STRING,
    ACTIONS(262), 1,
      anon_sym_GT,
    ACTIONS(297), 1,
      sym_identifier_type,
    STATE(60), 1,
      aux_sym_dialog_repeat1,
    STATE(63), 1,
      aux_sym_dialog_repeat2,
    STATE(89), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(295), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1414] = 7,
    ACTIONS(299), 1,
      sym_BAREWORD,
    ACTIONS(301), 1,
      anon_sym_LBRACK,
    ACTIONS(305), 1,
      anon_sym_label,
    ACTIONS(307), 1,
      anon_sym_index,
    STATE(220), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(303), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1438] = 7,
    ACTIONS(309), 1,
      sym_BAREWORD,
    ACTIONS(312), 1,
      anon_sym_RBRACE,
    ACTIONS(314), 1,
      sym_identifier_type,
    STATE(15), 1,
      sym_dialog_identifier,
    STATE(55), 1,
      aux_sym__dialog_block_repeat1,
    STATE(127), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1461] = 7,
    ACTIONS(264), 1,
      sym_QUOTED_STRING,
    ACTIONS(268), 1,
      anon_sym_wrap,
    STATE(59), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(71), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(156), 1,
      sym_serial_dialog_parameter_int,
    STATE(159), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1484] = 7,
    ACTIONS(264), 1,
      sym_QUOTED_STRING,
    ACTIONS(317), 1,
      anon_sym_RBRACE,
    ACTIONS(319), 1,
      sym_serial_dialog_option_type,
    STATE(74), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(91), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(164), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1507] = 7,
    ACTIONS(321), 1,
      sym_BAREWORD,
    ACTIONS(323), 1,
      anon_sym_RBRACE,
    ACTIONS(325), 1,
      sym_identifier_type,
    STATE(15), 1,
      sym_dialog_identifier,
    STATE(55), 1,
      aux_sym__dialog_block_repeat1,
    STATE(127), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1530] = 7,
    ACTIONS(264), 1,
      sym_QUOTED_STRING,
    ACTIONS(319), 1,
      sym_serial_dialog_option_type,
    ACTIONS(327), 1,
      anon_sym_RBRACE,
    STATE(83), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(91), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(164), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1553] = 5,
    ACTIONS(331), 1,
      sym_QUOTED_STRING,
    ACTIONS(334), 1,
      sym_identifier_type,
    STATE(60), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(329), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [1572] = 6,
    ACTIONS(262), 1,
      anon_sym_GT,
    ACTIONS(338), 1,
      sym_identifier_type,
    STATE(64), 1,
      aux_sym_dialog_repeat2,
    STATE(89), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(336), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1593] = 7,
    ACTIONS(321), 1,
      sym_BAREWORD,
    ACTIONS(325), 1,
      sym_identifier_type,
    ACTIONS(340), 1,
      anon_sym_RBRACE,
    STATE(15), 1,
      sym_dialog_identifier,
    STATE(58), 1,
      aux_sym__dialog_block_repeat1,
    STATE(127), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1616] = 6,
    ACTIONS(262), 1,
      anon_sym_GT,
    ACTIONS(344), 1,
      sym_identifier_type,
    STATE(64), 1,
      aux_sym_dialog_repeat2,
    STATE(89), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(342), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1637] = 6,
    ACTIONS(348), 1,
      sym_identifier_type,
    ACTIONS(350), 1,
      anon_sym_GT,
    STATE(64), 1,
      aux_sym_dialog_repeat2,
    STATE(89), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(346), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1658] = 5,
    ACTIONS(353), 1,
      anon_sym_LBRACK,
    ACTIONS(355), 1,
      sym_NUMBER,
    ACTIONS(357), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(179), 2,
      sym_DURATION,
      sym_duration_expansion,
  [1676] = 5,
    ACTIONS(353), 1,
      anon_sym_LBRACK,
    ACTIONS(355), 1,
      sym_NUMBER,
    ACTIONS(359), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(175), 2,
      sym_DURATION,
      sym_duration_expansion,
  [1694] = 3,
    ACTIONS(363), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(361), 4,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [1708] = 5,
    ACTIONS(365), 1,
      anon_sym_RBRACE,
    ACTIONS(367), 1,
      anon_sym_wrap,
    STATE(156), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(68), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1726] = 4,
    ACTIONS(301), 1,
      anon_sym_LBRACK,
    STATE(185), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(370), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1742] = 5,
    ACTIONS(268), 1,
      anon_sym_wrap,
    ACTIONS(372), 1,
      anon_sym_RBRACE,
    STATE(156), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(72), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1760] = 6,
    ACTIONS(374), 1,
      sym_QUOTED_STRING,
    ACTIONS(376), 1,
      anon_sym_wrap,
    STATE(71), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(156), 1,
      sym_serial_dialog_parameter_int,
    STATE(159), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1780] = 5,
    ACTIONS(268), 1,
      anon_sym_wrap,
    ACTIONS(379), 1,
      anon_sym_RBRACE,
    STATE(156), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(68), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1798] = 4,
    ACTIONS(381), 1,
      anon_sym_LBRACK,
    STATE(226), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(383), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1813] = 5,
    ACTIONS(319), 1,
      sym_serial_dialog_option_type,
    ACTIONS(385), 1,
      anon_sym_RBRACE,
    STATE(85), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(164), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1830] = 4,
    ACTIONS(389), 1,
      anon_sym_LBRACK,
    STATE(207), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(387), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1845] = 4,
    ACTIONS(381), 1,
      anon_sym_LBRACK,
    STATE(197), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(391), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1860] = 3,
    ACTIONS(395), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(393), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1873] = 4,
    ACTIONS(397), 1,
      anon_sym_LBRACK,
    STATE(193), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(399), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1888] = 5,
    ACTIONS(355), 1,
      sym_NUMBER,
    ACTIONS(401), 1,
      anon_sym_RBRACK,
    ACTIONS(403), 1,
      sym_CONSTANT,
    STATE(147), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1905] = 5,
    ACTIONS(405), 1,
      sym_duration_suffix,
    ACTIONS(407), 1,
      sym_distance_suffix,
    ACTIONS(409), 1,
      sym_quantity_suffix,
    ACTIONS(411), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1922] = 3,
    ACTIONS(415), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(413), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [1935] = 3,
    ACTIONS(405), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(417), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [1948] = 5,
    ACTIONS(319), 1,
      sym_serial_dialog_option_type,
    ACTIONS(419), 1,
      anon_sym_RBRACE,
    STATE(85), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(164), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1965] = 3,
    ACTIONS(423), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(421), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1978] = 5,
    ACTIONS(425), 1,
      anon_sym_RBRACE,
    ACTIONS(427), 1,
      sym_serial_dialog_option_type,
    STATE(85), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(164), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1995] = 3,
    ACTIONS(430), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(393), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2008] = 5,
    ACTIONS(355), 1,
      sym_NUMBER,
    ACTIONS(403), 1,
      sym_CONSTANT,
    ACTIONS(432), 1,
      anon_sym_RBRACK,
    STATE(147), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2025] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(434), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2036] = 3,
    ACTIONS(438), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(436), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2049] = 4,
    ACTIONS(381), 1,
      anon_sym_LBRACK,
    STATE(209), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(440), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2064] = 4,
    ACTIONS(442), 1,
      sym_QUOTED_STRING,
    STATE(91), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(445), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2079] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(447), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2090] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(449), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2101] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(451), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2112] = 4,
    ACTIONS(453), 1,
      anon_sym_COMMA,
    ACTIONS(455), 1,
      anon_sym_RBRACK,
    STATE(125), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2126] = 4,
    ACTIONS(457), 1,
      anon_sym_COMMA,
    ACTIONS(459), 1,
      anon_sym_RBRACK,
    STATE(113), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2140] = 3,
    ACTIONS(463), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(461), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2152] = 4,
    ACTIONS(465), 1,
      anon_sym_COMMA,
    ACTIONS(467), 1,
      anon_sym_RBRACK,
    STATE(115), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2166] = 3,
    ACTIONS(469), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(471), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2178] = 4,
    ACTIONS(473), 1,
      anon_sym_COMMA,
    ACTIONS(476), 1,
      anon_sym_RBRACK,
    STATE(100), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2192] = 4,
    ACTIONS(355), 1,
      sym_NUMBER,
    ACTIONS(478), 1,
      sym_CONSTANT,
    STATE(98), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2206] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(480), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2216] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(482), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2226] = 3,
    ACTIONS(484), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(486), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2238] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(488), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [2248] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(490), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2258] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(492), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [2268] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(494), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2278] = 4,
    ACTIONS(496), 1,
      anon_sym_COMMA,
    ACTIONS(498), 1,
      anon_sym_RBRACE,
    STATE(119), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2292] = 3,
    ACTIONS(500), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(471), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2304] = 4,
    ACTIONS(502), 1,
      anon_sym_COMMA,
    ACTIONS(504), 1,
      anon_sym_RBRACK,
    STATE(120), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2318] = 4,
    ACTIONS(506), 1,
      anon_sym_COMMA,
    ACTIONS(508), 1,
      anon_sym_RBRACK,
    STATE(122), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2332] = 4,
    ACTIONS(395), 1,
      anon_sym_RBRACK,
    ACTIONS(510), 1,
      anon_sym_COMMA,
    STATE(123), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2346] = 4,
    ACTIONS(500), 1,
      anon_sym_RBRACK,
    ACTIONS(512), 1,
      anon_sym_COMMA,
    STATE(100), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2360] = 4,
    ACTIONS(401), 1,
      anon_sym_RBRACK,
    ACTIONS(514), 1,
      anon_sym_COMMA,
    STATE(126), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2374] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(516), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2384] = 4,
    ACTIONS(518), 1,
      anon_sym_COMMA,
    ACTIONS(520), 1,
      anon_sym_RBRACK,
    STATE(114), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2398] = 3,
    ACTIONS(522), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(524), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2410] = 4,
    ACTIONS(496), 1,
      anon_sym_COMMA,
    ACTIONS(526), 1,
      anon_sym_RBRACE,
    STATE(131), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2424] = 4,
    ACTIONS(528), 1,
      anon_sym_COMMA,
    ACTIONS(531), 1,
      anon_sym_RBRACK,
    STATE(120), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2438] = 3,
    ACTIONS(533), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(535), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2450] = 4,
    ACTIONS(533), 1,
      anon_sym_RBRACK,
    ACTIONS(537), 1,
      anon_sym_COMMA,
    STATE(133), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2464] = 4,
    ACTIONS(539), 1,
      anon_sym_COMMA,
    ACTIONS(542), 1,
      anon_sym_RBRACK,
    STATE(123), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2478] = 3,
    ACTIONS(546), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(544), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2490] = 4,
    ACTIONS(546), 1,
      anon_sym_RBRACK,
    ACTIONS(548), 1,
      anon_sym_COMMA,
    STATE(136), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2504] = 4,
    ACTIONS(550), 1,
      anon_sym_COMMA,
    ACTIONS(553), 1,
      anon_sym_RBRACK,
    STATE(126), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2518] = 3,
    ACTIONS(557), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(555), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2530] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(559), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2540] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(561), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2550] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(563), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2560] = 4,
    ACTIONS(565), 1,
      anon_sym_COMMA,
    ACTIONS(568), 1,
      anon_sym_RBRACE,
    STATE(131), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2574] = 3,
    ACTIONS(570), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(535), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2586] = 4,
    ACTIONS(572), 1,
      anon_sym_COMMA,
    ACTIONS(575), 1,
      anon_sym_RBRACK,
    STATE(133), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2600] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(393), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2610] = 3,
    ACTIONS(577), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(544), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2622] = 4,
    ACTIONS(579), 1,
      anon_sym_COMMA,
    ACTIONS(582), 1,
      anon_sym_RBRACK,
    STATE(136), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2636] = 4,
    ACTIONS(355), 1,
      sym_NUMBER,
    ACTIONS(403), 1,
      sym_CONSTANT,
    STATE(147), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2650] = 4,
    ACTIONS(584), 1,
      sym_QUOTED_STRING,
    ACTIONS(586), 1,
      anon_sym_RBRACE,
    STATE(109), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2664] = 4,
    ACTIONS(502), 1,
      anon_sym_COMMA,
    ACTIONS(588), 1,
      anon_sym_RBRACK,
    STATE(111), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2678] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(590), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2688] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(592), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2698] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(542), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2707] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(594), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2716] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(490), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2725] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(482), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2734] = 3,
    ACTIONS(596), 1,
      anon_sym_slot,
    ACTIONS(598), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2745] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(553), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2754] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(600), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2763] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(471), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2772] = 3,
    ACTIONS(602), 1,
      anon_sym_serial_dialog,
    ACTIONS(604), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2783] = 3,
    ACTIONS(606), 1,
      anon_sym_LBRACE,
    STATE(40), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2794] = 3,
    ACTIONS(606), 1,
      anon_sym_LBRACE,
    STATE(36), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2805] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(608), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2814] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(610), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [2823] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(568), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [2832] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(612), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2841] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(614), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2850] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(575), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2859] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(616), 2,
      sym_QUOTED_STRING,
      anon_sym_wrap,
  [2868] = 3,
    ACTIONS(618), 1,
      anon_sym_serial_dialog,
    ACTIONS(620), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2879] = 3,
    ACTIONS(584), 1,
      sym_QUOTED_STRING,
    STATE(155), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2890] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(582), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2899] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(476), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2908] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(622), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2917] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(531), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2926] = 3,
    ACTIONS(624), 1,
      anon_sym_LBRACE,
    STATE(29), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2937] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(626), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2946] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(628), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2955] = 3,
    ACTIONS(630), 1,
      anon_sym_LBRACE,
    STATE(32), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2966] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(535), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2975] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(544), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2984] = 3,
    ACTIONS(170), 1,
      anon_sym_LBRACK,
    STATE(13), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2995] = 2,
    ACTIONS(632), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3003] = 2,
    ACTIONS(634), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3011] = 2,
    ACTIONS(636), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3019] = 2,
    ACTIONS(638), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3027] = 2,
    ACTIONS(640), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3035] = 2,
    ACTIONS(642), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3043] = 2,
    ACTIONS(644), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3051] = 2,
    ACTIONS(646), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3059] = 2,
    ACTIONS(648), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3067] = 2,
    ACTIONS(411), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3075] = 2,
    ACTIONS(650), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3083] = 2,
    ACTIONS(652), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3091] = 2,
    ACTIONS(654), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3099] = 2,
    ACTIONS(656), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3107] = 2,
    ACTIONS(658), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3115] = 2,
    ACTIONS(660), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3123] = 2,
    ACTIONS(662), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3131] = 2,
    ACTIONS(664), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3139] = 2,
    ACTIONS(666), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3147] = 2,
    ACTIONS(668), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3155] = 2,
    ACTIONS(670), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3163] = 2,
    ACTIONS(672), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3171] = 2,
    ACTIONS(674), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3179] = 2,
    ACTIONS(676), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3187] = 2,
    ACTIONS(678), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3195] = 2,
    ACTIONS(680), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3203] = 2,
    ACTIONS(682), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3211] = 2,
    ACTIONS(684), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3219] = 2,
    ACTIONS(686), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3227] = 2,
    ACTIONS(688), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3235] = 2,
    ACTIONS(690), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3243] = 2,
    ACTIONS(692), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3251] = 2,
    ACTIONS(694), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3259] = 2,
    ACTIONS(696), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3267] = 2,
    ACTIONS(698), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3275] = 2,
    ACTIONS(700), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3283] = 2,
    ACTIONS(702), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3291] = 2,
    ACTIONS(704), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3299] = 2,
    ACTIONS(706), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3307] = 2,
    ACTIONS(708), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3315] = 2,
    ACTIONS(710), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3323] = 2,
    ACTIONS(712), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3331] = 2,
    ACTIONS(714), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3339] = 2,
    ACTIONS(716), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3347] = 2,
    ACTIONS(718), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3355] = 2,
    ACTIONS(720), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3363] = 2,
    ACTIONS(722), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3371] = 2,
    ACTIONS(724), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3379] = 2,
    ACTIONS(726), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3387] = 2,
    ACTIONS(728), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3395] = 2,
    ACTIONS(730), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3403] = 2,
    ACTIONS(732), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3411] = 2,
    ACTIONS(734), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3419] = 2,
    ACTIONS(736), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3427] = 2,
    ACTIONS(738), 1,
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
  [SMALL_STATE(17)] = 603,
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
  [SMALL_STATE(36)] = 1044,
  [SMALL_STATE(37)] = 1062,
  [SMALL_STATE(38)] = 1080,
  [SMALL_STATE(39)] = 1096,
  [SMALL_STATE(40)] = 1114,
  [SMALL_STATE(41)] = 1132,
  [SMALL_STATE(42)] = 1150,
  [SMALL_STATE(43)] = 1168,
  [SMALL_STATE(44)] = 1186,
  [SMALL_STATE(45)] = 1202,
  [SMALL_STATE(46)] = 1220,
  [SMALL_STATE(47)] = 1247,
  [SMALL_STATE(48)] = 1276,
  [SMALL_STATE(49)] = 1303,
  [SMALL_STATE(50)] = 1318,
  [SMALL_STATE(51)] = 1345,
  [SMALL_STATE(52)] = 1360,
  [SMALL_STATE(53)] = 1387,
  [SMALL_STATE(54)] = 1414,
  [SMALL_STATE(55)] = 1438,
  [SMALL_STATE(56)] = 1461,
  [SMALL_STATE(57)] = 1484,
  [SMALL_STATE(58)] = 1507,
  [SMALL_STATE(59)] = 1530,
  [SMALL_STATE(60)] = 1553,
  [SMALL_STATE(61)] = 1572,
  [SMALL_STATE(62)] = 1593,
  [SMALL_STATE(63)] = 1616,
  [SMALL_STATE(64)] = 1637,
  [SMALL_STATE(65)] = 1658,
  [SMALL_STATE(66)] = 1676,
  [SMALL_STATE(67)] = 1694,
  [SMALL_STATE(68)] = 1708,
  [SMALL_STATE(69)] = 1726,
  [SMALL_STATE(70)] = 1742,
  [SMALL_STATE(71)] = 1760,
  [SMALL_STATE(72)] = 1780,
  [SMALL_STATE(73)] = 1798,
  [SMALL_STATE(74)] = 1813,
  [SMALL_STATE(75)] = 1830,
  [SMALL_STATE(76)] = 1845,
  [SMALL_STATE(77)] = 1860,
  [SMALL_STATE(78)] = 1873,
  [SMALL_STATE(79)] = 1888,
  [SMALL_STATE(80)] = 1905,
  [SMALL_STATE(81)] = 1922,
  [SMALL_STATE(82)] = 1935,
  [SMALL_STATE(83)] = 1948,
  [SMALL_STATE(84)] = 1965,
  [SMALL_STATE(85)] = 1978,
  [SMALL_STATE(86)] = 1995,
  [SMALL_STATE(87)] = 2008,
  [SMALL_STATE(88)] = 2025,
  [SMALL_STATE(89)] = 2036,
  [SMALL_STATE(90)] = 2049,
  [SMALL_STATE(91)] = 2064,
  [SMALL_STATE(92)] = 2079,
  [SMALL_STATE(93)] = 2090,
  [SMALL_STATE(94)] = 2101,
  [SMALL_STATE(95)] = 2112,
  [SMALL_STATE(96)] = 2126,
  [SMALL_STATE(97)] = 2140,
  [SMALL_STATE(98)] = 2152,
  [SMALL_STATE(99)] = 2166,
  [SMALL_STATE(100)] = 2178,
  [SMALL_STATE(101)] = 2192,
  [SMALL_STATE(102)] = 2206,
  [SMALL_STATE(103)] = 2216,
  [SMALL_STATE(104)] = 2226,
  [SMALL_STATE(105)] = 2238,
  [SMALL_STATE(106)] = 2248,
  [SMALL_STATE(107)] = 2258,
  [SMALL_STATE(108)] = 2268,
  [SMALL_STATE(109)] = 2278,
  [SMALL_STATE(110)] = 2292,
  [SMALL_STATE(111)] = 2304,
  [SMALL_STATE(112)] = 2318,
  [SMALL_STATE(113)] = 2332,
  [SMALL_STATE(114)] = 2346,
  [SMALL_STATE(115)] = 2360,
  [SMALL_STATE(116)] = 2374,
  [SMALL_STATE(117)] = 2384,
  [SMALL_STATE(118)] = 2398,
  [SMALL_STATE(119)] = 2410,
  [SMALL_STATE(120)] = 2424,
  [SMALL_STATE(121)] = 2438,
  [SMALL_STATE(122)] = 2450,
  [SMALL_STATE(123)] = 2464,
  [SMALL_STATE(124)] = 2478,
  [SMALL_STATE(125)] = 2490,
  [SMALL_STATE(126)] = 2504,
  [SMALL_STATE(127)] = 2518,
  [SMALL_STATE(128)] = 2530,
  [SMALL_STATE(129)] = 2540,
  [SMALL_STATE(130)] = 2550,
  [SMALL_STATE(131)] = 2560,
  [SMALL_STATE(132)] = 2574,
  [SMALL_STATE(133)] = 2586,
  [SMALL_STATE(134)] = 2600,
  [SMALL_STATE(135)] = 2610,
  [SMALL_STATE(136)] = 2622,
  [SMALL_STATE(137)] = 2636,
  [SMALL_STATE(138)] = 2650,
  [SMALL_STATE(139)] = 2664,
  [SMALL_STATE(140)] = 2678,
  [SMALL_STATE(141)] = 2688,
  [SMALL_STATE(142)] = 2698,
  [SMALL_STATE(143)] = 2707,
  [SMALL_STATE(144)] = 2716,
  [SMALL_STATE(145)] = 2725,
  [SMALL_STATE(146)] = 2734,
  [SMALL_STATE(147)] = 2745,
  [SMALL_STATE(148)] = 2754,
  [SMALL_STATE(149)] = 2763,
  [SMALL_STATE(150)] = 2772,
  [SMALL_STATE(151)] = 2783,
  [SMALL_STATE(152)] = 2794,
  [SMALL_STATE(153)] = 2805,
  [SMALL_STATE(154)] = 2814,
  [SMALL_STATE(155)] = 2823,
  [SMALL_STATE(156)] = 2832,
  [SMALL_STATE(157)] = 2841,
  [SMALL_STATE(158)] = 2850,
  [SMALL_STATE(159)] = 2859,
  [SMALL_STATE(160)] = 2868,
  [SMALL_STATE(161)] = 2879,
  [SMALL_STATE(162)] = 2890,
  [SMALL_STATE(163)] = 2899,
  [SMALL_STATE(164)] = 2908,
  [SMALL_STATE(165)] = 2917,
  [SMALL_STATE(166)] = 2926,
  [SMALL_STATE(167)] = 2937,
  [SMALL_STATE(168)] = 2946,
  [SMALL_STATE(169)] = 2955,
  [SMALL_STATE(170)] = 2966,
  [SMALL_STATE(171)] = 2975,
  [SMALL_STATE(172)] = 2984,
  [SMALL_STATE(173)] = 2995,
  [SMALL_STATE(174)] = 3003,
  [SMALL_STATE(175)] = 3011,
  [SMALL_STATE(176)] = 3019,
  [SMALL_STATE(177)] = 3027,
  [SMALL_STATE(178)] = 3035,
  [SMALL_STATE(179)] = 3043,
  [SMALL_STATE(180)] = 3051,
  [SMALL_STATE(181)] = 3059,
  [SMALL_STATE(182)] = 3067,
  [SMALL_STATE(183)] = 3075,
  [SMALL_STATE(184)] = 3083,
  [SMALL_STATE(185)] = 3091,
  [SMALL_STATE(186)] = 3099,
  [SMALL_STATE(187)] = 3107,
  [SMALL_STATE(188)] = 3115,
  [SMALL_STATE(189)] = 3123,
  [SMALL_STATE(190)] = 3131,
  [SMALL_STATE(191)] = 3139,
  [SMALL_STATE(192)] = 3147,
  [SMALL_STATE(193)] = 3155,
  [SMALL_STATE(194)] = 3163,
  [SMALL_STATE(195)] = 3171,
  [SMALL_STATE(196)] = 3179,
  [SMALL_STATE(197)] = 3187,
  [SMALL_STATE(198)] = 3195,
  [SMALL_STATE(199)] = 3203,
  [SMALL_STATE(200)] = 3211,
  [SMALL_STATE(201)] = 3219,
  [SMALL_STATE(202)] = 3227,
  [SMALL_STATE(203)] = 3235,
  [SMALL_STATE(204)] = 3243,
  [SMALL_STATE(205)] = 3251,
  [SMALL_STATE(206)] = 3259,
  [SMALL_STATE(207)] = 3267,
  [SMALL_STATE(208)] = 3275,
  [SMALL_STATE(209)] = 3283,
  [SMALL_STATE(210)] = 3291,
  [SMALL_STATE(211)] = 3299,
  [SMALL_STATE(212)] = 3307,
  [SMALL_STATE(213)] = 3315,
  [SMALL_STATE(214)] = 3323,
  [SMALL_STATE(215)] = 3331,
  [SMALL_STATE(216)] = 3339,
  [SMALL_STATE(217)] = 3347,
  [SMALL_STATE(218)] = 3355,
  [SMALL_STATE(219)] = 3363,
  [SMALL_STATE(220)] = 3371,
  [SMALL_STATE(221)] = 3379,
  [SMALL_STATE(222)] = 3387,
  [SMALL_STATE(223)] = 3395,
  [SMALL_STATE(224)] = 3403,
  [SMALL_STATE(225)] = 3411,
  [SMALL_STATE(226)] = 3419,
  [SMALL_STATE(227)] = 3427,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(160),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(143),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(167),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(195),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(172),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(213),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(177),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(150),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(174),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(146),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(212),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(195),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(172),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(213),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(177),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(150),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(174),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(212),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(151),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(151),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(218),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [102] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(160),
  [105] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(143),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(129),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(167),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_definition, 2, 0, 6),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_definition, 2, 0, 6),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 34),
  [152] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 34), SHIFT_REPEAT(144),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 34), SHIFT_REPEAT(106),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 3, 0, 30),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 3, 0, 30),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 9),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 9),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 19),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 20),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 20),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 1, 0, 28),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 29),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 29),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(153),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 26),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [286] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(196),
  [289] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(157),
  [292] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(102),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 35),
  [297] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 35),
  [299] = {.entry = {.count = 1, .reusable = false}}, SHIFT(220),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [305] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [307] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [309] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 31), SHIFT_REPEAT(49),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 31),
  [314] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 31), SHIFT_REPEAT(148),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 13),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [325] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 22),
  [329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 37),
  [331] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 37), SHIFT_REPEAT(67),
  [334] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 37),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 38),
  [338] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 38),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 40),
  [344] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 40),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 41),
  [348] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 41),
  [350] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 41), SHIFT_REPEAT(173),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [361] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 27),
  [363] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 27),
  [365] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [367] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 21),
  [376] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 21), SHIFT_REPEAT(153),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 25),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [413] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 47),
  [415] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 47),
  [417] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [419] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 32),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 33),
  [427] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 33), SHIFT_REPEAT(181),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [434] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 3, 0, 39),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 36),
  [438] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 36),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [442] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 24), SHIFT_REPEAT(116),
  [445] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 24),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 43),
  [449] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 44),
  [451] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 5, 0, 46),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [473] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(149),
  [476] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_entity, 1, 0, 0),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [488] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 19),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [492] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 10),
  [494] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [516] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 11),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [520] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [528] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [531] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [539] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [544] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [546] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [548] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [550] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(137),
  [553] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [555] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 14),
  [557] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 14),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [563] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [565] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(161),
  [568] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [570] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [572] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(170),
  [575] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [579] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(171),
  [582] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [584] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [586] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [590] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [592] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [594] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [604] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [606] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [608] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter_int, 1, 0, 0),
  [610] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 42),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [614] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_label, 1, 0, 0),
  [616] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 12),
  [618] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [620] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [622] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 23),
  [624] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [626] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [628] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 45),
  [630] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [632] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [634] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [636] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 8),
  [638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [642] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [644] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 8),
  [646] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [650] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [652] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [654] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 16),
  [656] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [658] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [660] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [662] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [664] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [666] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [668] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [670] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [672] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [674] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [676] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [678] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 15),
  [680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [682] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [684] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [688] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [690] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [692] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [694] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [696] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [698] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 17),
  [700] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [702] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 15),
  [704] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [706] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [712] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [714] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [716] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 10),
  [718] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 10),
  [720] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [722] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [724] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 7),
  [726] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [728] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [730] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [734] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [736] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 18),
  [738] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
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
