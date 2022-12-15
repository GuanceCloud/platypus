# Quickstart

## Environment preparation

1. [Install Platypus](./01-install.md)

## Write your first Platypus program

Since Platypus supports inter-script references, it is necessary to specify the working directory. By default, the directory when the `platypus` command is started is used as its working directory.

Create an `nginx_access_log.data` and write the following log content:

```
207.46.13.28 - - [19/Oct/2022:02:25:59 +0000] "GET / HTTP/2.0" 200 5 "-" "Mozilla/5.0 (compatible; bingbot/2.0; +http://www. bing.com/bingbot.htm)"
```

Create an `nginx_access_log.p` and write the following into the script:

```python
# access log
add_pattern("access_common", "%{NOTSPACE:client_ip} %{NOTSPACE:http_ident} %{NOTSPACE:http_auth} \\[%{HTTPDATE:time}\\] \"%{DATA:http_method} %{GREEDYDATA:http_url } HTTP/%{NUMBER:http_version}\" %{INT:status_code:int} %{INT:bytes:int}")

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

Execute the Platypus program:

```shell
platypus run -s nginx_access_log.p -i nginx_access_log.data
```

The `-s` parameter is a parameter that must be passed in. When no input is specified, only check whether the script is legal

Input data protocols supported by the platypus tool:

- `lineprotocol` For more information about line protocol see: [InfluxDB line-protocol](https://docs.influxdata.com/influxdb/cloud/reference/syntax/line-protocol/)
- `text` text data, which can be log, json, etc., will be the message field as the field part of the line protocol as input

Output data protocol:

- `lineprotocol`
- json representation of the `json` line protocol

output:

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
     "message": "207.46.13.28 - - [19/Oct/2022:02:25:59 +0000] \"GET / HTTP/2.0\" 200 5 \"-\" \"Mozilla/5.0 (compatible; bingbot /2.0; +http://www.bing.com/bingbot.htm)\"",
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

## go one step further

If you want to learn more about Platypus, you can refer to the following:

1. [Syntax Documentation](../references/01-syntax-spec.md)
2. [Built-in function documentation](https://github.com/GuanceCloud/ppl/blob/main/pkg/inimpl/guancecloud/funcs/md/fn.md)
3. [Grok Documentation](../references/02-grok.md)
