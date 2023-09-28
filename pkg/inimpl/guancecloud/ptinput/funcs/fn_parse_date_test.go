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
)

func TestParseDate(t *testing.T) {
	now := time.Now()
	collectTime := now.Add(time.Hour * 12345)
	cases := []struct {
		name     string
		pl, in   string
		outKey   string
		expected int64
		fail     bool
	}{
		{
			name: "normal",
			pl: `
grok(_, "%{INT:hour}:%{INT:min}:%{INT:sec}\\.%{INT:msec}")
parse_date("time", "", "", "", hour, min, sec, msec, "", "", "+8")
`,
			in:     "16:40:03.290",
			outKey: "time",
			expected: time.Date(now.Year(), now.Month(), now.Day(),
				16, 40, 0o3, 290*1000*1000, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
			fail: false,
		},

		{
			name: "normal",
			pl: `
grok(_, "%{INT:hour}:%{INT:min}:%{INT:sec}\\.%{INT:msec}")
parse_date(key="time", hh=hour, mm=min, ss=sec, ms=msec, zone="+8")
`,
			in:     "16:40:03.290",
			outKey: "time",
			expected: time.Date(now.Year(), now.Month(), now.Day(),
				16, 40, 0o3, 290*1000*1000, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
			fail: false,
		},

		{
			name: "normal",
			pl: `
grok(_, "%{INT:year}-%{INT:month}-%{INT:day} %{INT:hour}:%{INT:min}:%{INT:sec}\\.%{INT:msec}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, ms=msec, zone="+8")
`,
			in:     "2020-12-12 16:40:03.290",
			outKey: "time",
			expected: time.Date(2020, 12, 12,
				16, 40, 0o3, 290*1000*1000, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
			fail: false,
		},

		{
			name: "normal",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day} %{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:     "Mon Sep  6 16:40:03 CST 2021",
			outKey: "time",
			expected: time.Date(2021, 9, 6,
				16, 40, 0o3, 0, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
			fail: false,
		},

		{
			name: "normal",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day}\\s+%{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:     "Mon Sep  6 16:40:03 CST 2021",
			outKey: "time",
			expected: time.Date(2021, 9, 6,
				16, 40, 0o3, 0, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
			fail: false,
		},

		{
			name: "partial year",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day}\\s+%{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:     "Mon Sep  6 16:40:03 CST 00",
			outKey: "time",
			expected: time.Date(2000, 9, 6,
				16, 40, 0o3, 0, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
		},

		{
			name: "partial year",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day}\\s+%{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:     "Mon Sep  6 16:40:03 CST 09",
			outKey: "time",
			expected: time.Date(2009, 9, 6,
				16, 40, 0o3, 0, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
		},

		{
			name: "us",
			pl: `
grok(_, "%{INT:hour}:%{INT:min}:%{INT:sec}\\.%{INT:us}")
parse_date("time", "", "", "", hour, min, sec, "", us, "", "+8")
`,
			in:     "16:40:03.290290",
			outKey: "time",
			expected: time.Date(now.Year(), now.Month(), now.Day(),
				16, 40, 0o3, 290290*1000, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
		},

		{
			name: "ns",
			pl: `
grok(_, "%{INT:hour}:%{INT:min}:%{INT:sec}\\.%{INT:ns}")
parse_date("time", "", "", "", hour, min, sec, "", "", ns, "+8")
`,
			in:     "16:40:03.290290330",
			outKey: "time",
			expected: time.Date(now.Year(), now.Month(), now.Day(),
				16, 40, 0o3, 290290330, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
		},

		{
			name: "ns for kwargs",
			pl: `
grok(_, "%{INT:hour}:%{INT:min}:%{INT:sec}\\.%{INT:ns}")
parse_date(key="time", hh=hour, mm=min, ss=sec, ns=ns, zone="CST")
`,
			in:     "16:40:03.290290330",
			outKey: "time",
			expected: time.Date(now.Year(), now.Month(), now.Day(),
				16, 40, 0o3, 290290330, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
		},

		{
			name: "missed second: use 0",
			pl: `
grok(_, "%{INT:hour}:%{INT:min}")
parse_date(key="time", hh=hour, mm=min, zone="CST")`,
			in:     "16:40",
			outKey: "time",
			expected: time.Date(now.Year(), now.Month(), now.Day(),
				16, 40, 0o0, 0, time.FixedZone("UTC+8", 8*60*60)).UnixNano(),
		},

		{
			name: "normal",
			pl: `
grok(_, "%{INT:hour}:%{INT:min}:%{INT:sec}\\.%{INT:msec}")
parse_date("time", "", "", "", hour, min, sec, msec, "", "", "")
`,
			in:     "16:40:03.290",
			outKey: "time",
			expected: time.Date(now.Year(), now.Month(), now.Day(),
				16, 40, 0o3, 290*1000*1000, time.FixedZone("UTC", 0)).UnixNano(),
			fail: false,
		},

		{
			name: "invalid hour",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day}\\s+%{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:       "Mon Sep  6 25:40:03 CST 2021",
			expected: collectTime.UnixNano(),
			fail:     true,
		},

		{
			name: "invalid hour",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day}\\s+%{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:       "Mon Sep  6 -2:40:03 CST 2021",
			expected: collectTime.UnixNano(),
			fail:     true,
		},

		{
			name: "invalid minute",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day}\\s+%{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:       "Mon Sep  6 12:61:03 CST 2021",
			expected: collectTime.UnixNano(),
			fail:     true,
		},

		{
			name: "invalid minute",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day}\\s+%{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:       "Mon Sep  6 12:60:03 CST 2021",
			expected: collectTime.UnixNano(),
			fail:     true,
		},

		{
			name: "invalid second",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day}\\s+%{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:       "Mon Sep  6 12:11:61 CST 2021",
			expected: collectTime.UnixNano(),
			fail:     true,
		},

		{
			name: "invalid minute",
			pl: `
grok(_, "%{NOTSPACE:wd}\\s+%{NOTSPACE:month}\\s+%{INT:day}\\s+%{INT:hour}:%{INT:min}:%{INT:sec}\\s+%{NOTSPACE:tz}\\s+%{INT:year}")
parse_date(key="time", yy=year, MM=month, dd=day, hh=hour, mm=min, ss=sec, zone=tz)
`,
			in:       "Mon Sep  6 12:12:-1 CST 2021",
			expected: collectTime.UnixNano(),
			fail:     true,
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

			pt := ptinput.NewPlPoint(
				point.Logging, "test", nil, map[string]any{"message": tc.in}, time.Now())
			errR := runScript(runner, pt)

			if errR != nil {
				if tc.fail {
					t.Logf("[%d]expect error: %s", idx, errR.Error())
				} else {
					t.Error(errR.Error())
				}
			} else {
				pt.KeyTime2Time()
				var v interface{}
				if tc.outKey != "time" && tc.outKey != "" {
					v, _, _ = pt.Get(tc.outKey)
				} else {
					v = pt.PtTime().UnixNano()
				}
				tu.Equals(t, tc.expected, v)
				t.Logf("[%d] PASS", idx)
			}
		})
	}
}
