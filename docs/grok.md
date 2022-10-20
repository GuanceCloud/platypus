# Grok

## Grok Pattern

PPL 中 grok pattern 可以分为两类：

- 内置模式：内置 pattern，所有 pipeline 脚本都可使用
- 局部模式：在 ppl 脚本中通过 add_pattern() 函数新增的模式为局部模式，只针对当前 pipeline 脚本有效

以下以 Nginx access-log 为例，说明一下如何编写对应的 grok，原始 nginx access log 如下：

```log
127.0.0.1 - - [26/May/2022:20:53:52 +0800] "GET /server_status HTTP/1.1" 404 134 "-" "Go-http-client/1.1"
```

假设我们需要从该访问日志中获取 client_ip、time (request)、http_method、http_url、http_version、status_code 这些内容，那么 grok pattern 可以写成:

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

### Grok 组合

grok 本质是预定义一些正则表达式来进行文本匹配提取，并且给预定义的正则表达式进行命名，方便使用与嵌套引用扩展出无数个新模式。比如 PPL 有 3 个如下内置模式：

```python
_second (?:(?:[0-5]?[0-9]|60)(?:[:.,][0-9]+)?)    # 匹配秒数，_second为模式名
_minute (?:[0-5][0-9])                            # 匹配分钟数，_minute为模式名
_hour (?:2[0123]|[01]?[0-9])                      # 匹配年份，_hour为模式名
```

基于上面三个内置模式，可以扩展出自己内置模式且命名为 `time`:

```python
# 把 time 加到 pattern 目录下文件中，此模式为全局模式，任何地方都能引用 time
time ([^0-9]?)%{hour:hour}:%{minute:minute}(?::%{second:second})([^0-9]?)

# 也可以通过 add_pattern() 添加到 pipeline 文件中，则此模式变为局部模式，只有当前 pipeline 脚本能使用 time
add_pattern(time, "([^0-9]?)%{HOUR:hour}:%{MINUTE:minute}(?::%{SECOND:second})([^0-9]?)")

# 通过 grok 提取原始输入中的时间字段。假定输入为 12:30:59，则提取到 {"hour": 12, "minute": 30, "second": 59}
grok(_, %{time})
```

注意事项：

- 如果出现同名模式，则以局部模式优先（即局部模式覆盖全局模式）
- pipeline 脚本中，`add_pattern` 函数需在 `grok` 函数前面调用，否则会导致第一条数据提取失败

### 内置的 Pattern 列表

我们在使用 Grok 切割的时候，可以直接使用内置的 Grok Pattern：

