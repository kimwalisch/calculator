# calculator

```calculator.hpp``` is a minimal, header-only C++ library for parsing and evaluating
integer arithmetic expressions, e.g. ```"10 * (7 - 1)"```. It is designed for simplicity,
it supports all C++ integer types (e.g. ```int8_t```, ```unsigned int```, ```long```, ```__int128_t```),
but does not support functions, comparison operators, or user variables. It compiles
with any C++ compiler that supports C++11 or later.

**calculator** is a simple but fast
[operator-precedence parser](https://en.wikipedia.org/wiki/Operator-precedence_parser).

In version 2.0 (2025), error handling has been significantly improved. The library now
detects virtually all integer overflows and underflows, helping prevent incorrect
results. An extensive test suite further ensures the correctness and robustness of
the implementation. This **calculator** is being used in production by the
[primesieve](https://github.com/kimwalisch/primesieve) and [primecount](https://github.com/kimwalisch/primecount)
C/C++ libraries.

# Supported operators

```calculator.hpp``` uses the same operator precedence and associativity
as the C++ programming language and also supports the power operator.

<table>
  <tr align="center">
    <td><b>Operator</b></td>
    <td><b>Description</b></td>
  </tr>
  <tr align="left">
    <td>|</td>
    <td>Bitwise Inclusive OR</td>
  </tr>
  <tr align="left">
    <td>&</td>
    <td>Bitwise AND</td>
  </tr>
  <tr align="left">
    <td>~</td>
    <td>Unary Complement </td>
  </tr>
  <tr align="left">
    <td>&lt;&lt;</td>
    <td>Shift Left</td>
  </tr>
  <tr align="left">
    <td>&gt;&gt;</td>
    <td>Shift Right</td>
  </tr>
  <tr align="left">
    <td>+</td>
    <td>Addition</td>
  </tr>
  <tr align="left">
    <td>-</td>
    <td>Subtraction</td>
  </tr>
  <tr align="left">
    <td>*</td>
    <td>Multiplication</td>
  </tr>
  <tr align="left">
    <td>/</td>
    <td>Division</td>
  </tr>
  <tr align="left">
    <td>%</td>
    <td>Modulo</td>
  </tr>
  <tr align="left">
    <td>^, **</td>
    <td>Raise to power</td>
  </tr>
  <tr align="left">
    <td>e</td>
    <td>Integer Scientific Notation</td>
  </tr>
</table>

# C++ API

Main functions defined in ```calculator.hpp```:

```C++
// Default eval() returns signed 64-bit
std::int64_t calculator::eval(const std::string& expression);

// Any integer type, e.g.: int8_t, unsigned short, __int128_t, ...
template <typename T>
T calculator::eval<T>(const std::string& expression);
```

# How to use it

```calculator::eval("1+2")``` takes a string with an integer arithmetic
expression as an argument, evaluates the arithmetic expression and returns
the result. If the expression string is not a valid integer arithmetic
expression a ```calculator::error``` exception is thrown.

```C++
#include "calculator.hpp"
#include <cassert>
#include <iostream>

int main()
{
    try
    {
        // Default eval() uses int64_t
        std::int64_t result = calculator::eval("(0 + (255 & 1000)*3) / -2");
        std::cout << result << std::endl;

        // GCC/Clang 128-bit integers
        __int128_t res = calculator::eval<__int128_t>("2^100");
        assert(res == __int128_t(1) << 100);
    }
    catch (calculator::error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
```

# Scientific notation

```calculator.hpp``` also supports basic scientific notation for integers (without the dot syntax).

```C++
res = calculator::eval("1e5");
assert(res == 100000);

res = calculator::eval("2e5");
assert(res == 200000);
```
