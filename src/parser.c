#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 88
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 59
#define ALIAS_COUNT 0
#define TOKEN_COUNT 34
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 9

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
  sym_DURATION = 10,
  sym_DISTANCE = 11,
  sym_QUANTITY = 12,
  sym_COLOR = 13,
  sym_CONSTANT = 14,
  anon_sym_EQ = 15,
  anon_sym_SEMI = 16,
  anon_sym_script = 17,
  anon_sym_LBRACE = 18,
  anon_sym_RBRACE = 19,
  anon_sym_rand = 20,
  anon_sym_BANG = 21,
  anon_sym_LPAREN = 22,
  anon_sym_RPAREN = 23,
  anon_sym_wait = 24,
  anon_sym_close = 25,
  anon_sym_dialog = 26,
  anon_sym_serial_dialog = 27,
  sym_return_statement = 28,
  anon_sym_load = 29,
  anon_sym_map = 30,
  anon_sym_goto = 31,
  anon_sym_label = 32,
  anon_sym_index = 33,
  sym_source_file = 34,
  sym_bareword_expansion = 35,
  sym_string_expansion = 36,
  sym_number_expansion = 37,
  sym_duration_expansion = 38,
  sym__root = 39,
  sym_constant_assignment = 40,
  sym_script_definition = 41,
  sym_script_block = 42,
  sym__script_item = 43,
  sym_rand_macro = 44,
  sym__action_item = 45,
  sym_action_non_blocking_delay = 46,
  sym_action_close_dialog = 47,
  sym_action_close_serial_dialog = 48,
  sym_action_load_map = 49,
  sym_action_run_script = 50,
  sym_action_goto_label = 51,
  sym_action_goto_index = 52,
  aux_sym_source_file_repeat1 = 53,
  aux_sym_bareword_expansion_repeat1 = 54,
  aux_sym_string_expansion_repeat1 = 55,
  aux_sym_number_expansion_repeat1 = 56,
  aux_sym_duration_expansion_repeat1 = 57,
  aux_sym_script_block_repeat1 = 58,
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
  [sym_DURATION] = "DURATION",
  [sym_DISTANCE] = "DISTANCE",
  [sym_QUANTITY] = "QUANTITY",
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
  [anon_sym_wait] = "wait",
  [anon_sym_close] = "close",
  [anon_sym_dialog] = "dialog",
  [anon_sym_serial_dialog] = "serial_dialog",
  [sym_return_statement] = "return_statement",
  [anon_sym_load] = "load",
  [anon_sym_map] = "map",
  [anon_sym_goto] = "goto",
  [anon_sym_label] = "label",
  [anon_sym_index] = "index",
  [sym_source_file] = "source_file",
  [sym_bareword_expansion] = "bareword_expansion",
  [sym_string_expansion] = "string_expansion",
  [sym_number_expansion] = "number_expansion",
  [sym_duration_expansion] = "duration_expansion",
  [sym__root] = "_root",
  [sym_constant_assignment] = "constant_assignment",
  [sym_script_definition] = "script_definition",
  [sym_script_block] = "script_block",
  [sym__script_item] = "_script_item",
  [sym_rand_macro] = "rand_macro",
  [sym__action_item] = "_action_item",
  [sym_action_non_blocking_delay] = "action_non_blocking_delay",
  [sym_action_close_dialog] = "action_close_dialog",
  [sym_action_close_serial_dialog] = "action_close_serial_dialog",
  [sym_action_load_map] = "action_load_map",
  [sym_action_run_script] = "action_run_script",
  [sym_action_goto_label] = "action_goto_label",
  [sym_action_goto_index] = "action_goto_index",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
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
  [sym_DURATION] = sym_DURATION,
  [sym_DISTANCE] = sym_DISTANCE,
  [sym_QUANTITY] = sym_QUANTITY,
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
  [anon_sym_wait] = anon_sym_wait,
  [anon_sym_close] = anon_sym_close,
  [anon_sym_dialog] = anon_sym_dialog,
  [anon_sym_serial_dialog] = anon_sym_serial_dialog,
  [sym_return_statement] = sym_return_statement,
  [anon_sym_load] = anon_sym_load,
  [anon_sym_map] = anon_sym_map,
  [anon_sym_goto] = anon_sym_goto,
  [anon_sym_label] = anon_sym_label,
  [anon_sym_index] = anon_sym_index,
  [sym_source_file] = sym_source_file,
  [sym_bareword_expansion] = sym_bareword_expansion,
  [sym_string_expansion] = sym_string_expansion,
  [sym_number_expansion] = sym_number_expansion,
  [sym_duration_expansion] = sym_duration_expansion,
  [sym__root] = sym__root,
  [sym_constant_assignment] = sym_constant_assignment,
  [sym_script_definition] = sym_script_definition,
  [sym_script_block] = sym_script_block,
  [sym__script_item] = sym__script_item,
  [sym_rand_macro] = sym_rand_macro,
  [sym__action_item] = sym__action_item,
  [sym_action_non_blocking_delay] = sym_action_non_blocking_delay,
  [sym_action_close_dialog] = sym_action_close_dialog,
  [sym_action_close_serial_dialog] = sym_action_close_serial_dialog,
  [sym_action_load_map] = sym_action_load_map,
  [sym_action_run_script] = sym_action_run_script,
  [sym_action_goto_label] = sym_action_goto_label,
  [sym_action_goto_index] = sym_action_goto_index,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
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
  [anon_sym_wait] = {
    .visible = true,
    .named = false,
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
  [anon_sym_label] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_index] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
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
  [sym_duration_expansion] = {
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
  [sym__action_item] = {
    .visible = false,
    .named = true,
  },
  [sym_action_non_blocking_delay] = {
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
  [aux_sym_source_file_repeat1] = {
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
  field_value = 7,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_duration] = "duration",
  [field_index] = "index",
  [field_label] = "label",
  [field_map] = "map",
  [field_script] = "script",
  [field_script_name] = "script_name",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 2},
  [6] = {.index = 6, .length = 1},
  [7] = {.index = 7, .length = 1},
  [8] = {.index = 8, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_script_name, 0},
  [1] =
    {field_script_name, 1},
  [2] =
    {field_duration, 1},
  [3] =
    {field_script, 1},
  [4] =
    {field_label, 0},
    {field_value, 2},
  [6] =
    {field_map, 2},
  [7] =
    {field_label, 2},
  [8] =
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(93);
      ADVANCE_MAP(
        '!', 177,
        '"', 4,
        '#', 89,
        '$', 90,
        '(', 178,
        ')', 179,
        ',', 157,
        '/', 5,
        ';', 171,
        '=', 170,
        '[', 156,
        ']', 158,
        'b', 51,
        'c', 52,
        'd', 46,
        'g', 65,
        'i', 59,
        'l', 9,
        'm', 10,
        'o', 60,
        'r', 18,
        's', 21,
        't', 41,
        'w', 15,
        'y', 32,
        '{', 174,
        '}', 175,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(160);
      END_STATE();
    case 1:
      ADVANCE_MAP(
        '"', 4,
        '#', 89,
        '$', 90,
        '/', 5,
        'b', 131,
        'c', 132,
        'f', 103,
        'g', 146,
        'm', 99,
        'o', 122,
        'r', 112,
        't', 126,
        'w', 125,
        'y', 118,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(160);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(4);
      if (lookahead == '$') ADVANCE(90);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '[') ADVANCE(156);
      if (lookahead == ']') ADVANCE(158);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(4);
      if (lookahead == '$') ADVANCE(90);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '[') ADVANCE(156);
      if (lookahead == 'i') ADVANCE(140);
      if (lookahead == 'l') ADVANCE(101);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(159);
      if (lookahead == '\\') ADVANCE(91);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(95);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(94);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(28);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(20);
      if (lookahead == 'o') ADVANCE(12);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(40);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(165);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(25);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(22);
      if (lookahead == 'u') ADVANCE(30);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(55);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(45);
      if (lookahead == 'h') ADVANCE(47);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(61);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(54);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(63);
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 20:
      if (lookahead == 'b') ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead == 'c') ADVANCE(73);
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(50);
      END_STATE();
    case 23:
      if (lookahead == 'c') ADVANCE(29);
      END_STATE();
    case 24:
      if (lookahead == 'd') ADVANCE(165);
      if (lookahead == 't') ADVANCE(83);
      END_STATE();
    case 25:
      if (lookahead == 'd') ADVANCE(185);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(176);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(33);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(49);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(164);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(165);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(181);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(86);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(61);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(53);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 38:
      if (lookahead == 'g') ADVANCE(182);
      END_STATE();
    case 39:
      if (lookahead == 'g') ADVANCE(183);
      END_STATE();
    case 40:
      if (lookahead == 'g') ADVANCE(36);
      if (lookahead == 'p') ADVANCE(186);
      END_STATE();
    case 41:
      if (lookahead == 'h') ADVANCE(72);
      if (lookahead == 'w') ADVANCE(42);
      END_STATE();
    case 42:
      if (lookahead == 'i') ADVANCE(23);
      END_STATE();
    case 43:
      if (lookahead == 'i') ADVANCE(85);
      if (lookahead == 'x') ADVANCE(163);
      END_STATE();
    case 44:
      if (lookahead == 'i') ADVANCE(71);
      END_STATE();
    case 45:
      if (lookahead == 'i') ADVANCE(78);
      END_STATE();
    case 46:
      if (lookahead == 'i') ADVANCE(14);
      END_STATE();
    case 47:
      if (lookahead == 'i') ADVANCE(81);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(17);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 50:
      if (lookahead == 'k') ADVANCE(165);
      END_STATE();
    case 51:
      if (lookahead == 'l') ADVANCE(13);
      END_STATE();
    case 52:
      if (lookahead == 'l') ADVANCE(69);
      if (lookahead == 'y') ADVANCE(16);
      END_STATE();
    case 53:
      if (lookahead == 'l') ADVANCE(188);
      END_STATE();
    case 54:
      if (lookahead == 'l') ADVANCE(8);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(67);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(68);
      END_STATE();
    case 57:
      if (lookahead == 'l') ADVANCE(70);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(56);
      END_STATE();
    case 59:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 60:
      if (lookahead == 'n') ADVANCE(23);
      END_STATE();
    case 61:
      if (lookahead == 'n') ADVANCE(165);
      END_STATE();
    case 62:
      if (lookahead == 'n') ADVANCE(184);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(26);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(82);
      END_STATE();
    case 65:
      if (lookahead == 'o') ADVANCE(80);
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 66:
      if (lookahead == 'o') ADVANCE(187);
      END_STATE();
    case 67:
      if (lookahead == 'o') ADVANCE(38);
      END_STATE();
    case 68:
      if (lookahead == 'o') ADVANCE(84);
      END_STATE();
    case 69:
      if (lookahead == 'o') ADVANCE(77);
      END_STATE();
    case 70:
      if (lookahead == 'o') ADVANCE(39);
      END_STATE();
    case 71:
      if (lookahead == 'p') ADVANCE(79);
      END_STATE();
    case 72:
      if (lookahead == 'r') ADVANCE(42);
      END_STATE();
    case 73:
      if (lookahead == 'r') ADVANCE(44);
      END_STATE();
    case 74:
      if (lookahead == 'r') ADVANCE(62);
      END_STATE();
    case 75:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 76:
      if (lookahead == 's') ADVANCE(161);
      END_STATE();
    case 77:
      if (lookahead == 's') ADVANCE(31);
      END_STATE();
    case 78:
      if (lookahead == 't') ADVANCE(180);
      END_STATE();
    case 79:
      if (lookahead == 't') ADVANCE(172);
      END_STATE();
    case 80:
      if (lookahead == 't') ADVANCE(66);
      END_STATE();
    case 81:
      if (lookahead == 't') ADVANCE(30);
      END_STATE();
    case 82:
      if (lookahead == 't') ADVANCE(11);
      END_STATE();
    case 83:
      if (lookahead == 'u') ADVANCE(74);
      END_STATE();
    case 84:
      if (lookahead == 'w') ADVANCE(165);
      END_STATE();
    case 85:
      if (lookahead == 'x') ADVANCE(163);
      END_STATE();
    case 86:
      if (lookahead == 'x') ADVANCE(190);
      END_STATE();
    case 87:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(168);
      END_STATE();
    case 88:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(87);
      END_STATE();
    case 89:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(88);
      END_STATE();
    case 90:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(169);
      END_STATE();
    case 91:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 92:
      if (eof) ADVANCE(93);
      if (lookahead == '"') ADVANCE(4);
      if (lookahead == '$') ADVANCE(90);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '[') ADVANCE(156);
      if (lookahead == ']') ADVANCE(158);
      if (lookahead == 's') ADVANCE(105);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(92);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(162);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(7);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(95);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(95);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_BOOL);
      if (lookahead == 'c') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_BOOL);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(106);
      if (lookahead == 'u') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'b') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(123);
      if (lookahead == 'n') ADVANCE(96);
      if (lookahead == 'p') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(152);
      if (lookahead == 'w') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(107);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(141);
      if (lookahead == 'y') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(147);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'p') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'x') ADVANCE(191);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == 'm') ADVANCE(76);
      if (lookahead == 'p') ADVANCE(43);
      if (lookahead == 's') ADVANCE(161);
      if (lookahead == 'x') ADVANCE(164);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_DURATION);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_DURATION);
      if (lookahead == 'm') ADVANCE(76);
      if (lookahead == 's') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(162);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_DISTANCE);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_QUANTITY);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(165);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(166);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(167);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(169);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_script);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_script);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_rand);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_wait);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_close);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_dialog);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_return_statement);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_load);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_map);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_label);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_index);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_index);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 92},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 92},
  [8] = {.lex_state = 92},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 92},
  [15] = {.lex_state = 92},
  [16] = {.lex_state = 92},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 92},
  [19] = {.lex_state = 92},
  [20] = {.lex_state = 92},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 92},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 92},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 92},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 92},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 0},
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
    [sym_DURATION] = ACTIONS(1),
    [sym_DISTANCE] = ACTIONS(1),
    [sym_QUANTITY] = ACTIONS(1),
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
    [anon_sym_wait] = ACTIONS(1),
    [anon_sym_close] = ACTIONS(1),
    [anon_sym_dialog] = ACTIONS(1),
    [anon_sym_serial_dialog] = ACTIONS(1),
    [sym_return_statement] = ACTIONS(1),
    [anon_sym_load] = ACTIONS(1),
    [anon_sym_map] = ACTIONS(1),
    [anon_sym_goto] = ACTIONS(1),
    [anon_sym_label] = ACTIONS(1),
    [anon_sym_index] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(66),
    [sym__root] = STATE(7),
    [sym_constant_assignment] = STATE(7),
    [sym_script_definition] = STATE(7),
    [aux_sym_source_file_repeat1] = STATE(7),
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
  [0] = 10,
    ACTIONS(17), 1,
      anon_sym_rand,
    ACTIONS(20), 1,
      anon_sym_wait,
    ACTIONS(23), 1,
      anon_sym_close,
    ACTIONS(26), 1,
      sym_return_statement,
    ACTIONS(29), 1,
      anon_sym_load,
    ACTIONS(32), 1,
      anon_sym_goto,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(15), 2,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
    STATE(2), 3,
      sym__script_item,
      sym_rand_macro,
      aux_sym_script_block_repeat1,
    STATE(64), 8,
      sym__action_item,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
  [42] = 10,
    ACTIONS(35), 1,
      anon_sym_RBRACE,
    ACTIONS(37), 1,
      anon_sym_rand,
    ACTIONS(39), 1,
      anon_sym_wait,
    ACTIONS(41), 1,
      anon_sym_close,
    ACTIONS(43), 1,
      sym_return_statement,
    ACTIONS(45), 1,
      anon_sym_load,
    ACTIONS(47), 1,
      anon_sym_goto,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(4), 3,
      sym__script_item,
      sym_rand_macro,
      aux_sym_script_block_repeat1,
    STATE(64), 8,
      sym__action_item,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
  [83] = 10,
    ACTIONS(37), 1,
      anon_sym_rand,
    ACTIONS(39), 1,
      anon_sym_wait,
    ACTIONS(41), 1,
      anon_sym_close,
    ACTIONS(43), 1,
      sym_return_statement,
    ACTIONS(45), 1,
      anon_sym_load,
    ACTIONS(47), 1,
      anon_sym_goto,
    ACTIONS(49), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 3,
      sym__script_item,
      sym_rand_macro,
      aux_sym_script_block_repeat1,
    STATE(64), 8,
      sym__action_item,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
  [124] = 10,
    ACTIONS(37), 1,
      anon_sym_rand,
    ACTIONS(39), 1,
      anon_sym_wait,
    ACTIONS(41), 1,
      anon_sym_close,
    ACTIONS(43), 1,
      sym_return_statement,
    ACTIONS(45), 1,
      anon_sym_load,
    ACTIONS(47), 1,
      anon_sym_goto,
    ACTIONS(51), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(6), 3,
      sym__script_item,
      sym_rand_macro,
      aux_sym_script_block_repeat1,
    STATE(64), 8,
      sym__action_item,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
  [165] = 10,
    ACTIONS(37), 1,
      anon_sym_rand,
    ACTIONS(39), 1,
      anon_sym_wait,
    ACTIONS(41), 1,
      anon_sym_close,
    ACTIONS(43), 1,
      sym_return_statement,
    ACTIONS(45), 1,
      anon_sym_load,
    ACTIONS(47), 1,
      anon_sym_goto,
    ACTIONS(53), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(2), 3,
      sym__script_item,
      sym_rand_macro,
      aux_sym_script_block_repeat1,
    STATE(64), 8,
      sym__action_item,
      sym_action_non_blocking_delay,
      sym_action_close_dialog,
      sym_action_close_serial_dialog,
      sym_action_load_map,
      sym_action_run_script,
      sym_action_goto_label,
      sym_action_goto_index,
  [206] = 7,
    ACTIONS(7), 1,
      sym_BAREWORD,
    ACTIONS(9), 1,
      sym_QUOTED_STRING,
    ACTIONS(11), 1,
      sym_CONSTANT,
    ACTIONS(13), 1,
      anon_sym_script,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(8), 4,
      sym__root,
      sym_constant_assignment,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [232] = 7,
    ACTIONS(57), 1,
      ts_builtin_sym_end,
    ACTIONS(59), 1,
      sym_BAREWORD,
    ACTIONS(62), 1,
      sym_QUOTED_STRING,
    ACTIONS(65), 1,
      sym_CONSTANT,
    ACTIONS(68), 1,
      anon_sym_script,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(8), 4,
      sym__root,
      sym_constant_assignment,
      sym_script_definition,
      aux_sym_source_file_repeat1,
  [258] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(73), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(71), 7,
      sym_BOOL,
      sym_BAREWORD,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
  [276] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(75), 8,
      anon_sym_RBRACE,
      anon_sym_rand,
      anon_sym_RPAREN,
      anon_sym_wait,
      anon_sym_close,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
  [291] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(77), 8,
      anon_sym_RBRACE,
      anon_sym_rand,
      anon_sym_RPAREN,
      anon_sym_wait,
      anon_sym_close,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
  [306] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(79), 8,
      anon_sym_RBRACE,
      anon_sym_rand,
      anon_sym_RPAREN,
      anon_sym_wait,
      anon_sym_close,
      sym_return_statement,
      anon_sym_load,
      anon_sym_goto,
  [321] = 7,
    ACTIONS(81), 1,
      sym_BAREWORD,
    ACTIONS(83), 1,
      anon_sym_LBRACK,
    ACTIONS(87), 1,
      anon_sym_label,
    ACTIONS(89), 1,
      anon_sym_index,
    STATE(62), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(85), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [345] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(93), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(91), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [359] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(97), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(95), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [373] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(101), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(99), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [387] = 4,
    ACTIONS(83), 1,
      anon_sym_LBRACK,
    STATE(84), 1,
      sym_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(103), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [403] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(107), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(105), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [417] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(111), 2,
      sym_BAREWORD,
      anon_sym_script,
    ACTIONS(109), 3,
      ts_builtin_sym_end,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [431] = 4,
    ACTIONS(113), 1,
      anon_sym_LBRACK,
    STATE(78), 1,
      sym_duration_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(115), 2,
      sym_DURATION,
      sym_CONSTANT,
  [446] = 3,
    ACTIONS(119), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(117), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [459] = 3,
    ACTIONS(123), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(121), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [472] = 4,
    ACTIONS(125), 1,
      anon_sym_LBRACK,
    STATE(65), 1,
      sym_number_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(127), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [487] = 3,
    ACTIONS(129), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(121), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [500] = 4,
    ACTIONS(133), 1,
      anon_sym_LBRACK,
    STATE(61), 1,
      sym_bareword_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(131), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [515] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(121), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [525] = 3,
    ACTIONS(135), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(137), 2,
      sym_DURATION,
      sym_CONSTANT,
  [537] = 3,
    ACTIONS(139), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(141), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [549] = 4,
    ACTIONS(143), 1,
      anon_sym_COMMA,
    ACTIONS(145), 1,
      anon_sym_RBRACK,
    STATE(40), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [563] = 4,
    ACTIONS(123), 1,
      anon_sym_RBRACK,
    ACTIONS(147), 1,
      anon_sym_COMMA,
    STATE(36), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [577] = 3,
    ACTIONS(149), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(137), 2,
      sym_DURATION,
      sym_CONSTANT,
  [589] = 4,
    ACTIONS(149), 1,
      anon_sym_RBRACK,
    ACTIONS(151), 1,
      anon_sym_COMMA,
    STATE(34), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [603] = 4,
    ACTIONS(153), 1,
      anon_sym_COMMA,
    ACTIONS(155), 1,
      anon_sym_RBRACK,
    STATE(38), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [617] = 4,
    ACTIONS(157), 1,
      anon_sym_COMMA,
    ACTIONS(160), 1,
      anon_sym_RBRACK,
    STATE(34), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [631] = 4,
    ACTIONS(162), 1,
      anon_sym_COMMA,
    ACTIONS(164), 1,
      anon_sym_RBRACK,
    STATE(32), 1,
      aux_sym_duration_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [645] = 4,
    ACTIONS(166), 1,
      anon_sym_COMMA,
    ACTIONS(169), 1,
      anon_sym_RBRACK,
    STATE(36), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [659] = 3,
    ACTIONS(173), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(171), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [671] = 4,
    ACTIONS(173), 1,
      anon_sym_RBRACK,
    ACTIONS(175), 1,
      anon_sym_COMMA,
    STATE(43), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [685] = 3,
    ACTIONS(177), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(179), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [697] = 4,
    ACTIONS(177), 1,
      anon_sym_RBRACK,
    ACTIONS(181), 1,
      anon_sym_COMMA,
    STATE(45), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [711] = 3,
    ACTIONS(183), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(179), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [723] = 4,
    ACTIONS(185), 1,
      anon_sym_COMMA,
    ACTIONS(187), 1,
      anon_sym_RBRACK,
    STATE(30), 1,
      aux_sym_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [737] = 4,
    ACTIONS(189), 1,
      anon_sym_COMMA,
    ACTIONS(192), 1,
      anon_sym_RBRACK,
    STATE(43), 1,
      aux_sym_bareword_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [751] = 3,
    ACTIONS(194), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(171), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [763] = 4,
    ACTIONS(196), 1,
      anon_sym_COMMA,
    ACTIONS(199), 1,
      anon_sym_RBRACK,
    STATE(45), 1,
      aux_sym_number_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [777] = 3,
    ACTIONS(203), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(201), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [789] = 3,
    ACTIONS(205), 1,
      anon_sym_dialog,
    ACTIONS(207), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [800] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(209), 2,
      sym_DURATION,
      sym_CONSTANT,
  [809] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(211), 2,
      sym_BAREWORD,
      sym_QUOTED_STRING,
  [818] = 3,
    ACTIONS(213), 1,
      anon_sym_LBRACE,
    STATE(16), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [829] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(160), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [838] = 3,
    ACTIONS(213), 1,
      anon_sym_LBRACE,
    STATE(14), 1,
      sym_script_block,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [849] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(169), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [858] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(192), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [867] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(199), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [876] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(137), 2,
      sym_DURATION,
      sym_CONSTANT,
  [885] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(171), 2,
      sym_BAREWORD,
      sym_CONSTANT,
  [894] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(179), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [903] = 2,
    ACTIONS(215), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [911] = 2,
    ACTIONS(217), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [919] = 2,
    ACTIONS(219), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [927] = 2,
    ACTIONS(221), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [935] = 2,
    ACTIONS(223), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [943] = 2,
    ACTIONS(225), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [951] = 2,
    ACTIONS(227), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [959] = 2,
    ACTIONS(229), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [967] = 2,
    ACTIONS(231), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [975] = 2,
    ACTIONS(233), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [983] = 2,
    ACTIONS(235), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [991] = 2,
    ACTIONS(237), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [999] = 2,
    ACTIONS(239), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1007] = 2,
    ACTIONS(241), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1015] = 2,
    ACTIONS(243), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1023] = 2,
    ACTIONS(245), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1031] = 2,
    ACTIONS(247), 1,
      anon_sym_map,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1039] = 2,
    ACTIONS(249), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1047] = 2,
    ACTIONS(251), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1055] = 2,
    ACTIONS(253), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1063] = 2,
    ACTIONS(255), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1071] = 2,
    ACTIONS(257), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1079] = 2,
    ACTIONS(259), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1087] = 2,
    ACTIONS(261), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1095] = 2,
    ACTIONS(263), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1103] = 2,
    ACTIONS(265), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1111] = 2,
    ACTIONS(267), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1119] = 2,
    ACTIONS(269), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [1127] = 2,
    ACTIONS(271), 1,
      anon_sym_BANG,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 42,
  [SMALL_STATE(4)] = 83,
  [SMALL_STATE(5)] = 124,
  [SMALL_STATE(6)] = 165,
  [SMALL_STATE(7)] = 206,
  [SMALL_STATE(8)] = 232,
  [SMALL_STATE(9)] = 258,
  [SMALL_STATE(10)] = 276,
  [SMALL_STATE(11)] = 291,
  [SMALL_STATE(12)] = 306,
  [SMALL_STATE(13)] = 321,
  [SMALL_STATE(14)] = 345,
  [SMALL_STATE(15)] = 359,
  [SMALL_STATE(16)] = 373,
  [SMALL_STATE(17)] = 387,
  [SMALL_STATE(18)] = 403,
  [SMALL_STATE(19)] = 417,
  [SMALL_STATE(20)] = 431,
  [SMALL_STATE(21)] = 446,
  [SMALL_STATE(22)] = 459,
  [SMALL_STATE(23)] = 472,
  [SMALL_STATE(24)] = 487,
  [SMALL_STATE(25)] = 500,
  [SMALL_STATE(26)] = 515,
  [SMALL_STATE(27)] = 525,
  [SMALL_STATE(28)] = 537,
  [SMALL_STATE(29)] = 549,
  [SMALL_STATE(30)] = 563,
  [SMALL_STATE(31)] = 577,
  [SMALL_STATE(32)] = 589,
  [SMALL_STATE(33)] = 603,
  [SMALL_STATE(34)] = 617,
  [SMALL_STATE(35)] = 631,
  [SMALL_STATE(36)] = 645,
  [SMALL_STATE(37)] = 659,
  [SMALL_STATE(38)] = 671,
  [SMALL_STATE(39)] = 685,
  [SMALL_STATE(40)] = 697,
  [SMALL_STATE(41)] = 711,
  [SMALL_STATE(42)] = 723,
  [SMALL_STATE(43)] = 737,
  [SMALL_STATE(44)] = 751,
  [SMALL_STATE(45)] = 763,
  [SMALL_STATE(46)] = 777,
  [SMALL_STATE(47)] = 789,
  [SMALL_STATE(48)] = 800,
  [SMALL_STATE(49)] = 809,
  [SMALL_STATE(50)] = 818,
  [SMALL_STATE(51)] = 829,
  [SMALL_STATE(52)] = 838,
  [SMALL_STATE(53)] = 849,
  [SMALL_STATE(54)] = 858,
  [SMALL_STATE(55)] = 867,
  [SMALL_STATE(56)] = 876,
  [SMALL_STATE(57)] = 885,
  [SMALL_STATE(58)] = 894,
  [SMALL_STATE(59)] = 903,
  [SMALL_STATE(60)] = 911,
  [SMALL_STATE(61)] = 919,
  [SMALL_STATE(62)] = 927,
  [SMALL_STATE(63)] = 935,
  [SMALL_STATE(64)] = 943,
  [SMALL_STATE(65)] = 951,
  [SMALL_STATE(66)] = 959,
  [SMALL_STATE(67)] = 967,
  [SMALL_STATE(68)] = 975,
  [SMALL_STATE(69)] = 983,
  [SMALL_STATE(70)] = 991,
  [SMALL_STATE(71)] = 999,
  [SMALL_STATE(72)] = 1007,
  [SMALL_STATE(73)] = 1015,
  [SMALL_STATE(74)] = 1023,
  [SMALL_STATE(75)] = 1031,
  [SMALL_STATE(76)] = 1039,
  [SMALL_STATE(77)] = 1047,
  [SMALL_STATE(78)] = 1055,
  [SMALL_STATE(79)] = 1063,
  [SMALL_STATE(80)] = 1071,
  [SMALL_STATE(81)] = 1079,
  [SMALL_STATE(82)] = 1087,
  [SMALL_STATE(83)] = 1095,
  [SMALL_STATE(84)] = 1103,
  [SMALL_STATE(85)] = 1111,
  [SMALL_STATE(86)] = 1119,
  [SMALL_STATE(87)] = 1127,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(87),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(64),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_block_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(52),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 4, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__script_item, 2, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rand_macro, 5, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 2, 0, 1),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 2, 0, 1),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 2, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_definition, 3, 0, 2),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_definition, 3, 0, 2),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 5),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_assignment, 4, 0, 5),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script_block, 3, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_script_block, 3, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [157] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_duration_expansion_repeat1, 2, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [166] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_string_expansion_repeat1, 2, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [189] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_bareword_expansion_repeat1, 2, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [196] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(58),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_number_expansion_repeat1, 2, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 5, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 2, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_label, 3, 0, 7),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_run_script, 2, 0, 4),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 4, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_goto_index, 3, 0, 8),
  [229] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 3, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 3, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 3, 0, 0),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 5, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 5, 0, 0),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_expansion, 3, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 4, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_non_blocking_delay, 2, 0, 3),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_dialog, 2, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 4, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bareword_expansion, 2, 0, 0),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 2, 0, 0),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_close_serial_dialog, 2, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_action_load_map, 3, 0, 6),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration_expansion, 4, 0, 0),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_expansion, 5, 0, 0),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
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
