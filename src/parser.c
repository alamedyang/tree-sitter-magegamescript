#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 48
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 38
#define ALIAS_COUNT 0
#define TOKEN_COUNT 24
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  sym_block_comment = 1,
  sym_line_comment = 2,
  sym_BAREWORD = 3,
  sym_QUOTED_STRING = 4,
  anon_sym_LBRACK = 5,
  anon_sym_COMMA = 6,
  anon_sym_RBRACK = 7,
  sym_NUMBER = 8,
  sym_DURATION = 9,
  sym_DISTANCE = 10,
  sym_QUANTITY = 11,
  sym_COLOR = 12,
  sym_BOOLEAN = 13,
  sym_CONSTANT = 14,
  anon_sym_include = 15,
  anon_sym_SEMI = 16,
  anon_sym_EQ = 17,
  anon_sym_add = 18,
  anon_sym_serial_dialog = 19,
  anon_sym_settings = 20,
  anon_sym_LBRACE = 21,
  anon_sym_RBRACE = 22,
  anon_sym_wrap = 23,
  sym_source_file = 24,
  sym_quoted_string_expansion = 25,
  sym_constant_expansion = 26,
  sym_constant_value_expansion = 27,
  sym__root = 28,
  sym_include_macro = 29,
  sym_constant_assignment = 30,
  sym_add_serial_dialog_settings = 31,
  sym_serial_dialog_parameter = 32,
  aux_sym_source_file_repeat1 = 33,
  aux_sym_quoted_string_expansion_repeat1 = 34,
  aux_sym_constant_expansion_repeat1 = 35,
  aux_sym_constant_value_expansion_repeat1 = 36,
  aux_sym_add_serial_dialog_settings_repeat1 = 37,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_block_comment] = "block_comment",
  [sym_line_comment] = "line_comment",
  [sym_BAREWORD] = "BAREWORD",
  [sym_QUOTED_STRING] = "QUOTED_STRING",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_NUMBER] = "NUMBER",
  [sym_DURATION] = "DURATION",
  [sym_DISTANCE] = "DISTANCE",
  [sym_QUANTITY] = "QUANTITY",
  [sym_COLOR] = "COLOR",
  [sym_BOOLEAN] = "BOOLEAN",
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
  [sym_source_file] = "source_file",
  [sym_quoted_string_expansion] = "quoted_string_expansion",
  [sym_constant_expansion] = "constant_expansion",
  [sym_constant_value_expansion] = "constant_value_expansion",
  [sym__root] = "_root",
  [sym_include_macro] = "include_macro",
  [sym_constant_assignment] = "constant_assignment",
  [sym_add_serial_dialog_settings] = "add_serial_dialog_settings",
  [sym_serial_dialog_parameter] = "serial_dialog_parameter",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_quoted_string_expansion_repeat1] = "quoted_string_expansion_repeat1",
  [aux_sym_constant_expansion_repeat1] = "constant_expansion_repeat1",
  [aux_sym_constant_value_expansion_repeat1] = "constant_value_expansion_repeat1",
  [aux_sym_add_serial_dialog_settings_repeat1] = "add_serial_dialog_settings_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_block_comment] = sym_block_comment,
  [sym_line_comment] = sym_line_comment,
  [sym_BAREWORD] = sym_BAREWORD,
  [sym_QUOTED_STRING] = sym_QUOTED_STRING,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_NUMBER] = sym_NUMBER,
  [sym_DURATION] = sym_DURATION,
  [sym_DISTANCE] = sym_DISTANCE,
  [sym_QUANTITY] = sym_QUANTITY,
  [sym_COLOR] = sym_COLOR,
  [sym_BOOLEAN] = sym_BOOLEAN,
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
  [sym_source_file] = sym_source_file,
  [sym_quoted_string_expansion] = sym_quoted_string_expansion,
  [sym_constant_expansion] = sym_constant_expansion,
  [sym_constant_value_expansion] = sym_constant_value_expansion,
  [sym__root] = sym__root,
  [sym_include_macro] = sym_include_macro,
  [sym_constant_assignment] = sym_constant_assignment,
  [sym_add_serial_dialog_settings] = sym_add_serial_dialog_settings,
  [sym_serial_dialog_parameter] = sym_serial_dialog_parameter,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_quoted_string_expansion_repeat1] = aux_sym_quoted_string_expansion_repeat1,
  [aux_sym_constant_expansion_repeat1] = aux_sym_constant_expansion_repeat1,
  [aux_sym_constant_value_expansion_repeat1] = aux_sym_constant_value_expansion_repeat1,
  [aux_sym_add_serial_dialog_settings_repeat1] = aux_sym_add_serial_dialog_settings_repeat1,
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
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_string_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_constant_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_constant_value_expansion] = {
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
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_string_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constant_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_constant_value_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_add_serial_dialog_settings_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_fileName = 1,
  field_label = 2,
  field_value = 3,
  field_wrap = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_fileName] = "fileName",
  [field_label] = "label",
  [field_value] = "value",
  [field_wrap] = "wrap",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_fileName, 1},
  [1] =
    {field_label, 0},
    {field_value, 2},
  [3] =
    {field_wrap, 1},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(88);
      ADVANCE_MAP(
        '"', 3,
        '#', 85,
        '$', 86,
        ',', 133,
        '/', 4,
        ';', 147,
        '=', 148,
        '[', 132,
        ']', 134,
        'a', 23,
        'b', 52,
        'c', 53,
        'f', 12,
        'g', 71,
        'i', 60,
        'm', 9,
        'o', 38,
        'r', 32,
        's', 26,
        't', 43,
        'w', 44,
        'y', 33,
        '{', 152,
        '}', 153,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '"', 3,
        '#', 85,
        '$', 86,
        '/', 4,
        '[', 132,
        'b', 113,
        'c', 114,
        'f', 94,
        'g', 123,
        'm', 92,
        'o', 106,
        'r', 100,
        't', 108,
        'w', 109,
        'y', 103,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(131);
      if (lookahead == '\\') ADVANCE(87);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead == '/') ADVANCE(89);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(5);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '/') ADVANCE(1);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(25);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(42);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(139);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(68);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(58);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(17);
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(54);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 17:
      if (lookahead == 'c') ADVANCE(51);
      END_STATE();
    case 18:
      if (lookahead == 'c') ADVANCE(56);
      END_STATE();
    case 19:
      if (lookahead == 'c') ADVANCE(27);
      END_STATE();
    case 20:
      if (lookahead == 'd') ADVANCE(149);
      END_STATE();
    case 21:
      if (lookahead == 'd') ADVANCE(143);
      END_STATE();
    case 22:
      if (lookahead == 'd') ADVANCE(139);
      END_STATE();
    case 23:
      if (lookahead == 'd') ADVANCE(20);
      END_STATE();
    case 24:
      if (lookahead == 'd') ADVANCE(30);
      END_STATE();
    case 25:
      if (lookahead == 'd') ADVANCE(50);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(138);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(139);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(146);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(61);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(31);
      END_STATE();
    case 38:
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'n') ADVANCE(144);
      if (lookahead == 'p') ADVANCE(34);
      END_STATE();
    case 39:
      if (lookahead == 'f') ADVANCE(143);
      END_STATE();
    case 40:
      if (lookahead == 'g') ADVANCE(150);
      END_STATE();
    case 41:
      if (lookahead == 'g') ADVANCE(73);
      END_STATE();
    case 42:
      if (lookahead == 'g') ADVANCE(36);
      END_STATE();
    case 43:
      if (lookahead == 'h') ADVANCE(69);
      if (lookahead == 'r') ADVANCE(80);
      if (lookahead == 'w') ADVANCE(47);
      END_STATE();
    case 44:
      if (lookahead == 'h') ADVANCE(46);
      if (lookahead == 'r') ADVANCE(11);
      END_STATE();
    case 45:
      if (lookahead == 'i') ADVANCE(82);
      if (lookahead == 'x') ADVANCE(137);
      END_STATE();
    case 46:
      if (lookahead == 'i') ADVANCE(78);
      END_STATE();
    case 47:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(63);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(15);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(16);
      END_STATE();
    case 51:
      if (lookahead == 'k') ADVANCE(139);
      END_STATE();
    case 52:
      if (lookahead == 'l') ADVANCE(14);
      END_STATE();
    case 53:
      if (lookahead == 'l') ADVANCE(66);
      if (lookahead == 'y') ADVANCE(13);
      END_STATE();
    case 54:
      if (lookahead == 'l') ADVANCE(8);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(65);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(79);
      END_STATE();
    case 57:
      if (lookahead == 'l') ADVANCE(67);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(74);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(55);
      END_STATE();
    case 60:
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 61:
      if (lookahead == 'n') ADVANCE(143);
      END_STATE();
    case 62:
      if (lookahead == 'n') ADVANCE(139);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(77);
      END_STATE();
    case 65:
      if (lookahead == 'o') ADVANCE(81);
      END_STATE();
    case 66:
      if (lookahead == 'o') ADVANCE(75);
      END_STATE();
    case 67:
      if (lookahead == 'o') ADVANCE(40);
      END_STATE();
    case 68:
      if (lookahead == 'p') ADVANCE(154);
      END_STATE();
    case 69:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 70:
      if (lookahead == 'r') ADVANCE(49);
      if (lookahead == 't') ADVANCE(76);
      END_STATE();
    case 71:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 72:
      if (lookahead == 's') ADVANCE(136);
      END_STATE();
    case 73:
      if (lookahead == 's') ADVANCE(151);
      END_STATE();
    case 74:
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 75:
      if (lookahead == 's') ADVANCE(35);
      END_STATE();
    case 76:
      if (lookahead == 't') ADVANCE(48);
      END_STATE();
    case 77:
      if (lookahead == 't') ADVANCE(10);
      END_STATE();
    case 78:
      if (lookahead == 't') ADVANCE(29);
      END_STATE();
    case 79:
      if (lookahead == 'u') ADVANCE(24);
      END_STATE();
    case 80:
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 81:
      if (lookahead == 'w') ADVANCE(139);
      END_STATE();
    case 82:
      if (lookahead == 'x') ADVANCE(137);
      END_STATE();
    case 83:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(142);
      END_STATE();
    case 84:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(83);
      END_STATE();
    case 85:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      END_STATE();
    case 86:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 87:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(5);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(6);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(7);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(107);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'a') ADVANCE(96);
      if (lookahead == 'u') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'c') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'd') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(119);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'e') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'f') ADVANCE(105);
      if (lookahead == 'n') ADVANCE(97);
      if (lookahead == 'p') ADVANCE(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'g') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(122);
      if (lookahead == 'r') ADVANCE(128);
      if (lookahead == 'w') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'h') ADVANCE(111);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'i') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'k') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(120);
      if (lookahead == 'y') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'l') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'n') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'o') ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'r') ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 's') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 't') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'u') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (lookahead == 'w') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_BAREWORD);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_NUMBER);
      if (lookahead == 'm') ADVANCE(72);
      if (lookahead == 'p') ADVANCE(45);
      if (lookahead == 's') ADVANCE(136);
      if (lookahead == 'x') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_DURATION);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_DISTANCE);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_QUANTITY);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_COLOR);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_COLOR);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_BOOLEAN);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_BOOLEAN);
      if (lookahead == 'c') ADVANCE(27);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_add);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_serial_dialog);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_settings);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_wrap);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
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
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [sym_QUOTED_STRING] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_NUMBER] = ACTIONS(1),
    [sym_DURATION] = ACTIONS(1),
    [sym_DISTANCE] = ACTIONS(1),
    [sym_QUANTITY] = ACTIONS(1),
    [sym_COLOR] = ACTIONS(1),
    [sym_BOOLEAN] = ACTIONS(1),
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
  },
  [1] = {
    [sym_source_file] = STATE(34),
    [sym_constant_expansion] = STATE(33),
    [sym__root] = STATE(3),
    [sym_include_macro] = STATE(3),
    [sym_constant_assignment] = STATE(3),
    [sym_add_serial_dialog_settings] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(7),
    [sym_CONSTANT] = ACTIONS(9),
    [anon_sym_include] = ACTIONS(11),
    [anon_sym_add] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
    STATE(40), 1,
      sym_constant_value_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(15), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(19), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [24] = 8,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(9), 1,
      sym_CONSTANT,
    ACTIONS(11), 1,
      anon_sym_include,
    ACTIONS(13), 1,
      anon_sym_add,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    STATE(33), 1,
      sym_constant_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(4), 5,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      aux_sym_source_file_repeat1,
  [54] = 8,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    ACTIONS(25), 1,
      anon_sym_LBRACK,
    ACTIONS(28), 1,
      sym_CONSTANT,
    ACTIONS(31), 1,
      anon_sym_include,
    ACTIONS(34), 1,
      anon_sym_add,
    STATE(33), 1,
      sym_constant_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(4), 5,
      sym__root,
      sym_include_macro,
      sym_constant_assignment,
      sym_add_serial_dialog_settings,
      aux_sym_source_file_repeat1,
  [84] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(37), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(39), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [102] = 3,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(41), 3,
      sym_BAREWORD,
      sym_QUOTED_STRING,
      sym_CONSTANT,
    ACTIONS(43), 6,
      sym_NUMBER,
      sym_DURATION,
      sym_DISTANCE,
      sym_QUANTITY,
      sym_COLOR,
      sym_BOOLEAN,
  [120] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(45), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_include,
      anon_sym_add,
  [132] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(47), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_include,
      anon_sym_add,
  [144] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(49), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_include,
      anon_sym_add,
  [156] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(51), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_CONSTANT,
      anon_sym_include,
      anon_sym_add,
  [168] = 4,
    ACTIONS(55), 1,
      anon_sym_LBRACK,
    STATE(46), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(53), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [183] = 4,
    ACTIONS(57), 1,
      anon_sym_RBRACE,
    ACTIONS(59), 1,
      anon_sym_wrap,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(13), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [198] = 4,
    ACTIONS(61), 1,
      anon_sym_RBRACE,
    ACTIONS(63), 1,
      anon_sym_wrap,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(13), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [213] = 4,
    ACTIONS(59), 1,
      anon_sym_wrap,
    ACTIONS(66), 1,
      anon_sym_RBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(12), 2,
      sym_serial_dialog_parameter,
      aux_sym_add_serial_dialog_settings_repeat1,
  [228] = 3,
    ACTIONS(70), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(68), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [240] = 4,
    ACTIONS(72), 1,
      anon_sym_COMMA,
    ACTIONS(74), 1,
      anon_sym_RBRACK,
    STATE(19), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [254] = 4,
    ACTIONS(72), 1,
      anon_sym_COMMA,
    ACTIONS(76), 1,
      anon_sym_RBRACK,
    STATE(16), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [268] = 4,
    ACTIONS(78), 1,
      anon_sym_COMMA,
    ACTIONS(80), 1,
      anon_sym_RBRACK,
    STATE(21), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [282] = 4,
    ACTIONS(82), 1,
      anon_sym_COMMA,
    ACTIONS(85), 1,
      anon_sym_RBRACK,
    STATE(19), 1,
      aux_sym_constant_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [296] = 4,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    ACTIONS(89), 1,
      anon_sym_RBRACK,
    STATE(24), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [310] = 4,
    ACTIONS(78), 1,
      anon_sym_COMMA,
    ACTIONS(91), 1,
      anon_sym_RBRACK,
    STATE(23), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [324] = 4,
    ACTIONS(93), 1,
      anon_sym_COMMA,
    ACTIONS(96), 1,
      anon_sym_RBRACK,
    STATE(22), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [338] = 4,
    ACTIONS(98), 1,
      anon_sym_COMMA,
    ACTIONS(101), 1,
      anon_sym_RBRACK,
    STATE(23), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [352] = 4,
    ACTIONS(87), 1,
      anon_sym_COMMA,
    ACTIONS(103), 1,
      anon_sym_RBRACK,
    STATE(22), 1,
      aux_sym_constant_value_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [366] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(96), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [375] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(105), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [384] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(101), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [393] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(107), 2,
      sym_NUMBER,
      sym_CONSTANT,
  [402] = 3,
    ACTIONS(109), 1,
      anon_sym_RBRACK,
    ACTIONS(111), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [413] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(113), 2,
      anon_sym_RBRACE,
      anon_sym_wrap,
  [422] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(85), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [431] = 2,
    ACTIONS(115), 1,
      anon_sym_settings,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [439] = 2,
    ACTIONS(117), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [447] = 2,
    ACTIONS(119), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [455] = 2,
    ACTIONS(121), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [463] = 2,
    ACTIONS(123), 1,
      sym_CONSTANT,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [471] = 2,
    ACTIONS(125), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [479] = 2,
    ACTIONS(127), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [487] = 2,
    ACTIONS(129), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [495] = 2,
    ACTIONS(131), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [503] = 2,
    ACTIONS(133), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [511] = 2,
    ACTIONS(135), 1,
      anon_sym_serial_dialog,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [519] = 2,
    ACTIONS(137), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [527] = 2,
    ACTIONS(139), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [535] = 2,
    ACTIONS(141), 1,
      anon_sym_LBRACE,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [543] = 2,
    ACTIONS(143), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [551] = 2,
    ACTIONS(145), 1,
      anon_sym_EQ,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 54,
  [SMALL_STATE(5)] = 84,
  [SMALL_STATE(6)] = 102,
  [SMALL_STATE(7)] = 120,
  [SMALL_STATE(8)] = 132,
  [SMALL_STATE(9)] = 144,
  [SMALL_STATE(10)] = 156,
  [SMALL_STATE(11)] = 168,
  [SMALL_STATE(12)] = 183,
  [SMALL_STATE(13)] = 198,
  [SMALL_STATE(14)] = 213,
  [SMALL_STATE(15)] = 228,
  [SMALL_STATE(16)] = 240,
  [SMALL_STATE(17)] = 254,
  [SMALL_STATE(18)] = 268,
  [SMALL_STATE(19)] = 282,
  [SMALL_STATE(20)] = 296,
  [SMALL_STATE(21)] = 310,
  [SMALL_STATE(22)] = 324,
  [SMALL_STATE(23)] = 338,
  [SMALL_STATE(24)] = 352,
  [SMALL_STATE(25)] = 366,
  [SMALL_STATE(26)] = 375,
  [SMALL_STATE(27)] = 384,
  [SMALL_STATE(28)] = 393,
  [SMALL_STATE(29)] = 402,
  [SMALL_STATE(30)] = 413,
  [SMALL_STATE(31)] = 422,
  [SMALL_STATE(32)] = 431,
  [SMALL_STATE(33)] = 439,
  [SMALL_STATE(34)] = 447,
  [SMALL_STATE(35)] = 455,
  [SMALL_STATE(36)] = 463,
  [SMALL_STATE(37)] = 471,
  [SMALL_STATE(38)] = 479,
  [SMALL_STATE(39)] = 487,
  [SMALL_STATE(40)] = 495,
  [SMALL_STATE(41)] = 503,
  [SMALL_STATE(42)] = 511,
  [SMALL_STATE(43)] = 519,
  [SMALL_STATE(44)] = 527,
  [SMALL_STATE(45)] = 535,
  [SMALL_STATE(46)] = 543,
  [SMALL_STATE(47)] = 551,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(42),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 6, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_add_serial_dialog_settings, 5, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_assignment, 4, 0, 2),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_add_serial_dialog_settings_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_expansion_repeat1, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_constant_value_expansion_repeat1, 2, 0, 0),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_serial_dialog_parameter, 2, 0, 3),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [119] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 3, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 2, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 3, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_value_expansion, 4, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_expansion, 4, 0, 0),
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
