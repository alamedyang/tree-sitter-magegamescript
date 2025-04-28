#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 152
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 91
#define ALIAS_COUNT 0
#define TOKEN_COUNT 45
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 17
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 27

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
  anon_sym_rand = 27,
  anon_sym_BANG = 28,
  anon_sym_LPAREN = 29,
  anon_sym_RPAREN = 30,
  anon_sym_COLON = 31,
  sym_action_return_statement = 32,
  anon_sym_close = 33,
  anon_sym_dialog = 34,
  anon_sym_save = 35,
  anon_sym_slot = 36,
  anon_sym_load = 37,
  anon_sym_erase = 38,
  anon_sym_map = 39,
  anon_sym_goto = 40,
  anon_sym_label = 41,
  anon_sym_index = 42,
  anon_sym_wait = 43,
  anon_sym_block = 44,
  sym_document = 45,
  sym_bareword_expansion = 46,
  sym_quoted_string_expansion = 47,
  sym_string_expansion = 48,
  sym_number_expansion = 49,
  sym_DURATION = 50,
  sym_duration_expansion = 51,
  sym_DISTANCE = 52,
  sym_QUANTITY = 53,
  sym__root = 54,
  sym_include_macro = 55,
  sym_constant_assignment = 56,
  sym_add_serial_dialog_settings = 57,
  sym_serial_dialog_parameter = 58,
  sym_serial_dialog_definition = 59,
  sym__serial_dialog_block = 60,
  sym_serial_dialog = 61,
  sym_serial_dialog_option = 62,
  sym_script_definition = 63,
  sym_script_block = 64,
  sym__script_item = 65,
  sym_rand_macro = 66,
  sym_label = 67,
  sym__action_item = 68,
  sym_action_close_dialog = 69,
  sym_action_close_serial_dialog = 70,
  sym_action_save_slot = 71,
  sym_action_load_slot = 72,
  sym_action_erase_slot = 73,
  sym_action_load_map = 74,
  sym_action_run_script = 75,
  sym_action_goto_label = 76,
  sym_action_goto_index = 77,
  sym_action_non_blocking_delay = 78,
  sym_action_blocking_delay = 79,
  aux_sym_document_repeat1 = 80,
  aux_sym_bareword_expansion_repeat1 = 81,
  aux_sym_quoted_string_expansion_repeat1 = 82,
  aux_sym_string_expansion_repeat1 = 83,
  aux_sym_number_expansion_repeat1 = 84,
  aux_sym_duration_expansion_repeat1 = 85,
  aux_sym_add_serial_dialog_settings_repeat1 = 86,
  aux_sym_serial_dialog_repeat1 = 87,
  aux_sym_serial_dialog_repeat2 = 88,
  aux_sym_serial_dialog_repeat3 = 89,
  aux_sym_script_block_repeat1 = 90,
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
  [anon_sym_rand] = "rand",
  [anon_sym_BANG] = "!",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
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
  [anon_sym_rand] = anon_sym_rand,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
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
  [anon_sym_COLON] = {
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
  [26] = {.index = 35, .length = 3},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(125);
      ADVANCE_MAP(
        '!', 272,
        '"', 6,
        '#', 267,
        '$', 121,
        '(', 273,
        ')', 274,
        ',', 240,
        '/', 8,
        ':', 275,
        ';', 256,
        '=', 257,
        '[', 239,
        ']', 241,
        '_', 266,
        'a', 38,
        'b', 70,
        'c', 71,
        'd', 61,
        'e', 97,
        'g', 86,
        'i', 79,
        'l', 13,
        'm', 15,
        'o', 80,
        'p', 60,
        'r', 23,
        's', 245,
        't', 58,
        'w', 22,
        'x', 247,
        'y', 48,
        '{', 263,
        '}', 264,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(123);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(243);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 6,
        '#', 118,
        '$', 121,
        '/', 8,
        'b', 192,
        'c', 197,
        'f', 142,
        'g', 221,
        'm', 136,
        'o', 175,
        'r', 170,
        't', 180,
        'w', 179,
        'y', 171,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(243);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(121);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '[') ADVANCE(239);
      if (lookahead == ']') ADVANCE(241);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(121);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == '[') ADVANCE(239);
      if (lookahead == 'i') ADVANCE(206);
      if (lookahead == 'l') ADVANCE(133);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 4:
      ADVANCE_MAP(
        '"', 6,
        ',', 240,
        '/', 8,
        ';', 256,
        ']', 241,
        'm', 101,
        'p', 60,
        's', 244,
        'x', 247,
        '}', 264,
        '#', 266,
        '_', 266,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        '"', 6,
        ',', 240,
        '/', 8,
        ';', 256,
        ']', 241,
        '}', 264,
        '#', 266,
        '_', 266,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      END_STATE();
    case 6:
      if (lookahead == '"') ADVANCE(242);
      if (lookahead == '\\') ADVANCE(122);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      ADVANCE_MAP(
        ')', 274,
        '/', 8,
        'b', 194,
        'c', 195,
        'e', 220,
        'g', 212,
        'l', 213,
        'r', 134,
        's', 132,
        'w', 139,
        '}', 264,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(127);
      END_STATE();
    case 9:
      if (lookahead == '*') ADVANCE(9);
      if (lookahead == '/') ADVANCE(126);
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
      if (lookahead == 'd') ADVANCE(61);
      if (lookahead == 'm') ADVANCE(24);
      if (lookahead == 's') ADVANCE(41);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == '_') ADVANCE(40);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(29);
      if (lookahead == 'o') ADVANCE(20);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(57);
      if (lookahead == 's') ADVANCE(244);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(114);
      if (lookahead == 'c') ADVANCE(98);
      if (lookahead == 'e') ADVANCE(100);
      if (lookahead == 'l') ADVANCE(91);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(249);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(94);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(30);
      if (lookahead == 'o') ADVANCE(31);
      if (lookahead == 'u') ADVANCE(42);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(75);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(63);
      if (lookahead == 'h') ADVANCE(64);
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(84);
      if (lookahead == 'e') ADVANCE(35);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(93);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(81);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(73);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(104);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(77);
      END_STATE();
    case 29:
      if (lookahead == 'b') ADVANCE(52);
      END_STATE();
    case 30:
      if (lookahead == 'c') ADVANCE(68);
      END_STATE();
    case 31:
      if (lookahead == 'c') ADVANCE(69);
      END_STATE();
    case 32:
      if (lookahead == 'c') ADVANCE(74);
      if (lookahead == 'd') ADVANCE(49);
      END_STATE();
    case 33:
      if (lookahead == 'c') ADVANCE(43);
      END_STATE();
    case 34:
      if (lookahead == 'd') ADVANCE(258);
      END_STATE();
    case 35:
      if (lookahead == 'd') ADVANCE(249);
      if (lookahead == 't') ADVANCE(112);
      END_STATE();
    case 36:
      if (lookahead == 'd') ADVANCE(284);
      END_STATE();
    case 37:
      if (lookahead == 'd') ADVANCE(270);
      END_STATE();
    case 38:
      if (lookahead == 'd') ADVANCE(34);
      END_STATE();
    case 39:
      if (lookahead == 'd') ADVANCE(47);
      END_STATE();
    case 40:
      if (lookahead == 'd') ADVANCE(67);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(100);
      if (lookahead == 'l') ADVANCE(91);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(249);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(248);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(281);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(278);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(286);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(254);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(117);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 51:
      if (lookahead == 'e') ADVANCE(50);
      END_STATE();
    case 52:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(85);
      END_STATE();
    case 54:
      if (lookahead == 'g') ADVANCE(280);
      END_STATE();
    case 55:
      if (lookahead == 'g') ADVANCE(260);
      END_STATE();
    case 56:
      if (lookahead == 'g') ADVANCE(102);
      END_STATE();
    case 57:
      if (lookahead == 'g') ADVANCE(53);
      if (lookahead == 'p') ADVANCE(288);
      END_STATE();
    case 58:
      if (lookahead == 'h') ADVANCE(96);
      if (lookahead == 'w') ADVANCE(59);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 60:
      if (lookahead == 'i') ADVANCE(116);
      if (lookahead == 'x') ADVANCE(246);
      END_STATE();
    case 61:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 62:
      if (lookahead == 'i') ADVANCE(95);
      END_STATE();
    case 63:
      if (lookahead == 'i') ADVANCE(106);
      END_STATE();
    case 64:
      if (lookahead == 'i') ADVANCE(108);
      END_STATE();
    case 65:
      if (lookahead == 'i') ADVANCE(83);
      END_STATE();
    case 66:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 67:
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 68:
      if (lookahead == 'k') ADVANCE(249);
      END_STATE();
    case 69:
      if (lookahead == 'k') ADVANCE(297);
      END_STATE();
    case 70:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 71:
      if (lookahead == 'l') ADVANCE(87);
      if (lookahead == 'y') ADVANCE(25);
      END_STATE();
    case 72:
      if (lookahead == 'l') ADVANCE(291);
      END_STATE();
    case 73:
      if (lookahead == 'l') ADVANCE(12);
      END_STATE();
    case 74:
      if (lookahead == 'l') ADVANCE(113);
      END_STATE();
    case 75:
      if (lookahead == 'l') ADVANCE(89);
      END_STATE();
    case 76:
      if (lookahead == 'l') ADVANCE(90);
      END_STATE();
    case 77:
      if (lookahead == 'l') ADVANCE(92);
      END_STATE();
    case 78:
      if (lookahead == 'l') ADVANCE(76);
      END_STATE();
    case 79:
      if (lookahead == 'n') ADVANCE(32);
      END_STATE();
    case 80:
      if (lookahead == 'n') ADVANCE(33);
      END_STATE();
    case 81:
      if (lookahead == 'n') ADVANCE(249);
      END_STATE();
    case 82:
      if (lookahead == 'n') ADVANCE(276);
      END_STATE();
    case 83:
      if (lookahead == 'n') ADVANCE(56);
      END_STATE();
    case 84:
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 85:
      if (lookahead == 'n') ADVANCE(111);
      END_STATE();
    case 86:
      if (lookahead == 'o') ADVANCE(109);
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 87:
      if (lookahead == 'o') ADVANCE(103);
      END_STATE();
    case 88:
      if (lookahead == 'o') ADVANCE(289);
      END_STATE();
    case 89:
      if (lookahead == 'o') ADVANCE(54);
      END_STATE();
    case 90:
      if (lookahead == 'o') ADVANCE(115);
      END_STATE();
    case 91:
      if (lookahead == 'o') ADVANCE(105);
      END_STATE();
    case 92:
      if (lookahead == 'o') ADVANCE(55);
      END_STATE();
    case 93:
      if (lookahead == 'p') ADVANCE(288);
      END_STATE();
    case 94:
      if (lookahead == 'p') ADVANCE(265);
      END_STATE();
    case 95:
      if (lookahead == 'p') ADVANCE(107);
      END_STATE();
    case 96:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 97:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 98:
      if (lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 99:
      if (lookahead == 'r') ADVANCE(82);
      END_STATE();
    case 100:
      if (lookahead == 'r') ADVANCE(66);
      if (lookahead == 't') ADVANCE(110);
      END_STATE();
    case 101:
      if (lookahead == 's') ADVANCE(244);
      END_STATE();
    case 102:
      if (lookahead == 's') ADVANCE(262);
      END_STATE();
    case 103:
      if (lookahead == 's') ADVANCE(45);
      END_STATE();
    case 104:
      if (lookahead == 's') ADVANCE(46);
      END_STATE();
    case 105:
      if (lookahead == 't') ADVANCE(283);
      END_STATE();
    case 106:
      if (lookahead == 't') ADVANCE(295);
      END_STATE();
    case 107:
      if (lookahead == 't') ADVANCE(268);
      END_STATE();
    case 108:
      if (lookahead == 't') ADVANCE(42);
      END_STATE();
    case 109:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 110:
      if (lookahead == 't') ADVANCE(65);
      END_STATE();
    case 111:
      if (lookahead == 't') ADVANCE(17);
      END_STATE();
    case 112:
      if (lookahead == 'u') ADVANCE(99);
      END_STATE();
    case 113:
      if (lookahead == 'u') ADVANCE(39);
      END_STATE();
    case 114:
      if (lookahead == 'v') ADVANCE(44);
      END_STATE();
    case 115:
      if (lookahead == 'w') ADVANCE(249);
      END_STATE();
    case 116:
      if (lookahead == 'x') ADVANCE(246);
      END_STATE();
    case 117:
      if (lookahead == 'x') ADVANCE(293);
      END_STATE();
    case 118:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(120);
      END_STATE();
    case 119:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(252);
      END_STATE();
    case 120:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(119);
      END_STATE();
    case 121:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 122:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 123:
      if (eof) ADVANCE(125);
      ADVANCE_MAP(
        '!', 272,
        '"', 6,
        '#', 267,
        '$', 121,
        '(', 273,
        ')', 274,
        ',', 240,
        '/', 8,
        ':', 275,
        ';', 256,
        '=', 257,
        '[', 239,
        ']', 241,
        '_', 266,
        'a', 38,
        'b', 70,
        'c', 71,
        'd', 61,
        'e', 97,
        'g', 86,
        'i', 79,
        'l', 13,
        'm', 14,
        'o', 80,
        'r', 23,
        's', 16,
        't', 58,
        'w', 22,
        'y', 48,
        '{', 263,
        '}', 264,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(123);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(243);
      END_STATE();
    case 124:
      if (eof) ADVANCE(125);
      if (lookahead == '"') ADVANCE(6);
      if (lookahead == '$') ADVANCE(121);
      if (lookahead == '/') ADVANCE(8);
      if (lookahead == 'a') ADVANCE(156);
      if (lookahead == 'i') ADVANCE(201);
      if (lookahead == 's') ADVANCE(145);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(124);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(10);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(127);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == '_') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(204);
      if (lookahead == 'e') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(148);
      if (lookahead == 'u') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(216);
      if (lookahead == 'e') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(287);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(176);
      if (lookahead == 'n') ADVANCE(128);
      if (lookahead == 'p') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(169);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(219);
      if (lookahead == 'r') ADVANCE(234);
      if (lookahead == 'w') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(227);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(207);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(214);
      if (lookahead == 'y') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(277);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(147);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(226);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(202);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(174);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(218);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(243);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(114);
      if (lookahead == 'c') ADVANCE(98);
      if (lookahead == 'e') ADVANCE(100);
      if (lookahead == 'l') ADVANCE(91);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(249);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(250);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(251);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(253);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(anon_sym_include);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(anon_sym_add);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_serial_dialog_parameter_int);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_serial_dialog_option_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(120);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_action_return_statement);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_action_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(238);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 124},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 7},
  [5] = {.lex_state = 7},
  [6] = {.lex_state = 7},
  [7] = {.lex_state = 124},
  [8] = {.lex_state = 124},
  [9] = {.lex_state = 7},
  [10] = {.lex_state = 7},
  [11] = {.lex_state = 7},
  [12] = {.lex_state = 7},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 124},
  [15] = {.lex_state = 124},
  [16] = {.lex_state = 124},
  [17] = {.lex_state = 124},
  [18] = {.lex_state = 124},
  [19] = {.lex_state = 124},
  [20] = {.lex_state = 124},
  [21] = {.lex_state = 124},
  [22] = {.lex_state = 124},
  [23] = {.lex_state = 124},
  [24] = {.lex_state = 124},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 3},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 4},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 2},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 2},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 11},
  [88] = {.lex_state = 11},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
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
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 11},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 11},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 11},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
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
  [148] = {.lex_state = 11},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
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
    [anon_sym_rand] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
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
    [sym_document] = STATE(126),
    [sym__root] = STATE(7),
    [sym_include_macro] = STATE(7),
    [sym_constant_assignment] = STATE(7),
    [sym_add_serial_dialog_settings] = STATE(7),
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
  [0] = 14,
    ACTIONS(21), 1,
      sym_BAREWORD,
    ACTIONS(26), 1,
      anon_sym_rand,
    ACTIONS(29), 1,
      sym_action_return_statement,
    ACTIONS(32), 1,
      anon_sym_close,
    ACTIONS(35), 1,
      anon_sym_save,
    ACTIONS(38), 1,
      anon_sym_load,
    ACTIONS(41), 1,
      anon_sym_erase,
    ACTIONS(44), 1,
      anon_sym_goto,
    ACTIONS(47), 1,
      anon_sym_wait,
    ACTIONS(50), 1,
      anon_sym_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(24), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(2), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(135), 12,
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
  [59] = 14,
    ACTIONS(53), 1,
      sym_BAREWORD,
    ACTIONS(55), 1,
      anon_sym_RBRACE,
    ACTIONS(57), 1,
      anon_sym_rand,
    ACTIONS(59), 1,
      sym_action_return_statement,
    ACTIONS(61), 1,
      anon_sym_close,
    ACTIONS(63), 1,
      anon_sym_save,
    ACTIONS(65), 1,
      anon_sym_load,
    ACTIONS(67), 1,
      anon_sym_erase,
    ACTIONS(69), 1,
      anon_sym_goto,
    ACTIONS(71), 1,
      anon_sym_wait,
    ACTIONS(73), 1,
      anon_sym_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(5), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(135), 12,
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
  [117] = 14,
    ACTIONS(53), 1,
      sym_BAREWORD,
    ACTIONS(57), 1,
      anon_sym_rand,
    ACTIONS(59), 1,
      sym_action_return_statement,
    ACTIONS(61), 1,
      anon_sym_close,
    ACTIONS(63), 1,
      anon_sym_save,
    ACTIONS(65), 1,
      anon_sym_load,
    ACTIONS(67), 1,
      anon_sym_erase,
    ACTIONS(69), 1,
      anon_sym_goto,
    ACTIONS(71), 1,
      anon_sym_wait,
    ACTIONS(73), 1,
      anon_sym_block,
    ACTIONS(75), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(6), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(135), 12,
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
  [175] = 14,
    ACTIONS(53), 1,
      sym_BAREWORD,
    ACTIONS(57), 1,
      anon_sym_rand,
    ACTIONS(59), 1,
      sym_action_return_statement,
    ACTIONS(61), 1,
      anon_sym_close,
    ACTIONS(63), 1,
      anon_sym_save,
    ACTIONS(65), 1,
      anon_sym_load,
    ACTIONS(67), 1,
      anon_sym_erase,
    ACTIONS(69), 1,
      anon_sym_goto,
    ACTIONS(71), 1,
      anon_sym_wait,
    ACTIONS(73), 1,
      anon_sym_block,
    ACTIONS(77), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(135), 12,
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
  [233] = 14,
    ACTIONS(53), 1,
      sym_BAREWORD,
    ACTIONS(57), 1,
      anon_sym_rand,
    ACTIONS(59), 1,
      sym_action_return_statement,
    ACTIONS(61), 1,
      anon_sym_close,
    ACTIONS(63), 1,
      anon_sym_save,
    ACTIONS(65), 1,
      anon_sym_load,
    ACTIONS(67), 1,
      anon_sym_erase,
    ACTIONS(69), 1,
      anon_sym_goto,
    ACTIONS(71), 1,
      anon_sym_wait,
    ACTIONS(73), 1,
      anon_sym_block,
    ACTIONS(79), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(135), 12,
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
  [291] = 10,
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
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(8), 7,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [329] = 10,
    ACTIONS(83), 1,
      ts_builtin_sym_end,
    ACTIONS(85), 1,
      sym_BAREWORD,
    ACTIONS(88), 1,
      sym_QUOTED_STRING,
    ACTIONS(91), 1,
      sym_CONSTANT,
    ACTIONS(94), 1,
      anon_sym_include,
    ACTIONS(97), 1,
      anon_sym_add,
    ACTIONS(100), 1,
      anon_sym_serial_dialog,
    ACTIONS(103), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(8), 7,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      sym_serial_dialog_definition,
      sym_script_definition,
      aux_sym_document_repeat1,
  [367] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(108), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(106), 10,
      sym_BAREWORD,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [388] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(112), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(110), 10,
      sym_BAREWORD,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [409] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(116), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(114), 10,
      sym_BAREWORD,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [430] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(120), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(118), 10,
      sym_BAREWORD,
      anon_sym_rand,
      sym_action_return_statement,
      anon_sym_close,
      anon_sym_save,
      anon_sym_load,
      anon_sym_erase,
      anon_sym_goto,
      anon_sym_wait,
      anon_sym_block,
  [451] = 6,
    ACTIONS(126), 1,
      sym_NUMBER,
    ACTIONS(128), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(122), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(124), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(150), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [476] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(130), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(132), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [493] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(134), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(136), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [510] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(138), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(140), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [527] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(142), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(144), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [544] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(146), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(148), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [561] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(150), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(152), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [578] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(154), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(156), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [595] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(158), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(160), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [612] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(162), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(164), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [629] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(166), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(168), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [646] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(170), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(172), 5,
      sym_BAREWORD,
      anon_sym_include,
      anon_sym_add,
      anon_sym_serial_dialog,
      anon_sym_script,
  [663] = 8,
    ACTIONS(174), 1,
      sym_QUOTED_STRING,
    ACTIONS(176), 1,
      anon_sym_RBRACE,
    ACTIONS(178), 1,
      sym_serial_dialog_parameter_int,
    STATE(28), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(31), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(98), 1,
      sym_serial_dialog_parameter,
    STATE(125), 1,
      sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [689] = 7,
    ACTIONS(180), 1,
      sym_BAREWORD,
    ACTIONS(182), 1,
      anon_sym_LBRACK,
    ACTIONS(186), 1,
      anon_sym_label,
    ACTIONS(188), 1,
      anon_sym_index,
    STATE(121), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(184), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [713] = 7,
    ACTIONS(174), 1,
      sym_QUOTED_STRING,
    ACTIONS(190), 1,
      anon_sym_RBRACE,
    ACTIONS(192), 1,
      sym_serial_dialog_option_type,
    STATE(43), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(49), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(90), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [736] = 7,
    ACTIONS(174), 1,
      sym_QUOTED_STRING,
    ACTIONS(192), 1,
      sym_serial_dialog_option_type,
    ACTIONS(194), 1,
      anon_sym_RBRACE,
    STATE(43), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(44), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(90), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [759] = 4,
    ACTIONS(182), 1,
      anon_sym_LBRACK,
    STATE(136), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(196), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [775] = 5,
    ACTIONS(198), 1,
      anon_sym_LBRACK,
    ACTIONS(200), 1,
      sym_NUMBER,
    ACTIONS(202), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(124), 2,
      sym_DURATION,
      sym_duration_expansion,
  [793] = 6,
    ACTIONS(174), 1,
      sym_QUOTED_STRING,
    ACTIONS(178), 1,
      sym_serial_dialog_parameter_int,
    STATE(27), 1,
      aux_sym_serial_dialog_repeat2,
    STATE(41), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(98), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [813] = 5,
    ACTIONS(198), 1,
      anon_sym_LBRACK,
    ACTIONS(200), 1,
      sym_NUMBER,
    ACTIONS(204), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(130), 2,
      sym_DURATION,
      sym_duration_expansion,
  [831] = 4,
    ACTIONS(206), 1,
      anon_sym_LBRACK,
    STATE(137), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(208), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [846] = 4,
    ACTIONS(178), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(210), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(39), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [861] = 4,
    ACTIONS(206), 1,
      anon_sym_LBRACK,
    STATE(146), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(212), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [876] = 3,
    ACTIONS(216), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(214), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [889] = 4,
    ACTIONS(206), 1,
      anon_sym_LBRACK,
    STATE(133), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(218), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [904] = 4,
    ACTIONS(220), 1,
      anon_sym_LBRACK,
    STATE(105), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(222), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [919] = 4,
    ACTIONS(178), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(224), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(48), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [934] = 3,
    ACTIONS(228), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(226), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [947] = 5,
    ACTIONS(230), 1,
      sym_QUOTED_STRING,
    ACTIONS(232), 1,
      sym_serial_dialog_parameter_int,
    STATE(41), 1,
      aux_sym_serial_dialog_repeat1,
    STATE(98), 1,
      sym_serial_dialog_parameter,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [964] = 4,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    STATE(143), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(235), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [979] = 4,
    ACTIONS(239), 1,
      sym_QUOTED_STRING,
    STATE(43), 1,
      aux_sym_serial_dialog_repeat2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(242), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [994] = 5,
    ACTIONS(192), 1,
      sym_serial_dialog_option_type,
    ACTIONS(244), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(90), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1011] = 5,
    ACTIONS(216), 1,
      sym_duration_suffix,
    ACTIONS(246), 1,
      sym_distance_suffix,
    ACTIONS(248), 1,
      sym_quantity_suffix,
    ACTIONS(250), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1028] = 3,
    ACTIONS(254), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(252), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1041] = 5,
    ACTIONS(200), 1,
      sym_NUMBER,
    ACTIONS(256), 1,
      anon_sym_RBRACK,
    ACTIONS(258), 1,
      sym_CONSTANT,
    STATE(99), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1058] = 4,
    ACTIONS(260), 1,
      anon_sym_RBRACE,
    ACTIONS(262), 1,
      sym_serial_dialog_parameter_int,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(48), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [1073] = 5,
    ACTIONS(192), 1,
      sym_serial_dialog_option_type,
    ACTIONS(265), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(90), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1090] = 5,
    ACTIONS(267), 1,
      anon_sym_RBRACE,
    ACTIONS(269), 1,
      sym_serial_dialog_option_type,
    STATE(50), 1,
      aux_sym_serial_dialog_repeat3,
    STATE(90), 1,
      sym_serial_dialog_option,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1107] = 3,
    ACTIONS(272), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(252), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1120] = 5,
    ACTIONS(200), 1,
      sym_NUMBER,
    ACTIONS(258), 1,
      sym_CONSTANT,
    ACTIONS(274), 1,
      anon_sym_RBRACK,
    STATE(99), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1137] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(276), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1147] = 3,
    ACTIONS(278), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(280), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1159] = 3,
    ACTIONS(282), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(284), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1171] = 4,
    ACTIONS(286), 1,
      anon_sym_COMMA,
    ACTIONS(289), 1,
      anon_sym_RBRACK,
    STATE(56), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1185] = 4,
    ACTIONS(291), 1,
      anon_sym_COMMA,
    ACTIONS(293), 1,
      anon_sym_RBRACK,
    STATE(69), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1199] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(295), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1209] = 4,
    ACTIONS(254), 1,
      anon_sym_RBRACK,
    ACTIONS(297), 1,
      anon_sym_COMMA,
    STATE(71), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1223] = 4,
    ACTIONS(299), 1,
      anon_sym_COMMA,
    ACTIONS(301), 1,
      anon_sym_RBRACK,
    STATE(73), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1237] = 4,
    ACTIONS(200), 1,
      sym_NUMBER,
    ACTIONS(303), 1,
      sym_CONSTANT,
    STATE(74), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1251] = 4,
    ACTIONS(256), 1,
      anon_sym_RBRACK,
    ACTIONS(305), 1,
      anon_sym_COMMA,
    STATE(75), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1265] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(307), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [1275] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(309), 3,
      sym_QUOTED_STRING,
      anon_sym_RBRACE,
      sym_serial_dialog_parameter_int,
  [1285] = 3,
    ACTIONS(311), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(313), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1297] = 4,
    ACTIONS(315), 1,
      anon_sym_COMMA,
    ACTIONS(317), 1,
      anon_sym_RBRACK,
    STATE(59), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1311] = 4,
    ACTIONS(319), 1,
      anon_sym_COMMA,
    ACTIONS(321), 1,
      anon_sym_RBRACK,
    STATE(76), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1325] = 3,
    ACTIONS(323), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(325), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1337] = 4,
    ACTIONS(323), 1,
      anon_sym_RBRACK,
    ACTIONS(327), 1,
      anon_sym_COMMA,
    STATE(78), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1351] = 3,
    ACTIONS(331), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(329), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1363] = 4,
    ACTIONS(333), 1,
      anon_sym_COMMA,
    ACTIONS(336), 1,
      anon_sym_RBRACK,
    STATE(71), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1377] = 3,
    ACTIONS(340), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(338), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1389] = 4,
    ACTIONS(340), 1,
      anon_sym_RBRACK,
    ACTIONS(342), 1,
      anon_sym_COMMA,
    STATE(81), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1403] = 4,
    ACTIONS(344), 1,
      anon_sym_COMMA,
    ACTIONS(346), 1,
      anon_sym_RBRACK,
    STATE(62), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1417] = 4,
    ACTIONS(348), 1,
      anon_sym_COMMA,
    ACTIONS(351), 1,
      anon_sym_RBRACK,
    STATE(75), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1431] = 4,
    ACTIONS(353), 1,
      anon_sym_COMMA,
    ACTIONS(355), 1,
      anon_sym_RBRACK,
    STATE(56), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1445] = 3,
    ACTIONS(357), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(325), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1457] = 4,
    ACTIONS(359), 1,
      anon_sym_COMMA,
    ACTIONS(362), 1,
      anon_sym_RBRACK,
    STATE(78), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1471] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(252), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1481] = 3,
    ACTIONS(364), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(338), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1493] = 4,
    ACTIONS(366), 1,
      anon_sym_COMMA,
    ACTIONS(369), 1,
      anon_sym_RBRACK,
    STATE(81), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1507] = 4,
    ACTIONS(200), 1,
      sym_NUMBER,
    ACTIONS(258), 1,
      sym_CONSTANT,
    STATE(99), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1521] = 3,
    ACTIONS(355), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(280), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1533] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(371), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1542] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(338), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1551] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(289), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1560] = 3,
    ACTIONS(373), 1,
      anon_sym_serial_dialog,
    ACTIONS(375), 1,
      anon_sym_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1571] = 3,
    ACTIONS(377), 1,
      anon_sym_slot,
    ACTIONS(379), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1582] = 3,
    ACTIONS(381), 1,
      anon_sym_LBRACE,
    STATE(15), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1593] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(383), 2,
      anon_sym_RBRACE,
      sym_serial_dialog_option_type,
  [1602] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(385), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1611] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(387), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1620] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(280), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [1629] = 3,
    ACTIONS(389), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym__serial_dialog_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1640] = 3,
    ACTIONS(381), 1,
      anon_sym_LBRACE,
    STATE(17), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1651] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(391), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1660] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(336), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1669] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(393), 2,
      sym_QUOTED_STRING,
      sym_serial_dialog_parameter_int,
  [1678] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(351), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1687] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(362), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1696] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(369), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1705] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(325), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1714] = 2,
    ACTIONS(395), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1722] = 2,
    ACTIONS(397), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1730] = 2,
    ACTIONS(399), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1738] = 2,
    ACTIONS(401), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1746] = 2,
    ACTIONS(403), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1754] = 2,
    ACTIONS(405), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1762] = 2,
    ACTIONS(407), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1770] = 2,
    ACTIONS(409), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1778] = 2,
    ACTIONS(411), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1786] = 2,
    ACTIONS(413), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1794] = 2,
    ACTIONS(415), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1802] = 2,
    ACTIONS(417), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1810] = 2,
    ACTIONS(419), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1818] = 2,
    ACTIONS(421), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1826] = 2,
    ACTIONS(423), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1834] = 2,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1842] = 2,
    ACTIONS(427), 1,
      sym_QUOTED_STRING,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1850] = 2,
    ACTIONS(429), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1858] = 2,
    ACTIONS(431), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1866] = 2,
    ACTIONS(433), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1874] = 2,
    ACTIONS(435), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1882] = 2,
    ACTIONS(437), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1890] = 2,
    ACTIONS(439), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1898] = 2,
    ACTIONS(441), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1906] = 2,
    ACTIONS(443), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1914] = 2,
    ACTIONS(445), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1922] = 2,
    ACTIONS(447), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1930] = 2,
    ACTIONS(449), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1938] = 2,
    ACTIONS(451), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1946] = 2,
    ACTIONS(453), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1954] = 2,
    ACTIONS(455), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1962] = 2,
    ACTIONS(457), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1970] = 2,
    ACTIONS(459), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1978] = 2,
    ACTIONS(461), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1986] = 2,
    ACTIONS(463), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1994] = 2,
    ACTIONS(465), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2002] = 2,
    ACTIONS(467), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2010] = 2,
    ACTIONS(469), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2018] = 2,
    ACTIONS(471), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2026] = 2,
    ACTIONS(473), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2034] = 2,
    ACTIONS(475), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2042] = 2,
    ACTIONS(477), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2050] = 2,
    ACTIONS(479), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2058] = 2,
    ACTIONS(481), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2066] = 2,
    ACTIONS(483), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2074] = 2,
    ACTIONS(485), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2082] = 2,
    ACTIONS(487), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2090] = 2,
    ACTIONS(250), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [2098] = 2,
    ACTIONS(489), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 59,
  [SMALL_STATE(4)] = 117,
  [SMALL_STATE(5)] = 175,
  [SMALL_STATE(6)] = 233,
  [SMALL_STATE(7)] = 291,
  [SMALL_STATE(8)] = 329,
  [SMALL_STATE(9)] = 367,
  [SMALL_STATE(10)] = 388,
  [SMALL_STATE(11)] = 409,
  [SMALL_STATE(12)] = 430,
  [SMALL_STATE(13)] = 451,
  [SMALL_STATE(14)] = 476,
  [SMALL_STATE(15)] = 493,
  [SMALL_STATE(16)] = 510,
  [SMALL_STATE(17)] = 527,
  [SMALL_STATE(18)] = 544,
  [SMALL_STATE(19)] = 561,
  [SMALL_STATE(20)] = 578,
  [SMALL_STATE(21)] = 595,
  [SMALL_STATE(22)] = 612,
  [SMALL_STATE(23)] = 629,
  [SMALL_STATE(24)] = 646,
  [SMALL_STATE(25)] = 663,
  [SMALL_STATE(26)] = 689,
  [SMALL_STATE(27)] = 713,
  [SMALL_STATE(28)] = 736,
  [SMALL_STATE(29)] = 759,
  [SMALL_STATE(30)] = 775,
  [SMALL_STATE(31)] = 793,
  [SMALL_STATE(32)] = 813,
  [SMALL_STATE(33)] = 831,
  [SMALL_STATE(34)] = 846,
  [SMALL_STATE(35)] = 861,
  [SMALL_STATE(36)] = 876,
  [SMALL_STATE(37)] = 889,
  [SMALL_STATE(38)] = 904,
  [SMALL_STATE(39)] = 919,
  [SMALL_STATE(40)] = 934,
  [SMALL_STATE(41)] = 947,
  [SMALL_STATE(42)] = 964,
  [SMALL_STATE(43)] = 979,
  [SMALL_STATE(44)] = 994,
  [SMALL_STATE(45)] = 1011,
  [SMALL_STATE(46)] = 1028,
  [SMALL_STATE(47)] = 1041,
  [SMALL_STATE(48)] = 1058,
  [SMALL_STATE(49)] = 1073,
  [SMALL_STATE(50)] = 1090,
  [SMALL_STATE(51)] = 1107,
  [SMALL_STATE(52)] = 1120,
  [SMALL_STATE(53)] = 1137,
  [SMALL_STATE(54)] = 1147,
  [SMALL_STATE(55)] = 1159,
  [SMALL_STATE(56)] = 1171,
  [SMALL_STATE(57)] = 1185,
  [SMALL_STATE(58)] = 1199,
  [SMALL_STATE(59)] = 1209,
  [SMALL_STATE(60)] = 1223,
  [SMALL_STATE(61)] = 1237,
  [SMALL_STATE(62)] = 1251,
  [SMALL_STATE(63)] = 1265,
  [SMALL_STATE(64)] = 1275,
  [SMALL_STATE(65)] = 1285,
  [SMALL_STATE(66)] = 1297,
  [SMALL_STATE(67)] = 1311,
  [SMALL_STATE(68)] = 1325,
  [SMALL_STATE(69)] = 1337,
  [SMALL_STATE(70)] = 1351,
  [SMALL_STATE(71)] = 1363,
  [SMALL_STATE(72)] = 1377,
  [SMALL_STATE(73)] = 1389,
  [SMALL_STATE(74)] = 1403,
  [SMALL_STATE(75)] = 1417,
  [SMALL_STATE(76)] = 1431,
  [SMALL_STATE(77)] = 1445,
  [SMALL_STATE(78)] = 1457,
  [SMALL_STATE(79)] = 1471,
  [SMALL_STATE(80)] = 1481,
  [SMALL_STATE(81)] = 1493,
  [SMALL_STATE(82)] = 1507,
  [SMALL_STATE(83)] = 1521,
  [SMALL_STATE(84)] = 1533,
  [SMALL_STATE(85)] = 1542,
  [SMALL_STATE(86)] = 1551,
  [SMALL_STATE(87)] = 1560,
  [SMALL_STATE(88)] = 1571,
  [SMALL_STATE(89)] = 1582,
  [SMALL_STATE(90)] = 1593,
  [SMALL_STATE(91)] = 1602,
  [SMALL_STATE(92)] = 1611,
  [SMALL_STATE(93)] = 1620,
  [SMALL_STATE(94)] = 1629,
  [SMALL_STATE(95)] = 1640,
  [SMALL_STATE(96)] = 1651,
  [SMALL_STATE(97)] = 1660,
  [SMALL_STATE(98)] = 1669,
  [SMALL_STATE(99)] = 1678,
  [SMALL_STATE(100)] = 1687,
  [SMALL_STATE(101)] = 1696,
  [SMALL_STATE(102)] = 1705,
  [SMALL_STATE(103)] = 1714,
  [SMALL_STATE(104)] = 1722,
  [SMALL_STATE(105)] = 1730,
  [SMALL_STATE(106)] = 1738,
  [SMALL_STATE(107)] = 1746,
  [SMALL_STATE(108)] = 1754,
  [SMALL_STATE(109)] = 1762,
  [SMALL_STATE(110)] = 1770,
  [SMALL_STATE(111)] = 1778,
  [SMALL_STATE(112)] = 1786,
  [SMALL_STATE(113)] = 1794,
  [SMALL_STATE(114)] = 1802,
  [SMALL_STATE(115)] = 1810,
  [SMALL_STATE(116)] = 1818,
  [SMALL_STATE(117)] = 1826,
  [SMALL_STATE(118)] = 1834,
  [SMALL_STATE(119)] = 1842,
  [SMALL_STATE(120)] = 1850,
  [SMALL_STATE(121)] = 1858,
  [SMALL_STATE(122)] = 1866,
  [SMALL_STATE(123)] = 1874,
  [SMALL_STATE(124)] = 1882,
  [SMALL_STATE(125)] = 1890,
  [SMALL_STATE(126)] = 1898,
  [SMALL_STATE(127)] = 1906,
  [SMALL_STATE(128)] = 1914,
  [SMALL_STATE(129)] = 1922,
  [SMALL_STATE(130)] = 1930,
  [SMALL_STATE(131)] = 1938,
  [SMALL_STATE(132)] = 1946,
  [SMALL_STATE(133)] = 1954,
  [SMALL_STATE(134)] = 1962,
  [SMALL_STATE(135)] = 1970,
  [SMALL_STATE(136)] = 1978,
  [SMALL_STATE(137)] = 1986,
  [SMALL_STATE(138)] = 1994,
  [SMALL_STATE(139)] = 2002,
  [SMALL_STATE(140)] = 2010,
  [SMALL_STATE(141)] = 2018,
  [SMALL_STATE(142)] = 2026,
  [SMALL_STATE(143)] = 2034,
  [SMALL_STATE(144)] = 2042,
  [SMALL_STATE(145)] = 2050,
  [SMALL_STATE(146)] = 2058,
  [SMALL_STATE(147)] = 2066,
  [SMALL_STATE(148)] = 2074,
  [SMALL_STATE(149)] = 2082,
  [SMALL_STATE(150)] = 2090,
  [SMALL_STATE(151)] = 2098,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(128),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(87),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(112),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(88),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(148),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(131),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [97] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [100] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [103] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 5),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 5),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(150),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_serial_dialog_definition, 3, 0, 3),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 4),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 4),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 8),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 2, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__serial_dialog_block, 3, 0, 18),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__serial_dialog_block, 3, 0, 18),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 2),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_macro, 3, 0, 2),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [186] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 20),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 1, 0, 12),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 19),
  [232] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 2, 0, 19), SHIFT_REPEAT(96),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [239] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 22), SHIFT_REPEAT(58),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 2, 0, 22),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 2, 0, 23),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [262] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog, 3, 0, 24),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 25),
  [269] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 2, 0, 25), SHIFT_REPEAT(119),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [286] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat2, 1, 0, 10),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 9),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 17),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [333] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [348] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(82),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [359] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(102),
  [362] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [366] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(85),
  [369] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_option, 4, 0, 26),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [383] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat3, 1, 0, 21),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [393] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_serial_dialog_repeat1, 1, 0, 11),
  [395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [405] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 9),
  [407] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 9),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [415] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [417] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [429] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [431] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 6),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [437] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 7),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [441] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [443] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [447] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [449] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 7),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [455] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 13),
  [457] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [461] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 14),
  [463] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 13),
  [465] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [467] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [469] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [471] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [473] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [475] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 15),
  [477] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [479] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [481] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 16),
  [483] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
  [485] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [487] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [489] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
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
