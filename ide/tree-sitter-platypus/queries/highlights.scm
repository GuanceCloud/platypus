; Keywords
[
  "if"
  "elif"
  "else"
  ; "identifier" ; TODO: why is this here?
  "for"
  "in"
  ; "while" ; TODO: why is this here?
  "break"
  "continue"
  "fn"
  "return"
] @keyword

; Function calls
((identifier) @function.method.builtin
 (#eq? @function.method.builtin "use"))

(call_expr name: (identifier) @function.method)
(function_decl_stmt name: (identifier) @function)

; Identifiers
(identifier) @variable

; Literals
(string_lit) @string
(number_lit) @number
(escape_sequence) @escape

[
  (nil_lit)
  (bool_lit)
] @constant.builtin

(comment) @comment

; Operators

[
  "+"
  "-"
  "*"
  "/"
  "%"
  "||"
  "&&"
  "=="
  "!="
  ">"
  ">="
  "<="
  "<"
] @operator

[
  ","
] @punctuation.delimiter

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @punctuation.bracket
