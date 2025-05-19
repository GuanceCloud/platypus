// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.
//
// ====================================================================================
// Copyright 2015 The Prometheus Authors
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package parser

import (
	"errors"
	"fmt"
	"os"
	"runtime"
	"strconv"
	"strings"
	"sync"

	"github.com/GuanceCloud/platypus/internal/logger"
	"github.com/GuanceCloud/platypus/pkg/errchain"
	"github.com/GuanceCloud/platypus/pkg/v2/ast"
	"go.uber.org/zap"

	plToken "github.com/GuanceCloud/platypus/pkg/token"
)

var log logger.Logger = logger.NewStdoutLogger("iploc", zap.DebugLevel)

func InitLog(logger logger.Logger) {
	log = logger
}

var parserPool = sync.Pool{
	New: func() interface{} {
		return &parser{}
	},
}

type parser struct {
	lex      Lexer
	yyParser yyParserImpl

	parseResult ast.Stmts
	lastClosing plToken.Pos
	errs        ParseErrors

	inject    ItemType
	injecting bool

	posCache plToken.PosCache
}

func (p *parser) InjectItem(typ ItemType) {
	if p.injecting {
		log.Warnf("current inject is %v, new inject is %v", p.inject, typ)
		panic("cannot inject multiple Items into the token stream")
	}

	if typ != 0 && (typ <= startSymbolsStart || typ >= startSymbolsEnd) {
		log.Warnf("current inject is %v", typ)
		panic("cannot inject symbol that isn't start symbol")
	}
	p.inject = typ
	p.injecting = true
}

var errUnexpected = errors.New("unexpected error")

func (p *parser) unexpected(context string, expected string) {
	var errMsg strings.Builder

	if p.yyParser.lval.item.Typ == ERROR { // do not report lex error twice
		return
	}

	errMsg.WriteString("unexpected: ")
	errMsg.WriteString(p.yyParser.lval.item.desc())

	if context != "" {
		errMsg.WriteString(" in: ")
		errMsg.WriteString(context)
	}

	if expected != "" {
		errMsg.WriteString(", expected: ")
		errMsg.WriteString(expected)
	}

	p.addParseErr(p.yyParser.lval.item.PositionRange(), errors.New(errMsg.String()))
}

func (p *parser) recover(errp *error) {
	e := recover() //nolint: ifshort
	if _, ok := e.(runtime.Error); ok {
		buf := make([]byte, 64<<10) // 64k
		buf = buf[:runtime.Stack(buf, false)]
		fmt.Fprintf(os.Stderr, "parser panic: %v\n%s", e, buf)
		*errp = errUnexpected
	} else if e != nil {
		if x, ok := e.(error); ok {
			*errp = x
		}
	}
}

func (p *parser) addParseErr(pr *PositionRange, err error) {
	p.errs = append(p.errs, ParseError{
		Pos:   pr,
		Err:   err,
		Query: p.lex.input,
	})
}

func (p *parser) addParseErrf(pr *PositionRange, format string, args ...interface{}) {
	p.addParseErr(pr, fmt.Errorf(format, args...))
}

func (p *parser) pos(item Item) plToken.LnColPos {
	return p.posCache.LnCol(item.Pos)
}

func (p *parser) unquoteString(s string) string {
	unq, err := Unquote(s)
	if err != nil {
		p.addParseErrf(p.yyParser.lval.item.PositionRange(),
			"error unquoting string %q: %s", s, err)
		return ""
	}
	return unq
}

func (p *parser) unquoteMultilineString(s string) string {
	unq, err := UnquoteMultiline(s)
	if err != nil {
		p.addParseErrf(p.yyParser.lval.item.PositionRange(),
			"error unquoting multiline string %q: %s", s, err)
		return ""
	}
	return unq
}

// literal

func (p *parser) newBoolLiteral(pos plToken.Pos, val bool) ast.Node {
	return &ast.BoolLiteral{
		Val:   val,
		Start: p.posCache.LnCol(pos),
	}
}

func (p *parser) newNilLiteral(pos plToken.Pos) ast.Node {
	return &ast.NilLiteral{
		Start: p.posCache.LnCol(pos),
	}
}

func (p *parser) newIdentifierLiteral(name Item) ast.Node {
	return &ast.Identifier{
		Name:  name.Val,
		Start: p.posCache.LnCol(name.Pos),
	}
}

func (p *parser) newStringLiteral(val Item) ast.Node {
	return &ast.StringLiteral{
		Val:   val.Val,
		Start: p.posCache.LnCol(val.Pos),
	}
}

func (p *parser) newParenExpr(lParen, rParen Item, node ast.Node) ast.Node {
	return &ast.ParenExpr{
		Param:  node,
		LParen: p.posCache.LnCol(lParen.Pos),
		RParen: p.posCache.LnCol(rParen.Pos),
	}
}

