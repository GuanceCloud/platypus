// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package runtime

import (
	"encoding/json"
	"fmt"
	"testing"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/parser"
	"github.com/stretchr/testify/assert"
)

type inputImpl struct {
	data map[string]any
}

func (in *inputImpl) Get(key string) (any, ast.DType, error) {
	if in.data == nil {
		return nil, ast.Nil, fmt.Errorf("err")
	}
	v, ok := in.data[key]
	if !ok {
		return nil, ast.Nil, fmt.Errorf("err")
	}

	v, dtype := ast.DectDataType(v)
	if dtype == ast.Invalid {
		return nil, ast.Nil, fmt.Errorf("err")
	}
	return v, dtype, nil
}

func TestRunWithRMapIn(t *testing.T) {
}

func TestRuntime(t *testing.T) {
	pl := `
	b = 1 + 1
	a = (b + 2) == 4 || False
	c = a * 3 + +100 + -10 +
		3/1.1
	d = 4 / 3
	e = "dwdw" + "3"
	add_key(e)

	1 != 2
	2 == 2
	2 > 2
	c = 1 / 2 + 1 - 2 * 1 + 3 % 2
	add_key(c)

	map_a = {"a": 1, "b" :2 , "1.1": 2, "nil": [1,2.1,"3"], "1": nil}

	f = map_a["nil"][-1]


	aaaa = 1.0 == (b = 1)

	a = v = a
	x7 = [1, 2.1, "3"]
	if b == 2 {
		x = 2
		for i = 1; i < 4; i = i+1 {
			x1 = 1 + x
			e = e + "1"
			if i == 2 {
				break
			}
			continue
			e = e + "2"
		}
	}
	ddd = ""

	# 无序遍历 key
	# for x in {'a': 1, "b":2, "c":3} {
	# 	ddd = ddd + x
	# }

	# add_key(ddd)

	abc = {
		"a": [1,2,3],
		"d": "a",
		"1": 2,
		"d": nil
	}
	add_key(abc)
	abc["a"][-1] = 5
	add_key(abc)
` + ";`aa dw.` = abc;" + "add_key(`aa dw.`)" + `
for x in [1,2,3 ] {
	for y in [1,3,4] {
		if y == 3 {
			break
		}
		continue
	}
	break
}

a  = 1
for ;; {
	if a > 10 {
		break
	}
	a = a + 1
	continue
	a = a - 1
}

for ; a < 12; a = a + 1 {

}

for a; ; {
	if a > 15 {
		break
	}
	a = a + 1
}

for ; a; {
	add_key(a)
	if a > 10 {
		break
	}
}

for ; ; a= 15 {
	if a > 10 {
		break
	}
}

for a = 0; a < 12; a = a + 1 {
	if a > 5 {
	  add_key(ef, a)
	  break
	}
	continue
	a = a - 1
  }

add_key(len1, len([12,2]))
add_key(len2, len("123"))
`
	stmts, err := parseScript(pl)
	if err != nil {
		t.Fatal(err)
	}

	script := &Script{
		CallRef: nil,
		FuncCall: map[string]FuncCall{
			"test":    callexprtest,
			"add_key": addkeytest,
			"len":     lentest,
		},
		Name:      "abc",
		Namespace: "default",
		Category:  "",
		FilePath:  "",
		Content:   pl,
		Ast:       stmts,
	}
	errR := CheckScript(script, map[string]FuncCheck{
		"add_key": addkeycheck,
		"len":     lencheck,
	})
	if errR != nil {
		t.Fatal(*errR)
	}

	inData := &inputImpl{
		data: map[string]any{},
	}

	errR = RunScriptWithRMapIn(script, inData, nil)
	if errR != nil {
		t.Fatal(errR.ChainError())
	}
	assert.Equal(t, map[string]any{
		"aa dw.": `{"1":2,"a":[1,2,5],"d":null}`,
		"abc":    `{"1":2,"a":[1,2,5],"d":null}`,
		"e":      "dwdw3",
		"ef":     int64(6),
		"a":      int64(16),
		"len1":   int64(2),
		"len2":   int64(3),
		"c":      int64(0),
	}, inData.data)
}

