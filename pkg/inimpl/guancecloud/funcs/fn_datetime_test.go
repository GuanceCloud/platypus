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

func TestDateTime(t *testing.T) {
	// local timezone: utc+0800
	cst := time.FixedZone("CST", 8*3600)
	time.Local = cst

	cases := []struct {
		name, pl, in string
		outkey       string
		expect       interface{}
		fail         bool
	}{
		{
			name: "ANSIC s",
			in:   `{"a":{"timestamp": "1638253518", "second":2},"age":47}`,
			pl: `
	input = load_json(_); printf("%v", input["a"]["timestamp"]);ts = input["a"]["timestamp"];
	datetime(ts, 's', 'ANSIC')
	`,
			outkey: "ts",
			expect: "Tue Nov 30 14:25:18 2021",
			fail:   false,
		},
		{
			name: "ANSIC ms",
			in:   `{"a":{"timestamp": "1638253518000", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'ANSIC')
	`,
			outkey: "ts",
			expect: "Tue Nov 30 14:25:18 2021",
			fail:   false,
		},
		{
			name: "UnixDate s",
			in:   `{"a":{"timestamp": "1638253518", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'UnixDate')
	`,
			outkey: "ts",
			expect: "Tue Nov 30 14:25:18 CST 2021",
			fail:   false,
		},
		{
			name: "UnixDate ms",
			in:   `{"a":{"timestamp": "1638253518999", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'UnixDate')
	`,
			outkey: "ts",
			expect: "Tue Nov 30 14:25:18 CST 2021",
			fail:   false,
		},
		{
			name: "RubyDate ms",
			in:   `{"a":{"timestamp": "1638253518999", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'RubyDate')
	`,
			outkey: "ts",
			expect: "Tue Nov 30 14:25:18 +0800 2021",
			fail:   false,
		},
		{
			name: "RubyDate s",
			in:   `{"a":{"timestamp": "1638253518", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'RubyDate')
	`,
			outkey: "ts",
			expect: "Tue Nov 30 14:25:18 +0800 2021",
			fail:   false,
		},
		{
			name: "RFC822 ms",
			in:   `{"a":{"timestamp": "1638253518999", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'RFC822')
	`,
			outkey: "ts",
			expect: "30 Nov 21 14:25 CST",
			fail:   false,
		},
		{
			name: "RFC822 s",
			in:   `{"a":{"timestamp": "1638253518", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'RFC822')
	`,
			outkey: "ts",
			expect: "30 Nov 21 14:25 CST",
			fail:   false,
		},
		{
			name: "RFC822Z ms",
			in:   `{"a":{"timestamp": "1638253518999", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'RFC822Z')
	`,
			outkey: "ts",
			expect: "30 Nov 21 14:25 +0800",
			fail:   false,
		},
		{
			name: "RFC822Z s",
			in:   `{"a":{"timestamp": "1638253518", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'RFC822Z')
	`,
			outkey: "ts",
			expect: "30 Nov 21 14:25 +0800",
			fail:   false,
		},
		{
			name: "RFC850 ms",
			in:   `{"a":{"timestamp": "1638253518999", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'RFC850')
	`,
			outkey: "ts",
			expect: "Tuesday, 30-Nov-21 14:25:18 CST",
			fail:   false,
		},
		{
			name: "RFC850 s",
			in:   `{"a":{"timestamp": "1638253518", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'RFC850')
	`,
			outkey: "ts",
			expect: "Tuesday, 30-Nov-21 14:25:18 CST",
			fail:   false,
		},
		{
			name: "RFC1123 ms",
			in:   `{"a":{"timestamp": "1638253518999", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'RFC1123')
	`,
			outkey: "ts",
			expect: "Tue, 30 Nov 2021 14:25:18 CST",
			fail:   false,
		},
		{
			name: "RFC1123 s",
			in:   `{"a":{"timestamp": "1638253518", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'RFC1123')
	`,
			outkey: "ts",
			expect: "Tue, 30 Nov 2021 14:25:18 CST",
			fail:   false,
		},
		{
			name: "RFC1123Z ms",
			in:   `{"a":{"timestamp": "1638253518999", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'RFC1123Z')
	`,
			outkey: "ts",
			expect: "Tue, 30 Nov 2021 14:25:18 +0800",
			fail:   false,
		},
		{
			name: "RFC1123Z s",
			in:   `{"a":{"timestamp": "1638253518", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'RFC1123Z')
	`,
			outkey: "ts",
			expect: "Tue, 30 Nov 2021 14:25:18 +0800",
			fail:   false,
		},
		{
			name: "RFC3339 s",
			in:   `{"a":{"timestamp": "1610960605", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'RFC3339')
	`,
			outkey: "ts",
			expect: "2021-01-18T17:03:25+08:00",
			fail:   false,
		},
		{
			name: "RFC3339 ms",
			in:   `{"a":{"timestamp": "1610960605000", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'RFC3339')
	`,
			outkey: "ts",
			expect: "2021-01-18T17:03:25+08:00",
			fail:   false,
		},
		{
			name: "RFC3339Nano s",
			in:   `{"a":{"timestamp": "1610960605", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'RFC3339Nano')
	`,
			outkey: "ts",
			expect: "2021-01-18T17:03:25+08:00",
			fail:   false,
		},
		{
			name: "RFC3339Nano ms",
			in:   `{"a":{"timestamp": "1610960605001", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'RFC3339Nano')
	`,
			outkey: "ts",
			expect: "2021-01-18T17:03:25.001+08:00",
			fail:   false,
		},
		{
			name: "Kitchen ms",
			in:   `{"a":{"timestamp": "1610960605001", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 'ms', 'Kitchen')
	`,
			outkey: "ts",
			expect: "5:03PM",
			fail:   true,
		},
		{
			name: "Kitchen s",
			in:   `{"a":{"timestamp": "1610960605", "second":2},"age":47}`,
			pl: `
	input = load_json(_); ts = input["a"]["timestamp"];
	datetime(ts, 's', 'Kitchen')
	`,
			outkey: "ts",
			expect: "5:03PM",
			fail:   true,
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
				t.Error(err)
				return
			}
			t.Log(f)
			v := f[tc.outkey]
			assert.Equal(t, tc.expect, v)
			t.Logf("[%d] PASS", idx)
		})
	}
}
