// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package refertable

import (
	"context"
	"database/sql"
	"fmt"
	"io"
	"net"
	"net/http"
	"net/url"
	"strings"
	"time"

	"github.com/GuanceCloud/cliutils/logger"
	"github.com/hashicorp/go-retryablehttp"
)

var (
	_plReferTables PlReferTables
	_runner        = &Runner{
		initFinished: make(chan struct{}),
	}

	l = logger.DefaultSLogger("refer-table")
)

const (
	SchemeHTTP  = "http"
	SchemeHTTPS = "https"
)

func QueryReferTable(tableName string, colName []string, colValue []any,
	selected []string,
) (map[string]any, bool) {
	defer func() {
		if err := recover(); err != nil {
			l.Error(fmt.Errorf("run pl: %s", err))
		}
	}()

	if _plReferTables == nil {
		return nil, false
	}

	return _plReferTables.query(tableName, colName, colValue, selected)
}

func Stats() *ReferTableStats {
	if _plReferTables == nil {
		return nil
	}
	return _plReferTables.stats()
}

func InitFinished(interval time.Duration) bool {
	return _runner.InitFinished(interval)
}

type InConfig struct {
	URL      string        `toml:"url"`
	Interval time.Duration `toml:"interval"`
}

type Runner struct {
	inConfig InConfig

	cli *retryablehttp.Client

	initFinished chan struct{}
}

func (r *Runner) InitFinished(interval time.Duration) bool {
	ticker := time.NewTicker(interval)

	if r.initFinished == nil {
		return false
	}

	select {
	case <-r.initFinished:
		return true
	case <-ticker.C:
		return false
	}
}

func InitLog() {
	l = logger.SLogger("refer-table")
}

func InitReferTableRunner(ctx context.Context, tableURL, dbPath string, interval time.Duration, useSQLite bool, sqliteMemMode bool) error {
	if useSQLite {
		if sqliteMemMode {
			l.Infof("using in-memory SQLite for refer-table")
			d, err := sql.Open("sqlite", ":memory:")
			if err != nil {
				return fmt.Errorf("open in-memory SQLite failed: %w", err)
			}
			_plReferTables = &PlReferTablesSqlite{db: d}
		} else {
			l.Infof("using on-disk SQLite for refer-table")
			d, err := sql.Open("sqlite", dbPath)
			if err != nil {
				return fmt.Errorf("open SQLite at %s failed: %w", dbPath, err)
			}
			_plReferTables = &PlReferTablesSqlite{db: d}
		}
	} else {
		l.Infof("using memory mode for refer-table")
		_plReferTables = &PlReferTablesInMemory{}
	}
	return initReferTableRunner(ctx, _runner, _plReferTables, tableURL, interval)
}

func initReferTableRunner(ctx context.Context, runner *Runner, plRefTables PlReferTables, tableURL string, interval time.Duration) error {
	if tableURL == "" {
		return nil
	}
	if runner == nil {
		return fmt.Errorf("runner == nil")
	}

	if interval < time.Second*10 {
		interval = time.Second * 10
	}

	runner.inConfig.Interval = interval

	scheme, err := checkURL(tableURL)
	if err != nil {
		l.Error(err)
		return err
	}

	runner.inConfig.URL = tableURL

	switch scheme {
	case SchemeHTTP, SchemeHTTPS:
		cli := http.Client{
			Transport: &http.Transport{
				DialContext: (&net.Dialer{
					Timeout:   time.Second * 30,
					KeepAlive: time.Second * 90,
				}).DialContext,
				MaxIdleConns:          100,
				MaxConnsPerHost:       64,
				IdleConnTimeout:       time.Second * 90,
				TLSHandshakeTimeout:   time.Second * 10,
				ExpectContinueTimeout: time.Second,
			},
		}
		runner.cli = newRetryCli(&cli, time.Minute)
		go httpGetWkr(ctx, plRefTables, runner)
	}

	return nil
}

func checkURL(tableURL string) (string, error) {
	u, err := url.Parse(tableURL)
	if err != nil {
		return "", fmt.Errorf("parse url: %s, error: %w",
			tableURL, err)
	}
	scheme := strings.ToLower(u.Scheme)
	switch scheme {
	case SchemeHTTP, SchemeHTTPS:
	default:
		return "", fmt.Errorf("url: %s, unsupported scheme %s",
			tableURL, scheme)
	}
	return scheme, nil
}

func httpGetWkr(ctx context.Context, plRefTables PlReferTables, runner *Runner) {
	ticker := time.NewTicker(runner.inConfig.Interval)
	for {
		getAndUpdate(plRefTables, runner)
		select {
		case <-ticker.C:
		case <-ctx.Done():
			return
		}
	}
}

func getAndUpdate(plRefTables PlReferTables, runner *Runner) {
	if tables, err := httpGet(runner.cli, runner.inConfig.URL); err != nil {
		l.Errorf("get table data from URL: %v", err)
	} else {
		if err := plRefTables.updateAll(tables); err != nil {
			l.Errorf("failed to update tables: %v", err)
		}
	}

	select {
	case <-runner.initFinished:
	default:
		if runner.initFinished != nil {
			close(runner.initFinished)
		}
	}
}

func httpGet(cli *retryablehttp.Client, url string) ([]referTable, error) {
	resp, err := cli.Get(url)
	defer func() { _ = resp.Body.Close() }()
	if err != nil {
		return nil, err
	}

	if resp.StatusCode != http.StatusOK {
		return nil, fmt.Errorf("url: %s, status: %s", url, resp.Status)
	}

	data, err := io.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}

	tables, err := decodeJSONData(data)
	if err != nil {
		return nil, err
	}

	return tables, nil
}
