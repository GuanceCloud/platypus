// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

%{
package parser

import (
	ast "github.com/GuanceCloud/platypus/pkg/v2/ast"
)

%}

%union {
	aststmts   ast.Stmts
	astblock   *ast.BlockStmt

	classbody  any
	fnparams  any

	ifitem     *ast.IfStmtElem
	iflist	   []*ast.IfStmtElem
	node       ast.Node
	nodes      []ast.Node
	map_nodes [][2]ast.Node
	item       Item

}

%token <item> SEMICOLON COMMA COMMENT EOF ERROR ID NUMBER 
	LEFT_PAREN LEFT_BRACKET LEFT_BRACE RIGHT_BRACE
	RIGHT_PAREN RIGHT_BRACKET STRING QUOTED_STRING MULTILINE_STRING
	COLON EOL

// operator
%token operatorsStart
%token <item> 
	ADD SUB MUL DIV MOD
	EQ
	GTE GT LT LTE NEQ  EQEQ 
	ADD_EQ SUB_EQ DIV_EQ MUL_EQ MOD_EQ
	AND OR NOT
	DOT
%token operatorsEnd

// keywords
%token keywordsStart
%token <item>
TRUE FALSE CLASS
NIL NULL IF ELIF ELSE 
STR INT FLOAT BOOL LIST MAP ANY
FOR IN WHILE BREAK CONTINUE	RETURN SWITCH CASE GOTO
FN LET VAR VAR_ARG FN_RET IMPORT AS TYPE
NEW MAKE INTERFACE CONST
%token keywordsEnd

// start symbols for parser
%token startSymbolsStart
%token START_STMTS
%token startSymbolsEnd

////////////////////////////////////////////////////
// grammar rules
////////////////////////////////////////////////////
/* %type <item>
	unary_op */


%type<astblock>
	stmt_block
	empty_block


%type<aststmts>
	stmts
	stmts_list

%type<ifitem>
	if_elem
	elif_elem

%type<iflist>
	if_elif_list

%type<nodes>
	function_args
	exprs

%type<map_nodes>
	expr_colon_expr

%type <node>
	stmt
	assignment_stmt
	for_in_stmt
	for_stmt
	continue_stmt
	break_stmt
	ifelse_stmt
	call_expr
	named_arg

%type <node>
	identifier
	unary_expr
	conditional_expr
	arithmeticExpr
	paren_expr
	index_expr
	attr_expr
	in_expr
	expr
	map_literal
	value_stmt
	expr_or_empty
	typed_literal
	list_literal
	basic_literal
	for_init_elem
	slice_expr
	data_type
	fn_type
	list_type
	map_type
	var_def_stmt
	method_def_stmt
	fn_def_stmt
	import_stmt
	type_def_stmt
	return_stmt
	//columnref

%type <classbody>
	

%type <fnparams>
	fn_def_params
	fn_def_param

%start start

// operator listed with increasing precedence
%right EQ SUB_EQ ADD_EQ MUL_EQ DIV_EQ MOD_EQ
%left OR
%left AND
%left IN
%left GTE GT NEQ EQEQ LTE LT
%left ADD SUB
%left MUL DIV MOD
%right NOT UMINUS
%left LEFT_PAREN RIGHT_PAREN DOT LEFT_BRACKET RIGHT_BRACKET
%%


sep: SEMICOLON
| EOL
| sep SEMICOLON
| sep EOL
;

start: START_STMTS stmts
{
	yylex.(*parser).parseResult = $2
}
| START_STMTS
{
	yylex.(*parser).parseResult = ast.Stmts{}
}
| start EOF
| error
{
	yylex.(*parser).unexpected("", "")
}
;

/*
stmts and exprs
*/

stmts: stmts_list stmt
{
	s := $1
	s = append(s, $2)
	$$ = s
}
| stmts_list
| stmt
{
	$$ = ast.Stmts{$1}
}
;

stmts_list: stmt sep
{
	$$ = ast.Stmts{$1}
}
| sep
{
	$$ = ast.Stmts{}
}
| stmts_list stmt sep
{
	s := $1
	s = append(s, $2)
	$$ = s
}
;

