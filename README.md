## About

```calculator.hpp``` is a simple C++ operator-precedence parser with
infix notation for integer arithmetic expressions. calculator.hpp is a
header-only library that compiles with any C++ compiler. I wrote it
because I needed a portable and GPL compatible calculator for 64-bit
integers and could not find one elsewhere.

## Supported binary operators

calculator.hpp uses the same operator precedence and associativity as
the C++ programming language and also supports the power operator.

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
    <td>^</td>
    <td>Bitwise Exclusive OR</td>
  </tr>
  <tr align="left">
    <td>&</td>
    <td>Bitwise AND</td>
  </tr>
  <tr align="left">
    <td><</td>
    <td>Shift Left</td>
  </tr>
  <tr align="left">
    <td>>></td>
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
    <td>**</td>
    <td>Raise to power</td>
  </tr>
</table>

## Example

The following C++ code snippet shows how to use calculator.hpp, the
signature of its eval function is
```T calculator::eval<T>(const std::string& expression)```.
If the expression string is not a valid arithmetic expression a
```calculator::error``` exception is thrown.

```C++
#include "calculator.hpp"
#include <iostream>

int main()
{
  try {
     long result = calculator::eval<long>("(0 + ~(0xFF & 1000)*3) /-2");
     std::cout << result << std::endl;
  }
  catch (calculator::error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
```