func TestCondTrue(t *testing.T) {
	cases := []struct {
		val   any
		dtype ast.DType
		ok    bool
	}{
		{int64(1), ast.Int, true},
		{int64(0), ast.Int, false},
		{int64(-1), ast.Int, true},
		{float64(-0.), ast.Float, false},
		{float64(0.0), ast.Float, false},
		{float64(0.00000000000001), ast.Float, true},
		{"", ast.String, false},
		{"a1", ast.String, true},
		{true, ast.Bool, true},
		{false, ast.Bool, false},
		{map[string]any{}, ast.Map, false},
		{map[string]any{"1": nil}, ast.Map, true},
		{[]any{}, ast.List, false},
		{[]any{1}, ast.List, true},
	}

	for i, v := range cases {
		if condTrue(v.val, v.dtype) != v.ok {
			t.Error("idx ", i, v, " ", " ", !v.ok)
		}
	}
}

func TestCondOp(t *testing.T) {
	cases := []struct {
		op         ast.Op
		lhs, rhs   any
		lhsT, rhsT ast.DType
		ok         bool
		fail       bool
	}{
		{
			op:  ast.EQEQ,
			lhs: nil, rhs: nil,
			lhsT: ast.Nil, rhsT: ast.Nil,
			ok: true,
		},
		{
			op:  ast.EQEQ,
			lhs: int64(1), rhs: nil,
			lhsT: ast.Int, rhsT: ast.Nil,
			ok: false,
		},
		{
			op:  ast.EQEQ,
			lhs: int64(1), rhs: float64(1.),
			lhsT: ast.Int, rhsT: ast.Float,
			ok: true,
		},
		{
			op:  ast.EQEQ,
			lhs: int64(1), rhs: true,
			lhsT: ast.Int, rhsT: ast.Bool,
			ok: true,
		},
		{
			op:  ast.EQEQ,
			lhs: true, rhs: true,
			lhsT: ast.Bool, rhsT: ast.Bool,
			ok: true,
		},
		{
			op:  ast.EQEQ,
			lhs: true, rhs: float64(1.),
			lhsT: ast.Bool, rhsT: ast.Float,
			ok: true,
		},
		{
			op:  ast.EQEQ,
			lhs: false, rhs: float64(1.),
			lhsT: ast.Int, rhsT: ast.Float,
			ok: false,
		},
		{
			op:  ast.EQEQ,
			lhs: int64(1), rhs: "",
			lhsT: ast.Int, rhsT: ast.String,
			ok: false,
		},
		{
			op:  ast.EQEQ,
			lhs: "", rhs: "",
			lhsT: ast.String, rhsT: ast.String,
			ok: true,
		},
		{
			op:  ast.EQEQ,
			lhs: "", rhs: true,
			lhsT: ast.String, rhsT: ast.Bool,
			ok: false,
		},
		{
			op:  ast.EQEQ,
			lhs: nil, rhs: true,
			lhsT: ast.Nil, rhsT: ast.Bool,
			ok: false,
		},
		{
			op:  ast.EQEQ,
			lhs: nil, rhs: nil,
			lhsT: ast.Nil, rhsT: ast.Nil,
			ok: true,
		},
		{
			op:   ast.EQEQ,
			lhs:  []any{"a", []any{1, 2, "3", nil}},
			rhs:  []any{"a", []any{1, 2, "3", nil}},
			lhsT: ast.List, rhsT: ast.List,
			ok: true,
		},
		{
			op:   ast.EQEQ,
			lhs:  []any{"a", []any{1, 2, "3", nil}},
			rhs:  []any{"a"},
			lhsT: ast.List, rhsT: ast.List,
			ok: false,
		},
		{
			op:  ast.NEQ,
			lhs: nil, rhs: nil,
			lhsT: ast.Nil, rhsT: ast.Nil,
			ok: false,
		},
		{
			op:  ast.NEQ,
			lhs: int64(1), rhs: nil,
			lhsT: ast.Int, rhsT: ast.Nil,
			ok: true,
		},
		{
			op:  ast.NEQ,
			lhs: int64(1), rhs: float64(1.),
			lhsT: ast.Int, rhsT: ast.Float,
			ok: false,
		},
		{
			op:  ast.NEQ,
			lhs: int64(1), rhs: true,
			lhsT: ast.Int, rhsT: ast.Bool,
			ok: false,
		},
		{
			op:  ast.NEQ,
			lhs: true, rhs: true,
			lhsT: ast.Bool, rhsT: ast.Bool,
			ok: false,
		},
		{
			op:  ast.NEQ,
			lhs: true, rhs: float64(1.),
			lhsT: ast.Bool, rhsT: ast.Float,
			ok: false,
		},
		{
			op:  ast.NEQ,
			lhs: false, rhs: float64(1.),
			lhsT: ast.Int, rhsT: ast.Float,
			ok: true,
		},
		{
			op:  ast.NEQ,
			lhs: int64(1), rhs: "",
			lhsT: ast.Int, rhsT: ast.String,
			ok: true,
		},
		{
			op:  ast.NEQ,
			lhs: "", rhs: "",
			lhsT: ast.String, rhsT: ast.String,
			ok: false,
		},
		{
			op:  ast.NEQ,
			lhs: "", rhs: true,
			lhsT: ast.String, rhsT: ast.Bool,
			ok: true,
		},
		{
			op:  ast.NEQ,
			lhs: nil, rhs: true,
			lhsT: ast.Nil, rhsT: ast.Bool,
			ok: true,
		},
		{
			op:  ast.NEQ,
			lhs: nil, rhs: nil,
			lhsT: ast.Nil, rhsT: ast.Nil,
			ok: false,
		},
		{
			op:   ast.NEQ,
			lhs:  []any{"a", []any{1, 2, "3", nil}},
			rhs:  []any{"a", []any{1, 2, "3", nil}},
			lhsT: ast.List, rhsT: ast.List,
			ok: false,
		},
		{
			op:   ast.NEQ,
			lhs:  []any{"a", []any{1, 2, "3", nil}},
			rhs:  []any{"a"},
			lhsT: ast.List, rhsT: ast.List,
			ok: true,
		},

		{
			op:  ast.AND,
			lhs: true, rhs: false,
			lhsT: ast.Bool, rhsT: ast.Bool,
			ok: false,
		},
		{
			op:  ast.AND,
			lhs: true, rhs: true,
			lhsT: ast.Bool, rhsT: ast.Bool,
			ok: true,
		},
		{
			op:  ast.AND,
			lhs: nil, rhs: true,
			lhsT: ast.Nil, rhsT: ast.Bool,
			// ok: false,
			fail: true,
		},
		{
			op:  ast.AND,
			lhs: false, rhs: nil,
			lhsT: ast.Bool, rhsT: ast.Nil,
			// ok: false,
			fail: true,
		},
		{
			op:  ast.OR,
			lhs: false, rhs: false,
			lhsT: ast.Bool, rhsT: ast.Bool,
			ok: false,
		},
		{
			op:  ast.OR,
			lhs: true, rhs: false,
			lhsT: ast.Bool, rhsT: ast.Bool,
			ok: true,
		},
		{
			op:  ast.OR,
			lhs: true, rhs: true,
			lhsT: ast.Bool, rhsT: ast.Bool,
			ok: true,
		},
		{
			op:  ast.OR,
			lhs: nil, rhs: true,
			lhsT: ast.Nil, rhsT: ast.Bool,
			// ok: true,
			fail: true,
		},
		{
			op:  ast.OR,
			lhs: false, rhs: nil,
			lhsT: ast.Bool, rhsT: ast.Nil,
			// ok: true,
			fail: true,
		},

		{
			op:  ast.LT,
			lhs: true, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: false,
		},
		{
			op:  ast.LT,
			lhs: false, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: false,
		},
		{
			op:  ast.LT,
			lhs: false, rhs: float64(1),
			lhsT: ast.Bool, rhsT: ast.Float,
			ok: true,
		},

		{
			op:  ast.LTE,
			lhs: true, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: false,
		},
		{
			op:  ast.LTE,
			lhs: false, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: true,
		},
		{
			op:  ast.LTE,
			lhs: false, rhs: float64(1),
			lhsT: ast.Bool, rhsT: ast.Float,
			ok: true,
		},

		{
			op:  ast.LTE,
			lhs: true, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: false,
		},
		{
			op:  ast.LTE,
			lhs: false, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: true,
		},
		{
			op:  ast.LTE,
			lhs: false, rhs: float64(1),
			lhsT: ast.Bool, rhsT: ast.Float,
			ok: true,
		},

		{
			op:  ast.GTE,
			lhs: true, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: true,
		},
		{
			op:  ast.GTE,
			lhs: false, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: true,
		},
		{
			op:  ast.GTE,
			lhs: false, rhs: float64(1),
			lhsT: ast.Bool, rhsT: ast.Float,
			ok: false,
		},

		{
			op:  ast.GT,
			lhs: true, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: true,
		},
		{
			op:  ast.GT,
			lhs: false, rhs: int64(0),
			lhsT: ast.Bool, rhsT: ast.Int,
			ok: false,
		},
		{
			op:  ast.GT,
			lhs: false, rhs: float64(1),
			lhsT: ast.Bool, rhsT: ast.Float,
			ok: false,
		},

		{
			op:  ast.EQ,
			lhs: false, rhs: float64(1),
			lhsT: ast.Bool, rhsT: ast.Float,
			// ok: false
			fail: true,
		},
	}

	for k, v := range cases {
		val, dtype, err := condOp(v.lhs, v.rhs, v.lhsT, v.rhsT, v.op)
		if err != nil {
			if v.fail {
				continue
			}
			t.Error(err, v)
			continue
		}
		if condTrue(val, dtype) != v.ok {
			t.Error("idx", k, val, v)
		}
	}
}

