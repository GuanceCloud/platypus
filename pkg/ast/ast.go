// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

// Package ast pipeline ast node
package ast

import (
	"fmt"
	"sort"
	"strings"
	"sync"

	"github.com/GuanceCloud/platypus/pkg/token"
)

type NodeType uint

var (
	dagCache = struct {
		sync.RWMutex
		m map[string]*DAGNode
	}{m: make(map[string]*DAGNode)}
)

const (
	// expr.
	TypeInvalid NodeType = iota

	TypeIdentifier
	TypeStringLiteral
	TypeIntegerLiteral
	TypeFloatLiteral
	TypeBoolLiteral
	TypeNilLiteral

	TypeListLiteral
	TypeMapLiteral

	TypeInExpr

	TypeParenExpr

	TypeAttrExpr
	TypeIndexExpr

	TypeUnaryExpr
	TypeArithmeticExpr
	TypeConditionalExpr
	TypeAssignmentExpr

	TypeCallExpr
	TypeSliceExpr

	// stmt.
	TypeBlockStmt
	TypeIfelseStmt
	TypeForStmt
	TypeForInStmt
	TypeContinueStmt
	TypeBreakStmt
)

func (t NodeType) String() string {
	switch t {
	case TypeInvalid:
		return "Invalid"
	case TypeIdentifier:
		return "Identifier"
	case TypeInExpr:
		return "InExpr"
	case TypeStringLiteral:
		return "StringLiteral"
	case TypeIntegerLiteral:
		return "IntLiteral"
	case TypeFloatLiteral:
		return "FloatLiteral"
	case TypeBoolLiteral:
		return "BoolLiteral"
	case TypeNilLiteral:
		return "NilLiteral"
	case TypeListLiteral:
		return "ListLiteral"
	case TypeMapLiteral:
		return "MapLiteral"
	case TypeParenExpr:
		return "ParenExpr"
	case TypeAttrExpr:
		return "AttrExpr"
	case TypeIndexExpr:
		return "IndexExpr"
	case TypeUnaryExpr:
		return "UnaryExpr"
	case TypeArithmeticExpr:
		return "ArithmeticExpr"
	case TypeConditionalExpr:
		return "ConditionalExpr"
	case TypeAssignmentExpr:
		return "AssignmentExpr"
	case TypeCallExpr:
		return "CallExpr"
	case TypeSliceExpr:
		return "SliceExpr"
	case TypeBlockStmt:
		return "BlockStmt"
	case TypeIfelseStmt:
		return "IfelseStmt"
	case TypeForStmt:
		return "ForStmt"
	case TypeForInStmt:
		return "ForInStmt"
	case TypeContinueStmt:
		return "ContinueStmt"
	case TypeBreakStmt:
		return "BreakStmt"
	}
	return "Undefined"
}

type Stmts []*Node

type KwArgs map[string]*Node

type FuncArgList []*Node

func (e KwArgs) String() string {
	keys := []string{}
	for k := range e {
		keys = append(keys, k)
	}
	sort.Strings(keys)

	arr := []string{}
	for _, key := range keys {
		arr = append(arr, fmt.Sprintf("%s = %s", key, e[key]))
	}
	return strings.Join(arr, ", ")
}

func (e Stmts) String() string {
	arr := []string{}
	for _, x := range e {
		arr = append(arr, x.String())
	}
	return strings.Join(arr, "\n")
}

type AstNode interface {
	String() string
}

type Node struct {
	// node type
	NodeType NodeType
	elem     AstNode
	DagNode  *DAGNode
}

func (n *Node) String() string {
	if n.elem != nil {
		return n.elem.String()
	}
	return n.NodeType.String()
}

