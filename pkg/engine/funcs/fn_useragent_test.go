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

func TestUserAgent(t *testing.T) {
	cases := []struct {
		name     string
		pl, in   string
		expected map[string]interface{}
		fail     bool
	}{
		{
			name: "normal",
			pl: `json(_, userAgent) 
			user_agent(userAgent)`,
			in: `
{
   "userAgent" : "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1985.125 Safari/537.36",
   "second"    : 2,
   "third"     : "abc",
   "forth"     : true
}
`,
			expected: map[string]interface{}{
				"isMobile":   false,
				"isBot":      false,
				"os":         "Windows 7",
				"browser":    "Chrome",
				"browserVer": "36.0.1985.125",
				"engine":     "AppleWebKit",
				"engineVer":  "537.36",
				"ua":         "Windows",
			},
			fail: false,
		},
		{
			name: "normal",
			pl: `json(_, userAgent) 
			user_agent(userAgent)`,
			in: `
{
    "userAgent" : "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/15.1 Safari/605.1.15"
}
`,
			expected: map[string]interface{}{
				"isMobile":   false,
				"isBot":      false,
				"os":         "Intel Mac OS X 10_15_7",
				"browser":    "Safari",
				"browserVer": "15.1",
				"engine":     "AppleWebKit",
				"engineVer":  "605.1.15",
				"ua":         "Macintosh",
			},
			fail: false,
		},

		{
			name: "normal",
			pl: `json(_, userAgent) 
			user_agent(agent)`,
			in: `
{
    "userAgent" : "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/15.1 Safari/605.1.15"
}
`,
			expected: map[string]interface{}{},
			fail:     false,
		},

		{
			name: "invalid arg type",
			pl: `json(_, userAgent) 
			user_agent("userAgent")`,
			in: `
		{
		   "userAgent" : "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/15.1 Safari/605.1.15"
		}
		`,
			expected: map[string]interface{}{},
			fail:     false,
		},

		{
			name: "too many args",
			pl: `json(_, userAgent) 
			user_agent(userAgent, someArg)`,
			in: `
		{
		   "userAgent" : "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/15.1 Safari/605.1.15"
		}
		`,
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
			if err != nil {
				if tc.fail {
					t.Logf("[%d]expect error: %s", idx, err)
				} else {
					t.Error(err)
				}
			} else {
				t.Log(f)
				fieldsToCompare := make(map[string]interface{})
				for k := range tc.expected {
					fieldsToCompare[k] = f[k]
				}
				assert.Equal(t, tc.expected, fieldsToCompare)
				t.Logf("[%d] PASS", idx)
			}
		})
	}
}
