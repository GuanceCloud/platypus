#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 141
#define LARGE_STATE_COUNT 3
#define SYMBOL_COUNT 72
#define ALIAS_COUNT 0
#define TOKEN_COUNT 42
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 7
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 9

enum {
  sym_comment = 1,
  anon_sym_if = 2,
  anon_sym_elif = 3,
  anon_sym_else = 4,
  anon_sym_for = 5,
  anon_sym_in = 6,
  anon_sym_LBRACE = 7,
  anon_sym_RBRACE = 8,
  anon_sym_continue = 9,
  anon_sym_break = 10,
  anon_sym_EQ = 11,
  sym_identifier = 12,
  anon_sym_LPAREN = 13,
  anon_sym_RPAREN = 14,
  anon_sym_COMMA = 15,
  anon_sym_PLUS = 16,
  anon_sym_DASH = 17,
  anon_sym_STAR = 18,
  anon_sym_SLASH = 19,
  anon_sym_PERCENT = 20,
  anon_sym_PIPE_PIPE = 21,
  anon_sym_AMP_AMP = 22,
  anon_sym_EQ_EQ = 23,
  anon_sym_BANG_EQ = 24,
  anon_sym_GT = 25,
  anon_sym_GT_EQ = 26,
  anon_sym_LT_EQ = 27,
  anon_sym_LT = 28,
  anon_sym_LBRACK = 29,
  anon_sym_RBRACK = 30,
  anon_sym_COLON = 31,
  anon_sym_nil = 32,
  anon_sym_null = 33,
  sym_number_lit = 34,
  anon_sym_DQUOTE = 35,
  aux_sym_string_lit_token1 = 36,
  anon_sym_SQUOTE = 37,
  aux_sym_string_lit_token2 = 38,
  anon_sym_true = 39,
  anon_sym_false = 40,
  sym_escape_sequence = 41,
  sym_source_file = 42,
  sym__stmt = 43,
  sym_if_stmt = 44,
  sym_for_in_stmt = 45,
  sym_block_stmts = 46,
  sym_continue_stmt = 47,
  sym_break_stmt = 48,
  sym_assign_stmt = 49,
  sym_expr_stmt = 50,
  sym__expr = 51,
  sym_paren_expr = 52,
  sym_call_expr = 53,
  sym_argument_list = 54,
  sym_binary_expr = 55,
  sym_index_expr = 56,
  sym_list_expr = 57,
  sym_list_elem = 58,
  sym_map_expr = 59,
  sym_map_elem = 60,
  sym__literal = 61,
  sym_nil_lit = 62,
  sym_string_lit = 63,
  sym_bool_lit = 64,
  aux_sym_source_file_repeat1 = 65,
  aux_sym_if_stmt_repeat1 = 66,
  aux_sym_argument_list_repeat1 = 67,
  aux_sym_list_expr_repeat1 = 68,
  aux_sym_map_expr_repeat1 = 69,
  aux_sym_string_lit_repeat1 = 70,
  aux_sym_string_lit_repeat2 = 71,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [aux_sym_if_stmt_repeat1] = "if_stmt_repeat1",
  [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
  [aux_sym_list_expr_repeat1] = "list_expr_repeat1",
  [aux_sym_map_expr_repeat1] = "map_expr_repeat1",
  [aux_sym_string_lit_repeat1] = "string_lit_repeat1",
  [aux_sym_string_lit_repeat2] = "string_lit_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
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
  field_alternative = 1,
  field_condition = 2,
  field_consequence = 3,
  field_left = 4,
  field_name = 5,
  field_operator = 6,
  field_right = 7,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alternative] = "alternative",
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
  [4] = {.index = 6, .length = 3},
  [5] = {.index = 9, .length = 1},
  [6] = {.index = 10, .length = 3},
  [7] = {.index = 13, .length = 2},
  [8] = {.index = 15, .length = 4},
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
  [6] =
    {field_alternative, 3, .inherited = true},
    {field_condition, 1},
    {field_consequence, 2},
  [9] =
    {field_alternative, 1},
  [10] =
    {field_alternative, 4},
    {field_condition, 1},
    {field_consequence, 2},
  [13] =
    {field_alternative, 0, .inherited = true},
    {field_alternative, 1, .inherited = true},
  [15] =
    {field_alternative, 3, .inherited = true},
    {field_alternative, 5},
    {field_condition, 1},
    {field_consequence, 2},
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
  [5] = 4,
  [6] = 3,
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
  [35] = 34,
  [36] = 36,
  [37] = 37,
  [38] = 36,
  [39] = 39,
  [40] = 40,
  [41] = 13,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 42,
  [46] = 43,
  [47] = 47,
  [48] = 47,
  [49] = 40,
  [50] = 39,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 52,
  [55] = 55,
  [56] = 56,
  [57] = 51,
  [58] = 56,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 31,
  [67] = 19,
  [68] = 32,
  [69] = 10,
  [70] = 29,
  [71] = 26,
  [72] = 20,
  [73] = 14,
  [74] = 30,
  [75] = 33,
  [76] = 15,
  [77] = 28,
  [78] = 25,
  [79] = 12,
  [80] = 17,
  [81] = 18,
  [82] = 11,
  [83] = 24,
  [84] = 8,
  [85] = 21,
  [86] = 22,
  [87] = 23,
  [88] = 88,
  [89] = 89,
  [90] = 65,
  [91] = 63,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 95,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 103,
  [105] = 102,
  [106] = 101,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 112,
  [114] = 111,
  [115] = 115,
  [116] = 115,
  [117] = 110,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 120,
  [124] = 122,
  [125] = 125,
  [126] = 121,
  [127] = 127,
  [128] = 127,
  [129] = 119,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(26);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(108);
      if (lookahead == '#') ADVANCE(27);
      if (lookahead == '%') ADVANCE(79);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(111);
      if (lookahead == '(') ADVANCE(70);
      if (lookahead == ')') ADVANCE(71);
      if (lookahead == '*') ADVANCE(77);
      if (lookahead == '+') ADVANCE(74);
      if (lookahead == ',') ADVANCE(72);
      if (lookahead == '-') ADVANCE(76);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '/') ADVANCE(78);
      if (lookahead == '0') ADVANCE(97);
      if (lookahead == ':') ADVANCE(90);
      if (lookahead == '<') ADVANCE(87);
      if (lookahead == '=') ADVANCE(38);
      if (lookahead == '>') ADVANCE(84);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == '\\') ADVANCE(16);
      if (lookahead == ']') ADVANCE(89);
      if (lookahead == 'b') ADVANCE(62);
      if (lookahead == 'c') ADVANCE(61);
      if (lookahead == 'e') ADVANCE(54);
      if (lookahead == 'f') ADVANCE(40);
      if (lookahead == 'i') ADVANCE(47);
      if (lookahead == 'n') ADVANCE(52);
      if (lookahead == 't') ADVANCE(63);
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(23)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(5)
      if (lookahead == '"') ADVANCE(108);
      if (lookahead == '\\') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(109);
      if (lookahead != 0) ADVANCE(110);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == '\'') ADVANCE(111);
      if (lookahead == '\\') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (lookahead != 0) ADVANCE(113);
      END_STATE();
    case 3:
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '%') ADVANCE(79);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '(') ADVANCE(70);
      if (lookahead == ')') ADVANCE(71);
      if (lookahead == '*') ADVANCE(77);
      if (lookahead == '+') ADVANCE(73);
      if (lookahead == ',') ADVANCE(72);
      if (lookahead == '-') ADVANCE(75);
      if (lookahead == '/') ADVANCE(78);
      if (lookahead == ':') ADVANCE(90);
      if (lookahead == '<') ADVANCE(87);
      if (lookahead == '=') ADVANCE(12);
      if (lookahead == '>') ADVANCE(84);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == ']') ADVANCE(89);
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(108);
      if (lookahead == '\'') ADVANCE(111);
      if (lookahead == '(') ADVANCE(70);
      if (lookahead == ')') ADVANCE(71);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '0') ADVANCE(97);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == ']') ADVANCE(89);
      if (lookahead == 'f') ADVANCE(41);
      if (lookahead == 'n') ADVANCE(52);
      if (lookahead == 't') ADVANCE(63);
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(108);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '&') ADVANCE(81);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(111);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '0') ADVANCE(97);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '0') ADVANCE(95);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(104);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '0') ADVANCE(98);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      END_STATE();
    case 11:
      if (lookahead == '=') ADVANCE(83);
      END_STATE();
    case 12:
      if (lookahead == '=') ADVANCE(82);
      END_STATE();
    case 13:
      if (lookahead == 'n') ADVANCE(32);
      END_STATE();
    case 14:
      if (lookahead == '|') ADVANCE(80);
      END_STATE();
    case 15:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 16:
      if (lookahead == '"' ||
          lookahead == '/' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'f' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't' ||
          lookahead == 'u') ADVANCE(116);
      END_STATE();
    case 17:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(99);
      END_STATE();
    case 18:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(104);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(101);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(104);
      END_STATE();
    case 22:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(94);
      END_STATE();
    case 23:
      if (eof) ADVANCE(26);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(108);
      if (lookahead == '#') ADVANCE(27);
      if (lookahead == '%') ADVANCE(79);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(111);
      if (lookahead == '(') ADVANCE(70);
      if (lookahead == ')') ADVANCE(71);
      if (lookahead == '*') ADVANCE(77);
      if (lookahead == '+') ADVANCE(74);
      if (lookahead == ',') ADVANCE(72);
      if (lookahead == '-') ADVANCE(76);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '/') ADVANCE(78);
      if (lookahead == '0') ADVANCE(97);
      if (lookahead == ':') ADVANCE(90);
      if (lookahead == '<') ADVANCE(87);
      if (lookahead == '=') ADVANCE(38);
      if (lookahead == '>') ADVANCE(84);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == ']') ADVANCE(89);
      if (lookahead == 'b') ADVANCE(62);
      if (lookahead == 'c') ADVANCE(61);
      if (lookahead == 'e') ADVANCE(54);
      if (lookahead == 'f') ADVANCE(40);
      if (lookahead == 'i') ADVANCE(47);
      if (lookahead == 'n') ADVANCE(52);
      if (lookahead == 't') ADVANCE(63);
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(23)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 24:
      if (eof) ADVANCE(26);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(108);
      if (lookahead == '#') ADVANCE(27);
      if (lookahead == '%') ADVANCE(79);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(111);
      if (lookahead == '(') ADVANCE(70);
      if (lookahead == '*') ADVANCE(77);
      if (lookahead == '+') ADVANCE(74);
      if (lookahead == ',') ADVANCE(72);
      if (lookahead == '-') ADVANCE(76);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '/') ADVANCE(78);
      if (lookahead == '0') ADVANCE(97);
      if (lookahead == '<') ADVANCE(87);
      if (lookahead == '=') ADVANCE(38);
      if (lookahead == '>') ADVANCE(84);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == ']') ADVANCE(89);
      if (lookahead == 'b') ADVANCE(62);
      if (lookahead == 'c') ADVANCE(61);
      if (lookahead == 'f') ADVANCE(40);
      if (lookahead == 'i') ADVANCE(48);
      if (lookahead == 'n') ADVANCE(52);
      if (lookahead == 't') ADVANCE(63);
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(24)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 25:
      if (eof) ADVANCE(26);
      if (lookahead == '"') ADVANCE(108);
      if (lookahead == '#') ADVANCE(27);
      if (lookahead == '\'') ADVANCE(111);
      if (lookahead == '(') ADVANCE(70);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '0') ADVANCE(97);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == 'b') ADVANCE(62);
      if (lookahead == 'c') ADVANCE(61);
      if (lookahead == 'e') ADVANCE(54);
      if (lookahead == 'f') ADVANCE(40);
      if (lookahead == 'i') ADVANCE(48);
      if (lookahead == 'n') ADVANCE(52);
      if (lookahead == 't') ADVANCE(63);
      if (lookahead == '{') ADVANCE(34);
      if (lookahead == '}') ADVANCE(35);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(25)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_elif);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_else);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_for);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_in);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_continue);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_break);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(82);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(55);
      if (lookahead == 'o') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(115);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(28);
      if (lookahead == 'n') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(49);
      if (lookahead == 's') ADVANCE(43);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(56);
      if (lookahead == 'u') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(42);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(44);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '0') ADVANCE(97);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '.') ADVANCE(18);
      if (lookahead == '0') ADVANCE(97);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(99);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(86);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_nil);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_null);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(18);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(22);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(94);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'E') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(19);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(104);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'b') ADVANCE(103);
      if (lookahead == 'x') ADVANCE(21);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(102);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(106);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(19);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(104);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(102);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(106);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(17);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'b') ADVANCE(10);
      if (lookahead == 'x') ADVANCE(9);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(99);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(17);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'b') ADVANCE(17);
      if (lookahead == 'x') ADVANCE(21);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(99);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(17);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(20);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(101);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(22);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(100);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(101);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(20);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(101);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(100);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(21);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(104);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(22);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(102);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(104);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(21);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(104);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(102);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(106);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(104);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(21);
      if (lookahead == '.') ADVANCE(105);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(104);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(102);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(104);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(101);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(100);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(101);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(94);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(22);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'E') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(94);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(107);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_string_lit_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(109);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(110);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym_string_lit_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(110);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(aux_sym_string_lit_token2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(113);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(aux_sym_string_lit_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(113);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 24},
  [2] = {.lex_state = 24},
  [3] = {.lex_state = 24},
  [4] = {.lex_state = 24},
  [5] = {.lex_state = 24},
  [6] = {.lex_state = 24},
  [7] = {.lex_state = 24},
  [8] = {.lex_state = 24},
  [9] = {.lex_state = 24},
  [10] = {.lex_state = 24},
  [11] = {.lex_state = 24},
  [12] = {.lex_state = 24},
  [13] = {.lex_state = 24},
  [14] = {.lex_state = 24},
  [15] = {.lex_state = 24},
  [16] = {.lex_state = 24},
  [17] = {.lex_state = 24},
  [18] = {.lex_state = 24},
  [19] = {.lex_state = 24},
  [20] = {.lex_state = 24},
  [21] = {.lex_state = 24},
  [22] = {.lex_state = 24},
  [23] = {.lex_state = 24},
  [24] = {.lex_state = 24},
  [25] = {.lex_state = 24},
  [26] = {.lex_state = 24},
  [27] = {.lex_state = 24},
  [28] = {.lex_state = 24},
  [29] = {.lex_state = 24},
  [30] = {.lex_state = 24},
  [31] = {.lex_state = 24},
  [32] = {.lex_state = 24},
  [33] = {.lex_state = 24},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 4},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 3},
  [42] = {.lex_state = 4},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 4},
  [47] = {.lex_state = 4},
  [48] = {.lex_state = 4},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 4},
  [55] = {.lex_state = 4},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 4},
  [58] = {.lex_state = 4},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 25},
  [61] = {.lex_state = 25},
  [62] = {.lex_state = 25},
  [63] = {.lex_state = 25},
  [64] = {.lex_state = 25},
  [65] = {.lex_state = 25},
  [66] = {.lex_state = 3},
  [67] = {.lex_state = 3},
  [68] = {.lex_state = 3},
  [69] = {.lex_state = 3},
  [70] = {.lex_state = 3},
  [71] = {.lex_state = 3},
  [72] = {.lex_state = 3},
  [73] = {.lex_state = 3},
  [74] = {.lex_state = 3},
  [75] = {.lex_state = 3},
  [76] = {.lex_state = 3},
  [77] = {.lex_state = 3},
  [78] = {.lex_state = 3},
  [79] = {.lex_state = 3},
  [80] = {.lex_state = 3},
  [81] = {.lex_state = 3},
  [82] = {.lex_state = 3},
  [83] = {.lex_state = 3},
  [84] = {.lex_state = 3},
  [85] = {.lex_state = 3},
  [86] = {.lex_state = 3},
  [87] = {.lex_state = 3},
  [88] = {.lex_state = 24},
  [89] = {.lex_state = 24},
  [90] = {.lex_state = 24},
  [91] = {.lex_state = 24},
  [92] = {.lex_state = 24},
  [93] = {.lex_state = 24},
  [94] = {.lex_state = 24},
  [95] = {.lex_state = 3},
  [96] = {.lex_state = 3},
  [97] = {.lex_state = 3},
  [98] = {.lex_state = 3},
  [99] = {.lex_state = 3},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 4},
  [102] = {.lex_state = 3},
  [103] = {.lex_state = 3},
  [104] = {.lex_state = 3},
  [105] = {.lex_state = 3},
  [106] = {.lex_state = 4},
  [107] = {.lex_state = 4},
  [108] = {.lex_state = 1},
  [109] = {.lex_state = 2},
  [110] = {.lex_state = 1},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 1},
  [113] = {.lex_state = 1},
  [114] = {.lex_state = 2},
  [115] = {.lex_state = 2},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 1},
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
  [138] = {.lex_state = 3},
  [139] = {.lex_state = 15},
  [140] = {.lex_state = 0},
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
    [sym_identifier] = ACTIONS(1),
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
    [sym_number_lit] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(140),
    [sym__stmt] = STATE(7),
    [sym_if_stmt] = STATE(7),
    [sym_for_in_stmt] = STATE(7),
    [sym_continue_stmt] = STATE(7),
    [sym_break_stmt] = STATE(7),
    [sym_assign_stmt] = STATE(7),
    [sym_expr_stmt] = STATE(7),
    [sym__expr] = STATE(16),
    [sym_paren_expr] = STATE(16),
    [sym_call_expr] = STATE(16),
    [sym_binary_expr] = STATE(16),
    [sym_index_expr] = STATE(16),
    [sym_list_expr] = STATE(16),
    [sym_map_expr] = STATE(16),
    [sym__literal] = STATE(16),
    [sym_nil_lit] = STATE(16),
    [sym_string_lit] = STATE(16),
    [sym_bool_lit] = STATE(16),
    [aux_sym_source_file_repeat1] = STATE(7),
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
  [2] = {
    [sym__stmt] = STATE(2),
    [sym_if_stmt] = STATE(2),
    [sym_for_in_stmt] = STATE(2),
    [sym_continue_stmt] = STATE(2),
    [sym_break_stmt] = STATE(2),
    [sym_assign_stmt] = STATE(2),
    [sym_expr_stmt] = STATE(2),
    [sym__expr] = STATE(16),
    [sym_paren_expr] = STATE(16),
    [sym_call_expr] = STATE(16),
    [sym_binary_expr] = STATE(16),
    [sym_index_expr] = STATE(16),
    [sym_list_expr] = STATE(16),
    [sym_map_expr] = STATE(16),
    [sym__literal] = STATE(16),
    [sym_nil_lit] = STATE(16),
    [sym_string_lit] = STATE(16),
    [sym_bool_lit] = STATE(16),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_comment] = ACTIONS(35),
    [anon_sym_if] = ACTIONS(38),
    [anon_sym_for] = ACTIONS(41),
    [anon_sym_LBRACE] = ACTIONS(44),
    [anon_sym_RBRACE] = ACTIONS(33),
    [anon_sym_continue] = ACTIONS(47),
    [anon_sym_break] = ACTIONS(50),
    [sym_identifier] = ACTIONS(53),
    [anon_sym_LPAREN] = ACTIONS(56),
    [anon_sym_LBRACK] = ACTIONS(59),
    [anon_sym_nil] = ACTIONS(62),
    [anon_sym_null] = ACTIONS(62),
    [sym_number_lit] = ACTIONS(65),
    [anon_sym_DQUOTE] = ACTIONS(68),
    [anon_sym_SQUOTE] = ACTIONS(71),
    [anon_sym_true] = ACTIONS(74),
    [anon_sym_false] = ACTIONS(74),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 17,
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
    ACTIONS(77), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(4), 8,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
      aux_sym_source_file_repeat1,
    STATE(16), 11,
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
  [71] = 17,
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
    ACTIONS(81), 1,
      sym_comment,
    ACTIONS(83), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 8,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
      aux_sym_source_file_repeat1,
    STATE(16), 11,
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
  [142] = 17,
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
    ACTIONS(81), 1,
      sym_comment,
    ACTIONS(85), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 8,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
      aux_sym_source_file_repeat1,
    STATE(16), 11,
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
  [213] = 17,
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
    ACTIONS(87), 1,
      sym_comment,
    ACTIONS(89), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(5), 8,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
      aux_sym_source_file_repeat1,
    STATE(16), 11,
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
  [284] = 17,
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
    ACTIONS(81), 1,
      sym_comment,
    ACTIONS(91), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 8,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
      aux_sym_source_file_repeat1,
    STATE(16), 11,
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
  [355] = 2,
    ACTIONS(95), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(93), 20,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [393] = 6,
    ACTIONS(101), 1,
      anon_sym_EQ,
    ACTIONS(103), 1,
      anon_sym_LPAREN,
    ACTIONS(105), 1,
      anon_sym_LBRACK,
    STATE(26), 1,
      sym_argument_list,
    ACTIONS(99), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(97), 16,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [439] = 2,
    ACTIONS(109), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(107), 20,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [477] = 2,
    ACTIONS(113), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(111), 20,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [515] = 2,
    ACTIONS(117), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(115), 20,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [553] = 5,
    ACTIONS(103), 1,
      anon_sym_LPAREN,
    ACTIONS(105), 1,
      anon_sym_LBRACK,
    STATE(26), 1,
      sym_argument_list,
    ACTIONS(99), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(97), 16,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [596] = 2,
    ACTIONS(121), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(119), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [632] = 2,
    ACTIONS(125), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(123), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [668] = 9,
    ACTIONS(135), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(137), 1,
      anon_sym_AMP_AMP,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(139), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(141), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(143), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(133), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(127), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(129), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [718] = 4,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(133), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(147), 11,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(145), 15,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [758] = 8,
    ACTIONS(135), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(137), 1,
      anon_sym_AMP_AMP,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(141), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(143), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(133), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(147), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(145), 11,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [806] = 6,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(141), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(143), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(133), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(147), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(145), 13,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [850] = 2,
    ACTIONS(151), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(149), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [886] = 7,
    ACTIONS(137), 1,
      anon_sym_AMP_AMP,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(141), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(143), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(133), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(147), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(145), 12,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [932] = 2,
    ACTIONS(147), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(145), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [968] = 3,
    ACTIONS(133), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(147), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(145), 15,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1006] = 2,
    ACTIONS(155), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(153), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1042] = 2,
    ACTIONS(159), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(157), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1078] = 2,
    ACTIONS(163), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(161), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1114] = 9,
    ACTIONS(135), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(137), 1,
      anon_sym_AMP_AMP,
    ACTIONS(131), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(139), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(141), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(143), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(133), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(165), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(167), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [1164] = 2,
    ACTIONS(171), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(169), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1200] = 2,
    ACTIONS(175), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(173), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1236] = 2,
    ACTIONS(179), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(177), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1272] = 2,
    ACTIONS(183), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(181), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1308] = 2,
    ACTIONS(187), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(185), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1344] = 2,
    ACTIONS(191), 13,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(189), 18,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1380] = 12,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(195), 1,
      anon_sym_RBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(205), 1,
      sym_number_lit,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    STATE(121), 1,
      sym_map_elem,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
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
  [1429] = 12,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(205), 1,
      sym_number_lit,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(213), 1,
      anon_sym_RBRACE,
    STATE(126), 1,
      sym_map_elem,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
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
  [1478] = 11,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(215), 1,
      anon_sym_RPAREN,
    ACTIONS(217), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(96), 11,
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
  [1524] = 11,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(205), 1,
      sym_number_lit,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    STATE(136), 1,
      sym_map_elem,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
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
  [1570] = 11,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(219), 1,
      anon_sym_RPAREN,
    ACTIONS(221), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(95), 11,
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
  [1616] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(223), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(86), 11,
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
  [1659] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(225), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(85), 11,
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
  [1702] = 5,
    ACTIONS(227), 1,
      anon_sym_LPAREN,
    ACTIONS(229), 1,
      anon_sym_LBRACK,
    STATE(71), 1,
      sym_argument_list,
    ACTIONS(99), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(97), 17,
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
  [1735] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(231), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
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
  [1778] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(233), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(81), 11,
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
  [1821] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(235), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
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
  [1864] = 10,
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
    ACTIONS(237), 1,
      sym_identifier,
    ACTIONS(239), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(17), 11,
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
  [1907] = 10,
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
    ACTIONS(237), 1,
      sym_identifier,
    ACTIONS(241), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(18), 11,
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
  [1950] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(243), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
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
  [1993] = 10,
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
    ACTIONS(237), 1,
      sym_identifier,
    ACTIONS(245), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(19), 11,
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
  [2036] = 10,
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
    ACTIONS(237), 1,
      sym_identifier,
    ACTIONS(247), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(21), 11,
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
  [2079] = 10,
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
    ACTIONS(237), 1,
      sym_identifier,
    ACTIONS(249), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(22), 11,
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
  [2122] = 10,
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
    ACTIONS(237), 1,
      sym_identifier,
    ACTIONS(251), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(23), 11,
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
  [2165] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(253), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(104), 11,
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
  [2208] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(255), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(97), 11,
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
  [2251] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(257), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(103), 11,
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
  [2294] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(259), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
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
  [2337] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(261), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(102), 11,
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
  [2380] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(263), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(87), 11,
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
  [2423] = 10,
    ACTIONS(193), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    ACTIONS(265), 1,
      sym_number_lit,
    ACTIONS(203), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(211), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(105), 11,
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
  [2466] = 10,
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
    ACTIONS(237), 1,
      sym_identifier,
    ACTIONS(267), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(27), 11,
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
  [2509] = 4,
    ACTIONS(273), 1,
      anon_sym_elif,
    STATE(60), 1,
      aux_sym_if_stmt_repeat1,
    ACTIONS(269), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(271), 10,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [2539] = 5,
    ACTIONS(280), 1,
      anon_sym_elif,
    ACTIONS(282), 1,
      anon_sym_else,
    STATE(60), 1,
      aux_sym_if_stmt_repeat1,
    ACTIONS(276), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(278), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [2571] = 5,
    ACTIONS(280), 1,
      anon_sym_elif,
    ACTIONS(288), 1,
      anon_sym_else,
    STATE(61), 1,
      aux_sym_if_stmt_repeat1,
    ACTIONS(284), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(286), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [2603] = 2,
    ACTIONS(290), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(292), 11,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [2628] = 2,
    ACTIONS(294), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(296), 11,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [2653] = 2,
    ACTIONS(298), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(300), 11,
      anon_sym_if,
      anon_sym_elif,
      anon_sym_else,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [2678] = 2,
    ACTIONS(183), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(181), 17,
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
  [2702] = 5,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(145), 10,
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
  [2732] = 2,
    ACTIONS(187), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(185), 17,
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
  [2756] = 2,
    ACTIONS(109), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(107), 17,
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
  [2780] = 2,
    ACTIONS(175), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(173), 17,
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
  [2804] = 2,
    ACTIONS(163), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(161), 17,
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
  [2828] = 2,
    ACTIONS(151), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(149), 17,
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
  [2852] = 2,
    ACTIONS(121), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(119), 17,
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
  [2876] = 2,
    ACTIONS(179), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(177), 17,
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
  [2900] = 2,
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
  [2924] = 2,
    ACTIONS(125), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(123), 17,
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
  [2948] = 2,
    ACTIONS(171), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(169), 17,
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
  [2972] = 2,
    ACTIONS(159), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(157), 17,
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
  [2996] = 2,
    ACTIONS(117), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(115), 17,
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
  [3020] = 4,
    ACTIONS(147), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(145), 12,
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
  [3048] = 7,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(145), 8,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [3082] = 2,
    ACTIONS(113), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(111), 17,
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
  [3106] = 2,
    ACTIONS(155), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(153), 17,
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
  [3130] = 2,
    ACTIONS(95), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(93), 17,
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
  [3154] = 6,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(145), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE_PIPE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [3186] = 2,
    ACTIONS(147), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(145), 17,
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
  [3210] = 3,
    ACTIONS(147), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(145), 14,
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
  [3236] = 2,
    ACTIONS(314), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(316), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [3259] = 2,
    ACTIONS(318), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(320), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [3282] = 2,
    ACTIONS(298), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(300), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [3305] = 2,
    ACTIONS(290), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(292), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [3328] = 2,
    ACTIONS(322), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(324), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [3351] = 2,
    ACTIONS(326), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(328), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [3374] = 2,
    ACTIONS(330), 9,
      ts_builtin_sym_end,
      sym_comment,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_LBRACK,
      sym_number_lit,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
    ACTIONS(332), 9,
      anon_sym_if,
      anon_sym_for,
      anon_sym_continue,
      anon_sym_break,
      sym_identifier,
      anon_sym_nil,
      anon_sym_null,
      anon_sym_true,
      anon_sym_false,
  [3397] = 10,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(334), 1,
      anon_sym_RPAREN,
    ACTIONS(336), 1,
      anon_sym_COMMA,
    STATE(123), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3434] = 10,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(336), 1,
      anon_sym_COMMA,
    ACTIONS(340), 1,
      anon_sym_RPAREN,
    STATE(120), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3471] = 8,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(342), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3503] = 8,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(344), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3535] = 9,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(346), 1,
      anon_sym_LBRACE,
    STATE(62), 1,
      sym_block_stmts,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3569] = 8,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(348), 1,
      anon_sym_COLON,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3600] = 9,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(350), 1,
      sym_identifier,
    ACTIONS(352), 1,
      anon_sym_RBRACK,
    ACTIONS(354), 1,
      sym_number_lit,
    STATE(119), 1,
      sym_list_elem,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(133), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [3633] = 8,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(356), 1,
      anon_sym_RBRACK,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3664] = 8,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(358), 1,
      anon_sym_RPAREN,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3695] = 8,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(360), 1,
      anon_sym_RPAREN,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3726] = 8,
    ACTIONS(310), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(312), 1,
      anon_sym_AMP_AMP,
    ACTIONS(362), 1,
      anon_sym_RBRACK,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(306), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(308), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3757] = 9,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(350), 1,
      sym_identifier,
    ACTIONS(354), 1,
      sym_number_lit,
    ACTIONS(364), 1,
      anon_sym_RBRACK,
    STATE(129), 1,
      sym_list_elem,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(133), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [3790] = 8,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(350), 1,
      sym_identifier,
    ACTIONS(354), 1,
      sym_number_lit,
    STATE(131), 1,
      sym_list_elem,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(133), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [3820] = 3,
    ACTIONS(366), 1,
      anon_sym_DQUOTE,
    STATE(108), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(368), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3831] = 3,
    ACTIONS(371), 1,
      anon_sym_SQUOTE,
    STATE(109), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(373), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3842] = 3,
    ACTIONS(376), 1,
      anon_sym_DQUOTE,
    STATE(112), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(378), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3853] = 3,
    ACTIONS(380), 1,
      anon_sym_SQUOTE,
    STATE(109), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(382), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3864] = 3,
    ACTIONS(384), 1,
      anon_sym_DQUOTE,
    STATE(108), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(386), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3875] = 3,
    ACTIONS(380), 1,
      anon_sym_DQUOTE,
    STATE(108), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(386), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3886] = 3,
    ACTIONS(384), 1,
      anon_sym_SQUOTE,
    STATE(109), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(382), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3897] = 3,
    ACTIONS(376), 1,
      anon_sym_SQUOTE,
    STATE(114), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(388), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3908] = 3,
    ACTIONS(390), 1,
      anon_sym_SQUOTE,
    STATE(111), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(392), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3919] = 3,
    ACTIONS(390), 1,
      anon_sym_DQUOTE,
    STATE(113), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(394), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3930] = 3,
    ACTIONS(396), 1,
      anon_sym_RBRACE,
    ACTIONS(398), 1,
      anon_sym_COMMA,
    STATE(118), 1,
      aux_sym_map_expr_repeat1,
  [3940] = 3,
    ACTIONS(401), 1,
      anon_sym_COMMA,
    ACTIONS(403), 1,
      anon_sym_RBRACK,
    STATE(124), 1,
      aux_sym_list_expr_repeat1,
  [3950] = 3,
    ACTIONS(336), 1,
      anon_sym_COMMA,
    ACTIONS(405), 1,
      anon_sym_RPAREN,
    STATE(130), 1,
      aux_sym_argument_list_repeat1,
  [3960] = 3,
    ACTIONS(407), 1,
      anon_sym_RBRACE,
    ACTIONS(409), 1,
      anon_sym_COMMA,
    STATE(127), 1,
      aux_sym_map_expr_repeat1,
  [3970] = 3,
    ACTIONS(401), 1,
      anon_sym_COMMA,
    ACTIONS(411), 1,
      anon_sym_RBRACK,
    STATE(125), 1,
      aux_sym_list_expr_repeat1,
  [3980] = 3,
    ACTIONS(336), 1,
      anon_sym_COMMA,
    ACTIONS(413), 1,
      anon_sym_RPAREN,
    STATE(130), 1,
      aux_sym_argument_list_repeat1,
  [3990] = 3,
    ACTIONS(401), 1,
      anon_sym_COMMA,
    ACTIONS(415), 1,
      anon_sym_RBRACK,
    STATE(125), 1,
      aux_sym_list_expr_repeat1,
  [4000] = 3,
    ACTIONS(417), 1,
      anon_sym_COMMA,
    ACTIONS(420), 1,
      anon_sym_RBRACK,
    STATE(125), 1,
      aux_sym_list_expr_repeat1,
  [4010] = 3,
    ACTIONS(409), 1,
      anon_sym_COMMA,
    ACTIONS(422), 1,
      anon_sym_RBRACE,
    STATE(128), 1,
      aux_sym_map_expr_repeat1,
  [4020] = 3,
    ACTIONS(409), 1,
      anon_sym_COMMA,
    ACTIONS(424), 1,
      anon_sym_RBRACE,
    STATE(118), 1,
      aux_sym_map_expr_repeat1,
  [4030] = 3,
    ACTIONS(409), 1,
      anon_sym_COMMA,
    ACTIONS(426), 1,
      anon_sym_RBRACE,
    STATE(118), 1,
      aux_sym_map_expr_repeat1,
  [4040] = 3,
    ACTIONS(401), 1,
      anon_sym_COMMA,
    ACTIONS(428), 1,
      anon_sym_RBRACK,
    STATE(122), 1,
      aux_sym_list_expr_repeat1,
  [4050] = 3,
    ACTIONS(342), 1,
      anon_sym_RPAREN,
    ACTIONS(430), 1,
      anon_sym_COMMA,
    STATE(130), 1,
      aux_sym_argument_list_repeat1,
  [4060] = 1,
    ACTIONS(420), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4065] = 2,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(92), 1,
      sym_block_stmts,
  [4072] = 1,
    ACTIONS(435), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4077] = 2,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(89), 1,
      sym_block_stmts,
  [4084] = 2,
    ACTIONS(346), 1,
      anon_sym_LBRACE,
    STATE(64), 1,
      sym_block_stmts,
  [4091] = 1,
    ACTIONS(396), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [4096] = 2,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(88), 1,
      sym_block_stmts,
  [4103] = 1,
    ACTIONS(437), 1,
      anon_sym_in,
  [4107] = 1,
    ACTIONS(439), 1,
      sym_identifier,
  [4111] = 1,
    ACTIONS(441), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(3)] = 0,
  [SMALL_STATE(4)] = 71,
  [SMALL_STATE(5)] = 142,
  [SMALL_STATE(6)] = 213,
  [SMALL_STATE(7)] = 284,
  [SMALL_STATE(8)] = 355,
  [SMALL_STATE(9)] = 393,
  [SMALL_STATE(10)] = 439,
  [SMALL_STATE(11)] = 477,
  [SMALL_STATE(12)] = 515,
  [SMALL_STATE(13)] = 553,
  [SMALL_STATE(14)] = 596,
  [SMALL_STATE(15)] = 632,
  [SMALL_STATE(16)] = 668,
  [SMALL_STATE(17)] = 718,
  [SMALL_STATE(18)] = 758,
  [SMALL_STATE(19)] = 806,
  [SMALL_STATE(20)] = 850,
  [SMALL_STATE(21)] = 886,
  [SMALL_STATE(22)] = 932,
  [SMALL_STATE(23)] = 968,
  [SMALL_STATE(24)] = 1006,
  [SMALL_STATE(25)] = 1042,
  [SMALL_STATE(26)] = 1078,
  [SMALL_STATE(27)] = 1114,
  [SMALL_STATE(28)] = 1164,
  [SMALL_STATE(29)] = 1200,
  [SMALL_STATE(30)] = 1236,
  [SMALL_STATE(31)] = 1272,
  [SMALL_STATE(32)] = 1308,
  [SMALL_STATE(33)] = 1344,
  [SMALL_STATE(34)] = 1380,
  [SMALL_STATE(35)] = 1429,
  [SMALL_STATE(36)] = 1478,
  [SMALL_STATE(37)] = 1524,
  [SMALL_STATE(38)] = 1570,
  [SMALL_STATE(39)] = 1616,
  [SMALL_STATE(40)] = 1659,
  [SMALL_STATE(41)] = 1702,
  [SMALL_STATE(42)] = 1735,
  [SMALL_STATE(43)] = 1778,
  [SMALL_STATE(44)] = 1821,
  [SMALL_STATE(45)] = 1864,
  [SMALL_STATE(46)] = 1907,
  [SMALL_STATE(47)] = 1950,
  [SMALL_STATE(48)] = 1993,
  [SMALL_STATE(49)] = 2036,
  [SMALL_STATE(50)] = 2079,
  [SMALL_STATE(51)] = 2122,
  [SMALL_STATE(52)] = 2165,
  [SMALL_STATE(53)] = 2208,
  [SMALL_STATE(54)] = 2251,
  [SMALL_STATE(55)] = 2294,
  [SMALL_STATE(56)] = 2337,
  [SMALL_STATE(57)] = 2380,
  [SMALL_STATE(58)] = 2423,
  [SMALL_STATE(59)] = 2466,
  [SMALL_STATE(60)] = 2509,
  [SMALL_STATE(61)] = 2539,
  [SMALL_STATE(62)] = 2571,
  [SMALL_STATE(63)] = 2603,
  [SMALL_STATE(64)] = 2628,
  [SMALL_STATE(65)] = 2653,
  [SMALL_STATE(66)] = 2678,
  [SMALL_STATE(67)] = 2702,
  [SMALL_STATE(68)] = 2732,
  [SMALL_STATE(69)] = 2756,
  [SMALL_STATE(70)] = 2780,
  [SMALL_STATE(71)] = 2804,
  [SMALL_STATE(72)] = 2828,
  [SMALL_STATE(73)] = 2852,
  [SMALL_STATE(74)] = 2876,
  [SMALL_STATE(75)] = 2900,
  [SMALL_STATE(76)] = 2924,
  [SMALL_STATE(77)] = 2948,
  [SMALL_STATE(78)] = 2972,
  [SMALL_STATE(79)] = 2996,
  [SMALL_STATE(80)] = 3020,
  [SMALL_STATE(81)] = 3048,
  [SMALL_STATE(82)] = 3082,
  [SMALL_STATE(83)] = 3106,
  [SMALL_STATE(84)] = 3130,
  [SMALL_STATE(85)] = 3154,
  [SMALL_STATE(86)] = 3186,
  [SMALL_STATE(87)] = 3210,
  [SMALL_STATE(88)] = 3236,
  [SMALL_STATE(89)] = 3259,
  [SMALL_STATE(90)] = 3282,
  [SMALL_STATE(91)] = 3305,
  [SMALL_STATE(92)] = 3328,
  [SMALL_STATE(93)] = 3351,
  [SMALL_STATE(94)] = 3374,
  [SMALL_STATE(95)] = 3397,
  [SMALL_STATE(96)] = 3434,
  [SMALL_STATE(97)] = 3471,
  [SMALL_STATE(98)] = 3503,
  [SMALL_STATE(99)] = 3535,
  [SMALL_STATE(100)] = 3569,
  [SMALL_STATE(101)] = 3600,
  [SMALL_STATE(102)] = 3633,
  [SMALL_STATE(103)] = 3664,
  [SMALL_STATE(104)] = 3695,
  [SMALL_STATE(105)] = 3726,
  [SMALL_STATE(106)] = 3757,
  [SMALL_STATE(107)] = 3790,
  [SMALL_STATE(108)] = 3820,
  [SMALL_STATE(109)] = 3831,
  [SMALL_STATE(110)] = 3842,
  [SMALL_STATE(111)] = 3853,
  [SMALL_STATE(112)] = 3864,
  [SMALL_STATE(113)] = 3875,
  [SMALL_STATE(114)] = 3886,
  [SMALL_STATE(115)] = 3897,
  [SMALL_STATE(116)] = 3908,
  [SMALL_STATE(117)] = 3919,
  [SMALL_STATE(118)] = 3930,
  [SMALL_STATE(119)] = 3940,
  [SMALL_STATE(120)] = 3950,
  [SMALL_STATE(121)] = 3960,
  [SMALL_STATE(122)] = 3970,
  [SMALL_STATE(123)] = 3980,
  [SMALL_STATE(124)] = 3990,
  [SMALL_STATE(125)] = 4000,
  [SMALL_STATE(126)] = 4010,
  [SMALL_STATE(127)] = 4020,
  [SMALL_STATE(128)] = 4030,
  [SMALL_STATE(129)] = 4040,
  [SMALL_STATE(130)] = 4050,
  [SMALL_STATE(131)] = 4060,
  [SMALL_STATE(132)] = 4065,
  [SMALL_STATE(133)] = 4072,
  [SMALL_STATE(134)] = 4077,
  [SMALL_STATE(135)] = 4084,
  [SMALL_STATE(136)] = 4091,
  [SMALL_STATE(137)] = 4096,
  [SMALL_STATE(138)] = 4103,
  [SMALL_STATE(139)] = 4107,
  [SMALL_STATE(140)] = 4111,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(55),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(139),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(34),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(94),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(93),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(54),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(101),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(110),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(115),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(12),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_lit, 3),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_lit, 3),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr, 1),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expr, 1),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_lit, 2),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_lit, 2),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nil_lit, 1),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_nil_lit, 1),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_lit, 1),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_lit, 1),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 4),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 4),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_expr, 4),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_index_expr, 4),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_stmt, 1),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expr_stmt, 1),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expr, 3, .production_id = 3),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expr, 3, .production_id = 3),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_expr, 2),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_map_expr, 2),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_expr, 3),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_map_expr, 3),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_expr, 4),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_map_expr, 4),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expr, 2, .production_id = 1),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_expr, 2, .production_id = 1),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign_stmt, 3),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assign_stmt, 3),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 3),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 3),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_expr, 2),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_expr, 2),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_expr, 3),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_expr, 3),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 2),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paren_expr, 3),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paren_expr, 3),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_expr, 4),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_expr, 4),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_stmt_repeat1, 2, .production_id = 7),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 2, .production_id = 7),
  [273] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 2, .production_id = 7), SHIFT_REPEAT(135),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 4, .production_id = 4),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_stmt, 4, .production_id = 4),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [282] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 3, .production_id = 2),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_stmt, 3, .production_id = 2),
  [288] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [290] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_stmts, 3),
  [292] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_stmts, 3),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_stmt_repeat1, 2, .production_id = 5),
  [296] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 2, .production_id = 5),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_stmts, 2),
  [300] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_stmts, 2),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [306] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 5, .production_id = 6),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_stmt, 5, .production_id = 6),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 6, .production_id = 8),
  [320] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_stmt, 6, .production_id = 8),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_in_stmt, 4),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_in_stmt, 4),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_break_stmt, 1),
  [328] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_break_stmt, 1),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_continue_stmt, 1),
  [332] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_continue_stmt, 1),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_elem, 3),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [350] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [366] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_lit_repeat1, 2),
  [368] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_lit_repeat1, 2), SHIFT_REPEAT(108),
  [371] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_lit_repeat2, 2),
  [373] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_lit_repeat2, 2), SHIFT_REPEAT(109),
  [376] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [380] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [384] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [390] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_map_expr_repeat1, 2),
  [398] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_map_expr_repeat1, 2), SHIFT_REPEAT(37),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [417] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_expr_repeat1, 2), SHIFT_REPEAT(107),
  [420] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_expr_repeat1, 2),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [430] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(53),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_elem, 1),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [441] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_ppl(void) {
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