func (p *parser) newListLiteral(l, r Item, exprs []ast.Node) ast.Node {
	return &ast.ListLiteral{
		List:     exprs,
		LBracket: p.pos(l),
		RBracket: p.pos(r),
	}
}

func (p *parser) newMapLiteral(l, r Item, exprs [][2]ast.Node) ast.Node {
	return &ast.MapLiteral{
		KeyValeList: exprs,
		LBrace:      p.pos(l),
		RBrace:      p.pos(r),
	}
}

func (p *parser) newNumberLiteral(v Item) ast.Node {
	if n, err := strconv.ParseInt(v.Val, 0, 64); err != nil {
		f, err := strconv.ParseFloat(v.Val, 64)
		if err != nil {
			p.addParseErrf(p.yyParser.lval.item.PositionRange(),
				"error parsing number: %s", err)
			return nil
		}
		return &ast.FloatLiteral{
			Val:   f,
			Start: p.posCache.LnCol(v.Pos),
		}
	} else {
		return &ast.IntegerLiteral{
			Val:   n,
			Start: p.posCache.LnCol(v.Pos),
		}
	}
}

func (p *parser) newFnParam(id ast.Node, typ ast.Node, val ast.Node, varb ...bool) ast.FnParam {
	v := false
	if len(varb) > 0 && varb[0] {
		v = true
	}
	return ast.FnParam{
		Name:       id,
		DType:      typ,
		DefaultVal: val,
		Varb:       v,
	}
}

func (p *parser) newReturnStmt(pos Item, exprs []ast.Node) ast.Node {
	return &ast.ReturnStmt{
		ReturnPos: p.pos(pos),
		Exprs:     exprs,
	}
}

func (p *parser) newFnDefStmt(fn Item, name ast.Node, params []ast.FnParam, results []ast.Node, body *ast.BlockStmt) ast.Node {
	return &ast.FnDefStmt{
		FnPos: p.pos(fn),
		Name:  name,
		FnType: &ast.TypeFn{
			Params:  params,
			Results: results,
		},
		Block: body,
	}
}

func (p *parser) newBlockStmt(lBrace, rBrace Item, stmts ast.Stmts) *ast.BlockStmt {
	return &ast.BlockStmt{
		LBracePos: p.posCache.LnCol(lBrace.Pos),
		Stmts:     stmts,
		RBracePos: p.posCache.LnCol(rBrace.Pos),
	}
}

func (p *parser) newBreakStmt(pos plToken.Pos) ast.Node {
	return &ast.BreakStmt{
		Start: p.posCache.LnCol(pos),
	}
}

func (p *parser) newContinueStmt(pos plToken.Pos) ast.Node {
	return &ast.ContinueStmt{
		Start: p.posCache.LnCol(pos),
	}
}

func (p *parser) newForStmt(forTK Item, initExpr, condExpr, loopExpr ast.Node, body *ast.BlockStmt) ast.Node {
	return &ast.ForStmt{
		Init: initExpr,
		Loop: loopExpr,
		Cond: condExpr,
		Body: body,

		ForPos: p.pos(forTK),
	}
}

func (p *parser) newForInStmt(forTk Item, inExpr ast.Node, body *ast.BlockStmt) ast.Node {
	return &ast.ForInStmt{
		InExpr: inExpr,
		Body:   body,
		ForPos: p.pos(forTk),
	}
}

func (p *parser) newIfElifStmt(ifElifList []*ast.IfStmtElem) ast.Node {
	if len(ifElifList) == 0 {
		p.addParseErrf(p.yyParser.lval.item.PositionRange(), "invalid ifelse stmt is empty")
		return nil
	}

	return &ast.IfelseStmt{
		IfList: ast.IfList(ifElifList),
	}
}

func (p *parser) newIfElifelseStmt(ifElifList []*ast.IfStmtElem,
	elseTk Item, elseElem *ast.BlockStmt,
) ast.Node {
	if len(ifElifList) == 0 {
		p.addParseErrf(p.yyParser.lval.item.PositionRange(), "invalid ifelse stmt is empty")
		return nil
	}

	return &ast.IfelseStmt{
		IfList:  ast.IfList(ifElifList),
		Else:    elseElem,
		ElsePos: p.posCache.LnCol(elseTk.Pos),
	}
}

func (p *parser) newIfElem(ifTk Item, condition ast.Node, block *ast.BlockStmt) *ast.IfStmtElem {
	if condition == nil {
		p.addParseErrf(p.yyParser.lval.item.PositionRange(), "invalid if/elif condition")
		return nil
	}

	ifElem := &ast.IfStmtElem{
		Condition: condition,
		Block:     block,
		Start:     p.posCache.LnCol(ifTk.Pos),
	}

	return ifElem
}

