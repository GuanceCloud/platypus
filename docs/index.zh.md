# 概述

[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat&logo=github&color=2370ff&labelColor=454545)](http://makeapullrequest.com)
[![Go Report Card](https://goreportcard.com/badge/github.com/GuanceCloud/ppl)](https://goreportcard.com/report/github.com/GuanceCloud/ppl)
[![Downloads](https://img.shields.io/github/downloads/GuanceCloud/ppl/total.svg)](https://github.com/GuanceCloud/ppl/releases)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/6660/badge)](https://bestpractices.coreinfrastructure.org/projects/6660)


## 什么是 PPL

Guance Cloud PPL（Pipeline Processor Language）是一种用于数据处理的领域特定语言，主要用于文本和半结构化数据处理。 PPL 可在边缘节点进行大规模数据解析和特征提取。 支持 Grok、JSON 和 XML 等多种提取方法。
PPL作为一种数据处理语言，极大地提高了文本和半结构化数据处理的可编程性。

## 快速开始

### 构建 PPL 工具

使用 go build 构建 ppl 命令行工具，并将 ppl 工具拷贝至 /usr/local/bin 目录下

```sh
go build cmd/ppl/ppl.go
sudo cp ppl /usr/local/bin
```

### PPL 工具使用方法

由于 ppl 支持脚本间的引用，所以需要指定工作目录，默认为启动 ppl 命令时的目录作为其工作目录

其中 `-s` 参数为必须传入的参数，在未指定输入时，仅检查脚本是否合法

ppl 工具支持的输入的数据协议:

- `lineprotocol` 更多关于行协议信息见：[influxdb line-protocol](https://docs.influxdata.com/influxdb/cloud/reference/syntax/line-protocol/)
- `text` 文本数据，可以是日志，json 等，将作为行协议 field 部分的 message 字段作为输入

输出的数据协议:

- `lineprotocol`
- `json` 行协议的 json 表示

```sh
Usage:
  ppl run [flags]

Flags:
  -h, --help                 help for run
  -i, --input string         input data file path
      --output-type string   result output type: json, lineprotocol (default "json")
  -s, --script string        script name
  -t, --type string          data source type: text, lineprotocol (default "text")
  -w, --workspace string     ppl workspace directory (default "/path/to/ppl-process-working-dir")
```

### 编写第一个 PPL 脚本

> 内置函数文档： [pkg/engine/funcs/md](pkg/engine/funcs/md)
> grok 文档： [docs/grok.md](docs/grok.md)

创建一个 `nginx_access_log.data`，并写入以下日志内容：

```text
207.46.13.28 - - [19/Oct/2022:02:25:59 +0000] "GET / HTTP/2.0" 200 5 "-" "Mozilla/5.0 (compatible; bingbot/2.0; +http://www.bing.com/bingbot.htm)"
```

创建一个 `nginx_access_log.ppl`，并将以下内容写入脚本中：

```txt
# access log
add_pattern("access_common", "%{NOTSPACE:client_ip} %{NOTSPACE:http_ident} %{NOTSPACE:http_auth} \\[%{HTTPDATE:time}\\] \"%{DATA:http_method} %{GREEDYDATA:http_url} HTTP/%{NUMBER:http_version}\" %{INT:status_code:int} %{INT:bytes:int}")

grok(_, '%{access_common} "%{NOTSPACE:referrer}" "%{GREEDYDATA:agent}"')

user_agent(agent)

group_between(status_code, [200,299], "OK", status)
group_between(status_code, [300,399], "notice", status)
group_between(status_code, [400,499], "warning", status)
group_between(status_code, [500,599], "error", status)

nullif(http_ident, "-")
nullif(http_auth, "-")
nullif(upstream, "")

default_time(time)
```

执行 ppl 工具：

```sh
ppl@GuanceCloud:~/go/src/github.com/GuanceCloud/ppl/scripts/test_nginx_access_log$ ppl run -s nginx_access_log.ppl -i nginx_access_log.data 
{
  "fields": {
    "agent": "Mozilla/5.0 (compatible; bingbot/2.0; +http://www.bing.com/bingbot.htm)",
    "browser": "bingbot",
    "browserVer": "2.0",
    "bytes": 5,
    "client_ip": "207.46.13.28",
    "engine": "",
    "engineVer": "",
    "http_method": "GET",
    "http_url": "/",
    "http_version": "2.0",
    "isBot": true,
    "isMobile": false,
    "message": "207.46.13.28 - - [19/Oct/2022:02:25:59 +0000] \"GET / HTTP/2.0\" 200 5 \"-\" \"Mozilla/5.0 (compatible; bingbot/2.0; +http://www.bing.com/bingbot.htm)\"",
    "os": "",
    "referrer": "-",
    "status": "OK",
    "status_code": 200,
    "ua": ""
  },
  "measurement": "default_name",
  "tags": {},
  "time": "2022-10-19T10:25:59+08:00"
}
```

## PPL 语法

语法文档见 [docs/pipeline.md](docs/pipeline.md)
