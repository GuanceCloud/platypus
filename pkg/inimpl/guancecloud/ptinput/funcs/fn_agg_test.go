// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"testing"
	"time"

	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/ptinput"
	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/ptinput/plmap"
	"github.com/stretchr/testify/assert"

	"github.com/GuanceCloud/cliutils/point"
)

func TestAgg(t *testing.T) {
	cases := []struct {
		name, pl string
		in       []string
		fail     bool
		out      map[point.Category]map[string]map[string]any
	}{
		{
			name: "",
			pl: `
				set_tag("t0", "t1111")
				set_tag("t1", "t1111")
				set_tag("t2", "t2__")
				f0 = _
				cast(f0, "int")
				agg_create("abc", on_interval="5s",on_count=0, const_tags={"a":"b"})
				agg_create("def")

				agg_metric("abc", "f1", "avg", ["t2","t0"], "f0")
				agg_metric("def", "f1", "avg", ["t1", "t2"], "f0")

				agg_create("abc", on_interval="5s",on_count=0, const_tags={"a":"b"}, 
						category="logging")
				agg_create("def", category="logging")

				agg_metric("abc", "f1", "avg", ["t2","t0"], "f0", category="logging")
				agg_metric("def", "f1", "avg", ["t1", "t2"], "f0", "logging")
				`,
			in: []string{`1`, `2`},
			out: map[point.Category]map[string]map[string]any{
				point.Metric: {
					"abc": {
						"f1": float64(1.5),
						"t0": "t1111",
					},
					"def": {
						"f1": float64(1.5),
						"t1": "t1111",
					},
				},
				point.Logging: {
					"abc": {
						"f1": float64(1.5),
						"t0": "t1111",
					},
					"def": {
						"f1": float64(1.5),
						"t1": "t1111",
					},
				},
			},
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

			ptsLi := map[point.Category]map[string][]*point.Point{}
			fn := func(cat point.Category, n string, d any) error {
				catBuk, ok := ptsLi[cat]
				if !ok {
					catBuk = map[string][]*point.Point{}
					ptsLi[cat] = catBuk
				}
				catBuk[n] = append(catBuk[n], d.([]*point.Point)...)
				return nil
			}

			buks := plmap.NewAggBuks(fn, nil)
			for _, tcIn := range tc.in {
				pt := ptinput.NewPlPoint(
					point.Logging, "test", nil, map[string]any{"message": tcIn}, time.Now())
				pt.SetAggBuckets(buks)
				errR := runScript(runner, pt)
				if errR != nil {
					t.Fatal(*errR)
				}
			}

			buks.StopAllBukScanner()

			for cat, catBuk := range tc.out {
				for bukName, kv := range catBuk {
					for k, v := range kv {
						if len(ptsLi[cat][bukName]) == 0 {
							t.Fatal("no data")
						}
						pt := ptsLi[cat][bukName][0]
						f := pt.InfluxFields()
						tags := pt.InfluxTags()
						if _, ok := f[k]; ok {
							assert.Equal(t, v, f[k])
						} else if _, ok := tags[k]; ok {
							assert.Equal(t, v, tags[k])
						} else {
							t.Error(k)
						}
					}
				}
			}
		})
	}
}