func (n *Node) Identifier() *Identifier {
	return n.elem.(*Identifier)
}
func (n *Node) StringLiteral() *StringLiteral {
	return n.elem.(*StringLiteral)
}
func (n *Node) IntegerLiteral() *IntegerLiteral {
	return n.elem.(*IntegerLiteral)
}
func (n *Node) FloatLiteral() *FloatLiteral {
	return n.elem.(*FloatLiteral)
}
func (n *Node) BoolLiteral() *BoolLiteral {
	return n.elem.(*BoolLiteral)
}
func (n *Node) NilLiteral() *NilLiteral {
	return n.elem.(*NilLiteral)
}
func (n *Node) ListLiteral() *ListLiteral {
	return n.elem.(*ListLiteral)
}
func (n *Node) MapLiteral() *MapLiteral {
	return n.elem.(*MapLiteral)
}
func (n *Node) ParenExpr() *ParenExpr {
	return n.elem.(*ParenExpr)
}
func (n *Node) AttrExpr() *AttrExpr {
	return n.elem.(*AttrExpr)
}
func (n *Node) IndexExpr() *IndexExpr {
	return n.elem.(*IndexExpr)
}
func (n *Node) InExpr() *InExpr {
	return n.elem.(*InExpr)
}
func (n *Node) UnaryExpr() *UnaryExpr {
	return n.elem.(*UnaryExpr)
}
func (n *Node) ArithmeticExpr() *ArithmeticExpr {
	return n.elem.(*ArithmeticExpr)
}
func (n *Node) ConditionalExpr() *ConditionalExpr {
	return n.elem.(*ConditionalExpr)
}
func (n *Node) AssignmentExpr() *AssignmentExpr {
	return n.elem.(*AssignmentExpr)
}
func (n *Node) CallExpr() *CallExpr {
	return n.elem.(*CallExpr)
}
func (n *Node) SliceExpr() *SliceExpr {
	return n.elem.(*SliceExpr)
}
func (n *Node) BlockStmt() *BlockStmt {
	return n.elem.(*BlockStmt)
}
func (n *Node) IfelseStmt() *IfelseStmt {
	return n.elem.(*IfelseStmt)
}
func (n *Node) ForStmt() *ForStmt {
	return n.elem.(*ForStmt)
}
func (n *Node) ForInStmt() *ForInStmt {
	return n.elem.(*ForInStmt)
}
func (n *Node) ContinueStmt() *ContinueStmt {
	return n.elem.(*ContinueStmt)
}
func (n *Node) BreakStmt() *BreakStmt {
	return n.elem.(*BreakStmt)
}

func (n *Node) StartPos() token.LnColPos {
	return NodeStartPos(n)
}

