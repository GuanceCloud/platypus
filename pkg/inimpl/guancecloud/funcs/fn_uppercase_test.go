// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"strings"
	"testing"
	"time"

	"github.com/stretchr/testify/assert"
)

func TestUppercase(t *testing.T) {
	cases := []struct {
		name     string
		pl, in   string
		outKey   string
		expected string
		fail     bool
	}{
		{
			name: "normal1",
			pl: `
input  = load_json(_)
third = input["a"]["third"]
uppercase(third)
`,
			in:       `{"a":{"first":2.3,"second":2,"third":"abc","forth":true},"age":47}`,
			outKey:   "third",
			expected: "ABC",
			fail:     false,
		},

		{
			name: "normal2",
			pl: `
			input  = load_json(_)
			age = input["age"]
			uppercase(age)
`,
			in:       `{"a":{"first":2.3,"second":2,"third":"abc","forth":true},"age":47}`,
			outKey:   "age",
			expected: "47",
			fail:     false,
		},

		{
			name: "normal3",
			pl: `
			input  = load_json(_)
			forth = input["a"]["forth"];uppercase(forth)
`,
			in:       `{"a":{"first":2.3,"second":2,"third":"abc","forth":"1a2B3c/d"},"age":47}`,
			outKey:   "forth",
			expected: strings.ToUpper("1a2B3C/d"),
			fail:     false,
		},

		{
			name: "too many args",
			pl: `
			input  = load_json(_)
			forth = input["a"]["forth"]
		uppercase(forth, "someArg")
		`,
			in:   `{"a":{"first":2.3,"second":2,"third":"abc","forth":"1a2B3c/d"},"age":47}`,
			fail: true,
		},

		{
			name: "invalid arg type",
			pl: `
			input  = load_json(_)
			forth = input["a"]["forth"]
		uppercase("hello")
		`,
			in:   `{"a":{"first":2.3,"second":2,"third":"abc","forth":"1a2B3c/d"},"age":47}`,
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
		})
	}
}
