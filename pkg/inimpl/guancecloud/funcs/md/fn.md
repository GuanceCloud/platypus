# GuanceCloud Pipeline Functions

## `printf()`

函数原型：`printf(fmt=required, key1=optional, key2, ...)`

函数说明：对已提取 `key1,key2...` 指定的字段内容根据 `fmt` 进行格式化，并把格式化后的内容输出到标准输出

函数参数

- `fmt`: 格式化字符串模板
- `key1，key2`: 占位符对应的参数

示例:

```python
count = 10
printf("count: %d", count)
```

## `load_json()`

函数原型：`fn load_json(val: str) nil|bool|float|map|list`

函数说明：将 json 字符串转换成 map、list、nil、bool、float 的其中一种，可通过 index 表达式取值及修改值。

参数:

- `val`: 要求是 string 类型的数据

示例:

```python
# _: {"a":{"first": [2.2, 1.1], "ff": "[2.2, 1.1]","second":2,"third":"aBC","forth":true},"age":47}
abc = load_json(_)

add_key(abc, abc["a"]["first"][-1])

abc["a"]["first"][-1] = 11

# 需要将堆栈上的数据同步到 point 中
add_key(abc, abc["a"]["first"][-1])

add_key(len_abc, len(abc))

add_key(len_abc, len(load_json(abc["a"]["ff"])))
```

## `len()`

函数原型：`fn len(val: str|map|list) int`

函数说明：计算 string 字节数，map 和 list 的元素个数。

参数:

- `val`: 可以是 map、list 或 string

示例:

```python
# 例 1
add_key(abc, len("abc"))
# 输出
{
 "abc": 3,
}

# 例 2
add_key(abc, len(["abc"]))
#处理结果
{
  "abc": 1,
}
```

## `add_pattern()`

函数原型：`fn add_pattern(name: str, pattern: str)`

函数说明：创建自定义 grok 模式。grok 模式有作用域限制, 如在 if else 语句内将产生新的作用域, 该 pattern 仅在此作用域内有效。该函数不可覆盖同一作用域或者上一作用域已经存在的 grok 模式

参数:

- `name`：模式命名
- `pattern`: 自定义模式内容

示例:

```python
# 待处理数据: "11,abc,end1", "22,abc,end1", "33,abc,end3"

# pipline脚本
add_pattern("aa", "\\d{2}")
grok(_, "%{aa:aa}")
if false {

} else {
    add_pattern("bb", "[a-z]{3}")
    if aa == "11" {
        add_pattern("cc", "end1")
        grok(_, "%{aa:aa},%{bb:bb},%{cc:cc}")
    } elif aa == "22" {
        # 此处使用 pattern cc 将导致编译失败: no pattern found for %{cc}
        grok(_, "%{aa:aa},%{bb:bb},%{INT:cc}")
    } elif aa == "33" {
        add_pattern("bb", "[\\d]{5}")	# 此处覆盖 bb 失败
        add_pattern("cc", "end3")
        grok(_, "%{aa:aa},%{bb:bb},%{cc:cc}")
    }
}

# 处理结果
{
    "aa":      "11"
    "bb":      "abc"
    "cc":      "end1"
    "message": "11,abc,end1"
}

{
    "aa":      "22",
	"message": "22,abc,end1"
}

{
    "aa":      "33"
    "bb":      "abc"
    "cc":      "end3"
    "message": "33,abc,end3"
}
```

## `grok()`

函数原型：`fn grok(input: str, pattern: str, trim_space: bool = true) bool`

函数说明：通过 `pattern` 提取文本串 `input` 中的内容，当 pattern 匹配 input 成功时返回 true 否则返回 false。

参数:

- `input`：待提取文本，可以是原始文本（`_`）或经过初次提取之后的某个 `key`
- `pattern`: grok 表达式，表达式中支持指定 key 的数据类型：bool, float, int, string(对应 ppl 的 str，亦可写为 str)，默认为 string
- `trim_space`: 删除提取出的字符中的空白首尾字符，默认值为 true