func WrapIdentifier(node *Identifier) *Node {
	fingerprint := fmt.Sprintf("id %s", node.Name)
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeIdentifier,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.Name, node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeIdentifier,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapStringLiteral(node *StringLiteral) *Node {
	fingerprint := fmt.Sprintf("str %s", node.Val)
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeStringLiteral,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.Val, node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeStringLiteral,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapIntegerLiteral(node *IntegerLiteral) *Node {
	fingerprint := fmt.Sprintf("int %d", node.Val)
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeIntegerLiteral,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.String(), node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeIntegerLiteral,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapFloatLiteral(node *FloatLiteral) *Node {
	fingerprint := fmt.Sprintf("float %f", node.Val)
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeFloatLiteral,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.String(), node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeFloatLiteral,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapBoolLiteral(node *BoolLiteral) *Node {
	fingerprint := fmt.Sprintf("bool %t", node.Val)
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeBoolLiteral,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.String(), node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeBoolLiteral,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapNilLiteral(node *NilLiteral) *Node {
	fingerprint := "nil"
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeNilLiteral,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode("nil", node)
	return &Node{
		NodeType: TypeNilLiteral,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapListInitExpr(node *ListLiteral) *Node {
	fingerprint := fmt.Sprintf("list %s", node.String())
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeListLiteral,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.String(), node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeListLiteral,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapMapLiteral(node *MapLiteral) *Node {
	fingerprint := fmt.Sprintf("map %s", node.String())
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeMapLiteral,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.String(), node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeMapLiteral,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapParenExpr(node *ParenExpr) *Node {
	fingerprint := fmt.Sprintf("paren %s", node.String())
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeParenExpr,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.String(), node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeParenExpr,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapAttrExpr(node *AttrExpr) *Node {
	fingerprint := fmt.Sprintf("attr %s", node.String())
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeAttrExpr,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.String(), node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeAttrExpr,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapIndexExpr(node *IndexExpr) *Node {
	fingerprint := fmt.Sprintf("index %s", node.String())
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeIndexExpr,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(fingerprint, node)
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeIndexExpr,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapArithmeticExpr(node *ArithmeticExpr) *Node {
	lhsHash := node.LHS.Hash()
	rhsHash := node.RHS.Hash()
	fingerprint := fmt.Sprintf("%s %s %s", lhsHash, node.Op, rhsHash)
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeArithmeticExpr,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(fingerprint, node)
	if node.LHS.DagNode != nil {
		dagNode.AddChild(node.LHS.DagNode)
	}
	if node.RHS.DagNode != nil {
		dagNode.AddChild(node.RHS.DagNode)
	}
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeArithmeticExpr,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapConditionExpr(node *ConditionalExpr) *Node {
	lhsHash := node.LHS.Hash()
	rhsHash := node.RHS.Hash()
	fingerprint := fmt.Sprintf("%s %s %s", lhsHash, node.Op, rhsHash)
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeConditionalExpr,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(fingerprint, node)
	if node.LHS.DagNode != nil {
		dagNode.AddChild(node.LHS.DagNode)
	}
	if node.RHS.DagNode != nil {
		dagNode.AddChild(node.RHS.DagNode)
	}
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeConditionalExpr,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapInExpr(node *InExpr) *Node {
	lhsHash := node.LHS.Hash()
	rhsHash := node.RHS.Hash()
	fingerprint := fmt.Sprintf("%s %s %s", lhsHash, node.Op, rhsHash)
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeInExpr,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(fingerprint, node)
	if node.LHS.DagNode != nil {
		dagNode.AddChild(node.LHS.DagNode)
	}
	if node.RHS.DagNode != nil {
		dagNode.AddChild(node.RHS.DagNode)
	}
	cacheNode(fingerprint, dagNode)
	return &Node{
		NodeType: TypeInExpr,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapUnaryExpr(node *UnaryExpr) *Node {
	rhsHash := node.RHS.Hash()
	fingerprint := fmt.Sprintf("%s %s", node.Op, rhsHash)
	if cached, exists := getCachedNode(fingerprint); exists {
		return &Node{
			NodeType: TypeUnaryExpr,
			elem:     node,
			DagNode:  cached,
		}
	}
	dagNode := NewDAGNode(node.String(), node)

	return &Node{
		NodeType: TypeUnaryExpr,
		elem:     node,
		DagNode:  dagNode,
	}
}

func WrapAssignmentStmt(node *AssignmentExpr) *Node {
	return &Node{
		NodeType: TypeAssignmentExpr,
		elem:     node,
	}
}

func WrapCallExpr(node *CallExpr) *Node {
	return &Node{
		NodeType: TypeCallExpr,
		elem:     node,
	}
}

func WrapSliceExpr(node *SliceExpr) *Node {
	return &Node{
		NodeType: TypeSliceExpr,
		elem:     node,
	}
}
func WrapIfelseStmt(node *IfelseStmt) *Node {
	return &Node{
		NodeType: TypeIfelseStmt,
		elem:     node,
	}
}

func WrapForStmt(node *ForStmt) *Node {
	return &Node{
		NodeType: TypeForStmt,
		elem:     node,
	}
}

func WrapForInStmt(node *ForInStmt) *Node {
	return &Node{
		NodeType: TypeForInStmt,
		elem:     node,
	}
}

func WrapContinueStmt(node *ContinueStmt) *Node {
	return &Node{
		NodeType: TypeContinueStmt,
		elem:     node,
	}
}

func WrapBreakStmt(node *BreakStmt) *Node {
	return &Node{
		NodeType: TypeBreakStmt,
		elem:     node,
	}
}

func WrapeBlockStmt(node *BlockStmt) *Node {
	return &Node{
		NodeType: TypeBlockStmt,
		elem:     node,
	}
}

func NodeStartPos(node *Node) token.LnColPos {
	if node == nil || node.elem == nil {
		return token.InvalidLnColPos
	}
	switch node.NodeType {
	case TypeInvalid:
		return token.InvalidLnColPos
	case TypeIdentifier:
		return node.Identifier().Start
	case TypeStringLiteral:
		return node.StringLiteral().Start
	case TypeIntegerLiteral:
		return node.IntegerLiteral().Start
	case TypeFloatLiteral:
		return node.FloatLiteral().Start
	case TypeBoolLiteral:
		return node.BoolLiteral().Start
	case TypeNilLiteral:
		return node.NilLiteral().Start

	case TypeListLiteral:
		return node.ListLiteral().LBracket
	case TypeMapLiteral:
		return node.MapLiteral().LBrace

	case TypeParenExpr:
		return node.ParenExpr().LParen

	case TypeAttrExpr:
		return node.AttrExpr().Start

	case TypeIndexExpr:
		return node.IndexExpr().Obj.Start

	case TypeUnaryExpr:
		return node.UnaryExpr().OpPos
	case TypeArithmeticExpr:
		return node.ArithmeticExpr().LHS.StartPos()
	case TypeConditionalExpr:
		return node.ConditionalExpr().LHS.StartPos()
	case TypeAssignmentExpr:
		return node.AssignmentExpr().LHS.StartPos()

	case TypeCallExpr:
		return node.CallExpr().NamePos

	case TypeSliceExpr:
		return node.SliceExpr().LBracket
	case TypeBlockStmt:
		return node.BlockStmt().LBracePos

	case TypeIfelseStmt:
		if len(node.IfelseStmt().IfList) > 0 {
			return node.IfelseStmt().IfList[0].Start
		} else {
			return token.InvalidLnColPos
		}

	case TypeForStmt:
		return node.ForStmt().ForPos
	case TypeForInStmt:
		return node.ForInStmt().ForPos
	case TypeContinueStmt:
		return node.ContinueStmt().Start
	case TypeBreakStmt:
		return node.BreakStmt().Start
	}
	return token.InvalidLnColPos
}

func getCachedNode(fingerprint string) (*DAGNode, bool) {
	dagCache.RLock()
	defer dagCache.RUnlock()
	node, exists := dagCache.m[fingerprint]
	return node, exists
}

func cacheNode(fingerprint string, node *DAGNode) {
	dagCache.Lock()
	defer dagCache.Unlock()
	dagCache.m[fingerprint] = node
}

func (n *Node) Hash() string {
	if n.DagNode != nil {
		return n.DagNode.ID
	}
	switch n.NodeType {
	case TypeIdentifier:
		return n.Identifier().Name
	case TypeStringLiteral:
		return n.StringLiteral().Val
	case TypeIntegerLiteral:
		return n.IntegerLiteral().String()
	case TypeFloatLiteral:
		return n.FloatLiteral().String()
	case TypeBoolLiteral:
		return n.BoolLiteral().String()
	case TypeNilLiteral:
		return "nil"
	case TypeListLiteral:
		return n.ListLiteral().String()
	case TypeMapLiteral:
		return n.MapLiteral().String()
	case TypeParenExpr:
		return n.ParenExpr().String()
	case TypeAttrExpr:
		return n.AttrExpr().String()
	case TypeIndexExpr:
		return n.IndexExpr().String()
	case TypeUnaryExpr:
		return n.UnaryExpr().String()
	case TypeArithmeticExpr:
		return n.ArithmeticExpr().String()
	case TypeConditionalExpr:
		return n.ConditionalExpr().String()
	case TypeAssignmentExpr:
		return n.AssignmentExpr().String()
	}
	return ""
}
