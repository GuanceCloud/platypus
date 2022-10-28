// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

// Package funcs for pipeline
package funcs

import (
	"github.com/GuanceCloud/ppl/internal/logger"
	"github.com/GuanceCloud/ppl/pkg/engine/runtime"
	"go.uber.org/zap"
)

var l logger.Logger = logger.NewStdoutLogger("funcs", "debug")

func InitLog(logger *zap.SugaredLogger) {
	l = logger
}

var FuncsMap = map[string]runtime.FuncCall{
	"grok":         Grok,
	"add_key":      AddKey,
	"add_pattern":  AddPattern,
	"cast":         Cast,
	"datetime":     DateTime,
	"default_time": DefaultTime,

	"drop_key": Dropkey,
	"exit":     Exit,
	"get_key":  Getkey,

	"len":             Len,
	"load_json":       LoadJSON,
	"rename":          Rename,
	"set_tag":         SetTag,
	"set_measurement": SetMeasurement,
	"strfmt":          Strfmt,
	"trim":            Trim,
	"uppercase":       Uppercase,
	"use":             Use,
	"url_decode":      URLDecode,

	"printf":  Printf,
	"cover":   Cover,
	"replace": Replace,
	"xml":     XML,
	// "match":                 Match,
	"sql_cover": SQLCover,
}

var FuncsCheckMap = map[string]runtime.FuncCheck{
	"grok":         GrokChecking,
	"add_key":      AddkeyChecking,
	"add_pattern":  AddPatternChecking,
	"cast":         CastChecking,
	"datetime":     DateTimeChecking,
	"default_time": DefaultTimeChecking,

	"drop_key": DropkeyChecking,
	"exit":     ExitChecking,
	"get_key":  GetkeyChecking,

	"len":       LenChecking,
	"load_json": LoadJSONChecking,

	"rename":          RenameChecking,
	"set_measurement": SetMeasurementChecking,
	"set_tag":         SetTagChecking,
	"strfmt":          StrfmtChecking,
	"trim":            TrimChecking,
	"uppercase":       UppercaseChecking,
	"use":             UseChecking,
	"url_decode":      URLDecodeChecking,

	"printf":    PrintfChecking,
	"cover":     CoverChecking,
	"replace":   ReplaceChecking,
	"sql_cover": SQLCoverChecking,
	"xml":       XMLChecking,
	// "match":                 MatchChecking,
}