func parseScript(content string) (ast.Stmts, error) {
	return parser.ParsePipeline(content)
}

func callexprtest(ctx *Context, callExpr *ast.CallExpr) *RuntimeError {
	return nil
}

func addkeytest(ctx *Context, callExpr *ast.CallExpr) *RuntimeError {
	key := callExpr.Param[0].Identifier.Name
	if len(callExpr.Param) > 1 {
		val, dtype, err := RunStmt(ctx, callExpr.Param[1])
		if err != nil {
			return err
		}
		if ctx.inType == InRMap {
			if v, ok := ctx.inRMap.(*inputImpl); ok {
				switch dtype {
				case ast.Map, ast.List:
					if res, err := json.Marshal(val); err == nil {
						v.data[key] = string(res)
					}
				default:
					v.data[key] = val
				}
			}
		}
	}
	if varb, err := ctx.GetKey(key); err == nil {
		if ctx.inType == InRMap {
			if v, ok := ctx.inRMap.(*inputImpl); ok {
				switch varb.DType {
				case ast.Map, ast.List:
					if res, err := json.Marshal(varb.Value); err == nil {
						v.data[key] = string(res)
					}
				default:
					v.data[key] = varb.Value
				}
			}
		}
	}

	return nil
}

func addkeycheck(ctx *Context, callExpr *ast.CallExpr) *RuntimeError {
	return nil
}

func lentest(ctx *Context, callExpr *ast.CallExpr) *RuntimeError {
	val, dtype, err := RunStmt(ctx, callExpr.Param[0])
	if err != nil {
		return err
	}
	switch dtype { //nolint:exhaustive
	case ast.String:
		ctx.Regs.ReturnAppend(int64(len(val.(string))), ast.Int)
	case ast.List:
		ctx.Regs.ReturnAppend(int64(len(val.([]any))), ast.Int)
	case ast.Map:
		ctx.Regs.ReturnAppend(int64(len(val.(map[string]any))), ast.Int)
	default:
		ctx.Regs.ReturnAppend(int64(0), ast.Int)
	}
	return nil
}

func lencheck(ctx *Context, callexpr *ast.CallExpr) *RuntimeError {
	return nil
}
