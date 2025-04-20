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
#define STATE_COUNT 153
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 101
#define ALIAS_COUNT 2
#define TOKEN_COUNT 49
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 22
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 36

enum ts_symbol_identifiers {
  sym_block_comment = 1,
  sym_line_comment = 2,
  sym_BAREWORD = 3,
  sym_QUOTED_STRING = 4,
  sym_NUMBER = 5,
  sym_DURATION = 6,
  sym_DISTANCE = 7,
  sym_QUANTITY = 8,
  sym_COLOR = 9,
  sym_BOOLEAN = 10,
  sym_CONSTANT = 11,
  sym_ENUM_ALIGNMENT = 12,
  anon_sym_include = 13,
  anon_sym_SEMI = 14,
  anon_sym_EQ = 15,
  anon_sym_add = 16,
  anon_sym_serial_dialog = 17,
  anon_sym_settings = 18,
  anon_sym_LBRACE = 19,
  anon_sym_RBRACE = 20,
  anon_sym_wrap = 21,
  anon_sym_dialog = 22,
  anon_sym_default = 23,
  anon_sym_label = 24,
  anon_sym_entity = 25,
  anon_sym_name = 26,
  anon_sym_portrait = 27,
  anon_sym_alignment = 28,
  anon_sym_border_tileset = 29,
  anon_sym_emote = 30,
  anon_sym_GT = 31,
  sym_serial_dialog_option_type = 32,
  anon_sym_script = 33,
  anon_sym_COLON = 34,
  anon_sym_json = 35,
  anon_sym_LBRACK = 36,
  anon_sym_COMMA = 37,
  anon_sym_RBRACK = 38,
  sym_json_number = 39,
  anon_sym_true = 40,
  anon_sym_false = 41,
  anon_sym_null = 42,
  sym_return_statement = 43,
  anon_sym_load = 44,
  anon_sym_map = 45,
  anon_sym_goto = 46,
  anon_sym_index = 47,
  anon_sym_show = 48,
  sym_source_file = 49,
  sym__bareword = 50,
  sym__STRING = 51,
  sym__string = 52,
  sym__number = 53,
  sym__NUMBERISH = 54,
  sym__enum_alignment = 55,
  sym__root = 56,
  sym_include_macro = 57,
  sym_constant_assignment = 58,
  sym_add_serial_dialog_settings = 59,
  sym_serial_dialog_parameter = 60,
  sym_add_dialog_settings = 61,
  sym_dialog_settings_block = 62,
  sym_dialog_parameter = 63,
  sym_dialog_definition = 64,
  sym_dialog_block = 65,
  sym_dialog = 66,
  sym_dialog_identifier = 67,
  sym_dialog_option = 68,
  sym_serial_dialog_definition = 69,
  sym_serial_dialog_block = 70,
  sym_serial_dialog = 71,
  sym_serial_dialog_option = 72,
  sym_script_definition = 73,
  sym_script_block = 74,
  sym__script_item = 75,
  sym_label = 76,
  sym_json_block = 77,
  sym_json_array = 78,
  sym__json_item = 79,
  sym_json_language_constant = 80,
  sym_json_object = 81,
  sym_json_name_value_pair = 82,
  sym__action_item = 83,
  sym_action_load_map = 84,
  sym_action_run_script = 85,
  sym_action_goto_action_label = 86,
  sym_action_goto_action_index = 87,
  sym_action_show_dialog = 88,
  aux_sym_source_file_repeat1 = 89,
  aux_sym_add_serial_dialog_settings_repeat1 = 90,
  aux_sym_add_dialog_settings_repeat1 = 91,
  aux_sym_dialog_settings_block_repeat1 = 92,
  aux_sym_dialog_block_repeat1 = 93,
  aux_sym_dialog_repeat1 = 94,
  aux_sym_dialog_repeat2 = 95,
  aux_sym_serial_dialog_repeat1 = 96,
  aux_sym_serial_dialog_repeat2 = 97,
  aux_sym_script_block_repeat1 = 98,
  aux_sym_json_array_repeat1 = 99,
  aux_sym_json_object_repeat1 = 100,
  alias_sym_entity_settings = 101,
  alias_sym_label_settings = 102,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_block_comment] = "block_comment",
  [sym_line_comment] = "line_comment",
  [sym_BAREWORD] = "BAREWORD",
  [sym_QUOTED_STRING] = "QUOTED_STRING",
  [sym_NUMBER] = "NUMBER",
  [sym_DURATION] = "DURATION",
  [sym_DISTANCE] = "DISTANCE",
  [sym_QUANTITY] = "QUANTITY",
  [sym_COLOR] = "COLOR",
  [sym_BOOLEAN] = "BOOLEAN",
  [sym_CONSTANT] = "CONSTANT",
  [sym_ENUM_ALIGNMENT] = "ENUM_ALIGNMENT",
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
  [anon_sym_default] = "default",
  [anon_sym_label] = "label",
  [anon_sym_entity] = "entity",
  [anon_sym_name] = "name",
  [anon_sym_portrait] = "portrait",
  [anon_sym_alignment] = "alignment",
  [anon_sym_border_tileset] = "border_tileset",
  [anon_sym_emote] = "emote",
  [anon_sym_GT] = ">",
  [sym_serial_dialog_option_type] = "serial_dialog_option_type",
  [anon_sym_script] = "script",
  [anon_sym_COLON] = ":",
  [anon_sym_json] = "json",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_json_number] = "json_number",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_null] = "null",
  [sym_return_statement] = "return_statement",
  [anon_sym_load] = "load",
  [anon_sym_map] = "map",
  [anon_sym_goto] = "goto",
  [anon_sym_index] = "index",
  [anon_sym_show] = "show",
  [sym_source_file] = "source_file",
  [sym__bareword] = "_bareword",
  [sym__STRING] = "_STRING",
  [sym__string] = "_string",
  [sym__number] = "_number",
  [sym__NUMBERISH] = "_NUMBERISH",
  [sym__enum_alignment] = "_enum_alignment",
  [sym__root] = "_root",
  [sym_include_macro] = "include_macro",
  [sym_constant_assignment] = "constant_assignment",
  [sym_add_serial_dialog_settings] = "add_serial_dialog_settings",
  [sym_serial_dialog_parameter] = "serial_dialog_parameter",
  [sym_add_dialog_settings] = "add_dialog_settings",
  [sym_dialog_settings_block] = "default_settings",
  [sym_dialog_parameter] = "dialog_parameter",
  [sym_dialog_definition] = "dialog_definition",
  [sym_dialog_block] = "dialog_block",
  [sym_dialog] = "dialog",
  [sym_dialog_identifier] = "dialog_identifier",
  [sym_dialog_option] = "dialog_option",
  [sym_serial_dialog_definition] = "serial_dialog_definition",
  [sym_serial_dialog_block] = "serial_dialog_block",
  [sym_serial_dialog] = "serial_dialog",
  [sym_serial_dialog_option] = "serial_dialog_option",
  [sym_script_definition] = "script_definition",
  [sym_script_block] = "script_block",
  [sym__script_item] = "_script_item",
  [sym_label] = "label",
  [sym_json_block] = "json_block",
  [sym_json_array] = "json_array",
  [sym__json_item] = "_json_item",
  [sym_json_language_constant] = "json_language_constant",
  [sym_json_object] = "json_object",
  [sym_json_name_value_pair] = "json_name_value_pair",
  [sym__action_item] = "_action_item",
  [sym_action_load_map] = "action_load_map",
  [sym_action_run_script] = "action_run_script",
  [sym_action_goto_action_label] = "action_goto_action_label",
  [sym_action_goto_action_index] = "action_goto_action_index",
  [sym_action_show_dialog] = "action_show_dialog",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_add_serial_dialog_settings_repeat1] = "add_serial_dialog_settings_repeat1",
  [aux_sym_add_dialog_settings_repeat1] = "add_dialog_settings_repeat1",
  [aux_sym_dialog_settings_block_repeat1] = "dialog_settings_block_repeat1",
  [aux_sym_dialog_block_repeat1] = "dialog_block_repeat1",
  [aux_sym_dialog_repeat1] = "dialog_repeat1",
  [aux_sym_dialog_repeat2] = "dialog_repeat2",
  [aux_sym_serial_dialog_repeat1] = "serial_dialog_repeat1",
  [aux_sym_serial_dialog_repeat2] = "serial_dialog_repeat2",
  [aux_sym_script_block_repeat1] = "script_block_repeat1",
  [aux_sym_json_array_repeat1] = "json_array_repeat1",
  [aux_sym_json_object_repeat1] = "json_object_repeat1",
  [alias_sym_entity_settings] = "entity_settings",
  [alias_sym_label_settings] = "label_settings",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_block_comment] = sym_block_comment,
  [sym_line_comment] = sym_line_comment,
  [sym_BAREWORD] = sym_BAREWORD,
  [sym_QUOTED_STRING] = sym_QUOTED_STRING,
  [sym_NUMBER] = sym_NUMBER,
  [sym_DURATION] = sym_DURATION,
  [sym_DISTANCE] = sym_DISTANCE,
  [sym_QUANTITY] = sym_QUANTITY,
  [sym_COLOR] = sym_COLOR,
  [sym_BOOLEAN] = sym_BOOLEAN,
  [sym_CONSTANT] = sym_CONSTANT,
  [sym_ENUM_ALIGNMENT] = sym_ENUM_ALIGNMENT,
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
  [anon_sym_default] = anon_sym_default,
  [anon_sym_label] = anon_sym_label,
  [anon_sym_entity] = anon_sym_entity,
  [anon_sym_name] = anon_sym_name,
  [anon_sym_portrait] = anon_sym_portrait,
  [anon_sym_alignment] = anon_sym_alignment,
  [anon_sym_border_tileset] = anon_sym_border_tileset,
  [anon_sym_emote] = anon_sym_emote,
  [anon_sym_GT] = anon_sym_GT,
  [sym_serial_dialog_option_type] = sym_serial_dialog_option_type,
  [anon_sym_script] = anon_sym_script,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_json] = anon_sym_json,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_json_number] = sym_json_number,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_null] = anon_sym_null,
  [sym_return_statement] = sym_return_statement,
  [anon_sym_load] = anon_sym_load,
  [anon_sym_map] = anon_sym_map,
  [anon_sym_goto] = anon_sym_goto,
  [anon_sym_index] = anon_sym_index,
  [anon_sym_show] = anon_sym_show,
  [sym_source_file] = sym_source_file,
  [sym__bareword] = sym__bareword,
  [sym__STRING] = sym__STRING,
  [sym__string] = sym__string,
  [sym__number] = sym__number,
  [sym__NUMBERISH] = sym__NUMBERISH,
  [sym__enum_alignment] = sym__enum_alignment,
  [sym__root] = sym__root,
  [sym_include_macro] = sym_include_macro,
  [sym_constant_assignment] = sym_constant_assignment,
  [sym_add_serial_dialog_settings] = sym_add_serial_dialog_settings,
  [sym_serial_dialog_parameter] = sym_serial_dialog_parameter,
  [sym_add_dialog_settings] = sym_add_dialog_settings,
  [sym_dialog_settings_block] = sym_dialog_settings_block,
  [sym_dialog_parameter] = sym_dialog_parameter,
  [sym_dialog_definition] = sym_dialog_definition,
  [sym_dialog_block] = sym_dialog_block,
  [sym_dialog] = sym_dialog,
  [sym_dialog_identifier] = sym_dialog_identifier,
  [sym_dialog_option] = sym_dialog_option,
  [sym_serial_dialog_definition] = sym_serial_dialog_definition,
  [sym_serial_dialog_block] = sym_serial_dialog_block,
  [sym_serial_dialog] = sym_serial_dialog,
  [sym_serial_dialog_option] = sym_serial_dialog_option,
  [sym_script_definition] = sym_script_definition,
  [sym_script_block] = sym_script_block,
  [sym__script_item] = sym__script_item,
  [sym_label] = sym_label,
  [sym_json_block] = sym_json_block,
  [sym_json_array] = sym_json_array,
  [sym__json_item] = sym__json_item,
  [sym_json_language_constant] = sym_json_language_constant,
  [sym_json_object] = sym_json_object,
  [sym_json_name_value_pair] = sym_json_name_value_pair,
  [sym__action_item] = sym__action_item,
  [sym_action_load_map] = sym_action_load_map,
  [sym_action_run_script] = sym_action_run_script,
  [sym_action_goto_action_label] = sym_action_goto_action_label,
  [sym_action_goto_action_index] = sym_action_goto_action_index,
  [sym_action_show_dialog] = sym_action_show_dialog,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_add_serial_dialog_settings_repeat1] = aux_sym_add_serial_dialog_settings_repeat1,
  [aux_sym_add_dialog_settings_repeat1] = aux_sym_add_dialog_settings_repeat1,
  [aux_sym_dialog_settings_block_repeat1] = aux_sym_dialog_settings_block_repeat1,
  [aux_sym_dialog_block_repeat1] = aux_sym_dialog_block_repeat1,
  [aux_sym_dialog_repeat1] = aux_sym_dialog_repeat1,
  [aux_sym_dialog_repeat2] = aux_sym_dialog_repeat2,
  [aux_sym_serial_dialog_repeat1] = aux_sym_serial_dialog_repeat1,
  [aux_sym_serial_dialog_repeat2] = aux_sym_serial_dialog_repeat2,
  [aux_sym_script_block_repeat1] = aux_sym_script_block_repeat1,
  [aux_sym_json_array_repeat1] = aux_sym_json_array_repeat1,
  [aux_sym_json_object_repeat1] = aux_sym_json_object_repeat1,
  [alias_sym_entity_settings] = alias_sym_entity_settings,
  [alias_sym_label_settings] = alias_sym_label_settings,
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
  [sym_BAREWORD] = {
    .visible = true,
    .named = true,
  },
  [sym_QUOTED_STRING] = {
    .visible = true,
    .named = true,
  },
  [sym_NUMBER] = {
    .visible = true,
    .named = true,
  },
  [sym_DURATION] = {
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
  [sym_COLOR] = {
    .visible = true,
    .named = true,
  },
  [sym_BOOLEAN] = {
    .visible = true,
    .named = true,
  },
  [sym_CONSTANT] = {
    .visible = true,
    .named = true,
  },
  [sym_ENUM_ALIGNMENT] = {
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
  [anon_sym_default] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_label] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_entity] = {
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
  [anon_sym_emote] = {
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
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_json] = {
    .visible = true,
    .named = false,
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
  [sym_return_statement] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_load] = {
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
  [anon_sym_show] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__bareword] = {
    .visible = false,
    .named = true,
  },
  [sym__STRING] = {
    .visible = false,
    .named = true,
  },
  [sym__string] = {
    .visible = false,
    .named = true,
  },
  [sym__number] = {
    .visible = false,
    .named = true,
  },
  [sym__NUMBERISH] = {
    .visible = false,
    .named = true,
  },
  [sym__enum_alignment] = {
    .visible = false,
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
  [sym_dialog_settings_block] = {
    .visible = true,
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
  [sym_dialog_block] = {
    .visible = true,
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
  [sym_serial_dialog_block] = {
    .visible = true,
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
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym_json_block] = {
    .visible = true,
    .named = true,
  },
  [sym_json_array] = {
    .visible = true,
    .named = true,
  },
  [sym__json_item] = {
    .visible = false,
    .named = true,
  },
  [sym_json_language_constant] = {
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
  [sym__action_item] = {
    .visible = false,
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
  [sym_action_goto_action_label] = {
    .visible = true,
    .named = true,
  },
  [sym_action_goto_action_index] = {
    .visible = true,
    .named = true,
  },
  [sym_action_show_dialog] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
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
  [aux_sym_dialog_settings_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dialog_block_repeat1] = {
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
  [alias_sym_entity_settings] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_label_settings] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_alignment = 1,
  field_border_tileset = 2,
  field_dialog_name = 3,
  field_emote = 4,
  field_entity = 5,
  field_fileName = 6,
  field_index = 7,
  field_label = 8,
  field_map = 9,
  field_message = 10,
  field_name = 11,
  field_option_type = 12,
  field_portrait = 13,
  field_property = 14,
  field_script = 15,
  field_script_name = 16,
  field_serial_dialog_name = 17,
  field_serial_message = 18,
  field_target_entity = 19,
  field_target_label = 20,
  field_value = 21,
  field_wrap = 22,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alignment] = "alignment",
  [field_border_tileset] = "border_tileset",
  [field_dialog_name] = "dialog_name",
  [field_emote] = "emote",
  [field_entity] = "entity",
  [field_fileName] = "fileName",
  [field_index] = "index",
  [field_label] = "label",
  [field_map] = "map",
  [field_message] = "message",
  [field_name] = "name",
  [field_option_type] = "option_type",
  [field_portrait] = "portrait",
  [field_property] = "property",
  [field_script] = "script",
  [field_script_name] = "script_name",
  [field_serial_dialog_name] = "serial_dialog_name",
  [field_serial_message] = "serial_message",
  [field_target_entity] = "target_entity",
  [field_target_label] = "target_label",
  [field_value] = "value",
  [field_wrap] = "wrap",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 1},
  [6] = {.index = 5, .length = 1},
  [7] = {.index = 6, .length = 1},
  [8] = {.index = 7, .length = 2},
  [9] = {.index = 9, .length = 1},
  [10] = {.index = 10, .length = 1},
  [11] = {.index = 11, .length = 1},
  [12] = {.index = 12, .length = 1},
  [13] = {.index = 13, .length = 1},
  [14] = {.index = 14, .length = 1},
  [15] = {.index = 15, .length = 2},
  [16] = {.index = 17, .length = 1},
  [17] = {.index = 18, .length = 2},
  [18] = {.index = 20, .length = 1},
  [19] = {.index = 21, .length = 1},
  [20] = {.index = 22, .length = 1},
  [21] = {.index = 23, .length = 1},
  [22] = {.index = 24, .length = 2},
  [23] = {.index = 26, .length = 4},
  [24] = {.index = 30, .length = 1},
  [25] = {.index = 31, .length = 1},
  [26] = {.index = 32, .length = 1},
  [27] = {.index = 33, .length = 1},
  [28] = {.index = 34, .length = 1},
  [29] = {.index = 35, .length = 1},
  [30] = {.index = 36, .length = 2},
  [31] = {.index = 38, .length = 1},
  [32] = {.index = 39, .length = 1},
  [33] = {.index = 40, .length = 2},
  [34] = {.index = 42, .length = 3},
  [35] = {.index = 45, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_script_name, 0},
  [1] =
    {field_fileName, 1},
  [2] =
    {field_serial_dialog_name, 1},
  [3] =
    {field_dialog_name, 1},
  [4] =
    {field_script_name, 1},
  [5] =
    {field_label, 0},
  [6] =
    {field_script, 1},
  [7] =
    {field_label, 0},
    {field_value, 2},
  [9] =
    {field_serial_message, 0},
  [10] =
    {field_serial_message, 0, .inherited = true},
  [11] =
    {field_map, 2},
  [12] =
    {field_label, 2},
  [13] =
    {field_index, 2},
  [14] =
    {field_dialog_name, 2},
  [15] =
    {field_property, 0},
    {field_value, 1},
  [17] =
    {field_serial_message, 1, .inherited = true},
  [18] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [20] =
    {field_entity, 1},
  [21] =
    {field_name, 1},
  [22] =
    {field_message, 0},
  [23] =
    {field_message, 1, .inherited = true},
  [24] =
    {field_target_entity, 4, .inherited = true},
    {field_target_label, 4, .inherited = true},
  [26] =
    {field_target_entity, 0, .inherited = true},
    {field_target_entity, 1, .inherited = true},
    {field_target_label, 0, .inherited = true},
    {field_target_label, 1, .inherited = true},
  [30] =
    {field_wrap, 1},
  [31] =
    {field_portrait, 1},
  [32] =
    {field_alignment, 1},
  [33] =
    {field_border_tileset, 1},
  [34] =
    {field_emote, 1},
  [35] =
    {field_message, 2, .inherited = true},
  [36] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [38] =
    {field_target_label, 1},
  [39] =
    {field_target_entity, 1},
  [40] =
    {field_property, 0},
    {field_value, 2},
  [42] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [45] =
    {field_label, 1},
    {field_script, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [31] = {
    [2] = alias_sym_label_settings,
  },
  [32] = {
    [2] = alias_sym_entity_settings,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym_dialog_settings_block, 3,
    sym_dialog_settings_block,
    alias_sym_entity_settings,
    alias_sym_label_settings,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(190);
      ADVANCE_MAP(
        '"', 6,
        '#', 337,
        '$', 187,
        ',', 344,
        '-', 15,
        '/', 7,
        ':', 340,
        ';', 312,
        '=', 313,
        '>', 335,
        'B', 19,
        'I', 119,
        'T', 20,
        '[', 343,
        ']', 345,
        '_', 336,
        'a', 48,
        'b', 104,
        'c', 105,
        'd', 64,
        'e', 116,
        'f', 29,
        'g', 133,
        'i', 120,
        'j', 153,
        'l', 30,
        'm', 31,
        'n', 32,
        'o', 78,
        'p', 132,
        'r', 56,
        's', 45,
        't', 87,
        'w', 86,
        'y', 75,
        '{', 319,
        '}', 320,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(192);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 6,
        '#', 183,
        '$', 187,
        '/', 7,
        'b', 247,
        'c', 249,
        'f', 203,
        'g', 275,
        'm', 200,
        'o', 229,
        'r', 224,
        't', 235,
        'w', 233,
        'y', 225,
        '{', 319,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(297);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(187);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == 'i') ADVANCE(261);
      if (lookahead == 'l') ADVANCE(197);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 6,
        '-', 15,
        '/', 7,
        'I', 119,
        '[', 343,
        ']', 345,
        'f', 29,
        'n', 172,
        't', 142,
        '{', 319,
        '}', 320,
        '#', 336,
        '_', 336,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(347);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == '>') ADVANCE(335);
      if (lookahead == 'e') ADVANCE(260);
      if (lookahead == 'n') ADVANCE(196);
      if (lookahead == '}') ADVANCE(320);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(295);
      if (lookahead == '\\') ADVANCE(188);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(8);
      if (lookahead == '/') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        ',', 344,
        '/', 7,
        ']', 345,
        'g', 268,
        'j', 278,
        'l', 266,
        'r', 221,
        's', 234,
        '}', 320,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 11:
      if (lookahead == 'E') ADVANCE(12);
      END_STATE();
    case 12:
      if (lookahead == 'F') ADVANCE(23);
      END_STATE();
    case 13:
      if (lookahead == 'G') ADVANCE(14);
      END_STATE();
    case 14:
      if (lookahead == 'H') ADVANCE(23);
      END_STATE();
    case 15:
      if (lookahead == 'I') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(347);
      END_STATE();
    case 16:
      if (lookahead == 'I') ADVANCE(13);
      END_STATE();
    case 17:
      if (lookahead == 'L') ADVANCE(11);
      if (lookahead == 'R') ADVANCE(16);
      END_STATE();
    case 18:
      if (lookahead == 'M') ADVANCE(26);
      END_STATE();
    case 19:
      if (lookahead == 'O') ADVANCE(25);
      if (lookahead == 'L' ||
          lookahead == 'R') ADVANCE(309);
      END_STATE();
    case 20:
      if (lookahead == 'O') ADVANCE(22);
      if (lookahead == 'L' ||
          lookahead == 'R') ADVANCE(309);
      END_STATE();
    case 21:
      if (lookahead == 'O') ADVANCE(18);
      END_STATE();
    case 22:
      if (lookahead == 'P') ADVANCE(26);
      END_STATE();
    case 23:
      if (lookahead == 'T') ADVANCE(309);
      END_STATE();
    case 24:
      if (lookahead == 'T') ADVANCE(21);
      END_STATE();
    case 25:
      if (lookahead == 'T') ADVANCE(24);
      END_STATE();
    case 26:
      if (lookahead == '_') ADVANCE(17);
      END_STATE();
    case 27:
      if (lookahead == '_') ADVANCE(55);
      END_STATE();
    case 28:
      if (lookahead == '_') ADVANCE(167);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(114);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(43);
      if (lookahead == 'o') ADVANCE(37);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(85);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(117);
      if (lookahead == 'u') ADVANCE(108);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(44);
      if (lookahead == 'u') ADVANCE(58);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(302);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(140);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(122);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(52);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(109);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(174);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(106);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(111);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(97);
      END_STATE();
    case 43:
      if (lookahead == 'b') ADVANCE(70);
      END_STATE();
    case 44:
      if (lookahead == 'c') ADVANCE(101);
      END_STATE();
    case 45:
      if (lookahead == 'c') ADVANCE(147);
      if (lookahead == 'e') ADVANCE(148);
      if (lookahead == 'h') ADVANCE(130);
      END_STATE();
    case 46:
      if (lookahead == 'c') ADVANCE(107);
      if (lookahead == 'd') ADVANCE(65);
      END_STATE();
    case 47:
      if (lookahead == 'c') ADVANCE(57);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(49);
      if (lookahead == 'l') ADVANCE(88);
      END_STATE();
    case 49:
      if (lookahead == 'd') ADVANCE(314);
      END_STATE();
    case 50:
      if (lookahead == 'd') ADVANCE(306);
      END_STATE();
    case 51:
      if (lookahead == 'd') ADVANCE(302);
      if (lookahead == 't') ADVANCE(173);
      END_STATE();
    case 52:
      if (lookahead == 'd') ADVANCE(354);
      END_STATE();
    case 53:
      if (lookahead == 'd') ADVANCE(71);
      END_STATE();
    case 54:
      if (lookahead == 'd') ADVANCE(63);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(100);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(51);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(301);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(302);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(329);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(349);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(334);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(350);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(310);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(80);
      if (lookahead == 'i') ADVANCE(38);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(180);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(122);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(50);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(121);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(103);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(145);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(126);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(127);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(162);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(115);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(156);
      END_STATE();
    case 77:
      if (lookahead == 'f') ADVANCE(306);
      END_STATE();
    case 78:
      if (lookahead == 'f') ADVANCE(77);
      if (lookahead == 'n') ADVANCE(307);
      if (lookahead == 'p') ADVANCE(68);
      END_STATE();
    case 79:
      if (lookahead == 'f') ADVANCE(93);
      END_STATE();
    case 80:
      if (lookahead == 'f') ADVANCE(39);
      END_STATE();
    case 81:
      if (lookahead == 'g') ADVANCE(322);
      END_STATE();
    case 82:
      if (lookahead == 'g') ADVANCE(316);
      END_STATE();
    case 83:
      if (lookahead == 'g') ADVANCE(152);
      END_STATE();
    case 84:
      if (lookahead == 'g') ADVANCE(128);
      END_STATE();
    case 85:
      if (lookahead == 'g') ADVANCE(72);
      if (lookahead == 'p') ADVANCE(356);
      END_STATE();
    case 86:
      if (lookahead == 'h') ADVANCE(98);
      if (lookahead == 'r') ADVANCE(35);
      END_STATE();
    case 87:
      if (lookahead == 'h') ADVANCE(144);
      if (lookahead == 'r') ADVANCE(175);
      if (lookahead == 'w') ADVANCE(90);
      END_STATE();
    case 88:
      if (lookahead == 'i') ADVANCE(84);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(179);
      if (lookahead == 'x') ADVANCE(300);
      END_STATE();
    case 90:
      if (lookahead == 'i') ADVANCE(47);
      END_STATE();
    case 91:
      if (lookahead == 'i') ADVANCE(141);
      END_STATE();
    case 92:
      if (lookahead == 'i') ADVANCE(157);
      END_STATE();
    case 93:
      if (lookahead == 'i') ADVANCE(129);
      END_STATE();
    case 94:
      if (lookahead == 'i') ADVANCE(163);
      END_STATE();
    case 95:
      if (lookahead == 'i') ADVANCE(113);
      END_STATE();
    case 96:
      if (lookahead == 'i') ADVANCE(125);
      END_STATE();
    case 97:
      if (lookahead == 'i') ADVANCE(160);
      END_STATE();
    case 98:
      if (lookahead == 'i') ADVANCE(164);
      END_STATE();
    case 99:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 100:
      if (lookahead == 'i') ADVANCE(41);
      END_STATE();
    case 101:
      if (lookahead == 'k') ADVANCE(302);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(351);
      END_STATE();
    case 103:
      if (lookahead == 'l') ADVANCE(325);
      END_STATE();
    case 104:
      if (lookahead == 'l') ADVANCE(33);
      if (lookahead == 'o') ADVANCE(143);
      END_STATE();
    case 105:
      if (lookahead == 'l') ADVANCE(136);
      if (lookahead == 'y') ADVANCE(36);
      END_STATE();
    case 106:
      if (lookahead == 'l') ADVANCE(27);
      END_STATE();
    case 107:
      if (lookahead == 'l') ADVANCE(176);
      END_STATE();
    case 108:
      if (lookahead == 'l') ADVANCE(102);
      END_STATE();
    case 109:
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 110:
      if (lookahead == 'l') ADVANCE(135);
      END_STATE();
    case 111:
      if (lookahead == 'l') ADVANCE(139);
      END_STATE();
    case 112:
      if (lookahead == 'l') ADVANCE(159);
      END_STATE();
    case 113:
      if (lookahead == 'l') ADVANCE(76);
      END_STATE();
    case 114:
      if (lookahead == 'l') ADVANCE(155);
      END_STATE();
    case 115:
      if (lookahead == 'l') ADVANCE(110);
      END_STATE();
    case 116:
      if (lookahead == 'm') ADVANCE(137);
      if (lookahead == 'n') ADVANCE(170);
      END_STATE();
    case 117:
      if (lookahead == 'm') ADVANCE(59);
      END_STATE();
    case 118:
      if (lookahead == 'm') ADVANCE(73);
      END_STATE();
    case 119:
      if (lookahead == 'n') ADVANCE(79);
      END_STATE();
    case 120:
      if (lookahead == 'n') ADVANCE(46);
      END_STATE();
    case 121:
      if (lookahead == 'n') ADVANCE(306);
      END_STATE();
    case 122:
      if (lookahead == 'n') ADVANCE(302);
      END_STATE();
    case 123:
      if (lookahead == 'n') ADVANCE(341);
      END_STATE();
    case 124:
      if (lookahead == 'n') ADVANCE(352);
      END_STATE();
    case 125:
      if (lookahead == 'n') ADVANCE(83);
      END_STATE();
    case 126:
      if (lookahead == 'n') ADVANCE(168);
      END_STATE();
    case 127:
      if (lookahead == 'n') ADVANCE(161);
      END_STATE();
    case 128:
      if (lookahead == 'n') ADVANCE(118);
      END_STATE();
    case 129:
      if (lookahead == 'n') ADVANCE(94);
      END_STATE();
    case 130:
      if (lookahead == 'o') ADVANCE(178);
      END_STATE();
    case 131:
      if (lookahead == 'o') ADVANCE(357);
      END_STATE();
    case 132:
      if (lookahead == 'o') ADVANCE(146);
      END_STATE();
    case 133:
      if (lookahead == 'o') ADVANCE(166);
      if (lookahead == 'r') ADVANCE(69);
      END_STATE();
    case 134:
      if (lookahead == 'o') ADVANCE(81);
      END_STATE();
    case 135:
      if (lookahead == 'o') ADVANCE(177);
      END_STATE();
    case 136:
      if (lookahead == 'o') ADVANCE(154);
      END_STATE();
    case 137:
      if (lookahead == 'o') ADVANCE(169);
      END_STATE();
    case 138:
      if (lookahead == 'o') ADVANCE(123);
      END_STATE();
    case 139:
      if (lookahead == 'o') ADVANCE(82);
      END_STATE();
    case 140:
      if (lookahead == 'p') ADVANCE(321);
      END_STATE();
    case 141:
      if (lookahead == 'p') ADVANCE(158);
      END_STATE();
    case 142:
      if (lookahead == 'r') ADVANCE(175);
      END_STATE();
    case 143:
      if (lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 144:
      if (lookahead == 'r') ADVANCE(90);
      END_STATE();
    case 145:
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 146:
      if (lookahead == 'r') ADVANCE(165);
      END_STATE();
    case 147:
      if (lookahead == 'r') ADVANCE(91);
      END_STATE();
    case 148:
      if (lookahead == 'r') ADVANCE(99);
      if (lookahead == 't') ADVANCE(171);
      END_STATE();
    case 149:
      if (lookahead == 'r') ADVANCE(42);
      END_STATE();
    case 150:
      if (lookahead == 'r') ADVANCE(124);
      END_STATE();
    case 151:
      if (lookahead == 's') ADVANCE(299);
      END_STATE();
    case 152:
      if (lookahead == 's') ADVANCE(318);
      END_STATE();
    case 153:
      if (lookahead == 's') ADVANCE(138);
      END_STATE();
    case 154:
      if (lookahead == 's') ADVANCE(67);
      END_STATE();
    case 155:
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 156:
      if (lookahead == 's') ADVANCE(74);
      END_STATE();
    case 157:
      if (lookahead == 't') ADVANCE(181);
      END_STATE();
    case 158:
      if (lookahead == 't') ADVANCE(338);
      END_STATE();
    case 159:
      if (lookahead == 't') ADVANCE(324);
      END_STATE();
    case 160:
      if (lookahead == 't') ADVANCE(331);
      END_STATE();
    case 161:
      if (lookahead == 't') ADVANCE(332);
      END_STATE();
    case 162:
      if (lookahead == 't') ADVANCE(333);
      END_STATE();
    case 163:
      if (lookahead == 't') ADVANCE(182);
      END_STATE();
    case 164:
      if (lookahead == 't') ADVANCE(58);
      END_STATE();
    case 165:
      if (lookahead == 't') ADVANCE(149);
      END_STATE();
    case 166:
      if (lookahead == 't') ADVANCE(131);
      END_STATE();
    case 167:
      if (lookahead == 't') ADVANCE(95);
      END_STATE();
    case 168:
      if (lookahead == 't') ADVANCE(34);
      END_STATE();
    case 169:
      if (lookahead == 't') ADVANCE(61);
      END_STATE();
    case 170:
      if (lookahead == 't') ADVANCE(92);
      END_STATE();
    case 171:
      if (lookahead == 't') ADVANCE(96);
      END_STATE();
    case 172:
      if (lookahead == 'u') ADVANCE(108);
      END_STATE();
    case 173:
      if (lookahead == 'u') ADVANCE(150);
      END_STATE();
    case 174:
      if (lookahead == 'u') ADVANCE(112);
      END_STATE();
    case 175:
      if (lookahead == 'u') ADVANCE(60);
      END_STATE();
    case 176:
      if (lookahead == 'u') ADVANCE(54);
      END_STATE();
    case 177:
      if (lookahead == 'w') ADVANCE(302);
      END_STATE();
    case 178:
      if (lookahead == 'w') ADVANCE(361);
      END_STATE();
    case 179:
      if (lookahead == 'x') ADVANCE(300);
      END_STATE();
    case 180:
      if (lookahead == 'x') ADVANCE(359);
      END_STATE();
    case 181:
      if (lookahead == 'y') ADVANCE(327);
      END_STATE();
    case 182:
      if (lookahead == 'y') ADVANCE(346);
      END_STATE();
    case 183:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(186);
      END_STATE();
    case 184:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(348);
      END_STATE();
    case 185:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(305);
      END_STATE();
    case 186:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(185);
      END_STATE();
    case 187:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      END_STATE();
    case 188:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 189:
      if (eof) ADVANCE(190);
      if (lookahead == '$') ADVANCE(187);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == ';') ADVANCE(312);
      if (lookahead == 'a') ADVANCE(214);
      if (lookahead == 'd') ADVANCE(236);
      if (lookahead == 'i') ADVANCE(256);
      if (lookahead == 's') ADVANCE(206);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(189);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(298);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(9);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_line_comment);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(207);
      if (lookahead == 'u') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(272);
      if (lookahead == 'e') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(355);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(311);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(228);
      if (lookahead == 'n') ADVANCE(209);
      if (lookahead == 'p') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(323);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(273);
      if (lookahead == 'r') ADVANCE(289);
      if (lookahead == 'w') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(281);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(269);
      if (lookahead == 'y') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(286);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(284);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(265);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(339);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(293);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(274);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(362);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(360);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == '.') ADVANCE(184);
      if (lookahead == 'm') ADVANCE(151);
      if (lookahead == 'p') ADVANCE(89);
      if (lookahead == 's') ADVANCE(299);
      if (lookahead == 'x') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(296);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == 'm') ADVANCE(151);
      if (lookahead == 'p') ADVANCE(89);
      if (lookahead == 's') ADVANCE(299);
      if (lookahead == 'x') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(297);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(298);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_DURATION);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_DISTANCE);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_QUANTITY);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(302);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(303);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(304);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_BOOLEAN);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_BOOLEAN);
      if (lookahead == 'c') ADVANCE(57);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(308);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_ENUM_ALIGNMENT);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(anon_sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(186);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_json_number);
      if (lookahead == '.') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(347);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(348);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_return_statement);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(anon_sym_show);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(anon_sym_show);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(294);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 189},
  [2] = {.lex_state = 189},
  [3] = {.lex_state = 10},
  [4] = {.lex_state = 10},
  [5] = {.lex_state = 189},
  [6] = {.lex_state = 10},
  [7] = {.lex_state = 4},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 4},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 189},
  [17] = {.lex_state = 10},
  [18] = {.lex_state = 5},
  [19] = {.lex_state = 189},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 10},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 5},
  [29] = {.lex_state = 10},
  [30] = {.lex_state = 189},
  [31] = {.lex_state = 189},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 189},
  [35] = {.lex_state = 189},
  [36] = {.lex_state = 189},
  [37] = {.lex_state = 189},
  [38] = {.lex_state = 189},
  [39] = {.lex_state = 189},
  [40] = {.lex_state = 189},
  [41] = {.lex_state = 189},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 189},
  [44] = {.lex_state = 189},
  [45] = {.lex_state = 189},
  [46] = {.lex_state = 189},
  [47] = {.lex_state = 10},
  [48] = {.lex_state = 10},
  [49] = {.lex_state = 5},
  [50] = {.lex_state = 10},
  [51] = {.lex_state = 5},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 5},
  [54] = {.lex_state = 5},
  [55] = {.lex_state = 5},
  [56] = {.lex_state = 5},
  [57] = {.lex_state = 5},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 5},
  [61] = {.lex_state = 3},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 5},
  [69] = {.lex_state = 4},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 4},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 4},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 2},
  [86] = {.lex_state = 4},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 189},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 189},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 189},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 189},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 4},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 2},
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
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_QUOTED_STRING] = ACTIONS(1),
    [sym_NUMBER] = ACTIONS(1),
    [sym_DURATION] = ACTIONS(1),
    [sym_DISTANCE] = ACTIONS(1),
    [sym_QUANTITY] = ACTIONS(1),
    [sym_COLOR] = ACTIONS(1),
    [sym_BOOLEAN] = ACTIONS(1),
    [sym_CONSTANT] = ACTIONS(1),
    [sym_ENUM_ALIGNMENT] = ACTIONS(1),
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
    [anon_sym_default] = ACTIONS(1),
    [anon_sym_label] = ACTIONS(1),
    [anon_sym_entity] = ACTIONS(1),
    [anon_sym_name] = ACTIONS(1),
    [anon_sym_portrait] = ACTIONS(1),
    [anon_sym_alignment] = ACTIONS(1),
    [anon_sym_border_tileset] = ACTIONS(1),
    [anon_sym_emote] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym_serial_dialog_option_type] = ACTIONS(1),
    [anon_sym_script] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_json] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_json_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [sym_return_statement] = ACTIONS(1),
    [anon_sym_load] = ACTIONS(1),
    [anon_sym_map] = ACTIONS(1),
    [anon_sym_goto] = ACTIONS(1),
    [anon_sym_index] = ACTIONS(1),
    [anon_sym_show] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(140),
    [sym__root] = STATE(5),
    [sym_include_macro] = STATE(5),
    [sym_constant_assignment] = STATE(5),
    [sym_add_serial_dialog_settings] = STATE(5),
    [sym_add_dialog_settings] = STATE(5),
    [sym_dialog_definition] = STATE(5),
    [sym_serial_dialog_definition] = STATE(5),
    [sym_script_definition] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(7),
    [sym_CONSTANT] = ACTIONS(9),
    [anon_sym_include] = ACTIONS(11),
    [anon_sym_add] = ACTIONS(13),
    [anon_sym_serial_dialog] = ACTIONS(15),
    [anon_sym_dialog] = ACTIONS(17),
    [anon_sym_script] = ACTIONS(19),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      sym_BAREWORD,
    ACTIONS(26), 1,
      sym_CONSTANT,
    ACTIONS(29), 1,
      anon_sym_include,
    ACTIONS(32), 1,
      anon_sym_add,
    ACTIONS(35), 1,
      anon_sym_serial_dialog,
    ACTIONS(38), 1,
      anon_sym_dialog,
    ACTIONS(41), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [40] = 10,
    ACTIONS(44), 1,
      sym_BAREWORD,
    ACTIONS(47), 1,
      anon_sym_RBRACE,
    ACTIONS(49), 1,
      anon_sym_json,
    ACTIONS(52), 1,
      sym_return_statement,
    ACTIONS(55), 1,
      anon_sym_load,
    ACTIONS(58), 1,
      anon_sym_goto,
    ACTIONS(61), 1,
      anon_sym_show,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(3), 4,
      sym__script_item,
      sym_label,
      sym_json_block,
      aux_sym_script_block_repeat1,
    STATE(137), 6,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_action_label,
      sym_action_goto_action_index,
      sym_action_show_dialog,
  [80] = 10,
    ACTIONS(64), 1,
      sym_BAREWORD,
    ACTIONS(66), 1,
      anon_sym_RBRACE,
    ACTIONS(68), 1,
      anon_sym_json,
    ACTIONS(70), 1,
      sym_return_statement,
    ACTIONS(72), 1,
      anon_sym_load,
    ACTIONS(74), 1,
      anon_sym_goto,
    ACTIONS(76), 1,
      anon_sym_show,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(3), 4,
      sym__script_item,
      sym_label,
      sym_json_block,
      aux_sym_script_block_repeat1,
    STATE(137), 6,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_action_label,
      sym_action_goto_action_index,
      sym_action_show_dialog,
  [120] = 10,
    ACTIONS(7), 1,
      sym_BAREWORD,
    ACTIONS(9), 1,
      sym_CONSTANT,
    ACTIONS(11), 1,
      anon_sym_include,
    ACTIONS(13), 1,
      anon_sym_add,
    ACTIONS(15), 1,
      anon_sym_serial_dialog,
    ACTIONS(17), 1,
      anon_sym_dialog,
    ACTIONS(19), 1,
      anon_sym_script,
    ACTIONS(78), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 9,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_add_dialog_settings,
      sym_dialog_definition,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [160] = 10,
    ACTIONS(64), 1,
      sym_BAREWORD,
    ACTIONS(68), 1,
      anon_sym_json,
    ACTIONS(70), 1,
      sym_return_statement,
    ACTIONS(72), 1,
      anon_sym_load,
    ACTIONS(74), 1,
      anon_sym_goto,
    ACTIONS(76), 1,
      anon_sym_show,
    ACTIONS(80), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(4), 4,
      sym__script_item,
      sym_label,
      sym_json_block,
      aux_sym_script_block_repeat1,
    STATE(137), 6,
      sym__action_item,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_action_label,
      sym_action_goto_action_index,
      sym_action_show_dialog,
  [200] = 7,
    ACTIONS(84), 1,
      anon_sym_LBRACE,
    ACTIONS(86), 1,
      anon_sym_LBRACK,
    ACTIONS(88), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(82), 2,
      sym_QUOTED_STRING,
      sym_json_number,
    ACTIONS(90), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(104), 4,
      sym_json_array,
      sym__json_item,
      sym_json_language_constant,
      sym_json_object,
  [229] = 4,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(139), 2,
      sym__STRING,
      sym__NUMBERISH,
    ACTIONS(92), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(94), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [251] = 11,
    ACTIONS(96), 1,
      sym_QUOTED_STRING,
    ACTIONS(98), 1,
      anon_sym_wrap,
    ACTIONS(100), 1,
      anon_sym_entity,
    ACTIONS(102), 1,
      anon_sym_name,
    ACTIONS(104), 1,
      anon_sym_portrait,
    ACTIONS(106), 1,
      anon_sym_alignment,
    ACTIONS(108), 1,
      anon_sym_border_tileset,
    ACTIONS(110), 1,
      anon_sym_emote,
    STATE(18), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(10), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [287] = 11,
    ACTIONS(96), 1,
      sym_QUOTED_STRING,
    ACTIONS(98), 1,
      anon_sym_wrap,
    ACTIONS(100), 1,
      anon_sym_entity,
    ACTIONS(102), 1,
      anon_sym_name,
    ACTIONS(104), 1,
      anon_sym_portrait,
    ACTIONS(106), 1,
      anon_sym_alignment,
    ACTIONS(108), 1,
      anon_sym_border_tileset,
    ACTIONS(110), 1,
      anon_sym_emote,
    STATE(28), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(12), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [323] = 6,
    ACTIONS(84), 1,
      anon_sym_LBRACE,
    ACTIONS(86), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(112), 2,
      sym_QUOTED_STRING,
      sym_json_number,
    ACTIONS(90), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(120), 4,
      sym_json_array,
      sym__json_item,
      sym_json_language_constant,
      sym_json_object,
  [349] = 10,
    ACTIONS(116), 1,
      anon_sym_wrap,
    ACTIONS(119), 1,
      anon_sym_entity,
    ACTIONS(122), 1,
      anon_sym_name,
    ACTIONS(125), 1,
      anon_sym_portrait,
    ACTIONS(128), 1,
      anon_sym_alignment,
    ACTIONS(131), 1,
      anon_sym_border_tileset,
    ACTIONS(134), 1,
      anon_sym_emote,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(114), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(12), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [383] = 6,
    ACTIONS(84), 1,
      anon_sym_LBRACE,
    ACTIONS(86), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(137), 2,
      sym_QUOTED_STRING,
      sym_json_number,
    ACTIONS(90), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(123), 4,
      sym_json_array,
      sym__json_item,
      sym_json_language_constant,
      sym_json_object,
  [409] = 10,
    ACTIONS(98), 1,
      anon_sym_wrap,
    ACTIONS(100), 1,
      anon_sym_entity,
    ACTIONS(102), 1,
      anon_sym_name,
    ACTIONS(104), 1,
      anon_sym_portrait,
    ACTIONS(106), 1,
      anon_sym_alignment,
    ACTIONS(108), 1,
      anon_sym_border_tileset,
    ACTIONS(110), 1,
      anon_sym_emote,
    ACTIONS(139), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(15), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [442] = 10,
    ACTIONS(98), 1,
      anon_sym_wrap,
    ACTIONS(100), 1,
      anon_sym_entity,
    ACTIONS(102), 1,
      anon_sym_name,
    ACTIONS(104), 1,
      anon_sym_portrait,
    ACTIONS(106), 1,
      anon_sym_alignment,
    ACTIONS(108), 1,
      anon_sym_border_tileset,
    ACTIONS(110), 1,
      anon_sym_emote,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(12), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [475] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(143), 3,
      ts_builtin_sym_end,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(145), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [493] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(149), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(147), 6,
      sym_BAREWORD,
      anon_sym_json,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
  [511] = 7,
    ACTIONS(96), 1,
      sym_QUOTED_STRING,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    ACTIONS(155), 1,
      anon_sym_GT,
    STATE(55), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(53), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(151), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [537] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(157), 3,
      ts_builtin_sym_end,
      sym_CONSTANT,
      anon_sym_SEMI,
    ACTIONS(159), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [555] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(161), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [571] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(163), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [587] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(165), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [603] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(167), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [619] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(169), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [635] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(171), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [651] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(175), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(173), 6,
      sym_BAREWORD,
      anon_sym_json,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
  [669] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(177), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [685] = 7,
    ACTIONS(96), 1,
      sym_QUOTED_STRING,
    ACTIONS(155), 1,
      anon_sym_GT,
    ACTIONS(181), 1,
      anon_sym_RBRACE,
    STATE(55), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(57), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(179), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [711] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(185), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(183), 6,
      sym_BAREWORD,
      anon_sym_json,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
  [729] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(187), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(189), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [746] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(191), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(193), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [763] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(195), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [778] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(197), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [793] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(199), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(201), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [810] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(203), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(205), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [827] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(207), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(209), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [844] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(211), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(213), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [861] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(215), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(217), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [878] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(219), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(221), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [895] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(223), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(225), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [912] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(227), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(229), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [929] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(231), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [944] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(233), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(235), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [961] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(237), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(239), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [978] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(241), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(243), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [995] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(245), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(247), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [1012] = 3,
    ACTIONS(251), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(249), 6,
      sym_BAREWORD,
      anon_sym_json,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
  [1028] = 3,
    ACTIONS(255), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(253), 6,
      sym_BAREWORD,
      anon_sym_json,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
  [1044] = 7,
    ACTIONS(257), 1,
      sym_BAREWORD,
    ACTIONS(260), 1,
      anon_sym_RBRACE,
    ACTIONS(262), 1,
      anon_sym_entity,
    ACTIONS(265), 1,
      anon_sym_name,
    STATE(9), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(49), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1068] = 3,
    ACTIONS(270), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(268), 6,
      sym_BAREWORD,
      anon_sym_json,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
      anon_sym_show,
  [1084] = 7,
    ACTIONS(272), 1,
      sym_BAREWORD,
    ACTIONS(274), 1,
      anon_sym_RBRACE,
    ACTIONS(276), 1,
      anon_sym_entity,
    ACTIONS(278), 1,
      anon_sym_name,
    STATE(9), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(49), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1108] = 7,
    ACTIONS(280), 1,
      sym_QUOTED_STRING,
    ACTIONS(282), 1,
      anon_sym_RBRACE,
    ACTIONS(284), 1,
      anon_sym_wrap,
    STATE(59), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(148), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(67), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1132] = 5,
    ACTIONS(155), 1,
      anon_sym_GT,
    ACTIONS(288), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(54), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(286), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1152] = 5,
    ACTIONS(292), 1,
      anon_sym_RBRACE,
    ACTIONS(294), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(54), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(290), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1172] = 5,
    ACTIONS(299), 1,
      sym_QUOTED_STRING,
    STATE(55), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(302), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(297), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1192] = 7,
    ACTIONS(272), 1,
      sym_BAREWORD,
    ACTIONS(276), 1,
      anon_sym_entity,
    ACTIONS(278), 1,
      anon_sym_name,
    ACTIONS(304), 1,
      anon_sym_RBRACE,
    STATE(9), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(51), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1216] = 5,
    ACTIONS(155), 1,
      anon_sym_GT,
    ACTIONS(308), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(54), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(306), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1236] = 6,
    ACTIONS(280), 1,
      sym_QUOTED_STRING,
    ACTIONS(310), 1,
      anon_sym_RBRACE,
    ACTIONS(312), 1,
      sym_serial_dialog_option_type,
    STATE(82), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(69), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1257] = 6,
    ACTIONS(280), 1,
      sym_QUOTED_STRING,
    ACTIONS(312), 1,
      sym_serial_dialog_option_type,
    ACTIONS(314), 1,
      anon_sym_RBRACE,
    STATE(82), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(86), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1278] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(316), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
    ACTIONS(318), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [1293] = 6,
    ACTIONS(320), 1,
      sym_BAREWORD,
    ACTIONS(324), 1,
      anon_sym_label,
    ACTIONS(326), 1,
      anon_sym_index,
    STATE(146), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(322), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1314] = 5,
    ACTIONS(330), 1,
      anon_sym_LBRACE,
    STATE(105), 1,
      sym__STRING,
    STATE(133), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(328), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1332] = 6,
    ACTIONS(332), 1,
      anon_sym_RBRACE,
    ACTIONS(334), 1,
      anon_sym_default,
    ACTIONS(337), 1,
      anon_sym_label,
    ACTIONS(340), 1,
      anon_sym_entity,
    STATE(63), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1352] = 6,
    ACTIONS(343), 1,
      anon_sym_RBRACE,
    ACTIONS(345), 1,
      anon_sym_default,
    ACTIONS(347), 1,
      anon_sym_label,
    ACTIONS(349), 1,
      anon_sym_entity,
    STATE(65), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1372] = 6,
    ACTIONS(345), 1,
      anon_sym_default,
    ACTIONS(347), 1,
      anon_sym_label,
    ACTIONS(349), 1,
      anon_sym_entity,
    ACTIONS(351), 1,
      anon_sym_RBRACE,
    STATE(63), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1392] = 4,
    ACTIONS(355), 1,
      anon_sym_wrap,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(353), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(66), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1408] = 5,
    ACTIONS(280), 1,
      sym_QUOTED_STRING,
    ACTIONS(284), 1,
      anon_sym_wrap,
    STATE(58), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(66), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1426] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(360), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(358), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1440] = 4,
    ACTIONS(312), 1,
      sym_serial_dialog_option_type,
    ACTIONS(362), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(75), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1455] = 3,
    STATE(68), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(364), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1468] = 3,
    STATE(20), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(366), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1481] = 3,
    STATE(151), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(368), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1494] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(370), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1505] = 3,
    STATE(21), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(372), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1518] = 4,
    ACTIONS(374), 1,
      anon_sym_RBRACE,
    ACTIONS(376), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(75), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1533] = 4,
    ACTIONS(284), 1,
      anon_sym_wrap,
    ACTIONS(379), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(77), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1548] = 4,
    ACTIONS(284), 1,
      anon_sym_wrap,
    ACTIONS(381), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(66), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1563] = 3,
    STATE(22), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(383), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1576] = 3,
    STATE(114), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(385), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1589] = 3,
    STATE(27), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(387), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1602] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(389), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1613] = 4,
    ACTIONS(391), 1,
      sym_QUOTED_STRING,
    STATE(82), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(394), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1628] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(396), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1639] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(398), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1650] = 3,
    STATE(126), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(400), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1663] = 4,
    ACTIONS(312), 1,
      sym_serial_dialog_option_type,
    ACTIONS(402), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(75), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1678] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(404), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1689] = 3,
    STATE(116), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(406), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1702] = 3,
    STATE(32), 1,
      sym__STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(408), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1714] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(410), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1724] = 3,
    STATE(125), 1,
      sym__bareword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(412), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1736] = 4,
    ACTIONS(414), 1,
      anon_sym_RBRACE,
    ACTIONS(416), 1,
      anon_sym_COMMA,
    STATE(98), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1750] = 3,
    STATE(23), 1,
      sym__enum_alignment,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(418), 2,
      sym_CONSTANT,
      sym_ENUM_ALIGNMENT,
  [1762] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(420), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [1772] = 3,
    STATE(127), 1,
      sym__number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(422), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1784] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(424), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1794] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(426), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1804] = 4,
    ACTIONS(416), 1,
      anon_sym_COMMA,
    ACTIONS(428), 1,
      anon_sym_RBRACE,
    STATE(109), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1818] = 3,
    STATE(94), 1,
      sym__number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(430), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1830] = 4,
    ACTIONS(432), 1,
      anon_sym_COMMA,
    ACTIONS(435), 1,
      anon_sym_RBRACK,
    STATE(100), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1844] = 3,
    STATE(33), 1,
      sym__STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(437), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1856] = 3,
    STATE(115), 1,
      sym__STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(439), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1868] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(441), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1878] = 4,
    ACTIONS(443), 1,
      anon_sym_COMMA,
    ACTIONS(445), 1,
      anon_sym_RBRACK,
    STATE(106), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1892] = 4,
    ACTIONS(330), 1,
      anon_sym_LBRACE,
    ACTIONS(447), 1,
      anon_sym_SEMI,
    STATE(142), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1906] = 4,
    ACTIONS(443), 1,
      anon_sym_COMMA,
    ACTIONS(449), 1,
      anon_sym_RBRACK,
    STATE(100), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1920] = 3,
    STATE(25), 1,
      sym__number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(451), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1932] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(453), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1942] = 4,
    ACTIONS(455), 1,
      anon_sym_RBRACE,
    ACTIONS(457), 1,
      anon_sym_COMMA,
    STATE(109), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1956] = 4,
    ACTIONS(460), 1,
      sym_QUOTED_STRING,
    ACTIONS(462), 1,
      anon_sym_RBRACE,
    STATE(92), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1970] = 3,
    STATE(129), 1,
      sym__bareword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(464), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1982] = 3,
    STATE(24), 1,
      sym__number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(466), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1994] = 3,
    ACTIONS(468), 1,
      anon_sym_LBRACE,
    STATE(73), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2005] = 3,
    ACTIONS(468), 1,
      anon_sym_LBRACE,
    STATE(84), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2016] = 3,
    ACTIONS(470), 1,
      anon_sym_LBRACE,
    STATE(44), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2027] = 3,
    ACTIONS(330), 1,
      anon_sym_LBRACE,
    STATE(31), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2038] = 3,
    ACTIONS(472), 1,
      anon_sym_LBRACE,
    STATE(34), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2049] = 3,
    ACTIONS(86), 1,
      anon_sym_LBRACK,
    STATE(47), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2060] = 3,
    ACTIONS(460), 1,
      sym_QUOTED_STRING,
    STATE(124), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2071] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(435), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [2080] = 3,
    ACTIONS(474), 1,
      anon_sym_serial_dialog,
    ACTIONS(476), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2091] = 3,
    ACTIONS(472), 1,
      anon_sym_LBRACE,
    STATE(37), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2102] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(478), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2111] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(455), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [2120] = 3,
    ACTIONS(468), 1,
      anon_sym_LBRACE,
    STATE(83), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2131] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(480), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [2140] = 2,
    ACTIONS(482), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2148] = 2,
    ACTIONS(484), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2156] = 2,
    ACTIONS(486), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2164] = 2,
    ACTIONS(488), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2172] = 2,
    ACTIONS(490), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2180] = 2,
    ACTIONS(492), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2188] = 2,
    ACTIONS(494), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2196] = 2,
    ACTIONS(496), 1,
      sym_BAREWORD,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2204] = 2,
    ACTIONS(498), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2212] = 2,
    ACTIONS(500), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2220] = 2,
    ACTIONS(502), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2228] = 2,
    ACTIONS(504), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2236] = 2,
    ACTIONS(506), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2244] = 2,
    ACTIONS(508), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2252] = 2,
    ACTIONS(510), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2260] = 2,
    ACTIONS(512), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2268] = 2,
    ACTIONS(514), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2276] = 2,
    ACTIONS(516), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2284] = 2,
    ACTIONS(518), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2292] = 2,
    ACTIONS(520), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2300] = 2,
    ACTIONS(522), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2308] = 2,
    ACTIONS(524), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2316] = 2,
    ACTIONS(526), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2324] = 2,
    ACTIONS(528), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2332] = 2,
    ACTIONS(530), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2340] = 2,
    ACTIONS(532), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 40,
  [SMALL_STATE(4)] = 80,
  [SMALL_STATE(5)] = 120,
  [SMALL_STATE(6)] = 160,
  [SMALL_STATE(7)] = 200,
  [SMALL_STATE(8)] = 229,
  [SMALL_STATE(9)] = 251,
  [SMALL_STATE(10)] = 287,
  [SMALL_STATE(11)] = 323,
  [SMALL_STATE(12)] = 349,
  [SMALL_STATE(13)] = 383,
  [SMALL_STATE(14)] = 409,
  [SMALL_STATE(15)] = 442,
  [SMALL_STATE(16)] = 475,
  [SMALL_STATE(17)] = 493,
  [SMALL_STATE(18)] = 511,
  [SMALL_STATE(19)] = 537,
  [SMALL_STATE(20)] = 555,
  [SMALL_STATE(21)] = 571,
  [SMALL_STATE(22)] = 587,
  [SMALL_STATE(23)] = 603,
  [SMALL_STATE(24)] = 619,
  [SMALL_STATE(25)] = 635,
  [SMALL_STATE(26)] = 651,
  [SMALL_STATE(27)] = 669,
  [SMALL_STATE(28)] = 685,
  [SMALL_STATE(29)] = 711,
  [SMALL_STATE(30)] = 729,
  [SMALL_STATE(31)] = 746,
  [SMALL_STATE(32)] = 763,
  [SMALL_STATE(33)] = 778,
  [SMALL_STATE(34)] = 793,
  [SMALL_STATE(35)] = 810,
  [SMALL_STATE(36)] = 827,
  [SMALL_STATE(37)] = 844,
  [SMALL_STATE(38)] = 861,
  [SMALL_STATE(39)] = 878,
  [SMALL_STATE(40)] = 895,
  [SMALL_STATE(41)] = 912,
  [SMALL_STATE(42)] = 929,
  [SMALL_STATE(43)] = 944,
  [SMALL_STATE(44)] = 961,
  [SMALL_STATE(45)] = 978,
  [SMALL_STATE(46)] = 995,
  [SMALL_STATE(47)] = 1012,
  [SMALL_STATE(48)] = 1028,
  [SMALL_STATE(49)] = 1044,
  [SMALL_STATE(50)] = 1068,
  [SMALL_STATE(51)] = 1084,
  [SMALL_STATE(52)] = 1108,
  [SMALL_STATE(53)] = 1132,
  [SMALL_STATE(54)] = 1152,
  [SMALL_STATE(55)] = 1172,
  [SMALL_STATE(56)] = 1192,
  [SMALL_STATE(57)] = 1216,
  [SMALL_STATE(58)] = 1236,
  [SMALL_STATE(59)] = 1257,
  [SMALL_STATE(60)] = 1278,
  [SMALL_STATE(61)] = 1293,
  [SMALL_STATE(62)] = 1314,
  [SMALL_STATE(63)] = 1332,
  [SMALL_STATE(64)] = 1352,
  [SMALL_STATE(65)] = 1372,
  [SMALL_STATE(66)] = 1392,
  [SMALL_STATE(67)] = 1408,
  [SMALL_STATE(68)] = 1426,
  [SMALL_STATE(69)] = 1440,
  [SMALL_STATE(70)] = 1455,
  [SMALL_STATE(71)] = 1468,
  [SMALL_STATE(72)] = 1481,
  [SMALL_STATE(73)] = 1494,
  [SMALL_STATE(74)] = 1505,
  [SMALL_STATE(75)] = 1518,
  [SMALL_STATE(76)] = 1533,
  [SMALL_STATE(77)] = 1548,
  [SMALL_STATE(78)] = 1563,
  [SMALL_STATE(79)] = 1576,
  [SMALL_STATE(80)] = 1589,
  [SMALL_STATE(81)] = 1602,
  [SMALL_STATE(82)] = 1613,
  [SMALL_STATE(83)] = 1628,
  [SMALL_STATE(84)] = 1639,
  [SMALL_STATE(85)] = 1650,
  [SMALL_STATE(86)] = 1663,
  [SMALL_STATE(87)] = 1678,
  [SMALL_STATE(88)] = 1689,
  [SMALL_STATE(89)] = 1702,
  [SMALL_STATE(90)] = 1714,
  [SMALL_STATE(91)] = 1724,
  [SMALL_STATE(92)] = 1736,
  [SMALL_STATE(93)] = 1750,
  [SMALL_STATE(94)] = 1762,
  [SMALL_STATE(95)] = 1772,
  [SMALL_STATE(96)] = 1784,
  [SMALL_STATE(97)] = 1794,
  [SMALL_STATE(98)] = 1804,
  [SMALL_STATE(99)] = 1818,
  [SMALL_STATE(100)] = 1830,
  [SMALL_STATE(101)] = 1844,
  [SMALL_STATE(102)] = 1856,
  [SMALL_STATE(103)] = 1868,
  [SMALL_STATE(104)] = 1878,
  [SMALL_STATE(105)] = 1892,
  [SMALL_STATE(106)] = 1906,
  [SMALL_STATE(107)] = 1920,
  [SMALL_STATE(108)] = 1932,
  [SMALL_STATE(109)] = 1942,
  [SMALL_STATE(110)] = 1956,
  [SMALL_STATE(111)] = 1970,
  [SMALL_STATE(112)] = 1982,
  [SMALL_STATE(113)] = 1994,
  [SMALL_STATE(114)] = 2005,
  [SMALL_STATE(115)] = 2016,
  [SMALL_STATE(116)] = 2027,
  [SMALL_STATE(117)] = 2038,
  [SMALL_STATE(118)] = 2049,
  [SMALL_STATE(119)] = 2060,
  [SMALL_STATE(120)] = 2071,
  [SMALL_STATE(121)] = 2080,
  [SMALL_STATE(122)] = 2091,
  [SMALL_STATE(123)] = 2102,
  [SMALL_STATE(124)] = 2111,
  [SMALL_STATE(125)] = 2120,
  [SMALL_STATE(126)] = 2131,
  [SMALL_STATE(127)] = 2140,
  [SMALL_STATE(128)] = 2148,
  [SMALL_STATE(129)] = 2156,
  [SMALL_STATE(130)] = 2164,
  [SMALL_STATE(131)] = 2172,
  [SMALL_STATE(132)] = 2180,
  [SMALL_STATE(133)] = 2188,
  [SMALL_STATE(134)] = 2196,
  [SMALL_STATE(135)] = 2204,
  [SMALL_STATE(136)] = 2212,
  [SMALL_STATE(137)] = 2220,
  [SMALL_STATE(138)] = 2228,
  [SMALL_STATE(139)] = 2236,
  [SMALL_STATE(140)] = 2244,
  [SMALL_STATE(141)] = 2252,
  [SMALL_STATE(142)] = 2260,
  [SMALL_STATE(143)] = 2268,
  [SMALL_STATE(144)] = 2276,
  [SMALL_STATE(145)] = 2284,
  [SMALL_STATE(146)] = 2292,
  [SMALL_STATE(147)] = 2300,
  [SMALL_STATE(148)] = 2308,
  [SMALL_STATE(149)] = 2316,
  [SMALL_STATE(150)] = 2324,
  [SMALL_STATE(151)] = 2332,
  [SMALL_STATE(152)] = 2340,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(147),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(121),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(102),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(88),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(138),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(118),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(137),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(149),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(138),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0),
  [116] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(112),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [122] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(78),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(80),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 21),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 21),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 18),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 19),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 25),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 26),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 24),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 28),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 27),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 29),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 29),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 18),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 19),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 22),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 22),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_block, 2, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_block, 2, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [257] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0),
  [262] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [265] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 6),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 6),
  [272] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [276] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 21),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 21),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [294] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(150),
  [297] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 30),
  [299] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 30), SHIFT_REPEAT(60),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 30),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [306] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 29),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 29),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 16),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 10),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 20),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 20),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [324] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [326] = {.entry = {.count = 1, .reusable = false}}, SHIFT(95),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 23),
  [334] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 23), SHIFT_REPEAT(113),
  [337] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 23), SHIFT_REPEAT(91),
  [340] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 23), SHIFT_REPEAT(79),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [353] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [355] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [358] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 35),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 35),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 16),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0),
  [376] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(128),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 2, 0, 0),
  [391] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 17), SHIFT_REPEAT(90),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 17),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 31),
  [398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 32),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [402] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 10),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 3, 0, 0),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [410] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 9),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 15),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_language_constant, 1, 0, 0),
  [426] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [432] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [441] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 14),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [455] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [457] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(119),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 33),
  [480] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 34),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_action_index, 3, 0, 13),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_action_label, 3, 0, 12),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [494] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 3, 0, 0),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [502] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [508] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [512] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_show_dialog, 4, 0, 14),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [516] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [518] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 7),
  [522] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [524] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [526] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [528] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 11),
  [532] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
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
