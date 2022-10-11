// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

// Package geoip implement ipdb.
package geoip

import (
	"fmt"
	"net"
	"os"
	"path/filepath"

	"github.com/GuanceCloud/ppl/internal/ipdb"
	"github.com/GuanceCloud/ppl/internal/logger"
	"github.com/oschwald/geoip2-golang"
)

const INVALIDIP = "Invalid IP address"

var l logger.Logger = logger.NewStdoutLogger("iploc", "debug")

var openDB = func(f string) (*geoip2.Reader, error) {
	db, err := geoip2.Open(f)
	return db, err
}

type Geoip struct {
	db *geoip2.Reader
}

func (g *Geoip) loadIPLib(f string) error {
	if _, err := os.Stat(f); err != nil && !os.IsExist(err) {
		l.Warnf("%v not found", f)
		return nil
	}

	db, err := openDB(f)
	if err != nil {
		return err
	} else {
		g.db = db
	}

	return nil
}

func (g *Geoip) Init(dataDir string, config map[string]string, slogger ...logger.Logger) {
	if len(slogger) > 0 && slogger[0] != nil {
		l = slogger[0]
	}
	l.Debug("use geolite2 db")
	ipdbDir := filepath.Join(dataDir, "ipdb", "geolite2", "GeoLite2-City_20220617")
	ipdbFile := "GeoLite2-City.mmdb"

	if file, ok := config["geoip_file"]; ok {
		if len(file) > 0 {
			ipdbFile = file
		}
	}

	if err := g.loadIPLib(filepath.Join(ipdbDir, ipdbFile)); err != nil {
		l.Warnf("geolite2 load ip lib error: %s", err.Error())
	}
}

func (g *Geoip) Geo(ip string) (*ipdb.IPdbRecord, error) {
	record := &ipdb.IPdbRecord{}
	if g.db == nil {
		return record, nil
	}

	r, err := g.Get(ip)
	if err != nil {
		return record, err
	}
	// ip invalid
	if r == nil {
		record.City = INVALIDIP
		record.Timezone = INVALIDIP
		record.Region = INVALIDIP
		record.Country = INVALIDIP
		return record, nil
	}

	record.City = r.City.Names["en"]
	record.Timezone = r.Location.TimeZone
	if len(r.Subdivisions) != 0 {
		record.Region = r.Subdivisions[0].Names["en"]
	}
	record.Country = r.Country.Names["en"]

	return record, err
}

func (g *Geoip) Get(ip string) (*geoip2.City, error) {
	if g.db == nil {
		return nil, fmt.Errorf("GEO DB not set")
	}
	ipParse := net.ParseIP(ip)
	// ip invalid
	if ipParse == nil {
		return nil, nil
	}
	r, err := g.db.City(ipParse)
	if err != nil {
		return nil, err
	}

	return r, nil
}

func (g *Geoip) SearchIsp(ip string) string {
	return ""
}