```python
grok(_, pattern)    # 直接使用输入的文本作为原始数据
grok(key, pattern)  # 对之前已经提取出来的某个 key，做再次 grok
```

示例:

```python
# 待处理数据: "12/01/2021 21:13:14.123"

# pipline脚本
add_pattern("_second", "(?:(?:[0-5]?[0-9]|60)(?:[:.,][0-9]+)?)")
add_pattern("_minute", "(?:[0-5][0-9])")
add_pattern("_hour", "(?:2[0123]|[01]?[0-9])")
add_pattern("time", "([^0-9]?)%{_hour:hour:string}:%{_minute:minute:int}(?::%{_second:second:float})([^0-9]?)")

grok_match_ok = grok(_, "%{DATE_US:date} %{time}")

add_key(grok_match_ok)

# 处理结果
{
  "date": "12/01/2021",
  "hour": "21",
  "message": "12/01/2021 21:13:14.123",
  "minute": 13,
  "second": 14.123
}

{
  "date": "12/01/2021",
  "grok_match_ok": true,
  "hour": "21",
  "message": "12/01/2021 21:13:14.123",
  "minute": 13,
  "second": 14.123,
  "status": "unknown",
  "time": 1665994187473917724
}
```

## `add_key()`

##函数原型：`fn add_key(key, value)`

函数说明：往 point 中增加一个字段

函数参数

- `key`: 新增的 key 名称
- `value`：作为 key 的值

示例:

```python
# 待处理数据: {"age": 17, "name": "zhangsan", "height": 180}

# 处理脚本
add_key(city, "shanghai")

# 处理结果
{
    "age": 17,
    "height": 180,
    "name": "zhangsan",
    "city": "shanghai"
}
```

## `get_key()`

函数原型：`fn get_key(key)`

函数说明：从 point 中读取 key 的值，而不是堆栈上的变量的值

函数参数

- `key_name`: key 的名称

示例一:

```python
# scipt 1
key = "shanghai"
add_key(key)
key = "tokyo" 
add_key(add_new_key, key)

# 处理结果
{
  "add_new_key": "tokyo",
  "key": "shanghai",
}

```

## `set_tag()`

函数原型：`fn set_tag(key, value: str)`

函数说明：对指定字段标记为 tag 输出，设置为 tag 后，其他函数仍可对该变量操作。如果被置为 tag 的 key 是已经切割出来的 field，那么它将不会在 field 中出现，这样可以避免切割出来的 field key 跟已有数据上的 tag key 重名

函数参数

- `key`: 待标记为 tag 的字段
- `value`: 可以为字符串字面量或者变量

```python
# in << {"str": "13789123014"}
set_tag(str)
json(_, str)          # str == "13789123014"
replace(str, "(1[0-9]{2})[0-9]{4}([0-9]{4})", "$1****$2")
# Extracted data(drop: false, cost: 49.248µs):
# {
#   "message": "{\"str\": \"13789123014\", \"str_b\": \"3\"}",
#   "str#": "137****3014"
# }
# * 字符 `#` 仅为 datakit --pl <path> --txt <str> 输出展示时字段为 tag 的标记

# in << {"str_a": "2", "str_b": "3"}
json(_, str_a)
set_tag(str_a, "3")   # str_a == 3
# Extracted data(drop: false, cost: 30.069µs):
# {
#   "message": "{\"str_a\": \"2\", \"str_b\": \"3\"}",
#   "str_a#": "3"
# }


# in << {"str_a": "2", "str_b": "3"}
json(_, str_a)
json(_, str_b)
set_tag(str_a, str_b) # str_a == str_b == "3"
# Extracted data(drop: false, cost: 32.903µs):
# {
#   "message": "{\"str_a\": \"2\", \"str_b\": \"3\"}",
#   "str_a#": "3",
#   "str_b": "3"
# }
```

## `rename()`

函数原型：`fn rename(new_key, old_key)`

函数说明：将已提取的字段重新命名

参数:

- `new_key`: 新字段名
- `old_key`: 已提取的字段名

```python
# 把已提取的 abc 字段重新命名为 abc1
rename('abc1', abc)