stmt: ifelse_stmt
| for_in_stmt
| for_stmt
| continue_stmt
| break_stmt
| value_stmt
| var_def_stmt
| fn_def_stmt
| method_def_stmt
| import_stmt
| type_def_stmt
| return_stmt
;


value_stmt: expr
{
	$$ = nil
}
;

/* expression */
expr: identifier
| basic_literal 
| list_literal 
| map_literal
| typed_literal
| paren_expr
| unary_expr
| conditional_expr
| arithmeticExpr
| attr_expr
| index_expr
| slice_expr
| in_expr
| call_expr
;


/*
type
*/

data_type: INT
{
	$$ =nil
}
| FLOAT
{
	$$ =nil
}
| STRING
{
	$$ =nil
}
| BOOL
{
	$$ =nil
}
| ANY 
{
	$$ =nil
}
| list_type
| map_type
| fn_type
| identifier
;


list_type: LEFT_BRACKET RIGHT_BRACKET data_type 
{
	$$ =nil
}
;

map_type: MAP LEFT_BRACKET data_type RIGHT_BRACKET data_type
{
	$$ =nil
}
;

var_def_stmt: LET identifier data_type EQ expr
{
	$$ =nil
}
| LET identifier data_type
{
	$$ =nil
}
| LET identifier EQ expr
{
	$$ =nil
}
;


fn_type: FN LEFT_PAREN  RIGHT_PAREN LEFT_BRACE RIGHT_BRACE
{
	$$=nil
}
| FN  LEFT_PAREN  RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET data_type
{
	$$ =nil
}
| FN LEFT_PAREN  RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET LEFT_PAREN fn_ret_types_multi RIGHT_PAREN 
{
	$$ =nil
}
| FN LEFT_PAREN fn_def_params RIGHT_PAREN LEFT_BRACE RIGHT_BRACE
{
	$$ =nil
}
| FN LEFT_PAREN fn_def_params RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET data_type
{
	$$ =nil
}
| FN LEFT_PAREN fn_def_params RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET LEFT_PAREN fn_ret_types_multi RIGHT_PAREN
{
	$$ =nil
}
;

/*
stmt
*/


import_stmt: IMPORT STRING
{
	$$ = nil
}
| IMPORT STRING AS identifier
{
	$$ = nil
}
;


type_def_stmt: TYPE identifier data_type
{
	$$ = nil
}
;


fn_def_param: identifier
{
	$$ = nil
}
| identifier COLON data_type
{
	$$ = nil
}
| identifier COLON VAR_ARG data_type
{
	$$ = nil
}
// | identifier EQ expr
// {
// 	$$ = nil
// }
// | identifier COLON data_type EQ expr
// {
// 	$$ = nil
// }
// | identifier COLON VAR_ARG data_type EQ expr
// {
// 	$$ = nil
// }
;


return_stmt: RETURN
{
	$$ = nil
}
| RETURN exprs 
{
	$$ = nil
}
;


fn_def_params: fn_def_param
| fn_def_params COMMA fn_def_param
;


fn_ret_types_multi: data_type
| fn_ret_types_multi COMMA data_type
;


method_def_stmt: FN LEFT_BRACE identifier identifier RIGHT_BRACE identifier  LEFT_PAREN  RIGHT_PAREN LEFT_BRACE RIGHT_BRACE stmt_block
{
	$$=nil
}
| FN LEFT_BRACE identifier identifier RIGHT_BRACE identifier  LEFT_PAREN  RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET data_type stmt_block
{
	$$=nil
}
| FN LEFT_BRACE identifier identifier RIGHT_BRACE identifier  LEFT_PAREN  RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET LEFT_PAREN fn_ret_types_multi RIGHT_PAREN stmt_block
{
	$$=nil
}
| FN LEFT_BRACE identifier identifier RIGHT_BRACE identifier  LEFT_PAREN fn_def_params RIGHT_PAREN LEFT_BRACE RIGHT_BRACE stmt_block
{
	$$=nil
}
| FN LEFT_BRACE identifier identifier RIGHT_BRACE identifier  LEFT_PAREN fn_def_params RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET data_type stmt_block
{
	$$=nil
}
| FN LEFT_BRACE identifier identifier RIGHT_BRACE identifier  LEFT_PAREN fn_def_params RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET LEFT_PAREN fn_ret_types_multi RIGHT_PAREN stmt_block
{
	$$=nil
}
;



