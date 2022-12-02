#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 142
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
  [66] = 24,
  [67] = 30,
  [68] = 33,
  [69] = 10,
  [70] = 25,
  [71] = 29,
  [72] = 26,
  [73] = 20,
  [74] = 17,
  [75] = 18,
  [76] = 19,
  [77] = 21,
  [78] = 22,
  [79] = 23,
  [80] = 28,
  [81] = 8,
  [82] = 12,
  [83] = 15,
  [84] = 11,
  [85] = 32,
  [86] = 31,
  [87] = 14,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 65,
  [92] = 92,
  [93] = 63,
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
  [105] = 101,
  [106] = 100,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 112,
  [114] = 109,
  [115] = 110,
  [116] = 116,
  [117] = 111,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 121,
  [127] = 118,
  [128] = 125,
  [129] = 120,
  [130] = 122,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(52);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '#') ADVANCE(53);
      if (lookahead == '%') ADVANCE(109);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(143);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == '*') ADVANCE(107);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(102);
      if (lookahead == '-') ADVANCE(106);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '/') ADVANCE(108);
      if (lookahead == '0') ADVANCE(129);
      if (lookahead == ':') ADVANCE(120);
      if (lookahead == '<') ADVANCE(117);
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '>') ADVANCE(114);
      if (lookahead == '[') ADVANCE(118);
      if (lookahead == '\\') ADVANCE(42);
      if (lookahead == ']') ADVANCE(119);
      if (lookahead == 'b') ADVANCE(34);
      if (lookahead == 'c') ADVANCE(33);
      if (lookahead == 'e') ADVANCE(26);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(20);
      if (lookahead == 'n') ADVANCE(24);
      if (lookahead == 't') ADVANCE(35);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '}') ADVANCE(64);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(49)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == '\'') ADVANCE(143);
      if (lookahead == '\\') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(144);
      if (lookahead != 0) ADVANCE(145);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(5)
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '\\') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0) ADVANCE(142);
      END_STATE();
    case 3:
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '%') ADVANCE(109);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == '*') ADVANCE(107);
      if (lookahead == '+') ADVANCE(103);
      if (lookahead == ',') ADVANCE(102);
      if (lookahead == '-') ADVANCE(105);
      if (lookahead == '/') ADVANCE(108);
      if (lookahead == ':') ADVANCE(120);
      if (lookahead == '<') ADVANCE(117);
      if (lookahead == '=') ADVANCE(12);
      if (lookahead == '>') ADVANCE(114);
      if (lookahead == '[') ADVANCE(118);
      if (lookahead == ']') ADVANCE(119);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '}') ADVANCE(64);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '\'') ADVANCE(143);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(129);
      if (lookahead == '[') ADVANCE(118);
      if (lookahead == ']') ADVANCE(119);
      if (lookahead == 'f') ADVANCE(71);
      if (lookahead == 'n') ADVANCE(82);
      if (lookahead == 't') ADVANCE(93);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '}') ADVANCE(64);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '&') ADVANCE(111);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(143);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(129);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(127);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(136);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(130);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 11:
      if (lookahead == '=') ADVANCE(113);
      END_STATE();
    case 12:
      if (lookahead == '=') ADVANCE(112);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(25);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(27);
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(146);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(148);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 20:
      if (lookahead == 'f') ADVANCE(54);
      if (lookahead == 'n') ADVANCE(62);
      END_STATE();
    case 21:
      if (lookahead == 'f') ADVANCE(56);
      END_STATE();
    case 22:
      if (lookahead == 'i') ADVANCE(21);
      if (lookahead == 's') ADVANCE(16);
      END_STATE();
    case 23:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 24:
      if (lookahead == 'i') ADVANCE(28);
      if (lookahead == 'u') ADVANCE(30);
      END_STATE();
    case 25:
      if (lookahead == 'k') ADVANCE(67);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(22);
      END_STATE();
    case 27:
      if (lookahead == 'l') ADVANCE(37);
      END_STATE();
    case 28:
      if (lookahead == 'l') ADVANCE(121);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(123);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(29);
      END_STATE();
    case 31:
      if (lookahead == 'n') ADVANCE(38);
      END_STATE();
    case 32:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 33:
      if (lookahead == 'o') ADVANCE(31);
      END_STATE();
    case 34:
      if (lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 35:
      if (lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 36:
      if (lookahead == 'r') ADVANCE(60);
      END_STATE();
    case 37:
      if (lookahead == 's') ADVANCE(18);
      END_STATE();
    case 38:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 39:
      if (lookahead == 'u') ADVANCE(17);
      END_STATE();
    case 40:
      if (lookahead == 'u') ADVANCE(19);
      END_STATE();
    case 41:
      if (lookahead == '|') ADVANCE(110);
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
          lookahead == 'u') ADVANCE(150);
      END_STATE();
    case 43:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 44:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(136);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(133);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(136);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(126);
      END_STATE();
    case 49:
      if (eof) ADVANCE(52);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '#') ADVANCE(53);
      if (lookahead == '%') ADVANCE(109);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(143);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == ')') ADVANCE(101);
      if (lookahead == '*') ADVANCE(107);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(102);
      if (lookahead == '-') ADVANCE(106);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '/') ADVANCE(108);
      if (lookahead == '0') ADVANCE(129);
      if (lookahead == ':') ADVANCE(120);
      if (lookahead == '<') ADVANCE(117);
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '>') ADVANCE(114);
      if (lookahead == '[') ADVANCE(118);
      if (lookahead == ']') ADVANCE(119);
      if (lookahead == 'b') ADVANCE(34);
      if (lookahead == 'c') ADVANCE(33);
      if (lookahead == 'e') ADVANCE(26);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(20);
      if (lookahead == 'n') ADVANCE(24);
      if (lookahead == 't') ADVANCE(35);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '}') ADVANCE(64);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(49)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 50:
      if (eof) ADVANCE(52);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '#') ADVANCE(53);
      if (lookahead == '%') ADVANCE(109);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(143);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == '*') ADVANCE(107);
      if (lookahead == '+') ADVANCE(104);
      if (lookahead == ',') ADVANCE(102);
      if (lookahead == '-') ADVANCE(106);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '/') ADVANCE(108);
      if (lookahead == '0') ADVANCE(129);
      if (lookahead == '<') ADVANCE(117);
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '>') ADVANCE(114);
      if (lookahead == '[') ADVANCE(118);
      if (lookahead == ']') ADVANCE(119);
      if (lookahead == 'b') ADVANCE(92);
      if (lookahead == 'c') ADVANCE(91);
      if (lookahead == 'f') ADVANCE(70);
      if (lookahead == 'i') ADVANCE(78);
      if (lookahead == 'n') ADVANCE(82);
      if (lookahead == 't') ADVANCE(93);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '}') ADVANCE(64);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(50)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 51:
      if (eof) ADVANCE(52);
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '#') ADVANCE(53);
      if (lookahead == '\'') ADVANCE(143);
      if (lookahead == '(') ADVANCE(100);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(129);
      if (lookahead == '[') ADVANCE(118);
      if (lookahead == 'b') ADVANCE(92);
      if (lookahead == 'c') ADVANCE(91);
      if (lookahead == 'e') ADVANCE(87);
      if (lookahead == 'f') ADVANCE(70);
      if (lookahead == 'i') ADVANCE(78);
      if (lookahead == 'n') ADVANCE(82);
      if (lookahead == 't') ADVANCE(93);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '}') ADVANCE(64);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(51)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(53);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_elif);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_elif);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_else);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_for);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_continue);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_continue);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_break);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(112);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(84);
      if (lookahead == 'o') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(147);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(79);
      if (lookahead == 's') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(85);
      if (lookahead == 'u') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(129);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '.') ADVANCE(44);
      if (lookahead == '0') ADVANCE(129);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(115);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(116);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_nil);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_nil);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_null);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(126);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'E') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(126);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(45);
      if (lookahead == '.') ADVANCE(137);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(136);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'b') ADVANCE(135);
      if (lookahead == 'x') ADVANCE(47);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(128);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(45);
      if (lookahead == '.') ADVANCE(137);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(136);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(128);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(43);
      if (lookahead == '.') ADVANCE(137);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'b') ADVANCE(10);
      if (lookahead == 'x') ADVANCE(9);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(43);
      if (lookahead == '.') ADVANCE(137);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'b') ADVANCE(43);
      if (lookahead == 'x') ADVANCE(47);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(43);
      if (lookahead == '.') ADVANCE(137);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(46);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(133);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(48);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(133);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(46);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(133);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '.') ADVANCE(137);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(136);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(48);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(136);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '.') ADVANCE(137);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(136);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(128);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '.') ADVANCE(137);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(136);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(134);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(133);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(132);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(133);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(126);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'E') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(126);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(139);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_string_lit_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(142);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_string_lit_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(142);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_string_lit_token2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(144);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_string_lit_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(99);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 50},
  [2] = {.lex_state = 50},
  [3] = {.lex_state = 50},
  [4] = {.lex_state = 50},
  [5] = {.lex_state = 50},
  [6] = {.lex_state = 50},
  [7] = {.lex_state = 50},
  [8] = {.lex_state = 50},
  [9] = {.lex_state = 50},
  [10] = {.lex_state = 50},
  [11] = {.lex_state = 50},
  [12] = {.lex_state = 50},
  [13] = {.lex_state = 50},
  [14] = {.lex_state = 50},
  [15] = {.lex_state = 50},
  [16] = {.lex_state = 50},
  [17] = {.lex_state = 50},
  [18] = {.lex_state = 50},
  [19] = {.lex_state = 50},
  [20] = {.lex_state = 50},
  [21] = {.lex_state = 50},
  [22] = {.lex_state = 50},
  [23] = {.lex_state = 50},
  [24] = {.lex_state = 50},
  [25] = {.lex_state = 50},
  [26] = {.lex_state = 50},
  [27] = {.lex_state = 50},
  [28] = {.lex_state = 50},
  [29] = {.lex_state = 50},
  [30] = {.lex_state = 50},
  [31] = {.lex_state = 50},
  [32] = {.lex_state = 50},
  [33] = {.lex_state = 50},
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
  [60] = {.lex_state = 51},
  [61] = {.lex_state = 51},
  [62] = {.lex_state = 51},
  [63] = {.lex_state = 51},
  [64] = {.lex_state = 51},
  [65] = {.lex_state = 51},
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
  [88] = {.lex_state = 50},
  [89] = {.lex_state = 50},
  [90] = {.lex_state = 50},
  [91] = {.lex_state = 50},
  [92] = {.lex_state = 50},
  [93] = {.lex_state = 50},
  [94] = {.lex_state = 50},
  [95] = {.lex_state = 3},
  [96] = {.lex_state = 3},
  [97] = {.lex_state = 3},
  [98] = {.lex_state = 3},
  [99] = {.lex_state = 3},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 3},
  [102] = {.lex_state = 3},
  [103] = {.lex_state = 4},
  [104] = {.lex_state = 4},
  [105] = {.lex_state = 3},
  [106] = {.lex_state = 3},
  [107] = {.lex_state = 4},
  [108] = {.lex_state = 1},
  [109] = {.lex_state = 2},
  [110] = {.lex_state = 1},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 1},
  [113] = {.lex_state = 1},
  [114] = {.lex_state = 2},
  [115] = {.lex_state = 1},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 2},
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
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 3},
  [141] = {.lex_state = 0},
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
    [sym_number_lit] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(139),
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
    STATE(118), 1,
      sym_map_elem,
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
    STATE(127), 1,
      sym_map_elem,
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
    STATE(135), 1,
      sym_map_elem,
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
    STATE(78), 11,
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
  [1702] = 5,
    ACTIONS(227), 1,
      anon_sym_LPAREN,
    ACTIONS(229), 1,
      anon_sym_LBRACK,
    STATE(72), 1,
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
    STATE(74), 11,
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
    STATE(106), 11,
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
    STATE(79), 11,
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
  [2702] = 2,
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
  [2726] = 2,
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
  [2750] = 2,
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
  [2774] = 2,
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
  [2798] = 2,
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
  [2822] = 2,
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
  [2846] = 2,
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
  [2870] = 4,
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
  [2898] = 7,
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
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
  [2932] = 5,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
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
  [2962] = 6,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
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
  [2994] = 2,
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
  [3018] = 3,
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
  [3044] = 2,
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
  [3068] = 2,
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
  [3092] = 2,
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
  [3116] = 2,
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
  [3140] = 2,
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
  [3164] = 2,
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
  [3188] = 2,
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
  [3212] = 2,
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
  [3305] = 2,
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
  [3328] = 2,
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
  [3351] = 2,
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
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(334), 1,
      anon_sym_RPAREN,
    ACTIONS(336), 1,
      anon_sym_COMMA,
    STATE(129), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
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
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
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
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
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
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
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
  [3503] = 9,
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(344), 1,
      anon_sym_LBRACE,
    STATE(62), 1,
      sym_block_stmts,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3537] = 8,
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(346), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3569] = 8,
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(348), 1,
      anon_sym_RBRACK,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3600] = 8,
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(350), 1,
      anon_sym_RPAREN,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3631] = 8,
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(352), 1,
      anon_sym_COLON,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3662] = 9,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(354), 1,
      sym_identifier,
    ACTIONS(356), 1,
      anon_sym_RBRACK,
    ACTIONS(358), 1,
      sym_number_lit,
    STATE(122), 1,
      sym_list_elem,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(134), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [3695] = 9,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(354), 1,
      sym_identifier,
    ACTIONS(358), 1,
      sym_number_lit,
    ACTIONS(360), 1,
      anon_sym_RBRACK,
    STATE(130), 1,
      sym_list_elem,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(134), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [3728] = 8,
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(362), 1,
      anon_sym_RPAREN,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3759] = 8,
    ACTIONS(306), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(308), 1,
      anon_sym_AMP_AMP,
    ACTIONS(364), 1,
      anon_sym_RBRACK,
    ACTIONS(302), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(310), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(312), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(338), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(304), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3790] = 8,
    ACTIONS(27), 1,
      anon_sym_DQUOTE,
    ACTIONS(29), 1,
      anon_sym_SQUOTE,
    ACTIONS(354), 1,
      sym_identifier,
    ACTIONS(358), 1,
      sym_number_lit,
    STATE(131), 1,
      sym_list_elem,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(31), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(134), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [3820] = 3,
    ACTIONS(366), 1,
      anon_sym_SQUOTE,
    STATE(108), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(368), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3831] = 3,
    ACTIONS(371), 1,
      anon_sym_DQUOTE,
    STATE(116), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(373), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3842] = 3,
    ACTIONS(371), 1,
      anon_sym_SQUOTE,
    STATE(108), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(375), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3853] = 3,
    ACTIONS(377), 1,
      anon_sym_DQUOTE,
    STATE(114), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(379), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3864] = 3,
    ACTIONS(377), 1,
      anon_sym_SQUOTE,
    STATE(115), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(381), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3875] = 3,
    ACTIONS(383), 1,
      anon_sym_SQUOTE,
    STATE(110), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(385), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3886] = 3,
    ACTIONS(387), 1,
      anon_sym_DQUOTE,
    STATE(116), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(373), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3897] = 3,
    ACTIONS(387), 1,
      anon_sym_SQUOTE,
    STATE(108), 1,
      aux_sym_string_lit_repeat2,
    ACTIONS(375), 2,
      aux_sym_string_lit_token2,
      sym_escape_sequence,
  [3908] = 3,
    ACTIONS(389), 1,
      anon_sym_DQUOTE,
    STATE(116), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(391), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3919] = 3,
    ACTIONS(383), 1,
      anon_sym_DQUOTE,
    STATE(109), 1,
      aux_sym_string_lit_repeat1,
    ACTIONS(394), 2,
      aux_sym_string_lit_token1,
      sym_escape_sequence,
  [3930] = 3,
    ACTIONS(396), 1,
      anon_sym_RBRACE,
    ACTIONS(398), 1,
      anon_sym_COMMA,
    STATE(128), 1,
      aux_sym_map_expr_repeat1,
  [3940] = 3,
    ACTIONS(400), 1,
      anon_sym_COMMA,
    ACTIONS(403), 1,
      anon_sym_RBRACK,
    STATE(119), 1,
      aux_sym_list_expr_repeat1,
  [3950] = 3,
    ACTIONS(336), 1,
      anon_sym_COMMA,
    ACTIONS(405), 1,
      anon_sym_RPAREN,
    STATE(124), 1,
      aux_sym_argument_list_repeat1,
  [3960] = 3,
    ACTIONS(407), 1,
      anon_sym_COMMA,
    ACTIONS(409), 1,
      anon_sym_RBRACK,
    STATE(119), 1,
      aux_sym_list_expr_repeat1,
  [3970] = 3,
    ACTIONS(407), 1,
      anon_sym_COMMA,
    ACTIONS(411), 1,
      anon_sym_RBRACK,
    STATE(126), 1,
      aux_sym_list_expr_repeat1,
  [3980] = 3,
    ACTIONS(413), 1,
      anon_sym_RBRACE,
    ACTIONS(415), 1,
      anon_sym_COMMA,
    STATE(123), 1,
      aux_sym_map_expr_repeat1,
  [3990] = 3,
    ACTIONS(342), 1,
      anon_sym_RPAREN,
    ACTIONS(418), 1,
      anon_sym_COMMA,
    STATE(124), 1,
      aux_sym_argument_list_repeat1,
  [4000] = 3,
    ACTIONS(398), 1,
      anon_sym_COMMA,
    ACTIONS(421), 1,
      anon_sym_RBRACE,
    STATE(123), 1,
      aux_sym_map_expr_repeat1,
  [4010] = 3,
    ACTIONS(407), 1,
      anon_sym_COMMA,
    ACTIONS(423), 1,
      anon_sym_RBRACK,
    STATE(119), 1,
      aux_sym_list_expr_repeat1,
  [4020] = 3,
    ACTIONS(398), 1,
      anon_sym_COMMA,
    ACTIONS(425), 1,
      anon_sym_RBRACE,
    STATE(125), 1,
      aux_sym_map_expr_repeat1,
  [4030] = 3,
    ACTIONS(398), 1,
      anon_sym_COMMA,
    ACTIONS(427), 1,
      anon_sym_RBRACE,
    STATE(123), 1,
      aux_sym_map_expr_repeat1,
  [4040] = 3,
    ACTIONS(336), 1,
      anon_sym_COMMA,
    ACTIONS(429), 1,
      anon_sym_RPAREN,
    STATE(124), 1,
      aux_sym_argument_list_repeat1,
  [4050] = 3,
    ACTIONS(407), 1,
      anon_sym_COMMA,
    ACTIONS(431), 1,
      anon_sym_RBRACK,
    STATE(121), 1,
      aux_sym_list_expr_repeat1,
  [4060] = 1,
    ACTIONS(403), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4065] = 2,
    ACTIONS(344), 1,
      anon_sym_LBRACE,
    STATE(64), 1,
      sym_block_stmts,
  [4072] = 2,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(89), 1,
      sym_block_stmts,
  [4079] = 1,
    ACTIONS(435), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4084] = 1,
    ACTIONS(413), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [4089] = 2,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(88), 1,
      sym_block_stmts,
  [4096] = 2,
    ACTIONS(433), 1,
      anon_sym_LBRACE,
    STATE(90), 1,
      sym_block_stmts,
  [4103] = 1,
    ACTIONS(437), 1,
      sym_identifier,
  [4107] = 1,
    ACTIONS(439), 1,
      ts_builtin_sym_end,
  [4111] = 1,
    ACTIONS(441), 1,
      sym_identifier,
  [4115] = 1,
    ACTIONS(443), 1,
      anon_sym_in,
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
  [SMALL_STATE(68)] = 2726,
  [SMALL_STATE(69)] = 2750,
  [SMALL_STATE(70)] = 2774,
  [SMALL_STATE(71)] = 2798,
  [SMALL_STATE(72)] = 2822,
  [SMALL_STATE(73)] = 2846,
  [SMALL_STATE(74)] = 2870,
  [SMALL_STATE(75)] = 2898,
  [SMALL_STATE(76)] = 2932,
  [SMALL_STATE(77)] = 2962,
  [SMALL_STATE(78)] = 2994,
  [SMALL_STATE(79)] = 3018,
  [SMALL_STATE(80)] = 3044,
  [SMALL_STATE(81)] = 3068,
  [SMALL_STATE(82)] = 3092,
  [SMALL_STATE(83)] = 3116,
  [SMALL_STATE(84)] = 3140,
  [SMALL_STATE(85)] = 3164,
  [SMALL_STATE(86)] = 3188,
  [SMALL_STATE(87)] = 3212,
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
  [SMALL_STATE(99)] = 3537,
  [SMALL_STATE(100)] = 3569,
  [SMALL_STATE(101)] = 3600,
  [SMALL_STATE(102)] = 3631,
  [SMALL_STATE(103)] = 3662,
  [SMALL_STATE(104)] = 3695,
  [SMALL_STATE(105)] = 3728,
  [SMALL_STATE(106)] = 3759,
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
  [SMALL_STATE(134)] = 4079,
  [SMALL_STATE(135)] = 4084,
  [SMALL_STATE(136)] = 4089,
  [SMALL_STATE(137)] = 4096,
  [SMALL_STATE(138)] = 4103,
  [SMALL_STATE(139)] = 4107,
  [SMALL_STATE(140)] = 4111,
  [SMALL_STATE(141)] = 4115,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(55),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(140),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(34),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(94),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(92),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(54),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(103),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(117),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(113),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(12),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
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
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [237] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_stmt_repeat1, 2, .production_id = 7),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 2, .production_id = 7),
  [273] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 2, .production_id = 7), SHIFT_REPEAT(132),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 4, .production_id = 4),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_stmt, 4, .production_id = 4),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [282] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
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
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [310] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_in_stmt, 5),
  [316] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_in_stmt, 5),
  [318] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 6, .production_id = 8),
  [320] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_stmt, 6, .production_id = 8),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 5, .production_id = 6),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_stmt, 5, .production_id = 6),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_break_stmt, 1),
  [328] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_break_stmt, 1),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_continue_stmt, 1),
  [332] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_continue_stmt, 1),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_elem, 3),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [354] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [366] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_lit_repeat2, 2),
  [368] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_lit_repeat2, 2), SHIFT_REPEAT(108),
  [371] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [377] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [383] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [387] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [389] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_lit_repeat1, 2),
  [391] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_lit_repeat1, 2), SHIFT_REPEAT(116),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [400] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_expr_repeat1, 2), SHIFT_REPEAT(107),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_expr_repeat1, 2),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [413] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_map_expr_repeat1, 2),
  [415] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_map_expr_repeat1, 2), SHIFT_REPEAT(37),
  [418] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(53),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [435] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_elem, 1),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [439] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
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
