// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

// Package engine run pipeline script
package engine

import (
	"os"
	"path/filepath"
	"time"

	"github.com/GuanceCloud/ppl/pkg/engine/runtime"
	"github.com/GuanceCloud/ppl/pkg/parser"
)

func ParseScript(scripts map[string]string,
	call map[string]runtime.FuncCall, check map[string]runtime.FuncCheck) (
	map[string]*runtime.Script, map[string]error,
) {
	retErrMap := map[string]error{}
	retMap := map[string]*runtime.Script{}

	for name, content := range scripts {
		stmts, err := parser.ParsePipeline(content)
		if err != nil {
			retErrMap[name] = err
			continue
		}
		p := &runtime.Script{
			FuncCall: call,
			Name:     name,
			Ast:      stmts,
		}

		if err := CheckScript(p, check); err != nil {
			retErrMap[name] = err
			continue
		}
		retMap[name] = p
	}
	retMap, retErrs := EngineCallRefLinkAndCheck(retMap, retErrMap)

	for k, v := range retErrs {
		retErrMap[k] = v
	}

	return retMap, retErrMap
}

func RunScript(proc *runtime.Script, measurement string,
	tags map[string]string, fields map[string]any, tn time.Time, signal runtime.Signal) (
	string, map[string]string, map[string]any, time.Time, bool, error,
) {
	return runtime.RunScript(proc, measurement, tags, fields, tn, signal)
}

func RunScriptWithCtx(ctx *runtime.Context, proc *runtime.Script) error {
	return runtime.RunScriptWithCtx(ctx, proc)
}

func CheckScript(proc *runtime.Script, funcsCheck map[string]runtime.FuncCheck) error {
	return runtime.CheckScript(proc, funcsCheck)
}

func ReadPlScriptFromDir(dirPath string) (map[string]string, map[string]string, error) {
	ret := map[string]string{}
	retPath := map[string]string{}
	dirPath = filepath.Clean(dirPath)
	if dirEntry, err := os.ReadDir(dirPath); err != nil {
		return nil, nil, err
	} else {
		for _, v := range dirEntry {
			if v.IsDir() {
				continue
			}
			sName := v.Name()
			if filepath.Ext(sName) != ".p" {
				continue
			}
			sPath := filepath.Join(dirPath, sName)
			if name, script, err := ReadPlScriptFromFile(sPath); err == nil {
				ret[name] = script
				retPath[name] = sPath
			} else {
				return nil, nil, err
			}
		}
	}
	return ret, retPath, nil
}

func ReadPlScriptFromFile(fp string) (string, string, error) {
	fp = filepath.Clean(fp)
	if v, err := os.ReadFile(filepath.Clean(fp)); err == nil {
		_, sName := filepath.Split(fp)
		return sName, string(v), nil
	} else {
		return "", "", err
	}
}
