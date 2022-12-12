#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 148
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 75
#define ALIAS_COUNT 0
#define TOKEN_COUNT 43
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 4

enum {
  sym_newline = 1,
  sym_comment = 2,
  anon_sym_if = 3,
  anon_sym_elif = 4,
  anon_sym_else = 5,
  anon_sym_for = 6,
  anon_sym_in = 7,
  anon_sym_LBRACE = 8,
  anon_sym_RBRACE = 9,
  anon_sym_continue = 10,
  anon_sym_break = 11,
  anon_sym_EQ = 12,
  sym_identifier = 13,
  anon_sym_LPAREN = 14,
  anon_sym_RPAREN = 15,
  anon_sym_COMMA = 16,
  anon_sym_PLUS = 17,
  anon_sym_DASH = 18,
  anon_sym_STAR = 19,
  anon_sym_SLASH = 20,
  anon_sym_PERCENT = 21,
  anon_sym_PIPE_PIPE = 22,
  anon_sym_AMP_AMP = 23,
  anon_sym_EQ_EQ = 24,
  anon_sym_BANG_EQ = 25,
  anon_sym_GT = 26,
  anon_sym_GT_EQ = 27,
  anon_sym_LT_EQ = 28,
  anon_sym_LT = 29,
  anon_sym_LBRACK = 30,
  anon_sym_RBRACK = 31,
  anon_sym_COLON = 32,
  anon_sym_nil = 33,
  anon_sym_null = 34,
  sym_number_lit = 35,
  anon_sym_DQUOTE = 36,
  aux_sym_string_lit_token1 = 37,
  anon_sym_SQUOTE = 38,
  aux_sym_string_lit_token2 = 39,
  anon_sym_true = 40,
  anon_sym_false = 41,
  sym_escape_sequence = 42,
  sym_source_file = 43,
  sym_inline_statement = 44,
  sym__stmt = 45,
  sym_if_stmt = 46,
  sym_for_in_stmt = 47,
  sym_block_stmts = 48,
  sym_continue_stmt = 49,
  sym_break_stmt = 50,
  sym_assign_stmt = 51,
  sym_expr_stmt = 52,
  sym__expr = 53,
  sym_paren_expr = 54,
  sym_call_expr = 55,
  sym_argument_list = 56,
  sym_binary_expr = 57,
  sym_index_expr = 58,
  sym_list_expr = 59,
  sym_list_elem = 60,
  sym_map_expr = 61,
  sym_map_elem = 62,
  sym__literal = 63,
  sym_nil_lit = 64,
  sym_string_lit = 65,
  sym_bool_lit = 66,
  aux_sym_source_file_repeat1 = 67,
  aux_sym_inline_statement_repeat1 = 68,
  aux_sym_if_stmt_repeat1 = 69,
  aux_sym_argument_list_repeat1 = 70,
  aux_sym_list_expr_repeat1 = 71,
  aux_sym_map_expr_repeat1 = 72,
  aux_sym_string_lit_repeat1 = 73,
  aux_sym_string_lit_repeat2 = 74,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_newline] = "newline",
  [sym_comment] = "comment",
  [anon_sym_if] = "if",
  [anon_sym_elif] = "elif",
  [anon_sym_else] = "else",
  [anon_sym_for] = "for",
  [anon_sym_in] = "in",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_continue] = "continue",
  [anon_sym_break] = "break",
  [anon_sym_EQ] = "=",
  [sym_identifier] = "identifier",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COMMA] = ",",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_LT] = "<",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_COLON] = ":",
  [anon_sym_nil] = "nil",
  [anon_sym_null] = "null",
  [sym_number_lit] = "number_lit",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_lit_token1] = "string_lit_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_lit_token2] = "string_lit_token2",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_escape_sequence] = "escape_sequence",
  [sym_source_file] = "source_file",
  [sym_inline_statement] = "inline_statement",
  [sym__stmt] = "_stmt",
  [sym_if_stmt] = "if_stmt",
  [sym_for_in_stmt] = "for_in_stmt",
  [sym_block_stmts] = "block_stmts",
  [sym_continue_stmt] = "continue_stmt",
  [sym_break_stmt] = "break_stmt",
  [sym_assign_stmt] = "assign_stmt",
  [sym_expr_stmt] = "expr_stmt",
  [sym__expr] = "_expr",
  [sym_paren_expr] = "paren_expr",
  [sym_call_expr] = "call_expr",
  [sym_argument_list] = "argument_list",
  [sym_binary_expr] = "binary_expr",
  [sym_index_expr] = "index_expr",
  [sym_list_expr] = "list_expr",
  [sym_list_elem] = "list_elem",
  [sym_map_expr] = "map_expr",
  [sym_map_elem] = "map_elem",
  [sym__literal] = "_literal",
  [sym_nil_lit] = "nil_lit",
  [sym_string_lit] = "string_lit",
  [sym_bool_lit] = "bool_lit",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_inline_statement_repeat1] = "inline_statement_repeat1",
  [aux_sym_if_stmt_repeat1] = "if_stmt_repeat1",
  [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
  [aux_sym_list_expr_repeat1] = "list_expr_repeat1",
  [aux_sym_map_expr_repeat1] = "map_expr_repeat1",
  [aux_sym_string_lit_repeat1] = "string_lit_repeat1",
  [aux_sym_string_lit_repeat2] = "string_lit_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_newline] = sym_newline,
  [sym_comment] = sym_comment,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_elif] = anon_sym_elif,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_continue] = anon_sym_continue,
  [anon_sym_break] = anon_sym_break,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_identifier] = sym_identifier,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_nil] = anon_sym_nil,
  [anon_sym_null] = anon_sym_null,
  [sym_number_lit] = sym_number_lit,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_lit_token1] = aux_sym_string_lit_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_lit_token2] = aux_sym_string_lit_token2,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_source_file] = sym_source_file,
  [sym_inline_statement] = sym_inline_statement,
  [sym__stmt] = sym__stmt,
  [sym_if_stmt] = sym_if_stmt,
  [sym_for_in_stmt] = sym_for_in_stmt,
  [sym_block_stmts] = sym_block_stmts,
  [sym_continue_stmt] = sym_continue_stmt,
  [sym_break_stmt] = sym_break_stmt,
  [sym_assign_stmt] = sym_assign_stmt,
  [sym_expr_stmt] = sym_expr_stmt,
  [sym__expr] = sym__expr,
  [sym_paren_expr] = sym_paren_expr,
  [sym_call_expr] = sym_call_expr,
  [sym_argument_list] = sym_argument_list,
  [sym_binary_expr] = sym_binary_expr,
  [sym_index_expr] = sym_index_expr,
  [sym_list_expr] = sym_list_expr,
  [sym_list_elem] = sym_list_elem,
  [sym_map_expr] = sym_map_expr,
  [sym_map_elem] = sym_map_elem,
  [sym__literal] = sym__literal,
  [sym_nil_lit] = sym_nil_lit,
  [sym_string_lit] = sym_string_lit,
  [sym_bool_lit] = sym_bool_lit,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_inline_statement_repeat1] = aux_sym_inline_statement_repeat1,
  [aux_sym_if_stmt_repeat1] = aux_sym_if_stmt_repeat1,
  [aux_sym_argument_list_repeat1] = aux_sym_argument_list_repeat1,
  [aux_sym_list_expr_repeat1] = aux_sym_list_expr_repeat1,
  [aux_sym_map_expr_repeat1] = aux_sym_map_expr_repeat1,
  [aux_sym_string_lit_repeat1] = aux_sym_string_lit_repeat1,
  [aux_sym_string_lit_repeat2] = aux_sym_string_lit_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_newline] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_elif] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
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
  [anon_sym_continue] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_break] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_nil] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_null] = {
    .visible = true,
    .named = false,
  },
  [sym_number_lit] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_lit_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_lit_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_statement] = {
    .visible = true,
    .named = true,
  },
  [sym__stmt] = {
    .visible = false,
    .named = true,
  },
  [sym_if_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_for_in_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_block_stmts] = {
    .visible = true,
    .named = true,
  },
  [sym_continue_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_break_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_assign_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym_expr_stmt] = {
    .visible = true,
    .named = true,
  },
  [sym__expr] = {
    .visible = false,
    .named = true,
  },
  [sym_paren_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_call_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_argument_list] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_index_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_list_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_list_elem] = {
    .visible = true,
    .named = true,
  },
  [sym_map_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_map_elem] = {
    .visible = true,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [sym_nil_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_string_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_bool_lit] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_inline_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_if_stmt_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_argument_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_list_expr_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_map_expr_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_lit_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_lit_repeat2] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_condition = 1,
  field_consequence = 2,
  field_left = 3,
  field_name = 4,
  field_operator = 5,
  field_right = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_condition] = "condition",
  [field_consequence] = "consequence",
  [field_left] = "left",
  [field_name] = "name",
  [field_operator] = "operator",
  [field_right] = "right",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 0},
  [1] =
    {field_condition, 1},
    {field_consequence, 2},
  [3] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
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
  [5] = 3,
  [6] = 6,
  [7] = 7,
  [8] = 7,
  [9] = 9,
  [10] = 10,
  [11] = 9,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 15,
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
  [27] = 21,
  [28] = 28,
  [29] = 14,
  [30] = 20,
  [31] = 19,
  [32] = 18,
  [33] = 17,
  [34] = 12,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 37,
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
  [51] = 36,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 48,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 22,
  [65] = 65,
  [66] = 65,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 50,
  [73] = 62,
  [74] = 54,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 43,
  [79] = 79,
  [80] = 44,
  [81] = 38,
  [82] = 45,
  [83] = 41,
  [84] = 77,
  [85] = 40,
  [86] = 61,
  [87] = 60,
  [88] = 42,
  [89] = 56,
  [90] = 90,
  [91] = 35,
  [92] = 58,
  [93] = 79,
  [94] = 75,
  [95] = 55,
  [96] = 53,
  [97] = 57,
  [98] = 46,
  [99] = 47,
  [100] = 49,
  [101] = 101,
  [102] = 52,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 106,
  [112] = 108,
  [113] = 110,
  [114] = 114,
  [115] = 109,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 118,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 121,
  [127] = 127,
  [128] = 123,
  [129] = 129,
  [130] = 125,
  [131] = 131,
  [132] = 129,
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
  [144] = 139,
  [145] = 145,
  [146] = 146,
  [147] = 147,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(52);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(133);
      if (lookahead == '#') ADVANCE(54);
      if (lookahead == '%') ADVANCE(102);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(136);
      if (lookahead == '(') ADVANCE(95);
      if (lookahead == ')') ADVANCE(96);
      if (lookahead == '*') ADVANCE(100);
      if (lookahead == '+') ADVANCE(98);
      if (lookahead == ',') ADVANCE(97);
      if (lookahead == '-') ADVANCE(99);
      if (lookahead == '/') ADVANCE(101);
      if (lookahead == ':') ADVANCE(113);
      if (lookahead == '<') ADVANCE(110);
      if (lookahead == '=') ADVANCE(68);
      if (lookahead == '>') ADVANCE(107);
      if (lookahead == '[') ADVANCE(111);
      if (lookahead == '\\') ADVANCE(42);
      if (lookahead == ']') ADVANCE(112);
      if (lookahead == 'b') ADVANCE(33);
      if (lookahead == 'c') ADVANCE(32);
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == 'f') ADVANCE(13);
      if (lookahead == 'i') ADVANCE(19);
      if (lookahead == 'n') ADVANCE(23);
      if (lookahead == 't') ADVANCE(34);
      if (lookahead == '{') ADVANCE(62);
      if (lookahead == '|') ADVANCE(40);
      if (lookahead == '}') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(50)
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(53);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '%') ADVANCE(102);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '(') ADVANCE(95);
      if (lookahead == '*') ADVANCE(100);
      if (lookahead == '+') ADVANCE(98);
      if (lookahead == '-') ADVANCE(99);
      if (lookahead == '/') ADVANCE(101);
      if (lookahead == '<') ADVANCE(110);
      if (lookahead == '=') ADVANCE(68);
      if (lookahead == '>') ADVANCE(107);
      if (lookahead == '[') ADVANCE(111);
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == '|') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == '\'') ADVANCE(136);
      if (lookahead == '\\') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(137);
      if (lookahead != 0) ADVANCE(138);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(5)
      if (lookahead == '"') ADVANCE(133);
      if (lookahead == '\\') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(134);
      if (lookahead != 0) ADVANCE(135);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(133);
      if (lookahead == '\'') ADVANCE(136);
      if (lookahead == '(') ADVANCE(95);
      if (lookahead == ')') ADVANCE(96);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(123);
      if (lookahead == '[') ADVANCE(111);
      if (lookahead == ']') ADVANCE(112);
      if (lookahead == 'f') ADVANCE(70);
      if (lookahead == 'n') ADVANCE(78);
      if (lookahead == 't') ADVANCE(88);
      if (lookahead == '{') ADVANCE(62);
      if (lookahead == '}') ADVANCE(63);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(124);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(133);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '&') ADVANCE(104);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(136);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(123);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(124);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(120);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(121);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(129);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(122);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(124);
      END_STATE();
    case 11:
      if (lookahead == '=') ADVANCE(106);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(24);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(139);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(141);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 19:
      if (lookahead == 'f') ADVANCE(55);
      if (lookahead == 'n') ADVANCE(61);
      END_STATE();
    case 20:
      if (lookahead == 'f') ADVANCE(57);
      END_STATE();
    case 21:
      if (lookahead == 'i') ADVANCE(20);
      if (lookahead == 's') ADVANCE(15);
      END_STATE();
    case 22:
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 23:
      if (lookahead == 'i') ADVANCE(27);
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 24:
      if (lookahead == 'k') ADVANCE(66);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(36);
      END_STATE();
    case 27:
      if (lookahead == 'l') ADVANCE(114);
      END_STATE();
    case 28:
      if (lookahead == 'l') ADVANCE(116);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(28);
      END_STATE();
    case 30:
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 31:
      if (lookahead == 'n') ADVANCE(39);
      END_STATE();
    case 32:
      if (lookahead == 'o') ADVANCE(30);
      END_STATE();
    case 33:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 34:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 35:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 36:
      if (lookahead == 's') ADVANCE(17);
      END_STATE();
    case 37:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 38:
      if (lookahead == 'u') ADVANCE(16);
      END_STATE();
    case 39:
      if (lookahead == 'u') ADVANCE(18);
      END_STATE();
    case 40:
      if (lookahead == '|') ADVANCE(103);
      END_STATE();
    case 41:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(41)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 42:
      if (lookahead == '"' ||
          lookahead == '/' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'f' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't' ||
          lookahead == 'u') ADVANCE(143);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(124);
      END_STATE();
    case 44:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(118);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(121);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(129);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(126);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(129);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(119);
      END_STATE();
    case 49:
      if (eof) ADVANCE(52);
      if (lookahead == '\n') ADVANCE(53);
      if (lookahead == '"') ADVANCE(133);
      if (lookahead == '#') ADVANCE(54);
      if (lookahead == '\'') ADVANCE(136);
      if (lookahead == '(') ADVANCE(95);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(123);
      if (lookahead == '[') ADVANCE(111);
      if (lookahead == 'b') ADVANCE(87);
      if (lookahead == 'c') ADVANCE(86);
      if (lookahead == 'f') ADVANCE(69);
      if (lookahead == 'i') ADVANCE(76);
      if (lookahead == 'n') ADVANCE(78);
      if (lookahead == 't') ADVANCE(88);
      if (lookahead == '{') ADVANCE(62);
      if (lookahead == '}') ADVANCE(63);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(49)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(124);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 50:
      if (eof) ADVANCE(52);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(133);
      if (lookahead == '#') ADVANCE(54);
      if (lookahead == '%') ADVANCE(102);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(136);
      if (lookahead == '(') ADVANCE(95);
      if (lookahead == ')') ADVANCE(96);
      if (lookahead == '*') ADVANCE(100);
      if (lookahead == '+') ADVANCE(98);
      if (lookahead == ',') ADVANCE(97);
      if (lookahead == '-') ADVANCE(99);
      if (lookahead == '/') ADVANCE(101);
      if (lookahead == ':') ADVANCE(113);
      if (lookahead == '<') ADVANCE(110);
      if (lookahead == '=') ADVANCE(68);
      if (lookahead == '>') ADVANCE(107);
      if (lookahead == '[') ADVANCE(111);
      if (lookahead == ']') ADVANCE(112);
      if (lookahead == 'b') ADVANCE(33);
      if (lookahead == 'c') ADVANCE(32);
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == 'f') ADVANCE(13);
      if (lookahead == 'i') ADVANCE(19);
      if (lookahead == 'n') ADVANCE(23);
      if (lookahead == 't') ADVANCE(34);
      if (lookahead == '{') ADVANCE(62);
      if (lookahead == '|') ADVANCE(40);
      if (lookahead == '}') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(50)
      END_STATE();
    case 51:
      if (eof) ADVANCE(52);
      if (lookahead == '"') ADVANCE(133);
      if (lookahead == '#') ADVANCE(54);
      if (lookahead == '\'') ADVANCE(136);
      if (lookahead == '(') ADVANCE(95);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(123);
      if (lookahead == '[') ADVANCE(111);
      if (lookahead == 'b') ADVANCE(87);
      if (lookahead == 'c') ADVANCE(86);
      if (lookahead == 'f') ADVANCE(69);
      if (lookahead == 'i') ADVANCE(76);
      if (lookahead == 'n') ADVANCE(78);
      if (lookahead == 't') ADVANCE(88);
      if (lookahead == '{') ADVANCE(62);
      if (lookahead == '}') ADVANCE(63);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(51)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(124);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_newline);
      if (lookahead == '\n') ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_elif);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_for);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_continue);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_continue);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_break);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(105);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(80);
      if (lookahead == 'o') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(81);
      if (lookahead == 'u') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(108);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(109);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_nil);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_nil);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_null);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(118);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(119);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'E') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(119);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(45);
      if (lookahead == '.') ADVANCE(130);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(129);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'b') ADVANCE(128);
      if (lookahead == 'x') ADVANCE(47);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(127);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(121);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(45);
      if (lookahead == '.') ADVANCE(130);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(129);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(127);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(121);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(43);
      if (lookahead == '.') ADVANCE(130);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'b') ADVANCE(43);
      if (lookahead == 'x') ADVANCE(47);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(124);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(43);
      if (lookahead == '.') ADVANCE(130);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'b') ADVANCE(10);
      if (lookahead == 'x') ADVANCE(9);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(124);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(43);
      if (lookahead == '.') ADVANCE(130);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(124);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(46);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(126);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(48);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(125);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(126);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(46);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(126);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(125);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(126);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '.') ADVANCE(130);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(129);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(48);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(127);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(129);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '.') ADVANCE(130);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(129);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(127);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(129);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(121);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '.') ADVANCE(130);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(129);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(127);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(129);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(126);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(125);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(126);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(119);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'E') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(119);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(132);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_string_lit_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(135);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_string_lit_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(135);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_string_lit_token2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(138);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_string_lit_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(94);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 51},
  [2] = {.lex_state = 51},
  [3] = {.lex_state = 51},
  [4] = {.lex_state = 51},
  [5] = {.lex_state = 51},
  [6] = {.lex_state = 51},
  [7] = {.lex_state = 4},
  [8] = {.lex_state = 4},
  [9] = {.lex_state = 4},
  [10] = {.lex_state = 4},
  [11] = {.lex_state = 4},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 4},
  [16] = {.lex_state = 4},
  [17] = {.lex_state = 4},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 4},
  [20] = {.lex_state = 4},
  [21] = {.lex_state = 4},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 4},
  [24] = {.lex_state = 4},
  [25] = {.lex_state = 4},
  [26] = {.lex_state = 4},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 4},
  [29] = {.lex_state = 4},
  [30] = {.lex_state = 4},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 4},
  [33] = {.lex_state = 4},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 49},
  [37] = {.lex_state = 49},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 49},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 49},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 49},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 49},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 1},
  [73] = {.lex_state = 1},
  [74] = {.lex_state = 1},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 1},
  [79] = {.lex_state = 4},
  [80] = {.lex_state = 1},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 1},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 1},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 1},
  [88] = {.lex_state = 1},
  [89] = {.lex_state = 1},
  [90] = {.lex_state = 1},
  [91] = {.lex_state = 1},
  [92] = {.lex_state = 1},
  [93] = {.lex_state = 4},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 1},
  [96] = {.lex_state = 1},
  [97] = {.lex_state = 1},
  [98] = {.lex_state = 1},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 1},
  [102] = {.lex_state = 1},
  [103] = {.lex_state = 4},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 3},
  [107] = {.lex_state = 1},
  [108] = {.lex_state = 2},
  [109] = {.lex_state = 3},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 3},
  [112] = {.lex_state = 2},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 3},
  [115] = {.lex_state = 3},
  [116] = {.lex_state = 1},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 1},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 1},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 1},
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
  [138] = {.lex_state = 49},
  [139] = {.lex_state = 49},
  [140] = {.lex_state = 49},
  [141] = {.lex_state = 41},
  [142] = {.lex_state = 49},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 49},
  [145] = {.lex_state = 49},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 49},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_elif] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_continue] = ACTIONS(1),
    [anon_sym_break] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_nil] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(143),
    [sym_inline_statement] = STATE(2),
    [sym__stmt] = STATE(144),
    [sym_if_stmt] = STATE(144),
    [sym_for_in_stmt] = STATE(144),
    [sym_continue_stmt] = STATE(144),
    [sym_break_stmt] = STATE(144),
    [sym_assign_stmt] = STATE(144),
    [sym_expr_stmt] = STATE(144),
    [sym__expr] = STATE(101),
    [sym_paren_expr] = STATE(101),
    [sym_call_expr] = STATE(101),
    [sym_binary_expr] = STATE(101),
    [sym_index_expr] = STATE(101),
    [sym_list_expr] = STATE(101),
    [sym_map_expr] = STATE(101),
    [sym__literal] = STATE(101),
    [sym_nil_lit] = STATE(101),
    [sym_string_lit] = STATE(101),
    [sym_bool_lit] = STATE(101),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_comment] = ACTIONS(5),
    [anon_sym_if] = ACTIONS(7),
    [anon_sym_for] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_continue] = ACTIONS(13),
    [anon_sym_break] = ACTIONS(15),
    [sym_identifier] = ACTIONS(17),
    [anon_sym_LPAREN] = ACTIONS(19),
    [anon_sym_LBRACK] = ACTIONS(21),
    [anon_sym_nil] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(23),
    [sym_number_lit] = ACTIONS(25),
    [anon_sym_DQUOTE] = ACTIONS(27),
    [anon_sym_SQUOTE] = ACTIONS(29),
    [anon_sym_true] = ACTIONS(31),
    [anon_sym_false] = ACTIONS(31),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 18,
    ACTIONS(5), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_if,
    ACTIONS(9), 1,
      anon_sym_for,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_break,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(25), 1,
      sym_number_lit,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(5), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(144), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
    STATE(101), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [74] = 18,
    ACTIONS(35), 1,
      sym_comment,
    ACTIONS(38), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_for,
    ACTIONS(44), 1,
      anon_sym_LBRACE,
    ACTIONS(47), 1,
      anon_sym_RBRACE,
    ACTIONS(49), 1,
      anon_sym_continue,
    ACTIONS(52), 1,
      anon_sym_break,
    ACTIONS(55), 1,
      sym_identifier,
    ACTIONS(58), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(67), 1,
      sym_number_lit,
    ACTIONS(70), 1,
      anon_sym_DQUOTE,
    ACTIONS(73), 1,
      anon_sym_SQUOTE,
    ACTIONS(64), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(76), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(3), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(139), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
    STATE(101), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [148] = 18,
    ACTIONS(7), 1,
      anon_sym_if,
    ACTIONS(9), 1,
      anon_sym_for,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_break,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(25), 1,
      sym_number_lit,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(79), 1,
      sym_comment,
    ACTIONS(81), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(3), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(139), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
    STATE(101), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [222] = 18,
    ACTIONS(38), 1,
      anon_sym_if,
    ACTIONS(41), 1,
      anon_sym_for,
    ACTIONS(44), 1,
      anon_sym_LBRACE,
    ACTIONS(47), 1,
      ts_builtin_sym_end,
    ACTIONS(49), 1,
      anon_sym_continue,
    ACTIONS(52), 1,
      anon_sym_break,
    ACTIONS(55), 1,
      sym_identifier,
    ACTIONS(58), 1,
      anon_sym_LPAREN,
    ACTIONS(61), 1,
      anon_sym_LBRACK,
    ACTIONS(67), 1,
      sym_number_lit,
    ACTIONS(70), 1,
      anon_sym_DQUOTE,
    ACTIONS(73), 1,
      anon_sym_SQUOTE,
    ACTIONS(83), 1,
      sym_comment,
    ACTIONS(64), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(76), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(5), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(144), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
    STATE(101), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [296] = 18,
    ACTIONS(7), 1,
      anon_sym_if,
    ACTIONS(9), 1,
      anon_sym_for,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(13), 1,
      anon_sym_continue,
    ACTIONS(15), 1,
      anon_sym_break,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(25), 1,
      sym_number_lit,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(79), 1,
      sym_comment,
    ACTIONS(86), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(139), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
    STATE(101), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [370] = 12,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(90), 1,
      anon_sym_RBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(100), 1,
      sym_number_lit,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    STATE(132), 1,
      sym_map_elem,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(76), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [419] = 12,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(100), 1,
      sym_number_lit,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(108), 1,
      anon_sym_RBRACE,
    STATE(129), 1,
      sym_map_elem,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(76), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [468] = 11,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(110), 1,
      anon_sym_RPAREN,
    ACTIONS(112), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(66), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [514] = 11,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(100), 1,
      sym_number_lit,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    STATE(133), 1,
      sym_map_elem,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(76), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [560] = 11,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(114), 1,
      anon_sym_RPAREN,
    ACTIONS(116), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(65), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [606] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(118), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(44), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [649] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(120), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(68), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [692] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(122), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(75), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [735] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(124), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(77), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [778] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(84), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [821] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(128), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(45), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [864] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(130), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(46), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [907] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(132), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(47), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [950] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(134), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(49), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [993] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(136), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(50), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1036] = 5,
    ACTIONS(140), 1,
      anon_sym_LPAREN,
    ACTIONS(144), 1,
      anon_sym_LBRACK,
    STATE(62), 1,
      sym_argument_list,
    ACTIONS(142), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(138), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1069] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(146), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(69), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1112] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(148), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(70), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1155] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(150), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(71), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1198] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(152), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(67), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1241] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(154), 1,
      sym_identifier,
    ACTIONS(156), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(72), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1284] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(154), 1,
      sym_identifier,
    ACTIONS(158), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(90), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1327] = 10,
    ACTIONS(88), 1,
      anon_sym_LBRACE,
    ACTIONS(92), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACK,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(160), 1,
      sym_number_lit,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(94), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1370] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(154), 1,
      sym_identifier,
    ACTIONS(162), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(100), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1413] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(154), 1,
      sym_identifier,
    ACTIONS(164), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(99), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1456] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(154), 1,
      sym_identifier,
    ACTIONS(166), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(98), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1499] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(154), 1,
      sym_identifier,
    ACTIONS(168), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(82), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1542] = 10,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(154), 1,
      sym_identifier,
    ACTIONS(170), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(80), 11,
      sym__expr,
      sym_paren_expr,
      sym_call_expr,
      sym_binary_expr,
      sym_index_expr,
      sym_list_expr,
      sym_map_expr,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [1585] = 2,
    ACTIONS(174), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(172), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1609] = 4,
    ACTIONS(176), 1,
      ts_builtin_sym_end,
    ACTIONS(178), 1,
      sym_newline,
    STATE(37), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(180), 16,
      sym_comment,
      anon_sym_if,
      anon_sym_for,
      anon_sym_LBRACE,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_nil,
      anon_sym_null,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1637] = 4,
    ACTIONS(182), 1,
      ts_builtin_sym_end,
    ACTIONS(184), 1,
      sym_newline,
    STATE(37), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(187), 16,
      sym_comment,
      anon_sym_if,
      anon_sym_for,
      anon_sym_LBRACE,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_nil,
      anon_sym_null,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1665] = 2,
    ACTIONS(191), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(189), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1689] = 3,
    ACTIONS(193), 1,
      sym_newline,
    STATE(39), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(187), 17,
      sym_comment,
      anon_sym_if,
      anon_sym_for,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_nil,
      anon_sym_null,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1715] = 2,
    ACTIONS(198), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(196), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1739] = 2,
    ACTIONS(202), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(200), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1763] = 2,
    ACTIONS(206), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(204), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1787] = 2,
    ACTIONS(210), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(208), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1811] = 4,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(218), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(212), 12,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1839] = 7,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(212), 8,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1873] = 5,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(212), 10,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1903] = 6,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(212), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE_PIPE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1935] = 4,
    ACTIONS(228), 1,
      ts_builtin_sym_end,
    ACTIONS(230), 1,
      sym_newline,
    STATE(36), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(232), 16,
      sym_comment,
      anon_sym_if,
      anon_sym_for,
      anon_sym_LBRACE,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_nil,
      anon_sym_null,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1963] = 2,
    ACTIONS(218), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(212), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [1987] = 3,
    ACTIONS(218), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(212), 14,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2013] = 3,
    ACTIONS(234), 1,
      sym_newline,
    STATE(39), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(180), 17,
      sym_comment,
      anon_sym_if,
      anon_sym_for,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_nil,
      anon_sym_null,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [2039] = 2,
    ACTIONS(238), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(236), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2063] = 2,
    ACTIONS(242), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(240), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2087] = 2,
    ACTIONS(246), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(244), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2111] = 2,
    ACTIONS(250), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(248), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2135] = 2,
    ACTIONS(254), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(252), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2159] = 2,
    ACTIONS(258), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(256), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2183] = 2,
    ACTIONS(262), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(260), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2207] = 3,
    ACTIONS(264), 1,
      sym_newline,
    STATE(51), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(232), 17,
      sym_comment,
      anon_sym_if,
      anon_sym_for,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      anon_sym_nil,
      anon_sym_null,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [2233] = 2,
    ACTIONS(268), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(266), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2257] = 2,
    ACTIONS(272), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(270), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2281] = 2,
    ACTIONS(276), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(274), 17,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2305] = 6,
    ACTIONS(138), 1,
      sym_newline,
    ACTIONS(278), 1,
      anon_sym_EQ,
    ACTIONS(280), 1,
      anon_sym_LPAREN,
    ACTIONS(282), 1,
      anon_sym_LBRACK,
    STATE(73), 1,
      sym_argument_list,
    ACTIONS(142), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2336] = 5,
    ACTIONS(138), 1,
      sym_newline,
    ACTIONS(280), 1,
      anon_sym_LPAREN,
    ACTIONS(282), 1,
      anon_sym_LBRACK,
    STATE(73), 1,
      sym_argument_list,
    ACTIONS(142), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2364] = 10,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(284), 1,
      anon_sym_RPAREN,
    ACTIONS(286), 1,
      anon_sym_COMMA,
    STATE(118), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2401] = 10,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(286), 1,
      anon_sym_COMMA,
    ACTIONS(290), 1,
      anon_sym_RPAREN,
    STATE(122), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2438] = 9,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    STATE(127), 1,
      sym_block_stmts,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2472] = 9,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    STATE(116), 1,
      sym_block_stmts,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2506] = 8,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(294), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2538] = 9,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    STATE(147), 1,
      sym_block_stmts,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2572] = 8,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(296), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2604] = 3,
    ACTIONS(212), 1,
      sym_newline,
    ACTIONS(298), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(218), 10,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2625] = 2,
    ACTIONS(274), 1,
      sym_newline,
    ACTIONS(276), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2644] = 2,
    ACTIONS(244), 1,
      sym_newline,
    ACTIONS(246), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2663] = 8,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(300), 1,
      anon_sym_RBRACK,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2694] = 8,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(302), 1,
      anon_sym_COLON,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2725] = 8,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(304), 1,
      anon_sym_RPAREN,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2756] = 2,
    ACTIONS(208), 1,
      sym_newline,
    ACTIONS(210), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2775] = 9,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(306), 1,
      sym_identifier,
    ACTIONS(308), 1,
      anon_sym_RBRACK,
    ACTIONS(310), 1,
      sym_number_lit,
    STATE(130), 1,
      sym_list_elem,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(135), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [2808] = 4,
    ACTIONS(212), 1,
      sym_newline,
    ACTIONS(312), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(298), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(218), 8,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2831] = 2,
    ACTIONS(189), 1,
      sym_newline,
    ACTIONS(191), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2850] = 7,
    ACTIONS(212), 1,
      sym_newline,
    ACTIONS(314), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(316), 1,
      anon_sym_AMP_AMP,
    ACTIONS(218), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(312), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(298), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(318), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2879] = 2,
    ACTIONS(200), 1,
      sym_newline,
    ACTIONS(202), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2898] = 8,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(320), 1,
      anon_sym_RPAREN,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2929] = 2,
    ACTIONS(196), 1,
      sym_newline,
    ACTIONS(198), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2948] = 2,
    ACTIONS(270), 1,
      sym_newline,
    ACTIONS(272), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2967] = 2,
    ACTIONS(266), 1,
      sym_newline,
    ACTIONS(268), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [2986] = 2,
    ACTIONS(204), 1,
      sym_newline,
    ACTIONS(206), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3005] = 2,
    ACTIONS(252), 1,
      sym_newline,
    ACTIONS(254), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3024] = 7,
    ACTIONS(314), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(316), 1,
      anon_sym_AMP_AMP,
    ACTIONS(322), 1,
      sym_newline,
    ACTIONS(312), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(324), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(298), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(318), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3053] = 2,
    ACTIONS(172), 1,
      sym_newline,
    ACTIONS(174), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3072] = 2,
    ACTIONS(260), 1,
      sym_newline,
    ACTIONS(262), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3091] = 9,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(306), 1,
      sym_identifier,
    ACTIONS(310), 1,
      sym_number_lit,
    ACTIONS(326), 1,
      anon_sym_RBRACK,
    STATE(125), 1,
      sym_list_elem,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(135), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [3124] = 8,
    ACTIONS(220), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(222), 1,
      anon_sym_AMP_AMP,
    ACTIONS(328), 1,
      anon_sym_RBRACK,
    ACTIONS(214), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(224), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(226), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(288), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(216), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3155] = 2,
    ACTIONS(248), 1,
      sym_newline,
    ACTIONS(250), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3174] = 2,
    ACTIONS(240), 1,
      sym_newline,
    ACTIONS(242), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3193] = 2,
    ACTIONS(256), 1,
      sym_newline,
    ACTIONS(258), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3212] = 5,
    ACTIONS(212), 1,
      sym_newline,
    ACTIONS(312), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(298), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(218), 4,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(318), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3237] = 6,
    ACTIONS(212), 1,
      sym_newline,
    ACTIONS(316), 1,
      anon_sym_AMP_AMP,
    ACTIONS(312), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(218), 3,
      anon_sym_PIPE_PIPE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(298), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(318), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3264] = 2,
    ACTIONS(212), 1,
      sym_newline,
    ACTIONS(218), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3283] = 7,
    ACTIONS(314), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(316), 1,
      anon_sym_AMP_AMP,
    ACTIONS(330), 1,
      sym_newline,
    ACTIONS(312), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(324), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(298), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(318), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3312] = 2,
    ACTIONS(236), 1,
      sym_newline,
    ACTIONS(238), 13,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3331] = 8,
    ACTIONS(102), 1,
      anon_sym_DQUOTE,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
    ACTIONS(306), 1,
      sym_identifier,
    ACTIONS(310), 1,
      sym_number_lit,
    STATE(134), 1,
      sym_list_elem,
    ACTIONS(98), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(106), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(135), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [3361] = 4,
    ACTIONS(332), 1,
      sym_newline,
    ACTIONS(334), 1,
      anon_sym_elif,
    ACTIONS(337), 1,
      anon_sym_else,
    STATE(104), 1,
      aux_sym_if_stmt_repeat1,
  [3374] = 3,
    ACTIONS(339), 1,
      anon_sym_SQUOTE,
    STATE(105), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(341), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3385] = 3,
    ACTIONS(344), 1,
      anon_sym_DQUOTE,
    STATE(115), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(346), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3396] = 4,
    ACTIONS(348), 1,
      sym_newline,
    ACTIONS(350), 1,
      anon_sym_elif,
    ACTIONS(352), 1,
      anon_sym_else,
    STATE(104), 1,
      aux_sym_if_stmt_repeat1,
  [3409] = 3,
    ACTIONS(354), 1,
      anon_sym_SQUOTE,
    STATE(105), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(356), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3420] = 3,
    ACTIONS(354), 1,
      anon_sym_DQUOTE,
    STATE(114), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(358), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3431] = 3,
    ACTIONS(360), 1,
      anon_sym_SQUOTE,
    STATE(108), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(362), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3442] = 3,
    ACTIONS(360), 1,
      anon_sym_DQUOTE,
    STATE(109), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(364), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3453] = 3,
    ACTIONS(366), 1,
      anon_sym_SQUOTE,
    STATE(105), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(356), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3464] = 3,
    ACTIONS(344), 1,
      anon_sym_SQUOTE,
    STATE(112), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(368), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3475] = 3,
    ACTIONS(370), 1,
      anon_sym_DQUOTE,
    STATE(114), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(372), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3486] = 3,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(114), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(358), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3497] = 4,
    ACTIONS(350), 1,
      anon_sym_elif,
    ACTIONS(375), 1,
      sym_newline,
    ACTIONS(377), 1,
      anon_sym_else,
    STATE(107), 1,
      aux_sym_if_stmt_repeat1,
  [3510] = 3,
    ACTIONS(379), 1,
      anon_sym_COMMA,
    ACTIONS(382), 1,
      anon_sym_RBRACK,
    STATE(117), 1,
      aux_sym_list_expr_repeat1,
  [3520] = 3,
    ACTIONS(286), 1,
      anon_sym_COMMA,
    ACTIONS(384), 1,
      anon_sym_RPAREN,
    STATE(119), 1,
      aux_sym_argument_list_repeat1,
  [3530] = 3,
    ACTIONS(294), 1,
      anon_sym_RPAREN,
    ACTIONS(386), 1,
      anon_sym_COMMA,
    STATE(119), 1,
      aux_sym_argument_list_repeat1,
  [3540] = 2,
    ACTIONS(389), 1,
      sym_newline,
    ACTIONS(391), 2,
      anon_sym_elif,
      anon_sym_else,
  [3548] = 3,
    ACTIONS(393), 1,
      anon_sym_RBRACE,
    ACTIONS(395), 1,
      anon_sym_COMMA,
    STATE(131), 1,
      aux_sym_map_expr_repeat1,
  [3558] = 3,
    ACTIONS(286), 1,
      anon_sym_COMMA,
    ACTIONS(397), 1,
      anon_sym_RPAREN,
    STATE(119), 1,
      aux_sym_argument_list_repeat1,
  [3568] = 3,
    ACTIONS(399), 1,
      anon_sym_COMMA,
    ACTIONS(401), 1,
      anon_sym_RBRACK,
    STATE(117), 1,
      aux_sym_list_expr_repeat1,
  [3578] = 2,
    ACTIONS(403), 1,
      sym_newline,
    ACTIONS(405), 2,
      anon_sym_elif,
      anon_sym_else,
  [3586] = 3,
    ACTIONS(399), 1,
      anon_sym_COMMA,
    ACTIONS(407), 1,
      anon_sym_RBRACK,
    STATE(128), 1,
      aux_sym_list_expr_repeat1,
  [3596] = 3,
    ACTIONS(395), 1,
      anon_sym_COMMA,
    ACTIONS(409), 1,
      anon_sym_RBRACE,
    STATE(131), 1,
      aux_sym_map_expr_repeat1,
  [3606] = 2,
    ACTIONS(411), 1,
      sym_newline,
    ACTIONS(413), 2,
      anon_sym_elif,
      anon_sym_else,
  [3614] = 3,
    ACTIONS(399), 1,
      anon_sym_COMMA,
    ACTIONS(415), 1,
      anon_sym_RBRACK,
    STATE(117), 1,
      aux_sym_list_expr_repeat1,
  [3624] = 3,
    ACTIONS(395), 1,
      anon_sym_COMMA,
    ACTIONS(417), 1,
      anon_sym_RBRACE,
    STATE(121), 1,
      aux_sym_map_expr_repeat1,
  [3634] = 3,
    ACTIONS(399), 1,
      anon_sym_COMMA,
    ACTIONS(419), 1,
      anon_sym_RBRACK,
    STATE(123), 1,
      aux_sym_list_expr_repeat1,
  [3644] = 3,
    ACTIONS(421), 1,
      anon_sym_RBRACE,
    ACTIONS(423), 1,
      anon_sym_COMMA,
    STATE(131), 1,
      aux_sym_map_expr_repeat1,
  [3654] = 3,
    ACTIONS(395), 1,
      anon_sym_COMMA,
    ACTIONS(426), 1,
      anon_sym_RBRACE,
    STATE(126), 1,
      aux_sym_map_expr_repeat1,
  [3664] = 1,
    ACTIONS(421), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [3669] = 1,
    ACTIONS(382), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3674] = 1,
    ACTIONS(428), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [3679] = 2,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    STATE(145), 1,
      sym_block_stmts,
  [3686] = 2,
    ACTIONS(292), 1,
      anon_sym_LBRACE,
    STATE(138), 1,
      sym_block_stmts,
  [3693] = 1,
    ACTIONS(430), 1,
      sym_newline,
  [3697] = 1,
    ACTIONS(432), 1,
      sym_newline,
  [3701] = 1,
    ACTIONS(434), 1,
      sym_newline,
  [3705] = 1,
    ACTIONS(436), 1,
      sym_identifier,
  [3709] = 1,
    ACTIONS(438), 1,
      sym_newline,
  [3713] = 1,
    ACTIONS(440), 1,
      ts_builtin_sym_end,
  [3717] = 1,
    ACTIONS(442), 1,
      sym_newline,
  [3721] = 1,
    ACTIONS(444), 1,
      sym_newline,
  [3725] = 1,
    ACTIONS(446), 1,
      anon_sym_in,
  [3729] = 1,
    ACTIONS(448), 1,
      sym_newline,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 74,
  [SMALL_STATE(4)] = 148,
  [SMALL_STATE(5)] = 222,
  [SMALL_STATE(6)] = 296,
  [SMALL_STATE(7)] = 370,
  [SMALL_STATE(8)] = 419,
  [SMALL_STATE(9)] = 468,
  [SMALL_STATE(10)] = 514,
  [SMALL_STATE(11)] = 560,
  [SMALL_STATE(12)] = 606,
  [SMALL_STATE(13)] = 649,
  [SMALL_STATE(14)] = 692,
  [SMALL_STATE(15)] = 735,
  [SMALL_STATE(16)] = 778,
  [SMALL_STATE(17)] = 821,
  [SMALL_STATE(18)] = 864,
  [SMALL_STATE(19)] = 907,
  [SMALL_STATE(20)] = 950,
  [SMALL_STATE(21)] = 993,
  [SMALL_STATE(22)] = 1036,
  [SMALL_STATE(23)] = 1069,
  [SMALL_STATE(24)] = 1112,
  [SMALL_STATE(25)] = 1155,
  [SMALL_STATE(26)] = 1198,
  [SMALL_STATE(27)] = 1241,
  [SMALL_STATE(28)] = 1284,
  [SMALL_STATE(29)] = 1327,
  [SMALL_STATE(30)] = 1370,
  [SMALL_STATE(31)] = 1413,
  [SMALL_STATE(32)] = 1456,
  [SMALL_STATE(33)] = 1499,
  [SMALL_STATE(34)] = 1542,
  [SMALL_STATE(35)] = 1585,
  [SMALL_STATE(36)] = 1609,
  [SMALL_STATE(37)] = 1637,
  [SMALL_STATE(38)] = 1665,
  [SMALL_STATE(39)] = 1689,
  [SMALL_STATE(40)] = 1715,
  [SMALL_STATE(41)] = 1739,
  [SMALL_STATE(42)] = 1763,
  [SMALL_STATE(43)] = 1787,
  [SMALL_STATE(44)] = 1811,
  [SMALL_STATE(45)] = 1839,
  [SMALL_STATE(46)] = 1873,
  [SMALL_STATE(47)] = 1903,
  [SMALL_STATE(48)] = 1935,
  [SMALL_STATE(49)] = 1963,
  [SMALL_STATE(50)] = 1987,
  [SMALL_STATE(51)] = 2013,
  [SMALL_STATE(52)] = 2039,
  [SMALL_STATE(53)] = 2063,
  [SMALL_STATE(54)] = 2087,
  [SMALL_STATE(55)] = 2111,
  [SMALL_STATE(56)] = 2135,
  [SMALL_STATE(57)] = 2159,
  [SMALL_STATE(58)] = 2183,
  [SMALL_STATE(59)] = 2207,
  [SMALL_STATE(60)] = 2233,
  [SMALL_STATE(61)] = 2257,
  [SMALL_STATE(62)] = 2281,
  [SMALL_STATE(63)] = 2305,
  [SMALL_STATE(64)] = 2336,
  [SMALL_STATE(65)] = 2364,
  [SMALL_STATE(66)] = 2401,
  [SMALL_STATE(67)] = 2438,
  [SMALL_STATE(68)] = 2472,
  [SMALL_STATE(69)] = 2506,
  [SMALL_STATE(70)] = 2538,
  [SMALL_STATE(71)] = 2572,
  [SMALL_STATE(72)] = 2604,
  [SMALL_STATE(73)] = 2625,
  [SMALL_STATE(74)] = 2644,
  [SMALL_STATE(75)] = 2663,
  [SMALL_STATE(76)] = 2694,
  [SMALL_STATE(77)] = 2725,
  [SMALL_STATE(78)] = 2756,
  [SMALL_STATE(79)] = 2775,
  [SMALL_STATE(80)] = 2808,
  [SMALL_STATE(81)] = 2831,
  [SMALL_STATE(82)] = 2850,
  [SMALL_STATE(83)] = 2879,
  [SMALL_STATE(84)] = 2898,
  [SMALL_STATE(85)] = 2929,
  [SMALL_STATE(86)] = 2948,
  [SMALL_STATE(87)] = 2967,
  [SMALL_STATE(88)] = 2986,
  [SMALL_STATE(89)] = 3005,
  [SMALL_STATE(90)] = 3024,
  [SMALL_STATE(91)] = 3053,
  [SMALL_STATE(92)] = 3072,
  [SMALL_STATE(93)] = 3091,
  [SMALL_STATE(94)] = 3124,
  [SMALL_STATE(95)] = 3155,
  [SMALL_STATE(96)] = 3174,
  [SMALL_STATE(97)] = 3193,
  [SMALL_STATE(98)] = 3212,
  [SMALL_STATE(99)] = 3237,
  [SMALL_STATE(100)] = 3264,
  [SMALL_STATE(101)] = 3283,
  [SMALL_STATE(102)] = 3312,
  [SMALL_STATE(103)] = 3331,
  [SMALL_STATE(104)] = 3361,
  [SMALL_STATE(105)] = 3374,
  [SMALL_STATE(106)] = 3385,
  [SMALL_STATE(107)] = 3396,
  [SMALL_STATE(108)] = 3409,
  [SMALL_STATE(109)] = 3420,
  [SMALL_STATE(110)] = 3431,
  [SMALL_STATE(111)] = 3442,
  [SMALL_STATE(112)] = 3453,
  [SMALL_STATE(113)] = 3464,
  [SMALL_STATE(114)] = 3475,
  [SMALL_STATE(115)] = 3486,
  [SMALL_STATE(116)] = 3497,
  [SMALL_STATE(117)] = 3510,
  [SMALL_STATE(118)] = 3520,
  [SMALL_STATE(119)] = 3530,
  [SMALL_STATE(120)] = 3540,
  [SMALL_STATE(121)] = 3548,
  [SMALL_STATE(122)] = 3558,
  [SMALL_STATE(123)] = 3568,
  [SMALL_STATE(124)] = 3578,
  [SMALL_STATE(125)] = 3586,
  [SMALL_STATE(126)] = 3596,
  [SMALL_STATE(127)] = 3606,
  [SMALL_STATE(128)] = 3614,
  [SMALL_STATE(129)] = 3624,
  [SMALL_STATE(130)] = 3634,
  [SMALL_STATE(131)] = 3644,
  [SMALL_STATE(132)] = 3654,
  [SMALL_STATE(133)] = 3664,
  [SMALL_STATE(134)] = 3669,
  [SMALL_STATE(135)] = 3674,
  [SMALL_STATE(136)] = 3679,
  [SMALL_STATE(137)] = 3686,
  [SMALL_STATE(138)] = 3693,
  [SMALL_STATE(139)] = 3697,
  [SMALL_STATE(140)] = 3701,
  [SMALL_STATE(141)] = 3705,
  [SMALL_STATE(142)] = 3709,
  [SMALL_STATE(143)] = 3713,
  [SMALL_STATE(144)] = 3717,
  [SMALL_STATE(145)] = 3721,
  [SMALL_STATE(146)] = 3725,
  [SMALL_STATE(147)] = 3729,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(141),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(139),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(13),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(141),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(8),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(142),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(140),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(63),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(93),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(74),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(101),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(106),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(113),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(97),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(144),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr, 1),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expr, 1),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 2),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_statement, 3),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_statement, 3),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_inline_statement_repeat1, 2),
  [184] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inline_statement_repeat1, 2), SHIFT_REPEAT(37),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_inline_statement_repeat1, 2),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 4),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 4),
  [193] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inline_statement_repeat1, 2), SHIFT_REPEAT(39),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_expr, 4),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_expr, 4),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_expr, 4),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_index_expr, 4),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 3),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 3),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_expr, 4),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_map_expr, 4),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expr, 3, .production_id = 3),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expr, 3, .production_id = 3),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [224] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_statement, 2),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_statement, 2),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_lit, 3),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_lit, 3),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_expr, 3),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_expr, 3),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nil_lit, 1),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_nil_lit, 1),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paren_expr, 3),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paren_expr, 3),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_expr, 3),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_map_expr, 3),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_lit, 1),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_lit, 1),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_expr, 2),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_map_expr, 2),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_lit, 2),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_lit, 2),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_expr, 2),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_expr, 2),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expr, 2, .production_id = 1),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_expr, 2, .production_id = 1),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [282] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_elem, 3),
  [298] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [306] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [312] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [316] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [318] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign_stmt, 3),
  [324] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_stmt, 1),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_stmt_repeat1, 2),
  [334] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 2), SHIFT_REPEAT(26),
  [337] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 2),
  [339] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_lit_repeat2, 2),
  [341] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_lit_repeat2, 2), SHIFT_REPEAT(105),
  [344] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 4, .production_id = 2),
  [350] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [352] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [354] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [360] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [366] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [370] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_lit_repeat1, 2),
  [372] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_lit_repeat1, 2), SHIFT_REPEAT(114),
  [375] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 3, .production_id = 2),
  [377] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [379] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_expr_repeat1, 2), SHIFT_REPEAT(103),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_expr_repeat1, 2),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [386] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(23),
  [389] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_stmts, 2),
  [391] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_stmts, 2),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_stmts, 3),
  [405] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_stmts, 3),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_stmt_repeat1, 3),
  [413] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 3),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_map_expr_repeat1, 2),
  [423] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_map_expr_repeat1, 2), SHIFT_REPEAT(10),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [428] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_elem, 1),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 6, .production_id = 2),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [434] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_break_stmt, 1),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [438] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_continue_stmt, 1),
  [440] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 5, .production_id = 2),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_in_stmt, 5),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_platypus(void) {
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