# or 

rename(abc1, abc)
```

示例：

```python
# 待处理数据: {"info": {"age": 17, "name": "zhangsan", "height": 180}}

# 处理脚本
json(_, info.name, "姓名")

# 处理结果
{
  "message": "{\"info\": {\"age\": 17, \"name\": \"zhangsan\", \"height\": 180}}",
  "zhangsan": {
    "age": 17,
    "height": 180,
    "姓名": "zhangsan"
  }
}
```

## `set_measurement()`

函数原型：`fn set_measurement(name: str, delete_key: bool = false)`

函数说明：改变行协议的 name

函数参数

- `name`: 值作为 mesaurement name，可传入字符串常量或变量
- `delete_key`: 如果在 point 中存在与变量同名的 tag 或 field 则删除它

## `cast()`

函数原型：`fn cast(key, dst_type: str)`

函数说明：将 key 值转换成指定类型

函数参数

- `key`: 已提取的某字段
- `type`：转换的目标类型，支持 `\"str\", \"float\", \"int\", \"bool\"` 这几种，目标类型需要用英文状态双引号括起来

示例:

```python
# 待处理数据: {"first": 1,"second":2,"third":"aBC","forth":true}

# 处理脚本
json(_, first) 
cast(first, "str")

# 处理结果
{
  "first": "1"
}
```

## `default_time()`

函数原型：`fn default_time(key: str, timezone: str = "")`

函数说明：以提取的某个字段作为最终数据的时间戳

函数参数

- `key`: 指定的 key， key 的数据类型需要为字符串类型
- `timezone`: 指定待格式化的时间文本所使用的时区，可选参数，默认为当前系统时区，时区示例 `+8/-8/+8:30`

待处理数据支持以下格式化时间

| 日期格式                                           | 日期格式                                                | 日期格式                                       | 日期格式                          |
| -----                                              | ----                                                    | ----                                           | ----                              |
| `2014-04-26 17:24:37.3186369`                      | `May 8, 2009 5:57:51 PM`                                | `2012-08-03 18:31:59.257000000`                | `oct 7, 1970`                     |
| `2014-04-26 17:24:37.123`                          | `oct 7, '70`                                            | `2013-04-01 22:43`                             | `oct. 7, 1970`                    |
| `2013-04-01 22:43:22`                              | `oct. 7, 70`                                            | `2014-12-16 06:20:00 UTC`                      | `Mon Jan  2 15:04:05 2006`        |
| `2014-12-16 06:20:00 GMT`                          | `Mon Jan  2 15:04:05 MST 2006`                          | `2014-04-26 05:24:37 PM`                       | `Mon Jan 02 15:04:05 -0700 2006`  |
| `2014-04-26 13:13:43 +0800`                        | `Monday, 02-Jan-06 15:04:05 MST`                        | `2014-04-26 13:13:43 +0800 +08`                | `Mon, 02 Jan 2006 15:04:05 MST`   |
| `2014-04-26 13:13:44 +09:00`                       | `Tue, 11 Jul 2017 16:28:13 +0200 (CEST)`                | `2012-08-03 18:31:59.257000000 +0000 UTC`      | `Mon, 02 Jan 2006 15:04:05 -0700` |
| `2015-09-30 18:48:56.35272715 +0000 UTC`           | `Thu, 4 Jan 2018 17:53:36 +0000`                        | `2015-02-18 00:12:00 +0000 GMT`                | `Mon 30 Sep 2018 09:09:09 PM UTC` |
| `2015-02-18 00:12:00 +0000 UTC`                    | `Mon Aug 10 15:44:11 UTC+0100 2015`                     | `2015-02-08 03:02:00 +0300 MSK m=+0.000000001` | `Thu, 4 Jan 2018 17:53:36 +0000`  |
| `2015-02-08 03:02:00.001 +0300 MSK m=+0.000000001` | `Fri Jul 03 2015 18:04:07 GMT+0100 (GMT Daylight Time)` | `2017-07-19 03:21:51+00:00`                    | `September 17, 2012 10:09am`      |
| `2014-04-26`                                       | `September 17, 2012 at 10:09am PST-08`                  | `2014-04`                                      | `September 17, 2012, 10:10:09`    |
| `2014`                                             | `2014:3:31`                                             | `2014-05-11 08:20:13,787`                      | `2014:03:31`                      |
| `3.31.2014`                                        | `2014:4:8 22:05`                                        | `03.31.2014`                                   | `2014:04:08 22:05`                |
| `08.21.71`                                         | `2014:04:2 03:00:51`                                    | `2014.03`                                      | `2014:4:02 03:00:51`              |
| `2014.03.30`                                       | `2012:03:19 10:11:59`                                   | `20140601`                                     | `2012:03:19 10:11:59.3186369`     |
| `20140722105203`                                   | `2014年04月08日`                                        | `1332151919`                                   | `2006-01-02T15:04:05+0000`        |
| `1384216367189`                                    | `2009-08-12T22:15:09-07:00`                             | `1384216367111222`                             | `2009-08-12T22:15:09`             |
| `1384216367111222333`                              | `2009-08-12T22:15:09Z`                                  |

