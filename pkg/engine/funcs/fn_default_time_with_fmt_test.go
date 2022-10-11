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

func TestDefaultTimeWithFmt(t *testing.T) {
	// local timezone: utc+0800
	cst := time.FixedZone("CST", 8*3600)
	time.Local = cst

	cases := []struct {
		name, pl string
		in       []string
		outkey   string
		expect   []interface{}
		fail     bool
	}{
		{
			name: "02/Jan/2006:15:04:05 -0700",
			in: []string{
				`{"time":"02/Dec/2021:12:55:34 +0900"}`,
				`{"time":"02/Dec/2021:11:55:34 +0800"}`,
			},
			pl: `
			json(_, time)
			default_time_with_fmt(time, "02/Jan/2006:15:04:05 -0700","Asia/Tokyo")
		`,
			outkey: "time",
			expect: []interface{}{
				int64(1638417334000000000),
				int64(1638417334000000000),
			},
			fail: false,
		},
		{
			name: "02/Jan/2006:15:04:05 (Shanghai)",
			in: []string{
				`{"time":"02/Dec/2021:11:55:34"}`,
			},
			pl: `
			json(_, time)
			default_time_with_fmt(time, "02/Jan/2006:15:04:05","Asia/Shanghai")
		`,
			outkey: "time",
			expect: []interface{}{
				int64(1638417334000000000),
			},
			fail: false,
		},
		{
			name: "02/Jan/2006:15:04:05 (Local Shanghai)",
			in: []string{
				`{"time":"02/Dec/2021:11:55:34"}`,
			},
			pl: `
			json(_, time)
			default_time_with_fmt(time, "02/Jan/2006:15:04:05")
		`,
			outkey: "time",
			expect: []interface{}{
				int64(1638417334000000000),
			},
			fail: false,
		},
		{
			name: "02/Jan/2006:15:04:05 (Tokyo)",
			in: []string{
				`{"time":"02/Dec/2021:12:55:34"}`,
			},
			pl: `
			json(_, time)
			default_time_with_fmt(time, "02/Jan/2006:15:04:05","Asia/Tokyo")
		`,
			outkey: "time",
			expect: []interface{}{
				int64(1638417334000000000),
			},
			fail: false,
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
			for idxIn := 0; idxIn < len(tc.in); idxIn++ {
				_, _, f, tn, _, err := runScript(runner, "test", nil, map[string]interface{}{
					"message": tc.in[idxIn],
				}, time.Now())
				if err != nil {
					t.Error(err)
					return
				}

				var v interface{}
				if tc.outkey != "time" && tc.outkey != "" {
					v = f[tc.outkey]
				} else {
					v = tn.UnixNano()
				}
				assert.Equal(t, tc.expect[idxIn], v)
				t.Logf("[%d] PASS", idx)
			}
		})
	}
}
