package logger

import (
	"go.uber.org/zap"
	"go.uber.org/zap/zapcore"
)

const (
	NameKeyMod   = "mod"
	NameKeyMsg   = "msg"
	NameKeyLevel = "lev"
	NameKeyTime  = "ts"
	NameKeyPos   = "pos"
)

type Logger interface {
	Debug(args ...interface{})
	Debugf(format string, args ...interface{})

	Info(args ...interface{})
	Infof(format string, args ...interface{})

	Warn(args ...interface{})
	Warnf(format string, args ...interface{})

	Error(args ...interface{})
	Errorf(format string, args ...interface{})

	Fatal(args ...interface{})
	Fatalf(format string, args ...interface{})
}

func NewStdoutLogger(name, level string) Logger {
	cfg := &zap.Config{
		Level:    zap.NewAtomicLevelAt(zapcore.DebugLevel),
		Encoding: `json`,
		EncoderConfig: zapcore.EncoderConfig{
			NameKey:    NameKeyMod,
			MessageKey: NameKeyMsg,
			LevelKey:   NameKeyLevel,
			TimeKey:    NameKeyTime,
			CallerKey:  NameKeyPos,

			EncodeLevel:  zapcore.CapitalLevelEncoder,
			EncodeTime:   zapcore.ISO8601TimeEncoder,
			EncodeCaller: zapcore.FullCallerEncoder,
		},
	}

	l, err := cfg.Build()
	if err != nil {
		panic(err)
	}

	return l.Sugar().Named(name)
}
