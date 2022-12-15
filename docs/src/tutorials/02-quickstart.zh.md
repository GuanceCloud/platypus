# 快速开始

## 环境准备

1. [安装 Platypus](./01-install.md)

## 编写第一个 Platypus 程序

由于 Platypus 支持脚本间的引用，所以需要指定工作目录，默认以启动 `platypus` 命令时的目录作为其工作目录。

创建一个 `nginx_access_log.data`，并写入以下日志内容：

```
207.46.13.28 - - [19/Oct/2022:02:25:59 +0000] "GET / HTTP/2.0" 200 5 "-" "Mozilla/5.0 (compatible; bingbot/2.0; +http://www.bing.com/bingbot.htm)"
```

创建一个 `nginx_access_log.p`，并将以下内容写入脚本中：

```python
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

执行 Platypus 程序：

```shell
platypus run -s nginx_access_log.p -i nginx_access_log.data
```

其中 `-s` 参数为必须传入的参数，在未指定输入时，仅检查脚本是否合法

platypus 工具支持的输入的数据协议:

- `lineprotocol` 更多关于行协议信息见：[InfluxDB line-protocol](https://docs.influxdata.com/influxdb/cloud/reference/syntax/line-protocol/)
- `text` 文本数据，可以是日志，json 等，将作为行协议 field 部分的 message 字段作为输入

输出的数据协议:

- `lineprotocol`
- `json` 行协议的 json 表示

输出：

```json
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

## 更进一步

如果您希望了解更多关于 Platypus 的信息，可以参考以下内容：

1. [语法文档](../references/01-syntax-spec.md)
2. [内置函数文档](https://github.com/GuanceCloud/ppl/blob/main/pkg/inimpl/guancecloud/funcs/md/fn.md)
3. [Grok 文档](../references/02-grok.md)
