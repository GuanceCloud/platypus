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

func TestRename(t *testing.T) {
	cases := []struct {
		name, pl, in string
		expected     interface{}
		fail         bool
		outkey       string
	}{
		{
			name: "normal",
			pl: `
		add_pattern("_second", "(?:(?:[0-5]?[0-9]|60)(?:[:.,][0-9]+)?)")
		add_pattern("_minute", "(?:[0-5][0-9])")
		add_pattern("_hour", "(?:2[0123]|[01]?[0-9])")
		add_pattern("time", "([^0-9]?)%{_hour:hour}:%{_minute:minute}(?::%{_second:second})([^0-9]?)")
		grok(_, "%{time}")
		rename(newhour, hour)
	`,
			in:       "12:34:15",
			expected: "12",
			outkey:   "newhour",
		},
		{
			name: "normal",
			pl: `
		add_pattern("_second", "(?:(?:[0-5]?[0-9]|60)(?:[:.,][0-9]+)?)")
		add_pattern("_minute", "(?:[0-5][0-9])")
		add_pattern("_hour", "(?:2[0123]|[01]?[0-9])")
		add_pattern("time", "([^0-9]?)%{_hour:hour}:%{_minute:minute}(?::%{_second:second})([^0-9]?)")
		grok(_, "%{time}")
		rename(newsecond, second)
	`,
			in:       "12:34:15",
			expected: "15",
			outkey:   "newsecond",
		},
		{
			name: "normal",
			pl: `
		add_pattern("_second", "(?:(?:[0-5]?[0-9]|60)(?:[:.,][0-9]+)?)")
		add_pattern("_minute", "(?:[0-5][0-9])")
		add_pattern("_hour", "(?:2[0123]|[01]?[0-9])")
		add_pattern("time", "([^0-9]?)%{_hour:hour}:%{_minute:minute}(?::%{_second:second})([^0-9]?)")
		grok(_, "%{time}")
		rename(newminute, minute)
	`,
			in:       "12:34:15",
			expected: "34",
			outkey:   "newminute",
		},
		{
			name: "normal",
			pl: `
		add_pattern("_second", "(?:(?:[0-5]?[0-9]|60)(?:[:.,][0-9]+)?)")
		add_pattern("_minute", "(?:[0-5][0-9])")
		add_pattern("_hour", "(?:2[0123]|[01]?[0-9])")
		add_pattern("time", "([^0-9]?)%{_hour:hour}:%{_minute:minute}(?::%{_second:second})([^0-9]?)")
		grok(_, "%{time}")
		rename(minute, newminute)
	`,
			in:       "12:34:15",
			expected: "34",
			outkey:   "minute",
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
