// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"testing"
	"time"

	"github.com/GuanceCloud/cliutils/point"
	tu "github.com/GuanceCloud/cliutils/testutil"
	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/ptinput"
	"golang.org/x/text/encoding/simplifiedchinese"
)

type funcCase struct {
	name     string
	in       string
	script   string
	expected interface{}
	key      string
	fail     bool
}

func TestDecode(t *testing.T) {
	data := []string{"测试一下", "不知道", "测试一下123456", "哈哈哈哈哈", "-汪98阿萨德离开家"}
	decodeDataSlice := make([]string, 10)

	for idx, cont := range data {
		decodeData, _ := simplifiedchinese.GBK.NewEncoder().Bytes([]byte(cont))
		decodeDataSlice[idx] = string(decodeData)
	}

	testCase := []*funcCase{
		{
			in:     decodeDataSlice[0],
			script: `decode(_,"gbk")`,
			key:    "message",
		},
		{
			in:     decodeDataSlice[1],
			script: `decode(_,"gbk")`,
			key:    "message",
		},
		{
			in:     decodeDataSlice[2],
			script: `decode(_,"gbk")`,
			key:    "message",
		},
		{
			in:     decodeDataSlice[3],
			script: `decode(_,"gbk")`,
			key:    "message",
		},
		{
			in:     decodeDataSlice[4],
			script: `decode(_,"gbk")`,
			key:    "message",
		},
	}
	for idx, tc := range testCase {
		t.Run(tc.name, func(t *testing.T) {
			runner, err := NewTestingRunner(tc.script)
			tu.Equals(t, nil, err)

			pt := ptinput.NewPlPoint(
				point.Logging, "test", nil, map[string]any{"message": tc.in}, time.Now())
			errR := runScript(runner, pt)

			if errR != nil {
				t.Fatal(errR)
			}

			v, _, _ := pt.Get(tc.key)
			tu.Equals(t, data[idx], v)

			t.Logf("[%d] PASS", idx)
		})
	}
}
