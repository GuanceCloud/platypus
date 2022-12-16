# Platypus Syntax Specification

The following is the definition of Pipeline processor language. Being supported by increasing syntax, the document would be adjusted to varying degrees.

## Identifiers and Keywords

### Identifiers

Identifiers, used to identify objects, can be used to represent a variable and function. Identifiers contain keywords.

Customized identifiers cannot duplicate keywords of Pipeline data processor language.

Identifiers consist of numbers (`0-9`), letters (`A-Z a-z`) and underscores (`_`), but the first character cannot be a number and case sensitive:

- `_abc`
- `abc`
- `abc1`
- `abc_1_`

If you need to start with a letter or use the above characters in the identifier, you need to use reverse quotation marks:

- `` `1abc` ``
- `` `@some-variable` ``
- `` `an emoticon variable👍` ``

### Special Identifiers

The special identifier（`_`）represents the external raw input data when the platypus script is triggered, and this parameter may be implicitly passed to some functions.

In some functions, `_` is treated as an alias for ` message ` for forward compatibility.

### Keywords

Keywords have special meanings, such as `if`, `elif`, `else`, `for`, `in`, `break` and `continue` .

## Notes

With `#` as a line comment character, inline comment is not supported.

```python
# this is a line comment
a = 1 # this is a line comment

"""
This is a (multi-line) string instead of a comment
"""
a = 2

"alphabetic string"
a = 3
```

## Built-in Data Type

In the Pipeline data processor language, the type of the value of a variable can change dynamically. But each value has its data type, which can be one of the **primitive types** or a **compound types**.

### Basic Types

#### Integer Type

Integers have a type length of 64bits with symbols. Currently, it is only supported to write integer literals in decimal form, such as `-1`, `0`, `1`, `+19`.

#### Float Type

Float types are 64bit long with symbols, and currently only support writing floating numeric quantities in decimal form, such as `-1.00001`, `0.0`, `1.0`, `+19.0`.

#### Boolean Type

Literals in boolean types only include `true` 和 `false`.

#### String Type

String literals can be written in double or single quotation marks, and multi-line strings can be written in triple double or triple quotation marks.

  * `"hello world"`

  * `'hello world'`

  * ```
    """hello
    world"""
    ```

  * ```
    '''
    hello
    world
    '''
    ```

#### Nil Type
  Nil is a special data type that means no value. The literal of this type is `nil`,  When a variable is used without assignment, its value is nil.

### Compound Type

Map type and list type are different from the base type. Multiple variables can point to the same map or list object. When assigning values, they do not make a memory copy of list or map but refer to it.

#### Map Type

Map type is key-value structure, only string type can be used as key, and the data type of value is not limited.

It can read and write elements in the map through index expressions.

```python
a = {
  "1": [1, "2", 3, nil],
  "2": 1.1,
  "abc": nil,
  "def": true
}

# as a["1"] is the object of list，b just refers to the value of a["1"].
b = a["1"]

"""
此时 a["1"][0] == 1.1
"""
b[0] = 1.1
```

#### List Type

The list type can store any number and any type of value in the list. 
It can read and write elements in the list through index expressions.

```python
a = [1, "2", 3.0, false, nil, {"a": 1}]

a = a[0] # a == 1
```

## Operator

The followings are the operators currently supported by Platypus. The higher the value, the higher the priority.

|Priority|Symbol|Combinability|Description|
|-|-|-|-|
| 1 | `=`  | Right | Assignment; Named parameter; the lowest priority|
| 2 | `\|\|` | Left | or |
| 3 | `&&` | Left | and |
| 4 | `>=` | Left | greater than or equal |
| 4 | `>`  | Left | greater than |
| 4 | `!=` | Left | not equal |
| 4 | `==` | Left | equal |
| 4 | `<=` | Left | less than or equal |
| 4 | `<`  | Left | less than |
| 5 | `+`  | Left | plus |
| 5 | `-`  | Left | subtract |
| 6 | `*`  | Left | multiply |
| 6 | `/`  | Left | divide |
| 6 | `%`  | Left | remainder|
| 7 | `[]` | Left | Use the list subscript or the key value of map|
| 7 | `()` | None | Operator priority can be changed; function call|

