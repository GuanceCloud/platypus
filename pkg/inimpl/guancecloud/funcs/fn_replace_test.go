// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"testing"
	"time"

	"github.com/stretchr/testify/assert"
)

func TestReplace(t *testing.T) {
	cases := []struct {
		name     string
		pl, in   string
		outKey   string
		expected interface{}
		fail     bool
	}{
		{
			name: `normal1`,
			pl: `input = load_json(_); str1xxx = input["str1xxx"] 
			replace(str1xxx, "(1[0-9]{2})[0-9]{4}([0-9]{4})", "$1****$2")`,
			in:       `{"str1xxx": "13789123014"}`,
			outKey:   "str1xxx",
			fail:     false,
			expected: "137****3014",
		},

		{
			name: `normal2`,
			pl: `input = load_json(_); str1xxx = input["str1xxx"] 
			replace(str1xxx, "([a-z]*) \\w*", "$1 ***")`,
			in:       `{"str1xxx": "zhang san"}`,
			outKey:   "str1xxx",
			expected: "zhang ***",
			fail:     false,
		},

		{
			name: `normal3`,
			pl: `input = load_json(_); str1xxx = input["str1xxx"] 
			replace(str1xxx, "([1-9]{4})[0-9]{10}([0-9]{4})", "$1**********$2")`,
			in:       `{"str1xxx": "362201200005302565"}`,
			outKey:   "str1xxx",
			expected: "3622**********2565",
			fail:     false,
		},

		{
			name: `normal4`,
			pl: `input = load_json(_); str1xxx = input["str1xxx"] 
			replace(str1xxx, '([\u4e00-\u9fa5])[\u4e00-\u9fa5]([\u4e00-\u9fa5])', "$1＊$2")`,
			in:       `{"str1xxx": "小阿卡"}`,
			outKey:   "str1xxx",
			expected: "小＊卡",
			fail:     false,
		},

		{
			name: `normal5`,
			pl: `input = load_json(_); str1xxx = input["str1xxx"]; add_key(str1xxx); printf("%v", get_key(str1xxx))
			replace(str1, '([\u4e00-\u9fa5])[\u4e00-\u9fa5]([\u4e00-\u9fa5])', "$1＊$2")`,
			in:       `{"str1xxx": "小阿卡"}`,
			outKey:   "str1xxx",
			expected: "小阿卡",
			fail:     false,
		},

		{
			name: `not enough args`,
			pl: `input = load_json(_); str1xxx = input["str1xxx"] 
			replace(str1xxx, '([\u4e00-\u9fa5])[\u4e00-\u9fa5]([\u4e00-\u9fa5])')`,
			in:   `{"str1xxx": "小阿卡"}`,
			fail: true,
		},

		{
			name: `invalid arg type`,
			pl: `input = load_json(_); str1xxx = input["str1xxx"] 
			replace(str1xxx, 2, "$1＊$2")`,
			in:   `{"str1xxx": "小阿卡"}`,
			fail: true,
		},
	}

	for idx, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			runner, err := NewTestingRunner(tc.pl)
			if err != nil {
				if tc.fail {
					t.Logf("[%d]expect error: %s", idx, err)
				} else {
					t.Errorf("[%d] failed: %s", idx, err)
				}
				return
			}

			_, _, f, _, _, err := runScript(runner, "test", nil, map[string]interface{}{
				"message": tc.in,
			}, time.Now())
			if err != nil {
				t.Fatal(err)
			}

			if v, ok := f[tc.outKey]; !ok {
				if !tc.fail {
					t.Errorf("[%d]expect error: %s", idx, err)
				}
			} else {
				assert.Equal(t, tc.expected, v)
				t.Logf("[%d] PASS", idx)
			}

			t.Logf("[%d] PASS", idx)
		})
	}
}
