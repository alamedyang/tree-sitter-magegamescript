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
#define STATE_COUNT 262
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 136
#define ALIAS_COUNT 0
#define TOKEN_COUNT 61
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 25
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 54

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
  anon_sym_show = 59,
  anon_sym_concat = 60,
  sym_document = 61,
  sym_bareword_expansion = 62,
  sym_quoted_string_expansion = 63,
  sym_string_expansion = 64,
  sym_number_expansion = 65,
  sym_DURATION = 66,
  sym_duration_expansion = 67,
  sym_DISTANCE = 68,
  sym_QUANTITY = 69,
  sym__root = 70,
  sym_include_macro = 71,
  sym_constant_assignment = 72,
  sym_add_serial_dialog_settings = 73,
  sym_serial_dialog_parameter_int = 74,
  sym_serial_dialog_parameter = 75,
  sym_add_dialog_settings = 76,
  sym_target_label = 77,
  sym_target_entity = 78,
  sym_add_dialog_settings_target = 79,
  sym__dialog_parameter_int = 80,
  sym__dialog_parameter_string = 81,
  sym_dialog_parameter = 82,
  sym_dialog_definition = 83,
  sym__dialog_block = 84,
  sym_dialog = 85,
  sym_dialog_identifier = 86,
  sym_dialog_option = 87,
  sym_serial_dialog_definition = 88,
  sym__serial_dialog_block = 89,
  sym_serial_dialog = 90,
  sym_serial_dialog_option = 91,
  sym_script_definition = 92,
  sym_script_block = 93,
  sym__script_item = 94,
  sym_json_literal = 95,
  sym_json_array = 96,
  sym_json_object = 97,
  sym_json_name_value_pair = 98,
  sym__json_item = 99,
  sym_rand_macro = 100,
  sym_label_definition = 101,
  sym__action_item = 102,
  sym_action_return_statement = 103,
  sym_action_close_dialog = 104,
  sym_action_close_serial_dialog = 105,
  sym_action_save_slot = 106,
  sym_action_load_slot = 107,
  sym_action_erase_slot = 108,
  sym_action_load_map = 109,
  sym_action_run_script = 110,
  sym_action_goto_label = 111,
  sym_action_goto_index = 112,
  sym_action_non_blocking_delay = 113,
  sym_action_blocking_delay = 114,
  sym_action_show_dialog = 115,
  sym_action_show_serial_dialog = 116,
  sym_action_concat_serial_dialog = 117,
  aux_sym_document_repeat1 = 118,
  aux_sym_bareword_expansion_repeat1 = 119,
  aux_sym_quoted_string_expansion_repeat1 = 120,
  aux_sym_string_expansion_repeat1 = 121,
  aux_sym_number_expansion_repeat1 = 122,
  aux_sym_duration_expansion_repeat1 = 123,
  aux_sym_add_serial_dialog_settings_repeat1 = 124,
  aux_sym_add_dialog_settings_repeat1 = 125,
  aux_sym_add_dialog_settings_target_repeat1 = 126,
  aux_sym__dialog_block_repeat1 = 127,
  aux_sym_dialog_repeat1 = 128,
  aux_sym_dialog_repeat2 = 129,
  aux_sym_serial_dialog_repeat1 = 130,
  aux_sym_serial_dialog_repeat2 = 131,
  aux_sym_serial_dialog_repeat3 = 132,
  aux_sym_script_block_repeat1 = 133,
  aux_sym_json_array_repeat1 = 134,
  aux_sym_json_object_repeat1 = 135,
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
  [anon_sym_show] = "show",
  [anon_sym_concat] = "concat",
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
  [sym_action_show_dialog] = "action_show_dialog",
  [sym_action_show_serial_dialog] = "action_show_serial_dialog",
  [sym_action_concat_serial_dialog] = "action_concat_serial_dialog",
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
  [anon_sym_show] = anon_sym_show,
  [anon_sym_concat] = anon_sym_concat,
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
  [sym_action_show_dialog] = sym_action_show_dialog,
  [sym_action_show_serial_dialog] = sym_action_show_serial_dialog,
  [sym_action_concat_serial_dialog] = sym_action_concat_serial_dialog,
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
  [anon_sym_show] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_concat] = {
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
  [sym_action_show_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_action_show_serial_dialog] = {
    .visible = true,
    .named = true,
  },
  [sym_action_concat_serial_dialog] = {
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
  [32] = {.index = 42, .length = 1},
  [33] = {.index = 43, .length = 1},
  [34] = {.index = 44, .length = 1},
  [35] = {.index = 45, .length = 1},
  [36] = {.index = 46, .length = 3},
  [37] = {.index = 49, .length = 2},
  [38] = {.index = 51, .length = 2},
  [39] = {.index = 53, .length = 3},
  [40] = {.index = 56, .length = 1},
  [41] = {.index = 57, .length = 2},
  [42] = {.index = 59, .length = 3},
  [43] = {.index = 62, .length = 2},
  [44] = {.index = 64, .length = 2},
  [45] = {.index = 66, .length = 1},
  [46] = {.index = 67, .length = 4},
  [47] = {.index = 71, .length = 2},
  [48] = {.index = 73, .length = 2},
  [49] = {.index = 75, .length = 2},
  [50] = {.index = 77, .length = 2},
  [51] = {.index = 79, .length = 3},
  [52] = {.index = 82, .length = 3},
  [53] = {.index = 85, .length = 2},
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
    {field_serial_dialog_name, 2},
  [43] =
    {field_serial_dialog, 2, .inherited = true},
  [44] =
    {field_dialog_name, 2},
  [45] =
    {field_dialog, 2, .inherited = true},
  [46] =
    {field_serial_dialog_option, 2, .inherited = true},
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [49] =
    {field_serial_dialog_option, 0, .inherited = true},
    {field_serial_dialog_option, 1, .inherited = true},
  [51] =
    {field_dialog_parameter, 0, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
  [53] =
    {field_dialog_identifier, 0},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [56] =
    {field_dialog_option, 0},
  [57] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [59] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 2, .inherited = true},
    {field_message, 1, .inherited = true},
  [62] =
    {field_serial_dialog, 3, .inherited = true},
    {field_serial_dialog_name, 2},
  [64] =
    {field_dialog, 3, .inherited = true},
    {field_dialog_name, 2},
  [66] =
    {field_type, 0},
  [67] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 3, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [71] =
    {field_dialog_option, 0, .inherited = true},
    {field_dialog_option, 1, .inherited = true},
  [73] =
    {field_property, 0},
    {field_value, 2},
  [75] =
    {field_dialog_parameter, 2, .inherited = true},
    {field_type, 0},
  [77] =
    {field_target, 1},
    {field_type, 0},
  [79] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [82] =
    {field_dialog_parameter, 3, .inherited = true},
    {field_target, 1},
    {field_type, 0},
  [85] =
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
  [239] = 239,
  [240] = 240,
  [241] = 241,
  [242] = 242,
  [243] = 243,
  [244] = 244,
  [245] = 245,
  [246] = 246,
  [247] = 247,
  [248] = 248,
  [249] = 249,
  [250] = 250,
  [251] = 251,
  [252] = 252,
  [253] = 253,
  [254] = 254,
  [255] = 255,
  [256] = 256,
  [257] = 257,
  [258] = 258,
  [259] = 259,
  [260] = 260,
  [261] = 261,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(199);
      ADVANCE_MAP(
        '!', 388,
        '"', 6,
        '#', 375,
        '$', 195,
        '(', 389,
        ')', 390,
        ',', 336,
        '-', 12,
        '/', 8,
        ':', 380,
        ';', 352,
        '=', 353,
        '>', 373,
        'I', 118,
        '[', 335,
        ']', 337,
        '_', 374,
        'a', 43,
        'b', 100,
        'c', 101,
        'd', 63,
        'e', 115,
        'f', 15,
        'g', 136,
        'i', 119,
        'j', 158,
        'l', 17,
        'm', 19,
        'n', 20,
        'o', 120,
        'p', 83,
        'r', 30,
        's', 341,
        't', 81,
        'w', 26,
        'x', 343,
        'y', 71,
        '{', 359,
        '}', 360,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(197);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(339);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 6,
        '#', 192,
        '$', 195,
        '/', 8,
        'b', 274,
        'c', 280,
        'f', 217,
        'g', 310,
        'm', 213,
        'o', 254,
        'r', 249,
        't', 259,
        'w', 260,
        'y', 248,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(339);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 6,
        '$', 195,
        '/', 8,
        '>', 373,
        '[', 335,
        ']', 337,
        'e', 292,
        'n', 208,
        '{', 359,
        '}', 360,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(195);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '[') ADVANCE(335);
      if (lookahead == 'i') ADVANCE(293);
      if (lookahead == 'l') ADVANCE(209);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 6,
        ',', 336,
        '-', 12,
        '/', 8,
        ';', 352,
        'I', 118,
        '[', 335,
        ']', 337,
        'a', 99,
        'b', 131,
        'd', 62,
        'e', 114,
        'f', 15,
        'l', 16,
        'm', 156,
        'n', 20,
        'p', 83,
        's', 340,
        't', 146,
        'w', 151,
        'x', 343,
        '{', 359,
        '}', 360,
        '#', 374,
        '_', 374,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(382);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '"', 6,
        ',', 336,
        '-', 12,
        '/', 8,
        ';', 352,
        'I', 118,
        '[', 335,
        ']', 337,
        'a', 99,
        'b', 131,
        'd', 62,
        'e', 114,
        'f', 15,
        'l', 16,
        'n', 20,
        'p', 135,
        't', 146,
        'w', 151,
        '{', 359,
        '}', 360,
        '#', 374,
        '_', 374,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(382);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(338);
      if (lookahead == '\\') ADVANCE(196);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        ')', 390,
        ',', 336,
        '/', 8,
        ']', 337,
        'b', 276,
        'c', 277,
        'e', 307,
        'g', 299,
        'j', 314,
        'l', 303,
        'r', 210,
        's', 207,
        'w', 211,
        '}', 360,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(201);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(200);
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
      if (lookahead == 'd') ADVANCE(94);
      if (lookahead == 'm') ADVANCE(29);
      if (lookahead == 's') ADVANCE(51);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == 'I') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(382);
      END_STATE();
    case 13:
      if (lookahead == '_') ADVANCE(50);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(176);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(113);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(37);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(37);
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(80);
      if (lookahead == 's') ADVANCE(340);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(116);
      if (lookahead == 'u') ADVANCE(106);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(185);
      if (lookahead == 'c') ADVANCE(152);
      if (lookahead == 'e') ADVANCE(153);
      if (lookahead == 'h') ADVANCE(132);
      if (lookahead == 'l') ADVANCE(141);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(345);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(144);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(38);
      if (lookahead == 'o') ADVANCE(39);
      if (lookahead == 'u') ADVANCE(52);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(46);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(86);
      if (lookahead == 'h') ADVANCE(87);
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(107);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(182);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(143);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(125);
      if (lookahead == 'e') ADVANCE(45);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(121);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(166);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(160);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(109);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(93);
      END_STATE();
    case 37:
      if (lookahead == 'b') ADVANCE(67);
      END_STATE();
    case 38:
      if (lookahead == 'c') ADVANCE(97);
      END_STATE();
    case 39:
      if (lookahead == 'c') ADVANCE(98);
      END_STATE();
    case 40:
      if (lookahead == 'c') ADVANCE(105);
      if (lookahead == 'd') ADVANCE(64);
      END_STATE();
    case 41:
      if (lookahead == 'c') ADVANCE(54);
      END_STATE();
    case 42:
      if (lookahead == 'c') ADVANCE(33);
      END_STATE();
    case 43:
      if (lookahead == 'd') ADVANCE(44);
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 44:
      if (lookahead == 'd') ADVANCE(354);
      END_STATE();
    case 45:
      if (lookahead == 'd') ADVANCE(345);
      if (lookahead == 't') ADVANCE(181);
      END_STATE();
    case 46:
      if (lookahead == 'd') ADVANCE(398);
      END_STATE();
    case 47:
      if (lookahead == 'd') ADVANCE(386);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(68);
      END_STATE();
    case 49:
      if (lookahead == 'd') ADVANCE(61);
      END_STATE();
    case 50:
      if (lookahead == 'd') ADVANCE(96);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(153);
      if (lookahead == 'l') ADVANCE(141);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(345);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(369);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(344);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(395);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(383);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(393);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(368);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(400);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(384);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(350);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(75);
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(189);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(121);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(103);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(147);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(127);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(171);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(112);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(128);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(162);
      END_STATE();
    case 74:
      if (lookahead == 'f') ADVANCE(88);
      END_STATE();
    case 75:
      if (lookahead == 'f') ADVANCE(28);
      END_STATE();
    case 76:
      if (lookahead == 'g') ADVANCE(362);
      END_STATE();
    case 77:
      if (lookahead == 'g') ADVANCE(356);
      END_STATE();
    case 78:
      if (lookahead == 'g') ADVANCE(157);
      END_STATE();
    case 79:
      if (lookahead == 'g') ADVANCE(129);
      END_STATE();
    case 80:
      if (lookahead == 'g') ADVANCE(69);
      if (lookahead == 'p') ADVANCE(402);
      END_STATE();
    case 81:
      if (lookahead == 'h') ADVANCE(149);
      if (lookahead == 'r') ADVANCE(183);
      if (lookahead == 'w') ADVANCE(82);
      END_STATE();
    case 82:
      if (lookahead == 'i') ADVANCE(41);
      END_STATE();
    case 83:
      if (lookahead == 'i') ADVANCE(188);
      if (lookahead == 'o') ADVANCE(150);
      if (lookahead == 'x') ADVANCE(342);
      END_STATE();
    case 84:
      if (lookahead == 'i') ADVANCE(79);
      END_STATE();
    case 85:
      if (lookahead == 'i') ADVANCE(145);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(164);
      END_STATE();
    case 87:
      if (lookahead == 'i') ADVANCE(173);
      END_STATE();
    case 88:
      if (lookahead == 'i') ADVANCE(130);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(165);
      END_STATE();
    case 90:
      if (lookahead == 'i') ADVANCE(111);
      END_STATE();
    case 91:
      if (lookahead == 'i') ADVANCE(124);
      END_STATE();
    case 92:
      if (lookahead == 'i') ADVANCE(172);
      END_STATE();
    case 93:
      if (lookahead == 'i') ADVANCE(169);
      END_STATE();
    case 94:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 95:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 96:
      if (lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 97:
      if (lookahead == 'k') ADVANCE(345);
      END_STATE();
    case 98:
      if (lookahead == 'k') ADVANCE(409);
      END_STATE();
    case 99:
      if (lookahead == 'l') ADVANCE(84);
      END_STATE();
    case 100:
      if (lookahead == 'l') ADVANCE(24);
      if (lookahead == 'o') ADVANCE(148);
      END_STATE();
    case 101:
      if (lookahead == 'l') ADVANCE(134);
      if (lookahead == 'o') ADVANCE(126);
      if (lookahead == 'y') ADVANCE(31);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(385);
      END_STATE();
    case 103:
      if (lookahead == 'l') ADVANCE(365);
      END_STATE();
    case 104:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 105:
      if (lookahead == 'l') ADVANCE(184);
      END_STATE();
    case 106:
      if (lookahead == 'l') ADVANCE(102);
      END_STATE();
    case 107:
      if (lookahead == 'l') ADVANCE(137);
      END_STATE();
    case 108:
      if (lookahead == 'l') ADVANCE(138);
      END_STATE();
    case 109:
      if (lookahead == 'l') ADVANCE(140);
      END_STATE();
    case 110:
      if (lookahead == 'l') ADVANCE(168);
      END_STATE();
    case 111:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 112:
      if (lookahead == 'l') ADVANCE(108);
      END_STATE();
    case 113:
      if (lookahead == 'l') ADVANCE(161);
      END_STATE();
    case 114:
      if (lookahead == 'm') ADVANCE(139);
      if (lookahead == 'n') ADVANCE(180);
      END_STATE();
    case 115:
      if (lookahead == 'm') ADVANCE(139);
      if (lookahead == 'n') ADVANCE(180);
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 116:
      if (lookahead == 'm') ADVANCE(53);
      END_STATE();
    case 117:
      if (lookahead == 'm') ADVANCE(72);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(74);
      END_STATE();
    case 119:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 120:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 121:
      if (lookahead == 'n') ADVANCE(345);
      END_STATE();
    case 122:
      if (lookahead == 'n') ADVANCE(378);
      END_STATE();
    case 123:
      if (lookahead == 'n') ADVANCE(391);
      END_STATE();
    case 124:
      if (lookahead == 'n') ADVANCE(78);
      END_STATE();
    case 125:
      if (lookahead == 'n') ADVANCE(47);
      END_STATE();
    case 126:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 127:
      if (lookahead == 'n') ADVANCE(177);
      END_STATE();
    case 128:
      if (lookahead == 'n') ADVANCE(170);
      END_STATE();
    case 129:
      if (lookahead == 'n') ADVANCE(117);
      END_STATE();
    case 130:
      if (lookahead == 'n') ADVANCE(92);
      END_STATE();
    case 131:
      if (lookahead == 'o') ADVANCE(148);
      END_STATE();
    case 132:
      if (lookahead == 'o') ADVANCE(187);
      END_STATE();
    case 133:
      if (lookahead == 'o') ADVANCE(403);
      END_STATE();
    case 134:
      if (lookahead == 'o') ADVANCE(159);
      END_STATE();
    case 135:
      if (lookahead == 'o') ADVANCE(150);
      END_STATE();
    case 136:
      if (lookahead == 'o') ADVANCE(175);
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 137:
      if (lookahead == 'o') ADVANCE(76);
      END_STATE();
    case 138:
      if (lookahead == 'o') ADVANCE(186);
      END_STATE();
    case 139:
      if (lookahead == 'o') ADVANCE(178);
      END_STATE();
    case 140:
      if (lookahead == 'o') ADVANCE(77);
      END_STATE();
    case 141:
      if (lookahead == 'o') ADVANCE(163);
      END_STATE();
    case 142:
      if (lookahead == 'o') ADVANCE(122);
      END_STATE();
    case 143:
      if (lookahead == 'p') ADVANCE(402);
      END_STATE();
    case 144:
      if (lookahead == 'p') ADVANCE(361);
      END_STATE();
    case 145:
      if (lookahead == 'p') ADVANCE(167);
      END_STATE();
    case 146:
      if (lookahead == 'r') ADVANCE(183);
      END_STATE();
    case 147:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 148:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 149:
      if (lookahead == 'r') ADVANCE(82);
      END_STATE();
    case 150:
      if (lookahead == 'r') ADVANCE(174);
      END_STATE();
    case 151:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 152:
      if (lookahead == 'r') ADVANCE(85);
      END_STATE();
    case 153:
      if (lookahead == 'r') ADVANCE(95);
      if (lookahead == 't') ADVANCE(179);
      END_STATE();
    case 154:
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 155:
      if (lookahead == 'r') ADVANCE(123);
      END_STATE();
    case 156:
      if (lookahead == 's') ADVANCE(340);
      END_STATE();
    case 157:
      if (lookahead == 's') ADVANCE(358);
      END_STATE();
    case 158:
      if (lookahead == 's') ADVANCE(142);
      END_STATE();
    case 159:
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 160:
      if (lookahead == 's') ADVANCE(59);
      END_STATE();
    case 161:
      if (lookahead == 's') ADVANCE(60);
      END_STATE();
    case 162:
      if (lookahead == 's') ADVANCE(70);
      END_STATE();
    case 163:
      if (lookahead == 't') ADVANCE(397);
      END_STATE();
    case 164:
      if (lookahead == 't') ADVANCE(407);
      END_STATE();
    case 165:
      if (lookahead == 't') ADVANCE(190);
      END_STATE();
    case 166:
      if (lookahead == 't') ADVANCE(413);
      END_STATE();
    case 167:
      if (lookahead == 't') ADVANCE(376);
      END_STATE();
    case 168:
      if (lookahead == 't') ADVANCE(364);
      END_STATE();
    case 169:
      if (lookahead == 't') ADVANCE(370);
      END_STATE();
    case 170:
      if (lookahead == 't') ADVANCE(371);
      END_STATE();
    case 171:
      if (lookahead == 't') ADVANCE(372);
      END_STATE();
    case 172:
      if (lookahead == 't') ADVANCE(191);
      END_STATE();
    case 173:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 174:
      if (lookahead == 't') ADVANCE(154);
      END_STATE();
    case 175:
      if (lookahead == 't') ADVANCE(133);
      END_STATE();
    case 176:
      if (lookahead == 't') ADVANCE(90);
      END_STATE();
    case 177:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 178:
      if (lookahead == 't') ADVANCE(58);
      END_STATE();
    case 179:
      if (lookahead == 't') ADVANCE(91);
      END_STATE();
    case 180:
      if (lookahead == 't') ADVANCE(89);
      END_STATE();
    case 181:
      if (lookahead == 'u') ADVANCE(155);
      END_STATE();
    case 182:
      if (lookahead == 'u') ADVANCE(110);
      END_STATE();
    case 183:
      if (lookahead == 'u') ADVANCE(56);
      END_STATE();
    case 184:
      if (lookahead == 'u') ADVANCE(49);
      END_STATE();
    case 185:
      if (lookahead == 'v') ADVANCE(55);
      END_STATE();
    case 186:
      if (lookahead == 'w') ADVANCE(345);
      END_STATE();
    case 187:
      if (lookahead == 'w') ADVANCE(411);
      END_STATE();
    case 188:
      if (lookahead == 'x') ADVANCE(342);
      END_STATE();
    case 189:
      if (lookahead == 'x') ADVANCE(405);
      END_STATE();
    case 190:
      if (lookahead == 'y') ADVANCE(367);
      END_STATE();
    case 191:
      if (lookahead == 'y') ADVANCE(381);
      END_STATE();
    case 192:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(194);
      END_STATE();
    case 193:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(348);
      END_STATE();
    case 194:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(193);
      END_STATE();
    case 195:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(349);
      END_STATE();
    case 196:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 197:
      if (eof) ADVANCE(199);
      ADVANCE_MAP(
        '!', 388,
        '"', 6,
        '#', 375,
        '$', 195,
        '(', 389,
        ')', 390,
        ',', 336,
        '-', 12,
        '/', 8,
        ':', 380,
        ';', 352,
        '=', 353,
        '>', 373,
        'I', 118,
        '[', 335,
        ']', 337,
        '_', 374,
        'a', 43,
        'b', 100,
        'c', 101,
        'd', 63,
        'e', 115,
        'f', 15,
        'g', 136,
        'i', 119,
        'j', 158,
        'l', 17,
        'm', 18,
        'n', 20,
        'o', 120,
        'p', 135,
        'r', 30,
        's', 21,
        't', 81,
        'w', 26,
        'y', 71,
        '{', 359,
        '}', 360,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(197);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(339);
      END_STATE();
    case 198:
      if (eof) ADVANCE(199);
      ADVANCE_MAP(
        '"', 6,
        '$', 195,
        '/', 8,
        ';', 352,
        '[', 335,
        ']', 337,
        'a', 234,
        'd', 261,
        'i', 285,
        's', 222,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(198);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(339);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(201);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(329);
      if (lookahead == 'h') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(290);
      if (lookahead == 'e') ADVANCE(321);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(225);
      if (lookahead == 'u') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(319);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(306);
      if (lookahead == 'e') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(355);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(399);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(401);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(332);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(281);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(255);
      if (lookahead == 'n') ADVANCE(202);
      if (lookahead == 'p') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(363);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(357);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(308);
      if (lookahead == 'r') ADVANCE(328);
      if (lookahead == 'w') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(410);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(300);
      if (lookahead == 'o') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(304);
      if (lookahead == 'y') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(278);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(392);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(325);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(331);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(404);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(323);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(414);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(327);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(266);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(412);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(406);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(339);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(185);
      if (lookahead == 'c') ADVANCE(152);
      if (lookahead == 'e') ADVANCE(153);
      if (lookahead == 'h') ADVANCE(132);
      if (lookahead == 'l') ADVANCE(141);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(345);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(346);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(347);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(349);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_target_default);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(194);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(382);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(anon_sym_concat);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(anon_sym_concat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(334);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 198},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 7},
  [5] = {.lex_state = 7},
  [6] = {.lex_state = 7},
  [7] = {.lex_state = 198},
  [8] = {.lex_state = 198},
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
  [21] = {.lex_state = 7},
  [22] = {.lex_state = 7},
  [23] = {.lex_state = 7},
  [24] = {.lex_state = 7},
  [25] = {.lex_state = 7},
  [26] = {.lex_state = 7},
  [27] = {.lex_state = 7},
  [28] = {.lex_state = 7},
  [29] = {.lex_state = 7},
  [30] = {.lex_state = 7},
  [31] = {.lex_state = 7},
  [32] = {.lex_state = 7},
  [33] = {.lex_state = 7},
  [34] = {.lex_state = 7},
  [35] = {.lex_state = 7},
  [36] = {.lex_state = 7},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 4},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 4},
  [42] = {.lex_state = 4},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 198},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 198},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 198},
  [51] = {.lex_state = 198},
  [52] = {.lex_state = 198},
  [53] = {.lex_state = 198},
  [54] = {.lex_state = 198},
  [55] = {.lex_state = 198},
  [56] = {.lex_state = 198},
  [57] = {.lex_state = 198},
  [58] = {.lex_state = 198},
  [59] = {.lex_state = 198},
  [60] = {.lex_state = 198},
  [61] = {.lex_state = 4},
  [62] = {.lex_state = 198},
  [63] = {.lex_state = 4},
  [64] = {.lex_state = 198},
  [65] = {.lex_state = 198},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 4},
  [68] = {.lex_state = 4},
  [69] = {.lex_state = 4},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 4},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 3},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 4},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 198},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 198},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 2},
  [94] = {.lex_state = 4},
  [95] = {.lex_state = 4},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 198},
  [98] = {.lex_state = 198},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 4},
  [101] = {.lex_state = 4},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 198},
  [104] = {.lex_state = 2},
  [105] = {.lex_state = 198},
  [106] = {.lex_state = 4},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 4},
  [109] = {.lex_state = 2},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 198},
  [112] = {.lex_state = 4},
  [113] = {.lex_state = 4},
  [114] = {.lex_state = 4},
  [115] = {.lex_state = 2},
  [116] = {.lex_state = 4},
  [117] = {.lex_state = 2},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 2},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 2},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 2},
  [127] = {.lex_state = 198},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 4},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 2},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 198},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 2},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 198},
  [153] = {.lex_state = 2},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 2},
  [156] = {.lex_state = 2},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 198},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 2},
  [162] = {.lex_state = 2},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 198},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 2},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 2},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 2},
  [171] = {.lex_state = 198},
  [172] = {.lex_state = 198},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 0},
  [175] = {.lex_state = 4},
  [176] = {.lex_state = 2},
  [177] = {.lex_state = 11},
  [178] = {.lex_state = 11},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 198},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 2},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 11},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 11},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 4},
  [197] = {.lex_state = 198},
  [198] = {.lex_state = 2},
  [199] = {.lex_state = 2},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 11},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 11},
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
  [228] = {.lex_state = 11},
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
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 0},
  [248] = {.lex_state = 0},
  [249] = {.lex_state = 0},
  [250] = {.lex_state = 0},
  [251] = {.lex_state = 0},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 0},
  [254] = {.lex_state = 0},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 0},
  [257] = {.lex_state = 0},
  [258] = {.lex_state = 0},
  [259] = {.lex_state = 11},
  [260] = {.lex_state = 0},
  [261] = {.lex_state = 0},
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
    [anon_sym_show] = ACTIONS(1),
    [anon_sym_concat] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(217),
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
  [0] = 16,
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
    ACTIONS(58), 1,
      anon_sym_show,
    ACTIONS(61), 1,
      anon_sym_concat,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(26), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(2), 21,
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
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      aux_sym_script_block_repeat1,
  [71] = 16,
    ACTIONS(64), 1,
      sym_BAREWORD,
    ACTIONS(66), 1,
      anon_sym_RBRACE,
    ACTIONS(68), 1,
      anon_sym_json,
    ACTIONS(70), 1,
      anon_sym_rand,
    ACTIONS(72), 1,
      anon_sym_return,
    ACTIONS(74), 1,
      anon_sym_close,
    ACTIONS(76), 1,
      anon_sym_save,
    ACTIONS(78), 1,
      anon_sym_load,
    ACTIONS(80), 1,
      anon_sym_erase,
    ACTIONS(82), 1,
      anon_sym_goto,
    ACTIONS(84), 1,
      anon_sym_wait,
    ACTIONS(86), 1,
      anon_sym_block,
    ACTIONS(88), 1,
      anon_sym_show,
    ACTIONS(90), 1,
      anon_sym_concat,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(4), 21,
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
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      aux_sym_script_block_repeat1,
  [141] = 16,
    ACTIONS(64), 1,
      sym_BAREWORD,
    ACTIONS(68), 1,
      anon_sym_json,
    ACTIONS(70), 1,
      anon_sym_rand,
    ACTIONS(72), 1,
      anon_sym_return,
    ACTIONS(74), 1,
      anon_sym_close,
    ACTIONS(76), 1,
      anon_sym_save,
    ACTIONS(78), 1,
      anon_sym_load,
    ACTIONS(80), 1,
      anon_sym_erase,
    ACTIONS(82), 1,
      anon_sym_goto,
    ACTIONS(84), 1,
      anon_sym_wait,
    ACTIONS(86), 1,
      anon_sym_block,
    ACTIONS(88), 1,
      anon_sym_show,
    ACTIONS(90), 1,
      anon_sym_concat,
    ACTIONS(92), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 21,
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
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      aux_sym_script_block_repeat1,
  [211] = 16,
    ACTIONS(64), 1,
      sym_BAREWORD,
    ACTIONS(68), 1,
      anon_sym_json,
    ACTIONS(70), 1,
      anon_sym_rand,
    ACTIONS(72), 1,
      anon_sym_return,
    ACTIONS(74), 1,
      anon_sym_close,
    ACTIONS(76), 1,
      anon_sym_save,
    ACTIONS(78), 1,
      anon_sym_load,
    ACTIONS(80), 1,
      anon_sym_erase,
    ACTIONS(82), 1,
      anon_sym_goto,
    ACTIONS(84), 1,
      anon_sym_wait,
    ACTIONS(86), 1,
      anon_sym_block,
    ACTIONS(88), 1,
      anon_sym_show,
    ACTIONS(90), 1,
      anon_sym_concat,
    ACTIONS(94), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 21,
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
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      aux_sym_script_block_repeat1,
  [281] = 16,
    ACTIONS(64), 1,
      sym_BAREWORD,
    ACTIONS(68), 1,
      anon_sym_json,
    ACTIONS(70), 1,
      anon_sym_rand,
    ACTIONS(72), 1,
      anon_sym_return,
    ACTIONS(74), 1,
      anon_sym_close,
    ACTIONS(76), 1,
      anon_sym_save,
    ACTIONS(78), 1,
      anon_sym_load,
    ACTIONS(80), 1,
      anon_sym_erase,
    ACTIONS(82), 1,
      anon_sym_goto,
    ACTIONS(84), 1,
      anon_sym_wait,
    ACTIONS(86), 1,
      anon_sym_block,
    ACTIONS(88), 1,
      anon_sym_show,
    ACTIONS(90), 1,
      anon_sym_concat,
    ACTIONS(96), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(5), 21,
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
      sym_action_show_dialog,
      sym_action_show_serial_dialog,
      sym_action_concat_serial_dialog,
      aux_sym_script_block_repeat1,
  [351] = 11,
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
    ACTIONS(98), 1,
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
  [394] = 11,
    ACTIONS(100), 1,
      ts_builtin_sym_end,
    ACTIONS(102), 1,
      sym_BAREWORD,
    ACTIONS(105), 1,
      sym_QUOTED_STRING,
    ACTIONS(108), 1,
      sym_CONSTANT,
    ACTIONS(111), 1,
      anon_sym_include,
    ACTIONS(114), 1,
      anon_sym_add,
    ACTIONS(117), 1,
      anon_sym_serial_dialog,
    ACTIONS(120), 1,
      anon_sym_dialog,
    ACTIONS(123), 1,
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
  [437] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(128), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(126), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [463] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(132), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(130), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [489] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(136), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(134), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [515] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(140), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(138), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [539] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(144), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(142), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [563] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(148), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(146), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [587] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(152), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(150), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [611] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(156), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(154), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [635] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(160), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(158), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [659] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(164), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(162), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [683] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(168), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(166), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [707] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(172), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(170), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [731] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(176), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(174), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [755] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(180), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(178), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [779] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(184), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(182), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [803] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(188), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(186), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [827] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(192), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(190), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [851] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(196), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(194), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [875] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(200), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(198), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [899] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(204), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(202), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [923] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(208), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(206), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [947] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(212), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(210), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [971] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(216), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(214), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [995] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(220), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(218), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [1019] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(224), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(222), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [1043] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(228), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(226), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [1067] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(232), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(230), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [1091] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(236), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(234), 13,
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
      anon_sym_show,
      anon_sym_concat,
  [1115] = 9,
    ACTIONS(238), 1,
      sym_QUOTED_STRING,
    STATE(39), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(61), 1,
      sym_dialog_parameter,
    STATE(72), 1,
      aux_sym_dialog_repeat1,
    STATE(126), 1,
      sym__dialog_parameter_string,
    STATE(180), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(240), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(242), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1149] = 9,
    ACTIONS(238), 1,
      sym_QUOTED_STRING,
    STATE(37), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(61), 1,
      sym_dialog_parameter,
    STATE(70), 1,
      aux_sym_dialog_repeat1,
    STATE(126), 1,
      sym__dialog_parameter_string,
    STATE(180), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(240), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(242), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1183] = 8,
    STATE(39), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(61), 1,
      sym_dialog_parameter,
    STATE(126), 1,
      sym__dialog_parameter_string,
    STATE(180), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(244), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    ACTIONS(246), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(249), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1215] = 8,
    ACTIONS(252), 1,
      anon_sym_RBRACE,
    STATE(39), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(61), 1,
      sym_dialog_parameter,
    STATE(126), 1,
      sym__dialog_parameter_string,
    STATE(180), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(240), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(242), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1246] = 8,
    ACTIONS(254), 1,
      anon_sym_RBRACE,
    STATE(42), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(61), 1,
      sym_dialog_parameter,
    STATE(126), 1,
      sym__dialog_parameter_string,
    STATE(180), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(240), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(242), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1277] = 8,
    ACTIONS(256), 1,
      anon_sym_RBRACE,
    STATE(39), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(61), 1,
      sym_dialog_parameter,
    STATE(126), 1,
      sym__dialog_parameter_string,
    STATE(180), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(240), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(242), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1308] = 8,
    ACTIONS(258), 1,
      anon_sym_RBRACE,
    STATE(40), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(61), 1,
      sym_dialog_parameter,
    STATE(126), 1,
      sym__dialog_parameter_string,
    STATE(180), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(240), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(242), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1339] = 6,
    ACTIONS(260), 1,
      anon_sym_LBRACK,
    ACTIONS(262), 1,
      anon_sym_RBRACK,
    ACTIONS(266), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(143), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(264), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1365] = 5,
    ACTIONS(260), 1,
      anon_sym_LBRACK,
    ACTIONS(266), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(181), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(268), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1388] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(270), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(272), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1407] = 6,
    ACTIONS(278), 1,
      sym_NUMBER,
    ACTIONS(280), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(274), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(276), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(234), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [1432] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(282), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(284), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1451] = 5,
    ACTIONS(260), 1,
      anon_sym_LBRACK,
    ACTIONS(266), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(190), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(286), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1474] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(288), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(290), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1493] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(292), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(294), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1512] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(296), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(298), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1530] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(300), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(302), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1548] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(304), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(306), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1566] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(308), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(310), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1584] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(312), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(314), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1602] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(316), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(318), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1620] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(320), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(322), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1638] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(324), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(326), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1656] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(328), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(330), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1674] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(332), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1690] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(334), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(336), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1708] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(338), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1724] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(340), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(342), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1742] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(344), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(346), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1760] = 9,
    ACTIONS(348), 1,
      sym_QUOTED_STRING,
    ACTIONS(350), 1,
      anon_sym_RBRACE,
    ACTIONS(352), 1,
      anon_sym_wrap,
    STATE(78), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(80), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(172), 1,
      sym_serial_dialog_parameter_int,
    STATE(174), 1,
      sym_serial_dialog_parameter,
    STATE(226), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1789] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(354), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1804] = 8,
    ACTIONS(356), 1,
      anon_sym_RBRACE,
    ACTIONS(358), 1,
      sym_target_default,
    ACTIONS(360), 1,
      anon_sym_label,
    ACTIONS(362), 1,
      anon_sym_entity,
    STATE(124), 1,
      sym_target_entity,
    STATE(168), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(71), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1831] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(364), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1846] = 8,
    ACTIONS(238), 1,
      sym_QUOTED_STRING,
    ACTIONS(368), 1,
      sym_identifier_type,
    ACTIONS(370), 1,
      anon_sym_GT,
    STATE(75), 1,
      aux_sym_dialog_repeat2,
    STATE(81), 1,
      aux_sym_dialog_repeat1,
    STATE(93), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(366), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1873] = 8,
    ACTIONS(372), 1,
      anon_sym_RBRACE,
    ACTIONS(374), 1,
      sym_target_default,
    ACTIONS(377), 1,
      anon_sym_label,
    ACTIONS(380), 1,
      anon_sym_entity,
    STATE(124), 1,
      sym_target_entity,
    STATE(168), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(71), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1900] = 8,
    ACTIONS(238), 1,
      sym_QUOTED_STRING,
    ACTIONS(370), 1,
      anon_sym_GT,
    ACTIONS(385), 1,
      sym_identifier_type,
    STATE(81), 1,
      aux_sym_dialog_repeat1,
    STATE(84), 1,
      aux_sym_dialog_repeat2,
    STATE(93), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(383), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1927] = 8,
    ACTIONS(358), 1,
      sym_target_default,
    ACTIONS(360), 1,
      anon_sym_label,
    ACTIONS(362), 1,
      anon_sym_entity,
    ACTIONS(387), 1,
      anon_sym_RBRACE,
    STATE(124), 1,
      sym_target_entity,
    STATE(168), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(68), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [1954] = 7,
    ACTIONS(389), 1,
      sym_BAREWORD,
    ACTIONS(391), 1,
      anon_sym_LBRACK,
    ACTIONS(395), 1,
      anon_sym_label,
    ACTIONS(397), 1,
      anon_sym_index,
    STATE(235), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(393), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1978] = 6,
    ACTIONS(370), 1,
      anon_sym_GT,
    ACTIONS(401), 1,
      sym_identifier_type,
    STATE(76), 1,
      aux_sym_dialog_repeat2,
    STATE(93), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(399), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [1999] = 6,
    ACTIONS(405), 1,
      sym_identifier_type,
    ACTIONS(407), 1,
      anon_sym_GT,
    STATE(76), 1,
      aux_sym_dialog_repeat2,
    STATE(93), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(403), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2020] = 7,
    ACTIONS(410), 1,
      sym_BAREWORD,
    ACTIONS(412), 1,
      anon_sym_RBRACE,
    ACTIONS(414), 1,
      sym_identifier_type,
    STATE(38), 1,
      sym_dialog_identifier,
    STATE(83), 1,
      aux_sym__dialog_block_repeat1,
    STATE(141), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2043] = 7,
    ACTIONS(348), 1,
      sym_QUOTED_STRING,
    ACTIONS(352), 1,
      anon_sym_wrap,
    STATE(79), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(86), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(172), 1,
      sym_serial_dialog_parameter_int,
    STATE(174), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2066] = 7,
    ACTIONS(348), 1,
      sym_QUOTED_STRING,
    ACTIONS(416), 1,
      anon_sym_RBRACE,
    ACTIONS(418), 1,
      sym_serial_dialog_option_type,
    STATE(100), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(112), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(175), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2089] = 7,
    ACTIONS(348), 1,
      sym_QUOTED_STRING,
    ACTIONS(418), 1,
      sym_serial_dialog_option_type,
    ACTIONS(420), 1,
      anon_sym_RBRACE,
    STATE(95), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(112), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(175), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2112] = 5,
    ACTIONS(424), 1,
      sym_QUOTED_STRING,
    ACTIONS(427), 1,
      sym_identifier_type,
    STATE(81), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(422), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2131] = 7,
    ACTIONS(429), 1,
      sym_BAREWORD,
    ACTIONS(432), 1,
      anon_sym_RBRACE,
    ACTIONS(434), 1,
      sym_identifier_type,
    STATE(38), 1,
      sym_dialog_identifier,
    STATE(82), 1,
      aux_sym__dialog_block_repeat1,
    STATE(141), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2154] = 7,
    ACTIONS(410), 1,
      sym_BAREWORD,
    ACTIONS(414), 1,
      sym_identifier_type,
    ACTIONS(437), 1,
      anon_sym_RBRACE,
    STATE(38), 1,
      sym_dialog_identifier,
    STATE(82), 1,
      aux_sym__dialog_block_repeat1,
    STATE(141), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2177] = 6,
    ACTIONS(370), 1,
      anon_sym_GT,
    ACTIONS(441), 1,
      sym_identifier_type,
    STATE(76), 1,
      aux_sym_dialog_repeat2,
    STATE(93), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(439), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2198] = 5,
    ACTIONS(352), 1,
      anon_sym_wrap,
    ACTIONS(443), 1,
      anon_sym_RBRACE,
    STATE(172), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(87), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2216] = 6,
    ACTIONS(445), 1,
      sym_QUOTED_STRING,
    ACTIONS(447), 1,
      anon_sym_wrap,
    STATE(86), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(172), 1,
      sym_serial_dialog_parameter_int,
    STATE(174), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2236] = 5,
    ACTIONS(352), 1,
      anon_sym_wrap,
    ACTIONS(450), 1,
      anon_sym_RBRACE,
    STATE(172), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(88), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2254] = 5,
    ACTIONS(452), 1,
      anon_sym_RBRACE,
    ACTIONS(454), 1,
      anon_sym_wrap,
    STATE(172), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(88), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2272] = 5,
    ACTIONS(457), 1,
      anon_sym_LBRACK,
    ACTIONS(459), 1,
      sym_NUMBER,
    ACTIONS(461), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(200), 2,
      sym_DURATION,
      sym_duration_expansion,
  [2290] = 3,
    ACTIONS(465), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(463), 4,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2304] = 5,
    ACTIONS(457), 1,
      anon_sym_LBRACK,
    ACTIONS(459), 1,
      sym_NUMBER,
    ACTIONS(467), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(212), 2,
      sym_DURATION,
      sym_duration_expansion,
  [2322] = 4,
    ACTIONS(391), 1,
      anon_sym_LBRACK,
    STATE(224), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(469), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2338] = 3,
    ACTIONS(473), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(471), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2351] = 5,
    ACTIONS(475), 1,
      sym_duration_suffix,
    ACTIONS(477), 1,
      sym_distance_suffix,
    ACTIONS(479), 1,
      sym_quantity_suffix,
    ACTIONS(481), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2368] = 5,
    ACTIONS(418), 1,
      sym_serial_dialog_option_type,
    ACTIONS(483), 1,
      anon_sym_RBRACE,
    STATE(101), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(175), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2385] = 4,
    ACTIONS(485), 1,
      anon_sym_LBRACK,
    STATE(256), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(487), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2400] = 4,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    STATE(223), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(491), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2415] = 4,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    STATE(225), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(493), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2430] = 3,
    ACTIONS(497), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(495), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2443] = 5,
    ACTIONS(418), 1,
      sym_serial_dialog_option_type,
    ACTIONS(499), 1,
      anon_sym_RBRACE,
    STATE(101), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(175), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2460] = 5,
    ACTIONS(501), 1,
      anon_sym_RBRACE,
    ACTIONS(503), 1,
      sym_serial_dialog_option_type,
    STATE(101), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(175), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2477] = 3,
    ACTIONS(508), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(506), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2490] = 5,
    ACTIONS(459), 1,
      sym_NUMBER,
    ACTIONS(510), 1,
      anon_sym_RBRACK,
    ACTIONS(512), 1,
      sym_CONSTANT,
    STATE(186), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2507] = 4,
    ACTIONS(516), 1,
      anon_sym_LBRACK,
    STATE(229), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(514), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2522] = 4,
    ACTIONS(489), 1,
      anon_sym_LBRACK,
    STATE(233), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(518), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2537] = 3,
    ACTIONS(475), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(520), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [2550] = 4,
    ACTIONS(524), 1,
      anon_sym_LBRACE,
    STATE(260), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(522), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2565] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(526), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2576] = 4,
    ACTIONS(530), 1,
      anon_sym_LBRACE,
    STATE(216), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(528), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2591] = 4,
    ACTIONS(524), 1,
      anon_sym_LBRACE,
    STATE(241), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(532), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2606] = 5,
    ACTIONS(459), 1,
      sym_NUMBER,
    ACTIONS(512), 1,
      sym_CONSTANT,
    ACTIONS(534), 1,
      anon_sym_RBRACK,
    STATE(186), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2623] = 4,
    ACTIONS(536), 1,
      sym_QUOTED_STRING,
    STATE(112), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(539), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2638] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(541), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2649] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(543), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2660] = 3,
    ACTIONS(545), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(506), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2673] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(547), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2684] = 3,
    ACTIONS(551), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(549), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2697] = 4,
    ACTIONS(553), 1,
      anon_sym_COMMA,
    ACTIONS(556), 1,
      anon_sym_RBRACK,
    STATE(118), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2711] = 4,
    ACTIONS(524), 1,
      anon_sym_LBRACE,
    ACTIONS(558), 1,
      anon_sym_SEMI,
    STATE(207), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2725] = 3,
    ACTIONS(560), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(562), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2737] = 4,
    ACTIONS(564), 1,
      anon_sym_COMMA,
    ACTIONS(567), 1,
      anon_sym_RBRACK,
    STATE(121), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2751] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(569), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2761] = 4,
    ACTIONS(530), 1,
      anon_sym_LBRACE,
    ACTIONS(571), 1,
      anon_sym_SEMI,
    STATE(203), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2775] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(573), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2785] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(575), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [2795] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(577), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2805] = 4,
    ACTIONS(459), 1,
      sym_NUMBER,
    ACTIONS(579), 1,
      sym_CONSTANT,
    STATE(165), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2819] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(581), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [2829] = 4,
    ACTIONS(583), 1,
      anon_sym_COMMA,
    ACTIONS(585), 1,
      anon_sym_RBRACE,
    STATE(145), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2843] = 4,
    ACTIONS(587), 1,
      anon_sym_COMMA,
    ACTIONS(589), 1,
      anon_sym_RBRACK,
    STATE(146), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2857] = 4,
    ACTIONS(591), 1,
      anon_sym_COMMA,
    ACTIONS(593), 1,
      anon_sym_RBRACK,
    STATE(148), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2871] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(595), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [2881] = 4,
    ACTIONS(545), 1,
      anon_sym_RBRACK,
    ACTIONS(597), 1,
      anon_sym_COMMA,
    STATE(149), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2895] = 3,
    ACTIONS(599), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(562), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2907] = 4,
    ACTIONS(601), 1,
      anon_sym_COMMA,
    ACTIONS(603), 1,
      anon_sym_RBRACK,
    STATE(151), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2921] = 4,
    ACTIONS(599), 1,
      anon_sym_RBRACK,
    ACTIONS(605), 1,
      anon_sym_COMMA,
    STATE(121), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2935] = 4,
    ACTIONS(534), 1,
      anon_sym_RBRACK,
    ACTIONS(607), 1,
      anon_sym_COMMA,
    STATE(118), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2949] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(609), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2959] = 4,
    ACTIONS(611), 1,
      anon_sym_COMMA,
    ACTIONS(613), 1,
      anon_sym_RBRACK,
    STATE(136), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2973] = 3,
    ACTIONS(615), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(617), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2985] = 3,
    ACTIONS(621), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(619), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2997] = 4,
    ACTIONS(524), 1,
      anon_sym_LBRACE,
    ACTIONS(623), 1,
      anon_sym_SEMI,
    STATE(243), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3011] = 4,
    ACTIONS(587), 1,
      anon_sym_COMMA,
    ACTIONS(625), 1,
      anon_sym_RBRACK,
    STATE(130), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3025] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(627), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [3035] = 4,
    ACTIONS(583), 1,
      anon_sym_COMMA,
    ACTIONS(629), 1,
      anon_sym_RBRACE,
    STATE(158), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3049] = 4,
    ACTIONS(631), 1,
      anon_sym_COMMA,
    ACTIONS(634), 1,
      anon_sym_RBRACK,
    STATE(146), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3063] = 3,
    ACTIONS(636), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(638), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3075] = 4,
    ACTIONS(636), 1,
      anon_sym_RBRACK,
    ACTIONS(640), 1,
      anon_sym_COMMA,
    STATE(160), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3089] = 4,
    ACTIONS(642), 1,
      anon_sym_COMMA,
    ACTIONS(645), 1,
      anon_sym_RBRACK,
    STATE(149), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3103] = 3,
    ACTIONS(649), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(647), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3115] = 4,
    ACTIONS(649), 1,
      anon_sym_RBRACK,
    ACTIONS(651), 1,
      anon_sym_COMMA,
    STATE(163), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3129] = 3,
    ACTIONS(653), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(655), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3141] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(657), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3151] = 4,
    ACTIONS(659), 1,
      anon_sym_COMMA,
    ACTIONS(661), 1,
      anon_sym_RBRACK,
    STATE(133), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3165] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(663), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3175] = 3,
    ACTIONS(667), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(665), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3187] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(669), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [3197] = 4,
    ACTIONS(671), 1,
      anon_sym_COMMA,
    ACTIONS(674), 1,
      anon_sym_RBRACE,
    STATE(158), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3211] = 3,
    ACTIONS(676), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(638), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3223] = 4,
    ACTIONS(678), 1,
      anon_sym_COMMA,
    ACTIONS(681), 1,
      anon_sym_RBRACK,
    STATE(160), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3237] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(506), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3247] = 3,
    ACTIONS(683), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(647), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3259] = 4,
    ACTIONS(685), 1,
      anon_sym_COMMA,
    ACTIONS(688), 1,
      anon_sym_RBRACK,
    STATE(163), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3273] = 4,
    ACTIONS(459), 1,
      sym_NUMBER,
    ACTIONS(512), 1,
      sym_CONSTANT,
    STATE(186), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3287] = 4,
    ACTIONS(690), 1,
      anon_sym_COMMA,
    ACTIONS(692), 1,
      anon_sym_RBRACK,
    STATE(137), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3301] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(694), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3311] = 4,
    ACTIONS(696), 1,
      sym_QUOTED_STRING,
    ACTIONS(698), 1,
      anon_sym_RBRACE,
    STATE(129), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3325] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(573), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3334] = 3,
    ACTIONS(260), 1,
      anon_sym_LBRACK,
    STATE(20), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3345] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(700), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3354] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(702), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3363] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(704), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3372] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(562), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3381] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(706), 2,
      sym_QUOTED_STRING,
      anon_sym_wrap,
  [3390] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(708), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3399] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(710), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3408] = 3,
    ACTIONS(712), 1,
      anon_sym_serial_dialog,
    ACTIONS(714), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3419] = 3,
    ACTIONS(716), 1,
      anon_sym_slot,
    ACTIONS(718), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3430] = 3,
    ACTIONS(696), 1,
      sym_QUOTED_STRING,
    STATE(191), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3441] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(577), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3450] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(634), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3459] = 3,
    ACTIONS(524), 1,
      anon_sym_LBRACE,
    STATE(53), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3470] = 3,
    ACTIONS(530), 1,
      anon_sym_LBRACE,
    STATE(54), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3481] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(645), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3490] = 3,
    ACTIONS(720), 1,
      anon_sym_LBRACE,
    STATE(55), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3501] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(556), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3510] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(722), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3519] = 3,
    ACTIONS(720), 1,
      anon_sym_LBRACE,
    STATE(56), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3530] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(567), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3539] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(724), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [3548] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(674), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [3557] = 3,
    ACTIONS(726), 1,
      anon_sym_serial_dialog,
    ACTIONS(728), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3568] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(681), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3577] = 3,
    ACTIONS(730), 1,
      anon_sym_serial_dialog,
    ACTIONS(732), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3588] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(688), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3597] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(734), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3606] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(638), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3615] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(647), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3624] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(736), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3633] = 2,
    ACTIONS(738), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3641] = 2,
    ACTIONS(740), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3649] = 2,
    ACTIONS(742), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3657] = 2,
    ACTIONS(744), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3665] = 2,
    ACTIONS(746), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3673] = 2,
    ACTIONS(748), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3681] = 2,
    ACTIONS(750), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3689] = 2,
    ACTIONS(752), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3697] = 2,
    ACTIONS(754), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3705] = 2,
    ACTIONS(756), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3713] = 2,
    ACTIONS(758), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3721] = 2,
    ACTIONS(760), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3729] = 2,
    ACTIONS(762), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3737] = 2,
    ACTIONS(764), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3745] = 2,
    ACTIONS(766), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3753] = 2,
    ACTIONS(768), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3761] = 2,
    ACTIONS(770), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3769] = 2,
    ACTIONS(772), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3777] = 2,
    ACTIONS(774), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3785] = 2,
    ACTIONS(776), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3793] = 2,
    ACTIONS(778), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3801] = 2,
    ACTIONS(780), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3809] = 2,
    ACTIONS(782), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3817] = 2,
    ACTIONS(784), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3825] = 2,
    ACTIONS(786), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3833] = 2,
    ACTIONS(788), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3841] = 2,
    ACTIONS(790), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3849] = 2,
    ACTIONS(792), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3857] = 2,
    ACTIONS(794), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3865] = 2,
    ACTIONS(796), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3873] = 2,
    ACTIONS(798), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3881] = 2,
    ACTIONS(800), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3889] = 2,
    ACTIONS(802), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3897] = 2,
    ACTIONS(804), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3905] = 2,
    ACTIONS(481), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3913] = 2,
    ACTIONS(806), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3921] = 2,
    ACTIONS(808), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3929] = 2,
    ACTIONS(810), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3937] = 2,
    ACTIONS(812), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3945] = 2,
    ACTIONS(814), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3953] = 2,
    ACTIONS(816), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3961] = 2,
    ACTIONS(818), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3969] = 2,
    ACTIONS(820), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3977] = 2,
    ACTIONS(822), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3985] = 2,
    ACTIONS(824), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3993] = 2,
    ACTIONS(826), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4001] = 2,
    ACTIONS(828), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4009] = 2,
    ACTIONS(830), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4017] = 2,
    ACTIONS(832), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4025] = 2,
    ACTIONS(834), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4033] = 2,
    ACTIONS(836), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4041] = 2,
    ACTIONS(838), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4049] = 2,
    ACTIONS(840), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4057] = 2,
    ACTIONS(842), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4065] = 2,
    ACTIONS(844), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4073] = 2,
    ACTIONS(846), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4081] = 2,
    ACTIONS(848), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4089] = 2,
    ACTIONS(850), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4097] = 2,
    ACTIONS(852), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4105] = 2,
    ACTIONS(854), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4113] = 2,
    ACTIONS(856), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4121] = 2,
    ACTIONS(858), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 71,
  [SMALL_STATE(4)] = 141,
  [SMALL_STATE(5)] = 211,
  [SMALL_STATE(6)] = 281,
  [SMALL_STATE(7)] = 351,
  [SMALL_STATE(8)] = 394,
  [SMALL_STATE(9)] = 437,
  [SMALL_STATE(10)] = 463,
  [SMALL_STATE(11)] = 489,
  [SMALL_STATE(12)] = 515,
  [SMALL_STATE(13)] = 539,
  [SMALL_STATE(14)] = 563,
  [SMALL_STATE(15)] = 587,
  [SMALL_STATE(16)] = 611,
  [SMALL_STATE(17)] = 635,
  [SMALL_STATE(18)] = 659,
  [SMALL_STATE(19)] = 683,
  [SMALL_STATE(20)] = 707,
  [SMALL_STATE(21)] = 731,
  [SMALL_STATE(22)] = 755,
  [SMALL_STATE(23)] = 779,
  [SMALL_STATE(24)] = 803,
  [SMALL_STATE(25)] = 827,
  [SMALL_STATE(26)] = 851,
  [SMALL_STATE(27)] = 875,
  [SMALL_STATE(28)] = 899,
  [SMALL_STATE(29)] = 923,
  [SMALL_STATE(30)] = 947,
  [SMALL_STATE(31)] = 971,
  [SMALL_STATE(32)] = 995,
  [SMALL_STATE(33)] = 1019,
  [SMALL_STATE(34)] = 1043,
  [SMALL_STATE(35)] = 1067,
  [SMALL_STATE(36)] = 1091,
  [SMALL_STATE(37)] = 1115,
  [SMALL_STATE(38)] = 1149,
  [SMALL_STATE(39)] = 1183,
  [SMALL_STATE(40)] = 1215,
  [SMALL_STATE(41)] = 1246,
  [SMALL_STATE(42)] = 1277,
  [SMALL_STATE(43)] = 1308,
  [SMALL_STATE(44)] = 1339,
  [SMALL_STATE(45)] = 1365,
  [SMALL_STATE(46)] = 1388,
  [SMALL_STATE(47)] = 1407,
  [SMALL_STATE(48)] = 1432,
  [SMALL_STATE(49)] = 1451,
  [SMALL_STATE(50)] = 1474,
  [SMALL_STATE(51)] = 1493,
  [SMALL_STATE(52)] = 1512,
  [SMALL_STATE(53)] = 1530,
  [SMALL_STATE(54)] = 1548,
  [SMALL_STATE(55)] = 1566,
  [SMALL_STATE(56)] = 1584,
  [SMALL_STATE(57)] = 1602,
  [SMALL_STATE(58)] = 1620,
  [SMALL_STATE(59)] = 1638,
  [SMALL_STATE(60)] = 1656,
  [SMALL_STATE(61)] = 1674,
  [SMALL_STATE(62)] = 1690,
  [SMALL_STATE(63)] = 1708,
  [SMALL_STATE(64)] = 1724,
  [SMALL_STATE(65)] = 1742,
  [SMALL_STATE(66)] = 1760,
  [SMALL_STATE(67)] = 1789,
  [SMALL_STATE(68)] = 1804,
  [SMALL_STATE(69)] = 1831,
  [SMALL_STATE(70)] = 1846,
  [SMALL_STATE(71)] = 1873,
  [SMALL_STATE(72)] = 1900,
  [SMALL_STATE(73)] = 1927,
  [SMALL_STATE(74)] = 1954,
  [SMALL_STATE(75)] = 1978,
  [SMALL_STATE(76)] = 1999,
  [SMALL_STATE(77)] = 2020,
  [SMALL_STATE(78)] = 2043,
  [SMALL_STATE(79)] = 2066,
  [SMALL_STATE(80)] = 2089,
  [SMALL_STATE(81)] = 2112,
  [SMALL_STATE(82)] = 2131,
  [SMALL_STATE(83)] = 2154,
  [SMALL_STATE(84)] = 2177,
  [SMALL_STATE(85)] = 2198,
  [SMALL_STATE(86)] = 2216,
  [SMALL_STATE(87)] = 2236,
  [SMALL_STATE(88)] = 2254,
  [SMALL_STATE(89)] = 2272,
  [SMALL_STATE(90)] = 2290,
  [SMALL_STATE(91)] = 2304,
  [SMALL_STATE(92)] = 2322,
  [SMALL_STATE(93)] = 2338,
  [SMALL_STATE(94)] = 2351,
  [SMALL_STATE(95)] = 2368,
  [SMALL_STATE(96)] = 2385,
  [SMALL_STATE(97)] = 2400,
  [SMALL_STATE(98)] = 2415,
  [SMALL_STATE(99)] = 2430,
  [SMALL_STATE(100)] = 2443,
  [SMALL_STATE(101)] = 2460,
  [SMALL_STATE(102)] = 2477,
  [SMALL_STATE(103)] = 2490,
  [SMALL_STATE(104)] = 2507,
  [SMALL_STATE(105)] = 2522,
  [SMALL_STATE(106)] = 2537,
  [SMALL_STATE(107)] = 2550,
  [SMALL_STATE(108)] = 2565,
  [SMALL_STATE(109)] = 2576,
  [SMALL_STATE(110)] = 2591,
  [SMALL_STATE(111)] = 2606,
  [SMALL_STATE(112)] = 2623,
  [SMALL_STATE(113)] = 2638,
  [SMALL_STATE(114)] = 2649,
  [SMALL_STATE(115)] = 2660,
  [SMALL_STATE(116)] = 2673,
  [SMALL_STATE(117)] = 2684,
  [SMALL_STATE(118)] = 2697,
  [SMALL_STATE(119)] = 2711,
  [SMALL_STATE(120)] = 2725,
  [SMALL_STATE(121)] = 2737,
  [SMALL_STATE(122)] = 2751,
  [SMALL_STATE(123)] = 2761,
  [SMALL_STATE(124)] = 2775,
  [SMALL_STATE(125)] = 2785,
  [SMALL_STATE(126)] = 2795,
  [SMALL_STATE(127)] = 2805,
  [SMALL_STATE(128)] = 2819,
  [SMALL_STATE(129)] = 2829,
  [SMALL_STATE(130)] = 2843,
  [SMALL_STATE(131)] = 2857,
  [SMALL_STATE(132)] = 2871,
  [SMALL_STATE(133)] = 2881,
  [SMALL_STATE(134)] = 2895,
  [SMALL_STATE(135)] = 2907,
  [SMALL_STATE(136)] = 2921,
  [SMALL_STATE(137)] = 2935,
  [SMALL_STATE(138)] = 2949,
  [SMALL_STATE(139)] = 2959,
  [SMALL_STATE(140)] = 2973,
  [SMALL_STATE(141)] = 2985,
  [SMALL_STATE(142)] = 2997,
  [SMALL_STATE(143)] = 3011,
  [SMALL_STATE(144)] = 3025,
  [SMALL_STATE(145)] = 3035,
  [SMALL_STATE(146)] = 3049,
  [SMALL_STATE(147)] = 3063,
  [SMALL_STATE(148)] = 3075,
  [SMALL_STATE(149)] = 3089,
  [SMALL_STATE(150)] = 3103,
  [SMALL_STATE(151)] = 3115,
  [SMALL_STATE(152)] = 3129,
  [SMALL_STATE(153)] = 3141,
  [SMALL_STATE(154)] = 3151,
  [SMALL_STATE(155)] = 3165,
  [SMALL_STATE(156)] = 3175,
  [SMALL_STATE(157)] = 3187,
  [SMALL_STATE(158)] = 3197,
  [SMALL_STATE(159)] = 3211,
  [SMALL_STATE(160)] = 3223,
  [SMALL_STATE(161)] = 3237,
  [SMALL_STATE(162)] = 3247,
  [SMALL_STATE(163)] = 3259,
  [SMALL_STATE(164)] = 3273,
  [SMALL_STATE(165)] = 3287,
  [SMALL_STATE(166)] = 3301,
  [SMALL_STATE(167)] = 3311,
  [SMALL_STATE(168)] = 3325,
  [SMALL_STATE(169)] = 3334,
  [SMALL_STATE(170)] = 3345,
  [SMALL_STATE(171)] = 3354,
  [SMALL_STATE(172)] = 3363,
  [SMALL_STATE(173)] = 3372,
  [SMALL_STATE(174)] = 3381,
  [SMALL_STATE(175)] = 3390,
  [SMALL_STATE(176)] = 3399,
  [SMALL_STATE(177)] = 3408,
  [SMALL_STATE(178)] = 3419,
  [SMALL_STATE(179)] = 3430,
  [SMALL_STATE(180)] = 3441,
  [SMALL_STATE(181)] = 3450,
  [SMALL_STATE(182)] = 3459,
  [SMALL_STATE(183)] = 3470,
  [SMALL_STATE(184)] = 3481,
  [SMALL_STATE(185)] = 3490,
  [SMALL_STATE(186)] = 3501,
  [SMALL_STATE(187)] = 3510,
  [SMALL_STATE(188)] = 3519,
  [SMALL_STATE(189)] = 3530,
  [SMALL_STATE(190)] = 3539,
  [SMALL_STATE(191)] = 3548,
  [SMALL_STATE(192)] = 3557,
  [SMALL_STATE(193)] = 3568,
  [SMALL_STATE(194)] = 3577,
  [SMALL_STATE(195)] = 3588,
  [SMALL_STATE(196)] = 3597,
  [SMALL_STATE(197)] = 3606,
  [SMALL_STATE(198)] = 3615,
  [SMALL_STATE(199)] = 3624,
  [SMALL_STATE(200)] = 3633,
  [SMALL_STATE(201)] = 3641,
  [SMALL_STATE(202)] = 3649,
  [SMALL_STATE(203)] = 3657,
  [SMALL_STATE(204)] = 3665,
  [SMALL_STATE(205)] = 3673,
  [SMALL_STATE(206)] = 3681,
  [SMALL_STATE(207)] = 3689,
  [SMALL_STATE(208)] = 3697,
  [SMALL_STATE(209)] = 3705,
  [SMALL_STATE(210)] = 3713,
  [SMALL_STATE(211)] = 3721,
  [SMALL_STATE(212)] = 3729,
  [SMALL_STATE(213)] = 3737,
  [SMALL_STATE(214)] = 3745,
  [SMALL_STATE(215)] = 3753,
  [SMALL_STATE(216)] = 3761,
  [SMALL_STATE(217)] = 3769,
  [SMALL_STATE(218)] = 3777,
  [SMALL_STATE(219)] = 3785,
  [SMALL_STATE(220)] = 3793,
  [SMALL_STATE(221)] = 3801,
  [SMALL_STATE(222)] = 3809,
  [SMALL_STATE(223)] = 3817,
  [SMALL_STATE(224)] = 3825,
  [SMALL_STATE(225)] = 3833,
  [SMALL_STATE(226)] = 3841,
  [SMALL_STATE(227)] = 3849,
  [SMALL_STATE(228)] = 3857,
  [SMALL_STATE(229)] = 3865,
  [SMALL_STATE(230)] = 3873,
  [SMALL_STATE(231)] = 3881,
  [SMALL_STATE(232)] = 3889,
  [SMALL_STATE(233)] = 3897,
  [SMALL_STATE(234)] = 3905,
  [SMALL_STATE(235)] = 3913,
  [SMALL_STATE(236)] = 3921,
  [SMALL_STATE(237)] = 3929,
  [SMALL_STATE(238)] = 3937,
  [SMALL_STATE(239)] = 3945,
  [SMALL_STATE(240)] = 3953,
  [SMALL_STATE(241)] = 3961,
  [SMALL_STATE(242)] = 3969,
  [SMALL_STATE(243)] = 3977,
  [SMALL_STATE(244)] = 3985,
  [SMALL_STATE(245)] = 3993,
  [SMALL_STATE(246)] = 4001,
  [SMALL_STATE(247)] = 4009,
  [SMALL_STATE(248)] = 4017,
  [SMALL_STATE(249)] = 4025,
  [SMALL_STATE(250)] = 4033,
  [SMALL_STATE(251)] = 4041,
  [SMALL_STATE(252)] = 4049,
  [SMALL_STATE(253)] = 4057,
  [SMALL_STATE(254)] = 4065,
  [SMALL_STATE(255)] = 4073,
  [SMALL_STATE(256)] = 4081,
  [SMALL_STATE(257)] = 4089,
  [SMALL_STATE(258)] = 4097,
  [SMALL_STATE(259)] = 4105,
  [SMALL_STATE(260)] = 4113,
  [SMALL_STATE(261)] = 4121,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(188),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(194),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(170),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(199),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(251),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(169),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(209),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(221),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(177),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(228),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(178),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(210),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(192),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(237),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(251),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(209),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(221),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(177),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(228),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(178),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(210),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [88] = {.entry = {.count = 1, .reusable = false}}, SHIFT(192),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(237),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [102] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(188),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(188),
  [108] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(227),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [114] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(194),
  [117] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(170),
  [120] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(153),
  [123] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(199),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_erase_slot, 4, 0, 28),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 4, 0, 28),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_run_script, 3, 0, 13),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 3, 0, 13),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 14),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 14),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_blocking_delay, 3, 0, 14),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 3, 0, 14),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_map, 4, 0, 29),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 4, 0, 29),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_slot, 4, 0, 28),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 4, 0, 28),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_label, 4, 0, 30),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 4, 0, 30),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_index, 4, 0, 31),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 4, 0, 31),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 32),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 32),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 33),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 33),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 34),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 34),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 35),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 35),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 32),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 32),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 33),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 33),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 43),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 43),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_definition, 2, 0, 6),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_definition, 2, 0, 6),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 5, 0, 44),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 5, 0, 44),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 43),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 43),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 38),
  [246] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 38), SHIFT_REPEAT(180),
  [249] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 38), SHIFT_REPEAT(126),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = false}}, SHIFT(234),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 3, 0, 26),
  [284] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 3, 0, 26),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 16),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 16),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [302] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [306] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [310] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [314] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [318] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [322] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [326] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 1, 0, 24),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [336] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 15),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 7),
  [342] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 7),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [346] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [354] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(187),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 22),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 25),
  [368] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 25),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [374] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(222),
  [377] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(187),
  [380] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [383] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 39),
  [385] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 39),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [389] = {.entry = {.count = 1, .reusable = false}}, SHIFT(235),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [395] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [397] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 42),
  [401] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 42),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 47),
  [405] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 47),
  [407] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 47), SHIFT_REPEAT(258),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [414] = {.entry = {.count = 1, .reusable = false}}, SHIFT(176),
  [416] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 18),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 11),
  [422] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 41),
  [424] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 41), SHIFT_REPEAT(90),
  [427] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 41),
  [429] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 27), SHIFT_REPEAT(67),
  [432] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 27),
  [434] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 27), SHIFT_REPEAT(176),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 46),
  [441] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 46),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [445] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 17),
  [447] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 17), SHIFT_REPEAT(171),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [452] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [454] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(171),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 23),
  [465] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 23),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [471] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 40),
  [473] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 40),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [483] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 21),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [487] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [489] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [491] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [495] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [499] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 36),
  [501] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 37),
  [503] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 37), SHIFT_REPEAT(201),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [512] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [526] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 3, 0, 45),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [530] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [534] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [536] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 20), SHIFT_REPEAT(138),
  [539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 20),
  [541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 49),
  [543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 50),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [547] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 5, 0, 52),
  [549] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 53),
  [551] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 53),
  [553] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(164),
  [556] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [558] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [560] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [562] = {.entry = {.count = 1, .reusable = true}}, SHIFT(189),
  [564] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(173),
  [567] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [569] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_entity, 1, 0, 0),
  [571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [575] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 15),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [581] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [593] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [595] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 8),
  [597] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [599] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [601] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [605] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [609] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 9),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [613] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [619] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 12),
  [621] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 12),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [627] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [631] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [634] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [636] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [638] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [642] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(161),
  [645] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [649] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [651] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [653] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [657] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [659] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [669] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [671] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(179),
  [674] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [676] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [678] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(197),
  [681] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [683] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [685] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(198),
  [688] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [690] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [692] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [694] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [696] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [700] = {.entry = {.count = 1, .reusable = true}}, SHIFT(182),
  [702] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter_int, 1, 0, 0),
  [704] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [706] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 10),
  [708] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 19),
  [710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [712] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [714] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [716] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [718] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [720] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [722] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_label, 1, 0, 0),
  [724] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 48),
  [726] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [728] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [734] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 51),
  [736] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [738] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [740] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [742] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [744] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [746] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [748] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [750] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [752] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [754] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [756] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [758] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [760] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [762] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [764] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [766] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [768] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [772] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [774] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [778] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [780] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [782] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [784] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [786] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [788] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [790] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [792] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [794] = {.entry = {.count = 1, .reusable = true}}, SHIFT(254),
  [796] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [798] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [800] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [802] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [804] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [806] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [808] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [810] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [812] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [814] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [816] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [818] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [820] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [822] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [824] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [826] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [828] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [830] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 8),
  [832] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [834] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 8),
  [836] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [838] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [840] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [842] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [844] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [846] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [848] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [850] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [852] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [854] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [856] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [858] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
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
