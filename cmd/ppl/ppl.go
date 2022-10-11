package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"os"
	"time"

	"github.com/GuanceCloud/ppl/pkg/engine"
	"github.com/GuanceCloud/ppl/pkg/engine/funcs"
	plruntime "github.com/GuanceCloud/ppl/pkg/engine/runtime"
	"github.com/influxdata/influxdb1-client/models"
	influxdb "github.com/influxdata/influxdb1-client/v2"
	"github.com/spf13/cobra"
)

type Option struct {
	Wksp       string
	Script     string
	Input      string
	Type       string
	OutputType string
}

const (
	TypeLineProtocol = "lineprotocol"
	TypeText         = "text"

	OutJSON         = "json"
	OutLineProtocol = "lineprotocol"

	defaultJSONIndent = "  "
)

func main() {
	rootCmd := NewRootCmd()
	if err := rootCmd.Execute(); err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}

func NewRootCmd() *cobra.Command {
	options := Option{}
	var rootCmd = &cobra.Command{
		Use:   "ppl",
		Short: "PPL is a pipeline processor language.",
		Long:  "PPL is a pipeline processor language.",
		Run: func(cmd *cobra.Command, args []string) {
			runcScript(&options)
		},
	}

	wd, _ := os.Getwd()
	rootCmd.Flags().StringVarP(&options.Wksp, "workspace", "w", wd, "ppl workspace directory")
	rootCmd.Flags().StringVarP(&options.Script, "script", "s", "", "script name")
	rootCmd.Flags().StringVarP(&options.Input, "input", "i", "", "input data file path")
	rootCmd.Flags().StringVarP(&options.Type, "type", "t", "text", "data source type: text, lineprotocol")
	rootCmd.Flags().StringVarP(&options.OutputType, "output-type", "", "json", "result output type: json, lineprotocol")
	rootCmd.MarkFlagRequired("script")
	rootCmd.MarkFlagRequired("file")
	return rootCmd
}

func runcScript(options *Option) {
	var scriptsContent map[string]string
	var err error
	if options.Script == "" {
		fmt.Println("No script to run specified")
		return
	}

	if options.Wksp != "" {
		scriptsContent, _, err = engine.ReadPlScriptFromDir(options.Wksp)
		if err != nil {
			fmt.Println(err)
			os.Exit(1)
		}
	} else {
		name, content, err := engine.ReadPlScriptFromFile(options.Script)
		if err != nil {
			fmt.Println(err)
			os.Exit(1)
		}
		scriptsContent = map[string]string{
			name: content,
		}
	}

	scripts, errs := engine.ParseScript(scriptsContent, funcs.FuncsMap, funcs.FuncsCheckMap)

	if len(errs) > 0 {
		if err, ok := errs[options.Script]; ok {
			fmt.Println(options.Script+":", err)
			os.Exit(1)
		}
	}

	var script *plruntime.Script

	if s, ok := scripts[options.Script]; !ok {
		fmt.Println("The specified script was not found in the parsed results")
		fmt.Print(scripts)
		os.Exit(1)

	} else {
		script = s
	}

	if options.Input == "" {
		return
	}

	data, err := os.ReadFile(options.Input)

	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	var measurement string
	var tags map[string]string
	var fields map[string]any
	tn := time.Now()

	switch options.Type {
	case TypeLineProtocol:
		pts, err := models.ParsePointsWithPrecision(data, time.Now(), "")
		if err != nil {
			fmt.Println(err)
			os.Exit(1)
		}
		pt := influxdb.NewPointFrom(pts[0])

		f, err := pt.Fields()
		if err != nil {
			fmt.Println(err)
			os.Exit(1)
		}
		fields = f
		tags = pt.Tags()
		measurement = pt.Name()
		tn = pt.Time()
	case TypeText:
		measurement = "default_name"
		fields = map[string]any{
			"message": string(data)}
	default:
		fmt.Printf("unsupported data type: %s\n", options.Type)
		os.Exit(1)
	}
	var dropped bool
	measurement, tags, fields, tn, dropped, err = engine.RunScript(script, measurement, tags, fields, tn, nil)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	if dropped {
		fmt.Println("result dropped")
		os.Exit(2)
	}

	switch options.OutputType {
	case OutJSON:

		buf := bytes.NewBuffer([]byte{})
		encoder := json.NewEncoder(buf)
		encoder.SetEscapeHTML(false)
		encoder.SetIndent("", defaultJSONIndent)
		if err := encoder.Encode(map[string]any{
			"measurement": measurement,
			"tags":        tags,
			"fields":      fields,
			"time":        tn,
		}); err != nil {
			println(err)
			os.Exit(1)
		}
		fmt.Printf("%s", buf.String())
	case OutLineProtocol:
		pt, err := influxdb.NewPoint(measurement, tags, fields, tn)
		if err != nil {
			println(err)
			os.Exit(1)
		}
		println(pt.String())
	}
}
