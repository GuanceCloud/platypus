package utils

import (
	"os"

	"github.com/GuanceCloud/cliutils/point"
)

func PtCatOption(cat point.Category) []point.Option {
	var opt []point.Option
	switch cat {
	case point.Logging:
		opt = point.DefaultLoggingOptions()
	case point.Tracing,
		point.Network,
		point.KeyEvent,
		point.RUM,
		point.Security,
		point.Profiling:
		opt = point.CommonLoggingOptions()
	case point.Object,
		point.CustomObject:
		opt = point.DefaultObjectOptions()
	case point.Metric:
		opt = point.DefaultMetricOptions()
	default:
	}
	return opt
}

func FileExist(filename string) bool {
	_, err := os.Stat(filename)
	return err == nil || os.IsExist(err)
}
