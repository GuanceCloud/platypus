const PREC = {
  DEFAULT: 0,

  EQ: 1,
  OR: 2,
  AND: 3,
  RELATIONAL: 4,
  ADD: 5,
  MULTIPLY: 6,
  UNARY: 7,

  CALL: 10,
  INDEX: 11,
}

module.exports = grammar({
  name: 'ppl',

  rules: {
    // TODO: error?
    // See: https://github.com/GuanceCloud/ppl/blob/main/pkg/parser/gram.y#LL131C9-L131C9
    source_file: $ => repeat($._stmt),

    // Statements
    _stmt: $ => choice(
      $.comment,
      $.if_stmt,
      $.for_in_stmt,
      $.continue_stmt,
      $.break_stmt,
      $.expr_stmt,

      // TODO: why it is expr
      $.assign_stmt,
    ),

    comment: $ => token(prec(-10, /#.*/)),

    if_stmt: $ => prec.right(seq(
      'if',
      field('condition', $._expr), // TODO: expr or condition expr
      field('consequence', $.block_stmts),
      repeat(seq(
        'elif',
        field('alternative', $.block_stmts)
      )),
      optional(seq(
        'else',
        field('alternative', $.block_stmts)
      ))
    )),

    for_in_stmt: $ => seq(
      'for',
      $.identifier,
      'in',
      $.identifier,
      $.block_stmts,
    ),

    block_stmts: $ => seq(
      '{',
      repeat($._stmt),
      '}',
    ),

    continue_stmt: $ => seq(
      'continue',
    ),

    break_stmt: $ => seq(
      'break',
    ),

    assign_stmt: $ => seq(
      $.identifier,
      '=',
      $._expr,
    ),

    expr_stmt: $ => $._expr,
      
    // Expressions
    _expr: $ => choice(
      $.identifier,
      $._literal,
      $.list_expr,
      $.map_expr,
      $.paren_expr,
      $.call_expr,
      $.binary_expr,
      // $.attr_expr,
      $.index_expr,
    ),
  
    identifier: $ => /[a-zA-Z_]\w*/,

    // Expr: paren
    paren_expr: $ => seq(
      '(',
      $._expr,
      ')',
    ),

    // Expr: call
    call_expr: $ => prec(PREC.CALL, seq(
      field('name', $.identifier),
      $.argument_list,
    )),

    argument_list: $ => seq(
      '(',
      commaSep($._expr),
      ')',
    ),

    // Expr: binary
    binary_expr: $ => {
      const table = [
        [prec.left, '+', PREC.ADD],
        [prec.left, '-', PREC.ADD],
        [prec.left, '*', PREC.MULTIPLY],
        [prec.left, '/', PREC.MULTIPLY],
        [prec.left, '%', PREC.MULTIPLY],
        [prec.left, '||', PREC.OR],
        [prec.left, '&&', PREC.AND],
        [prec.left, '==', PREC.EQ],
        [prec.left, '!=', PREC.EQ],
        [prec.left, '>', PREC.RELATIONAL],
        [prec.left, '>=', PREC.RELATIONAL],
        [prec.left, '<=', PREC.RELATIONAL],
        [prec.left, '<', PREC.RELATIONAL],
      ];

      return choice(...table.map(([fn, operator, precedence]) => fn(precedence, seq(
        field('left', $._expr),
        field('operator', operator),
        field('right', $._expr)
      ))));
    },

    // TODO: only for json function?
    // attr_expr: $ => seq(),

    // Expr: index
    index_expr: $ => prec(PREC.INDEX, seq(
      $.identifier,
      '[',
      $._expr,
      ']',
    )),

    // Expr: condition
    cond_expr: $ => seq(
      $._expr,
      choice(
        '>=',
        '>',
        '||',
        '&&',
        '<',
        '<=',
        '!=',
        '==',
      ),
      $._expr,
    ),

    // Expr: list
    list_expr: $ => seq(
      '[',
      commaSep($.list_elem),
      ']',
    ),

    list_elem: $ => choice(
      $._literal,
      $.identifier,
    ),

    // Expr: map
    map_expr: $ => seq(
      '{',
      commaSep($.map_elem),
      '}',
    ),

    map_elem: $ => seq(
      $._expr,
      ':',
      $._expr,
    ),
  
    // Literals
    _literal: $ => choice(
      $.nil_lit,
      $.number_lit,
      $.string_lit,
      $.bool_lit,
    ),

    // Literal: nil
    nil_lit: $ => choice(
      'nil',
      'null',
    ),

    // Literal: number
    number_lit: $ => {
      const separator = "'";
      const hex = /[0-9a-fA-F]/;
      const decimal = /[0-9]/;
      const hexDigits = seq(repeat1(hex), repeat(seq(separator, repeat1(hex))));
      const decimalDigits = seq(repeat1(decimal), repeat(seq(separator, repeat1(decimal))));
      return token(seq(
        optional(/[-\+]/),
        optional(choice('0x', '0b')),
        choice(
          seq(
            choice(
              decimalDigits,
              seq('0b', decimalDigits),
              seq('0x', hexDigits)
            ),
            optional(seq('.', optional(hexDigits)))
          ),
          seq('.', decimalDigits)
        ),
        optional(seq(
          /[eEpP]/,
          optional(seq(
            optional(/[-\+]/),
            hexDigits
          ))
        )),
        repeat(choice('u', 'l', 'U', 'L', 'f', 'F'))
      ))
    },

    // Literal: string
    string_lit: $ => choice(
      seq('"', '"'),
      seq('"', field('value', $.string_content), '"'),
    ),

    string_lit: $ => choice(
      seq(
        '"',
        repeat(choice(
          token.immediate(prec(1, /[^\\"\n]+/)),
          $.escape_sequence,
        )),
        '"'
      ),
      seq(
        "'",
        repeat(choice(
          token.immediate(prec(1, /[^\\'\n]+/)),
          $.escape_sequence,
        )),
        "'"
      )
    ),

    // Literal: bool
    bool_lit: $ => choice(
      'true',
      'false',
    ),

    escape_sequence: $ => token.immediate(seq(
      '\\',
      /(\"|\\|\/|b|f|n|r|t|u)/
    )),
  }
});

function commaSep (rule) {
  return optional(commaSep1(rule))
}

function commaSep1 (rule) {
  return seq(rule, repeat(seq(',', rule)))
}