fn_def_stmt: FN identifier LEFT_PAREN  RIGHT_PAREN LEFT_BRACE RIGHT_BRACE stmt_block
{
	$$=nil
}
| FN identifier LEFT_PAREN  RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET data_type stmt_block
{
	$$ =nil
}
| FN identifier LEFT_PAREN  RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET LEFT_PAREN fn_ret_types_multi RIGHT_PAREN  stmt_block
{
	$$ =nil
}
| FN identifier LEFT_PAREN fn_def_params RIGHT_PAREN LEFT_BRACE RIGHT_BRACE stmt_block
{
	$$ =nil
}
| FN identifier LEFT_PAREN fn_def_params RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET data_type stmt_block
{
	$$ =nil
}
| FN identifier LEFT_PAREN fn_def_params RIGHT_PAREN LEFT_BRACE RIGHT_BRACE FN_RET LEFT_PAREN fn_ret_types_multi RIGHT_PAREN stmt_block
{
	$$ =nil
}
;

exprs: expr
{
	$$ = []ast.Node{$1}
}
| exprs COMMA expr
{
	$$ = append($1, $3)
}
;


assignment_stmt: exprs EQ exprs
{
	$$ = yylex.(*parser).newAssignmentStmt(
		$1, $3, $2)
}
| expr ADD_EQ expr
{
	$$ = yylex.(*parser).newAssignmentStmt(
		[]ast.Node{$1}, []ast.Node{$3}, $2)
}
| expr SUB_EQ expr
{
	$$ = yylex.(*parser).newAssignmentStmt(
		[]ast.Node{$1}, []ast.Node{$3}, $2)
}
| expr MUL_EQ expr
{
	$$ = yylex.(*parser).newAssignmentStmt(
		[]ast.Node{$1}, []ast.Node{$3}, $2)
}
| expr DIV_EQ expr
{
	$$ = yylex.(*parser).newAssignmentStmt(
		[]ast.Node{$1}, []ast.Node{$3}, $2)
}
| expr MOD_EQ expr
{
	$$ = yylex.(*parser).newAssignmentStmt(
		[]ast.Node{$1}, []ast.Node{$3}, $2)
}
;


in_expr: expr IN expr
{
	$$ = yylex.(*parser).newInExpr($1, $3, $2)
}
;


break_stmt: BREAK
{
	$$ = yylex.(*parser).newBreakStmt($1.Pos)
}
;


continue_stmt: CONTINUE
{
	$$ = yylex.(*parser).newContinueStmt($1.Pos)
}
;

/*
	for identifier IN identifier
	for identifier IN list_init
	for identifier IN string
*/
for_in_stmt : FOR in_expr stmt_block
{
	$$ = yylex.(*parser).newForInStmt($1, $2, $3)
}
;


/*
	for init ; cond expr; loop { stmts }
	for init ; cond expr; 	   { stmts }
	for 	 ; cond expr; loop { stmts }
	for 	 ; cond expr;      { stmts }
*/

for_init_elem: expr | assignment_stmt | var_def_stmt
;

for_stmt : FOR for_init_elem SEMICOLON expr SEMICOLON expr stmt_block
{
	$$ = yylex.(*parser).newForStmt($1, $2, $4, $6, $7)
}
| FOR for_init_elem SEMICOLON expr SEMICOLON stmt_block
{
	$$ = yylex.(*parser).newForStmt($1, $2, $4, nil, $6)
}
| FOR for_init_elem SEMICOLON SEMICOLON expr stmt_block
{
	$$ = yylex.(*parser).newForStmt($1, $2, nil, $5, $6)
}
| FOR for_init_elem SEMICOLON SEMICOLON stmt_block
{
	$$ = yylex.(*parser).newForStmt($1, $2, nil, nil, $5)
}
| FOR SEMICOLON expr SEMICOLON expr stmt_block
{
	$$ = yylex.(*parser).newForStmt($1, $3, nil, $5, $6)
}
| FOR SEMICOLON expr SEMICOLON stmt_block
{
	$$ = yylex.(*parser).newForStmt($1, $3, nil, nil, $5)
}
| FOR SEMICOLON SEMICOLON expr stmt_block
{
	$$ = yylex.(*parser).newForStmt($1, nil, nil, $4, $5)
}
| FOR SEMICOLON SEMICOLON stmt_block
{
	$$ = yylex.(*parser).newForStmt($1, nil, nil, nil, $4)
}
;


