// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"fmt"
	"math"
	"strconv"
	"strings"
	"time"

	"github.com/GuanceCloud/ppl/pkg/ast"
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

func fixYear(now time.Time, x int64) (int, error) {
	if x == DefaultInt {
		return now.Year(), nil
	}

	if x < 0 {
		return -1, fmt.Errorf("year should larger than 0")
	}

	// year like 02 -> 2002, 21 -> 2021
	if x < int64(100) { //nolint:gomnd
		x += int64(now.Year() / 100 * 100) //nolint:gomnd
		return int(x), nil
	}

	return int(x), nil
}

func fixMonth(now time.Time, x string) (time.Month, error) {
	if x == DefaultStr {
		return now.Month(), nil
	} else {
		if v, err := strconv.ParseInt(x, 10, 64); err == nil { // digital month: i.e., 01, 11
			if v < 1 || v > 12 {
				return time.Month(-1), fmt.Errorf("month should between [1,12], got %x,", x)
			}
			return time.Month(v), nil
		} else { // month like aug/august, january/jan
			v, ok := monthMaps[strings.ToLower(x)]
			if !ok {
				return InvalidInt, fmt.Errorf("unknown month %s", x)
			}
			return v, nil
		}
	}
}

func fixDay(now time.Time, x int64) (int, error) {
	if x == DefaultInt {
		return now.Day(), nil
	}

	if x < 1 || x > 31 {
		return -1, fmt.Errorf("month day should between [1,31], got %d", x)
	}

	return int(x), nil
}

func fixHour(now time.Time, x int64) (int, error) {
	if x == DefaultInt {
		return now.Hour(), nil
	}

	if x < 0 || x > 23 {
		return -1, fmt.Errorf("hour should between [0,24], got %d", x)
	}

	return int(x), nil
}

func fixMinute(now time.Time, x int64) (int, error) {
	if x == DefaultInt {
		return now.Minute(), nil
	}

	if x < 0 || x > 59 {
		return -1, fmt.Errorf("minute should between [0,59], got %d", x)
	}

	return int(x), nil
}

func fixSecond(x int64) (int, error) {
	if x == DefaultInt {
		return 0, nil
	}

	if x < 0 || x > 59 {
		return -1, fmt.Errorf("second should between [0,59], got %d", x)
	}

	return int(x), nil
}

func tz(s string) (z *time.Location, err error) {
	z, err = time.LoadLocation(s)
	if err != nil {
		if _, ok := timezoneList[s]; !ok {
			return nil, fmt.Errorf("unknown timezone %s", s)
		}

		z, err = time.LoadLocation(timezoneList[s])
		if err != nil {
			return nil, err
		}
	}

	return z, nil
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
