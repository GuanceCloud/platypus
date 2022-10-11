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

func TestGroupIn(t *testing.T) {
	cases := []struct {
		name, pl, in string
		expected     interface{}
		fail         bool
		outkey       string
	}{
		{
			name: "normal",
			pl: `json(_, status) 
			group_in(status, [true], "ok", "newkey")`,
			in:       `{"status": true,"age":"47"}`,
			expected: "ok",
			outkey:   "newkey",
		},
		{
			name: "normal",
			pl: `json(_, status) 
			group_in(status, [true], "ok", "newkey")`,
			in:       `{"status": true,"age":"47"}`,
			expected: "ok",
			outkey:   "newkey",
		},
		{
			name: "normal",
			pl: `json(_, status)
			 group_in(status, [true], "ok", "newkey")`,
			in:       `{"status": "aa","age":"47"}`,
			expected: "aa",
			outkey:   "status",
		},
		{
			name: "normal",
			pl: `json(_, status)
			 group_in(status, ["aa"], "ok", "newkey")`,
			in:       `{"status": "aa","age":"47"}`,
			expected: "ok",
			outkey:   "newkey",
		},
		{
			name: "normal",
			in:   `{"log_level": "test","age":"47"}`,
			pl: `json(_, log_level)
			 group_in(log_level, [200, "test"], 119)`,
			expected: int64(119),
			outkey:   "log_level",
		},
		{
			name: "normal",
			in:   `{"log_level": "test","age":"47"}`,
			pl: `json(_, log_level)
			 group_in(log_level, [200, "test1"], 119)`,
			expected: "test",
			outkey:   "log_level",
		},
		{
			name: "normal",
			in:   `{"log_level": "test","age":"47"}`,
			pl: `json(_, log_level)
			 group_in(log_level, [200, "test"], 119, "hh")`,
			expected: int64(119),
			outkey:   "hh",
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

			assert.Equal(t, nil, err)

			t.Log(f)
			v, ok := f[tc.outkey]
			assert.Equal(t, true, ok)
			assert.Equal(t, tc.expected, v)
			t.Logf("[%d] PASS", idx)
		})
	}
}