ifelse_stmt: if_elif_list
{
	$$ = yylex.(*parser).newIfElifStmt($1)
}
| if_elif_list ELSE stmt_block
{
	$$ = yylex.(*parser).newIfElifelseStmt($1, $2, $3)
}
;

if_elem: IF expr stmt_block
{
	$$ = yylex.(*parser).newIfElem($1, $2, $3)
} 
;

if_elif_list: if_elem
{
	$$ = []*ast.IfStmtElem{$1}
}
| if_elif_list elif_elem
{
	$$ = append($1, $2)
}
;

elif_elem: ELIF expr stmt_block
{
	$$ = yylex.(*parser).newIfElem($1, $2, $3)
}
;


stmt_block: empty_block
| LEFT_BRACE stmts RIGHT_BRACE
{
	$$ = yylex.(*parser).newBlockStmt($1, $3, $2)
}
;


empty_block : LEFT_BRACE RIGHT_BRACE
{
	$$ = yylex.(*parser).newBlockStmt($1, $2, nil)
}
;


/*
expr
*/

function_args: function_args COMMA expr
{
	$$ = append($$, $3)
}
| function_args COMMA named_arg
{
	$$ = append($$, $3)
}
| named_arg
{
	$$ = []ast.Node{$1}
}
| expr
{
	$$ = []ast.Node{$1}
}
;

named_arg: identifier EQ expr
{
	$$ = yylex.(*parser).newAssignmentStmt([]ast.Node{$1}, []ast.Node{$3},  $2)
}
;


call_expr: expr LEFT_PAREN function_args RIGHT_PAREN
{
	$$ = yylex.(*parser).newCallExpr($2, $4, $1, $3)
}
| expr LEFT_PAREN function_args COMMA RIGHT_PAREN
{
	$$ = yylex.(*parser).newCallExpr($2, $5, $1, $3)
}
| expr LEFT_PAREN RIGHT_PAREN
{
	$$ = yylex.(*parser).newCallExpr($2, $3, $1, nil)
}
;

unary_expr: ADD expr %prec UMINUS 
{
	$$ = yylex.(*parser).newUnaryExpr($1, $2)
}
| SUB expr %prec UMINUS 
{
	$$ = yylex.(*parser).newUnaryExpr($1, $2)
}
| NOT expr
{
	$$ = yylex.(*parser).newUnaryExpr($1, $2)
}
;

conditional_expr: expr GTE expr
{
	$$ = yylex.(*parser).newConditionalExpr($1, $3, $2)
}
| expr GT expr
{
	$$ = yylex.(*parser).newConditionalExpr($1, $3, $2)
}
| expr OR expr
{
	$$ = yylex.(*parser).newConditionalExpr($1, $3, $2)
}
| expr AND expr
{
	$$ = yylex.(*parser).newConditionalExpr($1, $3, $2)
}
| expr LT expr
{
	$$ = yylex.(*parser).newConditionalExpr($1, $3, $2)
}
| expr LTE expr
{
	$$ = yylex.(*parser).newConditionalExpr($1, $3, $2)
}
| expr NEQ expr
{
	$$ = yylex.(*parser).newConditionalExpr($1, $3, $2)
}
| expr EQEQ expr
{
	$$ = yylex.(*parser).newConditionalExpr($1, $3, $2)
}
;


arithmeticExpr: expr ADD expr
{
	$$ = yylex.(*parser).newArithmeticExpr($1, $3, $2)
}
| expr SUB expr
{
	$$ = yylex.(*parser).newArithmeticExpr($1, $3, $2)
}
| expr MUL expr
{
	$$ = yylex.(*parser).newArithmeticExpr($1, $3, $2)
}
| expr DIV expr
{
	$$ = yylex.(*parser).newArithmeticExpr($1, $3, $2)
}
| expr MOD expr
{
	$$ = yylex.(*parser).newArithmeticExpr($1, $3, $2)
}
;