JSON 提取示例:

```python
# 原始 json
{
    "time":"06/Jan/2017:16:16:37 +0000",
    "second":2,
    "third":"abc",
    "forth":true
}

# pipeline 脚本
json(_, time)      # 提取 time 字段
default_time(time) # 将提取到的 time 字段转换成时间戳

# 处理结果
{
  "time": 1483719397000000000,
}
```

文本提取示例:

```python
# 原始日志文本
2021-01-11T17:43:51.887+0800  DEBUG io  io/io.go:458  post cost 6.87021ms

# pipeline 脚本
grok(_, '%{TIMESTAMP_ISO8601:log_time}')   # 提取日志时间，并将字段命名为 log_time
default_time(log_time)                     # 将提取到的 log_time 字段转换成时间戳

# 处理结果
{
  "log_time": 1610358231887000000,
}

# 对于 logging 采集的数据，最好将时间字段命名为 time，否则 logging 采集器会以当前时间填充
rename("time", log_time)

# 处理结果
{
  "time": 1610358231887000000,
}
```

## `drop_key()`

函数原型：`fn drop_key(key)`

函数说明：删除已提取字段

函数参数

- `key`: 待删除字段名

示例:

```python
data = `{\"age\": 17, \"name\": \"zhangsan\", \"height\": 180}`

# 处理脚本
json(_, age,)
json(_, name)
json(_, height)
drop_key(height)

# 处理结果
{
    "age": 17,
    "name": "zhangsan"
}
```

## `use()`

函数原型：`fn use(name: str)`

参数:

- `name`: 脚本名，如 abp.p

函数说明：调用其他脚本，可在被调用的脚本访问当前的所有数据
示例：

```python
# 待处理数据: {"ip":"1.2.3.4"}

# 处理脚本 a.p
use(\"b.p\")

# 处理脚本 b.p
json(_, ip)
geoip(ip)

# 执行脚本 a.p 的处理结果
{
  "city"     : "Brisbane",
  "country"  : "AU",
  "ip"       : "1.2.3.4",
  "province" : "Queensland",
  "isp"      : "unknown"
  "message"  : "{\"ip\": \"1.2.3.4\"}",
}
```

## `exit()`

函数原型：`fn exit()`

函数说明：结束当前一条日志的解析，若未调用函数 drop() 仍会输出已经解析的部分

```python
# in << {"str_a": "2", "str_b": "3"}
json(_, str_a)
if str_a == "2"{
  exit()
}
json(_, str_b)

# Extracted data(drop: false, cost: 48.233µs):
# {
#   "message": "{\"str_a\": \"2\", \"str_b\": \"3\"}",
#   "str_a": "2"
# }
```

示例二:

```python
# scipt 2
key = "shanghai"
add_key(key)
key = "tokyo" 
add_key(add_new_key, get_key(key))

#处理结果
{
  "add_new_key": "shanghai",
  "key": "shanghai",
}
```

## `cover()` {#fn-cover}

函数原型：`fn cover(key: str, range: list)`

函数说明：对指定字段上获取的字符串数据，按范围进行数据脱敏处理

函数参数

- `key`: 待提取字段
- `range`: 脱敏字符串的索引范围（`[start,end]`） start和end均支持负数下标，用来表达从尾部往前追溯的语义。区间合理即可，end如果大于字符串最大长度会默认成最大长度

示例:

```python
# 待处理数据 {"str": "13789123014"}
json(_, `str`)
cover(`str`, [8, 9])

# 待处理数据 {"abc": "13789123014"}
json(_, abc)
cover(abc, [2, 4])
```

## `datetime()` {#fn-datetime}

函数原型：`fn datetime(key, precision: str, fmt: str)`

函数说明：将时间戳转成指定日期格式

函数参数

- `key`: 已经提取的时间戳 (必选参数)
- `precision`：输入的时间戳精度(s, ms)
- `fmt`：日期格式，时间格式, 支持以下模版

```python
ANSIC       = "Mon Jan _2 15:04:05 2006"
UnixDate    = "Mon Jan _2 15:04:05 MST 2006"
RubyDate    = "Mon Jan 02 15:04:05 -0700 2006"
RFC822      = "02 Jan 06 15:04 MST"
RFC822Z     = "02 Jan 06 15:04 -0700" // RFC822 with numeric zone
RFC850      = "Monday, 02-Jan-06 15:04:05 MST"
RFC1123     = "Mon, 02 Jan 2006 15:04:05 MST"
RFC1123Z    = "Mon, 02 Jan 2006 15:04:05 -0700" // RFC1123 with numeric zone
RFC3339     = "2006-01-02T15:04:05Z07:00"
RFC3339Nano = "2006-01-02T15:04:05.999999999Z07:00"
Kitchen     = "3:04PM"
```

示例:

```python
# 待处理数据:
#    {
#        "a":{
#            "timestamp": "1610960605000",
#            "second":2
#        },
#        "age":47
#    }

# 处理脚本
json(_, a.timestamp) datetime(a.timestamp, 'ms', 'RFC3339')
```

## `replace()`

函数原型：`fn replace(key: str, regex: str, replace_str: str)`

函数说明：对指定字段上获取的字符串数据按正则进行替换

函数参数

- `key`: 待提取字段
- `regex`: 正则表达式
- `replace_str`: 替换的字符串

示例:

```python
# 电话号码：{"str": "13789123014"}
json(_, str)
replace(str, "(1[0-9]{2})[0-9]{4}([0-9]{4})", "$1****$2")

# 英文名 {"str": "zhang san"}
json(_, str)
replace(str, "([a-z]*) \\w*", "$1 ***")

# 身份证号 {"str": "362201200005302565"}
json(_, str)
replace(str, "([1-9]{4})[0-9]{10}([0-9]{4})", "$1**********$2")

# 中文名 {"str": "小阿卡"}
json(_, str)
replace(str, '([\u4e00-\u9fa5])[\u4e00-\u9fa5]([\u4e00-\u9fa5])', "$1＊$2")
```

## `sql_cover()`

函数原型：`fn sql_cover(sql_test: str)`

函数说明：脱敏sql语句

```python
# in << {"select abc from def where x > 3 and y < 5"}
sql_cover(_)

# Extracted data(drop: false, cost: 33.279µs):
# {
#   "message": "select abc from def where x > ? and y < ?"
# }
```

## `strfmt()`

函数原型：`fn strfmt(key, fmt: str, args ...: int|float|bool|str|list|map|nil)`

函数说明：对已提取 `arg1, arg2, ...` 指定的字段内容根据 `fmt` 进行格式化，并把格式化后的内容写入 `key` 字段中

函数参数

- `key`: 指定格式化后数据写入字段名
- `fmt`: 格式化字符串模板
- `args`:可变参数，可以是多个已提取的待格式化字段名

示例:

```python
# 待处理数据: {"a":{"first":2.3,"second":2,"third":"abc","forth":true},"age":47}

# 处理脚本
json(_, a.second)
json(_, a.thrid)
cast(a.second, "int")
json(_, a.forth)
strfmt(bb, "%v %s %v", a.second, a.thrid, a.forth)
```

## `trim()`

函数原型：`fn trim(key, cutset: str = "")`

函数说明：删除 key 中首尾中指定的字符，cutset 为空字符串时默认删除所有空白符

函数参数：

- `key`: 已提取的某字段，字符串类型
- `cutset`: 删除 key 中出现在 cutset 字符串的中首尾字符

示例:

```python
# 待处理数据: "trim(key, cutset)"

# 处理脚本
add_key(test_data, "ACCAA_test_DataA_ACBA")
trim(test_data, "ABC_")

# 处理结果
{
  "test_data": "test_Data"
}
```

## `uppercase()`

函数原型：`fn uppercase(key: str)`

函数说明：将已提取 key 中内容转换成大写

函数参数

- `key`: 指定已提取的待转换字段名，将 `key` 内容转成大写

示例:

```python
# 待处理数据: {"first": "hello","second":2,"third":"aBC","forth":true}

# 处理脚本
json(_, first) uppercase(first)

# 处理结果
{
   "first": "HELLO"
}
```

## `url_decode()`

函数原型：`fn url_decode(key: str)`

函数说明：将已提取 `key` 中的 URL 解析成明文

参数:

- `key`: 已经提取的某个 `key`

示例：

```python
# 待处理数据: {"url":"http%3a%2f%2fwww.baidu.com%2fs%3fwd%3d%e6%b5%8b%e8%af%95"}

# 处理脚本
json(_, url) url_decode(url)

# 处理结果
{
  "message": "{"url":"http%3a%2f%2fwww.baidu.com%2fs%3fwd%3d%e6%b5%8b%e8%af%95"}",
  "url": "http://www.baidu.com/s?wd=测试"
}
```

## `xml()`

函数原型：`fn xml(input: str, xpath_expr: str, key_name)`

函数说明：通过 xpath 表达式，从 XML 中提取字段。

参数：

- input: 待提取的 XML
- xpath_expr: xpath 表达式
- key_name: 提取后数据写入新 key

示例一：

```python
# 待处理数据
       <entry>
        <fieldx>valuex</fieldx>
        <fieldy>...</fieldy>
        <fieldz>...</fieldz>
        <fieldarray>
            <fielda>element_a_1</fielda>
            <fielda>element_a_2</fielda>
        </fieldarray>
    </entry>

# 处理脚本
xml(_, '/entry/fieldarray//fielda[1]/text()', field_a_1)

# 处理结果
{
  "field_a_1": "element_a_1",  # 提取了 element_a_1
  "message": "\t\t\u003centry\u003e\n        \u003cfieldx\u003evaluex\u003c/fieldx\u003e\n        \u003cfieldy\u003e...\u003c/fieldy\u003e\n        \u003cfieldz\u003e...\u003c/fieldz\u003e\n        \u003cfieldarray\u003e\n            \u003cfielda\u003eelement_a_1\u003c/fielda\u003e\n            \u003cfielda\u003eelement_a_2\u003c/fielda\u003e\n        \u003c/fieldarray\u003e\n    \u003c/entry\u003e",
  "status": "unknown",
  "time": 1655522989104916000
}
```

示例二：

```python
# 待处理数据
<OrderEvent actionCode = "5">
 <OrderNumber>ORD12345</OrderNumber>
 <VendorNumber>V11111</VendorNumber>
</OrderEvent>

# 处理脚本
xml(_, '/OrderEvent/@actionCode', action_code)
xml(_, '/OrderEvent/OrderNumber/text()', OrderNumber)

# 处理结果
{
  "OrderNumber": "ORD12345",
  "action_code": "5",
  "message": "\u003cOrderEvent actionCode = \"5\"\u003e\n \u003cOrderNumber\u003eORD12345\u003c/OrderNumber\u003e\n \u003cVendorNumber\u003eV11111\u003c/VendorNumber\u003e\n\u003c/OrderEvent\u003e",
  "status": "unknown",
  "time": 1655523193632471000
}
```
