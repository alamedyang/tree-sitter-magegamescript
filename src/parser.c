#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 105
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 73
#define ALIAS_COUNT 0
#define TOKEN_COUNT 40
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 9
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 12

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
  anon_sym_EQ = 16,
  anon_sym_SEMI = 17,
  anon_sym_script = 18,
  anon_sym_LBRACE = 19,
  anon_sym_RBRACE = 20,
  anon_sym_rand = 21,
  anon_sym_BANG = 22,
  anon_sym_LPAREN = 23,
  anon_sym_RPAREN = 24,
  anon_sym_COLON = 25,
  sym_action_return_statement = 26,
  anon_sym_close = 27,
  anon_sym_dialog = 28,
  anon_sym_serial_dialog = 29,
  anon_sym_save = 30,
  anon_sym_slot = 31,
  anon_sym_load = 32,
  anon_sym_erase = 33,
  anon_sym_map = 34,
  anon_sym_goto = 35,
  anon_sym_label = 36,
  anon_sym_index = 37,
  anon_sym_wait = 38,
  anon_sym_block = 39,
  sym_document = 40,
  sym_bareword_expansion = 41,
  sym_string_expansion = 42,
  sym_number_expansion = 43,
  sym_DURATION = 44,
  sym_duration_expansion = 45,
  sym_DISTANCE = 46,
  sym_QUANTITY = 47,
  sym__root = 48,
  sym_constant_assignment = 49,
  sym_script_definition = 50,
  sym_script_block = 51,
  sym__script_item = 52,
  sym_rand_macro = 53,
  sym_label = 54,
  sym__action_item = 55,
  sym_action_close_dialog = 56,
  sym_action_close_serial_dialog = 57,
  sym_action_save_slot = 58,
  sym_action_load_slot = 59,
  sym_action_erase_slot = 60,
  sym_action_load_map = 61,
  sym_action_run_script = 62,
  sym_action_goto_label = 63,
  sym_action_goto_index = 64,
  sym_action_non_blocking_delay = 65,
  sym_action_blocking_delay = 66,
  aux_sym_document_repeat1 = 67,
  aux_sym_bareword_expansion_repeat1 = 68,
  aux_sym_string_expansion_repeat1 = 69,
  aux_sym_number_expansion_repeat1 = 70,
  aux_sym_duration_expansion_repeat1 = 71,
  aux_sym_script_block_repeat1 = 72,
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
  [anon_sym_EQ] = "=",
  [anon_sym_SEMI] = ";",
  [anon_sym_script] = "script",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_rand] = "rand",
  [anon_sym_BANG] = "!",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [sym_action_return_statement] = "action_return_statement",
  [anon_sym_close] = "close",
  [anon_sym_dialog] = "dialog",
  [anon_sym_serial_dialog] = "serial_dialog",
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
  [sym_string_expansion] = "string_expansion",
  [sym_number_expansion] = "number_expansion",
  [sym_DURATION] = "DURATION",
  [sym_duration_expansion] = "duration_expansion",
  [sym_DISTANCE] = "DISTANCE",
  [sym_QUANTITY] = "QUANTITY",
  [sym__root] = "_root",
  [sym_constant_assignment] = "constant_assignment",
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
  [aux_sym_string_expansion_repeat1] = "string_expansion_repeat1",
  [aux_sym_number_expansion_repeat1] = "number_expansion_repeat1",
  [aux_sym_duration_expansion_repeat1] = "duration_expansion_repeat1",
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
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_script] = anon_sym_script,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_rand] = anon_sym_rand,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_action_return_statement] = sym_action_return_statement,
  [anon_sym_close] = anon_sym_close,
  [anon_sym_dialog] = anon_sym_dialog,
  [anon_sym_serial_dialog] = anon_sym_serial_dialog,
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
  [sym_string_expansion] = sym_string_expansion,
  [sym_number_expansion] = sym_number_expansion,
  [sym_DURATION] = sym_DURATION,
  [sym_duration_expansion] = sym_duration_expansion,
  [sym_DISTANCE] = sym_DISTANCE,
  [sym_QUANTITY] = sym_QUANTITY,
  [sym__root] = sym__root,
  [sym_constant_assignment] = sym_constant_assignment,
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
  [aux_sym_string_expansion_repeat1] = aux_sym_string_expansion_repeat1,
  [aux_sym_number_expansion_repeat1] = aux_sym_number_expansion_repeat1,
  [aux_sym_duration_expansion_repeat1] = aux_sym_duration_expansion_repeat1,
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
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_script] = {
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
  [anon_sym_serial_dialog] = {
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
  [sym_constant_assignment] = {
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
  [aux_sym_script_block_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_duration = 1,
  field_index = 2,
  field_label = 3,
  field_map = 4,
  field_script = 5,
  field_script_name = 6,
  field_slot = 7,
  field_suffix = 8,
  field_value = 9,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_duration] = "duration",
  [field_index] = "index",
  [field_label] = "label",
  [field_map] = "map",
  [field_script] = "script",
  [field_script_name] = "script_name",
  [field_slot] = "slot",
  [field_suffix] = "suffix",
  [field_value] = "value",
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
  [10] = {.index = 10, .length = 1},
  [11] = {.index = 11, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_script_name, 0},
  [1] =
    {field_script_name, 1},
  [2] =
    {field_label, 0},
  [3] =
    {field_script, 1},
  [4] =
    {field_duration, 1},
  [5] =
    {field_label, 0},
    {field_value, 2},
  [7] =
    {field_suffix, 1},
  [8] =
    {field_slot, 2},
  [9] =
    {field_map, 2},
  [10] =
    {field_label, 2},
  [11] =
    {field_index, 2},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(112);
      ADVANCE_MAP(
        '!', 230,
        '"', 4,
        '#', 107,
        '$', 108,
        '(', 231,
        ')', 232,
        ',', 208,
        '/', 6,
        ':', 233,
        ';', 223,
        '=', 222,
        '[', 207,
        ']', 209,
        'b', 63,
        'c', 64,
        'd', 56,
        'e', 87,
        'g', 77,
        'i', 71,
        'l', 13,
        'm', 15,
        'o', 72,
        'p', 54,
        'r', 25,
        's', 213,
        't', 52,
        'w', 22,
        'x', 215,
        'y', 42,
        '{', 226,
        '}', 227,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(110);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(211);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 4,
        '#', 107,
        '$', 108,
        '/', 6,
        'b', 164,
        'c', 169,
        'f', 125,
        'g', 190,
        'm', 121,
        'o', 153,
        'r', 146,
        't', 156,
        'w', 157,
        'y', 147,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(211);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(4);
      if (lookahead == '$') ADVANCE(108);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == '[') ADVANCE(207);
      if (lookahead == ']') ADVANCE(209);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(4);
      if (lookahead == '$') ADVANCE(108);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == '[') ADVANCE(207);
      if (lookahead == 'i') ADVANCE(176);
      if (lookahead == 'l') ADVANCE(122);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(210);
      if (lookahead == '\\') ADVANCE(109);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      ADVANCE_MAP(
        ')', 232,
        '/', 6,
        'b', 166,
        'c', 167,
        'e', 189,
        'g', 182,
        'l', 183,
        'r', 118,
        's', 119,
        'w', 123,
        '}', 227,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(8);
      if (lookahead == '/') ADVANCE(114);
      END_STATE();
    case 7:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(113);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 8:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 9:
      ADVANCE_MAP(
        ',', 208,
        '/', 6,
        ';', 223,
        ']', 209,
        'm', 91,
        'p', 54,
        's', 212,
        'x', 215,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      END_STATE();
    case 10:
      if (lookahead == ',') ADVANCE(208);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == ';') ADVANCE(223);
      if (lookahead == ']') ADVANCE(209);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10);
      END_STATE();
    case 11:
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == 'd') ADVANCE(56);
      if (lookahead == 'm') ADVANCE(20);
      if (lookahead == 's') ADVANCE(44);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      if (lookahead == '_') ADVANCE(36);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(28);
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(51);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(51);
      if (lookahead == 's') ADVANCE(212);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(101);
      if (lookahead == 'c') ADVANCE(88);
      if (lookahead == 'e') ADVANCE(90);
      if (lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(217);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(33);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(29);
      if (lookahead == 'o') ADVANCE(30);
      if (lookahead == 'u') ADVANCE(37);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(84);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(67);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(57);
      if (lookahead == 'h') ADVANCE(58);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(73);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(66);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(75);
      if (lookahead == 'e') ADVANCE(32);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(93);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(69);
      END_STATE();
    case 28:
      if (lookahead == 'b') ADVANCE(46);
      END_STATE();
    case 29:
      if (lookahead == 'c') ADVANCE(61);
      END_STATE();
    case 30:
      if (lookahead == 'c') ADVANCE(62);
      END_STATE();
    case 31:
      if (lookahead == 'c') ADVANCE(38);
      END_STATE();
    case 32:
      if (lookahead == 'd') ADVANCE(217);
      if (lookahead == 't') ADVANCE(100);
      END_STATE();
    case 33:
      if (lookahead == 'd') ADVANCE(243);
      END_STATE();
    case 34:
      if (lookahead == 'd') ADVANCE(228);
      END_STATE();
    case 35:
      if (lookahead == 'd') ADVANCE(43);
      END_STATE();
    case 36:
      if (lookahead == 'd') ADVANCE(60);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(217);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(216);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(240);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(236);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(245);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(104);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(90);
      if (lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(73);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(45);
      END_STATE();
    case 49:
      if (lookahead == 'g') ADVANCE(238);
      END_STATE();
    case 50:
      if (lookahead == 'g') ADVANCE(239);
      END_STATE();
    case 51:
      if (lookahead == 'g') ADVANCE(47);
      if (lookahead == 'p') ADVANCE(247);
      END_STATE();
    case 52:
      if (lookahead == 'h') ADVANCE(86);
      if (lookahead == 'w') ADVANCE(53);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(103);
      if (lookahead == 'x') ADVANCE(214);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(85);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(21);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(95);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(97);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(24);
      END_STATE();
    case 60:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 61:
      if (lookahead == 'k') ADVANCE(217);
      END_STATE();
    case 62:
      if (lookahead == 'k') ADVANCE(256);
      END_STATE();
    case 63:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 64:
      if (lookahead == 'l') ADVANCE(78);
      if (lookahead == 'y') ADVANCE(23);
      END_STATE();
    case 65:
      if (lookahead == 'l') ADVANCE(250);
      END_STATE();
    case 66:
      if (lookahead == 'l') ADVANCE(12);
      END_STATE();
    case 67:
      if (lookahead == 'l') ADVANCE(80);
      END_STATE();
    case 68:
      if (lookahead == 'l') ADVANCE(81);
      END_STATE();
    case 69:
      if (lookahead == 'l') ADVANCE(83);
      END_STATE();
    case 70:
      if (lookahead == 'l') ADVANCE(68);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(35);
      END_STATE();
    case 72:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 73:
      if (lookahead == 'n') ADVANCE(217);
      END_STATE();
    case 74:
      if (lookahead == 'n') ADVANCE(234);
      END_STATE();
    case 75:
      if (lookahead == 'n') ADVANCE(34);
      END_STATE();
    case 76:
      if (lookahead == 'n') ADVANCE(99);
      END_STATE();
    case 77:
      if (lookahead == 'o') ADVANCE(98);
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 78:
      if (lookahead == 'o') ADVANCE(92);
      END_STATE();
    case 79:
      if (lookahead == 'o') ADVANCE(248);
      END_STATE();
    case 80:
      if (lookahead == 'o') ADVANCE(49);
      END_STATE();
    case 81:
      if (lookahead == 'o') ADVANCE(102);
      END_STATE();
    case 82:
      if (lookahead == 'o') ADVANCE(94);
      END_STATE();
    case 83:
      if (lookahead == 'o') ADVANCE(50);
      END_STATE();
    case 84:
      if (lookahead == 'p') ADVANCE(247);
      END_STATE();
    case 85:
      if (lookahead == 'p') ADVANCE(96);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 87:
      if (lookahead == 'r') ADVANCE(26);
      END_STATE();
    case 88:
      if (lookahead == 'r') ADVANCE(55);
      END_STATE();
    case 89:
      if (lookahead == 'r') ADVANCE(74);
      END_STATE();
    case 90:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(212);
      END_STATE();
    case 92:
      if (lookahead == 's') ADVANCE(40);
      END_STATE();
    case 93:
      if (lookahead == 's') ADVANCE(41);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(242);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(254);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(224);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(79);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(17);
      END_STATE();
    case 100:
      if (lookahead == 'u') ADVANCE(89);
      END_STATE();
    case 101:
      if (lookahead == 'v') ADVANCE(39);
      END_STATE();
    case 102:
      if (lookahead == 'w') ADVANCE(217);
      END_STATE();
    case 103:
      if (lookahead == 'x') ADVANCE(214);
      END_STATE();
    case 104:
      if (lookahead == 'x') ADVANCE(252);
      END_STATE();
    case 105:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(220);
      END_STATE();
    case 106:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(105);
      END_STATE();
    case 107:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(106);
      END_STATE();
    case 108:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 109:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 110:
      if (eof) ADVANCE(112);
      ADVANCE_MAP(
        '!', 230,
        '"', 4,
        '#', 107,
        '$', 108,
        '(', 231,
        ')', 232,
        ',', 208,
        '/', 6,
        ':', 233,
        ';', 223,
        '=', 222,
        '[', 207,
        ']', 209,
        'b', 63,
        'c', 64,
        'd', 56,
        'e', 87,
        'g', 77,
        'i', 71,
        'l', 13,
        'm', 14,
        'o', 72,
        'r', 25,
        's', 16,
        't', 52,
        'w', 22,
        'y', 42,
        '{', 226,
        '}', 227,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(110);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(211);
      END_STATE();
    case 111:
      if (eof) ADVANCE(112);
      if (lookahead == '"') ADVANCE(4);
      if (lookahead == '$') ADVANCE(108);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead == 's') ADVANCE(129);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(111);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(114);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(114);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(175);
      if (lookahead == 'e') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(160);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(131);
      if (lookahead == 'u') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(162);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(244);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(170);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(174);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(165);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(154);
      if (lookahead == 'n') ADVANCE(115);
      if (lookahead == 'p') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(188);
      if (lookahead == 'r') ADVANCE(202);
      if (lookahead == 'w') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(200);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(181);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(184);
      if (lookahead == 'y') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(193);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(199);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(159);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'v') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_NUMBER);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(211);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_duration_suffix);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_duration_suffix);
      if (lookahead == 'a') ADVANCE(101);
      if (lookahead == 'c') ADVANCE(88);
      if (lookahead == 'e') ADVANCE(90);
      if (lookahead == 'l') ADVANCE(82);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_distance_suffix);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_quantity_suffix);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_QUANTITY_token1);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(217);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(218);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F')) ADVANCE(219);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(221);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_rand);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_action_return_statement);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_action_return_statement);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_close);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_save);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_save);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_slot);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(anon_sym_load);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(anon_sym_erase);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(anon_sym_erase);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(anon_sym_goto);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(anon_sym_wait);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(anon_sym_block);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(206);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 111},
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 5},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 5},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 111},
  [13] = {.lex_state = 111},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 111},
  [16] = {.lex_state = 111},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 111},
  [20] = {.lex_state = 111},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 111},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 9},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 9},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 2},
  [60] = {.lex_state = 11},
  [61] = {.lex_state = 11},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 11},
  [91] = {.lex_state = 11},
  [92] = {.lex_state = 0},
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
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_script] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_rand] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [sym_action_return_statement] = ACTIONS(1),
    [anon_sym_close] = ACTIONS(1),
    [anon_sym_dialog] = ACTIONS(1),
    [anon_sym_serial_dialog] = ACTIONS(1),
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
    [sym_document] = STATE(68),
    [sym__root] = STATE(13),
    [sym_constant_assignment] = STATE(13),
    [sym_script_definition] = STATE(13),
    [aux_sym_document_repeat1] = STATE(13),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_BAREWORD] = ACTIONS(7),
    [sym_QUOTED_STRING] = ACTIONS(9),
    [sym_CONSTANT] = ACTIONS(11),
    [anon_sym_script] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 14,
    ACTIONS(15), 1,
      sym_BAREWORD,
    ACTIONS(20), 1,
      anon_sym_rand,
    ACTIONS(23), 1,
      sym_action_return_statement,
    ACTIONS(26), 1,
      anon_sym_close,
    ACTIONS(29), 1,
      anon_sym_save,
    ACTIONS(32), 1,
      anon_sym_load,
    ACTIONS(35), 1,
      anon_sym_erase,
    ACTIONS(38), 1,
      anon_sym_goto,
    ACTIONS(41), 1,
      anon_sym_wait,
    ACTIONS(44), 1,
      anon_sym_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(18), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(2), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(87), 12,
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
    ACTIONS(47), 1,
      sym_BAREWORD,
    ACTIONS(49), 1,
      anon_sym_RBRACE,
    ACTIONS(51), 1,
      anon_sym_rand,
    ACTIONS(53), 1,
      sym_action_return_statement,
    ACTIONS(55), 1,
      anon_sym_close,
    ACTIONS(57), 1,
      anon_sym_save,
    ACTIONS(59), 1,
      anon_sym_load,
    ACTIONS(61), 1,
      anon_sym_erase,
    ACTIONS(63), 1,
      anon_sym_goto,
    ACTIONS(65), 1,
      anon_sym_wait,
    ACTIONS(67), 1,
      anon_sym_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(4), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(87), 12,
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
    ACTIONS(47), 1,
      sym_BAREWORD,
    ACTIONS(51), 1,
      anon_sym_rand,
    ACTIONS(53), 1,
      sym_action_return_statement,
    ACTIONS(55), 1,
      anon_sym_close,
    ACTIONS(57), 1,
      anon_sym_save,
    ACTIONS(59), 1,
      anon_sym_load,
    ACTIONS(61), 1,
      anon_sym_erase,
    ACTIONS(63), 1,
      anon_sym_goto,
    ACTIONS(65), 1,
      anon_sym_wait,
    ACTIONS(67), 1,
      anon_sym_block,
    ACTIONS(69), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(87), 12,
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
    ACTIONS(47), 1,
      sym_BAREWORD,
    ACTIONS(51), 1,
      anon_sym_rand,
    ACTIONS(53), 1,
      sym_action_return_statement,
    ACTIONS(55), 1,
      anon_sym_close,
    ACTIONS(57), 1,
      anon_sym_save,
    ACTIONS(59), 1,
      anon_sym_load,
    ACTIONS(61), 1,
      anon_sym_erase,
    ACTIONS(63), 1,
      anon_sym_goto,
    ACTIONS(65), 1,
      anon_sym_wait,
    ACTIONS(67), 1,
      anon_sym_block,
    ACTIONS(71), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(87), 12,
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
    ACTIONS(47), 1,
      sym_BAREWORD,
    ACTIONS(51), 1,
      anon_sym_rand,
    ACTIONS(53), 1,
      sym_action_return_statement,
    ACTIONS(55), 1,
      anon_sym_close,
    ACTIONS(57), 1,
      anon_sym_save,
    ACTIONS(59), 1,
      anon_sym_load,
    ACTIONS(61), 1,
      anon_sym_erase,
    ACTIONS(63), 1,
      anon_sym_goto,
    ACTIONS(65), 1,
      anon_sym_wait,
    ACTIONS(67), 1,
      anon_sym_block,
    ACTIONS(73), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(5), 4,
      sym__script_item,
      sym_rand_macro,
      sym_label,
      aux_sym_script_block_repeat1,
    STATE(87), 12,
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
  [291] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(77), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(75), 10,
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
  [312] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(81), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(79), 10,
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
  [333] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(85), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(83), 10,
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
  [354] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(89), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    ACTIONS(87), 10,
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
  [375] = 6,
    ACTIONS(95), 1,
      sym_NUMBER,
    ACTIONS(97), 1,
      aux_sym_QUANTITY_token1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(91), 2,
      sym_BOOL,
      sym_BAREWORD,
    ACTIONS(93), 3,
      sym_QUOTED_STRING,
      sym_COLOR,
      sym_CONSTANT,
    STATE(97), 3,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
  [400] = 7,
    ACTIONS(99), 1,
      ts_builtin_sym_end,
    ACTIONS(101), 1,
      sym_BAREWORD,
    ACTIONS(104), 1,
      sym_QUOTED_STRING,
    ACTIONS(107), 1,
      sym_CONSTANT,
    ACTIONS(110), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(12), 4,
      sym__root,
      sym_constant_assignment,
      sym_script_definition,
      aux_sym_document_repeat1,
  [426] = 7,
    ACTIONS(7), 1,
      sym_BAREWORD,
    ACTIONS(9), 1,
      sym_QUOTED_STRING,
    ACTIONS(11), 1,
      sym_CONSTANT,
    ACTIONS(13), 1,
      anon_sym_script,
    ACTIONS(113), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(12), 4,
      sym__root,
      sym_constant_assignment,
      sym_script_definition,
      aux_sym_document_repeat1,
  [452] = 7,
    ACTIONS(115), 1,
      sym_BAREWORD,
    ACTIONS(117), 1,
      anon_sym_LBRACK,
    ACTIONS(121), 1,
      anon_sym_label,
    ACTIONS(123), 1,
      anon_sym_index,
    STATE(83), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(119), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [476] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(127), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(125), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [490] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(131), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(129), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [504] = 5,
    ACTIONS(133), 1,
      anon_sym_LBRACK,
    ACTIONS(135), 1,
      sym_NUMBER,
    ACTIONS(137), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(76), 2,
      sym_DURATION,
      sym_duration_expansion,
  [522] = 5,
    ACTIONS(133), 1,
      anon_sym_LBRACK,
    ACTIONS(135), 1,
      sym_NUMBER,
    ACTIONS(139), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(104), 2,
      sym_DURATION,
      sym_duration_expansion,
  [540] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(143), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(141), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [554] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(147), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(145), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [568] = 4,
    ACTIONS(117), 1,
      anon_sym_LBRACK,
    STATE(80), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(149), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [584] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(153), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(151), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [598] = 3,
    ACTIONS(157), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(155), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [611] = 3,
    ACTIONS(161), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(159), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [624] = 4,
    ACTIONS(165), 1,
      anon_sym_LBRACK,
    STATE(86), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(163), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [639] = 4,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    STATE(89), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(169), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [654] = 3,
    ACTIONS(173), 1,
      sym_duration_suffix,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(171), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [667] = 4,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    STATE(77), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(175), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [682] = 5,
    ACTIONS(135), 1,
      sym_NUMBER,
    ACTIONS(177), 1,
      anon_sym_RBRACK,
    ACTIONS(179), 1,
      sym_CONSTANT,
    STATE(62), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [699] = 5,
    ACTIONS(173), 1,
      sym_duration_suffix,
    ACTIONS(181), 1,
      sym_distance_suffix,
    ACTIONS(183), 1,
      sym_quantity_suffix,
    ACTIONS(185), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [716] = 3,
    ACTIONS(187), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(155), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [729] = 5,
    ACTIONS(135), 1,
      sym_NUMBER,
    ACTIONS(179), 1,
      sym_CONSTANT,
    ACTIONS(189), 1,
      anon_sym_RBRACK,
    STATE(62), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [746] = 4,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    STATE(81), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(191), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [761] = 3,
    ACTIONS(193), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(195), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [773] = 4,
    ACTIONS(197), 1,
      anon_sym_COMMA,
    ACTIONS(199), 1,
      anon_sym_RBRACK,
    STATE(50), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [787] = 4,
    ACTIONS(201), 1,
      anon_sym_COMMA,
    ACTIONS(203), 1,
      anon_sym_RBRACK,
    STATE(46), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [801] = 4,
    ACTIONS(135), 1,
      sym_NUMBER,
    ACTIONS(205), 1,
      sym_CONSTANT,
    STATE(42), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [815] = 4,
    ACTIONS(207), 1,
      anon_sym_COMMA,
    ACTIONS(209), 1,
      anon_sym_RBRACK,
    STATE(39), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [829] = 4,
    ACTIONS(157), 1,
      anon_sym_RBRACK,
    ACTIONS(211), 1,
      anon_sym_COMMA,
    STATE(48), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [843] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(213), 3,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SEMI,
  [853] = 3,
    ACTIONS(215), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(217), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [865] = 4,
    ACTIONS(219), 1,
      anon_sym_COMMA,
    ACTIONS(221), 1,
      anon_sym_RBRACK,
    STATE(44), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [879] = 3,
    ACTIONS(225), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(223), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [891] = 4,
    ACTIONS(177), 1,
      anon_sym_RBRACK,
    ACTIONS(227), 1,
      anon_sym_COMMA,
    STATE(53), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [905] = 3,
    ACTIONS(229), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(195), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [917] = 4,
    ACTIONS(229), 1,
      anon_sym_RBRACK,
    ACTIONS(231), 1,
      anon_sym_COMMA,
    STATE(51), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [931] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(155), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [941] = 4,
    ACTIONS(233), 1,
      anon_sym_COMMA,
    ACTIONS(236), 1,
      anon_sym_RBRACK,
    STATE(48), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [955] = 3,
    ACTIONS(240), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(238), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [967] = 4,
    ACTIONS(240), 1,
      anon_sym_RBRACK,
    ACTIONS(242), 1,
      anon_sym_COMMA,
    STATE(54), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [981] = 4,
    ACTIONS(244), 1,
      anon_sym_COMMA,
    ACTIONS(247), 1,
      anon_sym_RBRACK,
    STATE(51), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [995] = 3,
    ACTIONS(249), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(238), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1007] = 4,
    ACTIONS(251), 1,
      anon_sym_COMMA,
    ACTIONS(254), 1,
      anon_sym_RBRACK,
    STATE(53), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1021] = 4,
    ACTIONS(256), 1,
      anon_sym_COMMA,
    ACTIONS(259), 1,
      anon_sym_RBRACK,
    STATE(54), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1035] = 4,
    ACTIONS(135), 1,
      sym_NUMBER,
    ACTIONS(179), 1,
      sym_CONSTANT,
    STATE(62), 1,
      sym_DURATION,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1049] = 3,
    ACTIONS(261), 1,
      anon_sym_LBRACE,
    STATE(19), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1060] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(263), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [1069] = 3,
    ACTIONS(261), 1,
      anon_sym_LBRACE,
    STATE(15), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1080] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(238), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [1089] = 3,
    ACTIONS(265), 1,
      anon_sym_slot,
    ACTIONS(267), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1100] = 3,
    ACTIONS(269), 1,
      anon_sym_dialog,
    ACTIONS(271), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1111] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(254), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1120] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(236), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1129] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(247), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1138] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(259), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [1147] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(195), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [1156] = 2,
    ACTIONS(273), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1164] = 2,
    ACTIONS(275), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1172] = 2,
    ACTIONS(277), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1180] = 2,
    ACTIONS(279), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1188] = 2,
    ACTIONS(281), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1196] = 2,
    ACTIONS(283), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1204] = 2,
    ACTIONS(285), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1212] = 2,
    ACTIONS(287), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1220] = 2,
    ACTIONS(289), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1228] = 2,
    ACTIONS(291), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1236] = 2,
    ACTIONS(293), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1244] = 2,
    ACTIONS(295), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1252] = 2,
    ACTIONS(297), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1260] = 2,
    ACTIONS(299), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1268] = 2,
    ACTIONS(301), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1276] = 2,
    ACTIONS(303), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1284] = 2,
    ACTIONS(305), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1292] = 2,
    ACTIONS(307), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1300] = 2,
    ACTIONS(309), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1308] = 2,
    ACTIONS(311), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1316] = 2,
    ACTIONS(313), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1324] = 2,
    ACTIONS(315), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1332] = 2,
    ACTIONS(317), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1340] = 2,
    ACTIONS(319), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1348] = 2,
    ACTIONS(321), 1,
      anon_sym_slot,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1356] = 2,
    ACTIONS(323), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1364] = 2,
    ACTIONS(325), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1372] = 2,
    ACTIONS(327), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1380] = 2,
    ACTIONS(329), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1388] = 2,
    ACTIONS(331), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1396] = 2,
    ACTIONS(185), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1404] = 2,
    ACTIONS(333), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1412] = 2,
    ACTIONS(335), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1420] = 2,
    ACTIONS(337), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1428] = 2,
    ACTIONS(339), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1436] = 2,
    ACTIONS(341), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1444] = 2,
    ACTIONS(343), 1,
      anon_sym_COLON,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1452] = 2,
    ACTIONS(345), 1,
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
  [SMALL_STATE(8)] = 312,
  [SMALL_STATE(9)] = 333,
  [SMALL_STATE(10)] = 354,
  [SMALL_STATE(11)] = 375,
  [SMALL_STATE(12)] = 400,
  [SMALL_STATE(13)] = 426,
  [SMALL_STATE(14)] = 452,
  [SMALL_STATE(15)] = 476,
  [SMALL_STATE(16)] = 490,
  [SMALL_STATE(17)] = 504,
  [SMALL_STATE(18)] = 522,
  [SMALL_STATE(19)] = 540,
  [SMALL_STATE(20)] = 554,
  [SMALL_STATE(21)] = 568,
  [SMALL_STATE(22)] = 584,
  [SMALL_STATE(23)] = 598,
  [SMALL_STATE(24)] = 611,
  [SMALL_STATE(25)] = 624,
  [SMALL_STATE(26)] = 639,
  [SMALL_STATE(27)] = 654,
  [SMALL_STATE(28)] = 667,
  [SMALL_STATE(29)] = 682,
  [SMALL_STATE(30)] = 699,
  [SMALL_STATE(31)] = 716,
  [SMALL_STATE(32)] = 729,
  [SMALL_STATE(33)] = 746,
  [SMALL_STATE(34)] = 761,
  [SMALL_STATE(35)] = 773,
  [SMALL_STATE(36)] = 787,
  [SMALL_STATE(37)] = 801,
  [SMALL_STATE(38)] = 815,
  [SMALL_STATE(39)] = 829,
  [SMALL_STATE(40)] = 843,
  [SMALL_STATE(41)] = 853,
  [SMALL_STATE(42)] = 865,
  [SMALL_STATE(43)] = 879,
  [SMALL_STATE(44)] = 891,
  [SMALL_STATE(45)] = 905,
  [SMALL_STATE(46)] = 917,
  [SMALL_STATE(47)] = 931,
  [SMALL_STATE(48)] = 941,
  [SMALL_STATE(49)] = 955,
  [SMALL_STATE(50)] = 967,
  [SMALL_STATE(51)] = 981,
  [SMALL_STATE(52)] = 995,
  [SMALL_STATE(53)] = 1007,
  [SMALL_STATE(54)] = 1021,
  [SMALL_STATE(55)] = 1035,
  [SMALL_STATE(56)] = 1049,
  [SMALL_STATE(57)] = 1060,
  [SMALL_STATE(58)] = 1069,
  [SMALL_STATE(59)] = 1080,
  [SMALL_STATE(60)] = 1089,
  [SMALL_STATE(61)] = 1100,
  [SMALL_STATE(62)] = 1111,
  [SMALL_STATE(63)] = 1120,
  [SMALL_STATE(64)] = 1129,
  [SMALL_STATE(65)] = 1138,
  [SMALL_STATE(66)] = 1147,
  [SMALL_STATE(67)] = 1156,
  [SMALL_STATE(68)] = 1164,
  [SMALL_STATE(69)] = 1172,
  [SMALL_STATE(70)] = 1180,
  [SMALL_STATE(71)] = 1188,
  [SMALL_STATE(72)] = 1196,
  [SMALL_STATE(73)] = 1204,
  [SMALL_STATE(74)] = 1212,
  [SMALL_STATE(75)] = 1220,
  [SMALL_STATE(76)] = 1228,
  [SMALL_STATE(77)] = 1236,
  [SMALL_STATE(78)] = 1244,
  [SMALL_STATE(79)] = 1252,
  [SMALL_STATE(80)] = 1260,
  [SMALL_STATE(81)] = 1268,
  [SMALL_STATE(82)] = 1276,
  [SMALL_STATE(83)] = 1284,
  [SMALL_STATE(84)] = 1292,
  [SMALL_STATE(85)] = 1300,
  [SMALL_STATE(86)] = 1308,
  [SMALL_STATE(87)] = 1316,
  [SMALL_STATE(88)] = 1324,
  [SMALL_STATE(89)] = 1332,
  [SMALL_STATE(90)] = 1340,
  [SMALL_STATE(91)] = 1348,
  [SMALL_STATE(92)] = 1356,
  [SMALL_STATE(93)] = 1364,
  [SMALL_STATE(94)] = 1372,
  [SMALL_STATE(95)] = 1380,
  [SMALL_STATE(96)] = 1388,
  [SMALL_STATE(97)] = 1396,
  [SMALL_STATE(98)] = 1404,
  [SMALL_STATE(99)] = 1412,
  [SMALL_STATE(100)] = 1420,
  [SMALL_STATE(101)] = 1428,
  [SMALL_STATE(102)] = 1436,
  [SMALL_STATE(103)] = 1444,
  [SMALL_STATE(104)] = 1452,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [15] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(103),
  [18] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [20] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(94),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(87),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(90),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2, 0, 3),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 3),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__script_item, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0),
  [101] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(58),
  [104] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(58),
  [107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(93),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 2),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 2),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 6),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 6),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 1, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DURATION, 2, 0, 7),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [233] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [244] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(66),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [251] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [256] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_DISTANCE, 2, 0, 7),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 2, 0, 7),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_QUANTITY, 1, 0, 0),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 5),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_slot, 3, 0, 8),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_save_slot, 2, 0, 0),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 9),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_erase_slot, 3, 0, 8),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 4),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 10),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 11),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [345] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_blocking_delay, 2, 0, 5),
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