paren_expr: LEFT_PAREN expr RIGHT_PAREN
{
	$$ = yylex.(*parser).newParenExpr($1, $3, $2)
}
;


index_expr: expr LEFT_BRACKET expr RIGHT_BRACKET
{
	$$ = yylex.(*parser).newIndexExpr($2, $4, $1, $3)
} 
| DOT LEFT_BRACKET expr RIGHT_BRACKET	// 特殊处理，兼容旧版
{
	$$ = yylex.(*parser).newIndexExpr($2, $4, nil, $3, $1)
}
;


attr_expr: expr DOT expr
{ 
	$$ = yylex.(*parser).newAttrExpr($1, $3)
}
;


expr_or_empty: expr
{
	$$ = $1
}
| 
{
	$$ = nil
}
;


slice_expr: expr LEFT_BRACKET expr_or_empty COLON expr_or_empty COLON expr_or_empty RIGHT_BRACKET
{
	$$ = yylex.(*parser).newSliceExpr($2, $8, $1, $3, $5, $7)
}
| expr LEFT_BRACKET expr_or_empty COLON expr_or_empty RIGHT_BRACKET
{
	$$ = yylex.(*parser).newSliceExpr($2, $6, $1, $3, $5, nil)
}
;


typed_literal: identifier LEFT_BRACE expr_colon_expr RIGHT_BRACE
{
	$$ = nil
}
| identifier LEFT_BRACE RIGHT_BRACE
{
	$$ = nil
}
| list_type LEFT_BRACE exprs RIGHT_BRACE
{ 
	$$ = nil
}
| list_type LEFT_BRACE RIGHT_BRACE
{ 
	$$ = nil
}
| map_type LEFT_BRACE expr_colon_expr RIGHT_BRACE
{
	$$ = nil
}
| map_type LEFT_BRACE RIGHT_BRACE
{
	$$ = nil
}
;

list_literal : LEFT_BRACKET exprs RIGHT_BRACKET
{ 
	$$ = yylex.(*parser).newListLiteral($1, $3, $2)
}
| LEFT_BRACKET RIGHT_BRACKET
{ 
	$$ = yylex.(*parser).newListLiteral($1, $2, nil)}
;


expr_colon_expr: expr COLON expr
{
	$$ = [][2]ast.Node{[2]ast.Node{$1, $2}}
}
| expr_colon_expr COMMA expr COLON expr
{
	$$ = append($$, [2]ast.Node{$3, $5})
}
;

map_literal : LEFT_BRACE RIGHT_BRACE
{
	$$ = yylex.(*parser).newMapLiteral($1, $2, nil)
}
|  LEFT_BRACE expr_colon_expr RIGHT_BRACE
{
	$$ = yylex.(*parser).newMapLiteral($1, $3, $2)
}
;


identifier: ID
{
	$$ = yylex.(*parser).newIdentifierLiteral($1)
}
| QUOTED_STRING
{
	$1.Val = yylex.(*parser).unquoteString($1.Val) 
	$$ = yylex.(*parser).newIdentifierLiteral($1)
}
;

basic_literal: NUMBER
{
	$$ =  yylex.(*parser).newNumberLiteral($1)
}
| TRUE
{
	$$ = yylex.(*parser).newBoolLiteral($1.Pos, true)
}
| FALSE
{
	$$ =  yylex.(*parser).newBoolLiteral($1.Pos, false)
}
| STRING
{ 
	$1.Val = yylex.(*parser).unquoteString($1.Val)
	$$ = yylex.(*parser).newStringLiteral($1)
}
| MULTILINE_STRING
{
	$1.Val = yylex.(*parser).unquoteMultilineString($1.Val)
	$$ = yylex.(*parser).newStringLiteral($1)
}
| NIL
{ 
	$$ = yylex.(*parser).newNilLiteral($1.Pos)
}
| NULL
{
	$$ = yylex.(*parser).newNilLiteral($1.Pos)
}
;

%%
