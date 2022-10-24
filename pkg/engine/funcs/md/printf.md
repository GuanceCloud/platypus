
### `printf()` {#fn-printf}

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
