package run

import (
	"bytes"
	"context"
	"encoding/json"
	"errors"
	"fmt"
	"os"
	"time"

	"github.com/GuanceCloud/cliutils/point"
	"github.com/GuanceCloud/platypus/internal/logger"
	"github.com/GuanceCloud/platypus/pkg/engine"
	plruntime "github.com/GuanceCloud/platypus/pkg/engine/runtime"
	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/ptinput"
	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/ptinput/funcs"
	"github.com/influxdata/influxdb1-client/models"
	influxdb "github.com/influxdata/influxdb1-client/v2"
	"go.uber.org/zap/zapcore"
)

var l = logger.NewStdoutLogger("cli", zapcore.DebugLevel)

func Run(ctx context.Context, options *Options) error {
	if options.Script == "" {
		return errors.New("no script to run specified")
	}

	script, err := loadScript(ctx, options)
	if err != nil {
		l.Error(err)
		return nil
	}

	// check script only
	if options.Input == "" {
		return nil
	}

	if err := runScript(ctx, options, script); err != nil {
		l.Error(err)
	}

	return nil
}

func loadScript(ctx context.Context, options *Options) (*plruntime.Script, error) {
	var err error
	var scriptsContent map[string]string

	if options.Workspace != "" {
		scriptsContent, _, err = engine.ReadPlScriptFromDir(options.Workspace)
		if err != nil {
			return nil, fmt.Errorf("read script from workspace error: %w", err)
		}
	} else {
		name, content, err := engine.ReadPlScriptFromFile(options.Script)
		if err != nil {
			return nil, fmt.Errorf("read script error: %w", err)
		}
		scriptsContent = map[string]string{
			name: content,
		}
	}

	scripts, errs := engine.ParseScript(scriptsContent, funcs.FuncsMap, funcs.FuncsCheckMap)
	if len(errs) > 0 {
		if err, ok := errs[options.Script]; ok {
			return nil, err
		}
	}

	script, ok := scripts[options.Script]
	if !ok {
		l.Debug(scripts)
		return nil, fmt.Errorf("the specified script %s was not found in the parsed results", options.Script)
	}
	return script, nil
}

func runScript(ctx context.Context, options *Options, script *plruntime.Script) error {
	data, err := os.ReadFile(options.Input)
	if err != nil {
		return fmt.Errorf("read input file error: %w", err)
	}

	var name string
	var tags map[string]string
	var fields map[string]any
	tn := time.Now()

	switch options.Type {
	case TypeLineProtocol:
		pts, err := models.ParsePointsWithPrecision(data, time.Now(), "")
		if err != nil {
			return fmt.Errorf("parse line protocol error: %w", err)
		}
		pt := influxdb.NewPointFrom(pts[0])

		f, err := pt.Fields()
		if err != nil {
			return fmt.Errorf("get fields from point error: %w", err)
		}
		fields = f
		tags = pt.Tags()
		name = pt.Name()
		tn = pt.Time()
	case TypeText:
		name = "default_name"
		fields = map[string]any{"message": string(data)}
	default:
		return fmt.Errorf("unsupported input type: %s", options.Type)
	}
	var dropped bool

	pt := ptinput.NewPlPoint(point.UnknownCategory, name, tags, fields, tn)

	fields = pt.Fields()
	tags = pt.Tags()
	dropped = pt.Dropped()
	tn = pt.PtTime()
	name = pt.GetPtName()

	errR := engine.RunScriptWithRMapIn(script, pt, nil)
	if errR != nil {
		return fmt.Errorf("run script error: %w", errR)
	}

	if dropped {
		return fmt.Errorf("point dropped")
	}

	switch options.OutputType {
	case OutTypeJSON:
		buf := bytes.NewBuffer([]byte{})
		encoder := json.NewEncoder(buf)
		encoder.SetEscapeHTML(false)
		encoder.SetIndent("", defaultJSONIndent)
		if err := encoder.Encode(map[string]any{
			"measurement": name,
			"tags":        tags,
			"fields":      fields,
			"time":        tn,
		}); err != nil {
			return fmt.Errorf("encode json output error: %w", err)
		}
		l.Infof("Platypus Output Data:\n%s", buf.String())
	case OutTypeLineProtocol:
		pt, err := influxdb.NewPoint(name, tags, fields, tn)
		if err != nil {
			return fmt.Errorf("encode point output error: %w", err)
		}
		l.Infof("Platypus Output Data:\n%s", pt.String())
	}
	return nil
}
