// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"fmt"

	"github.com/DataDog/datadog-agent/pkg/obfuscate"
	"github.com/GuanceCloud/ppl/pkg/ast"
	"github.com/GuanceCloud/ppl/pkg/engine/runtime"
	"github.com/GuanceCloud/ppl/pkg/inimpl/guancecloud/input"
)

func SQLCoverChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) error {
	if len(funcExpr.Param) != 1 {
		return fmt.Errorf("func %s expects 1 args", funcExpr.Name)
	}
	if _, err := getKeyName(funcExpr.Param[0]); err != nil {
		return err
	}
	return nil
}

func SQLCover(ctx *runtime.Context, funcExpr *ast.CallExpr) runtime.PlPanic {
	o := obfuscate.NewObfuscator(obfuscate.Config{})
	if len(funcExpr.Param) != 1 {
		return fmt.Errorf("func %s expects 1 args", funcExpr.Name)
	}

	key, err := getKeyName(funcExpr.Param[0])
	if err != nil {
		return err
	}

	cont, err := ctx.GetKeyConv2Str(key)
	if err != nil {
		l.Debugf("key `%v' not exist, ignored", key)
		return nil //nolint:nilerr
	}

	Type := "sql"

	v, err := obfuscatedResource(o, Type, cont)
	if err != nil {
		l.Debug(err)
		return nil
	}

	if err := addKey2PtWithVal(ctx.InData(), key, v, ast.String,
		input.KindPtDefault); err != nil {
		l.Debug(err)
		return nil
	}

	return nil
}

func obfuscatedResource(o *obfuscate.Obfuscator, typ, resource string) (string, error) {
	if typ != "sql" {
		return resource, nil
	}
	oq, err := o.ObfuscateSQLString(resource)
	if err != nil {
		err = fmt.Errorf("error obfuscating stats group resource %q: %w", resource, err)
		return "", err
	}
	return oq.Query, nil
}
