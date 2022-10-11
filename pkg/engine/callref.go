// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package engine

import (
	"fmt"
	"strings"

	"github.com/GuanceCloud/ppl/pkg/engine/runtime"
)

type searchPath struct {
	nodeMap map[string]struct{}
	path    []string
}

func (p *searchPath) Push(nodeName string) error {
	p.path = append(p.path, nodeName)
	if _, ok := p.nodeMap[nodeName]; ok {
		defer func() {
			p.path = p.path[:len(p.path)-1]
		}()
		return fmt.Errorf("circular dependency: %s", p)
	}
	p.nodeMap[nodeName] = struct{}{}
	return nil
}

func (p *searchPath) Pop() {
	if len(p.path) == 0 {
		return
	}

	nodeName := p.path[len(p.path)-1]

	p.path = p.path[:len(p.path)-1]
	delete(p.nodeMap, nodeName)
}

func newSearchPath() *searchPath {
	return &searchPath{
		nodeMap: map[string]struct{}{},
		path:    []string{},
	}
}

func (p *searchPath) String() string {
	if len(p.path) == 0 {
		return ""
	}

	return strings.Join(p.path, " -> ")
}

func EngineCallRefLinkAndCheck(allNg map[string]*runtime.Script, allErrNg map[string]error) (map[string]*runtime.Script, map[string]error) {
	retMap := map[string]*runtime.Script{}
	retErrMap := map[string]error{}

	for name, ng := range allNg {
		sPath := newSearchPath()
		if err := dfs(name, ng, allNg, sPath, retMap, retErrMap, allErrNg); err != nil {
			retErrMap[name] = err
		} else {
			retMap[name] = ng
		}
	}

	return retMap, retErrMap
}

func dfs(name string, procc *runtime.Script, allNg map[string]*runtime.Script,
	sPath *searchPath, retMap map[string]*runtime.Script, retErrMap map[string]error,
	allErrNg map[string]error,
) error {
	if err := sPath.Push(name); err != nil {
		return err
	}
	if err, ok := retErrMap[name]; ok {
		return err
	}

	if _, ok := retMap[name]; ok {
		return nil
	}

	for cName := range procc.CallRef {
		if cNg, ok := allNg[cName]; !ok {
			if err, ok := allErrNg[cName]; ok {
				return fmt.Errorf("%s: %s", cName, err.Error())
			}
			return fmt.Errorf("%s: script %s not found", sPath.String(), cName)
		} else {
			procc.CallRef[cName] = cNg
			if err := dfs(cName, cNg, allNg, sPath, retMap, retErrMap, allErrNg); err != nil {
				return err
			}
		}
	}

	retMap[name] = procc
	sPath.Pop()

	return nil
}
