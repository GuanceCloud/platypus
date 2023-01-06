#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 159
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 80
#define ALIAS_COUNT 0
#define TOKEN_COUNT 45
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
  anon_sym_BQUOTE = 36,
  aux_sym_multiline_string_lit_token1 = 37,
  anon_sym_DQUOTE = 38,
  aux_sym_quoted_string_lit_token1 = 39,
  anon_sym_SQUOTE = 40,
  aux_sym_quoted_string_lit_token2 = 41,
  anon_sym_true = 42,
  anon_sym_false = 43,
  sym_escape_sequence = 44,
  sym_source_file = 45,
  sym_inline_statement = 46,
  sym__stmt = 47,
  sym_if_stmt = 48,
  sym_for_in_stmt = 49,
  sym_block_stmts = 50,
  sym_continue_stmt = 51,
  sym_break_stmt = 52,
  sym_assign_stmt = 53,
  sym_expr_stmt = 54,
  sym__expr = 55,
  sym_paren_expr = 56,
  sym_call_expr = 57,
  sym_argument_list = 58,
  sym_binary_expr = 59,
  sym_index_expr = 60,
  sym_list_expr = 61,
  sym_list_elem = 62,
  sym_map_expr = 63,
  sym_map_elem = 64,
  sym__literal = 65,
  sym_nil_lit = 66,
  sym_string_lit = 67,
  sym_multiline_string_lit = 68,
  sym_quoted_string_lit = 69,
  sym_bool_lit = 70,
  aux_sym_source_file_repeat1 = 71,
  aux_sym_inline_statement_repeat1 = 72,
  aux_sym_if_stmt_repeat1 = 73,
  aux_sym_argument_list_repeat1 = 74,
  aux_sym_list_expr_repeat1 = 75,
  aux_sym_map_expr_repeat1 = 76,
  aux_sym_multiline_string_lit_repeat1 = 77,
  aux_sym_quoted_string_lit_repeat1 = 78,
  aux_sym_quoted_string_lit_repeat2 = 79,
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
  [anon_sym_BQUOTE] = "`",
  [aux_sym_multiline_string_lit_token1] = "multiline_string_lit_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_quoted_string_lit_token1] = "quoted_string_lit_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_quoted_string_lit_token2] = "quoted_string_lit_token2",
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
  [sym_multiline_string_lit] = "multiline_string_lit",
  [sym_quoted_string_lit] = "quoted_string_lit",
  [sym_bool_lit] = "bool_lit",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_inline_statement_repeat1] = "inline_statement_repeat1",
  [aux_sym_if_stmt_repeat1] = "if_stmt_repeat1",
  [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
  [aux_sym_list_expr_repeat1] = "list_expr_repeat1",
  [aux_sym_map_expr_repeat1] = "map_expr_repeat1",
  [aux_sym_multiline_string_lit_repeat1] = "multiline_string_lit_repeat1",
  [aux_sym_quoted_string_lit_repeat1] = "quoted_string_lit_repeat1",
  [aux_sym_quoted_string_lit_repeat2] = "quoted_string_lit_repeat2",
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
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym_multiline_string_lit_token1] = aux_sym_multiline_string_lit_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_quoted_string_lit_token1] = aux_sym_quoted_string_lit_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_quoted_string_lit_token2] = aux_sym_quoted_string_lit_token2,
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
  [sym_multiline_string_lit] = sym_multiline_string_lit,
  [sym_quoted_string_lit] = sym_quoted_string_lit,
  [sym_bool_lit] = sym_bool_lit,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_inline_statement_repeat1] = aux_sym_inline_statement_repeat1,
  [aux_sym_if_stmt_repeat1] = aux_sym_if_stmt_repeat1,
  [aux_sym_argument_list_repeat1] = aux_sym_argument_list_repeat1,
  [aux_sym_list_expr_repeat1] = aux_sym_list_expr_repeat1,
  [aux_sym_map_expr_repeat1] = aux_sym_map_expr_repeat1,
  [aux_sym_multiline_string_lit_repeat1] = aux_sym_multiline_string_lit_repeat1,
  [aux_sym_quoted_string_lit_repeat1] = aux_sym_quoted_string_lit_repeat1,
  [aux_sym_quoted_string_lit_repeat2] = aux_sym_quoted_string_lit_repeat2,
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
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_multiline_string_lit_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_string_lit_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_string_lit_token2] = {
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
  [sym_multiline_string_lit] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_string_lit] = {
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
  [aux_sym_multiline_string_lit_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_string_lit_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quoted_string_lit_repeat2] = {
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
  [5] = 5,
  [6] = 5,
  [7] = 7,
  [8] = 7,
  [9] = 9,
  [10] = 9,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 13,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 14,
  [25] = 23,
  [26] = 26,
  [27] = 27,
  [28] = 20,
  [29] = 21,
  [30] = 22,
  [31] = 27,
  [32] = 32,
  [33] = 32,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 35,
  [38] = 36,
  [39] = 39,
  [40] = 39,
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
  [67] = 34,
  [68] = 68,
  [69] = 68,
  [70] = 70,
  [71] = 71,
  [72] = 71,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 65,
  [79] = 50,
  [80] = 80,
  [81] = 81,
  [82] = 42,
  [83] = 44,
  [84] = 61,
  [85] = 59,
  [86] = 57,
  [87] = 64,
  [88] = 45,
  [89] = 56,
  [90] = 60,
  [91] = 91,
  [92] = 49,
  [93] = 51,
  [94] = 53,
  [95] = 95,
  [96] = 41,
  [97] = 55,
  [98] = 54,
  [99] = 62,
  [100] = 91,
  [101] = 52,
  [102] = 102,
  [103] = 63,
  [104] = 46,
  [105] = 47,
  [106] = 48,
  [107] = 81,
  [108] = 43,
  [109] = 58,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 114,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 116,
  [120] = 117,
  [121] = 121,
  [122] = 118,
  [123] = 113,
  [124] = 112,
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
  [138] = 133,
  [139] = 134,
  [140] = 140,
  [141] = 140,
  [142] = 135,
  [143] = 128,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 151,
  [156] = 156,
  [157] = 157,
  [158] = 158,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(53);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(137);
      if (lookahead == '#') ADVANCE(55);
      if (lookahead == '%') ADVANCE(103);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(140);
      if (lookahead == '(') ADVANCE(96);
      if (lookahead == ')') ADVANCE(97);
      if (lookahead == '*') ADVANCE(101);
      if (lookahead == '+') ADVANCE(99);
      if (lookahead == ',') ADVANCE(98);
      if (lookahead == '-') ADVANCE(100);
      if (lookahead == '/') ADVANCE(102);
      if (lookahead == ':') ADVANCE(114);
      if (lookahead == '<') ADVANCE(111);
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '>') ADVANCE(108);
      if (lookahead == '[') ADVANCE(112);
      if (lookahead == '\\') ADVANCE(43);
      if (lookahead == ']') ADVANCE(113);
      if (lookahead == '`') ADVANCE(134);
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
          lookahead == ' ') SKIP(51)
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(54);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '%') ADVANCE(103);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '(') ADVANCE(96);
      if (lookahead == '*') ADVANCE(101);
      if (lookahead == '+') ADVANCE(99);
      if (lookahead == '-') ADVANCE(100);
      if (lookahead == '/') ADVANCE(102);
      if (lookahead == '<') ADVANCE(111);
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '>') ADVANCE(108);
      if (lookahead == '[') ADVANCE(112);
      if (lookahead == 'e') ADVANCE(26);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == '\'') ADVANCE(140);
      if (lookahead == '\\') ADVANCE(43);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0) ADVANCE(142);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(5)
      if (lookahead == '"') ADVANCE(137);
      if (lookahead == '\\') ADVANCE(43);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(138);
      if (lookahead != 0) ADVANCE(139);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(137);
      if (lookahead == '\'') ADVANCE(140);
      if (lookahead == '(') ADVANCE(96);
      if (lookahead == ')') ADVANCE(97);
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '[') ADVANCE(112);
      if (lookahead == ']') ADVANCE(113);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == 'f') ADVANCE(71);
      if (lookahead == 'n') ADVANCE(79);
      if (lookahead == 't') ADVANCE(89);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '}') ADVANCE(64);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(137);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      END_STATE();
    case 6:
      if (lookahead == '&') ADVANCE(105);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(140);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '0') ADVANCE(124);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '0') ADVANCE(121);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(130);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '0') ADVANCE(123);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 11:
      if (lookahead == '=') ADVANCE(107);
      END_STATE();
    case 12:
      if (lookahead == '\\') ADVANCE(43);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(135);
      if (lookahead != 0) ADVANCE(136);
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
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(145);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 20:
      if (lookahead == 'f') ADVANCE(56);
      if (lookahead == 'n') ADVANCE(62);
      END_STATE();
    case 21:
      if (lookahead == 'f') ADVANCE(58);
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
      if (lookahead == 'l') ADVANCE(115);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(117);
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
      if (lookahead == '|') ADVANCE(104);
      END_STATE();
    case 42:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(42)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 43:
      if (lookahead == '"' ||
          lookahead == '/' ||
          lookahead == '\\' ||
          lookahead == 'b' ||
          lookahead == 'f' ||
          lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't' ||
          lookahead == 'u') ADVANCE(147);
      END_STATE();
    case 44:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 45:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(119);
      END_STATE();
    case 46:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(130);
      END_STATE();
    case 47:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(127);
      END_STATE();
    case 48:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(130);
      END_STATE();
    case 49:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(120);
      END_STATE();
    case 50:
      if (eof) ADVANCE(53);
      if (lookahead == '\n') ADVANCE(54);
      if (lookahead == '"') ADVANCE(137);
      if (lookahead == '#') ADVANCE(55);
      if (lookahead == '\'') ADVANCE(140);
      if (lookahead == '(') ADVANCE(96);
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '[') ADVANCE(112);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == 'b') ADVANCE(88);
      if (lookahead == 'c') ADVANCE(87);
      if (lookahead == 'f') ADVANCE(70);
      if (lookahead == 'i') ADVANCE(77);
      if (lookahead == 'n') ADVANCE(79);
      if (lookahead == 't') ADVANCE(89);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '}') ADVANCE(64);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(50)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 51:
      if (eof) ADVANCE(53);
      if (lookahead == '!') ADVANCE(11);
      if (lookahead == '"') ADVANCE(137);
      if (lookahead == '#') ADVANCE(55);
      if (lookahead == '%') ADVANCE(103);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(140);
      if (lookahead == '(') ADVANCE(96);
      if (lookahead == ')') ADVANCE(97);
      if (lookahead == '*') ADVANCE(101);
      if (lookahead == '+') ADVANCE(99);
      if (lookahead == ',') ADVANCE(98);
      if (lookahead == '-') ADVANCE(100);
      if (lookahead == '/') ADVANCE(102);
      if (lookahead == ':') ADVANCE(114);
      if (lookahead == '<') ADVANCE(111);
      if (lookahead == '=') ADVANCE(69);
      if (lookahead == '>') ADVANCE(108);
      if (lookahead == '[') ADVANCE(112);
      if (lookahead == ']') ADVANCE(113);
      if (lookahead == '`') ADVANCE(134);
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
          lookahead == ' ') SKIP(51)
      END_STATE();
    case 52:
      if (eof) ADVANCE(53);
      if (lookahead == '"') ADVANCE(137);
      if (lookahead == '#') ADVANCE(55);
      if (lookahead == '\'') ADVANCE(140);
      if (lookahead == '(') ADVANCE(96);
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '0') ADVANCE(124);
      if (lookahead == '[') ADVANCE(112);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == 'b') ADVANCE(88);
      if (lookahead == 'c') ADVANCE(87);
      if (lookahead == 'f') ADVANCE(70);
      if (lookahead == 'i') ADVANCE(77);
      if (lookahead == 'n') ADVANCE(79);
      if (lookahead == 't') ADVANCE(89);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '}') ADVANCE(64);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(52)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_newline);
      if (lookahead == '\n') ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(55);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_if);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_elif);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_for);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
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
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_break);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(106);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(81);
      if (lookahead == 'o') ADVANCE(90);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(82);
      if (lookahead == 'u') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(91);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(83);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(109);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(110);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_nil);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_nil);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_null);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(45);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(119);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(49);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(120);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'E') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(120);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(46);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(130);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'b') ADVANCE(129);
      if (lookahead == 'x') ADVANCE(48);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(128);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(46);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(130);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(128);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'b') ADVANCE(44);
      if (lookahead == 'x') ADVANCE(48);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'b') ADVANCE(10);
      if (lookahead == 'x') ADVANCE(9);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(44);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'E' ||
          lookahead == 'P' ||
          lookahead == 'e' ||
          lookahead == 'p') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(127);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(49);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(126);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(127);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(127);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(126);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(127);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(130);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(49);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(128);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(130);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(130);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(128);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(130);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(128);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(130);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(127);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(126);
      if (lookahead == 'P' ||
          lookahead == 'p') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'D') ||
          ('a' <= lookahead && lookahead <= 'd')) ADVANCE(127);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'f') ADVANCE(120);
      if (lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(49);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'E') ||
          ('a' <= lookahead && lookahead <= 'e')) ADVANCE(120);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_number_lit);
      if (lookahead == 'F' ||
          lookahead == 'L' ||
          lookahead == 'U' ||
          lookahead == 'f' ||
          lookahead == 'l' ||
          lookahead == 'u') ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_multiline_string_lit_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(135);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(136);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_multiline_string_lit_token1);
      if (lookahead != 0 &&
          lookahead != '\\' &&
          lookahead != '`') ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_quoted_string_lit_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_quoted_string_lit_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(139);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_quoted_string_lit_token2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(142);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_quoted_string_lit_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(142);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(95);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 52},
  [2] = {.lex_state = 52},
  [3] = {.lex_state = 52},
  [4] = {.lex_state = 52},
  [5] = {.lex_state = 52},
  [6] = {.lex_state = 52},
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
  [22] = {.lex_state = 4},
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
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 50},
  [36] = {.lex_state = 50},
  [37] = {.lex_state = 50},
  [38] = {.lex_state = 50},
  [39] = {.lex_state = 50},
  [40] = {.lex_state = 50},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 4},
  [69] = {.lex_state = 4},
  [70] = {.lex_state = 4},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 1},
  [79] = {.lex_state = 1},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 1},
  [84] = {.lex_state = 1},
  [85] = {.lex_state = 1},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 1},
  [88] = {.lex_state = 1},
  [89] = {.lex_state = 1},
  [90] = {.lex_state = 1},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 1},
  [93] = {.lex_state = 1},
  [94] = {.lex_state = 1},
  [95] = {.lex_state = 1},
  [96] = {.lex_state = 1},
  [97] = {.lex_state = 1},
  [98] = {.lex_state = 1},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 1},
  [102] = {.lex_state = 1},
  [103] = {.lex_state = 1},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 1},
  [106] = {.lex_state = 1},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 1},
  [109] = {.lex_state = 1},
  [110] = {.lex_state = 12},
  [111] = {.lex_state = 1},
  [112] = {.lex_state = 2},
  [113] = {.lex_state = 3},
  [114] = {.lex_state = 12},
  [115] = {.lex_state = 12},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 3},
  [118] = {.lex_state = 12},
  [119] = {.lex_state = 2},
  [120] = {.lex_state = 3},
  [121] = {.lex_state = 1},
  [122] = {.lex_state = 12},
  [123] = {.lex_state = 3},
  [124] = {.lex_state = 2},
  [125] = {.lex_state = 1},
  [126] = {.lex_state = 3},
  [127] = {.lex_state = 2},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 1},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 1},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 1},
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
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 50},
  [152] = {.lex_state = 50},
  [153] = {.lex_state = 50},
  [154] = {.lex_state = 50},
  [155] = {.lex_state = 50},
  [156] = {.lex_state = 42},
  [157] = {.lex_state = 50},
  [158] = {.lex_state = 50},
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
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(150),
    [sym_inline_statement] = STATE(2),
    [sym__stmt] = STATE(151),
    [sym_if_stmt] = STATE(151),
    [sym_for_in_stmt] = STATE(151),
    [sym_continue_stmt] = STATE(151),
    [sym_break_stmt] = STATE(151),
    [sym_assign_stmt] = STATE(151),
    [sym_expr_stmt] = STATE(151),
    [sym__expr] = STATE(95),
    [sym_paren_expr] = STATE(95),
    [sym_call_expr] = STATE(95),
    [sym_binary_expr] = STATE(95),
    [sym_index_expr] = STATE(95),
    [sym_list_expr] = STATE(95),
    [sym_map_expr] = STATE(95),
    [sym__literal] = STATE(95),
    [sym_nil_lit] = STATE(95),
    [sym_string_lit] = STATE(95),
    [sym_multiline_string_lit] = STATE(86),
    [sym_quoted_string_lit] = STATE(86),
    [sym_bool_lit] = STATE(95),
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
    [anon_sym_BQUOTE] = ACTIONS(27),
    [anon_sym_DQUOTE] = ACTIONS(29),
    [anon_sym_SQUOTE] = ACTIONS(31),
    [anon_sym_true] = ACTIONS(33),
    [anon_sym_false] = ACTIONS(33),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 20,
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
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(5), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(151), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
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
  [81] = 20,
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
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(37), 1,
      sym_comment,
    ACTIONS(39), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(6), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(155), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
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
  [162] = 20,
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
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(37), 1,
      sym_comment,
    ACTIONS(41), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(3), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(155), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
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
  [243] = 20,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    ACTIONS(45), 1,
      sym_comment,
    ACTIONS(48), 1,
      anon_sym_if,
    ACTIONS(51), 1,
      anon_sym_for,
    ACTIONS(54), 1,
      anon_sym_LBRACE,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_break,
    ACTIONS(63), 1,
      sym_identifier,
    ACTIONS(66), 1,
      anon_sym_LPAREN,
    ACTIONS(69), 1,
      anon_sym_LBRACK,
    ACTIONS(75), 1,
      sym_number_lit,
    ACTIONS(78), 1,
      anon_sym_BQUOTE,
    ACTIONS(81), 1,
      anon_sym_DQUOTE,
    ACTIONS(84), 1,
      anon_sym_SQUOTE,
    ACTIONS(72), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(87), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(5), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(151), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
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
  [324] = 20,
    ACTIONS(43), 1,
      anon_sym_RBRACE,
    ACTIONS(48), 1,
      anon_sym_if,
    ACTIONS(51), 1,
      anon_sym_for,
    ACTIONS(54), 1,
      anon_sym_LBRACE,
    ACTIONS(57), 1,
      anon_sym_continue,
    ACTIONS(60), 1,
      anon_sym_break,
    ACTIONS(63), 1,
      sym_identifier,
    ACTIONS(66), 1,
      anon_sym_LPAREN,
    ACTIONS(69), 1,
      anon_sym_LBRACK,
    ACTIONS(75), 1,
      sym_number_lit,
    ACTIONS(78), 1,
      anon_sym_BQUOTE,
    ACTIONS(81), 1,
      anon_sym_DQUOTE,
    ACTIONS(84), 1,
      anon_sym_SQUOTE,
    ACTIONS(90), 1,
      sym_comment,
    ACTIONS(72), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(87), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(6), 2,
      sym_inline_statement,
      aux_sym_source_file_repeat1,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(155), 7,
      sym__stmt,
      sym_if_stmt,
      sym_for_in_stmt,
      sym_continue_stmt,
      sym_break_stmt,
      sym_assign_stmt,
      sym_expr_stmt,
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
  [405] = 14,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(95), 1,
      anon_sym_RBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(105), 1,
      sym_number_lit,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    STATE(140), 1,
      sym_map_elem,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [461] = 14,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(105), 1,
      sym_number_lit,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(115), 1,
      anon_sym_RBRACE,
    STATE(141), 1,
      sym_map_elem,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [517] = 13,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(117), 1,
      anon_sym_RPAREN,
    ACTIONS(119), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [570] = 13,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(121), 1,
      anon_sym_RPAREN,
    ACTIONS(123), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [623] = 13,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(105), 1,
      sym_number_lit,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    STATE(144), 1,
      sym_map_elem,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [676] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(125), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [726] = 12,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(127), 1,
      sym_identifier,
    ACTIONS(129), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(93), 11,
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
  [776] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(131), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [826] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(133), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(51), 11,
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
  [876] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(135), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [926] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(137), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [976] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(139), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(73), 11,
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
  [1026] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(141), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [1076] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(143), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(91), 11,
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
  [1126] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(145), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(59), 11,
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
  [1176] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(147), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [1226] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(149), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [1276] = 12,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(127), 1,
      sym_identifier,
    ACTIONS(151), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(92), 11,
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
  [1326] = 12,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(127), 1,
      sym_identifier,
    ACTIONS(153), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(88), 11,
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
  [1376] = 12,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(127), 1,
      sym_identifier,
    ACTIONS(155), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [1426] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(157), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(43), 11,
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
  [1476] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(159), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [1526] = 12,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(127), 1,
      sym_identifier,
    ACTIONS(161), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [1576] = 12,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(127), 1,
      sym_identifier,
    ACTIONS(163), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(83), 11,
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
  [1626] = 12,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 1,
      anon_sym_BQUOTE,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(127), 1,
      sym_identifier,
    ACTIONS(165), 1,
      sym_number_lit,
    ACTIONS(23), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(33), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(86), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(108), 11,
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
  [1676] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(167), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
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
  [1726] = 12,
    ACTIONS(93), 1,
      anon_sym_LBRACE,
    ACTIONS(97), 1,
      sym_identifier,
    ACTIONS(99), 1,
      anon_sym_LPAREN,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(169), 1,
      sym_number_lit,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(107), 11,
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
  [1776] = 5,
    ACTIONS(173), 1,
      anon_sym_LPAREN,
    ACTIONS(177), 1,
      anon_sym_LBRACK,
    STATE(50), 1,
      sym_argument_list,
    ACTIONS(175), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(171), 17,
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
  [1809] = 4,
    ACTIONS(179), 1,
      ts_builtin_sym_end,
    ACTIONS(181), 1,
      sym_newline,
    STATE(40), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(183), 17,
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
      anon_sym_BQUOTE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1838] = 3,
    ACTIONS(185), 1,
      sym_newline,
    STATE(36), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(188), 18,
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
      anon_sym_BQUOTE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1865] = 3,
    ACTIONS(190), 1,
      sym_newline,
    STATE(39), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(183), 18,
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
      anon_sym_BQUOTE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1892] = 4,
    ACTIONS(192), 1,
      ts_builtin_sym_end,
    ACTIONS(194), 1,
      sym_newline,
    STATE(38), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(188), 17,
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
      anon_sym_BQUOTE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1921] = 3,
    ACTIONS(197), 1,
      sym_newline,
    STATE(36), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(199), 18,
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
      anon_sym_BQUOTE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1948] = 4,
    ACTIONS(201), 1,
      ts_builtin_sym_end,
    ACTIONS(203), 1,
      sym_newline,
    STATE(38), 1,
      aux_sym_inline_statement_repeat1,
    ACTIONS(199), 17,
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
      anon_sym_BQUOTE,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_true,
      anon_sym_false,
  [1977] = 2,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(205), 17,
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
  [2001] = 2,
    ACTIONS(211), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 17,
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
  [2025] = 4,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(219), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(213), 12,
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
  [2053] = 7,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(213), 8,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2087] = 6,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(213), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_PIPE_PIPE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_RBRACK,
      anon_sym_COLON,
  [2119] = 2,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(229), 17,
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
  [2143] = 2,
    ACTIONS(235), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 17,
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
  [2167] = 2,
    ACTIONS(239), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(237), 17,
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
  [2191] = 2,
    ACTIONS(219), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(213), 17,
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
  [2215] = 2,
    ACTIONS(243), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(241), 17,
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
  [2239] = 3,
    ACTIONS(219), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(213), 14,
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
  [2265] = 2,
    ACTIONS(247), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(245), 17,
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
  [2289] = 2,
    ACTIONS(251), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(249), 17,
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
  [2313] = 2,
    ACTIONS(255), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(253), 17,
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
  [2337] = 2,
    ACTIONS(259), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(257), 17,
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
  [2361] = 2,
    ACTIONS(263), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(261), 17,
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
  [2385] = 2,
    ACTIONS(267), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(265), 17,
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
  [2409] = 2,
    ACTIONS(271), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(269), 17,
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
  [2433] = 5,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(213), 10,
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
  [2463] = 2,
    ACTIONS(275), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(273), 17,
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
  [2487] = 2,
    ACTIONS(279), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(277), 17,
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
  [2511] = 2,
    ACTIONS(283), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(281), 17,
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
  [2535] = 2,
    ACTIONS(287), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(285), 17,
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
  [2559] = 2,
    ACTIONS(291), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(289), 17,
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
  [2583] = 2,
    ACTIONS(295), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(293), 17,
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
  [2607] = 6,
    ACTIONS(171), 1,
      sym_newline,
    ACTIONS(297), 1,
      anon_sym_EQ,
    ACTIONS(299), 1,
      anon_sym_LPAREN,
    ACTIONS(301), 1,
      anon_sym_LBRACK,
    STATE(79), 1,
      sym_argument_list,
    ACTIONS(175), 13,
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
  [2638] = 5,
    ACTIONS(171), 1,
      sym_newline,
    ACTIONS(299), 1,
      anon_sym_LPAREN,
    ACTIONS(301), 1,
      anon_sym_LBRACK,
    STATE(79), 1,
      sym_argument_list,
    ACTIONS(175), 13,
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
  [2666] = 11,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(303), 1,
      sym_identifier,
    ACTIONS(305), 1,
      anon_sym_RBRACK,
    ACTIONS(307), 1,
      sym_number_lit,
    STATE(128), 1,
      sym_list_elem,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(148), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [2706] = 11,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(303), 1,
      sym_identifier,
    ACTIONS(307), 1,
      sym_number_lit,
    ACTIONS(309), 1,
      anon_sym_RBRACK,
    STATE(143), 1,
      sym_list_elem,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(148), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [2746] = 10,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(303), 1,
      sym_identifier,
    ACTIONS(307), 1,
      sym_number_lit,
    STATE(146), 1,
      sym_list_elem,
    ACTIONS(103), 2,
      anon_sym_nil,
      anon_sym_null,
    ACTIONS(113), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(57), 2,
      sym_multiline_string_lit,
      sym_quoted_string_lit,
    STATE(148), 4,
      sym__literal,
      sym_nil_lit,
      sym_string_lit,
      sym_bool_lit,
  [2783] = 10,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(311), 1,
      anon_sym_RPAREN,
    ACTIONS(313), 1,
      anon_sym_COMMA,
    STATE(133), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2820] = 10,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(313), 1,
      anon_sym_COMMA,
    ACTIONS(317), 1,
      anon_sym_RPAREN,
    STATE(138), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2857] = 9,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(319), 1,
      anon_sym_LBRACE,
    STATE(129), 1,
      sym_block_stmts,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2891] = 8,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(321), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2923] = 9,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(319), 1,
      anon_sym_LBRACE,
    STATE(125), 1,
      sym_block_stmts,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2957] = 8,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(323), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2989] = 9,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(319), 1,
      anon_sym_LBRACE,
    STATE(153), 1,
      sym_block_stmts,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3023] = 2,
    ACTIONS(293), 1,
      sym_newline,
    ACTIONS(295), 13,
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
  [3042] = 2,
    ACTIONS(241), 1,
      sym_newline,
    ACTIONS(243), 13,
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
  [3061] = 8,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(325), 1,
      anon_sym_COLON,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3092] = 8,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(327), 1,
      anon_sym_RPAREN,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3123] = 2,
    ACTIONS(209), 1,
      sym_newline,
    ACTIONS(211), 13,
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
  [3142] = 7,
    ACTIONS(213), 1,
      sym_newline,
    ACTIONS(333), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(335), 1,
      anon_sym_AMP_AMP,
    ACTIONS(219), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(329), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(331), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(337), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3171] = 2,
    ACTIONS(277), 1,
      sym_newline,
    ACTIONS(279), 13,
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
  [3190] = 5,
    ACTIONS(213), 1,
      sym_newline,
    ACTIONS(329), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(331), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(219), 4,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(337), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3215] = 2,
    ACTIONS(265), 1,
      sym_newline,
    ACTIONS(267), 13,
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
  [3234] = 2,
    ACTIONS(289), 1,
      sym_newline,
    ACTIONS(291), 13,
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
  [3253] = 6,
    ACTIONS(213), 1,
      sym_newline,
    ACTIONS(335), 1,
      anon_sym_AMP_AMP,
    ACTIONS(329), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(219), 3,
      anon_sym_PIPE_PIPE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(331), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(337), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3280] = 2,
    ACTIONS(261), 1,
      sym_newline,
    ACTIONS(263), 13,
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
  [3299] = 2,
    ACTIONS(273), 1,
      sym_newline,
    ACTIONS(275), 13,
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
  [3318] = 8,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(339), 1,
      anon_sym_RBRACK,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3349] = 2,
    ACTIONS(213), 1,
      sym_newline,
    ACTIONS(219), 13,
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
  [3368] = 3,
    ACTIONS(213), 1,
      sym_newline,
    ACTIONS(331), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(219), 10,
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
  [3389] = 2,
    ACTIONS(249), 1,
      sym_newline,
    ACTIONS(251), 13,
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
  [3408] = 7,
    ACTIONS(333), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(335), 1,
      anon_sym_AMP_AMP,
    ACTIONS(341), 1,
      sym_newline,
    ACTIONS(329), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(343), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(331), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(337), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3437] = 2,
    ACTIONS(205), 1,
      sym_newline,
    ACTIONS(207), 13,
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
  [3456] = 2,
    ACTIONS(257), 1,
      sym_newline,
    ACTIONS(259), 13,
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
  [3475] = 2,
    ACTIONS(253), 1,
      sym_newline,
    ACTIONS(255), 13,
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
  [3494] = 2,
    ACTIONS(281), 1,
      sym_newline,
    ACTIONS(283), 13,
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
  [3513] = 8,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(345), 1,
      anon_sym_RBRACK,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3544] = 2,
    ACTIONS(245), 1,
      sym_newline,
    ACTIONS(247), 13,
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
  [3563] = 7,
    ACTIONS(333), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(335), 1,
      anon_sym_AMP_AMP,
    ACTIONS(347), 1,
      sym_newline,
    ACTIONS(329), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(343), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(331), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(337), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3592] = 2,
    ACTIONS(285), 1,
      sym_newline,
    ACTIONS(287), 13,
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
  [3611] = 2,
    ACTIONS(229), 1,
      sym_newline,
    ACTIONS(231), 13,
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
  [3630] = 2,
    ACTIONS(233), 1,
      sym_newline,
    ACTIONS(235), 13,
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
  [3649] = 2,
    ACTIONS(237), 1,
      sym_newline,
    ACTIONS(239), 13,
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
  [3668] = 8,
    ACTIONS(221), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 1,
      anon_sym_AMP_AMP,
    ACTIONS(349), 1,
      anon_sym_RPAREN,
    ACTIONS(215), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(225), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(315), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(217), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [3699] = 4,
    ACTIONS(213), 1,
      sym_newline,
    ACTIONS(329), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(331), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(219), 8,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3722] = 2,
    ACTIONS(269), 1,
      sym_newline,
    ACTIONS(271), 13,
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
  [3741] = 3,
    ACTIONS(351), 1,
      anon_sym_BQUOTE,
    STATE(110), 1,
      aux_sym_multiline_string_lit_repeat1,
    ACTIONS(353), 2,
      aux_sym_multiline_string_lit_token1,
      sym_escape_sequence,
  [3752] = 4,
    ACTIONS(356), 1,
      sym_newline,
    ACTIONS(358), 1,
      anon_sym_elif,
    ACTIONS(360), 1,
      anon_sym_else,
    STATE(121), 1,
      aux_sym_if_stmt_repeat1,
  [3765] = 3,
    ACTIONS(362), 1,
      anon_sym_SQUOTE,
    STATE(127), 1,
      aux_sym_quoted_string_lit_repeat2,
    ACTIONS(364), 2,
      aux_sym_quoted_string_lit_token2,
      sym_escape_sequence,
  [3776] = 3,
    ACTIONS(362), 1,
      anon_sym_DQUOTE,
    STATE(126), 1,
      aux_sym_quoted_string_lit_repeat1,
    ACTIONS(366), 2,
      aux_sym_quoted_string_lit_token1,
      sym_escape_sequence,
  [3787] = 3,
    ACTIONS(368), 1,
      anon_sym_BQUOTE,
    STATE(110), 1,
      aux_sym_multiline_string_lit_repeat1,
    ACTIONS(370), 2,
      aux_sym_multiline_string_lit_token1,
      sym_escape_sequence,
  [3798] = 3,
    ACTIONS(372), 1,
      anon_sym_BQUOTE,
    STATE(110), 1,
      aux_sym_multiline_string_lit_repeat1,
    ACTIONS(370), 2,
      aux_sym_multiline_string_lit_token1,
      sym_escape_sequence,
  [3809] = 3,
    ACTIONS(374), 1,
      anon_sym_SQUOTE,
    STATE(124), 1,
      aux_sym_quoted_string_lit_repeat2,
    ACTIONS(376), 2,
      aux_sym_quoted_string_lit_token2,
      sym_escape_sequence,
  [3820] = 3,
    ACTIONS(374), 1,
      anon_sym_DQUOTE,
    STATE(123), 1,
      aux_sym_quoted_string_lit_repeat1,
    ACTIONS(378), 2,
      aux_sym_quoted_string_lit_token1,
      sym_escape_sequence,
  [3831] = 3,
    ACTIONS(380), 1,
      anon_sym_BQUOTE,
    STATE(115), 1,
      aux_sym_multiline_string_lit_repeat1,
    ACTIONS(382), 2,
      aux_sym_multiline_string_lit_token1,
      sym_escape_sequence,
  [3842] = 3,
    ACTIONS(384), 1,
      anon_sym_SQUOTE,
    STATE(112), 1,
      aux_sym_quoted_string_lit_repeat2,
    ACTIONS(386), 2,
      aux_sym_quoted_string_lit_token2,
      sym_escape_sequence,
  [3853] = 3,
    ACTIONS(384), 1,
      anon_sym_DQUOTE,
    STATE(113), 1,
      aux_sym_quoted_string_lit_repeat1,
    ACTIONS(388), 2,
      aux_sym_quoted_string_lit_token1,
      sym_escape_sequence,
  [3864] = 4,
    ACTIONS(390), 1,
      sym_newline,
    ACTIONS(392), 1,
      anon_sym_elif,
    ACTIONS(395), 1,
      anon_sym_else,
    STATE(121), 1,
      aux_sym_if_stmt_repeat1,
  [3877] = 3,
    ACTIONS(397), 1,
      anon_sym_BQUOTE,
    STATE(114), 1,
      aux_sym_multiline_string_lit_repeat1,
    ACTIONS(399), 2,
      aux_sym_multiline_string_lit_token1,
      sym_escape_sequence,
  [3888] = 3,
    ACTIONS(401), 1,
      anon_sym_DQUOTE,
    STATE(126), 1,
      aux_sym_quoted_string_lit_repeat1,
    ACTIONS(366), 2,
      aux_sym_quoted_string_lit_token1,
      sym_escape_sequence,
  [3899] = 3,
    ACTIONS(401), 1,
      anon_sym_SQUOTE,
    STATE(127), 1,
      aux_sym_quoted_string_lit_repeat2,
    ACTIONS(364), 2,
      aux_sym_quoted_string_lit_token2,
      sym_escape_sequence,
  [3910] = 4,
    ACTIONS(358), 1,
      anon_sym_elif,
    ACTIONS(403), 1,
      sym_newline,
    ACTIONS(405), 1,
      anon_sym_else,
    STATE(111), 1,
      aux_sym_if_stmt_repeat1,
  [3923] = 3,
    ACTIONS(407), 1,
      anon_sym_DQUOTE,
    STATE(126), 1,
      aux_sym_quoted_string_lit_repeat1,
    ACTIONS(409), 2,
      aux_sym_quoted_string_lit_token1,
      sym_escape_sequence,
  [3934] = 3,
    ACTIONS(412), 1,
      anon_sym_SQUOTE,
    STATE(127), 1,
      aux_sym_quoted_string_lit_repeat2,
    ACTIONS(414), 2,
      aux_sym_quoted_string_lit_token2,
      sym_escape_sequence,
  [3945] = 3,
    ACTIONS(417), 1,
      anon_sym_COMMA,
    ACTIONS(419), 1,
      anon_sym_RBRACK,
    STATE(134), 1,
      aux_sym_list_expr_repeat1,
  [3955] = 2,
    ACTIONS(421), 1,
      sym_newline,
    ACTIONS(423), 2,
      anon_sym_elif,
      anon_sym_else,
  [3963] = 3,
    ACTIONS(425), 1,
      anon_sym_RBRACE,
    ACTIONS(427), 1,
      anon_sym_COMMA,
    STATE(130), 1,
      aux_sym_map_expr_repeat1,
  [3973] = 2,
    ACTIONS(430), 1,
      sym_newline,
    ACTIONS(432), 2,
      anon_sym_elif,
      anon_sym_else,
  [3981] = 3,
    ACTIONS(321), 1,
      anon_sym_RPAREN,
    ACTIONS(434), 1,
      anon_sym_COMMA,
    STATE(132), 1,
      aux_sym_argument_list_repeat1,
  [3991] = 3,
    ACTIONS(313), 1,
      anon_sym_COMMA,
    ACTIONS(437), 1,
      anon_sym_RPAREN,
    STATE(132), 1,
      aux_sym_argument_list_repeat1,
  [4001] = 3,
    ACTIONS(417), 1,
      anon_sym_COMMA,
    ACTIONS(439), 1,
      anon_sym_RBRACK,
    STATE(136), 1,
      aux_sym_list_expr_repeat1,
  [4011] = 3,
    ACTIONS(441), 1,
      anon_sym_RBRACE,
    ACTIONS(443), 1,
      anon_sym_COMMA,
    STATE(130), 1,
      aux_sym_map_expr_repeat1,
  [4021] = 3,
    ACTIONS(445), 1,
      anon_sym_COMMA,
    ACTIONS(448), 1,
      anon_sym_RBRACK,
    STATE(136), 1,
      aux_sym_list_expr_repeat1,
  [4031] = 2,
    ACTIONS(450), 1,
      sym_newline,
    ACTIONS(452), 2,
      anon_sym_elif,
      anon_sym_else,
  [4039] = 3,
    ACTIONS(313), 1,
      anon_sym_COMMA,
    ACTIONS(454), 1,
      anon_sym_RPAREN,
    STATE(132), 1,
      aux_sym_argument_list_repeat1,
  [4049] = 3,
    ACTIONS(417), 1,
      anon_sym_COMMA,
    ACTIONS(456), 1,
      anon_sym_RBRACK,
    STATE(136), 1,
      aux_sym_list_expr_repeat1,
  [4059] = 3,
    ACTIONS(443), 1,
      anon_sym_COMMA,
    ACTIONS(458), 1,
      anon_sym_RBRACE,
    STATE(135), 1,
      aux_sym_map_expr_repeat1,
  [4069] = 3,
    ACTIONS(443), 1,
      anon_sym_COMMA,
    ACTIONS(460), 1,
      anon_sym_RBRACE,
    STATE(142), 1,
      aux_sym_map_expr_repeat1,
  [4079] = 3,
    ACTIONS(443), 1,
      anon_sym_COMMA,
    ACTIONS(462), 1,
      anon_sym_RBRACE,
    STATE(130), 1,
      aux_sym_map_expr_repeat1,
  [4089] = 3,
    ACTIONS(417), 1,
      anon_sym_COMMA,
    ACTIONS(464), 1,
      anon_sym_RBRACK,
    STATE(139), 1,
      aux_sym_list_expr_repeat1,
  [4099] = 1,
    ACTIONS(425), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [4104] = 2,
    ACTIONS(319), 1,
      anon_sym_LBRACE,
    STATE(152), 1,
      sym_block_stmts,
  [4111] = 1,
    ACTIONS(448), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4116] = 2,
    ACTIONS(319), 1,
      anon_sym_LBRACE,
    STATE(154), 1,
      sym_block_stmts,
  [4123] = 1,
    ACTIONS(466), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [4128] = 1,
    ACTIONS(468), 1,
      anon_sym_in,
  [4132] = 1,
    ACTIONS(470), 1,
      ts_builtin_sym_end,
  [4136] = 1,
    ACTIONS(472), 1,
      sym_newline,
  [4140] = 1,
    ACTIONS(474), 1,
      sym_newline,
  [4144] = 1,
    ACTIONS(476), 1,
      sym_newline,
  [4148] = 1,
    ACTIONS(478), 1,
      sym_newline,
  [4152] = 1,
    ACTIONS(480), 1,
      sym_newline,
  [4156] = 1,
    ACTIONS(482), 1,
      sym_identifier,
  [4160] = 1,
    ACTIONS(484), 1,
      sym_newline,
  [4164] = 1,
    ACTIONS(486), 1,
      sym_newline,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 81,
  [SMALL_STATE(4)] = 162,
  [SMALL_STATE(5)] = 243,
  [SMALL_STATE(6)] = 324,
  [SMALL_STATE(7)] = 405,
  [SMALL_STATE(8)] = 461,
  [SMALL_STATE(9)] = 517,
  [SMALL_STATE(10)] = 570,
  [SMALL_STATE(11)] = 623,
  [SMALL_STATE(12)] = 676,
  [SMALL_STATE(13)] = 726,
  [SMALL_STATE(14)] = 776,
  [SMALL_STATE(15)] = 826,
  [SMALL_STATE(16)] = 876,
  [SMALL_STATE(17)] = 926,
  [SMALL_STATE(18)] = 976,
  [SMALL_STATE(19)] = 1026,
  [SMALL_STATE(20)] = 1076,
  [SMALL_STATE(21)] = 1126,
  [SMALL_STATE(22)] = 1176,
  [SMALL_STATE(23)] = 1226,
  [SMALL_STATE(24)] = 1276,
  [SMALL_STATE(25)] = 1326,
  [SMALL_STATE(26)] = 1376,
  [SMALL_STATE(27)] = 1426,
  [SMALL_STATE(28)] = 1476,
  [SMALL_STATE(29)] = 1526,
  [SMALL_STATE(30)] = 1576,
  [SMALL_STATE(31)] = 1626,
  [SMALL_STATE(32)] = 1676,
  [SMALL_STATE(33)] = 1726,
  [SMALL_STATE(34)] = 1776,
  [SMALL_STATE(35)] = 1809,
  [SMALL_STATE(36)] = 1838,
  [SMALL_STATE(37)] = 1865,
  [SMALL_STATE(38)] = 1892,
  [SMALL_STATE(39)] = 1921,
  [SMALL_STATE(40)] = 1948,
  [SMALL_STATE(41)] = 1977,
  [SMALL_STATE(42)] = 2001,
  [SMALL_STATE(43)] = 2025,
  [SMALL_STATE(44)] = 2053,
  [SMALL_STATE(45)] = 2087,
  [SMALL_STATE(46)] = 2119,
  [SMALL_STATE(47)] = 2143,
  [SMALL_STATE(48)] = 2167,
  [SMALL_STATE(49)] = 2191,
  [SMALL_STATE(50)] = 2215,
  [SMALL_STATE(51)] = 2239,
  [SMALL_STATE(52)] = 2265,
  [SMALL_STATE(53)] = 2289,
  [SMALL_STATE(54)] = 2313,
  [SMALL_STATE(55)] = 2337,
  [SMALL_STATE(56)] = 2361,
  [SMALL_STATE(57)] = 2385,
  [SMALL_STATE(58)] = 2409,
  [SMALL_STATE(59)] = 2433,
  [SMALL_STATE(60)] = 2463,
  [SMALL_STATE(61)] = 2487,
  [SMALL_STATE(62)] = 2511,
  [SMALL_STATE(63)] = 2535,
  [SMALL_STATE(64)] = 2559,
  [SMALL_STATE(65)] = 2583,
  [SMALL_STATE(66)] = 2607,
  [SMALL_STATE(67)] = 2638,
  [SMALL_STATE(68)] = 2666,
  [SMALL_STATE(69)] = 2706,
  [SMALL_STATE(70)] = 2746,
  [SMALL_STATE(71)] = 2783,
  [SMALL_STATE(72)] = 2820,
  [SMALL_STATE(73)] = 2857,
  [SMALL_STATE(74)] = 2891,
  [SMALL_STATE(75)] = 2923,
  [SMALL_STATE(76)] = 2957,
  [SMALL_STATE(77)] = 2989,
  [SMALL_STATE(78)] = 3023,
  [SMALL_STATE(79)] = 3042,
  [SMALL_STATE(80)] = 3061,
  [SMALL_STATE(81)] = 3092,
  [SMALL_STATE(82)] = 3123,
  [SMALL_STATE(83)] = 3142,
  [SMALL_STATE(84)] = 3171,
  [SMALL_STATE(85)] = 3190,
  [SMALL_STATE(86)] = 3215,
  [SMALL_STATE(87)] = 3234,
  [SMALL_STATE(88)] = 3253,
  [SMALL_STATE(89)] = 3280,
  [SMALL_STATE(90)] = 3299,
  [SMALL_STATE(91)] = 3318,
  [SMALL_STATE(92)] = 3349,
  [SMALL_STATE(93)] = 3368,
  [SMALL_STATE(94)] = 3389,
  [SMALL_STATE(95)] = 3408,
  [SMALL_STATE(96)] = 3437,
  [SMALL_STATE(97)] = 3456,
  [SMALL_STATE(98)] = 3475,
  [SMALL_STATE(99)] = 3494,
  [SMALL_STATE(100)] = 3513,
  [SMALL_STATE(101)] = 3544,
  [SMALL_STATE(102)] = 3563,
  [SMALL_STATE(103)] = 3592,
  [SMALL_STATE(104)] = 3611,
  [SMALL_STATE(105)] = 3630,
  [SMALL_STATE(106)] = 3649,
  [SMALL_STATE(107)] = 3668,
  [SMALL_STATE(108)] = 3699,
  [SMALL_STATE(109)] = 3722,
  [SMALL_STATE(110)] = 3741,
  [SMALL_STATE(111)] = 3752,
  [SMALL_STATE(112)] = 3765,
  [SMALL_STATE(113)] = 3776,
  [SMALL_STATE(114)] = 3787,
  [SMALL_STATE(115)] = 3798,
  [SMALL_STATE(116)] = 3809,
  [SMALL_STATE(117)] = 3820,
  [SMALL_STATE(118)] = 3831,
  [SMALL_STATE(119)] = 3842,
  [SMALL_STATE(120)] = 3853,
  [SMALL_STATE(121)] = 3864,
  [SMALL_STATE(122)] = 3877,
  [SMALL_STATE(123)] = 3888,
  [SMALL_STATE(124)] = 3899,
  [SMALL_STATE(125)] = 3910,
  [SMALL_STATE(126)] = 3923,
  [SMALL_STATE(127)] = 3934,
  [SMALL_STATE(128)] = 3945,
  [SMALL_STATE(129)] = 3955,
  [SMALL_STATE(130)] = 3963,
  [SMALL_STATE(131)] = 3973,
  [SMALL_STATE(132)] = 3981,
  [SMALL_STATE(133)] = 3991,
  [SMALL_STATE(134)] = 4001,
  [SMALL_STATE(135)] = 4011,
  [SMALL_STATE(136)] = 4021,
  [SMALL_STATE(137)] = 4031,
  [SMALL_STATE(138)] = 4039,
  [SMALL_STATE(139)] = 4049,
  [SMALL_STATE(140)] = 4059,
  [SMALL_STATE(141)] = 4069,
  [SMALL_STATE(142)] = 4079,
  [SMALL_STATE(143)] = 4089,
  [SMALL_STATE(144)] = 4099,
  [SMALL_STATE(145)] = 4104,
  [SMALL_STATE(146)] = 4111,
  [SMALL_STATE(147)] = 4116,
  [SMALL_STATE(148)] = 4123,
  [SMALL_STATE(149)] = 4128,
  [SMALL_STATE(150)] = 4132,
  [SMALL_STATE(151)] = 4136,
  [SMALL_STATE(152)] = 4140,
  [SMALL_STATE(153)] = 4144,
  [SMALL_STATE(154)] = 4148,
  [SMALL_STATE(155)] = 4152,
  [SMALL_STATE(156)] = 4156,
  [SMALL_STATE(157)] = 4160,
  [SMALL_STATE(158)] = 4164,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(156),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(151),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(19),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(156),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(158),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(157),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(66),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(32),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(68),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(90),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(95),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(118),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(117),
  [84] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(116),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(109),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(155),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expr, 1),
  [173] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expr, 1),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_statement, 2),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_statement, 2),
  [185] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inline_statement_repeat1, 2), SHIFT_REPEAT(36),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_inline_statement_repeat1, 2),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_inline_statement_repeat1, 2),
  [194] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inline_statement_repeat1, 2), SHIFT_REPEAT(38),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_statement, 3),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_statement, 3),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiline_string_lit, 3),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multiline_string_lit, 3),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_expr, 4),
  [211] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_map_expr, 4),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expr, 3, .production_id = 3),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expr, 3, .production_id = 3),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_lit, 2),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_string_lit, 2),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiline_string_lit, 2),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multiline_string_lit, 2),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_expr, 2),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_expr, 2),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expr, 2, .production_id = 1),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_expr, 2, .production_id = 1),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_expr, 2),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_map_expr, 2),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_string_lit, 3),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_string_lit, 3),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 4),
  [255] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 4),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_expr, 3),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_expr, 3),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_expr, 4),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_list_expr, 4),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_lit, 1),
  [267] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_lit, 1),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bool_lit, 1),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bool_lit, 1),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_nil_lit, 1),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_nil_lit, 1),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 3),
  [279] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 3),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paren_expr, 3),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paren_expr, 3),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_expr, 3),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_map_expr, 3),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_index_expr, 4),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_index_expr, 4),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2),
  [295] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 2),
  [297] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [299] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [301] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [303] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_map_elem, 3),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [329] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [331] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [333] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [335] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [337] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expr_stmt, 1),
  [343] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assign_stmt, 3),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [351] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_multiline_string_lit_repeat1, 2),
  [353] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_multiline_string_lit_repeat1, 2), SHIFT_REPEAT(110),
  [356] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 4, .production_id = 2),
  [358] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [360] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [362] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [368] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [372] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [374] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [380] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [384] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_stmt_repeat1, 2),
  [392] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 2), SHIFT_REPEAT(18),
  [395] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 2),
  [397] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [401] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 3, .production_id = 2),
  [405] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [407] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quoted_string_lit_repeat1, 2),
  [409] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_lit_repeat1, 2), SHIFT_REPEAT(126),
  [412] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quoted_string_lit_repeat2, 2),
  [414] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quoted_string_lit_repeat2, 2), SHIFT_REPEAT(127),
  [417] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [421] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_if_stmt_repeat1, 3),
  [423] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_if_stmt_repeat1, 3),
  [425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_map_expr_repeat1, 2),
  [427] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_map_expr_repeat1, 2), SHIFT_REPEAT(11),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_stmts, 2),
  [432] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_stmts, 2),
  [434] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(12),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [445] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_list_expr_repeat1, 2), SHIFT_REPEAT(70),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_list_expr_repeat1, 2),
  [450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_stmts, 3),
  [452] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_stmts, 3),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list_elem, 1),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [470] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [474] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 5, .production_id = 2),
  [476] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_in_stmt, 5),
  [478] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_stmt, 6, .production_id = 2),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [484] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_break_stmt, 1),
  [486] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_continue_stmt, 1),
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