```
USERNAME             : [a-zA-Z0-9._-]+
USER                 : %{USERNAME}
EMAILLOCALPART       : [a-zA-Z][a-zA-Z0-9_.+-=:]+
EMAILADDRESS         : %{EMAILLOCALPART}@%{HOSTNAME}
HTTPDUSER            : %{EMAILADDRESS}|%{USER}
INT                  : (?:[+-]?(?:[0-9]+))
BASE10NUM            : (?:[+-]?(?:[0-9]+(?:\.[0-9]+)?)|\.[0-9]+)
NUMBER               : (?:%{BASE10NUM})
BASE16NUM            : (?:0[xX]?[0-9a-fA-F]+)
POSINT               : \b(?:[1-9][0-9]*)\b
NONNEGINT            : \b(?:[0-9]+)\b
WORD                 : \b\w+\b
NOTSPACE             : \S+
SPACE                : \s*
DATA                 : .*?
GREEDYDATA           : .*
GREEDYLINES          : (?s).*
QUOTEDSTRING         : "(?:[^"\\]*(?:\\.[^"\\]*)*)"|\'(?:[^\'\\]*(?:\\.[^\'\\]*)*)\'
UUID                 : [A-Fa-f0-9]{8}-(?:[A-Fa-f0-9]{4}-){3}[A-Fa-f0-9]{12}
MAC                  : (?:%{CISCOMAC}|%{WINDOWSMAC}|%{COMMONMAC})
CISCOMAC             : (?:(?:[A-Fa-f0-9]{4}\.){2}[A-Fa-f0-9]{4})
WINDOWSMAC           : (?:(?:[A-Fa-f0-9]{2}-){5}[A-Fa-f0-9]{2})
COMMONMAC            : (?:(?:[A-Fa-f0-9]{2}:){5}[A-Fa-f0-9]{2})
IPV6                 : (?:(?:(?:[0-9A-Fa-f]{1,4}:){7}(?:[0-9A-Fa-f]{1,4}|:))|(?:(?:[0-9A-Fa-f]{1,4}:){6}(?::[0-9A-Fa-f]{1,4}|(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3})|:))|(?:(?:[0-9A-Fa-f]{1,4}:){5}(?:(?:(?::[0-9A-Fa-f]{1,4}){1,2})|:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3})|:))|(?:(?:[0-9A-Fa-f]{1,4}:){4}(?:(?:(?::[0-9A-Fa-f]{1,4}){1,3})|(?:(?::[0-9A-Fa-f]{1,4})?:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:))|(?:(?:[0-9A-Fa-f]{1,4}:){3}(?:(?:(?::[0-9A-Fa-f]{1,4}){1,4})|(?:(?::[0-9A-Fa-f]{1,4}){0,2}:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:))|(?:(?:[0-9A-Fa-f]{1,4}:){2}(?:(?:(?::[0-9A-Fa-f]{1,4}){1,5})|(?:(?::[0-9A-Fa-f]{1,4}){0,3}:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:))|(?:(?:[0-9A-Fa-f]{1,4}:){1}(?:(?:(?::[0-9A-Fa-f]{1,4}){1,6})|(?:(?::[0-9A-Fa-f]{1,4}){0,4}:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:))|(?::(?:(?:(?::[0-9A-Fa-f]{1,4}){1,7})|(?:(?::[0-9A-Fa-f]{1,4}){0,5}:(?:(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]?\d)){3}))|:)))(?:%.+)?
IPV4                 : (?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)
IP                   : (?:%{IPV6}|%{IPV4})
HOSTNAME             : \b(?:[0-9A-Za-z][0-9A-Za-z-]{0,62})(?:\.(?:[0-9A-Za-z][0-9A-Za-z-]{0,62}))*(?:\.?|\b)
HOST                 : %{HOSTNAME}
IPORHOST             : (?:%{IP}|%{HOSTNAME})
HOSTPORT             : %{IPORHOST}:%{POSINT}
PATH                 : (?:%{UNIXPATH}|%{WINPATH})
UNIXPATH             : (?:/[\w_%!$@:.,-]?/?)(?:\S+)?
TTY                  : (?:/dev/(?:pts|tty(?:[pq])?)(?:\w+)?/?(?:[0-9]+))
WINPATH              : (?:[A-Za-z]:|\\)(?:\\[^\\?*]*)+
URIPROTO             : [A-Za-z]+(?:\+[A-Za-z+]+)?
URIHOST              : %{IPORHOST}(?::%{POSINT:port})?
URIPATH              : (?:/[A-Za-z0-9$.+!*'(){},~:;=@#%_\-]*)+
URIPARAM             : \?[A-Za-z0-9$.+!*'|(){},~@#%&/=:;_?\-\[\]<>]*
URIPATHPARAM         : %{URIPATH}(?:%{URIPARAM})?
URI                  : %{URIPROTO}://(?:%{USER}(?::[^@]*)?@)?(?:%{URIHOST})?(?:%{URIPATHPARAM})?
MONTH                : \b(?:Jan(?:uary|uar)?|Feb(?:ruary|ruar)?|M(?:a|ä)?r(?:ch|z)?|Apr(?:il)?|Ma(?:y|i)?|Jun(?:e|i)?|Jul(?:y)?|Aug(?:ust)?|Sep(?:tember)?|O(?:c|k)?t(?:ober)?|Nov(?:ember)?|De(?:c|z)(?:ember)?)\b
MONTHNUM             : (?:0?[1-9]|1[0-2])
MONTHNUM2            : (?:0[1-9]|1[0-2])
MONTHDAY             : (?:(?:0[1-9])|(?:[12][0-9])|(?:3[01])|[1-9])
DAY                  : (?:Mon(?:day)?|Tue(?:sday)?|Wed(?:nesday)?|Thu(?:rsday)?|Fri(?:day)?|Sat(?:urday)?|Sun(?:day)?)
YEAR                 : (\d\d){1,2}
HOUR                 : (?:2[0123]|[01]?[0-9])
MINUTE               : (?:[0-5][0-9])
SECOND               : (?:(?:[0-5]?[0-9]|60)(?:[:.,][0-9]+)?)
TIME                 : (?:[^0-9]?)%{HOUR}:%{MINUTE}(?::%{SECOND})(?:[^0-9]?)
DATE_US              : %{MONTHNUM}[/-]%{MONTHDAY}[/-]%{YEAR}
DATE_EU              : %{MONTHDAY}[./-]%{MONTHNUM}[./-]%{YEAR}
ISO8601_TIMEZONE     : (?:Z|[+-]%{HOUR}(?::?%{MINUTE}))
ISO8601_SECOND       : (?:%{SECOND}|60)
TIMESTAMP_ISO8601    : %{YEAR}-%{MONTHNUM}-%{MONTHDAY}[T ]%{HOUR}:?%{MINUTE}(?::?%{SECOND})?%{ISO8601_TIMEZONE}?
DATE                 : %{DATE_US}|%{DATE_EU}
DATESTAMP            : %{DATE}[- ]%{TIME}
TZ                   : (?:[PMCE][SD]T|UTC)
DATESTAMP_RFC822     : %{DAY} %{MONTH} %{MONTHDAY} %{YEAR} %{TIME} %{TZ}
DATESTAMP_RFC2822    : %{DAY}, %{MONTHDAY} %{MONTH} %{YEAR} %{TIME} %{ISO8601_TIMEZONE}
DATESTAMP_OTHER      : %{DAY} %{MONTH} %{MONTHDAY} %{TIME} %{TZ} %{YEAR}
DATESTAMP_EVENTLOG   : %{YEAR}%{MONTHNUM2}%{MONTHDAY}%{HOUR}%{MINUTE}%{SECOND}
HTTPDERROR_DATE      : %{DAY} %{MONTH} %{MONTHDAY} %{TIME} %{YEAR}
SYSLOGTIMESTAMP      : %{MONTH} +%{MONTHDAY} %{TIME}
PROG                 : [\x21-\x5a\x5c\x5e-\x7e]+
SYSLOGPROG           : %{PROG:program}(?:\[%{POSINT:pid}\])?
SYSLOGHOST           : %{IPORHOST}
SYSLOGFACILITY       : <%{NONNEGINT:facility}.%{NONNEGINT:priority}>
HTTPDATE             : %{MONTHDAY}/%{MONTH}/%{YEAR}:%{TIME} %{INT}
QS                   : %{QUOTEDSTRING}
SYSLOGBASE           : %{SYSLOGTIMESTAMP:timestamp} (?:%{SYSLOGFACILITY} )?%{SYSLOGHOST:logsource} %{SYSLOGPROG}:
COMMONAPACHELOG      : %{IPORHOST:clientip} %{HTTPDUSER:ident} %{USER:auth} \[%{HTTPDATE:timestamp}\] "(?:%{WORD:verb} %{NOTSPACE:request}(?: HTTP/%{NUMBER:httpversion})?|%{DATA:rawrequest})" %{NUMBER:response} (?:%{NUMBER:bytes}|-)
COMBINEDAPACHELOG    : %{COMMONAPACHELOG} %{QS:referrer} %{QS:agent}
HTTPD20_ERRORLOG     : \[%{HTTPDERROR_DATE:timestamp}\] \[%{LOGLEVEL:loglevel}\] (?:\[client %{IPORHOST:clientip}\] ){0,1}%{GREEDYDATA:errormsg}
HTTPD24_ERRORLOG     : \[%{HTTPDERROR_DATE:timestamp}\] \[%{WORD:module}:%{LOGLEVEL:loglevel}\] \[pid %{POSINT:pid}:tid %{NUMBER:tid}\]( \(%{POSINT:proxy_errorcode}\)%{DATA:proxy_errormessage}:)?( \[client %{IPORHOST:client}:%{POSINT:clientport}\])? %{DATA:errorcode}: %{GREEDYDATA:message}
HTTPD_ERRORLOG       : %{HTTPD20_ERRORLOG}|%{HTTPD24_ERRORLOG}
LOGLEVEL             : (?:[Aa]lert|ALERT|[Tt]race|TRACE|[Dd]ebug|DEBUG|[Nn]otice|NOTICE|[Ii]nfo|INFO|[Ww]arn?(?:ing)?|WARN?(?:ING)?|[Ee]rr?(?:or)?|ERR?(?:OR)?|[Cc]rit?(?:ical)?|CRIT?(?:ICAL)?|[Ff]atal|FATAL|[Ss]evere|SEVERE|EMERG(?:ENCY)?|[Ee]merg(?:ency)?)
COMMONENVOYACCESSLOG : \[%{TIMESTAMP_ISO8601:timestamp}\] \"%{DATA:method} (?:%{URIPATH:uri_path}(?:%{URIPARAM:uri_param})?|%{DATA:}) %{DATA:protocol}\" %{NUMBER:status_code} %{DATA:response_flags} %{NUMBER:bytes_received} %{NUMBER:bytes_sent} %{NUMBER:duration} (?:%{NUMBER:upstream_service_time}|%{DATA:tcp_service_time}) \"%{DATA:forwarded_for}\" \"%{DATA:user_agent}\" \"%{DATA:request_id}\" \"%{DATA:authority}\" \"%{DATA:upstream_service}\"
```
