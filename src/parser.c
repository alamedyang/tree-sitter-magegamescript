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
#define STATE_COUNT 136
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 86
#define ALIAS_COUNT 2
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 20
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 31

enum ts_symbol_identifiers {
  sym_BAREWORD = 1,
  sym_QUOTED_STRING = 2,
  sym_NUMBER = 3,
  sym_DURATION = 4,
  sym_DISTANCE = 5,
  sym_QUANTITY = 6,
  sym_COLOR = 7,
  sym_BOOLEAN = 8,
  sym_CONSTANT = 9,
  sym_ENUM_ALIGNMENT = 10,
  anon_sym_include = 11,
  anon_sym_SEMI = 12,
  anon_sym_EQ = 13,
  anon_sym_add = 14,
  anon_sym_serial_dialog = 15,
  anon_sym_settings = 16,
  anon_sym_LBRACE = 17,
  anon_sym_RBRACE = 18,
  anon_sym_wrap = 19,
  anon_sym_dialog = 20,
  anon_sym_default = 21,
  anon_sym_label = 22,
  anon_sym_entity = 23,
  anon_sym_name = 24,
  anon_sym_portrait = 25,
  anon_sym_alignment = 26,
  anon_sym_border_tileset = 27,
  anon_sym_emote = 28,
  anon_sym_GT = 29,
  sym_serial_dialog_option_type = 30,
  anon_sym_script = 31,
  anon_sym_json = 32,
  anon_sym_LBRACK = 33,
  anon_sym_COMMA = 34,
  anon_sym_RBRACK = 35,
  sym_json_number = 36,
  anon_sym_true = 37,
  anon_sym_false = 38,
  anon_sym_null = 39,
  anon_sym_COLON = 40,
  sym_source_file = 41,
  sym__bareword = 42,
  sym__STRING = 43,
  sym__string = 44,
  sym__number = 45,
  sym__NUMBERISH = 46,
  sym__enum_alignment = 47,
  sym__root = 48,
  sym_include_macro = 49,
  sym_constant_assignment = 50,
  sym_add_serial_dialog_settings = 51,
  sym_serial_dialog_parameter = 52,
  sym_add_dialog_settings = 53,
  sym_dialog_settings_block = 54,
  sym_dialog_parameter = 55,
  sym_dialog_definition = 56,
  sym_dialog_block = 57,
  sym_dialog = 58,
  sym_dialog_identifier = 59,
  sym_dialog_option = 60,
  sym_serial_dialog_definition = 61,
  sym_serial_dialog_block = 62,
  sym_serial_dialog = 63,
  sym_serial_dialog_option = 64,
  sym_script_definition = 65,
  sym_script_literal = 66,
  sym_script_item = 67,
  sym_json_literal = 68,
  sym_json_array = 69,
  sym__json_item = 70,
  sym_json_language_constant = 71,
  sym_json_object = 72,
  sym_json_property_value_pair = 73,
  aux_sym_source_file_repeat1 = 74,
  aux_sym_add_serial_dialog_settings_repeat1 = 75,
  aux_sym_add_dialog_settings_repeat1 = 76,
  aux_sym_dialog_settings_block_repeat1 = 77,
  aux_sym_dialog_block_repeat1 = 78,
  aux_sym_dialog_repeat1 = 79,
  aux_sym_dialog_repeat2 = 80,
  aux_sym_serial_dialog_repeat1 = 81,
  aux_sym_serial_dialog_repeat2 = 82,
  aux_sym_script_literal_repeat1 = 83,
  aux_sym_json_array_repeat1 = 84,
  aux_sym_json_object_repeat1 = 85,
  alias_sym_entity_settings = 86,
  alias_sym_label_settings = 87,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [anon_sym_json] = "json",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_json_number] = "json_number",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_null] = "null",
  [anon_sym_COLON] = ":",
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
  [sym_script_item] = "script_item",
  [sym_json_literal] = "json_literal",
  [sym_json_array] = "json_array",
  [sym__json_item] = "_json_item",
  [sym_json_language_constant] = "json_language_constant",
  [sym_json_object] = "json_object",
  [sym_json_property_value_pair] = "json_property_value_pair",
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
  [anon_sym_json] = anon_sym_json,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_json_number] = sym_json_number,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_null] = anon_sym_null,
  [anon_sym_COLON] = anon_sym_COLON,
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
  [sym_script_item] = sym_script_item,
  [sym_json_literal] = sym_json_literal,
  [sym_json_array] = sym_json_array,
  [sym__json_item] = sym__json_item,
  [sym_json_language_constant] = sym_json_language_constant,
  [sym_json_object] = sym_json_object,
  [sym_json_property_value_pair] = sym_json_property_value_pair,
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
  [anon_sym_COLON] = {
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
  [sym_script_item] = {
    .visible = true,
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
  [sym_json_property_value_pair] = {
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
  [6] = {.index = 5, .length = 2},
  [7] = {.index = 7, .length = 1},
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
    {field_value, 2},
  [7] =
    {field_serial_message, 0},
  [8] =
    {field_serial_message, 0, .inherited = true},
  [9] =
    {field_label, 0},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(173);
      ADVANCE_MAP(
        '"', 4,
        '#', 292,
        '$', 170,
        ',', 297,
        '-', 9,
        ':', 305,
        ';', 268,
        '=', 269,
        '>', 290,
        'B', 13,
        'I', 110,
        'T', 14,
        '[', 296,
        ']', 298,
        '_', 291,
        'a', 41,
        'b', 95,
        'c', 96,
        'd', 55,
        'e', 107,
        'f', 23,
        'g', 132,
        'i', 111,
        'j', 140,
        'l', 24,
        'm', 25,
        'n', 26,
        'o', 69,
        'p', 122,
        'r', 56,
        's', 38,
        't', 78,
        'w', 77,
        'y', 66,
        '{', 275,
        '}', 276,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(252);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 4,
        '#', 166,
        '$', 170,
        'b', 219,
        'c', 220,
        'f', 182,
        'g', 237,
        'm', 181,
        'o', 202,
        'r', 198,
        't', 207,
        'w', 206,
        'y', 200,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(253);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 4,
        '-', 9,
        'I', 110,
        '[', 296,
        ']', 298,
        'f', 23,
        'n', 158,
        't', 129,
        '{', 275,
        '}', 276,
        '#', 291,
        '_', 291,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(300);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(4);
      if (lookahead == '>') ADVANCE(290);
      if (lookahead == 'e') ADVANCE(229);
      if (lookahead == 'n') ADVANCE(177);
      if (lookahead == '}') ADVANCE(276);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(251);
      if (lookahead == '\\') ADVANCE(171);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == 'E') ADVANCE(6);
      END_STATE();
    case 6:
      if (lookahead == 'F') ADVANCE(17);
      END_STATE();
    case 7:
      if (lookahead == 'G') ADVANCE(8);
      END_STATE();
    case 8:
      if (lookahead == 'H') ADVANCE(17);
      END_STATE();
    case 9:
      if (lookahead == 'I') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(300);
      END_STATE();
    case 10:
      if (lookahead == 'I') ADVANCE(7);
      END_STATE();
    case 11:
      if (lookahead == 'L') ADVANCE(5);
      if (lookahead == 'R') ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == 'M') ADVANCE(20);
      END_STATE();
    case 13:
      if (lookahead == 'O') ADVANCE(19);
      if (lookahead == 'L' ||
          lookahead == 'R') ADVANCE(265);
      END_STATE();
    case 14:
      if (lookahead == 'O') ADVANCE(16);
      if (lookahead == 'L' ||
          lookahead == 'R') ADVANCE(265);
      END_STATE();
    case 15:
      if (lookahead == 'O') ADVANCE(12);
      END_STATE();
    case 16:
      if (lookahead == 'P') ADVANCE(20);
      END_STATE();
    case 17:
      if (lookahead == 'T') ADVANCE(265);
      END_STATE();
    case 18:
      if (lookahead == 'T') ADVANCE(15);
      END_STATE();
    case 19:
      if (lookahead == 'T') ADVANCE(18);
      END_STATE();
    case 20:
      if (lookahead == '_') ADVANCE(11);
      END_STATE();
    case 21:
      if (lookahead == '_') ADVANCE(47);
      END_STATE();
    case 22:
      if (lookahead == '_') ADVANCE(155);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(99);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(76);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(108);
      if (lookahead == 'u') ADVANCE(101);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(258);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(127);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(37);
      if (lookahead == 'u') ADVANCE(49);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(159);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(113);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(100);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(98);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(87);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(103);
      END_STATE();
    case 36:
      if (lookahead == 'b') ADVANCE(61);
      END_STATE();
    case 37:
      if (lookahead == 'c') ADVANCE(92);
      END_STATE();
    case 38:
      if (lookahead == 'c') ADVANCE(135);
      if (lookahead == 'e') ADVANCE(137);
      END_STATE();
    case 39:
      if (lookahead == 'c') ADVANCE(97);
      END_STATE();
    case 40:
      if (lookahead == 'c') ADVANCE(48);
      END_STATE();
    case 41:
      if (lookahead == 'd') ADVANCE(42);
      if (lookahead == 'l') ADVANCE(80);
      END_STATE();
    case 42:
      if (lookahead == 'd') ADVANCE(270);
      END_STATE();
    case 43:
      if (lookahead == 'd') ADVANCE(262);
      END_STATE();
    case 44:
      if (lookahead == 'd') ADVANCE(258);
      END_STATE();
    case 45:
      if (lookahead == 'd') ADVANCE(62);
      END_STATE();
    case 46:
      if (lookahead == 'd') ADVANCE(54);
      END_STATE();
    case 47:
      if (lookahead == 'd') ADVANCE(91);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(257);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(258);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(284);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(302);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(289);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(303);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(266);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(71);
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 56:
      if (lookahead == 'e') ADVANCE(44);
      END_STATE();
    case 57:
      if (lookahead == 'e') ADVANCE(113);
      END_STATE();
    case 58:
      if (lookahead == 'e') ADVANCE(43);
      END_STATE();
    case 59:
      if (lookahead == 'e') ADVANCE(112);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(94);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(131);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(116);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(118);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(149);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(106);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(142);
      END_STATE();
    case 68:
      if (lookahead == 'f') ADVANCE(262);
      END_STATE();
    case 69:
      if (lookahead == 'f') ADVANCE(68);
      if (lookahead == 'n') ADVANCE(263);
      if (lookahead == 'p') ADVANCE(59);
      END_STATE();
    case 70:
      if (lookahead == 'f') ADVANCE(84);
      END_STATE();
    case 71:
      if (lookahead == 'f') ADVANCE(30);
      END_STATE();
    case 72:
      if (lookahead == 'g') ADVANCE(278);
      END_STATE();
    case 73:
      if (lookahead == 'g') ADVANCE(272);
      END_STATE();
    case 74:
      if (lookahead == 'g') ADVANCE(139);
      END_STATE();
    case 75:
      if (lookahead == 'g') ADVANCE(119);
      END_STATE();
    case 76:
      if (lookahead == 'g') ADVANCE(63);
      END_STATE();
    case 77:
      if (lookahead == 'h') ADVANCE(89);
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 78:
      if (lookahead == 'h') ADVANCE(130);
      if (lookahead == 'r') ADVANCE(160);
      if (lookahead == 'w') ADVANCE(82);
      END_STATE();
    case 79:
      if (lookahead == 'i') ADVANCE(163);
      if (lookahead == 'x') ADVANCE(256);
      END_STATE();
    case 80:
      if (lookahead == 'i') ADVANCE(75);
      END_STATE();
    case 81:
      if (lookahead == 'i') ADVANCE(128);
      END_STATE();
    case 82:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 83:
      if (lookahead == 'i') ADVANCE(144);
      END_STATE();
    case 84:
      if (lookahead == 'i') ADVANCE(117);
      END_STATE();
    case 85:
      if (lookahead == 'i') ADVANCE(150);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(115);
      END_STATE();
    case 87:
      if (lookahead == 'i') ADVANCE(147);
      END_STATE();
    case 88:
      if (lookahead == 'i') ADVANCE(105);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(151);
      END_STATE();
    case 90:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 91:
      if (lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 92:
      if (lookahead == 'k') ADVANCE(258);
      END_STATE();
    case 93:
      if (lookahead == 'l') ADVANCE(304);
      END_STATE();
    case 94:
      if (lookahead == 'l') ADVANCE(281);
      END_STATE();
    case 95:
      if (lookahead == 'l') ADVANCE(29);
      if (lookahead == 'o') ADVANCE(133);
      END_STATE();
    case 96:
      if (lookahead == 'l') ADVANCE(123);
      if (lookahead == 'y') ADVANCE(31);
      END_STATE();
    case 97:
      if (lookahead == 'l') ADVANCE(161);
      END_STATE();
    case 98:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 99:
      if (lookahead == 'l') ADVANCE(141);
      END_STATE();
    case 100:
      if (lookahead == 'l') ADVANCE(124);
      END_STATE();
    case 101:
      if (lookahead == 'l') ADVANCE(93);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(120);
      END_STATE();
    case 103:
      if (lookahead == 'l') ADVANCE(126);
      END_STATE();
    case 104:
      if (lookahead == 'l') ADVANCE(146);
      END_STATE();
    case 105:
      if (lookahead == 'l') ADVANCE(67);
      END_STATE();
    case 106:
      if (lookahead == 'l') ADVANCE(102);
      END_STATE();
    case 107:
      if (lookahead == 'm') ADVANCE(121);
      if (lookahead == 'n') ADVANCE(152);
      END_STATE();
    case 108:
      if (lookahead == 'm') ADVANCE(50);
      END_STATE();
    case 109:
      if (lookahead == 'm') ADVANCE(64);
      END_STATE();
    case 110:
      if (lookahead == 'n') ADVANCE(70);
      END_STATE();
    case 111:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 112:
      if (lookahead == 'n') ADVANCE(262);
      END_STATE();
    case 113:
      if (lookahead == 'n') ADVANCE(258);
      END_STATE();
    case 114:
      if (lookahead == 'n') ADVANCE(295);
      END_STATE();
    case 115:
      if (lookahead == 'n') ADVANCE(74);
      END_STATE();
    case 116:
      if (lookahead == 'n') ADVANCE(154);
      END_STATE();
    case 117:
      if (lookahead == 'n') ADVANCE(85);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(148);
      END_STATE();
    case 119:
      if (lookahead == 'n') ADVANCE(109);
      END_STATE();
    case 120:
      if (lookahead == 'o') ADVANCE(162);
      END_STATE();
    case 121:
      if (lookahead == 'o') ADVANCE(156);
      END_STATE();
    case 122:
      if (lookahead == 'o') ADVANCE(134);
      END_STATE();
    case 123:
      if (lookahead == 'o') ADVANCE(143);
      END_STATE();
    case 124:
      if (lookahead == 'o') ADVANCE(72);
      END_STATE();
    case 125:
      if (lookahead == 'o') ADVANCE(114);
      END_STATE();
    case 126:
      if (lookahead == 'o') ADVANCE(73);
      END_STATE();
    case 127:
      if (lookahead == 'p') ADVANCE(277);
      END_STATE();
    case 128:
      if (lookahead == 'p') ADVANCE(145);
      END_STATE();
    case 129:
      if (lookahead == 'r') ADVANCE(160);
      END_STATE();
    case 130:
      if (lookahead == 'r') ADVANCE(82);
      END_STATE();
    case 131:
      if (lookahead == 'r') ADVANCE(22);
      END_STATE();
    case 132:
      if (lookahead == 'r') ADVANCE(60);
      END_STATE();
    case 133:
      if (lookahead == 'r') ADVANCE(45);
      END_STATE();
    case 134:
      if (lookahead == 'r') ADVANCE(153);
      END_STATE();
    case 135:
      if (lookahead == 'r') ADVANCE(81);
      END_STATE();
    case 136:
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 137:
      if (lookahead == 'r') ADVANCE(90);
      if (lookahead == 't') ADVANCE(157);
      END_STATE();
    case 138:
      if (lookahead == 's') ADVANCE(255);
      END_STATE();
    case 139:
      if (lookahead == 's') ADVANCE(274);
      END_STATE();
    case 140:
      if (lookahead == 's') ADVANCE(125);
      END_STATE();
    case 141:
      if (lookahead == 's') ADVANCE(53);
      END_STATE();
    case 142:
      if (lookahead == 's') ADVANCE(65);
      END_STATE();
    case 143:
      if (lookahead == 's') ADVANCE(58);
      END_STATE();
    case 144:
      if (lookahead == 't') ADVANCE(164);
      END_STATE();
    case 145:
      if (lookahead == 't') ADVANCE(293);
      END_STATE();
    case 146:
      if (lookahead == 't') ADVANCE(280);
      END_STATE();
    case 147:
      if (lookahead == 't') ADVANCE(286);
      END_STATE();
    case 148:
      if (lookahead == 't') ADVANCE(287);
      END_STATE();
    case 149:
      if (lookahead == 't') ADVANCE(288);
      END_STATE();
    case 150:
      if (lookahead == 't') ADVANCE(165);
      END_STATE();
    case 151:
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 152:
      if (lookahead == 't') ADVANCE(83);
      END_STATE();
    case 153:
      if (lookahead == 't') ADVANCE(136);
      END_STATE();
    case 154:
      if (lookahead == 't') ADVANCE(27);
      END_STATE();
    case 155:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 156:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 157:
      if (lookahead == 't') ADVANCE(86);
      END_STATE();
    case 158:
      if (lookahead == 'u') ADVANCE(101);
      END_STATE();
    case 159:
      if (lookahead == 'u') ADVANCE(104);
      END_STATE();
    case 160:
      if (lookahead == 'u') ADVANCE(51);
      END_STATE();
    case 161:
      if (lookahead == 'u') ADVANCE(46);
      END_STATE();
    case 162:
      if (lookahead == 'w') ADVANCE(258);
      END_STATE();
    case 163:
      if (lookahead == 'x') ADVANCE(256);
      END_STATE();
    case 164:
      if (lookahead == 'y') ADVANCE(282);
      END_STATE();
    case 165:
      if (lookahead == 'y') ADVANCE(299);
      END_STATE();
    case 166:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(169);
      END_STATE();
    case 167:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(301);
      END_STATE();
    case 168:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(261);
      END_STATE();
    case 169:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(168);
      END_STATE();
    case 170:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(264);
      END_STATE();
    case 171:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 172:
      if (eof) ADVANCE(173);
      if (lookahead == '$') ADVANCE(170);
      if (lookahead == 'a') ADVANCE(191);
      if (lookahead == 'd') ADVANCE(208);
      if (lookahead == 'i') ADVANCE(227);
      if (lookahead == 's') ADVANCE(184);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(172);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(254);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(185);
      if (lookahead == 'u') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(235);
      if (lookahead == 'e') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(201);
      if (lookahead == 'n') ADVANCE(187);
      if (lookahead == 'p') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(236);
      if (lookahead == 'r') ADVANCE(247);
      if (lookahead == 'w') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(174);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(231);
      if (lookahead == 'y') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(221);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'm') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'y') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == '.') ADVANCE(167);
      if (lookahead == 'm') ADVANCE(138);
      if (lookahead == 'p') ADVANCE(79);
      if (lookahead == 's') ADVANCE(255);
      if (lookahead == 'x') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(252);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == 'm') ADVANCE(138);
      if (lookahead == 'p') ADVANCE(79);
      if (lookahead == 's') ADVANCE(255);
      if (lookahead == 'x') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(253);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(254);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_DURATION);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_DISTANCE);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_QUANTITY);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(258);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(259);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(260);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_BOOLEAN);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_BOOLEAN);
      if (lookahead == 'c') ADVANCE(48);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(264);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_ENUM_ALIGNMENT);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_entity);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(anon_sym_entity);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_name);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_portrait);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(anon_sym_alignment);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_border_tileset);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_emote);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(169);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(250);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_json);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_json_number);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_json_number);
      if (lookahead == '.') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(300);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_json_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(301);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 172},
  [2] = {.lex_state = 172},
  [3] = {.lex_state = 172},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 172},
  [24] = {.lex_state = 172},
  [25] = {.lex_state = 172},
  [26] = {.lex_state = 172},
  [27] = {.lex_state = 172},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 172},
  [30] = {.lex_state = 172},
  [31] = {.lex_state = 172},
  [32] = {.lex_state = 172},
  [33] = {.lex_state = 172},
  [34] = {.lex_state = 172},
  [35] = {.lex_state = 172},
  [36] = {.lex_state = 172},
  [37] = {.lex_state = 172},
  [38] = {.lex_state = 172},
  [39] = {.lex_state = 172},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 3},
  [42] = {.lex_state = 3},
  [43] = {.lex_state = 3},
  [44] = {.lex_state = 3},
  [45] = {.lex_state = 3},
  [46] = {.lex_state = 3},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 3},
  [49] = {.lex_state = 3},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 3},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 1},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 1},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 1},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 1},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 1},
  [92] = {.lex_state = 1},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 172},
  [99] = {.lex_state = 172},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 172},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
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
  [118] = {.lex_state = 2},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 1},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
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
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
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
    [anon_sym_json] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_json_number] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(127),
    [sym__root] = STATE(3),
    [sym_include_macro] = STATE(3),
    [sym_constant_assignment] = STATE(3),
    [sym_add_serial_dialog_settings] = STATE(3),
    [sym_add_dialog_settings] = STATE(3),
    [sym_dialog_definition] = STATE(3),
    [sym_serial_dialog_definition] = STATE(3),
    [sym_script_definition] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(5),
    [sym_CONSTANT] = ACTIONS(7),
    [anon_sym_include] = ACTIONS(9),
    [anon_sym_add] = ACTIONS(11),
    [anon_sym_serial_dialog] = ACTIONS(13),
    [anon_sym_dialog] = ACTIONS(15),
    [anon_sym_script] = ACTIONS(17),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 9,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      sym_BAREWORD,
    ACTIONS(24), 1,
      sym_CONSTANT,
    ACTIONS(27), 1,
      anon_sym_include,
    ACTIONS(30), 1,
      anon_sym_add,
    ACTIONS(33), 1,
      anon_sym_serial_dialog,
    ACTIONS(36), 1,
      anon_sym_dialog,
    ACTIONS(39), 1,
      anon_sym_script,
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
  [36] = 9,
    ACTIONS(5), 1,
      sym_BAREWORD,
    ACTIONS(7), 1,
      sym_CONSTANT,
    ACTIONS(9), 1,
      anon_sym_include,
    ACTIONS(11), 1,
      anon_sym_add,
    ACTIONS(13), 1,
      anon_sym_serial_dialog,
    ACTIONS(15), 1,
      anon_sym_dialog,
    ACTIONS(17), 1,
      anon_sym_script,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
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
  [72] = 6,
    ACTIONS(46), 1,
      anon_sym_LBRACE,
    ACTIONS(48), 1,
      anon_sym_LBRACK,
    ACTIONS(50), 1,
      anon_sym_RBRACK,
    ACTIONS(44), 2,
      sym_QUOTED_STRING,
      sym_json_number,
    ACTIONS(52), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(90), 4,
      sym_json_array,
      sym__json_item,
      sym_json_language_constant,
      sym_json_object,
  [97] = 10,
    ACTIONS(54), 1,
      sym_QUOTED_STRING,
    ACTIONS(56), 1,
      anon_sym_wrap,
    ACTIONS(58), 1,
      anon_sym_entity,
    ACTIONS(60), 1,
      anon_sym_name,
    ACTIONS(62), 1,
      anon_sym_portrait,
    ACTIONS(64), 1,
      anon_sym_alignment,
    ACTIONS(66), 1,
      anon_sym_border_tileset,
    ACTIONS(68), 1,
      anon_sym_emote,
    STATE(13), 1,
      aux_sym_dialog_repeat1,
    STATE(7), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [129] = 3,
    STATE(134), 2,
      sym__STRING,
      sym__NUMBERISH,
    ACTIONS(70), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(72), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [147] = 10,
    ACTIONS(54), 1,
      sym_QUOTED_STRING,
    ACTIONS(56), 1,
      anon_sym_wrap,
    ACTIONS(58), 1,
      anon_sym_entity,
    ACTIONS(60), 1,
      anon_sym_name,
    ACTIONS(62), 1,
      anon_sym_portrait,
    ACTIONS(64), 1,
      anon_sym_alignment,
    ACTIONS(66), 1,
      anon_sym_border_tileset,
    ACTIONS(68), 1,
      anon_sym_emote,
    STATE(21), 1,
      aux_sym_dialog_repeat1,
    STATE(9), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [179] = 5,
    ACTIONS(46), 1,
      anon_sym_LBRACE,
    ACTIONS(48), 1,
      anon_sym_LBRACK,
    ACTIONS(74), 2,
      sym_QUOTED_STRING,
      sym_json_number,
    ACTIONS(52), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(105), 4,
      sym_json_array,
      sym__json_item,
      sym_json_language_constant,
      sym_json_object,
  [201] = 9,
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
    ACTIONS(76), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(9), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [231] = 5,
    ACTIONS(46), 1,
      anon_sym_LBRACE,
    ACTIONS(48), 1,
      anon_sym_LBRACK,
    ACTIONS(99), 2,
      sym_QUOTED_STRING,
      sym_json_number,
    ACTIONS(52), 3,
      anon_sym_true,
      anon_sym_false,
      anon_sym_null,
    STATE(115), 4,
      sym_json_array,
      sym__json_item,
      sym_json_language_constant,
      sym_json_object,
  [253] = 9,
    ACTIONS(56), 1,
      anon_sym_wrap,
    ACTIONS(58), 1,
      anon_sym_entity,
    ACTIONS(60), 1,
      anon_sym_name,
    ACTIONS(62), 1,
      anon_sym_portrait,
    ACTIONS(64), 1,
      anon_sym_alignment,
    ACTIONS(66), 1,
      anon_sym_border_tileset,
    ACTIONS(68), 1,
      anon_sym_emote,
    ACTIONS(101), 1,
      anon_sym_RBRACE,
    STATE(9), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [282] = 9,
    ACTIONS(56), 1,
      anon_sym_wrap,
    ACTIONS(58), 1,
      anon_sym_entity,
    ACTIONS(60), 1,
      anon_sym_name,
    ACTIONS(62), 1,
      anon_sym_portrait,
    ACTIONS(64), 1,
      anon_sym_alignment,
    ACTIONS(66), 1,
      anon_sym_border_tileset,
    ACTIONS(68), 1,
      anon_sym_emote,
    ACTIONS(103), 1,
      anon_sym_RBRACE,
    STATE(11), 2,
      sym_dialog_parameter,
      aux_sym_dialog_settings_block_repeat1,
  [311] = 6,
    ACTIONS(54), 1,
      sym_QUOTED_STRING,
    ACTIONS(107), 1,
      anon_sym_RBRACE,
    ACTIONS(109), 1,
      anon_sym_GT,
    STATE(45), 1,
      aux_sym_dialog_repeat1,
    STATE(46), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(105), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [333] = 1,
    ACTIONS(111), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [345] = 1,
    ACTIONS(113), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [357] = 1,
    ACTIONS(115), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [369] = 1,
    ACTIONS(117), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [381] = 1,
    ACTIONS(119), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [393] = 1,
    ACTIONS(121), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [405] = 1,
    ACTIONS(123), 9,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [417] = 6,
    ACTIONS(54), 1,
      sym_QUOTED_STRING,
    ACTIONS(109), 1,
      anon_sym_GT,
    ACTIONS(127), 1,
      anon_sym_RBRACE,
    STATE(45), 1,
      aux_sym_dialog_repeat1,
    STATE(44), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(125), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [439] = 1,
    ACTIONS(129), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [450] = 2,
    ACTIONS(131), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(133), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [463] = 2,
    ACTIONS(135), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(137), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [476] = 2,
    ACTIONS(139), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(141), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [489] = 2,
    ACTIONS(143), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(145), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [502] = 2,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(149), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [515] = 1,
    ACTIONS(151), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [526] = 2,
    ACTIONS(153), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(155), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [539] = 2,
    ACTIONS(157), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(159), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [552] = 2,
    ACTIONS(161), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(163), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [565] = 2,
    ACTIONS(165), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(167), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [578] = 2,
    ACTIONS(169), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(171), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [591] = 2,
    ACTIONS(173), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(175), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [604] = 2,
    ACTIONS(177), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(179), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [617] = 2,
    ACTIONS(181), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(183), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [630] = 2,
    ACTIONS(185), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(187), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [643] = 2,
    ACTIONS(189), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(191), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [656] = 2,
    ACTIONS(193), 2,
      ts_builtin_sym_end,
      sym_CONSTANT,
    ACTIONS(195), 6,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_dialog,
      anon_sym_script,
  [669] = 1,
    ACTIONS(197), 8,
      sym_QUOTED_STRING,
      anon_sym_wrap,
      anon_sym_entity,
      anon_sym_name,
      anon_sym_portrait,
      anon_sym_alignment,
      anon_sym_border_tileset,
      anon_sym_emote,
  [680] = 6,
    ACTIONS(199), 1,
      sym_BAREWORD,
    ACTIONS(201), 1,
      anon_sym_RBRACE,
    ACTIONS(203), 1,
      anon_sym_entity,
    ACTIONS(205), 1,
      anon_sym_name,
    STATE(5), 1,
      sym_dialog_identifier,
    STATE(42), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [700] = 6,
    ACTIONS(199), 1,
      sym_BAREWORD,
    ACTIONS(203), 1,
      anon_sym_entity,
    ACTIONS(205), 1,
      anon_sym_name,
    ACTIONS(207), 1,
      anon_sym_RBRACE,
    STATE(5), 1,
      sym_dialog_identifier,
    STATE(43), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [720] = 6,
    ACTIONS(209), 1,
      sym_BAREWORD,
    ACTIONS(212), 1,
      anon_sym_RBRACE,
    ACTIONS(214), 1,
      anon_sym_entity,
    ACTIONS(217), 1,
      anon_sym_name,
    STATE(5), 1,
      sym_dialog_identifier,
    STATE(43), 2,
      sym_dialog,
      aux_sym_dialog_block_repeat1,
  [740] = 4,
    ACTIONS(109), 1,
      anon_sym_GT,
    ACTIONS(222), 1,
      anon_sym_RBRACE,
    STATE(48), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(220), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [756] = 4,
    ACTIONS(226), 1,
      sym_QUOTED_STRING,
    STATE(45), 1,
      aux_sym_dialog_repeat1,
    ACTIONS(229), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(224), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [772] = 4,
    ACTIONS(109), 1,
      anon_sym_GT,
    ACTIONS(233), 1,
      anon_sym_RBRACE,
    STATE(48), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(231), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [788] = 6,
    ACTIONS(235), 1,
      sym_QUOTED_STRING,
    ACTIONS(237), 1,
      anon_sym_RBRACE,
    ACTIONS(239), 1,
      anon_sym_wrap,
    STATE(51), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(131), 1,
      sym_serial_dialog,
    STATE(58), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [808] = 4,
    ACTIONS(243), 1,
      anon_sym_RBRACE,
    ACTIONS(245), 1,
      anon_sym_GT,
    STATE(48), 2,
      sym_dialog_option,
      aux_sym_dialog_repeat2,
    ACTIONS(241), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [824] = 2,
    ACTIONS(248), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
    ACTIONS(250), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_GT,
  [835] = 5,
    ACTIONS(235), 1,
      sym_QUOTED_STRING,
    ACTIONS(252), 1,
      anon_sym_RBRACE,
    ACTIONS(254), 1,
      sym_serial_dialog_option_type,
    STATE(78), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(72), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [852] = 5,
    ACTIONS(235), 1,
      sym_QUOTED_STRING,
    ACTIONS(254), 1,
      sym_serial_dialog_option_type,
    ACTIONS(256), 1,
      anon_sym_RBRACE,
    STATE(78), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(79), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [869] = 5,
    ACTIONS(258), 1,
      anon_sym_RBRACE,
    ACTIONS(260), 1,
      anon_sym_default,
    ACTIONS(262), 1,
      anon_sym_label,
    ACTIONS(264), 1,
      anon_sym_entity,
    STATE(56), 1,
      aux_sym_add_dialog_settings_repeat1,
  [885] = 4,
    ACTIONS(266), 1,
      anon_sym_RBRACE,
    ACTIONS(268), 1,
      anon_sym_json,
    STATE(117), 1,
      sym_json_literal,
    STATE(57), 2,
      sym_script_item,
      aux_sym_script_literal_repeat1,
  [899] = 3,
    ACTIONS(272), 1,
      anon_sym_wrap,
    ACTIONS(270), 2,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
    STATE(54), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [911] = 4,
    ACTIONS(268), 1,
      anon_sym_json,
    ACTIONS(275), 1,
      anon_sym_RBRACE,
    STATE(117), 1,
      sym_json_literal,
    STATE(53), 2,
      sym_script_item,
      aux_sym_script_literal_repeat1,
  [925] = 5,
    ACTIONS(277), 1,
      anon_sym_RBRACE,
    ACTIONS(279), 1,
      anon_sym_default,
    ACTIONS(282), 1,
      anon_sym_label,
    ACTIONS(285), 1,
      anon_sym_entity,
    STATE(56), 1,
      aux_sym_add_dialog_settings_repeat1,
  [941] = 4,
    ACTIONS(288), 1,
      anon_sym_RBRACE,
    ACTIONS(290), 1,
      anon_sym_json,
    STATE(117), 1,
      sym_json_literal,
    STATE(57), 2,
      sym_script_item,
      aux_sym_script_literal_repeat1,
  [955] = 4,
    ACTIONS(235), 1,
      sym_QUOTED_STRING,
    ACTIONS(239), 1,
      anon_sym_wrap,
    STATE(50), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(54), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [969] = 5,
    ACTIONS(260), 1,
      anon_sym_default,
    ACTIONS(262), 1,
      anon_sym_label,
    ACTIONS(264), 1,
      anon_sym_entity,
    ACTIONS(293), 1,
      anon_sym_RBRACE,
    STATE(52), 1,
      aux_sym_add_dialog_settings_repeat1,
  [985] = 2,
    ACTIONS(297), 2,
      anon_sym_RBRACE,
      anon_sym_GT,
    ACTIONS(295), 3,
      sym_BAREWORD,
      anon_sym_entity,
      anon_sym_name,
  [995] = 1,
    ACTIONS(299), 4,
      anon_sym_RBRACE,
      anon_sym_json,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1002] = 2,
    STATE(108), 1,
      sym__string,
    ACTIONS(301), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1011] = 3,
    ACTIONS(239), 1,
      anon_sym_wrap,
    ACTIONS(303), 1,
      anon_sym_RBRACE,
    STATE(54), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1022] = 2,
    STATE(104), 1,
      sym__string,
    ACTIONS(305), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1031] = 2,
    STATE(20), 1,
      sym__string,
    ACTIONS(307), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1040] = 3,
    ACTIONS(239), 1,
      anon_sym_wrap,
    ACTIONS(309), 1,
      anon_sym_RBRACE,
    STATE(63), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1051] = 2,
    STATE(15), 1,
      sym__string,
    ACTIONS(311), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1060] = 1,
    ACTIONS(313), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1067] = 2,
    STATE(16), 1,
      sym__string,
    ACTIONS(315), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1076] = 2,
    STATE(18), 1,
      sym__string,
    ACTIONS(317), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1085] = 1,
    ACTIONS(319), 4,
      anon_sym_RBRACE,
      anon_sym_json,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1092] = 3,
    ACTIONS(254), 1,
      sym_serial_dialog_option_type,
    ACTIONS(321), 1,
      anon_sym_RBRACE,
    STATE(74), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1103] = 1,
    ACTIONS(323), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1110] = 3,
    ACTIONS(325), 1,
      anon_sym_RBRACE,
    ACTIONS(327), 1,
      sym_serial_dialog_option_type,
    STATE(74), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1121] = 1,
    ACTIONS(330), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1128] = 1,
    ACTIONS(332), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1135] = 2,
    STATE(118), 1,
      sym__string,
    ACTIONS(334), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1144] = 3,
    ACTIONS(336), 1,
      sym_QUOTED_STRING,
    STATE(78), 1,
      aux_sym_serial_dialog_repeat1,
    ACTIONS(339), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1155] = 3,
    ACTIONS(254), 1,
      sym_serial_dialog_option_type,
    ACTIONS(341), 1,
      anon_sym_RBRACE,
    STATE(74), 2,
      sym_serial_dialog_option,
      aux_sym_serial_dialog_repeat2,
  [1166] = 1,
    ACTIONS(343), 4,
      anon_sym_RBRACE,
      anon_sym_default,
      anon_sym_label,
      anon_sym_entity,
  [1173] = 2,
    STATE(60), 1,
      sym__string,
    ACTIONS(345), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1182] = 1,
    ACTIONS(347), 4,
      anon_sym_RBRACE,
      anon_sym_json,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1189] = 3,
    ACTIONS(349), 1,
      anon_sym_COMMA,
    ACTIONS(352), 1,
      anon_sym_RBRACK,
    STATE(83), 1,
      aux_sym_json_array_repeat1,
  [1199] = 2,
    STATE(28), 1,
      sym__STRING,
    ACTIONS(354), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1207] = 1,
    ACTIONS(356), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1213] = 3,
    ACTIONS(358), 1,
      anon_sym_RBRACE,
    ACTIONS(360), 1,
      anon_sym_COMMA,
    STATE(96), 1,
      aux_sym_json_object_repeat1,
  [1223] = 3,
    ACTIONS(362), 1,
      anon_sym_COMMA,
    ACTIONS(364), 1,
      anon_sym_RBRACK,
    STATE(83), 1,
      aux_sym_json_array_repeat1,
  [1233] = 3,
    ACTIONS(366), 1,
      sym_QUOTED_STRING,
    ACTIONS(368), 1,
      anon_sym_RBRACE,
    STATE(86), 1,
      sym_json_property_value_pair,
  [1243] = 1,
    ACTIONS(370), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1249] = 3,
    ACTIONS(362), 1,
      anon_sym_COMMA,
    ACTIONS(372), 1,
      anon_sym_RBRACK,
    STATE(87), 1,
      aux_sym_json_array_repeat1,
  [1259] = 2,
    STATE(107), 1,
      sym__STRING,
    ACTIONS(374), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1267] = 2,
    STATE(119), 1,
      sym__bareword,
    ACTIONS(376), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1275] = 1,
    ACTIONS(378), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [1281] = 2,
    STATE(22), 1,
      sym__STRING,
    ACTIONS(380), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1289] = 1,
    ACTIONS(382), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1295] = 3,
    ACTIONS(360), 1,
      anon_sym_COMMA,
    ACTIONS(384), 1,
      anon_sym_RBRACE,
    STATE(103), 1,
      aux_sym_json_object_repeat1,
  [1305] = 1,
    ACTIONS(386), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1311] = 2,
    STATE(14), 1,
      sym__number,
    ACTIONS(388), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1319] = 2,
    STATE(93), 1,
      sym__number,
    ACTIONS(390), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1327] = 2,
    STATE(17), 1,
      sym__enum_alignment,
    ACTIONS(392), 2,
      sym_CONSTANT,
      sym_ENUM_ALIGNMENT,
  [1335] = 2,
    STATE(19), 1,
      sym__number,
    ACTIONS(394), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1343] = 1,
    ACTIONS(396), 3,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1349] = 3,
    ACTIONS(398), 1,
      anon_sym_RBRACE,
    ACTIONS(400), 1,
      anon_sym_COMMA,
    STATE(103), 1,
      aux_sym_json_object_repeat1,
  [1359] = 2,
    ACTIONS(403), 1,
      anon_sym_LBRACE,
    STATE(35), 1,
      sym_dialog_block,
  [1366] = 1,
    ACTIONS(352), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1371] = 1,
    ACTIONS(405), 2,
      anon_sym_RBRACE,
      anon_sym_json,
  [1376] = 2,
    ACTIONS(407), 1,
      anon_sym_LBRACE,
    STATE(33), 1,
      sym_serial_dialog_block,
  [1383] = 2,
    ACTIONS(409), 1,
      anon_sym_LBRACE,
    STATE(76), 1,
      sym_dialog_settings_block,
  [1390] = 2,
    ACTIONS(411), 1,
      anon_sym_LBRACE,
    STATE(36), 1,
      sym_script_literal,
  [1397] = 2,
    ACTIONS(413), 1,
      anon_sym_serial_dialog,
    ACTIONS(415), 1,
      anon_sym_dialog,
  [1404] = 2,
    ACTIONS(366), 1,
      sym_QUOTED_STRING,
    STATE(116), 1,
      sym_json_property_value_pair,
  [1411] = 2,
    ACTIONS(411), 1,
      anon_sym_LBRACE,
    STATE(24), 1,
      sym_script_literal,
  [1418] = 2,
    ACTIONS(48), 1,
      anon_sym_LBRACK,
    STATE(106), 1,
      sym_json_array,
  [1425] = 2,
    ACTIONS(409), 1,
      anon_sym_LBRACE,
    STATE(68), 1,
      sym_dialog_settings_block,
  [1432] = 1,
    ACTIONS(417), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [1437] = 1,
    ACTIONS(398), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [1442] = 1,
    ACTIONS(419), 2,
      anon_sym_RBRACE,
      anon_sym_json,
  [1447] = 1,
    ACTIONS(421), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1452] = 2,
    ACTIONS(409), 1,
      anon_sym_LBRACE,
    STATE(75), 1,
      sym_dialog_settings_block,
  [1459] = 1,
    ACTIONS(423), 1,
      sym_QUOTED_STRING,
  [1463] = 1,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
  [1467] = 1,
    ACTIONS(427), 1,
      sym_BAREWORD,
  [1471] = 1,
    ACTIONS(429), 1,
      sym_QUOTED_STRING,
  [1475] = 1,
    ACTIONS(431), 1,
      anon_sym_COLON,
  [1479] = 1,
    ACTIONS(433), 1,
      sym_QUOTED_STRING,
  [1483] = 1,
    ACTIONS(435), 1,
      anon_sym_EQ,
  [1487] = 1,
    ACTIONS(437), 1,
      ts_builtin_sym_end,
  [1491] = 1,
    ACTIONS(439), 1,
      anon_sym_SEMI,
  [1495] = 1,
    ACTIONS(441), 1,
      anon_sym_LBRACE,
  [1499] = 1,
    ACTIONS(443), 1,
      anon_sym_EQ,
  [1503] = 1,
    ACTIONS(445), 1,
      anon_sym_RBRACE,
  [1507] = 1,
    ACTIONS(447), 1,
      anon_sym_settings,
  [1511] = 1,
    ACTIONS(449), 1,
      anon_sym_settings,
  [1515] = 1,
    ACTIONS(451), 1,
      anon_sym_SEMI,
  [1519] = 1,
    ACTIONS(453), 1,
      anon_sym_EQ,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 36,
  [SMALL_STATE(4)] = 72,
  [SMALL_STATE(5)] = 97,
  [SMALL_STATE(6)] = 129,
  [SMALL_STATE(7)] = 147,
  [SMALL_STATE(8)] = 179,
  [SMALL_STATE(9)] = 201,
  [SMALL_STATE(10)] = 231,
  [SMALL_STATE(11)] = 253,
  [SMALL_STATE(12)] = 282,
  [SMALL_STATE(13)] = 311,
  [SMALL_STATE(14)] = 333,
  [SMALL_STATE(15)] = 345,
  [SMALL_STATE(16)] = 357,
  [SMALL_STATE(17)] = 369,
  [SMALL_STATE(18)] = 381,
  [SMALL_STATE(19)] = 393,
  [SMALL_STATE(20)] = 405,
  [SMALL_STATE(21)] = 417,
  [SMALL_STATE(22)] = 439,
  [SMALL_STATE(23)] = 450,
  [SMALL_STATE(24)] = 463,
  [SMALL_STATE(25)] = 476,
  [SMALL_STATE(26)] = 489,
  [SMALL_STATE(27)] = 502,
  [SMALL_STATE(28)] = 515,
  [SMALL_STATE(29)] = 526,
  [SMALL_STATE(30)] = 539,
  [SMALL_STATE(31)] = 552,
  [SMALL_STATE(32)] = 565,
  [SMALL_STATE(33)] = 578,
  [SMALL_STATE(34)] = 591,
  [SMALL_STATE(35)] = 604,
  [SMALL_STATE(36)] = 617,
  [SMALL_STATE(37)] = 630,
  [SMALL_STATE(38)] = 643,
  [SMALL_STATE(39)] = 656,
  [SMALL_STATE(40)] = 669,
  [SMALL_STATE(41)] = 680,
  [SMALL_STATE(42)] = 700,
  [SMALL_STATE(43)] = 720,
  [SMALL_STATE(44)] = 740,
  [SMALL_STATE(45)] = 756,
  [SMALL_STATE(46)] = 772,
  [SMALL_STATE(47)] = 788,
  [SMALL_STATE(48)] = 808,
  [SMALL_STATE(49)] = 824,
  [SMALL_STATE(50)] = 835,
  [SMALL_STATE(51)] = 852,
  [SMALL_STATE(52)] = 869,
  [SMALL_STATE(53)] = 885,
  [SMALL_STATE(54)] = 899,
  [SMALL_STATE(55)] = 911,
  [SMALL_STATE(56)] = 925,
  [SMALL_STATE(57)] = 941,
  [SMALL_STATE(58)] = 955,
  [SMALL_STATE(59)] = 969,
  [SMALL_STATE(60)] = 985,
  [SMALL_STATE(61)] = 995,
  [SMALL_STATE(62)] = 1002,
  [SMALL_STATE(63)] = 1011,
  [SMALL_STATE(64)] = 1022,
  [SMALL_STATE(65)] = 1031,
  [SMALL_STATE(66)] = 1040,
  [SMALL_STATE(67)] = 1051,
  [SMALL_STATE(68)] = 1060,
  [SMALL_STATE(69)] = 1067,
  [SMALL_STATE(70)] = 1076,
  [SMALL_STATE(71)] = 1085,
  [SMALL_STATE(72)] = 1092,
  [SMALL_STATE(73)] = 1103,
  [SMALL_STATE(74)] = 1110,
  [SMALL_STATE(75)] = 1121,
  [SMALL_STATE(76)] = 1128,
  [SMALL_STATE(77)] = 1135,
  [SMALL_STATE(78)] = 1144,
  [SMALL_STATE(79)] = 1155,
  [SMALL_STATE(80)] = 1166,
  [SMALL_STATE(81)] = 1173,
  [SMALL_STATE(82)] = 1182,
  [SMALL_STATE(83)] = 1189,
  [SMALL_STATE(84)] = 1199,
  [SMALL_STATE(85)] = 1207,
  [SMALL_STATE(86)] = 1213,
  [SMALL_STATE(87)] = 1223,
  [SMALL_STATE(88)] = 1233,
  [SMALL_STATE(89)] = 1243,
  [SMALL_STATE(90)] = 1249,
  [SMALL_STATE(91)] = 1259,
  [SMALL_STATE(92)] = 1267,
  [SMALL_STATE(93)] = 1275,
  [SMALL_STATE(94)] = 1281,
  [SMALL_STATE(95)] = 1289,
  [SMALL_STATE(96)] = 1295,
  [SMALL_STATE(97)] = 1305,
  [SMALL_STATE(98)] = 1311,
  [SMALL_STATE(99)] = 1319,
  [SMALL_STATE(100)] = 1327,
  [SMALL_STATE(101)] = 1335,
  [SMALL_STATE(102)] = 1343,
  [SMALL_STATE(103)] = 1349,
  [SMALL_STATE(104)] = 1359,
  [SMALL_STATE(105)] = 1366,
  [SMALL_STATE(106)] = 1371,
  [SMALL_STATE(107)] = 1376,
  [SMALL_STATE(108)] = 1383,
  [SMALL_STATE(109)] = 1390,
  [SMALL_STATE(110)] = 1397,
  [SMALL_STATE(111)] = 1404,
  [SMALL_STATE(112)] = 1411,
  [SMALL_STATE(113)] = 1418,
  [SMALL_STATE(114)] = 1425,
  [SMALL_STATE(115)] = 1432,
  [SMALL_STATE(116)] = 1437,
  [SMALL_STATE(117)] = 1442,
  [SMALL_STATE(118)] = 1447,
  [SMALL_STATE(119)] = 1452,
  [SMALL_STATE(120)] = 1459,
  [SMALL_STATE(121)] = 1463,
  [SMALL_STATE(122)] = 1467,
  [SMALL_STATE(123)] = 1471,
  [SMALL_STATE(124)] = 1475,
  [SMALL_STATE(125)] = 1479,
  [SMALL_STATE(126)] = 1483,
  [SMALL_STATE(127)] = 1487,
  [SMALL_STATE(128)] = 1491,
  [SMALL_STATE(129)] = 1495,
  [SMALL_STATE(130)] = 1499,
  [SMALL_STATE(131)] = 1503,
  [SMALL_STATE(132)] = 1507,
  [SMALL_STATE(133)] = 1511,
  [SMALL_STATE(134)] = 1515,
  [SMALL_STATE(135)] = 1519,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(112),
  [24] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [27] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(125),
  [30] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(110),
  [33] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [36] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(98),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [87] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(100),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(70),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_settings_block_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 2, 0, 16),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 2, 0, 16),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 19),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 14),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 20),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 21),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 22),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 23),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_parameter, 2, 0, 13),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 24),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 24),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 14),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 2, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 5, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 3, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 2, 0, 13),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_literal, 2, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_literal, 2, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_block, 3, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_dialog_settings, 6, 0, 17),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_dialog_settings, 6, 0, 17),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_definition, 3, 0, 4),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 5),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 5),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_literal, 3, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_literal, 3, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 6),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 6),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_block, 2, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_identifier, 1, 0, 9),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [209] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0),
  [214] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(84),
  [217] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_dialog_block_repeat1, 2, 0, 0), SHIFT_REPEAT(94),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 4, 0, 24),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 4, 0, 24),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 25),
  [226] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 25), SHIFT_REPEAT(49),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 2, 0, 25),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog, 3, 0, 16),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog, 3, 0, 16),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [241] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0),
  [245] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(123),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 15),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dialog_repeat1, 1, 0, 15),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 11),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 8),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [272] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 18),
  [279] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 18), SHIFT_REPEAT(114),
  [282] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 18), SHIFT_REPEAT(92),
  [285] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 18), SHIFT_REPEAT(62),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_literal_repeat1, 2, 0, 0),
  [290] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_literal_repeat1, 2, 0, 0), SHIFT_REPEAT(113),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [295] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dialog_option, 4, 0, 30),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_option, 4, 0, 30),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 3, 0, 0),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [313] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 2, 0, 0),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 4, 0, 0),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 11),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 2, 0, 0),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0),
  [327] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 0), SHIFT_REPEAT(120),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 26),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_dialog_settings_repeat1, 3, 0, 27),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [336] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 12), SHIFT_REPEAT(97),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 12),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 8),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dialog_settings_block, 3, 0, 0),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_array, 2, 0, 0),
  [349] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [352] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_array_repeat1, 2, 0, 0),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 2, 0, 0),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_language_constant, 1, 0, 0),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 10),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 3, 0, 0),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [386] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 7),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_object, 4, 0, 0),
  [398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0),
  [400] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_json_object_repeat1, 2, 0, 0), SHIFT_REPEAT(111),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_literal, 2, 0, 0),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [417] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_json_property_value_pair, 3, 0, 28),
  [419] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_item, 1, 0, 0),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 29),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [437] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
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