## Expression

Platypus uses the symbol comma `,` as the expression separator, such as the separation of expressions when passing parameters to invoke expressions and initializing maps and lists.

### Call Expression

The following is a function call to take the number of elements in the list:

```txt
len([1, 3, "5"])
```

### Binary Expression

An assignment expression belongs to a binary expression with a return value.

```txt
# 0
2 / 5

# 0.4，raise the type of left operand to float number during calculation
2 / 5.0

# true
1 + 2 * 3 == 7 && 1 <= 2

# b == 3; 
# as `=` right associativity of operators, a = (b = 3), a == 3
a = b = 3
```

### List Initialization Expression

```txt
[1, true, "1", nil]
```

### Map Initialization Expression

```txt
{
  "a": 1,
  "b": "2",
}
```

### Parenthesized Expression

Parenthesized expressions can change the precedence of operands in binary expressions, but they cannot change the combinability.

```txt
# 1 + 2 * 3 == 7

(1 + 2) * 3  # == 9
```

## Statement

All expressions in the Platypus can be treated as value statements when expressions are ended by list seperators `;` or `\n` , it would be treated as one statement, such as the following script content containing four statements.

```go
len("abc")
1
a = 2; a + 2 * 3 % 2
```

### Value Statement (Expression Statement)

An expression can be treated as a value statement when it is followed by a statement separator. Here are four legal statements.

```txt
a = 1; b = 2;
d = [1, 2]
len(d)
```

### Select Statement

Platypus supports the syntax of  `if/elif/else`.

```txt
if condition {

}
```

```txt
if condition {

} else {

}
```

```txt
if condition_1 {

} elif condition_2 {

} ... elif condition_n {

} else {

}
```

Like most programming languages, enter the corresponding statement block according to whether the condition of `if/elif` holds or not, and enter the else branch if none holds.

The current condition can be any expression as long as its value is one of the built-in data types. Here are the criteria:

* When the condition is `int` type value, if it is `0` the condition is `false`, otherwise `true`

* When the condition is `float` type value, if it is `0.0` the condition is `false`, otherwise `true`

* When the condition is `string` type value, it is an empty string `""` the condition is `false`, otherwise `true`

* When the condition is `bool` type value, the condition is the current value

* When the condition is `nil` type value, the condition is `false`

* When the condition is `map` type value, the length is 0, and the condition is `false`, otherwise `true`

* When the condition is `list` type value, the length is 0, and the condition is `false`, otherwise `true`

### Loop Statement

Platypus supports the syntax of `for` and `for in` .

The following are two statements that are only allowed in loop statement blocks:

- `cotinue` statement, no further statements are executed, and the next loop continues
- `break` statement, loop ends

The use of `for` statement can cause an infinite loop and should be used with caution, or use the statement `for in`  instead when possible.

```txt
for init-expr; condition; loop-expr {

}
```

```txt
for varb_name in map_value/list_value/string_value  {

}
```

Examples:

1. Use  `for` to run 10 loops.

```txt
for a = 0; a < 10; a = a + 1 {
  
}
```

2. Using `for in` traverses all elements of a list.

```txt
b = "2"
for a in ["1", "a" ,"2"] {
  b = b + a
  if b == "21a" {
    break
  }
}

# b == "21a"
```

3. Using `for in` traverses all the keys of the map.

```txt
d = 0
map_a = {"a": 1, "b":2}
for x in map_a {
  d = d + map_a[x]
}
```

4. Using `for in` traverses all characters of string.

```txt
s = ""
for c in "abcdef" {
  if s == "abc" {
    break
  } else {
    continue
  }
  s = s + "a"
}

# s == "abc"
```