func (p *parser) newUnaryExpr(op Item, r ast.Node) ast.Node {
	return &ast.UnaryExpr{
		Op:    AstOp(op.Typ),
		RHS:   r,
		OpPos: p.pos(op),
	}
}

func (p *parser) newAssignmentStmt(l, r []ast.Node, op Item) ast.Node {
	return &ast.AssignmentExpr{
		LHS:   l,
		Op:    AstOp(op.Typ),
		RHS:   r,
		OpPos: p.posCache.LnCol(op.Pos),
	}
}

func (p *parser) newInExpr(l, r ast.Node, inOp Item) ast.Node {
	return &ast.InExpr{
		LHS:   l,
		Op:    ast.IN,
		RHS:   r,
		OpPos: p.posCache.LnCol(inOp.Pos),
	}
}

func (p *parser) newConditionalExpr(l, r ast.Node, op Item) ast.Node {
	return &ast.ConditionalExpr{
		RHS:   r,
		LHS:   l,
		Op:    AstOp(op.Typ),
		OpPos: p.posCache.LnCol(op.Pos),
	}
}

func (p *parser) newArithmeticExpr(l, r ast.Node, op Item) ast.Node {
	return &ast.ArithmeticExpr{
		RHS: r,
		LHS: l,
		Op:  AstOp(op.Typ),

		OpPos: p.posCache.LnCol(op.Pos),
	}
}

func (p *parser) newAttrExpr(obj, attr ast.Node) ast.Node {
	pos := p.yyParser.lval.item.PositionRange()

	return &ast.AttrExpr{
		Obj:   obj,
		Attr:  attr,
		Start: p.posCache.LnCol(pos.Start),
	}
}

func (p *parser) newIndexExpr(lBracket, rBracket Item, obj, index ast.Node, dot ...Item) ast.Node {
	var dotPos plToken.LnColPos
	if len(dot) == 1 {
		dotPos = p.pos(dot[0])
	}
	return &ast.IndexExpr{
		Obj:      obj,
		Index:    index,
		Dot:      dotPos,
		LBracket: p.pos(lBracket),
		RBracket: p.pos(rBracket),
	}
}

func (p *parser) newCallExpr(lParen, rParen Item, fn ast.Node, args []ast.Node) ast.Node {

	f := &ast.CallExpr{
		Obj:    fn,
		Param:  args,
		LParen: p.posCache.LnCol(lParen.Pos),
		RParen: p.posCache.LnCol(rParen.Pos),
	}

	return f
}
func (p *parser) newSliceExpr(l, r Item, obj, start, end, step ast.Node) ast.Node {
	return &ast.SliceExpr{
		Obj:      obj,
		Start:    start,
		End:      end,
		Step:     step,
		LBracket: p.pos(l),
		RBracket: p.pos(r),
	}
}

// end of yylex.(*parser).newXXXX

// impl Lex interface.
func (p *parser) Lex(lval *yySymType) int {
	var typ ItemType

	if p.injecting {
		p.injecting = false
		return int(p.inject)
	}

	for { // skip comment
		p.lex.NextItem(&lval.item)
		typ = lval.item.Typ
		if typ != COMMENT {
			break
		}
	}

	switch typ {
	case ERROR:
		pos := PositionRange{
			Start: p.lex.start,
			End:   plToken.Pos(len(p.lex.input)),
		}

		p.addParseErr(&pos, errors.New(p.yyParser.lval.item.Val))
		return 0 // tell yacc it's the end of input

	case EOF:
		lval.item.Typ = EOF
		p.InjectItem(0)
	case RIGHT_PAREN:
		p.lastClosing = lval.item.Pos + plToken.Pos(len(lval.item.Val))
	}
	return int(typ)
}

func (p *parser) Error(e string) {}

func newParser(input string) *parser {
	p, ok := parserPool.Get().(*parser)
	if !ok {
		return nil
	}

	p.injecting = false
	p.errs = nil
	p.parseResult = nil
	p.lex = Lexer{
		input: input,
		state: lexStatements,
	}
	p.posCache = *plToken.NewPosCache(input)
	return p
}

func ParsePipeline(name, input string) (res ast.Stmts, err error) {
	p := newParser(input)
	defer parserPool.Put(p)
	defer p.recover(&err)

	p.InjectItem(START_STMTS)
	p.yyParser.Parse(p)

	if len(p.errs) != 0 {
		err = conv2PlError(name, p.errs, &p.posCache)
		return
	}

	if p.parseResult != nil {
		res = p.parseResult
	}

	return res, err
}

func conv2PlError(name string, errs ParseErrors, posCache *plToken.PosCache) *errchain.PlError {
	if len(errs) > 0 {
		pos := posCache.LnCol(errs[0].Pos.Start)
		return errchain.NewErr(name, pos, errs[0].Err.Error())
	}

	return nil
}
