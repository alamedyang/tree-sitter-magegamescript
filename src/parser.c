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
#define STATE_COUNT 239
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 131
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
  anon_sym_return = 48,
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
  sym_action_return_statement = 101,
  sym_action_close_dialog = 102,
  sym_action_close_serial_dialog = 103,
  sym_action_save_slot = 104,
  sym_action_load_slot = 105,
  sym_action_erase_slot = 106,
  sym_action_load_map = 107,
  sym_action_run_script = 108,
  sym_action_goto_label = 109,
  sym_action_goto_index = 110,
  sym_action_non_blocking_delay = 111,
  sym_action_blocking_delay = 112,
  aux_sym_document_repeat1 = 113,
  aux_sym_bareword_expansion_repeat1 = 114,
  aux_sym_quoted_string_expansion_repeat1 = 115,
  aux_sym_string_expansion_repeat1 = 116,
  aux_sym_number_expansion_repeat1 = 117,
  aux_sym_duration_expansion_repeat1 = 118,
  aux_sym_add_serial_dialog_settings_repeat1 = 119,
  aux_sym_add_dialog_settings_repeat1 = 120,
  aux_sym_add_dialog_settings_target_repeat1 = 121,
  aux_sym__dialog_block_repeat1 = 122,
  aux_sym_dialog_repeat1 = 123,
  aux_sym_dialog_repeat2 = 124,
  aux_sym_serial_dialog_repeat1 = 125,
  aux_sym_serial_dialog_repeat2 = 126,
  aux_sym_serial_dialog_repeat3 = 127,
  aux_sym_script_block_repeat1 = 128,
  aux_sym_json_array_repeat1 = 129,
  aux_sym_json_object_repeat1 = 130,
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
  [anon_sym_return] = "return",
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
  [sym_action_return_statement] = "action_return_statement",
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
  [anon_sym_return] = anon_sym_return,
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
  [sym_action_return_statement] = sym_action_return_statement,
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
  [anon_sym_return] = {
    .visible = true,
    .named = false,
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
  [sym_action_return_statement] = {
    .visible = true,
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
  [7] = {.index = 8, .length = 2},
  [8] = {.index = 10, .length = 1},
  [9] = {.index = 11, .length = 1},
  [10] = {.index = 12, .length = 1},
  [11] = {.index = 13, .length = 1},
  [12] = {.index = 14, .length = 1},
  [13] = {.index = 15, .length = 1},
  [14] = {.index = 16, .length = 1},
  [15] = {.index = 17, .length = 2},
  [16] = {.index = 19, .length = 1},
  [17] = {.index = 20, .length = 2},
  [18] = {.index = 22, .length = 2},
  [19] = {.index = 24, .length = 1},
  [20] = {.index = 25, .length = 2},
  [21] = {.index = 27, .length = 2},
  [22] = {.index = 29, .length = 2},
  [23] = {.index = 31, .length = 1},
  [24] = {.index = 32, .length = 1},
  [25] = {.index = 33, .length = 2},
  [26] = {.index = 35, .length = 1},
  [27] = {.index = 36, .length = 2},
  [28] = {.index = 38, .length = 1},
  [29] = {.index = 39, .length = 1},
  [30] = {.index = 40, .length = 1},
  [31] = {.index = 41, .length = 1},
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
    {field_dialog, 0},
  [15] =
    {field_script, 1},
  [16] =
    {field_duration, 1},
  [17] =
    {field_property, 0},
    {field_value, 1},
  [19] =
    {field_serial_dialog, 1},
  [20] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_dialog_parameter, 1, .inherited = true},
  [22] =
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [24] =
    {field_serial_dialog_option, 0},
  [25] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [27] =
    {field_serial_dialog_option, 1, .inherited = true},
    {field_serial_message, 0, .inherited = true},
  [29] =
    {field_type, 0},
    {field_value, 1},
  [31] =
    {field_message, 0},
  [32] =
    {field_dialog_parameter, 0},
  [33] =
    {field_dialog_identifier, 0},
    {field_message, 1, .inherited = true},
  [35] =
    {field_dialog, 1, .inherited = true},
  [36] =
    {field_dialog, 0, .inherited = true},
    {field_dialog, 1, .inherited = true},
  [38] =
    {field_slot, 2},
  [39] =
    {field_map, 2},
  [40] =
    {field_label, 2},
  [41] =
    {field_index, 2},
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
  [228] = 228,
  [229] = 229,
  [230] = 230,
  [231] = 231,
  [232] = 232,
  [233] = 233,
  [234] = 234,
  [235] = 235,
  [236] = 236,
  [237] = 237,
  [238] = 238,
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
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(anon_sym_return);
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
  [15] = {.lex_state = 7},
  [16] = {.lex_state = 7},
  [17] = {.lex_state = 7},
  [18] = {.lex_state = 7},
  [19] = {.lex_state = 7},
  [20] = {.lex_state = 7},
  [21] = {.lex_state = 4},
  [22] = {.lex_state = 7},
  [23] = {.lex_state = 7},
  [24] = {.lex_state = 7},
  [25] = {.lex_state = 4},
  [26] = {.lex_state = 7},
  [27] = {.lex_state = 7},
  [28] = {.lex_state = 4},
  [29] = {.lex_state = 7},
  [30] = {.lex_state = 7},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 4},
  [33] = {.lex_state = 4},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 192},
  [40] = {.lex_state = 192},
  [41] = {.lex_state = 192},
  [42] = {.lex_state = 192},
  [43] = {.lex_state = 192},
  [44] = {.lex_state = 192},
  [45] = {.lex_state = 192},
  [46] = {.lex_state = 192},
  [47] = {.lex_state = 192},
  [48] = {.lex_state = 192},
  [49] = {.lex_state = 192},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 192},
  [52] = {.lex_state = 192},
  [53] = {.lex_state = 192},
  [54] = {.lex_state = 192},
  [55] = {.lex_state = 4},
  [56] = {.lex_state = 192},
  [57] = {.lex_state = 4},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 4},
  [61] = {.lex_state = 4},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 4},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 3},
  [66] = {.lex_state = 4},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 192},
  [82] = {.lex_state = 192},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 192},
  [85] = {.lex_state = 192},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 4},
  [92] = {.lex_state = 192},
  [93] = {.lex_state = 4},
  [94] = {.lex_state = 4},
  [95] = {.lex_state = 4},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 192},
  [99] = {.lex_state = 4},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 192},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 4},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 4},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 2},
  [118] = {.lex_state = 4},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 2},
  [127] = {.lex_state = 192},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 192},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 2},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 192},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 192},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 2},
  [146] = {.lex_state = 2},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 192},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 2},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 11},
  [154] = {.lex_state = 192},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 2},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 4},
  [162] = {.lex_state = 2},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 11},
  [166] = {.lex_state = 192},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 2},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 2},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 192},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 2},
  [180] = {.lex_state = 4},
  [181] = {.lex_state = 11},
  [182] = {.lex_state = 192},
  [183] = {.lex_state = 2},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 11},
  [189] = {.lex_state = 11},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 11},
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
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 0},
  [235] = {.lex_state = 0},
  [236] = {.lex_state = 0},
  [237] = {.lex_state = 11},
  [238] = {.lex_state = 0},
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
    [anon_sym_return] = ACTIONS(1),
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
    [sym_document] = STATE(193),
    [sym__root] = STATE(7),
    [sym_include_macro] = STATE(7),
    [sym_constant_assignment] = STATE(7),
    [sym_add_serial_dialog_settings] = STATE(7),
    [sym_add_dialog_settings] = STATE(7),
    [sym_dialog_definition] = STATE(7),
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
    [anon_sym_dialog] = ACTIONS(19),
    [anon_sym_script] = ACTIONS(21),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 14,
    ACTIONS(23), 1,
      sym_BAREWORD,
    ACTIONS(28), 1,
      anon_sym_json,
    ACTIONS(31), 1,
      anon_sym_rand,
    ACTIONS(34), 1,
      anon_sym_return,
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
    STATE(2), 18,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
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
      aux_sym_script_block_repeat1,
  [62] = 14,
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(60), 1,
      anon_sym_RBRACE,
    ACTIONS(62), 1,
      anon_sym_json,
    ACTIONS(64), 1,
      anon_sym_rand,
    ACTIONS(66), 1,
      anon_sym_return,
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
    STATE(2), 18,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
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
      aux_sym_script_block_repeat1,
  [123] = 14,
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(62), 1,
      anon_sym_json,
    ACTIONS(64), 1,
      anon_sym_rand,
    ACTIONS(66), 1,
      anon_sym_return,
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
    STATE(3), 18,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
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
      aux_sym_script_block_repeat1,
  [184] = 14,
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(62), 1,
      anon_sym_json,
    ACTIONS(64), 1,
      anon_sym_rand,
    ACTIONS(66), 1,
      anon_sym_return,
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
    STATE(6), 18,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
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
      aux_sym_script_block_repeat1,
  [245] = 14,
    ACTIONS(58), 1,
      sym_BAREWORD,
    ACTIONS(62), 1,
      anon_sym_json,
    ACTIONS(64), 1,
      anon_sym_rand,
    ACTIONS(66), 1,
      anon_sym_return,
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
    STATE(2), 18,
      sym__script_item,
      sym_json_literal,
      sym_rand_macro,
      sym_label_definition,
      sym__action_item,
      sym_action_return_statement,
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
      aux_sym_script_block_repeat1,
  [306] = 11,
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
    ACTIONS(88), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(8), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [349] = 11,
    ACTIONS(90), 1,
      ts_builtin_sym_end,
    ACTIONS(92), 1,
      sym_BAREWORD,
    ACTIONS(95), 1,
      sym_QUOTED_STRING,
    ACTIONS(98), 1,
      sym_CONSTANT,
    ACTIONS(101), 1,
      anon_sym_include,
    ACTIONS(104), 1,
      anon_sym_add,
    ACTIONS(107), 1,
      anon_sym_serial_dialog,
    ACTIONS(110), 1,
      anon_sym_dialog,
    ACTIONS(113), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(8), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [392] = 3,
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
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [416] = 3,
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
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [440] = 3,
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
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [464] = 3,
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
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [486] = 3,
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
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [508] = 3,
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
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [530] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(140), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [552] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(146), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(144), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [574] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(150), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(148), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [596] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(154), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(152), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [618] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(158), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(156), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [640] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(162), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(160), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [662] = 9,
    ACTIONS(164), 1,
      sym_QUOTED_STRING,
    STATE(28), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(50), 1,
      sym_dialog_parameter,
    STATE(62), 1,
      aux_sym_dialog_repeat1,
    STATE(116), 1,
      sym__dialog_parameter_string,
    STATE(166), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(166), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(168), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [696] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(172), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(170), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [718] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(176), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(174), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [740] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(180), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(178), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [762] = 9,
    ACTIONS(164), 1,
      sym_QUOTED_STRING,
    STATE(21), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(50), 1,
      sym_dialog_parameter,
    STATE(58), 1,
      aux_sym_dialog_repeat1,
    STATE(116), 1,
      sym__dialog_parameter_string,
    STATE(166), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(166), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(168), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [796] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(184), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(182), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [818] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(188), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(186), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [840] = 8,
    STATE(28), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(50), 1,
      sym_dialog_parameter,
    STATE(116), 1,
      sym__dialog_parameter_string,
    STATE(166), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(190), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    ACTIONS(192), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(195), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [872] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(200), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(198), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [894] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(204), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(202), 11,
      sym_BAREWORD,
      anon_sym_json,
      anon_sym_rand,
      anon_sym_return,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [916] = 8,
    ACTIONS(206), 1,
      anon_sym_RBRACE,
    STATE(32), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(50), 1,
      sym_dialog_parameter,
    STATE(116), 1,
      sym__dialog_parameter_string,
    STATE(166), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(166), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(168), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [947] = 8,
    ACTIONS(208), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(50), 1,
      sym_dialog_parameter,
    STATE(116), 1,
      sym__dialog_parameter_string,
    STATE(166), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(166), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(168), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [978] = 8,
    ACTIONS(210), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(50), 1,
      sym_dialog_parameter,
    STATE(116), 1,
      sym__dialog_parameter_string,
    STATE(166), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(166), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(168), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1009] = 8,
    ACTIONS(212), 1,
      anon_sym_RBRACE,
    STATE(33), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(50), 1,
      sym_dialog_parameter,
    STATE(116), 1,
      sym__dialog_parameter_string,
    STATE(166), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(166), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(168), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1040] = 6,
    ACTIONS(214), 1,
      anon_sym_LBRACK,
    ACTIONS(216), 1,
      anon_sym_RBRACK,
    ACTIONS(220), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(129), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(218), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1066] = 5,
    ACTIONS(214), 1,
      anon_sym_LBRACK,
    ACTIONS(220), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(164), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(222), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1089] = 6,
    ACTIONS(228), 1,
      sym_NUMBER,
    ACTIONS(230), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(224), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(226), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(187), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [1114] = 5,
    ACTIONS(214), 1,
      anon_sym_LBRACK,
    ACTIONS(220), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(171), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(232), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1137] = 3,
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
  [1155] = 3,
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
  [1173] = 3,
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
  [1191] = 3,
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
  [1209] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(250), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(252), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1227] = 3,
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
  [1245] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(258), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(260), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1263] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(262), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(264), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1281] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(266), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(268), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1299] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(270), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(272), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1317] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(274), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(276), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1335] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(278), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1351] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(280), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(282), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1369] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(284), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(286), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1387] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(288), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(290), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1405] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(292), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(294), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1423] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(296), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1439] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(298), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(300), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1457] = 8,
    ACTIONS(302), 1,
      anon_sym_RBRACE,
    ACTIONS(304), 1,
      sym_target_default,
    ACTIONS(306), 1,
      anon_sym_label,
    ACTIONS(308), 1,
      anon_sym_entity,
    STATE(111), 1,
      sym_target_entity,
    STATE(179), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(63), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1484] = 8,
    ACTIONS(164), 1,
      sym_QUOTED_STRING,
    ACTIONS(312), 1,
      sym_identifier_type,
    ACTIONS(314), 1,
      anon_sym_GT,
    STATE(71), 1,
      aux_sym_dialog_repeat1,
    STATE(72), 1,
      aux_sym_dialog_repeat2,
    STATE(100), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(310), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1511] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(316), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1526] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(318), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1541] = 8,
    ACTIONS(304), 1,
      sym_target_default,
    ACTIONS(306), 1,
      anon_sym_label,
    ACTIONS(308), 1,
      anon_sym_entity,
    ACTIONS(320), 1,
      anon_sym_RBRACE,
    STATE(111), 1,
      sym_target_entity,
    STATE(179), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(57), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1568] = 8,
    ACTIONS(164), 1,
      sym_QUOTED_STRING,
    ACTIONS(314), 1,
      anon_sym_GT,
    ACTIONS(324), 1,
      sym_identifier_type,
    STATE(71), 1,
      aux_sym_dialog_repeat1,
    STATE(74), 1,
      aux_sym_dialog_repeat2,
    STATE(100), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(322), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1595] = 8,
    ACTIONS(326), 1,
      anon_sym_RBRACE,
    ACTIONS(328), 1,
      sym_target_default,
    ACTIONS(331), 1,
      anon_sym_label,
    ACTIONS(334), 1,
      anon_sym_entity,
    STATE(111), 1,
      sym_target_entity,
    STATE(179), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(63), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1622] = 9,
    ACTIONS(337), 1,
      sym_QUOTED_STRING,
    ACTIONS(339), 1,
      anon_sym_RBRACE,
    ACTIONS(341), 1,
      anon_sym_wrap,
    STATE(70), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(73), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(154), 1,
      sym_serial_dialog_parameter_int,
    STATE(156), 1,
      sym_serial_dialog_parameter,
    STATE(223), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1651] = 7,
    ACTIONS(343), 1,
      sym_BAREWORD,
    ACTIONS(345), 1,
      anon_sym_LBRACK,
    ACTIONS(349), 1,
      anon_sym_label,
    ACTIONS(351), 1,
      anon_sym_index,
    STATE(190), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(347), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1675] = 7,
    ACTIONS(337), 1,
      sym_QUOTED_STRING,
    ACTIONS(353), 1,
      anon_sym_RBRACE,
    ACTIONS(355), 1,
      sym_serial_dialog_option_type,
    STATE(90), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(93), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(161), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1698] = 7,
    ACTIONS(357), 1,
      sym_BAREWORD,
    ACTIONS(359), 1,
      anon_sym_RBRACE,
    ACTIONS(361), 1,
      sym_identifier_type,
    STATE(25), 1,
      sym_dialog_identifier,
    STATE(69), 1,
      aux_sym__dialog_block_repeat1,
    STATE(126), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1721] = 7,
    ACTIONS(363), 1,
      sym_BAREWORD,
    ACTIONS(366), 1,
      anon_sym_RBRACE,
    ACTIONS(368), 1,
      sym_identifier_type,
    STATE(25), 1,
      sym_dialog_identifier,
    STATE(68), 1,
      aux_sym__dialog_block_repeat1,
    STATE(126), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1744] = 7,
    ACTIONS(357), 1,
      sym_BAREWORD,
    ACTIONS(361), 1,
      sym_identifier_type,
    ACTIONS(371), 1,
      anon_sym_RBRACE,
    STATE(25), 1,
      sym_dialog_identifier,
    STATE(68), 1,
      aux_sym__dialog_block_repeat1,
    STATE(126), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1767] = 7,
    ACTIONS(337), 1,
      sym_QUOTED_STRING,
    ACTIONS(341), 1,
      anon_sym_wrap,
    STATE(66), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(78), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(154), 1,
      sym_serial_dialog_parameter_int,
    STATE(156), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1790] = 5,
    ACTIONS(375), 1,
      sym_QUOTED_STRING,
    ACTIONS(378), 1,
      sym_identifier_type,
    STATE(71), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(373), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [1809] = 6,
    ACTIONS(314), 1,
      anon_sym_GT,
    ACTIONS(382), 1,
      sym_identifier_type,
    STATE(75), 1,
      aux_sym_dialog_repeat2,
    STATE(100), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(380), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1830] = 7,
    ACTIONS(337), 1,
      sym_QUOTED_STRING,
    ACTIONS(355), 1,
      sym_serial_dialog_option_type,
    ACTIONS(384), 1,
      anon_sym_RBRACE,
    STATE(93), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(94), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(161), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1853] = 6,
    ACTIONS(314), 1,
      anon_sym_GT,
    ACTIONS(388), 1,
      sym_identifier_type,
    STATE(75), 1,
      aux_sym_dialog_repeat2,
    STATE(100), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(386), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1874] = 6,
    ACTIONS(392), 1,
      sym_identifier_type,
    ACTIONS(394), 1,
      anon_sym_GT,
    STATE(75), 1,
      aux_sym_dialog_repeat2,
    STATE(100), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(390), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1895] = 4,
    ACTIONS(345), 1,
      anon_sym_LBRACK,
    STATE(207), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(397), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1911] = 5,
    ACTIONS(341), 1,
      anon_sym_wrap,
    ACTIONS(399), 1,
      anon_sym_RBRACE,
    STATE(154), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(79), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1929] = 6,
    ACTIONS(401), 1,
      sym_QUOTED_STRING,
    ACTIONS(403), 1,
      anon_sym_wrap,
    STATE(78), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(154), 1,
      sym_serial_dialog_parameter_int,
    STATE(156), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1949] = 5,
    ACTIONS(341), 1,
      anon_sym_wrap,
    ACTIONS(406), 1,
      anon_sym_RBRACE,
    STATE(154), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(80), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1967] = 5,
    ACTIONS(408), 1,
      anon_sym_RBRACE,
    ACTIONS(410), 1,
      anon_sym_wrap,
    STATE(154), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(80), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1985] = 5,
    ACTIONS(413), 1,
      anon_sym_LBRACK,
    ACTIONS(415), 1,
      sym_NUMBER,
    ACTIONS(417), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(218), 2,
      sym_DURATION,
      sym_duration_expansion,
  [2003] = 5,
    ACTIONS(413), 1,
      anon_sym_LBRACK,
    ACTIONS(415), 1,
      sym_NUMBER,
    ACTIONS(419), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(192), 2,
      sym_DURATION,
      sym_duration_expansion,
  [2021] = 3,
    ACTIONS(423), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(421), 4,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2035] = 5,
    ACTIONS(415), 1,
      sym_NUMBER,
    ACTIONS(425), 1,
      anon_sym_RBRACK,
    ACTIONS(427), 1,
      sym_CONSTANT,
    STATE(168), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2052] = 4,
    ACTIONS(429), 1,
      anon_sym_LBRACK,
    STATE(238), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(431), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2067] = 3,
    ACTIONS(435), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(433), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2080] = 3,
    ACTIONS(439), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(437), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2093] = 4,
    ACTIONS(443), 1,
      anon_sym_LBRACK,
    STATE(236), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(441), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2108] = 4,
    ACTIONS(445), 1,
      anon_sym_LBRACK,
    STATE(231), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(447), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2123] = 5,
    ACTIONS(355), 1,
      sym_serial_dialog_option_type,
    ACTIONS(449), 1,
      anon_sym_RBRACE,
    STATE(91), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(161), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2140] = 5,
    ACTIONS(451), 1,
      anon_sym_RBRACE,
    ACTIONS(453), 1,
      sym_serial_dialog_option_type,
    STATE(91), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(161), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2157] = 4,
    ACTIONS(429), 1,
      anon_sym_LBRACK,
    STATE(196), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(456), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2172] = 4,
    ACTIONS(458), 1,
      sym_QUOTED_STRING,
    STATE(93), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(461), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2187] = 5,
    ACTIONS(355), 1,
      sym_serial_dialog_option_type,
    ACTIONS(463), 1,
      anon_sym_RBRACE,
    STATE(91), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(161), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2204] = 3,
    ACTIONS(467), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(465), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [2217] = 5,
    ACTIONS(467), 1,
      sym_duration_suffix,
    ACTIONS(469), 1,
      sym_distance_suffix,
    ACTIONS(471), 1,
      sym_quantity_suffix,
    ACTIONS(473), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2234] = 3,
    ACTIONS(475), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(433), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2247] = 5,
    ACTIONS(415), 1,
      sym_NUMBER,
    ACTIONS(427), 1,
      sym_CONSTANT,
    ACTIONS(477), 1,
      anon_sym_RBRACK,
    STATE(168), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2264] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(479), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2275] = 3,
    ACTIONS(483), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(481), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2288] = 4,
    ACTIONS(429), 1,
      anon_sym_LBRACK,
    STATE(204), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(485), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2303] = 3,
    ACTIONS(489), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(487), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2316] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(491), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2327] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(493), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2338] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(495), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2349] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(497), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2359] = 3,
    ACTIONS(501), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(499), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2371] = 4,
    ACTIONS(503), 1,
      anon_sym_COMMA,
    ACTIONS(505), 1,
      anon_sym_RBRACK,
    STATE(125), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2385] = 3,
    ACTIONS(507), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(509), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2397] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(511), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2407] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(513), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2417] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(515), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [2427] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(517), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [2437] = 3,
    ACTIONS(519), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(509), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2449] = 4,
    ACTIONS(519), 1,
      anon_sym_RBRACK,
    ACTIONS(521), 1,
      anon_sym_COMMA,
    STATE(152), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2463] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(523), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2473] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(525), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2483] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(527), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2493] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(529), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2503] = 4,
    ACTIONS(531), 1,
      anon_sym_COMMA,
    ACTIONS(533), 1,
      anon_sym_RBRACE,
    STATE(132), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2517] = 4,
    ACTIONS(535), 1,
      anon_sym_COMMA,
    ACTIONS(537), 1,
      anon_sym_RBRACK,
    STATE(133), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2531] = 4,
    ACTIONS(539), 1,
      anon_sym_COMMA,
    ACTIONS(541), 1,
      anon_sym_RBRACK,
    STATE(135), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2545] = 4,
    ACTIONS(435), 1,
      anon_sym_RBRACK,
    ACTIONS(543), 1,
      anon_sym_COMMA,
    STATE(136), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2559] = 4,
    ACTIONS(545), 1,
      anon_sym_COMMA,
    ACTIONS(547), 1,
      anon_sym_RBRACK,
    STATE(138), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2573] = 4,
    ACTIONS(425), 1,
      anon_sym_RBRACK,
    ACTIONS(549), 1,
      anon_sym_COMMA,
    STATE(140), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2587] = 3,
    ACTIONS(553), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(551), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2599] = 4,
    ACTIONS(415), 1,
      sym_NUMBER,
    ACTIONS(555), 1,
      sym_CONSTANT,
    STATE(108), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2613] = 4,
    ACTIONS(557), 1,
      sym_QUOTED_STRING,
    ACTIONS(559), 1,
      anon_sym_RBRACE,
    STATE(120), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2627] = 4,
    ACTIONS(535), 1,
      anon_sym_COMMA,
    ACTIONS(561), 1,
      anon_sym_RBRACK,
    STATE(121), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2641] = 3,
    ACTIONS(563), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(565), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2653] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(567), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2663] = 4,
    ACTIONS(531), 1,
      anon_sym_COMMA,
    ACTIONS(569), 1,
      anon_sym_RBRACE,
    STATE(142), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2677] = 4,
    ACTIONS(571), 1,
      anon_sym_COMMA,
    ACTIONS(574), 1,
      anon_sym_RBRACK,
    STATE(133), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2691] = 3,
    ACTIONS(576), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(578), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2703] = 4,
    ACTIONS(576), 1,
      anon_sym_RBRACK,
    ACTIONS(580), 1,
      anon_sym_COMMA,
    STATE(144), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2717] = 4,
    ACTIONS(582), 1,
      anon_sym_COMMA,
    ACTIONS(585), 1,
      anon_sym_RBRACK,
    STATE(136), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2731] = 3,
    ACTIONS(589), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(587), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2743] = 4,
    ACTIONS(589), 1,
      anon_sym_RBRACK,
    ACTIONS(591), 1,
      anon_sym_COMMA,
    STATE(147), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2757] = 3,
    ACTIONS(593), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(595), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2769] = 4,
    ACTIONS(597), 1,
      anon_sym_COMMA,
    ACTIONS(600), 1,
      anon_sym_RBRACK,
    STATE(140), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2783] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(602), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2793] = 4,
    ACTIONS(604), 1,
      anon_sym_COMMA,
    ACTIONS(607), 1,
      anon_sym_RBRACE,
    STATE(142), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2807] = 3,
    ACTIONS(609), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(578), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2819] = 4,
    ACTIONS(611), 1,
      anon_sym_COMMA,
    ACTIONS(614), 1,
      anon_sym_RBRACK,
    STATE(144), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2833] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(433), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2843] = 3,
    ACTIONS(616), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(587), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2855] = 4,
    ACTIONS(618), 1,
      anon_sym_COMMA,
    ACTIONS(621), 1,
      anon_sym_RBRACK,
    STATE(147), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2869] = 4,
    ACTIONS(415), 1,
      sym_NUMBER,
    ACTIONS(427), 1,
      sym_CONSTANT,
    STATE(168), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2883] = 4,
    ACTIONS(623), 1,
      anon_sym_COMMA,
    ACTIONS(625), 1,
      anon_sym_RBRACK,
    STATE(123), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2897] = 4,
    ACTIONS(627), 1,
      anon_sym_COMMA,
    ACTIONS(629), 1,
      anon_sym_RBRACK,
    STATE(115), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2911] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(631), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2921] = 4,
    ACTIONS(633), 1,
      anon_sym_COMMA,
    ACTIONS(636), 1,
      anon_sym_RBRACK,
    STATE(152), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2935] = 3,
    ACTIONS(638), 1,
      anon_sym_slot,
    ACTIONS(640), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2946] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(642), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2955] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(636), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2964] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(644), 2,
      sym_QUOTED_STRING,
      anon_sym_wrap,
  [2973] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(509), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2982] = 3,
    ACTIONS(646), 1,
      anon_sym_LBRACE,
    STATE(47), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2993] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(648), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3002] = 3,
    ACTIONS(650), 1,
      anon_sym_LBRACE,
    STATE(41), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3013] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(652), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3022] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(654), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3031] = 3,
    ACTIONS(557), 1,
      sym_QUOTED_STRING,
    STATE(172), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3042] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(574), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3051] = 3,
    ACTIONS(656), 1,
      anon_sym_serial_dialog,
    ACTIONS(658), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3062] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(523), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3071] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(585), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3080] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(600), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3089] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(660), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3098] = 3,
    ACTIONS(662), 1,
      anon_sym_LBRACE,
    STATE(40), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3109] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(664), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [3118] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(607), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [3127] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(666), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3136] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(614), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3145] = 3,
    ACTIONS(646), 1,
      anon_sym_LBRACE,
    STATE(42), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3156] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(668), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3165] = 3,
    ACTIONS(214), 1,
      anon_sym_LBRACK,
    STATE(20), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3176] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(621), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3185] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(513), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3194] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(670), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3203] = 3,
    ACTIONS(672), 1,
      anon_sym_serial_dialog,
    ACTIONS(674), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3214] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(578), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3223] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(587), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3232] = 2,
    ACTIONS(676), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3240] = 2,
    ACTIONS(678), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3248] = 2,
    ACTIONS(680), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3256] = 2,
    ACTIONS(473), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3264] = 2,
    ACTIONS(682), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3272] = 2,
    ACTIONS(684), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3280] = 2,
    ACTIONS(686), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3288] = 2,
    ACTIONS(688), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3296] = 2,
    ACTIONS(690), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3304] = 2,
    ACTIONS(692), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3312] = 2,
    ACTIONS(694), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3320] = 2,
    ACTIONS(696), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3328] = 2,
    ACTIONS(698), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3336] = 2,
    ACTIONS(700), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3344] = 2,
    ACTIONS(702), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3352] = 2,
    ACTIONS(704), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3360] = 2,
    ACTIONS(706), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3368] = 2,
    ACTIONS(708), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3376] = 2,
    ACTIONS(710), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3384] = 2,
    ACTIONS(712), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3392] = 2,
    ACTIONS(714), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3400] = 2,
    ACTIONS(716), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3408] = 2,
    ACTIONS(718), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3416] = 2,
    ACTIONS(720), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3424] = 2,
    ACTIONS(722), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3432] = 2,
    ACTIONS(724), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3440] = 2,
    ACTIONS(726), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3448] = 2,
    ACTIONS(728), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3456] = 2,
    ACTIONS(730), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3464] = 2,
    ACTIONS(732), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3472] = 2,
    ACTIONS(734), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3480] = 2,
    ACTIONS(736), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3488] = 2,
    ACTIONS(738), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3496] = 2,
    ACTIONS(740), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3504] = 2,
    ACTIONS(742), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3512] = 2,
    ACTIONS(744), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3520] = 2,
    ACTIONS(746), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3528] = 2,
    ACTIONS(748), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3536] = 2,
    ACTIONS(750), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3544] = 2,
    ACTIONS(752), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3552] = 2,
    ACTIONS(754), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3560] = 2,
    ACTIONS(756), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3568] = 2,
    ACTIONS(758), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3576] = 2,
    ACTIONS(760), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3584] = 2,
    ACTIONS(762), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3592] = 2,
    ACTIONS(764), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3600] = 2,
    ACTIONS(766), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3608] = 2,
    ACTIONS(768), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3616] = 2,
    ACTIONS(770), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3624] = 2,
    ACTIONS(772), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3632] = 2,
    ACTIONS(774), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3640] = 2,
    ACTIONS(776), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3648] = 2,
    ACTIONS(778), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3656] = 2,
    ACTIONS(780), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3664] = 2,
    ACTIONS(782), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 62,
  [SMALL_STATE(4)] = 123,
  [SMALL_STATE(5)] = 184,
  [SMALL_STATE(6)] = 245,
  [SMALL_STATE(7)] = 306,
  [SMALL_STATE(8)] = 349,
  [SMALL_STATE(9)] = 392,
  [SMALL_STATE(10)] = 416,
  [SMALL_STATE(11)] = 440,
  [SMALL_STATE(12)] = 464,
  [SMALL_STATE(13)] = 486,
  [SMALL_STATE(14)] = 508,
  [SMALL_STATE(15)] = 530,
  [SMALL_STATE(16)] = 552,
  [SMALL_STATE(17)] = 574,
  [SMALL_STATE(18)] = 596,
  [SMALL_STATE(19)] = 618,
  [SMALL_STATE(20)] = 640,
  [SMALL_STATE(21)] = 662,
  [SMALL_STATE(22)] = 696,
  [SMALL_STATE(23)] = 718,
  [SMALL_STATE(24)] = 740,
  [SMALL_STATE(25)] = 762,
  [SMALL_STATE(26)] = 796,
  [SMALL_STATE(27)] = 818,
  [SMALL_STATE(28)] = 840,
  [SMALL_STATE(29)] = 872,
  [SMALL_STATE(30)] = 894,
  [SMALL_STATE(31)] = 916,
  [SMALL_STATE(32)] = 947,
  [SMALL_STATE(33)] = 978,
  [SMALL_STATE(34)] = 1009,
  [SMALL_STATE(35)] = 1040,
  [SMALL_STATE(36)] = 1066,
  [SMALL_STATE(37)] = 1089,
  [SMALL_STATE(38)] = 1114,
  [SMALL_STATE(39)] = 1137,
  [SMALL_STATE(40)] = 1155,
  [SMALL_STATE(41)] = 1173,
  [SMALL_STATE(42)] = 1191,
  [SMALL_STATE(43)] = 1209,
  [SMALL_STATE(44)] = 1227,
  [SMALL_STATE(45)] = 1245,
  [SMALL_STATE(46)] = 1263,
  [SMALL_STATE(47)] = 1281,
  [SMALL_STATE(48)] = 1299,
  [SMALL_STATE(49)] = 1317,
  [SMALL_STATE(50)] = 1335,
  [SMALL_STATE(51)] = 1351,
  [SMALL_STATE(52)] = 1369,
  [SMALL_STATE(53)] = 1387,
  [SMALL_STATE(54)] = 1405,
  [SMALL_STATE(55)] = 1423,
  [SMALL_STATE(56)] = 1439,
  [SMALL_STATE(57)] = 1457,
  [SMALL_STATE(58)] = 1484,
  [SMALL_STATE(59)] = 1511,
  [SMALL_STATE(60)] = 1526,
  [SMALL_STATE(61)] = 1541,
  [SMALL_STATE(62)] = 1568,
  [SMALL_STATE(63)] = 1595,
  [SMALL_STATE(64)] = 1622,
  [SMALL_STATE(65)] = 1651,
  [SMALL_STATE(66)] = 1675,
  [SMALL_STATE(67)] = 1698,
  [SMALL_STATE(68)] = 1721,
  [SMALL_STATE(69)] = 1744,
  [SMALL_STATE(70)] = 1767,
  [SMALL_STATE(71)] = 1790,
  [SMALL_STATE(72)] = 1809,
  [SMALL_STATE(73)] = 1830,
  [SMALL_STATE(74)] = 1853,
  [SMALL_STATE(75)] = 1874,
  [SMALL_STATE(76)] = 1895,
  [SMALL_STATE(77)] = 1911,
  [SMALL_STATE(78)] = 1929,
  [SMALL_STATE(79)] = 1949,
  [SMALL_STATE(80)] = 1967,
  [SMALL_STATE(81)] = 1985,
  [SMALL_STATE(82)] = 2003,
  [SMALL_STATE(83)] = 2021,
  [SMALL_STATE(84)] = 2035,
  [SMALL_STATE(85)] = 2052,
  [SMALL_STATE(86)] = 2067,
  [SMALL_STATE(87)] = 2080,
  [SMALL_STATE(88)] = 2093,
  [SMALL_STATE(89)] = 2108,
  [SMALL_STATE(90)] = 2123,
  [SMALL_STATE(91)] = 2140,
  [SMALL_STATE(92)] = 2157,
  [SMALL_STATE(93)] = 2172,
  [SMALL_STATE(94)] = 2187,
  [SMALL_STATE(95)] = 2204,
  [SMALL_STATE(96)] = 2217,
  [SMALL_STATE(97)] = 2234,
  [SMALL_STATE(98)] = 2247,
  [SMALL_STATE(99)] = 2264,
  [SMALL_STATE(100)] = 2275,
  [SMALL_STATE(101)] = 2288,
  [SMALL_STATE(102)] = 2303,
  [SMALL_STATE(103)] = 2316,
  [SMALL_STATE(104)] = 2327,
  [SMALL_STATE(105)] = 2338,
  [SMALL_STATE(106)] = 2349,
  [SMALL_STATE(107)] = 2359,
  [SMALL_STATE(108)] = 2371,
  [SMALL_STATE(109)] = 2385,
  [SMALL_STATE(110)] = 2397,
  [SMALL_STATE(111)] = 2407,
  [SMALL_STATE(112)] = 2417,
  [SMALL_STATE(113)] = 2427,
  [SMALL_STATE(114)] = 2437,
  [SMALL_STATE(115)] = 2449,
  [SMALL_STATE(116)] = 2463,
  [SMALL_STATE(117)] = 2473,
  [SMALL_STATE(118)] = 2483,
  [SMALL_STATE(119)] = 2493,
  [SMALL_STATE(120)] = 2503,
  [SMALL_STATE(121)] = 2517,
  [SMALL_STATE(122)] = 2531,
  [SMALL_STATE(123)] = 2545,
  [SMALL_STATE(124)] = 2559,
  [SMALL_STATE(125)] = 2573,
  [SMALL_STATE(126)] = 2587,
  [SMALL_STATE(127)] = 2599,
  [SMALL_STATE(128)] = 2613,
  [SMALL_STATE(129)] = 2627,
  [SMALL_STATE(130)] = 2641,
  [SMALL_STATE(131)] = 2653,
  [SMALL_STATE(132)] = 2663,
  [SMALL_STATE(133)] = 2677,
  [SMALL_STATE(134)] = 2691,
  [SMALL_STATE(135)] = 2703,
  [SMALL_STATE(136)] = 2717,
  [SMALL_STATE(137)] = 2731,
  [SMALL_STATE(138)] = 2743,
  [SMALL_STATE(139)] = 2757,
  [SMALL_STATE(140)] = 2769,
  [SMALL_STATE(141)] = 2783,
  [SMALL_STATE(142)] = 2793,
  [SMALL_STATE(143)] = 2807,
  [SMALL_STATE(144)] = 2819,
  [SMALL_STATE(145)] = 2833,
  [SMALL_STATE(146)] = 2843,
  [SMALL_STATE(147)] = 2855,
  [SMALL_STATE(148)] = 2869,
  [SMALL_STATE(149)] = 2883,
  [SMALL_STATE(150)] = 2897,
  [SMALL_STATE(151)] = 2911,
  [SMALL_STATE(152)] = 2921,
  [SMALL_STATE(153)] = 2935,
  [SMALL_STATE(154)] = 2946,
  [SMALL_STATE(155)] = 2955,
  [SMALL_STATE(156)] = 2964,
  [SMALL_STATE(157)] = 2973,
  [SMALL_STATE(158)] = 2982,
  [SMALL_STATE(159)] = 2993,
  [SMALL_STATE(160)] = 3002,
  [SMALL_STATE(161)] = 3013,
  [SMALL_STATE(162)] = 3022,
  [SMALL_STATE(163)] = 3031,
  [SMALL_STATE(164)] = 3042,
  [SMALL_STATE(165)] = 3051,
  [SMALL_STATE(166)] = 3062,
  [SMALL_STATE(167)] = 3071,
  [SMALL_STATE(168)] = 3080,
  [SMALL_STATE(169)] = 3089,
  [SMALL_STATE(170)] = 3098,
  [SMALL_STATE(171)] = 3109,
  [SMALL_STATE(172)] = 3118,
  [SMALL_STATE(173)] = 3127,
  [SMALL_STATE(174)] = 3136,
  [SMALL_STATE(175)] = 3145,
  [SMALL_STATE(176)] = 3156,
  [SMALL_STATE(177)] = 3165,
  [SMALL_STATE(178)] = 3176,
  [SMALL_STATE(179)] = 3185,
  [SMALL_STATE(180)] = 3194,
  [SMALL_STATE(181)] = 3203,
  [SMALL_STATE(182)] = 3214,
  [SMALL_STATE(183)] = 3223,
  [SMALL_STATE(184)] = 3232,
  [SMALL_STATE(185)] = 3240,
  [SMALL_STATE(186)] = 3248,
  [SMALL_STATE(187)] = 3256,
  [SMALL_STATE(188)] = 3264,
  [SMALL_STATE(189)] = 3272,
  [SMALL_STATE(190)] = 3280,
  [SMALL_STATE(191)] = 3288,
  [SMALL_STATE(192)] = 3296,
  [SMALL_STATE(193)] = 3304,
  [SMALL_STATE(194)] = 3312,
  [SMALL_STATE(195)] = 3320,
  [SMALL_STATE(196)] = 3328,
  [SMALL_STATE(197)] = 3336,
  [SMALL_STATE(198)] = 3344,
  [SMALL_STATE(199)] = 3352,
  [SMALL_STATE(200)] = 3360,
  [SMALL_STATE(201)] = 3368,
  [SMALL_STATE(202)] = 3376,
  [SMALL_STATE(203)] = 3384,
  [SMALL_STATE(204)] = 3392,
  [SMALL_STATE(205)] = 3400,
  [SMALL_STATE(206)] = 3408,
  [SMALL_STATE(207)] = 3416,
  [SMALL_STATE(208)] = 3424,
  [SMALL_STATE(209)] = 3432,
  [SMALL_STATE(210)] = 3440,
  [SMALL_STATE(211)] = 3448,
  [SMALL_STATE(212)] = 3456,
  [SMALL_STATE(213)] = 3464,
  [SMALL_STATE(214)] = 3472,
  [SMALL_STATE(215)] = 3480,
  [SMALL_STATE(216)] = 3488,
  [SMALL_STATE(217)] = 3496,
  [SMALL_STATE(218)] = 3504,
  [SMALL_STATE(219)] = 3512,
  [SMALL_STATE(220)] = 3520,
  [SMALL_STATE(221)] = 3528,
  [SMALL_STATE(222)] = 3536,
  [SMALL_STATE(223)] = 3544,
  [SMALL_STATE(224)] = 3552,
  [SMALL_STATE(225)] = 3560,
  [SMALL_STATE(226)] = 3568,
  [SMALL_STATE(227)] = 3576,
  [SMALL_STATE(228)] = 3584,
  [SMALL_STATE(229)] = 3592,
  [SMALL_STATE(230)] = 3600,
  [SMALL_STATE(231)] = 3608,
  [SMALL_STATE(232)] = 3616,
  [SMALL_STATE(233)] = 3624,
  [SMALL_STATE(234)] = 3632,
  [SMALL_STATE(235)] = 3640,
  [SMALL_STATE(236)] = 3648,
  [SMALL_STATE(237)] = 3656,
  [SMALL_STATE(238)] = 3664,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(197),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(177),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(224),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(226),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(181),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(237),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(188),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(82),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(197),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(177),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(224),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(226),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(181),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(237),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(188),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [92] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(158),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(158),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(212),
  [101] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [104] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(165),
  [107] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(162),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [113] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(169),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_erase_slot, 4, 0, 28),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 4, 0, 28),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_run_script, 3, 0, 13),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 3, 0, 13),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_blocking_delay, 3, 0, 14),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 3, 0, 14),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 14),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 14),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_slot, 4, 0, 28),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 4, 0, 28),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_map, 4, 0, 29),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 4, 0, 29),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_label, 4, 0, 30),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 4, 0, 30),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_index, 4, 0, 31),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 4, 0, 31),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 34),
  [192] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 34), SHIFT_REPEAT(166),
  [195] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 34), SHIFT_REPEAT(116),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_definition, 2, 0, 6),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_definition, 2, 0, 6),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [224] = {.entry = {.count = 1, .reusable = false}}, SHIFT(187),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 7),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 7),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [264] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 16),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 16),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 1, 0, 24),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 3, 0, 26),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 3, 0, 26),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 15),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [300] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 25),
  [312] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 25),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 22),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 35),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 35),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [328] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(202),
  [331] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(173),
  [334] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [343] = {.entry = {.count = 1, .reusable = false}}, SHIFT(190),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [349] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [351] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [353] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 18),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [361] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [363] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 27), SHIFT_REPEAT(60),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 27),
  [368] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 27), SHIFT_REPEAT(159),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 37),
  [375] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 37), SHIFT_REPEAT(83),
  [378] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 37),
  [380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 38),
  [382] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 38),
  [384] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 11),
  [386] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 40),
  [388] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 40),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 41),
  [392] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 41),
  [394] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 41), SHIFT_REPEAT(221),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 17),
  [403] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 17), SHIFT_REPEAT(176),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [408] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [410] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(176),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 23),
  [423] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 23),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(168),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [449] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 32),
  [451] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 33),
  [453] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 33), SHIFT_REPEAT(220),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [458] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 20), SHIFT_REPEAT(118),
  [461] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 20),
  [463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 21),
  [465] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [479] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 3, 0, 39),
  [481] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 36),
  [483] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 36),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 47),
  [489] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 47),
  [491] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 43),
  [493] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 44),
  [495] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 5, 0, 46),
  [497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [499] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [511] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_entity, 1, 0, 0),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [515] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 15),
  [517] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 8),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [527] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 9),
  [529] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [551] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 12),
  [553] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 12),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [567] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [571] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [574] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [578] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [580] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [582] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(145),
  [585] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [595] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [597] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(148),
  [600] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [602] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [604] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(163),
  [607] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [609] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [611] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(182),
  [614] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [618] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(183),
  [621] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [633] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(157),
  [636] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [642] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [644] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 10),
  [646] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [650] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [652] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 19),
  [654] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [656] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [658] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [660] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [662] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [664] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 42),
  [666] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_label, 1, 0, 0),
  [668] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter_int, 1, 0, 0),
  [670] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 45),
  [672] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [674] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [676] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [678] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [680] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [682] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [688] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [690] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [692] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [694] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [696] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [700] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [702] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [704] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [706] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [712] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [714] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [716] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [718] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [720] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [722] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [724] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [726] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [728] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [734] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [736] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [738] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 8),
  [740] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [742] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [744] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [746] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [748] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [750] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [752] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [754] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [756] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [758] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [760] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [762] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [764] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [766] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 8),
  [768] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [770] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [772] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [774] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [778] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [780] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [782] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
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
