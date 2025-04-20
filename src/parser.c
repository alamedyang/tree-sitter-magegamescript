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
#define STATE_COUNT 139
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 91
#define ALIAS_COUNT 2
#define TOKEN_COUNT 44
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 20
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 31

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
  sym_return_statement = 35,
  anon_sym_json = 36,
  anon_sym_LBRACK = 37,
  anon_sym_COMMA = 38,
  anon_sym_RBRACK = 39,
  sym_json_number = 40,
  anon_sym_true = 41,
  anon_sym_false = 42,
  anon_sym_null = 43,
  sym_source_file = 44,
  sym__bareword = 45,
  sym__STRING = 46,
  sym__string = 47,
  sym__number = 48,
  sym__NUMBERISH = 49,
  sym__enum_alignment = 50,
  sym__root = 51,
  sym_include_macro = 52,
  sym_constant_assignment = 53,
  sym_add_serial_dialog_settings = 54,
  sym_serial_dialog_parameter = 55,
  sym_add_dialog_settings = 56,
  sym_dialog_settings_block = 57,
  sym_dialog_parameter = 58,
  sym_dialog_definition = 59,
  sym_dialog_block = 60,
  sym_dialog = 61,
  sym_dialog_identifier = 62,
  sym_dialog_option = 63,
  sym_serial_dialog_definition = 64,
  sym_serial_dialog_block = 65,
  sym_serial_dialog = 66,
  sym_serial_dialog_option = 67,
  sym_script_definition = 68,
  sym_script_literal = 69,
  sym__script_item = 70,
  sym_label = 71,
  sym__action_item = 72,
  sym_json_literal = 73,
  sym_json_array = 74,
  sym__json_item = 75,
  sym_json_language_constant = 76,
  sym_json_object = 77,
  sym_json_name_value_pair = 78,
  aux_sym_source_file_repeat1 = 79,
  aux_sym_add_serial_dialog_settings_repeat1 = 80,
  aux_sym_add_dialog_settings_repeat1 = 81,
  aux_sym_dialog_settings_block_repeat1 = 82,
  aux_sym_dialog_block_repeat1 = 83,
  aux_sym_dialog_repeat1 = 84,
  aux_sym_dialog_repeat2 = 85,
  aux_sym_serial_dialog_repeat1 = 86,
  aux_sym_serial_dialog_repeat2 = 87,
  aux_sym_script_literal_repeat1 = 88,
  aux_sym_json_array_repeat1 = 89,
  aux_sym_json_object_repeat1 = 90,
  alias_sym_entity_settings = 91,
  alias_sym_label_settings = 92,
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
  [sym_return_statement] = "return_statement",
  [anon_sym_json] = "json",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_json_number] = "json_number",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_null] = "null",
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
  [sym_script_literal] = "script_literal",
  [sym__script_item] = "_script_item",
  [sym_label] = "label",
  [sym__action_item] = "_action_item",
  [sym_json_literal] = "json_literal",
  [sym_json_array] = "json_array",
  [sym__json_item] = "_json_item",
  [sym_json_language_constant] = "json_language_constant",
  [sym_json_object] = "json_object",
  [sym_json_name_value_pair] = "json_name_value_pair",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_add_serial_dialog_settings_repeat1] = "add_serial_dialog_settings_repeat1",
  [aux_sym_add_dialog_settings_repeat1] = "add_dialog_settings_repeat1",
  [aux_sym_dialog_settings_block_repeat1] = "dialog_settings_block_repeat1",
  [aux_sym_dialog_block_repeat1] = "dialog_block_repeat1",
  [aux_sym_dialog_repeat1] = "dialog_repeat1",
  [aux_sym_dialog_repeat2] = "dialog_repeat2",
  [aux_sym_serial_dialog_repeat1] = "serial_dialog_repeat1",
  [aux_sym_serial_dialog_repeat2] = "serial_dialog_repeat2",
  [aux_sym_script_literal_repeat1] = "script_literal_repeat1",
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
  [sym_return_statement] = sym_return_statement,
  [anon_sym_json] = anon_sym_json,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_json_number] = sym_json_number,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_null] = anon_sym_null,
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
  [sym_script_literal] = sym_script_literal,
  [sym__script_item] = sym__script_item,
  [sym_label] = sym_label,
  [sym__action_item] = sym__action_item,
  [sym_json_literal] = sym_json_literal,
  [sym_json_array] = sym_json_array,
  [sym__json_item] = sym__json_item,
  [sym_json_language_constant] = sym_json_language_constant,
  [sym_json_object] = sym_json_object,
  [sym_json_name_value_pair] = sym_json_name_value_pair,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_add_serial_dialog_settings_repeat1] = aux_sym_add_serial_dialog_settings_repeat1,
  [aux_sym_add_dialog_settings_repeat1] = aux_sym_add_dialog_settings_repeat1,
  [aux_sym_dialog_settings_block_repeat1] = aux_sym_dialog_settings_block_repeat1,
  [aux_sym_dialog_block_repeat1] = aux_sym_dialog_block_repeat1,
  [aux_sym_dialog_repeat1] = aux_sym_dialog_repeat1,
  [aux_sym_dialog_repeat2] = aux_sym_dialog_repeat2,
  [aux_sym_serial_dialog_repeat1] = aux_sym_serial_dialog_repeat1,
  [aux_sym_serial_dialog_repeat2] = aux_sym_serial_dialog_repeat2,
  [aux_sym_script_literal_repeat1] = aux_sym_script_literal_repeat1,
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
  [sym_return_statement] = {
    .visible = true,
    .named = true,
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
  [sym_script_literal] = {
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
  [sym__action_item] = {
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
  [aux_sym_script_literal_repeat1] = {
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
  field_label = 7,
  field_message = 8,
  field_name = 9,
  field_option_type = 10,
  field_portrait = 11,
  field_property = 12,
  field_script = 13,
  field_script_name = 14,
  field_serial_dialog_name = 15,
  field_serial_message = 16,
  field_target_entity = 17,
  field_target_label = 18,
  field_value = 19,
  field_wrap = 20,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alignment] = "alignment",
  [field_border_tileset] = "border_tileset",
  [field_dialog_name] = "dialog_name",
  [field_emote] = "emote",
  [field_entity] = "entity",
  [field_fileName] = "fileName",
  [field_label] = "label",
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
  [7] = {.index = 6, .length = 2},
  [8] = {.index = 8, .length = 1},
  [9] = {.index = 9, .length = 1},
  [10] = {.index = 10, .length = 2},
  [11] = {.index = 12, .length = 1},
  [12] = {.index = 13, .length = 2},
  [13] = {.index = 15, .length = 1},
  [14] = {.index = 16, .length = 1},
  [15] = {.index = 17, .length = 1},
  [16] = {.index = 18, .length = 1},
  [17] = {.index = 19, .length = 2},
  [18] = {.index = 21, .length = 4},
  [19] = {.index = 25, .length = 1},
  [20] = {.index = 26, .length = 1},
  [21] = {.index = 27, .length = 1},
  [22] = {.index = 28, .length = 1},
  [23] = {.index = 29, .length = 1},
  [24] = {.index = 30, .length = 1},
  [25] = {.index = 31, .length = 2},
  [26] = {.index = 33, .length = 1},
  [27] = {.index = 34, .length = 1},
  [28] = {.index = 35, .length = 2},
  [29] = {.index = 37, .length = 3},
  [30] = {.index = 40, .length = 2},
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
    {field_label, 0},
    {field_value, 2},
  [8] =
    {field_serial_message, 0},
  [9] =
    {field_serial_message, 0, .inherited = true},
  [10] =
    {field_property, 0},
    {field_value, 1},
  [12] =
    {field_serial_message, 1, .inherited = true},
  [13] =
    {field_serial_message, 0, .inherited = true},
    {field_serial_message, 1, .inherited = true},
  [15] =
    {field_entity, 1},
  [16] =
    {field_name, 1},
  [17] =
    {field_message, 0},
  [18] =
    {field_message, 1, .inherited = true},
  [19] =
    {field_target_entity, 4, .inherited = true},
    {field_target_label, 4, .inherited = true},
  [21] =
    {field_target_entity, 0, .inherited = true},
    {field_target_entity, 1, .inherited = true},
    {field_target_label, 0, .inherited = true},
    {field_target_label, 1, .inherited = true},
  [25] =
    {field_wrap, 1},
  [26] =
    {field_portrait, 1},
  [27] =
    {field_alignment, 1},
  [28] =
    {field_border_tileset, 1},
  [29] =
    {field_emote, 1},
  [30] =
    {field_message, 2, .inherited = true},
  [31] =
    {field_message, 0, .inherited = true},
    {field_message, 1, .inherited = true},
  [33] =
    {field_target_label, 1},
  [34] =
    {field_target_entity, 1},
  [35] =
    {field_property, 0},
    {field_value, 2},
  [37] =
    {field_label, 1},
    {field_option_type, 0},
    {field_script, 3},
  [40] =
    {field_label, 1},
    {field_script, 3},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [26] = {
    [2] = alias_sym_label_settings,
  },
  [27] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(181);
      ADVANCE_MAP(
        '"', 5,
        '#', 310,
        '$', 178,
        ',', 319,
        '-', 14,
        '/', 6,
        ':', 313,
        ';', 286,
        '=', 287,
        '>', 308,
        'B', 18,
        'I', 115,
        'T', 19,
        '[', 318,
        ']', 320,
        '_', 309,
        'a', 46,
        'b', 100,
        'c', 101,
        'd', 61,
        'e', 112,
        'f', 28,
        'g', 139,
        'i', 116,
        'j', 147,
        'l', 29,
        'm', 30,
        'n', 31,
        'o', 74,
        'p', 128,
        'r', 53,
        's', 43,
        't', 83,
        'w', 82,
        'y', 71,
        '{', 293,
        '}', 294,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(270);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(183);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 5,
        '#', 174,
        '$', 178,
        '/', 6,
        'b', 230,
        'c', 231,
        'f', 192,
        'g', 251,
        'm', 191,
        'o', 213,
        'r', 208,
        't', 218,
        'w', 217,
        'y', 210,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '"', 5,
        '-', 14,
        '/', 6,
        'I', 115,
        '[', 318,
        ']', 320,
        'f', 28,
        'n', 165,
        't', 135,
        '{', 293,
        '}', 294,
        '#', 309,
        '_', 309,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(322);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(5);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == '>') ADVANCE(308);
      if (lookahead == 'e') ADVANCE(242);
      if (lookahead == 'n') ADVANCE(187);
      if (lookahead == '}') ADVANCE(294);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(269);
      if (lookahead == '\\') ADVANCE(179);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(8);
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 7:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 9:
      if (lookahead == ',') ADVANCE(319);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == ']') ADVANCE(320);
      if (lookahead == 'j') ADVANCE(255);
      if (lookahead == 'r') ADVANCE(211);
      if (lookahead == '}') ADVANCE(294);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 10:
      if (lookahead == 'E') ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == 'F') ADVANCE(22);
      END_STATE();
    case 12:
      if (lookahead == 'G') ADVANCE(13);
      END_STATE();
    case 13:
      if (lookahead == 'H') ADVANCE(22);
      END_STATE();
    case 14:
      if (lookahead == 'I') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(322);
      END_STATE();
    case 15:
      if (lookahead == 'I') ADVANCE(12);
      END_STATE();
    case 16:
      if (lookahead == 'L') ADVANCE(10);
      if (lookahead == 'R') ADVANCE(15);
      END_STATE();
    case 17:
      if (lookahead == 'M') ADVANCE(25);
      END_STATE();
    case 18:
      if (lookahead == 'O') ADVANCE(24);
      if (lookahead == 'L' ||
          lookahead == 'R') ADVANCE(283);
      END_STATE();
    case 19:
      if (lookahead == 'O') ADVANCE(21);
      if (lookahead == 'L' ||
          lookahead == 'R') ADVANCE(283);
      END_STATE();
    case 20:
      if (lookahead == 'O') ADVANCE(17);
      END_STATE();
    case 21:
      if (lookahead == 'P') ADVANCE(25);
      END_STATE();
    case 22:
      if (lookahead == 'T') ADVANCE(283);
      END_STATE();
    case 23:
      if (lookahead == 'T') ADVANCE(20);
      END_STATE();
    case 24:
      if (lookahead == 'T') ADVANCE(23);
      END_STATE();
    case 25:
      if (lookahead == '_') ADVANCE(16);
      END_STATE();
    case 26:
      if (lookahead == '_') ADVANCE(52);
      END_STATE();
    case 27:
      if (lookahead == '_') ADVANCE(162);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(110);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(41);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(81);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'u') ADVANCE(105);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(276);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(133);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(42);
      if (lookahead == 'u') ADVANCE(55);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(118);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(167);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(102);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(107);
      END_STATE();
    case 41:
      if (lookahead == 'b') ADVANCE(66);
      END_STATE();
    case 42:
      if (lookahead == 'c') ADVANCE(97);
      END_STATE();
    case 43:
      if (lookahead == 'c') ADVANCE(141);
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 44:
      if (lookahead == 'c') ADVANCE(103);
      END_STATE();
    case 45:
      if (lookahead == 'c') ADVANCE(54);
      END_STATE();
    case 46:
      if (lookahead == 'd') ADVANCE(47);
      if (lookahead == 'l') ADVANCE(85);
      END_STATE();
    case 47:
      if (lookahead == 'd') ADVANCE(288);
      END_STATE();
    case 48:
      if (lookahead == 'd') ADVANCE(280);
      END_STATE();
    case 49:
      if (lookahead == 'd') ADVANCE(276);
      if (lookahead == 't') ADVANCE(166);
      END_STATE();
    case 50:
      if (lookahead == 'd') ADVANCE(68);
      END_STATE();
    case 51:
      if (lookahead == 'd') ADVANCE(60);
      END_STATE();
    case 52:
      if (lookahead == 'd') ADVANCE(96);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(275);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(276);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(302);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(324);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(307);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(325);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(284);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(76);
      if (lookahead == 'i') ADVANCE(36);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(118);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(117);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(122);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(138);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(124);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(156);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(111);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(150);
      END_STATE();
    case 73:
      if (lookahead == 'f') ADVANCE(280);
      END_STATE();
    case 74:
      if (lookahead == 'f') ADVANCE(73);
      if (lookahead == 'n') ADVANCE(281);
      if (lookahead == 'p') ADVANCE(64);
      END_STATE();
    case 75:
      if (lookahead == 'f') ADVANCE(89);
      END_STATE();
    case 76:
      if (lookahead == 'f') ADVANCE(37);
      END_STATE();
    case 77:
      if (lookahead == 'g') ADVANCE(296);
      END_STATE();
    case 78:
      if (lookahead == 'g') ADVANCE(290);
      END_STATE();
    case 79:
      if (lookahead == 'g') ADVANCE(146);
      END_STATE();
    case 80:
      if (lookahead == 'g') ADVANCE(125);
      END_STATE();
    case 81:
      if (lookahead == 'g') ADVANCE(67);
      END_STATE();
    case 82:
      if (lookahead == 'h') ADVANCE(94);
      if (lookahead == 'r') ADVANCE(33);
      END_STATE();
    case 83:
      if (lookahead == 'h') ADVANCE(137);
      if (lookahead == 'r') ADVANCE(168);
      if (lookahead == 'w') ADVANCE(87);
      END_STATE();
    case 84:
      if (lookahead == 'i') ADVANCE(171);
      if (lookahead == 'x') ADVANCE(274);
      END_STATE();
    case 85:
      if (lookahead == 'i') ADVANCE(80);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(134);
      END_STATE();
    case 87:
      if (lookahead == 'i') ADVANCE(45);
      END_STATE();
    case 88:
      if (lookahead == 'i') ADVANCE(151);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(123);
      END_STATE();
    case 90:
      if (lookahead == 'i') ADVANCE(157);
      END_STATE();
    case 91:
      if (lookahead == 'i') ADVANCE(154);
      END_STATE();
    case 92:
      if (lookahead == 'i') ADVANCE(109);
      END_STATE();
    case 93:
      if (lookahead == 'i') ADVANCE(121);
      END_STATE();
    case 94:
      if (lookahead == 'i') ADVANCE(158);
      END_STATE();
    case 95:
      if (lookahead == 'i') ADVANCE(38);
      END_STATE();
    case 96:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 97:
      if (lookahead == 'k') ADVANCE(276);
      END_STATE();
    case 98:
      if (lookahead == 'l') ADVANCE(326);
      END_STATE();
    case 99:
      if (lookahead == 'l') ADVANCE(299);
      END_STATE();
    case 100:
      if (lookahead == 'l') ADVANCE(34);
      if (lookahead == 'o') ADVANCE(136);
      END_STATE();
    case 101:
      if (lookahead == 'l') ADVANCE(129);
      if (lookahead == 'y') ADVANCE(35);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 103:
      if (lookahead == 'l') ADVANCE(169);
      END_STATE();
    case 104:
      if (lookahead == 'l') ADVANCE(130);
      END_STATE();
    case 105:
      if (lookahead == 'l') ADVANCE(98);
      END_STATE();
    case 106:
      if (lookahead == 'l') ADVANCE(126);
      END_STATE();
    case 107:
      if (lookahead == 'l') ADVANCE(132);
      END_STATE();
    case 108:
      if (lookahead == 'l') ADVANCE(153);
      END_STATE();
    case 109:
      if (lookahead == 'l') ADVANCE(72);
      END_STATE();
    case 110:
      if (lookahead == 'l') ADVANCE(149);
      END_STATE();
    case 111:
      if (lookahead == 'l') ADVANCE(106);
      END_STATE();
    case 112:
      if (lookahead == 'm') ADVANCE(127);
      if (lookahead == 'n') ADVANCE(159);
      END_STATE();
    case 113:
      if (lookahead == 'm') ADVANCE(56);
      END_STATE();
    case 114:
      if (lookahead == 'm') ADVANCE(69);
      END_STATE();
    case 115:
      if (lookahead == 'n') ADVANCE(75);
      END_STATE();
    case 116:
      if (lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 117:
      if (lookahead == 'n') ADVANCE(280);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(276);
      END_STATE();
    case 119:
      if (lookahead == 'n') ADVANCE(316);
      END_STATE();
    case 120:
      if (lookahead == 'n') ADVANCE(314);
      END_STATE();
    case 121:
      if (lookahead == 'n') ADVANCE(79);
      END_STATE();
    case 122:
      if (lookahead == 'n') ADVANCE(161);
      END_STATE();
    case 123:
      if (lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 124:
      if (lookahead == 'n') ADVANCE(155);
      END_STATE();
    case 125:
      if (lookahead == 'n') ADVANCE(114);
      END_STATE();
    case 126:
      if (lookahead == 'o') ADVANCE(170);
      END_STATE();
    case 127:
      if (lookahead == 'o') ADVANCE(163);
      END_STATE();
    case 128:
      if (lookahead == 'o') ADVANCE(140);
      END_STATE();
    case 129:
      if (lookahead == 'o') ADVANCE(148);
      END_STATE();
    case 130:
      if (lookahead == 'o') ADVANCE(77);
      END_STATE();
    case 131:
      if (lookahead == 'o') ADVANCE(119);
      END_STATE();
    case 132:
      if (lookahead == 'o') ADVANCE(78);
      END_STATE();
    case 133:
      if (lookahead == 'p') ADVANCE(295);
      END_STATE();
    case 134:
      if (lookahead == 'p') ADVANCE(152);
      END_STATE();
    case 135:
      if (lookahead == 'r') ADVANCE(168);
      END_STATE();
    case 136:
      if (lookahead == 'r') ADVANCE(50);
      END_STATE();
    case 137:
      if (lookahead == 'r') ADVANCE(87);
      END_STATE();
    case 138:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 139:
      if (lookahead == 'r') ADVANCE(65);
      END_STATE();
    case 140:
      if (lookahead == 'r') ADVANCE(160);
      END_STATE();
    case 141:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 142:
      if (lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 143:
      if (lookahead == 'r') ADVANCE(95);
      if (lookahead == 't') ADVANCE(164);
      END_STATE();
    case 144:
      if (lookahead == 'r') ADVANCE(120);
      END_STATE();
    case 145:
      if (lookahead == 's') ADVANCE(273);
      END_STATE();
    case 146:
      if (lookahead == 's') ADVANCE(292);
      END_STATE();
    case 147:
      if (lookahead == 's') ADVANCE(131);
      END_STATE();
    case 148:
      if (lookahead == 's') ADVANCE(63);
      END_STATE();
    case 149:
      if (lookahead == 's') ADVANCE(59);
      END_STATE();
    case 150:
      if (lookahead == 's') ADVANCE(70);
      END_STATE();
    case 151:
      if (lookahead == 't') ADVANCE(172);
      END_STATE();
    case 152:
      if (lookahead == 't') ADVANCE(311);
      END_STATE();
    case 153:
      if (lookahead == 't') ADVANCE(298);
      END_STATE();
    case 154:
      if (lookahead == 't') ADVANCE(304);
      END_STATE();
    case 155:
      if (lookahead == 't') ADVANCE(305);
      END_STATE();
    case 156:
      if (lookahead == 't') ADVANCE(306);
      END_STATE();
    case 157:
      if (lookahead == 't') ADVANCE(173);
      END_STATE();
    case 158:
      if (lookahead == 't') ADVANCE(55);
      END_STATE();
    case 159:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 160:
      if (lookahead == 't') ADVANCE(142);
      END_STATE();
    case 161:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 162:
      if (lookahead == 't') ADVANCE(92);
      END_STATE();
    case 163:
      if (lookahead == 't') ADVANCE(58);
      END_STATE();
    case 164:
      if (lookahead == 't') ADVANCE(93);
      END_STATE();
    case 165:
      if (lookahead == 'u') ADVANCE(105);
      END_STATE();
    case 166:
      if (lookahead == 'u') ADVANCE(144);
      END_STATE();
    case 167:
      if (lookahead == 'u') ADVANCE(108);
      END_STATE();
    case 168:
      if (lookahead == 'u') ADVANCE(57);
      END_STATE();
    case 169:
      if (lookahead == 'u') ADVANCE(51);
      END_STATE();
    case 170:
      if (lookahead == 'w') ADVANCE(276);
      END_STATE();
    case 171:
      if (lookahead == 'x') ADVANCE(274);
      END_STATE();
    case 172:
      if (lookahead == 'y') ADVANCE(300);
      END_STATE();
    case 173:
      if (lookahead == 'y') ADVANCE(321);
      END_STATE();
    case 174:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(177);
      END_STATE();
    case 175:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(323);
      END_STATE();
    case 176:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(279);
      END_STATE();
    case 177:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(176);
      END_STATE();
    case 178:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 179:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(5);
      END_STATE();
    case 180:
      if (eof) ADVANCE(181);
      if (lookahead == '$') ADVANCE(178);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == 'a') ADVANCE(201);
      if (lookahead == 'd') ADVANCE(219);
      if (lookahead == 'i') ADVANCE(238);
      if (lookahead == 's') ADVANCE(194);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(180);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(272);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_line_comment);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(195);
      if (lookahead == 'u') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(249);
      if (lookahead == 'e') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(303);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(212);
      if (lookahead == 'n') ADVANCE(197);
      if (lookahead == 'p') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(291);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(250);
      if (lookahead == 'r') ADVANCE(265);
      if (lookahead == 'w') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(258);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(263);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(244);
      if (lookahead == 'y') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(266);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(264);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == '.') ADVANCE(175);
      if (lookahead == 'm') ADVANCE(145);
      if (lookahead == 'p') ADVANCE(84);
      if (lookahead == 's') ADVANCE(273);
      if (lookahead == 'x') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(270);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == 'm') ADVANCE(145);
      if (lookahead == 'p') ADVANCE(84);
      if (lookahead == 's') ADVANCE(273);
      if (lookahead == 'x') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(271);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(272);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_DURATION);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_DISTANCE);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_QUANTITY);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(276);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(277);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(278);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_BOOLEAN);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_BOOLEAN);
      if (lookahead == 'c') ADVANCE(54);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(282);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_ENUM_ALIGNMENT);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(177);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_return_statement);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(anon_sym_json);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(268);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_json_number);
      if (lookahead == '.') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(322);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(323);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 180},
  [2] = {.lex_state = 180},
  [3] = {.lex_state = 180},
  [4] = {.lex_state = 3},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 3},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 9},
  [16] = {.lex_state = 4},
  [17] = {.lex_state = 9},
  [18] = {.lex_state = 9},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 180},
  [26] = {.lex_state = 180},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 180},
  [29] = {.lex_state = 180},
  [30] = {.lex_state = 180},
  [31] = {.lex_state = 180},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 180},
  [34] = {.lex_state = 180},
  [35] = {.lex_state = 180},
  [36] = {.lex_state = 180},
  [37] = {.lex_state = 180},
  [38] = {.lex_state = 180},
  [39] = {.lex_state = 180},
  [40] = {.lex_state = 180},
  [41] = {.lex_state = 180},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 180},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 4},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 4},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 9},
  [53] = {.lex_state = 9},
  [54] = {.lex_state = 4},
  [55] = {.lex_state = 3},
  [56] = {.lex_state = 3},
  [57] = {.lex_state = 9},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 4},
  [64] = {.lex_state = 9},
  [65] = {.lex_state = 3},
  [66] = {.lex_state = 3},
  [67] = {.lex_state = 9},
  [68] = {.lex_state = 9},
  [69] = {.lex_state = 3},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 2},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 3},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 2},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 3},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 180},
  [101] = {.lex_state = 180},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 2},
  [104] = {.lex_state = 180},
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
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 3},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 2},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
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
  [138] = {.lex_state = 0},
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
    [sym_return_statement] = ACTIONS(1),
    [anon_sym_json] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_json_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(123),
    [sym__root] = STATE(3),
    [sym_include_macro] = STATE(3),
    [sym_constant_assignment] = STATE(3),
    [sym_add_serial_dialog_settings] = STATE(3),
    [sym_add_dialog_settings] = STATE(3),
    [sym_dialog_definition] = STATE(3),
    [sym_serial_dialog_definition] = STATE(3),
    [sym_script_definition] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
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
    ACTIONS(44), 1,
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
  [80] = 7,
    ACTIONS(48), 1,
      anon_sym_LBRACE,
    ACTIONS(50), 1,
      anon_sym_LBRACK,
    ACTIONS(52), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(46), 2,
      sym_QUOTED_STRING,
      sym_json_number,
    ACTIONS(54), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(93), 4,
      sym_json_array,
      sym__json_item,
      sym_json_language_constant,
      sym_json_object,
  [109] = 11,
    ACTIONS(56), 1,
      sym_QUOTED_STRING,
    ACTIONS(58), 1,
      anon_sym_wrap,
    ACTIONS(60), 1,
      anon_sym_entity,
    ACTIONS(62), 1,
      anon_sym_name,
    ACTIONS(64), 1,
      anon_sym_portrait,
    ACTIONS(66), 1,
      anon_sym_alignment,
    ACTIONS(68), 1,
      anon_sym_border_tileset,
    ACTIONS(70), 1,
      anon_sym_emote,
    STATE(16), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(10), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [145] = 4,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(127), 2,
      sym__STRING,
      sym__NUMBERISH,
    ACTIONS(72), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(74), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [167] = 10,
    ACTIONS(78), 1,
      anon_sym_wrap,
    ACTIONS(81), 1,
      anon_sym_entity,
    ACTIONS(84), 1,
      anon_sym_name,
    ACTIONS(87), 1,
      anon_sym_portrait,
    ACTIONS(90), 1,
      anon_sym_alignment,
    ACTIONS(93), 1,
      anon_sym_border_tileset,
    ACTIONS(96), 1,
      anon_sym_emote,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(76), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(7), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [201] = 6,
    ACTIONS(48), 1,
      anon_sym_LBRACE,
    ACTIONS(50), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(99), 2,
      sym_QUOTED_STRING,
      sym_json_number,
    ACTIONS(54), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(109), 4,
      sym_json_array,
      sym__json_item,
      sym_json_language_constant,
      sym_json_object,
  [227] = 6,
    ACTIONS(48), 1,
      anon_sym_LBRACE,
    ACTIONS(50), 1,
      anon_sym_LBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(101), 2,
      sym_QUOTED_STRING,
      sym_json_number,
    ACTIONS(54), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(116), 4,
      sym_json_array,
      sym__json_item,
      sym_json_language_constant,
      sym_json_object,
  [253] = 11,
    ACTIONS(56), 1,
      sym_QUOTED_STRING,
    ACTIONS(58), 1,
      anon_sym_wrap,
    ACTIONS(60), 1,
      anon_sym_entity,
    ACTIONS(62), 1,
      anon_sym_name,
    ACTIONS(64), 1,
      anon_sym_portrait,
    ACTIONS(66), 1,
      anon_sym_alignment,
    ACTIONS(68), 1,
      anon_sym_border_tileset,
    ACTIONS(70), 1,
      anon_sym_emote,
    STATE(14), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(7), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [289] = 10,
    ACTIONS(58), 1,
      anon_sym_wrap,
    ACTIONS(60), 1,
      anon_sym_entity,
    ACTIONS(62), 1,
      anon_sym_name,
    ACTIONS(64), 1,
      anon_sym_portrait,
    ACTIONS(66), 1,
      anon_sym_alignment,
    ACTIONS(68), 1,
      anon_sym_border_tileset,
    ACTIONS(70), 1,
      anon_sym_emote,
    ACTIONS(103), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(12), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [322] = 10,
    ACTIONS(58), 1,
      anon_sym_wrap,
    ACTIONS(60), 1,
      anon_sym_entity,
    ACTIONS(62), 1,
      anon_sym_name,
    ACTIONS(64), 1,
      anon_sym_portrait,
    ACTIONS(66), 1,
      anon_sym_alignment,
    ACTIONS(68), 1,
      anon_sym_border_tileset,
    ACTIONS(70), 1,
      anon_sym_emote,
    ACTIONS(105), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(7), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [355] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(107), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [371] = 7,
    ACTIONS(56), 1,
      sym_QUOTED_STRING,
    ACTIONS(111), 1,
      anon_sym_RBRACE,
    ACTIONS(113), 1,
      anon_sym_GT,
    STATE(46), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(50), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(109), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [397] = 7,
    ACTIONS(115), 1,
      sym_BAREWORD,
    ACTIONS(118), 1,
      anon_sym_RBRACE,
    ACTIONS(120), 1,
      sym_return_statement,
    ACTIONS(123), 1,
      anon_sym_json,
    STATE(129), 1,
      sym__action_item,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(15), 4,
      sym__script_item,
      sym_label,
      sym_json_literal,
      aux_sym_script_literal_repeat1,
  [423] = 7,
    ACTIONS(56), 1,
      sym_QUOTED_STRING,
    ACTIONS(113), 1,
      anon_sym_GT,
    ACTIONS(128), 1,
      anon_sym_RBRACE,
    STATE(46), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(48), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(126), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [449] = 7,
    ACTIONS(130), 1,
      sym_BAREWORD,
    ACTIONS(132), 1,
      anon_sym_RBRACE,
    ACTIONS(134), 1,
      sym_return_statement,
    ACTIONS(136), 1,
      anon_sym_json,
    STATE(129), 1,
      sym__action_item,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(18), 4,
      sym__script_item,
      sym_label,
      sym_json_literal,
      aux_sym_script_literal_repeat1,
  [475] = 7,
    ACTIONS(130), 1,
      sym_BAREWORD,
    ACTIONS(134), 1,
      sym_return_statement,
    ACTIONS(136), 1,
      anon_sym_json,
    ACTIONS(138), 1,
      anon_sym_RBRACE,
    STATE(129), 1,
      sym__action_item,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(15), 4,
      sym__script_item,
      sym_label,
      sym_json_literal,
      aux_sym_script_literal_repeat1,
  [501] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(140), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [517] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [533] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(144), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [549] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(146), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [565] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(148), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [581] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(150), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [597] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(152), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(154), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [614] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(158), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [631] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(160), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [646] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(162), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(164), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [663] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(166), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(168), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [680] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(170), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(172), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [697] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(174), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(176), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [714] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(178), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [729] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(180), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(182), 6,
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
    ACTIONS(184), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(186), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [763] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(188), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(190), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [780] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(192), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(194), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [797] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(196), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(198), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [814] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(200), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(202), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [831] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(204), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(206), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [848] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(208), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(210), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [865] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(212), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(214), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [882] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(216), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [897] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(218), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(220), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [914] = 7,
    ACTIONS(222), 1,
      sym_BAREWORD,
    ACTIONS(225), 1,
      anon_sym_RBRACE,
    ACTIONS(227), 1,
      anon_sym_entity,
    ACTIONS(230), 1,
      anon_sym_name,
    STATE(5), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(44), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [938] = 7,
    ACTIONS(233), 1,
      sym_BAREWORD,
    ACTIONS(235), 1,
      anon_sym_RBRACE,
    ACTIONS(237), 1,
      anon_sym_entity,
    ACTIONS(239), 1,
      anon_sym_name,
    STATE(5), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(44), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [962] = 5,
    ACTIONS(243), 1,
      sym_QUOTED_STRING,
    STATE(46), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(246), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(241), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [982] = 7,
    ACTIONS(248), 1,
      sym_QUOTED_STRING,
    ACTIONS(250), 1,
      anon_sym_RBRACE,
    ACTIONS(252), 1,
      anon_sym_wrap,
    STATE(55), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(126), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(61), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1006] = 5,
    ACTIONS(113), 1,
      anon_sym_GT,
    ACTIONS(256), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(51), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(254), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1026] = 7,
    ACTIONS(233), 1,
      sym_BAREWORD,
    ACTIONS(237), 1,
      anon_sym_entity,
    ACTIONS(239), 1,
      anon_sym_name,
    ACTIONS(258), 1,
      anon_sym_RBRACE,
    STATE(5), 1,
      sym_dialog_identifier,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(45), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [1050] = 5,
    ACTIONS(113), 1,
      anon_sym_GT,
    ACTIONS(262), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(51), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(260), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1070] = 5,
    ACTIONS(266), 1,
      anon_sym_RBRACE,
    ACTIONS(268), 1,
      anon_sym_GT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(51), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(264), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1090] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(271), 3,
      sym_BAREWORD,
      sym_return_statement,
      anon_sym_json,
    ACTIONS(273), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1105] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(275), 3,
      sym_BAREWORD,
      sym_return_statement,
      anon_sym_json,
    ACTIONS(277), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1120] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(279), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
    ACTIONS(281), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [1135] = 6,
    ACTIONS(248), 1,
      sym_QUOTED_STRING,
    ACTIONS(283), 1,
      anon_sym_RBRACE,
    ACTIONS(285), 1,
      sym_serial_dialog_option_type,
    STATE(65), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(66), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1156] = 6,
    ACTIONS(248), 1,
      sym_QUOTED_STRING,
    ACTIONS(285), 1,
      sym_serial_dialog_option_type,
    ACTIONS(287), 1,
      anon_sym_RBRACE,
    STATE(65), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(85), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1177] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(289), 3,
      sym_BAREWORD,
      sym_return_statement,
      anon_sym_json,
    ACTIONS(291), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1192] = 6,
    ACTIONS(293), 1,
      anon_sym_RBRACE,
    ACTIONS(295), 1,
      anon_sym_default,
    ACTIONS(298), 1,
      anon_sym_label,
    ACTIONS(301), 1,
      anon_sym_entity,
    STATE(58), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1212] = 6,
    ACTIONS(304), 1,
      anon_sym_RBRACE,
    ACTIONS(306), 1,
      anon_sym_default,
    ACTIONS(308), 1,
      anon_sym_label,
    ACTIONS(310), 1,
      anon_sym_entity,
    STATE(58), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1232] = 4,
    ACTIONS(314), 1,
      anon_sym_wrap,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(312), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(60), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1248] = 5,
    ACTIONS(248), 1,
      sym_QUOTED_STRING,
    ACTIONS(252), 1,
      anon_sym_wrap,
    STATE(56), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(60), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1266] = 6,
    ACTIONS(306), 1,
      anon_sym_default,
    ACTIONS(308), 1,
      anon_sym_label,
    ACTIONS(310), 1,
      anon_sym_entity,
    ACTIONS(317), 1,
      anon_sym_RBRACE,
    STATE(59), 1,
      aux_sym_add_dialog_settings_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1286] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(321), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(319), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [1300] = 3,
    ACTIONS(325), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(323), 3,
      sym_BAREWORD,
      sym_return_statement,
      anon_sym_json,
  [1313] = 4,
    ACTIONS(327), 1,
      sym_QUOTED_STRING,
    STATE(65), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(330), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1328] = 4,
    ACTIONS(285), 1,
      sym_serial_dialog_option_type,
    ACTIONS(332), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(69), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1343] = 3,
    ACTIONS(336), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(334), 3,
      sym_BAREWORD,
      sym_return_statement,
      anon_sym_json,
  [1356] = 3,
    ACTIONS(340), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(338), 3,
      sym_BAREWORD,
      sym_return_statement,
      anon_sym_json,
  [1369] = 4,
    ACTIONS(342), 1,
      anon_sym_RBRACE,
    ACTIONS(344), 1,
      sym_serial_dialog_option_type,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(69), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1384] = 3,
    STATE(20), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(347), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1397] = 3,
    STATE(21), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(349), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1410] = 3,
    STATE(22), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(351), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1423] = 3,
    STATE(24), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(353), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1436] = 4,
    ACTIONS(252), 1,
      anon_sym_wrap,
    ACTIONS(355), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(82), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1451] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(357), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1462] = 3,
    STATE(113), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(359), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1475] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(361), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1486] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(363), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1497] = 3,
    STATE(120), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(365), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1510] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(367), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1521] = 3,
    STATE(112), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(369), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1534] = 4,
    ACTIONS(252), 1,
      anon_sym_wrap,
    ACTIONS(371), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(60), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1549] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(373), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1560] = 3,
    STATE(63), 1,
      sym__string,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(375), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1573] = 4,
    ACTIONS(285), 1,
      sym_serial_dialog_option_type,
    ACTIONS(377), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(69), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1588] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(379), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1598] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(381), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1608] = 4,
    ACTIONS(383), 1,
      anon_sym_RBRACE,
    ACTIONS(385), 1,
      anon_sym_COMMA,
    STATE(97), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1622] = 4,
    ACTIONS(387), 1,
      anon_sym_COMMA,
    ACTIONS(389), 1,
      anon_sym_RBRACK,
    STATE(99), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1636] = 4,
    ACTIONS(391), 1,
      sym_QUOTED_STRING,
    ACTIONS(393), 1,
      anon_sym_RBRACE,
    STATE(88), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1650] = 3,
    STATE(111), 1,
      sym__STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(395), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1662] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(397), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1672] = 4,
    ACTIONS(387), 1,
      anon_sym_COMMA,
    ACTIONS(399), 1,
      anon_sym_RBRACK,
    STATE(89), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1686] = 3,
    STATE(110), 1,
      sym__bareword,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(401), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1698] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(403), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [1708] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(405), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1718] = 4,
    ACTIONS(385), 1,
      anon_sym_COMMA,
    ACTIONS(407), 1,
      anon_sym_RBRACE,
    STATE(105), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1732] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(409), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1742] = 4,
    ACTIONS(411), 1,
      anon_sym_COMMA,
    ACTIONS(414), 1,
      anon_sym_RBRACK,
    STATE(99), 1,
      aux_sym_json_array_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1756] = 3,
    STATE(19), 1,
      sym__number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(416), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1768] = 3,
    STATE(95), 1,
      sym__number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(418), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1780] = 3,
    STATE(23), 1,
      sym__enum_alignment,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(420), 2,
      sym_CONSTANT,
      sym_ENUM_ALIGNMENT,
  [1792] = 3,
    STATE(27), 1,
      sym__STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(422), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1804] = 3,
    STATE(13), 1,
      sym__number,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(424), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1816] = 4,
    ACTIONS(426), 1,
      anon_sym_RBRACE,
    ACTIONS(428), 1,
      anon_sym_COMMA,
    STATE(105), 1,
      aux_sym_json_object_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1830] = 3,
    STATE(42), 1,
      sym__STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(431), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1842] = 3,
    ACTIONS(391), 1,
      sym_QUOTED_STRING,
    STATE(117), 1,
      sym_json_name_value_pair,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1853] = 3,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(80), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1864] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(414), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1873] = 3,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(77), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1884] = 3,
    ACTIONS(435), 1,
      anon_sym_LBRACE,
    STATE(41), 1,
      sym_serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1895] = 3,
    ACTIONS(437), 1,
      anon_sym_LBRACE,
    STATE(43), 1,
      sym_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1906] = 3,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(78), 1,
      sym_dialog_settings_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1917] = 3,
    ACTIONS(439), 1,
      anon_sym_LBRACE,
    STATE(40), 1,
      sym_script_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1928] = 3,
    ACTIONS(439), 1,
      anon_sym_LBRACE,
    STATE(31), 1,
      sym_script_literal,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1939] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(441), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [1948] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(426), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [1957] = 3,
    ACTIONS(50), 1,
      anon_sym_LBRACK,
    STATE(67), 1,
      sym_json_array,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1968] = 3,
    ACTIONS(443), 1,
      anon_sym_serial_dialog,
    ACTIONS(445), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1979] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(447), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1988] = 2,
    ACTIONS(449), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1996] = 2,
    ACTIONS(451), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2004] = 2,
    ACTIONS(453), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2012] = 2,
    ACTIONS(455), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2020] = 2,
    ACTIONS(457), 1,
      sym_BAREWORD,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2028] = 2,
    ACTIONS(459), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2036] = 2,
    ACTIONS(461), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2044] = 2,
    ACTIONS(463), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2052] = 2,
    ACTIONS(465), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2060] = 2,
    ACTIONS(467), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2068] = 2,
    ACTIONS(469), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2076] = 2,
    ACTIONS(471), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2084] = 2,
    ACTIONS(473), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2092] = 2,
    ACTIONS(475), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2100] = 2,
    ACTIONS(477), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2108] = 2,
    ACTIONS(479), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2116] = 2,
    ACTIONS(481), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2124] = 2,
    ACTIONS(483), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 40,
  [SMALL_STATE(4)] = 80,
  [SMALL_STATE(5)] = 109,
  [SMALL_STATE(6)] = 145,
  [SMALL_STATE(7)] = 167,
  [SMALL_STATE(8)] = 201,
  [SMALL_STATE(9)] = 227,
  [SMALL_STATE(10)] = 253,
  [SMALL_STATE(11)] = 289,
  [SMALL_STATE(12)] = 322,
  [SMALL_STATE(13)] = 355,
  [SMALL_STATE(14)] = 371,
  [SMALL_STATE(15)] = 397,
  [SMALL_STATE(16)] = 423,
  [SMALL_STATE(17)] = 449,
  [SMALL_STATE(18)] = 475,
  [SMALL_STATE(19)] = 501,
  [SMALL_STATE(20)] = 517,
  [SMALL_STATE(21)] = 533,
  [SMALL_STATE(22)] = 549,
  [SMALL_STATE(23)] = 565,
  [SMALL_STATE(24)] = 581,
  [SMALL_STATE(25)] = 597,
  [SMALL_STATE(26)] = 614,
  [SMALL_STATE(27)] = 631,
  [SMALL_STATE(28)] = 646,
  [SMALL_STATE(29)] = 663,
  [SMALL_STATE(30)] = 680,
  [SMALL_STATE(31)] = 697,
  [SMALL_STATE(32)] = 714,
  [SMALL_STATE(33)] = 729,
  [SMALL_STATE(34)] = 746,
  [SMALL_STATE(35)] = 763,
  [SMALL_STATE(36)] = 780,
  [SMALL_STATE(37)] = 797,
  [SMALL_STATE(38)] = 814,
  [SMALL_STATE(39)] = 831,
  [SMALL_STATE(40)] = 848,
  [SMALL_STATE(41)] = 865,
  [SMALL_STATE(42)] = 882,
  [SMALL_STATE(43)] = 897,
  [SMALL_STATE(44)] = 914,
  [SMALL_STATE(45)] = 938,
  [SMALL_STATE(46)] = 962,
  [SMALL_STATE(47)] = 982,
  [SMALL_STATE(48)] = 1006,
  [SMALL_STATE(49)] = 1026,
  [SMALL_STATE(50)] = 1050,
  [SMALL_STATE(51)] = 1070,
  [SMALL_STATE(52)] = 1090,
  [SMALL_STATE(53)] = 1105,
  [SMALL_STATE(54)] = 1120,
  [SMALL_STATE(55)] = 1135,
  [SMALL_STATE(56)] = 1156,
  [SMALL_STATE(57)] = 1177,
  [SMALL_STATE(58)] = 1192,
  [SMALL_STATE(59)] = 1212,
  [SMALL_STATE(60)] = 1232,
  [SMALL_STATE(61)] = 1248,
  [SMALL_STATE(62)] = 1266,
  [SMALL_STATE(63)] = 1286,
  [SMALL_STATE(64)] = 1300,
  [SMALL_STATE(65)] = 1313,
  [SMALL_STATE(66)] = 1328,
  [SMALL_STATE(67)] = 1343,
  [SMALL_STATE(68)] = 1356,
  [SMALL_STATE(69)] = 1369,
  [SMALL_STATE(70)] = 1384,
  [SMALL_STATE(71)] = 1397,
  [SMALL_STATE(72)] = 1410,
  [SMALL_STATE(73)] = 1423,
  [SMALL_STATE(74)] = 1436,
  [SMALL_STATE(75)] = 1451,
  [SMALL_STATE(76)] = 1462,
  [SMALL_STATE(77)] = 1475,
  [SMALL_STATE(78)] = 1486,
  [SMALL_STATE(79)] = 1497,
  [SMALL_STATE(80)] = 1510,
  [SMALL_STATE(81)] = 1521,
  [SMALL_STATE(82)] = 1534,
  [SMALL_STATE(83)] = 1549,
  [SMALL_STATE(84)] = 1560,
  [SMALL_STATE(85)] = 1573,
  [SMALL_STATE(86)] = 1588,
  [SMALL_STATE(87)] = 1598,
  [SMALL_STATE(88)] = 1608,
  [SMALL_STATE(89)] = 1622,
  [SMALL_STATE(90)] = 1636,
  [SMALL_STATE(91)] = 1650,
  [SMALL_STATE(92)] = 1662,
  [SMALL_STATE(93)] = 1672,
  [SMALL_STATE(94)] = 1686,
  [SMALL_STATE(95)] = 1698,
  [SMALL_STATE(96)] = 1708,
  [SMALL_STATE(97)] = 1718,
  [SMALL_STATE(98)] = 1732,
  [SMALL_STATE(99)] = 1742,
  [SMALL_STATE(100)] = 1756,
  [SMALL_STATE(101)] = 1768,
  [SMALL_STATE(102)] = 1780,
  [SMALL_STATE(103)] = 1792,
  [SMALL_STATE(104)] = 1804,
  [SMALL_STATE(105)] = 1816,
  [SMALL_STATE(106)] = 1830,
  [SMALL_STATE(107)] = 1842,
  [SMALL_STATE(108)] = 1853,
  [SMALL_STATE(109)] = 1864,
  [SMALL_STATE(110)] = 1873,
  [SMALL_STATE(111)] = 1884,
  [SMALL_STATE(112)] = 1895,
  [SMALL_STATE(113)] = 1906,
  [SMALL_STATE(114)] = 1917,
  [SMALL_STATE(115)] = 1928,
  [SMALL_STATE(116)] = 1939,
  [SMALL_STATE(117)] = 1948,
  [SMALL_STATE(118)] = 1957,
  [SMALL_STATE(119)] = 1968,
  [SMALL_STATE(120)] = 1979,
  [SMALL_STATE(121)] = 1988,
  [SMALL_STATE(122)] = 1996,
  [SMALL_STATE(123)] = 2004,
  [SMALL_STATE(124)] = 2012,
  [SMALL_STATE(125)] = 2020,
  [SMALL_STATE(126)] = 2028,
  [SMALL_STATE(127)] = 2036,
  [SMALL_STATE(128)] = 2044,
  [SMALL_STATE(129)] = 2052,
  [SMALL_STATE(130)] = 2060,
  [SMALL_STATE(131)] = 2068,
  [SMALL_STATE(132)] = 2076,
  [SMALL_STATE(133)] = 2084,
  [SMALL_STATE(134)] = 2092,
  [SMALL_STATE(135)] = 2100,
  [SMALL_STATE(136)] = 2108,
  [SMALL_STATE(137)] = 2116,
  [SMALL_STATE(138)] = 2124,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(133),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(119),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(125),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(100),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(71),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(72),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(102),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(73),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(104),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 23),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 24),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 24),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [115] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(136),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_literal_repeat1, 2, 0, 0),
  [120] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(129),
  [123] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(118),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 16),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 16),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 19),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 13),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 14),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 20),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 21),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 22),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_literal, 3, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_literal, 3, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 14),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_literal, 2, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_literal, 2, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 7),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 7),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 6),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 17),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 17),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 13),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [222] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0),
  [227] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(106),
  [230] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(103),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [239] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [241] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 25),
  [243] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 25), SHIFT_REPEAT(54),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 25),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 16),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 16),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 24),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 24),
  [264] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [268] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(124),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 4, 0, 0),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 3, 0, 0),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 15),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 15),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 9),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 11),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_array, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 18),
  [295] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 18), SHIFT_REPEAT(108),
  [298] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 18), SHIFT_REPEAT(94),
  [301] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 18), SHIFT_REPEAT(76),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [314] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [319] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 30),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 30),
  [323] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 6),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 6),
  [327] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 12), SHIFT_REPEAT(98),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 12),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 9),
  [334] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_json_literal, 2, 0, 0),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0),
  [344] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(138),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [357] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 2, 0, 0),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [361] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 26),
  [363] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 27),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [367] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [373] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 3, 0, 0),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [377] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 11),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [381] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_language_constant, 1, 0, 0),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 10),
  [405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 8),
  [411] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [426] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [428] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [441] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_name_value_pair, 3, 0, 28),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 29),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [453] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [471] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [475] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [477] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [479] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [481] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [483] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
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
