# Overview
<!-- <div align="center">
<br/>

<img src="./docs/images/icon-color.svg" width="120">

</div> -->

[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat&logo=github&color=2370ff&labelColor=454545)](http://makeapullrequest.com)
[![Go Report Card](https://goreportcard.com/badge/github.com/GuanceCloud/platypus)](https://goreportcard.com/report/github.com/GuanceCloud/platypus)
[![Downloads](https://img.shields.io/github/downloads/GuanceCloud/platypus/total.svg)](https://github.com/GuanceCloud/platypus/releases)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/6660/badge)](https://bestpractices.coreinfrastructure.org/projects/6660)

Platypus Programming Language is a domain-specific language for data processing, mainly for text and semi-structured data processing. Platypus can be used for large-scale log parsing and feature extraction at the edge. Multiple extraction methods such as Grok, JSON and XML are supported.
As a data processing language, Platypus greatly improves the programmability of text and semi-structured processing.

## Getting Started

### Construction of Platypus Tools

Use go build to construct Platypus command lines and copy them to the directory /usr/local/bin.

```sh
go build cmd/ppl/ppl.go
sudo cp ppl /usr/local/bin
```

### Instructions of Platypus

Since platypus supports inter-script introductions, it is necessary to specify the working directory, which by default is the directory of the platypus command lines when it is started.

In addition, the parameter `-s` is a mandatory parameter and only checks if the script is legal when no entry is specified.

The input data protocol supported by the platypus tool:

- `lineprotocol`: for more information about the protocol, check [influxdb line-protocol](https://docs.influxdata.com/influxdb/cloud/reference/syntax/line-protocol/).
- `text`: text data, such as log and json, would be input as a message field in the field of line protocol.

The output data protocol:

- `lineprotocol`
- `json`: representing line protocol data in json.

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

### Edit the First Platypus Script

> Built-in functions document: [pkg/inimpl/guancecloud/funcs/md/fn.md](pkg/inimpl/guancecloud/funcs/md/fn.md)
> Grok document: [docs/grok.md](docs/grok.md)

Creat `nginx_access_log.data` and input the following logs:

```text
207.46.13.28 - - [19/Oct/2022:02:25:59 +0000] "GET / HTTP/2.0" 200 5 "-" "Mozilla/5.0 (compatible; bingbot/2.0; +http://www.bing.com/bingbot.htm)"
```

Creat `nginx_access_log.p` and input the following logs:

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

Execute platypus tools:

```sh
ppl run -s nginx_access_log.p -i nginx_access_log.data 
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

## Platypus Syntax

For more information of syntax, see [docs/pipeline.md](docs/pipeline.md).
