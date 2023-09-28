// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"fmt"
	"math"
	"strings"
	"time"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/input"

	conv "github.com/spf13/cast"
)

func getKeyName(node *ast.Node) (string, error) {
	var key string

	switch node.NodeType { //nolint:exhaustive
	case ast.TypeIdentifier:
		key = node.Identifier.Name
	case ast.TypeAttrExpr:
		key = node.AttrExpr.String()
	case ast.TypeStringLiteral:
		key = node.StringLiteral.Val
	default:
		return "", fmt.Errorf("expect StringLiteral or Identifier or AttrExpr, got %s",
			node.NodeType)
	}
	return key, nil
}

const (
	InvalidInt   = math.MinInt32
	DefaultInt   = int64(0xdeadbeef)
	DefaultStr   = ""
	InvalidStr   = "deadbeaf"
	InvalidFloat = math.SmallestNonzeroFloat64
	DefaultFloat = float64(0.0)
)

func getPoint(in any) (*input.Point, error) {
	if in == nil {
		return nil, fmt.Errorf("nil ptr: input")
	}

	pt, ok := in.(*input.Point)

	if !ok {
		return nil, fmt.Errorf("typeof input is not Point")
	}

	if pt == nil {
		return nil, fmt.Errorf("nil ptr: input")
	}
	return pt, nil
}

func getPtKey(in any, key string) (any, ast.DType, error) {
	pt, err := getPoint(in)
	if err != nil {
		return nil, ast.Invalid, err
	}

	if key == "_" {
		key = input.Originkey
	}
	return pt.Get(key)
}

func deletePtKey(in any, key string) {
	pt, err := getPoint(in)
	if err != nil {
		return
	}

	if key == "_" {
		key = input.Originkey
	}

	pt.Delete(key)
}

func pointTime(in any) time.Time {
	pt, err := getPoint(in)
	if err != nil {
		return time.Now()
	}
	return pt.Time
}

func setPointTime(in any, tn time.Time) error {
	pt, err := getPoint(in)
	if err != nil {
		return err
	}
	pt.Time = tn
	return nil
}

func addKey2PtWithVal(in any, key string, value any, dtype ast.DType, kind input.KeyKind) error {
	pt, err := getPoint(in)
	if err != nil {
		return err
	}

	if key == "_" {
		key = input.Originkey
	}

	switch kind {
	case input.KindPtTag:
		return pt.SetTag(key, value, dtype)
	default:
		return pt.Set(key, value, dtype)
	}
}

func renamePtKey(in any, to, from string) error {
	if to == "_" {
		to = input.Originkey
	}

	if from == "_" {
		from = input.Originkey
	}

	if to == from {
		return nil
	}

	if in == nil {
		return fmt.Errorf("nil ptr: input")
	}

	pt, err := getPoint(in)

	if err != nil {
		return err
	}

	v, ok := pt.Meta[from]
	if !ok {
		return fmt.Errorf("key(from) %s not found", from)
	}

	switch v.PtFlag { //nolint:exhaustive
	case input.PtField:
		if v, ok := pt.Fields[from]; ok {
			pt.Fields[to] = v
		}
		delete(pt.Fields, from)
	case input.PtTag:
		if v, ok := pt.Tags[from]; ok {
			pt.Tags[to] = v
		}
		delete(pt.Tags, from)
	}
	return nil
}

func setMeasurement(in any, val string) error {
	pt, err := getPoint(in)

	if err != nil {
		return err
	}
	pt.Measurement = val
	return nil
}

func doCast(result interface{}, tInfo string) (interface{}, ast.DType) {
	switch strings.ToLower(tInfo) {
	case "bool":
		return conv.ToBool(result), ast.Bool

	case "int":
		return conv.ToInt64(conv.ToFloat64(result)), ast.Int

	case "float":
		return conv.ToFloat64(result), ast.Float

	case "str":
		return conv.ToString(result), ast.String
	}

	return nil, ast.Nil
}

func reIndexFuncArgs(fnStmt *ast.CallExpr, keyList []string, reqParm int) error {
	// reqParm >= 1, if < 0, no optional args
	args := fnStmt.Param

	if reqParm < 0 || reqParm > len(keyList) {
		reqParm = len(keyList)
	}

	if len(args) > len(keyList) {
		return fmt.Errorf("the number of parameters does not match")
	}

	beforPosArg := true

	kMap := map[string]int{}
	for k, v := range keyList {
		kMap[v] = k
	}

	ret := make([]*ast.Node, len(keyList))

	for idx, arg := range args {
		if arg.NodeType == ast.TypeAssignmentExpr {
			if beforPosArg {
				beforPosArg = false
			}
			kname, err := getKeyName(arg.AssignmentExpr.LHS)
			if err != nil {
				return err
			}
			kIndex, ok := kMap[kname]
			if !ok {
				return fmt.Errorf("argument %s does not exist", kname)
			}
			ret[kIndex] = arg.AssignmentExpr.RHS
		} else {
			if !beforPosArg {
				return fmt.Errorf("positional arguments cannot follow keyword arguments")
			}
			ret[idx] = arg
		}
	}

	for i := 0; i < reqParm; i++ {
		if v := ret[i]; v == nil {
			return fmt.Errorf("parameter %s is required", keyList[i])
		}
	}

	fnStmt.Param = ret
	return nil
}
