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
#define STATE_COUNT 280
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 147
#define ALIAS_COUNT 0
#define TOKEN_COUNT 67
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 28
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 57

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
  anon_sym_delete = 61,
  anon_sym_command = 62,
  anon_sym_PLUS = 63,
  anon_sym_alias = 64,
  anon_sym_hide = 65,
  anon_sym_unhide = 66,
  sym_document = 67,
  sym_bareword_expansion = 68,
  sym_quoted_string_expansion = 69,
  sym_string_expansion = 70,
  sym_number_expansion = 71,
  sym_DURATION = 72,
  sym_duration_expansion = 73,
  sym_DISTANCE = 74,
  sym_QUANTITY = 75,
  sym__root = 76,
  sym_include_macro = 77,
  sym_constant_assignment = 78,
  sym_add_serial_dialog_settings = 79,
  sym_serial_dialog_parameter_int = 80,
  sym_serial_dialog_parameter = 81,
  sym_add_dialog_settings = 82,
  sym_target_label = 83,
  sym_target_entity = 84,
  sym_add_dialog_settings_target = 85,
  sym__dialog_parameter_int = 86,
  sym__dialog_parameter_string = 87,
  sym_dialog_parameter = 88,
  sym_dialog_definition = 89,
  sym__dialog_block = 90,
  sym_dialog = 91,
  sym_dialog_identifier = 92,
  sym_dialog_option = 93,
  sym_serial_dialog_definition = 94,
  sym__serial_dialog_block = 95,
  sym_serial_dialog = 96,
  sym_serial_dialog_option = 97,
  sym_script_definition = 98,
  sym_script_block = 99,
  sym__script_item = 100,
  sym_json_literal = 101,
  sym_json_array = 102,
  sym_json_object = 103,
  sym_json_name_value_pair = 104,
  sym__json_item = 105,
  sym_rand_macro = 106,
  sym_label_definition = 107,
  sym__action_item = 108,
  sym_action_return_statement = 109,
  sym_action_close_dialog = 110,
  sym_action_close_serial_dialog = 111,
  sym_action_save_slot = 112,
  sym_action_load_slot = 113,
  sym_action_erase_slot = 114,
  sym_action_load_map = 115,
  sym_action_run_script = 116,
  sym_action_goto_label = 117,
  sym_action_goto_index = 118,
  sym_action_non_blocking_delay = 119,
  sym_action_blocking_delay = 120,
  sym_action_show_dialog = 121,
  sym_action_show_serial_dialog = 122,
  sym_action_concat_serial_dialog = 123,
  sym_action_delete_command = 124,
  sym_action_delete_command_arg = 125,
  sym_action_delete_alias = 126,
  sym_action_hide_command = 127,
  sym_action_unhide_command = 128,
  aux_sym_document_repeat1 = 129,
  aux_sym_bareword_expansion_repeat1 = 130,
  aux_sym_quoted_string_expansion_repeat1 = 131,
  aux_sym_string_expansion_repeat1 = 132,
  aux_sym_number_expansion_repeat1 = 133,
  aux_sym_duration_expansion_repeat1 = 134,
  aux_sym_add_serial_dialog_settings_repeat1 = 135,
  aux_sym_add_dialog_settings_repeat1 = 136,
  aux_sym_add_dialog_settings_target_repeat1 = 137,
  aux_sym__dialog_block_repeat1 = 138,
  aux_sym_dialog_repeat1 = 139,
  aux_sym_dialog_repeat2 = 140,
  aux_sym_serial_dialog_repeat1 = 141,
  aux_sym_serial_dialog_repeat2 = 142,
  aux_sym_serial_dialog_repeat3 = 143,
  aux_sym_script_block_repeat1 = 144,
  aux_sym_json_array_repeat1 = 145,
  aux_sym_json_object_repeat1 = 146,
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
  [anon_sym_delete] = "delete",
  [anon_sym_command] = "command",
  [anon_sym_PLUS] = "+",
  [anon_sym_alias] = "alias",
  [anon_sym_hide] = "hide",
  [anon_sym_unhide] = "unhide",
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
  [sym_action_delete_command] = "action_delete_command",
  [sym_action_delete_command_arg] = "action_delete_command_arg",
  [sym_action_delete_alias] = "action_delete_alias",
  [sym_action_hide_command] = "action_hide_command",
  [sym_action_unhide_command] = "action_unhide_command",
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
  [anon_sym_delete] = anon_sym_delete,
  [anon_sym_command] = anon_sym_command,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_alias] = anon_sym_alias,
  [anon_sym_hide] = anon_sym_hide,
  [anon_sym_unhide] = anon_sym_unhide,
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
  [sym_action_delete_command] = sym_action_delete_command,
  [sym_action_delete_command_arg] = sym_action_delete_command_arg,
  [sym_action_delete_alias] = sym_action_delete_alias,
  [sym_action_hide_command] = sym_action_hide_command,
  [sym_action_unhide_command] = sym_action_unhide_command,
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
  [anon_sym_delete] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_command] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alias] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_hide] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unhide] = {
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
  [sym_action_delete_command] = {
    .visible = true,
    .named = true,
  },
  [sym_action_delete_command_arg] = {
    .visible = true,
    .named = true,
  },
  [sym_action_delete_alias] = {
    .visible = true,
    .named = true,
  },
  [sym_action_hide_command] = {
    .visible = true,
    .named = true,
  },
  [sym_action_unhide_command] = {
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
  field_alias = 1,
  field_argument = 2,
  field_command = 3,
  field_dialog = 4,
  field_dialog_identifier = 5,
  field_dialog_name = 6,
  field_dialog_option = 7,
  field_dialog_parameter = 8,
  field_duration = 9,
  field_fileName = 10,
  field_index = 11,
  field_label = 12,
  field_map = 13,
  field_message = 14,
  field_option_type = 15,
  field_property = 16,
  field_script = 17,
  field_script_name = 18,
  field_serial_dialog = 19,
  field_serial_dialog_name = 20,
  field_serial_dialog_option = 21,
  field_serial_dialog_parameter = 22,
  field_serial_message = 23,
  field_slot = 24,
  field_suffix = 25,
  field_target = 26,
  field_type = 27,
  field_value = 28,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias] = "alias",
  [field_argument] = "argument",
  [field_command] = "command",
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
  [36] = {.index = 46, .length = 1},
  [37] = {.index = 47, .length = 1},
  [38] = {.index = 48, .length = 3},
  [39] = {.index = 51, .length = 2},
  [40] = {.index = 53, .length = 2},
  [41] = {.index = 55, .length = 3},
  [42] = {.index = 58, .length = 1},
  [43] = {.index = 59, .length = 2},
  [44] = {.index = 61, .length = 3},
  [45] = {.index = 64, .length = 2},
  [46] = {.index = 66, .length = 2},
  [47] = {.index = 68, .length = 1},
  [48] = {.index = 69, .length = 4},
  [49] = {.index = 73, .length = 2},
  [50] = {.index = 75, .length = 2},
  [51] = {.index = 77, .length = 2},
  [52] = {.index = 79, .length = 2},
  [53] = {.index = 81, .length = 2},
  [54] = {.index = 83, .length = 3},
  [55] = {.index = 86, .length = 3},
  [56] = {.index = 89, .length = 2},
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
    {field_command, 2},
  [47] =
    {field_alias, 2},
  [48] =
    {field_serial_dialog_option, 2, .inherited = true},
    {field_serial_dialog_parameter, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [51] =
    {field_serial_dialog_option, 0, .inherited = true},
    {field_serial_dialog_option, 1, .inherited = true},
  [53] =
    {field_dialog_parameter, 0, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
  [55] =
    {field_dialog_identifier, 0},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [58] =
    {field_dialog_option, 0},
  [59] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [61] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 2, .inherited = true},
    {field_message, 1, .inherited = true},
  [64] =
    {field_serial_dialog, 3, .inherited = true},
    {field_serial_dialog_name, 2},
  [66] =
    {field_dialog, 3, .inherited = true},
    {field_dialog_name, 2},
  [68] =
    {field_type, 0},
  [69] =
    {field_dialog_identifier, 0},
    {field_dialog_option, 3, .inherited = true},
    {field_dialog_parameter, 1, .inherited = true},
    {field_message, 2, .inherited = true},
  [73] =
    {field_dialog_option, 0, .inherited = true},
    {field_dialog_option, 1, .inherited = true},
  [75] =
    {field_property, 0},
    {field_value, 2},
  [77] =
    {field_argument, 4},
    {field_command, 2},
  [79] =
    {field_dialog_parameter, 2, .inherited = true},
    {field_type, 0},
  [81] =
    {field_target, 1},
    {field_type, 0},
  [83] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [86] =
    {field_dialog_parameter, 3, .inherited = true},
    {field_target, 1},
    {field_type, 0},
  [89] =
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
  [262] = 262,
  [263] = 263,
  [264] = 264,
  [265] = 265,
  [266] = 266,
  [267] = 267,
  [268] = 268,
  [269] = 269,
  [270] = 270,
  [271] = 271,
  [272] = 272,
  [273] = 273,
  [274] = 274,
  [275] = 275,
  [276] = 276,
  [277] = 277,
  [278] = 278,
  [279] = 279,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(218);
      ADVANCE_MAP(
        '!', 420,
        '"', 6,
        '#', 407,
        '$', 214,
        '(', 421,
        ')', 422,
        '+', 450,
        ',', 368,
        '-', 12,
        '/', 8,
        ':', 412,
        ';', 384,
        '=', 385,
        '>', 405,
        'I', 134,
        '[', 367,
        ']', 369,
        '_', 406,
        'a', 45,
        'b', 113,
        'c', 114,
        'd', 56,
        'e', 129,
        'f', 15,
        'g', 154,
        'h', 96,
        'i', 135,
        'j', 176,
        'l', 17,
        'm', 19,
        'n', 20,
        'o', 136,
        'p', 94,
        'r', 31,
        's', 373,
        't', 91,
        'u', 137,
        'w', 30,
        'x', 375,
        'y', 79,
        '{', 391,
        '}', 392,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(216);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 6,
        '#', 211,
        '$', 214,
        '/', 8,
        'b', 303,
        'c', 310,
        'f', 236,
        'g', 341,
        'm', 231,
        'o', 280,
        'r', 277,
        't', 285,
        'w', 287,
        'y', 274,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 6,
        '$', 214,
        '/', 8,
        '>', 405,
        '[', 367,
        ']', 369,
        'e', 323,
        'n', 227,
        '{', 391,
        '}', 392,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(214);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '[') ADVANCE(367);
      if (lookahead == 'i') ADVANCE(324);
      if (lookahead == 'l') ADVANCE(228);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 6,
        ',', 368,
        '-', 12,
        '/', 8,
        ';', 384,
        'I', 134,
        '[', 367,
        ']', 369,
        'a', 122,
        'b', 148,
        'd', 71,
        'e', 128,
        'f', 15,
        'l', 16,
        'm', 173,
        'n', 20,
        'p', 94,
        's', 372,
        't', 163,
        'w', 167,
        'x', 375,
        '{', 391,
        '}', 392,
        '#', 406,
        '_', 406,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(414);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '"', 6,
        ',', 368,
        '-', 12,
        '/', 8,
        ';', 384,
        'I', 134,
        '[', 367,
        ']', 369,
        'a', 122,
        'b', 148,
        'd', 71,
        'e', 128,
        'f', 15,
        'l', 16,
        'n', 20,
        'p', 153,
        't', 163,
        'w', 167,
        '{', 391,
        '}', 392,
        '#', 406,
        '_', 406,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(414);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(370);
      if (lookahead == '\\') ADVANCE(215);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        ')', 422,
        ',', 368,
        '/', 8,
        ']', 369,
        'b', 306,
        'c', 307,
        'd', 270,
        'e', 338,
        'g', 330,
        'h', 291,
        'j', 343,
        'l', 334,
        'r', 229,
        's', 226,
        'u', 316,
        'w', 232,
        '}', 392,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(220);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(219);
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
      if (lookahead == 'd') ADVANCE(107);
      if (lookahead == 'm') ADVANCE(29);
      if (lookahead == 's') ADVANCE(57);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == 'I') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(414);
      END_STATE();
    case 13:
      if (lookahead == '_') ADVANCE(55);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(194);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(127);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(39);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(39);
      if (lookahead == 'o') ADVANCE(26);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(90);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(90);
      if (lookahead == 's') ADVANCE(372);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(131);
      if (lookahead == 'u') ADVANCE(119);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(204);
      if (lookahead == 'c') ADVANCE(168);
      if (lookahead == 'e') ADVANCE(169);
      if (lookahead == 'h') ADVANCE(149);
      if (lookahead == 'l') ADVANCE(158);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(377);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(161);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(40);
      if (lookahead == 'o') ADVANCE(41);
      if (lookahead == 'u') ADVANCE(58);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(174);
      if (lookahead == 'g') ADVANCE(146);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(48);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(120);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(201);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(160);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(99);
      if (lookahead == 'h') ADVANCE(100);
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(47);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(138);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(117);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(184);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(143);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(178);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(123);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(106);
      END_STATE();
    case 39:
      if (lookahead == 'b') ADVANCE(75);
      END_STATE();
    case 40:
      if (lookahead == 'c') ADVANCE(111);
      END_STATE();
    case 41:
      if (lookahead == 'c') ADVANCE(112);
      END_STATE();
    case 42:
      if (lookahead == 'c') ADVANCE(118);
      if (lookahead == 'd') ADVANCE(72);
      END_STATE();
    case 43:
      if (lookahead == 'c') ADVANCE(34);
      END_STATE();
    case 44:
      if (lookahead == 'c') ADVANCE(61);
      END_STATE();
    case 45:
      if (lookahead == 'd') ADVANCE(46);
      if (lookahead == 'l') ADVANCE(95);
      END_STATE();
    case 46:
      if (lookahead == 'd') ADVANCE(386);
      END_STATE();
    case 47:
      if (lookahead == 'd') ADVANCE(377);
      if (lookahead == 't') ADVANCE(200);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(430);
      END_STATE();
    case 49:
      if (lookahead == 'd') ADVANCE(418);
      END_STATE();
    case 50:
      if (lookahead == 'd') ADVANCE(449);
      END_STATE();
    case 51:
      if (lookahead == 'd') ADVANCE(59);
      END_STATE();
    case 52:
      if (lookahead == 'd') ADVANCE(76);
      END_STATE();
    case 53:
      if (lookahead == 'd') ADVANCE(69);
      END_STATE();
    case 54:
      if (lookahead == 'd') ADVANCE(70);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(110);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(85);
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(169);
      if (lookahead == 'l') ADVANCE(158);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(377);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(452);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(401);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(376);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(427);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(415);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(425);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(400);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(432);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(416);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(447);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(454);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(382);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(84);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(208);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(74);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(138);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(116);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(164);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(144);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(189);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(126);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(197);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(145);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(180);
      END_STATE();
    case 83:
      if (lookahead == 'f') ADVANCE(101);
      END_STATE();
    case 84:
      if (lookahead == 'f') ADVANCE(28);
      END_STATE();
    case 85:
      if (lookahead == 'f') ADVANCE(28);
      if (lookahead == 'l') ADVANCE(80);
      END_STATE();
    case 86:
      if (lookahead == 'g') ADVANCE(394);
      END_STATE();
    case 87:
      if (lookahead == 'g') ADVANCE(388);
      END_STATE();
    case 88:
      if (lookahead == 'g') ADVANCE(175);
      END_STATE();
    case 89:
      if (lookahead == 'g') ADVANCE(146);
      END_STATE();
    case 90:
      if (lookahead == 'g') ADVANCE(77);
      if (lookahead == 'p') ADVANCE(434);
      END_STATE();
    case 91:
      if (lookahead == 'h') ADVANCE(165);
      if (lookahead == 'r') ADVANCE(202);
      if (lookahead == 'w') ADVANCE(93);
      END_STATE();
    case 92:
      if (lookahead == 'h') ADVANCE(109);
      END_STATE();
    case 93:
      if (lookahead == 'i') ADVANCE(44);
      END_STATE();
    case 94:
      if (lookahead == 'i') ADVANCE(207);
      if (lookahead == 'o') ADVANCE(166);
      if (lookahead == 'x') ADVANCE(374);
      END_STATE();
    case 95:
      if (lookahead == 'i') ADVANCE(25);
      END_STATE();
    case 96:
      if (lookahead == 'i') ADVANCE(51);
      END_STATE();
    case 97:
      if (lookahead == 'i') ADVANCE(162);
      END_STATE();
    case 98:
      if (lookahead == 'i') ADVANCE(89);
      END_STATE();
    case 99:
      if (lookahead == 'i') ADVANCE(182);
      END_STATE();
    case 100:
      if (lookahead == 'i') ADVANCE(191);
      END_STATE();
    case 101:
      if (lookahead == 'i') ADVANCE(147);
      END_STATE();
    case 102:
      if (lookahead == 'i') ADVANCE(183);
      END_STATE();
    case 103:
      if (lookahead == 'i') ADVANCE(125);
      END_STATE();
    case 104:
      if (lookahead == 'i') ADVANCE(190);
      END_STATE();
    case 105:
      if (lookahead == 'i') ADVANCE(141);
      END_STATE();
    case 106:
      if (lookahead == 'i') ADVANCE(187);
      END_STATE();
    case 107:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 108:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 109:
      if (lookahead == 'i') ADVANCE(53);
      END_STATE();
    case 110:
      if (lookahead == 'i') ADVANCE(37);
      END_STATE();
    case 111:
      if (lookahead == 'k') ADVANCE(377);
      END_STATE();
    case 112:
      if (lookahead == 'k') ADVANCE(441);
      END_STATE();
    case 113:
      if (lookahead == 'l') ADVANCE(24);
      if (lookahead == 'o') ADVANCE(172);
      END_STATE();
    case 114:
      if (lookahead == 'l') ADVANCE(152);
      if (lookahead == 'o') ADVANCE(130);
      if (lookahead == 'y') ADVANCE(32);
      END_STATE();
    case 115:
      if (lookahead == 'l') ADVANCE(417);
      END_STATE();
    case 116:
      if (lookahead == 'l') ADVANCE(397);
      END_STATE();
    case 117:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 118:
      if (lookahead == 'l') ADVANCE(203);
      END_STATE();
    case 119:
      if (lookahead == 'l') ADVANCE(115);
      END_STATE();
    case 120:
      if (lookahead == 'l') ADVANCE(151);
      END_STATE();
    case 121:
      if (lookahead == 'l') ADVANCE(155);
      END_STATE();
    case 122:
      if (lookahead == 'l') ADVANCE(98);
      END_STATE();
    case 123:
      if (lookahead == 'l') ADVANCE(157);
      END_STATE();
    case 124:
      if (lookahead == 'l') ADVANCE(186);
      END_STATE();
    case 125:
      if (lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 126:
      if (lookahead == 'l') ADVANCE(121);
      END_STATE();
    case 127:
      if (lookahead == 'l') ADVANCE(179);
      END_STATE();
    case 128:
      if (lookahead == 'm') ADVANCE(156);
      if (lookahead == 'n') ADVANCE(199);
      END_STATE();
    case 129:
      if (lookahead == 'm') ADVANCE(156);
      if (lookahead == 'n') ADVANCE(199);
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 130:
      if (lookahead == 'm') ADVANCE(132);
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 131:
      if (lookahead == 'm') ADVANCE(60);
      END_STATE();
    case 132:
      if (lookahead == 'm') ADVANCE(35);
      END_STATE();
    case 133:
      if (lookahead == 'm') ADVANCE(81);
      END_STATE();
    case 134:
      if (lookahead == 'n') ADVANCE(83);
      END_STATE();
    case 135:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 136:
      if (lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 137:
      if (lookahead == 'n') ADVANCE(92);
      END_STATE();
    case 138:
      if (lookahead == 'n') ADVANCE(377);
      END_STATE();
    case 139:
      if (lookahead == 'n') ADVANCE(410);
      END_STATE();
    case 140:
      if (lookahead == 'n') ADVANCE(423);
      END_STATE();
    case 141:
      if (lookahead == 'n') ADVANCE(88);
      END_STATE();
    case 142:
      if (lookahead == 'n') ADVANCE(49);
      END_STATE();
    case 143:
      if (lookahead == 'n') ADVANCE(50);
      END_STATE();
    case 144:
      if (lookahead == 'n') ADVANCE(195);
      END_STATE();
    case 145:
      if (lookahead == 'n') ADVANCE(188);
      END_STATE();
    case 146:
      if (lookahead == 'n') ADVANCE(133);
      END_STATE();
    case 147:
      if (lookahead == 'n') ADVANCE(104);
      END_STATE();
    case 148:
      if (lookahead == 'o') ADVANCE(172);
      END_STATE();
    case 149:
      if (lookahead == 'o') ADVANCE(206);
      END_STATE();
    case 150:
      if (lookahead == 'o') ADVANCE(435);
      END_STATE();
    case 151:
      if (lookahead == 'o') ADVANCE(86);
      END_STATE();
    case 152:
      if (lookahead == 'o') ADVANCE(177);
      END_STATE();
    case 153:
      if (lookahead == 'o') ADVANCE(166);
      END_STATE();
    case 154:
      if (lookahead == 'o') ADVANCE(193);
      if (lookahead == 'r') ADVANCE(73);
      END_STATE();
    case 155:
      if (lookahead == 'o') ADVANCE(205);
      END_STATE();
    case 156:
      if (lookahead == 'o') ADVANCE(196);
      END_STATE();
    case 157:
      if (lookahead == 'o') ADVANCE(87);
      END_STATE();
    case 158:
      if (lookahead == 'o') ADVANCE(181);
      END_STATE();
    case 159:
      if (lookahead == 'o') ADVANCE(139);
      END_STATE();
    case 160:
      if (lookahead == 'p') ADVANCE(434);
      END_STATE();
    case 161:
      if (lookahead == 'p') ADVANCE(393);
      END_STATE();
    case 162:
      if (lookahead == 'p') ADVANCE(185);
      END_STATE();
    case 163:
      if (lookahead == 'r') ADVANCE(202);
      END_STATE();
    case 164:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 165:
      if (lookahead == 'r') ADVANCE(93);
      END_STATE();
    case 166:
      if (lookahead == 'r') ADVANCE(192);
      END_STATE();
    case 167:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 168:
      if (lookahead == 'r') ADVANCE(97);
      END_STATE();
    case 169:
      if (lookahead == 'r') ADVANCE(108);
      if (lookahead == 't') ADVANCE(198);
      END_STATE();
    case 170:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 171:
      if (lookahead == 'r') ADVANCE(140);
      END_STATE();
    case 172:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 173:
      if (lookahead == 's') ADVANCE(372);
      END_STATE();
    case 174:
      if (lookahead == 's') ADVANCE(451);
      END_STATE();
    case 175:
      if (lookahead == 's') ADVANCE(390);
      END_STATE();
    case 176:
      if (lookahead == 's') ADVANCE(159);
      END_STATE();
    case 177:
      if (lookahead == 's') ADVANCE(64);
      END_STATE();
    case 178:
      if (lookahead == 's') ADVANCE(66);
      END_STATE();
    case 179:
      if (lookahead == 's') ADVANCE(67);
      END_STATE();
    case 180:
      if (lookahead == 's') ADVANCE(78);
      END_STATE();
    case 181:
      if (lookahead == 't') ADVANCE(429);
      END_STATE();
    case 182:
      if (lookahead == 't') ADVANCE(439);
      END_STATE();
    case 183:
      if (lookahead == 't') ADVANCE(209);
      END_STATE();
    case 184:
      if (lookahead == 't') ADVANCE(445);
      END_STATE();
    case 185:
      if (lookahead == 't') ADVANCE(408);
      END_STATE();
    case 186:
      if (lookahead == 't') ADVANCE(396);
      END_STATE();
    case 187:
      if (lookahead == 't') ADVANCE(402);
      END_STATE();
    case 188:
      if (lookahead == 't') ADVANCE(403);
      END_STATE();
    case 189:
      if (lookahead == 't') ADVANCE(404);
      END_STATE();
    case 190:
      if (lookahead == 't') ADVANCE(210);
      END_STATE();
    case 191:
      if (lookahead == 't') ADVANCE(58);
      END_STATE();
    case 192:
      if (lookahead == 't') ADVANCE(170);
      END_STATE();
    case 193:
      if (lookahead == 't') ADVANCE(150);
      END_STATE();
    case 194:
      if (lookahead == 't') ADVANCE(103);
      END_STATE();
    case 195:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 196:
      if (lookahead == 't') ADVANCE(65);
      END_STATE();
    case 197:
      if (lookahead == 't') ADVANCE(68);
      END_STATE();
    case 198:
      if (lookahead == 't') ADVANCE(105);
      END_STATE();
    case 199:
      if (lookahead == 't') ADVANCE(102);
      END_STATE();
    case 200:
      if (lookahead == 'u') ADVANCE(171);
      END_STATE();
    case 201:
      if (lookahead == 'u') ADVANCE(124);
      END_STATE();
    case 202:
      if (lookahead == 'u') ADVANCE(63);
      END_STATE();
    case 203:
      if (lookahead == 'u') ADVANCE(54);
      END_STATE();
    case 204:
      if (lookahead == 'v') ADVANCE(62);
      END_STATE();
    case 205:
      if (lookahead == 'w') ADVANCE(377);
      END_STATE();
    case 206:
      if (lookahead == 'w') ADVANCE(443);
      END_STATE();
    case 207:
      if (lookahead == 'x') ADVANCE(374);
      END_STATE();
    case 208:
      if (lookahead == 'x') ADVANCE(437);
      END_STATE();
    case 209:
      if (lookahead == 'y') ADVANCE(399);
      END_STATE();
    case 210:
      if (lookahead == 'y') ADVANCE(413);
      END_STATE();
    case 211:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(213);
      END_STATE();
    case 212:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(380);
      END_STATE();
    case 213:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(212);
      END_STATE();
    case 214:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(381);
      END_STATE();
    case 215:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 216:
      if (eof) ADVANCE(218);
      ADVANCE_MAP(
        '!', 420,
        '"', 6,
        '#', 407,
        '$', 214,
        '(', 421,
        ')', 422,
        '+', 450,
        ',', 368,
        '-', 12,
        '/', 8,
        ':', 412,
        ';', 384,
        '=', 385,
        '>', 405,
        'I', 134,
        '[', 367,
        ']', 369,
        '_', 406,
        'a', 45,
        'b', 113,
        'c', 114,
        'd', 56,
        'e', 129,
        'f', 15,
        'g', 154,
        'h', 96,
        'i', 135,
        'j', 176,
        'l', 17,
        'm', 18,
        'n', 20,
        'o', 136,
        'p', 153,
        'r', 31,
        's', 21,
        't', 91,
        'u', 137,
        'w', 30,
        'y', 79,
        '{', 391,
        '}', 392,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(216);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      END_STATE();
    case 217:
      if (eof) ADVANCE(218);
      ADVANCE_MAP(
        '"', 6,
        '$', 214,
        '/', 8,
        ';', 384,
        '[', 367,
        ']', 369,
        'a', 253,
        'd', 288,
        'i', 315,
        's', 241,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(217);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(220);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(361);
      if (lookahead == 'h') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(321);
      if (lookahead == 'e') ADVANCE(352);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(302);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(244);
      if (lookahead == 'u') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(314);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(350);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(309);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(337);
      if (lookahead == 'e') ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(299);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(453);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(426);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(433);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(448);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(455);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(364);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(355);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(314);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(319);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(322);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(281);
      if (lookahead == 'n') ADVANCE(221);
      if (lookahead == 'p') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(395);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(389);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(339);
      if (lookahead == 'r') ADVANCE(360);
      if (lookahead == 'w') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(293);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(336);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(349);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(351);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(325);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(398);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(331);
      if (lookahead == 'o') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(332);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(335);
      if (lookahead == 'y') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(346);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(411);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(424);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(357);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(363);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(436);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(354);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(362);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(347);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(278);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(409);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(440);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(365);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(359);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(327);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(266);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(340);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(377);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(444);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(366);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(371);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(204);
      if (lookahead == 'c') ADVANCE(168);
      if (lookahead == 'e') ADVANCE(169);
      if (lookahead == 'h') ADVANCE(149);
      if (lookahead == 'l') ADVANCE(158);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(377);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(378);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(379);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(381);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_target_default);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(213);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(414);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(anon_sym_return);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(anon_sym_concat);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(anon_sym_concat);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(anon_sym_delete);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(anon_sym_delete);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(anon_sym_command);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(anon_sym_hide);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(anon_sym_hide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(anon_sym_unhide);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(anon_sym_unhide);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(366);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 217},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 7},
  [5] = {.lex_state = 7},
  [6] = {.lex_state = 7},
  [7] = {.lex_state = 7},
  [8] = {.lex_state = 7},
  [9] = {.lex_state = 7},
  [10] = {.lex_state = 7},
  [11] = {.lex_state = 7},
  [12] = {.lex_state = 7},
  [13] = {.lex_state = 7},
  [14] = {.lex_state = 7},
  [15] = {.lex_state = 7},
  [16] = {.lex_state = 7},
  [17] = {.lex_state = 217},
  [18] = {.lex_state = 217},
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
  [37] = {.lex_state = 7},
  [38] = {.lex_state = 7},
  [39] = {.lex_state = 7},
  [40] = {.lex_state = 7},
  [41] = {.lex_state = 7},
  [42] = {.lex_state = 4},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 4},
  [47] = {.lex_state = 4},
  [48] = {.lex_state = 4},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 217},
  [51] = {.lex_state = 217},
  [52] = {.lex_state = 217},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 1},
  [55] = {.lex_state = 217},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 217},
  [58] = {.lex_state = 217},
  [59] = {.lex_state = 217},
  [60] = {.lex_state = 217},
  [61] = {.lex_state = 217},
  [62] = {.lex_state = 217},
  [63] = {.lex_state = 217},
  [64] = {.lex_state = 217},
  [65] = {.lex_state = 217},
  [66] = {.lex_state = 217},
  [67] = {.lex_state = 4},
  [68] = {.lex_state = 4},
  [69] = {.lex_state = 217},
  [70] = {.lex_state = 217},
  [71] = {.lex_state = 4},
  [72] = {.lex_state = 4},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 4},
  [75] = {.lex_state = 4},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 3},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 2},
  [94] = {.lex_state = 2},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 217},
  [99] = {.lex_state = 217},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 4},
  [104] = {.lex_state = 2},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 4},
  [107] = {.lex_state = 4},
  [108] = {.lex_state = 2},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 217},
  [113] = {.lex_state = 217},
  [114] = {.lex_state = 2},
  [115] = {.lex_state = 4},
  [116] = {.lex_state = 4},
  [117] = {.lex_state = 2},
  [118] = {.lex_state = 217},
  [119] = {.lex_state = 217},
  [120] = {.lex_state = 217},
  [121] = {.lex_state = 4},
  [122] = {.lex_state = 4},
  [123] = {.lex_state = 4},
  [124] = {.lex_state = 2},
  [125] = {.lex_state = 2},
  [126] = {.lex_state = 4},
  [127] = {.lex_state = 2},
  [128] = {.lex_state = 2},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 2},
  [132] = {.lex_state = 2},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 217},
  [135] = {.lex_state = 2},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 4},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 2},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 2},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 217},
  [157] = {.lex_state = 217},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 2},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 2},
  [165] = {.lex_state = 2},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 217},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 2},
  [172] = {.lex_state = 2},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 217},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 0},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 2},
  [179] = {.lex_state = 2},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 2},
  [183] = {.lex_state = 217},
  [184] = {.lex_state = 217},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 0},
  [187] = {.lex_state = 2},
  [188] = {.lex_state = 4},
  [189] = {.lex_state = 11},
  [190] = {.lex_state = 0},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 2},
  [195] = {.lex_state = 0},
  [196] = {.lex_state = 217},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 0},
  [201] = {.lex_state = 0},
  [202] = {.lex_state = 0},
  [203] = {.lex_state = 11},
  [204] = {.lex_state = 0},
  [205] = {.lex_state = 0},
  [206] = {.lex_state = 0},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 0},
  [210] = {.lex_state = 11},
  [211] = {.lex_state = 4},
  [212] = {.lex_state = 0},
  [213] = {.lex_state = 217},
  [214] = {.lex_state = 2},
  [215] = {.lex_state = 11},
  [216] = {.lex_state = 0},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 0},
  [220] = {.lex_state = 11},
  [221] = {.lex_state = 0},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 0},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 11},
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
  [237] = {.lex_state = 0},
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
  [254] = {.lex_state = 11},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 0},
  [257] = {.lex_state = 0},
  [258] = {.lex_state = 0},
  [259] = {.lex_state = 0},
  [260] = {.lex_state = 0},
  [261] = {.lex_state = 0},
  [262] = {.lex_state = 0},
  [263] = {.lex_state = 0},
  [264] = {.lex_state = 0},
  [265] = {.lex_state = 0},
  [266] = {.lex_state = 11},
  [267] = {.lex_state = 0},
  [268] = {.lex_state = 0},
  [269] = {.lex_state = 0},
  [270] = {.lex_state = 0},
  [271] = {.lex_state = 11},
  [272] = {.lex_state = 0},
  [273] = {.lex_state = 0},
  [274] = {.lex_state = 0},
  [275] = {.lex_state = 0},
  [276] = {.lex_state = 0},
  [277] = {.lex_state = 0},
  [278] = {.lex_state = 0},
  [279] = {.lex_state = 0},
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
    [anon_sym_delete] = ACTIONS(1),
    [anon_sym_command] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_alias] = ACTIONS(1),
    [anon_sym_hide] = ACTIONS(1),
    [anon_sym_unhide] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(216),
    [sym__root] = STATE(18),
    [sym_include_macro] = STATE(18),
    [sym_constant_assignment] = STATE(18),
    [sym_add_serial_dialog_settings] = STATE(18),
    [sym_add_dialog_settings] = STATE(18),
    [sym_dialog_definition] = STATE(18),
    [sym_serial_dialog_definition] = STATE(18),
    [sym_script_definition] = STATE(18),
    [aux_sym_document_repeat1] = STATE(18),
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
  [0] = 19,
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
    ACTIONS(64), 1,
      anon_sym_delete,
    ACTIONS(67), 1,
      anon_sym_hide,
    ACTIONS(70), 1,
      anon_sym_unhide,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(26), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(2), 26,
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
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      aux_sym_script_block_repeat1,
  [85] = 19,
    ACTIONS(73), 1,
      sym_BAREWORD,
    ACTIONS(75), 1,
      anon_sym_RBRACE,
    ACTIONS(77), 1,
      anon_sym_json,
    ACTIONS(79), 1,
      anon_sym_rand,
    ACTIONS(81), 1,
      anon_sym_return,
    ACTIONS(83), 1,
      anon_sym_close,
    ACTIONS(85), 1,
      anon_sym_save,
    ACTIONS(87), 1,
      anon_sym_load,
    ACTIONS(89), 1,
      anon_sym_erase,
    ACTIONS(91), 1,
      anon_sym_goto,
    ACTIONS(93), 1,
      anon_sym_wait,
    ACTIONS(95), 1,
      anon_sym_block,
    ACTIONS(97), 1,
      anon_sym_show,
    ACTIONS(99), 1,
      anon_sym_concat,
    ACTIONS(101), 1,
      anon_sym_delete,
    ACTIONS(103), 1,
      anon_sym_hide,
    ACTIONS(105), 1,
      anon_sym_unhide,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(5), 26,
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
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      aux_sym_script_block_repeat1,
  [169] = 19,
    ACTIONS(73), 1,
      sym_BAREWORD,
    ACTIONS(77), 1,
      anon_sym_json,
    ACTIONS(79), 1,
      anon_sym_rand,
    ACTIONS(81), 1,
      anon_sym_return,
    ACTIONS(83), 1,
      anon_sym_close,
    ACTIONS(85), 1,
      anon_sym_save,
    ACTIONS(87), 1,
      anon_sym_load,
    ACTIONS(89), 1,
      anon_sym_erase,
    ACTIONS(91), 1,
      anon_sym_goto,
    ACTIONS(93), 1,
      anon_sym_wait,
    ACTIONS(95), 1,
      anon_sym_block,
    ACTIONS(97), 1,
      anon_sym_show,
    ACTIONS(99), 1,
      anon_sym_concat,
    ACTIONS(101), 1,
      anon_sym_delete,
    ACTIONS(103), 1,
      anon_sym_hide,
    ACTIONS(105), 1,
      anon_sym_unhide,
    ACTIONS(107), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(6), 26,
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
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      aux_sym_script_block_repeat1,
  [253] = 19,
    ACTIONS(73), 1,
      sym_BAREWORD,
    ACTIONS(77), 1,
      anon_sym_json,
    ACTIONS(79), 1,
      anon_sym_rand,
    ACTIONS(81), 1,
      anon_sym_return,
    ACTIONS(83), 1,
      anon_sym_close,
    ACTIONS(85), 1,
      anon_sym_save,
    ACTIONS(87), 1,
      anon_sym_load,
    ACTIONS(89), 1,
      anon_sym_erase,
    ACTIONS(91), 1,
      anon_sym_goto,
    ACTIONS(93), 1,
      anon_sym_wait,
    ACTIONS(95), 1,
      anon_sym_block,
    ACTIONS(97), 1,
      anon_sym_show,
    ACTIONS(99), 1,
      anon_sym_concat,
    ACTIONS(101), 1,
      anon_sym_delete,
    ACTIONS(103), 1,
      anon_sym_hide,
    ACTIONS(105), 1,
      anon_sym_unhide,
    ACTIONS(109), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 26,
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
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      aux_sym_script_block_repeat1,
  [337] = 19,
    ACTIONS(73), 1,
      sym_BAREWORD,
    ACTIONS(77), 1,
      anon_sym_json,
    ACTIONS(79), 1,
      anon_sym_rand,
    ACTIONS(81), 1,
      anon_sym_return,
    ACTIONS(83), 1,
      anon_sym_close,
    ACTIONS(85), 1,
      anon_sym_save,
    ACTIONS(87), 1,
      anon_sym_load,
    ACTIONS(89), 1,
      anon_sym_erase,
    ACTIONS(91), 1,
      anon_sym_goto,
    ACTIONS(93), 1,
      anon_sym_wait,
    ACTIONS(95), 1,
      anon_sym_block,
    ACTIONS(97), 1,
      anon_sym_show,
    ACTIONS(99), 1,
      anon_sym_concat,
    ACTIONS(101), 1,
      anon_sym_delete,
    ACTIONS(103), 1,
      anon_sym_hide,
    ACTIONS(105), 1,
      anon_sym_unhide,
    ACTIONS(111), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 26,
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
      sym_action_delete_command,
      sym_action_delete_command_arg,
      sym_action_delete_alias,
      sym_action_hide_command,
      sym_action_unhide_command,
      aux_sym_script_block_repeat1,
  [421] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(115), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(113), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [450] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(119), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(117), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [479] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(123), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(121), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [508] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(127), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(125), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [535] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(131), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(129), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [562] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(135), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(133), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [589] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(139), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(137), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [616] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(143), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(141), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [643] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(147), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(145), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [670] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(151), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(149), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [697] = 11,
    ACTIONS(153), 1,
      ts_builtin_sym_end,
    ACTIONS(155), 1,
      sym_BAREWORD,
    ACTIONS(158), 1,
      sym_QUOTED_STRING,
    ACTIONS(161), 1,
      sym_CONSTANT,
    ACTIONS(164), 1,
      anon_sym_include,
    ACTIONS(167), 1,
      anon_sym_add,
    ACTIONS(170), 1,
      anon_sym_serial_dialog,
    ACTIONS(173), 1,
      anon_sym_dialog,
    ACTIONS(176), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(17), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [740] = 11,
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
    ACTIONS(179), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(17), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [783] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(183), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(181), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [810] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(187), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(185), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [837] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(191), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(189), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [864] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(195), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(193), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [891] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(199), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(197), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [918] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(203), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(201), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [945] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(207), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(205), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [972] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(211), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(209), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [999] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(215), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(213), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1026] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(219), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(217), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1053] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(223), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(221), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1080] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(227), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(225), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1107] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(231), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(229), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1134] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(235), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(233), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1161] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(239), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(237), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1188] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(243), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(241), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1215] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(247), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(245), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1242] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(251), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(249), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1269] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(255), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(253), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1296] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(259), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(257), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1323] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(263), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(261), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1350] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(267), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(265), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1377] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(271), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(269), 16,
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
      anon_sym_delete,
      anon_sym_hide,
      anon_sym_unhide,
  [1404] = 9,
    ACTIONS(273), 1,
      sym_QUOTED_STRING,
    STATE(43), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(67), 1,
      sym_dialog_parameter,
    STATE(77), 1,
      aux_sym_dialog_repeat1,
    STATE(135), 1,
      sym__dialog_parameter_string,
    STATE(196), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(275), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(277), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1438] = 8,
    STATE(43), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(67), 1,
      sym_dialog_parameter,
    STATE(135), 1,
      sym__dialog_parameter_string,
    STATE(196), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(279), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    ACTIONS(281), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(284), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1470] = 9,
    ACTIONS(273), 1,
      sym_QUOTED_STRING,
    STATE(42), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(67), 1,
      sym_dialog_parameter,
    STATE(76), 1,
      aux_sym_dialog_repeat1,
    STATE(135), 1,
      sym__dialog_parameter_string,
    STATE(196), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(275), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(277), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1504] = 8,
    ACTIONS(287), 1,
      anon_sym_RBRACE,
    STATE(46), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(67), 1,
      sym_dialog_parameter,
    STATE(135), 1,
      sym__dialog_parameter_string,
    STATE(196), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(275), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(277), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1535] = 8,
    ACTIONS(289), 1,
      anon_sym_RBRACE,
    STATE(43), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(67), 1,
      sym_dialog_parameter,
    STATE(135), 1,
      sym__dialog_parameter_string,
    STATE(196), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(275), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(277), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1566] = 8,
    ACTIONS(291), 1,
      anon_sym_RBRACE,
    STATE(48), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(67), 1,
      sym_dialog_parameter,
    STATE(135), 1,
      sym__dialog_parameter_string,
    STATE(196), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(275), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(277), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1597] = 8,
    ACTIONS(293), 1,
      anon_sym_RBRACE,
    STATE(43), 1,
      aux_sym_add_dialog_settings_target_repeat1,
    STATE(67), 1,
      sym_dialog_parameter,
    STATE(135), 1,
      sym__dialog_parameter_string,
    STATE(196), 1,
      sym__dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(275), 2,
      anon_sym_wrap,
      anon_sym_emote,
    ACTIONS(277), 5,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1628] = 6,
    ACTIONS(295), 1,
      anon_sym_LBRACK,
    ACTIONS(297), 1,
      anon_sym_RBRACK,
    ACTIONS(301), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(151), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(299), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1654] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(303), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(305), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1673] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(307), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(309), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1692] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(311), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(313), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1711] = 5,
    ACTIONS(295), 1,
      anon_sym_LBRACK,
    ACTIONS(301), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(195), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(315), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1734] = 6,
    ACTIONS(321), 1,
      sym_NUMBER,
    ACTIONS(323), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(317), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(319), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(269), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [1759] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(325), 4,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(327), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1778] = 5,
    ACTIONS(295), 1,
      anon_sym_LBRACK,
    ACTIONS(301), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(204), 3,
      sym_json_array,
      sym_json_object,
      sym__json_item,
    ACTIONS(329), 5,
      sym_QUOTED_STRING,
      sym_json_number,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
  [1801] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(331), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(333), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1819] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(335), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(337), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1837] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(339), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(341), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1855] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(343), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(345), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1873] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(347), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(349), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1891] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(351), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(353), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1909] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(355), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(357), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1927] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(359), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(361), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1945] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(363), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(365), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1963] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(367), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(369), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1981] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(371), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [1997] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(373), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2013] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(375), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(377), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2031] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(379), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(381), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [2049] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(383), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2064] = 8,
    ACTIONS(385), 1,
      anon_sym_RBRACE,
    ACTIONS(387), 1,
      sym_target_default,
    ACTIONS(389), 1,
      anon_sym_label,
    ACTIONS(391), 1,
      anon_sym_entity,
    STATE(132), 1,
      sym_target_entity,
    STATE(179), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(75), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2091] = 8,
    ACTIONS(387), 1,
      sym_target_default,
    ACTIONS(389), 1,
      anon_sym_label,
    ACTIONS(391), 1,
      anon_sym_entity,
    ACTIONS(393), 1,
      anon_sym_RBRACE,
    STATE(132), 1,
      sym_target_entity,
    STATE(179), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(72), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2118] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(395), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_emote,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
  [2133] = 8,
    ACTIONS(397), 1,
      anon_sym_RBRACE,
    ACTIONS(399), 1,
      sym_target_default,
    ACTIONS(402), 1,
      anon_sym_label,
    ACTIONS(405), 1,
      anon_sym_entity,
    STATE(132), 1,
      sym_target_entity,
    STATE(179), 1,
      sym_target_label,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(75), 2,
      sym_add_dialog_settings_target,
      aux_sym_add_dialog_settings_repeat1,
  [2160] = 8,
    ACTIONS(273), 1,
      sym_QUOTED_STRING,
    ACTIONS(410), 1,
      sym_identifier_type,
    ACTIONS(412), 1,
      anon_sym_GT,
    STATE(84), 1,
      aux_sym_dialog_repeat2,
    STATE(86), 1,
      aux_sym_dialog_repeat1,
    STATE(105), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(408), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2187] = 8,
    ACTIONS(273), 1,
      sym_QUOTED_STRING,
    ACTIONS(412), 1,
      anon_sym_GT,
    ACTIONS(416), 1,
      sym_identifier_type,
    STATE(86), 1,
      aux_sym_dialog_repeat1,
    STATE(89), 1,
      aux_sym_dialog_repeat2,
    STATE(105), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2214] = 9,
    ACTIONS(418), 1,
      sym_QUOTED_STRING,
    ACTIONS(420), 1,
      anon_sym_RBRACE,
    ACTIONS(422), 1,
      anon_sym_wrap,
    STATE(85), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(87), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(184), 1,
      sym_serial_dialog_parameter_int,
    STATE(185), 1,
      sym_serial_dialog_parameter,
    STATE(230), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2243] = 7,
    ACTIONS(424), 1,
      sym_BAREWORD,
    ACTIONS(426), 1,
      anon_sym_LBRACK,
    ACTIONS(430), 1,
      anon_sym_label,
    ACTIONS(432), 1,
      anon_sym_index,
    STATE(247), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(428), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2267] = 7,
    ACTIONS(434), 1,
      sym_BAREWORD,
    ACTIONS(437), 1,
      anon_sym_RBRACE,
    ACTIONS(439), 1,
      sym_identifier_type,
    STATE(44), 1,
      sym_dialog_identifier,
    STATE(80), 1,
      aux_sym__dialog_block_repeat1,
    STATE(149), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2290] = 6,
    ACTIONS(444), 1,
      sym_identifier_type,
    ACTIONS(446), 1,
      anon_sym_GT,
    STATE(81), 1,
      aux_sym_dialog_repeat2,
    STATE(105), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(442), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2311] = 7,
    ACTIONS(449), 1,
      sym_BAREWORD,
    ACTIONS(451), 1,
      anon_sym_RBRACE,
    ACTIONS(453), 1,
      sym_identifier_type,
    STATE(44), 1,
      sym_dialog_identifier,
    STATE(88), 1,
      aux_sym__dialog_block_repeat1,
    STATE(149), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2334] = 7,
    ACTIONS(418), 1,
      sym_QUOTED_STRING,
    ACTIONS(455), 1,
      anon_sym_RBRACE,
    ACTIONS(457), 1,
      sym_serial_dialog_option_type,
    STATE(109), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(115), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(188), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2357] = 6,
    ACTIONS(412), 1,
      anon_sym_GT,
    ACTIONS(461), 1,
      sym_identifier_type,
    STATE(81), 1,
      aux_sym_dialog_repeat2,
    STATE(105), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(459), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2378] = 7,
    ACTIONS(418), 1,
      sym_QUOTED_STRING,
    ACTIONS(457), 1,
      sym_serial_dialog_option_type,
    ACTIONS(463), 1,
      anon_sym_RBRACE,
    STATE(106), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(115), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(188), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2401] = 5,
    ACTIONS(467), 1,
      sym_QUOTED_STRING,
    ACTIONS(470), 1,
      sym_identifier_type,
    STATE(86), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(465), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2420] = 7,
    ACTIONS(418), 1,
      sym_QUOTED_STRING,
    ACTIONS(422), 1,
      anon_sym_wrap,
    STATE(83), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(96), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(184), 1,
      sym_serial_dialog_parameter_int,
    STATE(185), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2443] = 7,
    ACTIONS(449), 1,
      sym_BAREWORD,
    ACTIONS(453), 1,
      sym_identifier_type,
    ACTIONS(472), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      sym_dialog_identifier,
    STATE(80), 1,
      aux_sym__dialog_block_repeat1,
    STATE(149), 1,
      sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2466] = 6,
    ACTIONS(412), 1,
      anon_sym_GT,
    ACTIONS(476), 1,
      sym_identifier_type,
    STATE(81), 1,
      aux_sym_dialog_repeat2,
    STATE(105), 1,
      sym_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(474), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [2487] = 4,
    ACTIONS(426), 1,
      anon_sym_LBRACK,
    STATE(223), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(478), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2503] = 4,
    ACTIONS(426), 1,
      anon_sym_LBRACK,
    STATE(225), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(480), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2519] = 5,
    ACTIONS(422), 1,
      anon_sym_wrap,
    ACTIONS(482), 1,
      anon_sym_RBRACE,
    STATE(184), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(97), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2537] = 4,
    ACTIONS(426), 1,
      anon_sym_LBRACK,
    STATE(244), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(484), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2553] = 4,
    ACTIONS(426), 1,
      anon_sym_LBRACK,
    STATE(243), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(486), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2569] = 4,
    ACTIONS(426), 1,
      anon_sym_LBRACK,
    STATE(199), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(488), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2585] = 6,
    ACTIONS(490), 1,
      sym_QUOTED_STRING,
    ACTIONS(492), 1,
      anon_sym_wrap,
    STATE(96), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(184), 1,
      sym_serial_dialog_parameter_int,
    STATE(185), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2605] = 5,
    ACTIONS(495), 1,
      anon_sym_RBRACE,
    ACTIONS(497), 1,
      anon_sym_wrap,
    STATE(184), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(97), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2623] = 5,
    ACTIONS(500), 1,
      anon_sym_LBRACK,
    ACTIONS(502), 1,
      sym_NUMBER,
    ACTIONS(504), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(232), 2,
      sym_DURATION,
      sym_duration_expansion,
  [2641] = 5,
    ACTIONS(500), 1,
      anon_sym_LBRACK,
    ACTIONS(502), 1,
      sym_NUMBER,
    ACTIONS(506), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(228), 2,
      sym_DURATION,
      sym_duration_expansion,
  [2659] = 5,
    ACTIONS(422), 1,
      anon_sym_wrap,
    ACTIONS(508), 1,
      anon_sym_RBRACE,
    STATE(184), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(92), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [2677] = 3,
    ACTIONS(512), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(510), 4,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2691] = 4,
    ACTIONS(426), 1,
      anon_sym_LBRACK,
    STATE(238), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(514), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2707] = 5,
    ACTIONS(516), 1,
      anon_sym_RBRACE,
    ACTIONS(518), 1,
      sym_serial_dialog_option_type,
    STATE(103), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(188), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2724] = 4,
    ACTIONS(523), 1,
      anon_sym_LBRACE,
    STATE(277), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(521), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2739] = 3,
    ACTIONS(527), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(525), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [2752] = 5,
    ACTIONS(457), 1,
      sym_serial_dialog_option_type,
    ACTIONS(529), 1,
      anon_sym_RBRACE,
    STATE(103), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(188), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2769] = 5,
    ACTIONS(531), 1,
      sym_duration_suffix,
    ACTIONS(533), 1,
      sym_distance_suffix,
    ACTIONS(535), 1,
      sym_quantity_suffix,
    ACTIONS(537), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2786] = 4,
    ACTIONS(541), 1,
      anon_sym_LBRACE,
    STATE(268), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(539), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [2801] = 5,
    ACTIONS(457), 1,
      sym_serial_dialog_option_type,
    ACTIONS(543), 1,
      anon_sym_RBRACE,
    STATE(103), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(188), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2818] = 4,
    ACTIONS(545), 1,
      anon_sym_LBRACK,
    STATE(261), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(547), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2833] = 3,
    ACTIONS(551), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(549), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2846] = 5,
    ACTIONS(502), 1,
      sym_NUMBER,
    ACTIONS(553), 1,
      anon_sym_RBRACK,
    ACTIONS(555), 1,
      sym_CONSTANT,
    STATE(200), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2863] = 4,
    ACTIONS(557), 1,
      anon_sym_LBRACK,
    STATE(240), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(559), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2878] = 3,
    ACTIONS(563), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(561), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [2891] = 4,
    ACTIONS(565), 1,
      sym_QUOTED_STRING,
    STATE(115), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(568), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2906] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(570), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [2917] = 4,
    ACTIONS(574), 1,
      anon_sym_LBRACK,
    STATE(245), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(572), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [2932] = 4,
    ACTIONS(557), 1,
      anon_sym_LBRACK,
    STATE(248), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(576), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2947] = 5,
    ACTIONS(502), 1,
      sym_NUMBER,
    ACTIONS(555), 1,
      sym_CONSTANT,
    ACTIONS(578), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2964] = 4,
    ACTIONS(557), 1,
      anon_sym_LBRACK,
    STATE(231), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(580), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [2979] = 3,
    ACTIONS(531), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(582), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [2992] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(584), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [3003] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(586), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [3014] = 3,
    ACTIONS(588), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(549), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3027] = 4,
    ACTIONS(541), 1,
      anon_sym_LBRACE,
    STATE(270), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(590), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3042] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(592), 4,
      anon_sym_RBRACE,
      sym_target_default,
      anon_sym_label,
      anon_sym_entity,
  [3053] = 3,
    ACTIONS(596), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(594), 3,
      sym_BAREWORD,
      anon_sym_RBRACE,
      anon_sym_GT,
  [3066] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(598), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3076] = 3,
    ACTIONS(600), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(602), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3088] = 4,
    ACTIONS(604), 1,
      anon_sym_COMMA,
    ACTIONS(607), 1,
      anon_sym_RBRACK,
    STATE(130), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3102] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(609), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3112] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(611), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3122] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(613), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [3132] = 4,
    ACTIONS(502), 1,
      sym_NUMBER,
    ACTIONS(615), 1,
      sym_CONSTANT,
    STATE(166), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3146] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(617), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3156] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(619), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [3166] = 4,
    ACTIONS(621), 1,
      anon_sym_COMMA,
    ACTIONS(623), 1,
      anon_sym_RBRACE,
    STATE(153), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3180] = 4,
    ACTIONS(625), 1,
      anon_sym_COMMA,
    ACTIONS(627), 1,
      anon_sym_RBRACK,
    STATE(155), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3194] = 4,
    ACTIONS(629), 1,
      anon_sym_COMMA,
    ACTIONS(631), 1,
      anon_sym_RBRACK,
    STATE(158), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3208] = 4,
    ACTIONS(588), 1,
      anon_sym_RBRACK,
    ACTIONS(633), 1,
      anon_sym_COMMA,
    STATE(159), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3222] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(635), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [3232] = 4,
    ACTIONS(637), 1,
      anon_sym_COMMA,
    ACTIONS(639), 1,
      anon_sym_RBRACK,
    STATE(161), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3246] = 4,
    ACTIONS(578), 1,
      anon_sym_RBRACK,
    ACTIONS(641), 1,
      anon_sym_COMMA,
    STATE(162), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3260] = 3,
    ACTIONS(643), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(602), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3272] = 4,
    ACTIONS(643), 1,
      anon_sym_RBRACK,
    ACTIONS(645), 1,
      anon_sym_COMMA,
    STATE(130), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3286] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(647), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3296] = 4,
    ACTIONS(649), 1,
      anon_sym_COMMA,
    ACTIONS(651), 1,
      anon_sym_RBRACK,
    STATE(145), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3310] = 3,
    ACTIONS(653), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(655), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3322] = 3,
    ACTIONS(659), 1,
      sym_identifier_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(657), 2,
      sym_BAREWORD,
      anon_sym_RBRACE,
  [3334] = 4,
    ACTIONS(661), 1,
      sym_QUOTED_STRING,
    ACTIONS(663), 1,
      anon_sym_RBRACE,
    STATE(137), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3348] = 4,
    ACTIONS(625), 1,
      anon_sym_COMMA,
    ACTIONS(665), 1,
      anon_sym_RBRACK,
    STATE(138), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3362] = 4,
    ACTIONS(541), 1,
      anon_sym_LBRACE,
    ACTIONS(667), 1,
      anon_sym_SEMI,
    STATE(218), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3376] = 4,
    ACTIONS(621), 1,
      anon_sym_COMMA,
    ACTIONS(669), 1,
      anon_sym_RBRACE,
    STATE(168), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3390] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(671), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3400] = 4,
    ACTIONS(673), 1,
      anon_sym_COMMA,
    ACTIONS(676), 1,
      anon_sym_RBRACK,
    STATE(155), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3414] = 3,
    ACTIONS(678), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(680), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3426] = 3,
    ACTIONS(682), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(684), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3438] = 4,
    ACTIONS(682), 1,
      anon_sym_RBRACK,
    ACTIONS(686), 1,
      anon_sym_COMMA,
    STATE(170), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3452] = 4,
    ACTIONS(688), 1,
      anon_sym_COMMA,
    ACTIONS(691), 1,
      anon_sym_RBRACK,
    STATE(159), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3466] = 3,
    ACTIONS(695), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(693), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3478] = 4,
    ACTIONS(695), 1,
      anon_sym_RBRACK,
    ACTIONS(697), 1,
      anon_sym_COMMA,
    STATE(173), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3492] = 4,
    ACTIONS(699), 1,
      anon_sym_COMMA,
    ACTIONS(702), 1,
      anon_sym_RBRACK,
    STATE(162), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3506] = 4,
    ACTIONS(704), 1,
      anon_sym_COMMA,
    ACTIONS(706), 1,
      anon_sym_RBRACK,
    STATE(140), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3520] = 3,
    ACTIONS(710), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(708), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3532] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(712), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3542] = 4,
    ACTIONS(714), 1,
      anon_sym_COMMA,
    ACTIONS(716), 1,
      anon_sym_RBRACK,
    STATE(143), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3556] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(718), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [3566] = 4,
    ACTIONS(720), 1,
      anon_sym_COMMA,
    ACTIONS(723), 1,
      anon_sym_RBRACE,
    STATE(168), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3580] = 3,
    ACTIONS(725), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(684), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3592] = 4,
    ACTIONS(727), 1,
      anon_sym_COMMA,
    ACTIONS(730), 1,
      anon_sym_RBRACK,
    STATE(170), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3606] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(549), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3616] = 3,
    ACTIONS(732), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(693), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3628] = 4,
    ACTIONS(734), 1,
      anon_sym_COMMA,
    ACTIONS(737), 1,
      anon_sym_RBRACK,
    STATE(173), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3642] = 4,
    ACTIONS(502), 1,
      sym_NUMBER,
    ACTIONS(555), 1,
      sym_CONSTANT,
    STATE(200), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3656] = 4,
    ACTIONS(541), 1,
      anon_sym_LBRACE,
    ACTIONS(739), 1,
      anon_sym_SEMI,
    STATE(237), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3670] = 4,
    ACTIONS(523), 1,
      anon_sym_LBRACE,
    ACTIONS(741), 1,
      anon_sym_SEMI,
    STATE(276), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3684] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(743), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RBRACE,
  [3694] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(745), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3703] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(611), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3712] = 3,
    ACTIONS(295), 1,
      anon_sym_LBRACK,
    STATE(39), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3723] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(607), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3732] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(747), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3741] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(749), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3750] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(751), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3759] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(753), 2,
      sym_QUOTED_STRING,
      anon_sym_wrap,
  [3768] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(602), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [3777] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(755), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [3786] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(757), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [3795] = 3,
    ACTIONS(759), 1,
      anon_sym_serial_dialog,
    ACTIONS(761), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3806] = 3,
    ACTIONS(541), 1,
      anon_sym_LBRACE,
    STATE(57), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3817] = 3,
    ACTIONS(523), 1,
      anon_sym_LBRACE,
    STATE(58), 1,
      sym__dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3828] = 3,
    ACTIONS(763), 1,
      anon_sym_LBRACE,
    STATE(59), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3839] = 3,
    ACTIONS(661), 1,
      sym_QUOTED_STRING,
    STATE(205), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3850] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(765), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [3859] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(676), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3868] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(617), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [3877] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(691), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3886] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(767), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [3895] = 3,
    ACTIONS(769), 1,
      anon_sym_SEMI,
    ACTIONS(771), 1,
      anon_sym_PLUS,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3906] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(702), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3915] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(773), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [3924] = 3,
    ACTIONS(763), 1,
      anon_sym_LBRACE,
    STATE(60), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3935] = 3,
    ACTIONS(775), 1,
      anon_sym_serial_dialog,
    ACTIONS(777), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3946] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(779), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [3955] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(723), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [3964] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(730), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3973] = 3,
    ACTIONS(781), 1,
      anon_sym_command,
    ACTIONS(783), 1,
      anon_sym_alias,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [3984] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(785), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [3993] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(737), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4002] = 3,
    ACTIONS(787), 1,
      anon_sym_serial_dialog,
    ACTIONS(789), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4013] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(791), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [4022] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(793), 2,
      anon_sym_SEMI,
      anon_sym_PLUS,
  [4031] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(684), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [4040] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(693), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [4049] = 3,
    ACTIONS(795), 1,
      anon_sym_slot,
    ACTIONS(797), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4060] = 2,
    ACTIONS(799), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4068] = 2,
    ACTIONS(801), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4076] = 2,
    ACTIONS(803), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4084] = 2,
    ACTIONS(805), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4092] = 2,
    ACTIONS(807), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4100] = 2,
    ACTIONS(809), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4108] = 2,
    ACTIONS(811), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4116] = 2,
    ACTIONS(813), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4124] = 2,
    ACTIONS(815), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4132] = 2,
    ACTIONS(817), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4140] = 2,
    ACTIONS(819), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4148] = 2,
    ACTIONS(821), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4156] = 2,
    ACTIONS(823), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4164] = 2,
    ACTIONS(825), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4172] = 2,
    ACTIONS(827), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4180] = 2,
    ACTIONS(829), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4188] = 2,
    ACTIONS(831), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4196] = 2,
    ACTIONS(833), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4204] = 2,
    ACTIONS(835), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4212] = 2,
    ACTIONS(837), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4220] = 2,
    ACTIONS(839), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4228] = 2,
    ACTIONS(841), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4236] = 2,
    ACTIONS(843), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4244] = 2,
    ACTIONS(845), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4252] = 2,
    ACTIONS(847), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4260] = 2,
    ACTIONS(849), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4268] = 2,
    ACTIONS(851), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4276] = 2,
    ACTIONS(853), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4284] = 2,
    ACTIONS(855), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4292] = 2,
    ACTIONS(857), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4300] = 2,
    ACTIONS(859), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4308] = 2,
    ACTIONS(861), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4316] = 2,
    ACTIONS(863), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4324] = 2,
    ACTIONS(865), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4332] = 2,
    ACTIONS(867), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4340] = 2,
    ACTIONS(869), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4348] = 2,
    ACTIONS(871), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4356] = 2,
    ACTIONS(873), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4364] = 2,
    ACTIONS(875), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4372] = 2,
    ACTIONS(877), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4380] = 2,
    ACTIONS(879), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4388] = 2,
    ACTIONS(881), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4396] = 2,
    ACTIONS(883), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4404] = 2,
    ACTIONS(885), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4412] = 2,
    ACTIONS(887), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4420] = 2,
    ACTIONS(889), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4428] = 2,
    ACTIONS(891), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4436] = 2,
    ACTIONS(893), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4444] = 2,
    ACTIONS(895), 1,
      anon_sym_command,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4452] = 2,
    ACTIONS(897), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4460] = 2,
    ACTIONS(899), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4468] = 2,
    ACTIONS(901), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4476] = 2,
    ACTIONS(903), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4484] = 2,
    ACTIONS(537), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4492] = 2,
    ACTIONS(905), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4500] = 2,
    ACTIONS(907), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4508] = 2,
    ACTIONS(909), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4516] = 2,
    ACTIONS(911), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4524] = 2,
    ACTIONS(913), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4532] = 2,
    ACTIONS(915), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4540] = 2,
    ACTIONS(917), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4548] = 2,
    ACTIONS(919), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4556] = 2,
    ACTIONS(921), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [4564] = 2,
    ACTIONS(923), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 85,
  [SMALL_STATE(4)] = 169,
  [SMALL_STATE(5)] = 253,
  [SMALL_STATE(6)] = 337,
  [SMALL_STATE(7)] = 421,
  [SMALL_STATE(8)] = 450,
  [SMALL_STATE(9)] = 479,
  [SMALL_STATE(10)] = 508,
  [SMALL_STATE(11)] = 535,
  [SMALL_STATE(12)] = 562,
  [SMALL_STATE(13)] = 589,
  [SMALL_STATE(14)] = 616,
  [SMALL_STATE(15)] = 643,
  [SMALL_STATE(16)] = 670,
  [SMALL_STATE(17)] = 697,
  [SMALL_STATE(18)] = 740,
  [SMALL_STATE(19)] = 783,
  [SMALL_STATE(20)] = 810,
  [SMALL_STATE(21)] = 837,
  [SMALL_STATE(22)] = 864,
  [SMALL_STATE(23)] = 891,
  [SMALL_STATE(24)] = 918,
  [SMALL_STATE(25)] = 945,
  [SMALL_STATE(26)] = 972,
  [SMALL_STATE(27)] = 999,
  [SMALL_STATE(28)] = 1026,
  [SMALL_STATE(29)] = 1053,
  [SMALL_STATE(30)] = 1080,
  [SMALL_STATE(31)] = 1107,
  [SMALL_STATE(32)] = 1134,
  [SMALL_STATE(33)] = 1161,
  [SMALL_STATE(34)] = 1188,
  [SMALL_STATE(35)] = 1215,
  [SMALL_STATE(36)] = 1242,
  [SMALL_STATE(37)] = 1269,
  [SMALL_STATE(38)] = 1296,
  [SMALL_STATE(39)] = 1323,
  [SMALL_STATE(40)] = 1350,
  [SMALL_STATE(41)] = 1377,
  [SMALL_STATE(42)] = 1404,
  [SMALL_STATE(43)] = 1438,
  [SMALL_STATE(44)] = 1470,
  [SMALL_STATE(45)] = 1504,
  [SMALL_STATE(46)] = 1535,
  [SMALL_STATE(47)] = 1566,
  [SMALL_STATE(48)] = 1597,
  [SMALL_STATE(49)] = 1628,
  [SMALL_STATE(50)] = 1654,
  [SMALL_STATE(51)] = 1673,
  [SMALL_STATE(52)] = 1692,
  [SMALL_STATE(53)] = 1711,
  [SMALL_STATE(54)] = 1734,
  [SMALL_STATE(55)] = 1759,
  [SMALL_STATE(56)] = 1778,
  [SMALL_STATE(57)] = 1801,
  [SMALL_STATE(58)] = 1819,
  [SMALL_STATE(59)] = 1837,
  [SMALL_STATE(60)] = 1855,
  [SMALL_STATE(61)] = 1873,
  [SMALL_STATE(62)] = 1891,
  [SMALL_STATE(63)] = 1909,
  [SMALL_STATE(64)] = 1927,
  [SMALL_STATE(65)] = 1945,
  [SMALL_STATE(66)] = 1963,
  [SMALL_STATE(67)] = 1981,
  [SMALL_STATE(68)] = 1997,
  [SMALL_STATE(69)] = 2013,
  [SMALL_STATE(70)] = 2031,
  [SMALL_STATE(71)] = 2049,
  [SMALL_STATE(72)] = 2064,
  [SMALL_STATE(73)] = 2091,
  [SMALL_STATE(74)] = 2118,
  [SMALL_STATE(75)] = 2133,
  [SMALL_STATE(76)] = 2160,
  [SMALL_STATE(77)] = 2187,
  [SMALL_STATE(78)] = 2214,
  [SMALL_STATE(79)] = 2243,
  [SMALL_STATE(80)] = 2267,
  [SMALL_STATE(81)] = 2290,
  [SMALL_STATE(82)] = 2311,
  [SMALL_STATE(83)] = 2334,
  [SMALL_STATE(84)] = 2357,
  [SMALL_STATE(85)] = 2378,
  [SMALL_STATE(86)] = 2401,
  [SMALL_STATE(87)] = 2420,
  [SMALL_STATE(88)] = 2443,
  [SMALL_STATE(89)] = 2466,
  [SMALL_STATE(90)] = 2487,
  [SMALL_STATE(91)] = 2503,
  [SMALL_STATE(92)] = 2519,
  [SMALL_STATE(93)] = 2537,
  [SMALL_STATE(94)] = 2553,
  [SMALL_STATE(95)] = 2569,
  [SMALL_STATE(96)] = 2585,
  [SMALL_STATE(97)] = 2605,
  [SMALL_STATE(98)] = 2623,
  [SMALL_STATE(99)] = 2641,
  [SMALL_STATE(100)] = 2659,
  [SMALL_STATE(101)] = 2677,
  [SMALL_STATE(102)] = 2691,
  [SMALL_STATE(103)] = 2707,
  [SMALL_STATE(104)] = 2724,
  [SMALL_STATE(105)] = 2739,
  [SMALL_STATE(106)] = 2752,
  [SMALL_STATE(107)] = 2769,
  [SMALL_STATE(108)] = 2786,
  [SMALL_STATE(109)] = 2801,
  [SMALL_STATE(110)] = 2818,
  [SMALL_STATE(111)] = 2833,
  [SMALL_STATE(112)] = 2846,
  [SMALL_STATE(113)] = 2863,
  [SMALL_STATE(114)] = 2878,
  [SMALL_STATE(115)] = 2891,
  [SMALL_STATE(116)] = 2906,
  [SMALL_STATE(117)] = 2917,
  [SMALL_STATE(118)] = 2932,
  [SMALL_STATE(119)] = 2947,
  [SMALL_STATE(120)] = 2964,
  [SMALL_STATE(121)] = 2979,
  [SMALL_STATE(122)] = 2992,
  [SMALL_STATE(123)] = 3003,
  [SMALL_STATE(124)] = 3014,
  [SMALL_STATE(125)] = 3027,
  [SMALL_STATE(126)] = 3042,
  [SMALL_STATE(127)] = 3053,
  [SMALL_STATE(128)] = 3066,
  [SMALL_STATE(129)] = 3076,
  [SMALL_STATE(130)] = 3088,
  [SMALL_STATE(131)] = 3102,
  [SMALL_STATE(132)] = 3112,
  [SMALL_STATE(133)] = 3122,
  [SMALL_STATE(134)] = 3132,
  [SMALL_STATE(135)] = 3146,
  [SMALL_STATE(136)] = 3156,
  [SMALL_STATE(137)] = 3166,
  [SMALL_STATE(138)] = 3180,
  [SMALL_STATE(139)] = 3194,
  [SMALL_STATE(140)] = 3208,
  [SMALL_STATE(141)] = 3222,
  [SMALL_STATE(142)] = 3232,
  [SMALL_STATE(143)] = 3246,
  [SMALL_STATE(144)] = 3260,
  [SMALL_STATE(145)] = 3272,
  [SMALL_STATE(146)] = 3286,
  [SMALL_STATE(147)] = 3296,
  [SMALL_STATE(148)] = 3310,
  [SMALL_STATE(149)] = 3322,
  [SMALL_STATE(150)] = 3334,
  [SMALL_STATE(151)] = 3348,
  [SMALL_STATE(152)] = 3362,
  [SMALL_STATE(153)] = 3376,
  [SMALL_STATE(154)] = 3390,
  [SMALL_STATE(155)] = 3400,
  [SMALL_STATE(156)] = 3414,
  [SMALL_STATE(157)] = 3426,
  [SMALL_STATE(158)] = 3438,
  [SMALL_STATE(159)] = 3452,
  [SMALL_STATE(160)] = 3466,
  [SMALL_STATE(161)] = 3478,
  [SMALL_STATE(162)] = 3492,
  [SMALL_STATE(163)] = 3506,
  [SMALL_STATE(164)] = 3520,
  [SMALL_STATE(165)] = 3532,
  [SMALL_STATE(166)] = 3542,
  [SMALL_STATE(167)] = 3556,
  [SMALL_STATE(168)] = 3566,
  [SMALL_STATE(169)] = 3580,
  [SMALL_STATE(170)] = 3592,
  [SMALL_STATE(171)] = 3606,
  [SMALL_STATE(172)] = 3616,
  [SMALL_STATE(173)] = 3628,
  [SMALL_STATE(174)] = 3642,
  [SMALL_STATE(175)] = 3656,
  [SMALL_STATE(176)] = 3670,
  [SMALL_STATE(177)] = 3684,
  [SMALL_STATE(178)] = 3694,
  [SMALL_STATE(179)] = 3703,
  [SMALL_STATE(180)] = 3712,
  [SMALL_STATE(181)] = 3723,
  [SMALL_STATE(182)] = 3732,
  [SMALL_STATE(183)] = 3741,
  [SMALL_STATE(184)] = 3750,
  [SMALL_STATE(185)] = 3759,
  [SMALL_STATE(186)] = 3768,
  [SMALL_STATE(187)] = 3777,
  [SMALL_STATE(188)] = 3786,
  [SMALL_STATE(189)] = 3795,
  [SMALL_STATE(190)] = 3806,
  [SMALL_STATE(191)] = 3817,
  [SMALL_STATE(192)] = 3828,
  [SMALL_STATE(193)] = 3839,
  [SMALL_STATE(194)] = 3850,
  [SMALL_STATE(195)] = 3859,
  [SMALL_STATE(196)] = 3868,
  [SMALL_STATE(197)] = 3877,
  [SMALL_STATE(198)] = 3886,
  [SMALL_STATE(199)] = 3895,
  [SMALL_STATE(200)] = 3906,
  [SMALL_STATE(201)] = 3915,
  [SMALL_STATE(202)] = 3924,
  [SMALL_STATE(203)] = 3935,
  [SMALL_STATE(204)] = 3946,
  [SMALL_STATE(205)] = 3955,
  [SMALL_STATE(206)] = 3964,
  [SMALL_STATE(207)] = 3973,
  [SMALL_STATE(208)] = 3984,
  [SMALL_STATE(209)] = 3993,
  [SMALL_STATE(210)] = 4002,
  [SMALL_STATE(211)] = 4013,
  [SMALL_STATE(212)] = 4022,
  [SMALL_STATE(213)] = 4031,
  [SMALL_STATE(214)] = 4040,
  [SMALL_STATE(215)] = 4049,
  [SMALL_STATE(216)] = 4060,
  [SMALL_STATE(217)] = 4068,
  [SMALL_STATE(218)] = 4076,
  [SMALL_STATE(219)] = 4084,
  [SMALL_STATE(220)] = 4092,
  [SMALL_STATE(221)] = 4100,
  [SMALL_STATE(222)] = 4108,
  [SMALL_STATE(223)] = 4116,
  [SMALL_STATE(224)] = 4124,
  [SMALL_STATE(225)] = 4132,
  [SMALL_STATE(226)] = 4140,
  [SMALL_STATE(227)] = 4148,
  [SMALL_STATE(228)] = 4156,
  [SMALL_STATE(229)] = 4164,
  [SMALL_STATE(230)] = 4172,
  [SMALL_STATE(231)] = 4180,
  [SMALL_STATE(232)] = 4188,
  [SMALL_STATE(233)] = 4196,
  [SMALL_STATE(234)] = 4204,
  [SMALL_STATE(235)] = 4212,
  [SMALL_STATE(236)] = 4220,
  [SMALL_STATE(237)] = 4228,
  [SMALL_STATE(238)] = 4236,
  [SMALL_STATE(239)] = 4244,
  [SMALL_STATE(240)] = 4252,
  [SMALL_STATE(241)] = 4260,
  [SMALL_STATE(242)] = 4268,
  [SMALL_STATE(243)] = 4276,
  [SMALL_STATE(244)] = 4284,
  [SMALL_STATE(245)] = 4292,
  [SMALL_STATE(246)] = 4300,
  [SMALL_STATE(247)] = 4308,
  [SMALL_STATE(248)] = 4316,
  [SMALL_STATE(249)] = 4324,
  [SMALL_STATE(250)] = 4332,
  [SMALL_STATE(251)] = 4340,
  [SMALL_STATE(252)] = 4348,
  [SMALL_STATE(253)] = 4356,
  [SMALL_STATE(254)] = 4364,
  [SMALL_STATE(255)] = 4372,
  [SMALL_STATE(256)] = 4380,
  [SMALL_STATE(257)] = 4388,
  [SMALL_STATE(258)] = 4396,
  [SMALL_STATE(259)] = 4404,
  [SMALL_STATE(260)] = 4412,
  [SMALL_STATE(261)] = 4420,
  [SMALL_STATE(262)] = 4428,
  [SMALL_STATE(263)] = 4436,
  [SMALL_STATE(264)] = 4444,
  [SMALL_STATE(265)] = 4452,
  [SMALL_STATE(266)] = 4460,
  [SMALL_STATE(267)] = 4468,
  [SMALL_STATE(268)] = 4476,
  [SMALL_STATE(269)] = 4484,
  [SMALL_STATE(270)] = 4492,
  [SMALL_STATE(271)] = 4500,
  [SMALL_STATE(272)] = 4508,
  [SMALL_STATE(273)] = 4516,
  [SMALL_STATE(274)] = 4524,
  [SMALL_STATE(275)] = 4532,
  [SMALL_STATE(276)] = 4540,
  [SMALL_STATE(277)] = 4548,
  [SMALL_STATE(278)] = 4556,
  [SMALL_STATE(279)] = 4564,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(202),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(202),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(210),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(154),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(178),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(241),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [28] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(180),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(219),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(279),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(189),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(220),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(215),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(226),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(203),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(254),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(207),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(263),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(264),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(241),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(219),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(279),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(189),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(220),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(215),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(226),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(203),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(254),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(207),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(263),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(264),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 3, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 3, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_run_script, 3, 0, 13),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 3, 0, 13),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 14),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 3, 0, 14),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_blocking_delay, 3, 0, 14),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 3, 0, 14),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_return_statement, 2, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [155] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(202),
  [158] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(202),
  [161] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(235),
  [164] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [167] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(210),
  [170] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(182),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(154),
  [176] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(178),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_slot, 4, 0, 28),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 4, 0, 28),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_load_map, 4, 0, 29),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 4, 0, 29),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_erase_slot, 4, 0, 28),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 4, 0, 28),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_label, 4, 0, 30),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 4, 0, 30),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_goto_index, 4, 0, 31),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 4, 0, 31),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 3, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 33),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 33),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 34),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 34),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 4, 0, 35),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 35),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 32),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 32),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 33),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 4, 0, 33),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_command, 4, 0, 36),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command, 4, 0, 36),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_alias, 4, 0, 37),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_alias, 4, 0, 37),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_hide_command, 4, 0, 36),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_hide_command, 4, 0, 36),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_unhide_command, 4, 0, 36),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_unhide_command, 4, 0, 36),
  [241] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label_definition, 2, 0, 6),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label_definition, 2, 0, 6),
  [245] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 45),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 5, 0, 45),
  [253] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_dialog, 5, 0, 46),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 5, 0, 46),
  [257] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 45),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_concat_serial_dialog, 5, 0, 45),
  [261] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_delete_command_arg, 6, 0, 51),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_delete_command_arg, 6, 0, 51),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 32),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_serial_dialog, 4, 0, 32),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(196),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 40),
  [281] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 40), SHIFT_REPEAT(196),
  [284] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 2, 0, 40), SHIFT_REPEAT(135),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 16),
  [305] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 16),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [309] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [313] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 2, 0, 0),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [317] = {.entry = {.count = 1, .reusable = false}}, SHIFT(269),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dialog_block, 3, 0, 26),
  [327] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dialog_block, 3, 0, 26),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(204),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [333] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [335] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [337] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [341] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [345] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [349] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [353] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [355] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [357] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [361] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [365] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [369] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_target_repeat1, 1, 0, 24),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 15),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [377] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 0),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 7),
  [381] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 7),
  [383] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 22),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [399] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(260),
  [402] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(194),
  [405] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [408] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 25),
  [410] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 25),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 41),
  [416] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 41),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [424] = {.entry = {.count = 1, .reusable = false}}, SHIFT(247),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [430] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [432] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [434] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 27), SHIFT_REPEAT(71),
  [437] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 27),
  [439] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 2, 0, 27), SHIFT_REPEAT(187),
  [442] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 49),
  [444] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 49),
  [446] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 49), SHIFT_REPEAT(274),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [453] = {.entry = {.count = 1, .reusable = false}}, SHIFT(187),
  [455] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 18),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [459] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 44),
  [461] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 44),
  [463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 11),
  [465] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 43),
  [467] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 43), SHIFT_REPEAT(101),
  [470] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 43),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 48),
  [476] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 48),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [490] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 17),
  [492] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 17), SHIFT_REPEAT(183),
  [495] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [497] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(183),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(232),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [508] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [510] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 23),
  [512] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 23),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [516] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 39),
  [518] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 39), SHIFT_REPEAT(257),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 42),
  [527] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 1, 0, 42),
  [529] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 21),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(272),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [543] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 38),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(197),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(200),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(240),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [565] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 20), SHIFT_REPEAT(146),
  [568] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 20),
  [570] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 3, 0, 47),
  [572] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [574] = {.entry = {.count = 1, .reusable = true}}, SHIFT(164),
  [576] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [578] = {.entry = {.count = 1, .reusable = true}}, SHIFT(236),
  [580] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [582] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [584] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 52),
  [586] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 4, 0, 53),
  [588] = {.entry = {.count = 1, .reusable = true}}, SHIFT(198),
  [590] = {.entry = {.count = 1, .reusable = true}}, SHIFT(175),
  [592] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings_target, 5, 0, 55),
  [594] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 56),
  [596] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 56),
  [598] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [600] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [604] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(186),
  [607] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [609] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_entity, 1, 0, 0),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [613] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 15),
  [615] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [619] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [621] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [623] = {.entry = {.count = 1, .reusable = true}}, SHIFT(177),
  [625] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [627] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [631] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [633] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [635] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 8),
  [637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [639] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [647] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 9),
  [649] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [651] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [653] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [657] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 12),
  [659] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__dialog_block_repeat1, 1, 0, 12),
  [661] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [665] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [667] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [669] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [671] = {.entry = {.count = 1, .reusable = true}}, SHIFT(191),
  [673] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [676] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [678] = {.entry = {.count = 1, .reusable = true}}, SHIFT(258),
  [680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [682] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [688] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(171),
  [691] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(209),
  [695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [699] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(174),
  [702] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [704] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [706] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [712] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [714] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [716] = {.entry = {.count = 1, .reusable = true}}, SHIFT(222),
  [718] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [720] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(193),
  [723] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(273),
  [727] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(213),
  [730] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(275),
  [734] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(214),
  [737] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [739] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [741] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [743] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [745] = {.entry = {.count = 1, .reusable = true}}, SHIFT(192),
  [747] = {.entry = {.count = 1, .reusable = true}}, SHIFT(190),
  [749] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter_int, 1, 0, 0),
  [751] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [753] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 10),
  [755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [757] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 19),
  [759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(242),
  [761] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [763] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [765] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_target_label, 1, 0, 0),
  [767] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [773] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [779] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 50),
  [781] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [783] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [785] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [789] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [791] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 54),
  [793] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [797] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [799] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [801] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [805] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [807] = {.entry = {.count = 1, .reusable = true}}, SHIFT(253),
  [809] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [811] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [815] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [817] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [819] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [821] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [823] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [825] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [827] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [829] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [831] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [833] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [835] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [837] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [839] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [841] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [843] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [845] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [847] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [849] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [851] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [853] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [855] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [857] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [859] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [861] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [863] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [865] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [867] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [869] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [871] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [873] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [875] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [877] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [879] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [881] = {.entry = {.count = 1, .reusable = true}}, SHIFT(259),
  [883] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [885] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [887] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [889] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [891] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [893] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [895] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [897] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [899] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [901] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [903] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [905] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [907] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [909] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 8),
  [911] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [913] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [915] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [917] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [919] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [921] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 8),
  [923] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
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
