// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package ast

import (
	"strings"

	"github.com/GuanceCloud/ppl/pkg/token"
)

type IfelseStmt struct {
	IfList IfList
	Else   *BlockStmt

	ElsePos token.Pos
}

func (e *IfelseStmt) IsExpr() bool {
	return false
}

func (e *IfelseStmt) String() string {
	arr := []string{e.IfList.String()}
	if e.Else != nil && len(e.Else.Stmts) != 0 {
		arr = append(arr, "else", "{", e.Else.String(), "}")
	}
	return strings.Join(arr, " ")
}

// IfList index [0] is IF, [1..end] is ELIF.
type IfList []*IfStmtElem

func (e IfList) String() string {
	if len(e) == 0 {
		return ""
	}
	arr := []string{"if", e[0].String()}
	for i := 1; i < len(e); i++ {
		arr = append(arr, "elif", e[i].String())
	}
	return strings.Join(arr, " ")
}

type IfStmtElem struct {
	Condition *Node
	Block     *BlockStmt

	Start token.Pos
}

func (e *IfStmtElem) String() string {
	arr := []string{e.Condition.String(), "{", e.Block.String(), "}"}
	return strings.Join(arr, " ")
}

type BreakStmt struct {
	Start token.Pos
}

func (e *BreakStmt) String() string {
	return "break"
}

type ContinueStmt struct {
	Start token.Pos
}

func (e *ContinueStmt) String() string {
	return "continue"
}

type ForInStmt struct {
	Varb *Node
	Iter *Node
	Body *BlockStmt

	ForPos token.Pos
	InPos  token.Pos
}

func (e *ForInStmt) String() string {
	return "for in stmt"
}

type ForStmt struct {
	// init
	Init *Node

	// step1: -> step2 or break
	Cond *Node

	// step3: -> step1
	Loop *Node

	// step2: -> step3
	Body *BlockStmt

	ForPos token.Pos
}

func (e *ForStmt) String() string {
	return "for stmt"
}

type BlockStmt struct {
	LBracePos token.Pos
	RBracePos token.Pos
	Stmts     Stmts
}

func (block *BlockStmt) String() string {
	return "block stmt"
}
