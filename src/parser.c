#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 20
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 16
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  sym_block_comment = 1,
  sym_line_comment = 2,
  sym_QUOTED_STRING = 3,
  anon_sym_LBRACK = 4,
  anon_sym_COMMA = 5,
  anon_sym_RBRACK = 6,
  sym_CONSTANT = 7,
  anon_sym_include = 8,
  anon_sym_SEMI = 9,
  sym_source_file = 10,
  sym_quoted_string_expansion = 11,
  sym__root = 12,
  sym_include_macro = 13,
  aux_sym_source_file_repeat1 = 14,
  aux_sym_quoted_string_expansion_repeat1 = 15,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_block_comment] = "block_comment",
  [sym_line_comment] = "line_comment",
  [sym_QUOTED_STRING] = "QUOTED_STRING",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [sym_CONSTANT] = "CONSTANT",
  [anon_sym_include] = "include",
  [anon_sym_SEMI] = ";",
  [sym_source_file] = "source_file",
  [sym_quoted_string_expansion] = "quoted_string_expansion",
  [sym__root] = "_root",
  [sym_include_macro] = "include_macro",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_quoted_string_expansion_repeat1] = "quoted_string_expansion_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_block_comment] = sym_block_comment,
  [sym_line_comment] = sym_line_comment,
  [sym_QUOTED_STRING] = sym_QUOTED_STRING,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_CONSTANT] = sym_CONSTANT,
  [anon_sym_include] = anon_sym_include,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [sym_source_file] = sym_source_file,
  [sym_quoted_string_expansion] = sym_quoted_string_expansion,
  [sym__root] = sym__root,
  [sym_include_macro] = sym_include_macro,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_quoted_string_expansion_repeat1] = aux_sym_quoted_string_expansion_repeat1,
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
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_string_expansion] = {
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
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_string_expansion_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_fileName = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_fileName] = "fileName",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_fileName, 1},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(13);
      ADVANCE_MAP(
        '"', 1,
        '$', 11,
        ',', 18,
        '/', 2,
        ';', 22,
        '[', 17,
        ']', 19,
        'i', 9,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(16);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '/') ADVANCE(15);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(3);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(3);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == 'c') ADVANCE(8);
      END_STATE();
    case 6:
      if (lookahead == 'd') ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 8:
      if (lookahead == 'l') ADVANCE(10);
      END_STATE();
    case 9:
      if (lookahead == 'n') ADVANCE(5);
      END_STATE();
    case 10:
      if (lookahead == 'u') ADVANCE(6);
      END_STATE();
    case 11:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 12:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(1);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_block_comment);
      if (lookahead == '*') ADVANCE(3);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_QUOTED_STRING);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_CONSTANT);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_include);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
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
    [sym_CONSTANT] = ACTIONS(1),
    [anon_sym_include] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(14),
    [sym__root] = STATE(2),
    [sym_include_macro] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_block_comment] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(3),
    [anon_sym_include] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(7), 1,
      anon_sym_include,
    ACTIONS(9), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(3), 3,
      sym__root,
      sym_include_macro,
      aux_sym_source_file_repeat1,
  [16] = 4,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      anon_sym_include,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    STATE(3), 3,
      sym__root,
      sym_include_macro,
      aux_sym_source_file_repeat1,
  [32] = 4,
    ACTIONS(18), 1,
      anon_sym_LBRACK,
    STATE(15), 1,
      sym_quoted_string_expansion,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(16), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [47] = 3,
    ACTIONS(22), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(20), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [59] = 4,
    ACTIONS(24), 1,
      anon_sym_COMMA,
    ACTIONS(26), 1,
      anon_sym_RBRACK,
    STATE(8), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [73] = 3,
    ACTIONS(30), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(28), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [85] = 4,
    ACTIONS(30), 1,
      anon_sym_RBRACK,
    ACTIONS(32), 1,
      anon_sym_COMMA,
    STATE(10), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [99] = 3,
    ACTIONS(34), 1,
      anon_sym_RBRACK,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(28), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [111] = 4,
    ACTIONS(36), 1,
      anon_sym_COMMA,
    ACTIONS(39), 1,
      anon_sym_RBRACK,
    STATE(10), 1,
      aux_sym_quoted_string_expansion_repeat1,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [125] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(41), 2,
      ts_builtin_sym_end,
      anon_sym_include,
  [134] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(39), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [143] = 2,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
    ACTIONS(28), 2,
      sym_QUOTED_STRING,
      sym_CONSTANT,
  [152] = 2,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [160] = 2,
    ACTIONS(45), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [168] = 2,
    ACTIONS(47), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [176] = 2,
    ACTIONS(49), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [184] = 2,
    ACTIONS(51), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
  [192] = 2,
    ACTIONS(53), 1,
      anon_sym_SEMI,
    ACTIONS(3), 2,
      sym_block_comment,
      sym_line_comment,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 16,
  [SMALL_STATE(4)] = 32,
  [SMALL_STATE(5)] = 47,
  [SMALL_STATE(6)] = 59,
  [SMALL_STATE(7)] = 73,
  [SMALL_STATE(8)] = 85,
  [SMALL_STATE(9)] = 99,
  [SMALL_STATE(10)] = 111,
  [SMALL_STATE(11)] = 125,
  [SMALL_STATE(12)] = 134,
  [SMALL_STATE(13)] = 143,
  [SMALL_STATE(14)] = 152,
  [SMALL_STATE(15)] = 160,
  [SMALL_STATE(16)] = 168,
  [SMALL_STATE(17)] = 176,
  [SMALL_STATE(18)] = 184,
  [SMALL_STATE(19)] = 192,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [16] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [18] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quoted_string_expansion_repeat1, 2, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_macro, 3, 0, 1),
  [43] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 2, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 3, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 4, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_expansion, 5, 0, 0),
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
