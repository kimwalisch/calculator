///
/// @file   test.cpp
/// @brief  test program for calculator.hpp
///
/// Copyright (C) 2013 Kim Walisch, <kim.walisch@gmail.com>
///
/// This file is distributed under the New BSD License. See the
/// LICENSE file in the top level directory.
///

#include "calculator.hpp"
#include <iostream>
#include <iomanip>
#include <string>

#define STR1(s) #s
#define TOSTRING(s) STR1(s)

/// Test expressions
#define EXPR1 45345 + 0 + 0xdf234 - 1000 % 7
#define EXPR2 (0 + 0xdf234 - 1000) * 3 / 2 % 999
#define EXPR3 1 << 16
#define EXPR4 (0 + ~(0xdf234 & 1000) * 3) / -2
#define EXPR5 ((1 << 16) + (1 << 16)) >> 0X5
#define EXPR6 1+(((2+(3+(4+(5+6)* -7)/8))&127)<<1) *-3
#define EXPR7 100000000 + (1 << 16) + (1 << 16)
#define EXPR8 1-~1
#define EXPR9 1- ~1*0xfFa/( ((((8+(6|(4 *(2*(1)*3)*5)|7)+9)))))
#define EXPRa ((12|13)<<8)>>((1|127) %10&(31+7))
#define EXPRb ((((((((((5))))))  ))))- ((((((((( 6)))))))))

int failed = 0;

void compare(int result, const std::string& str)
{
  int r = calculator::eval(str);
  std::cout << (r == result ? "Correct: " : "Error: ");
  std::cout << std::setw(50) << str << " = " << std::setw(10) << r;
  if (r != result)
  {
    std::cout << " != " << result;
    failed++;
  }
  std::cout << std::endl;
}

int main()
{
  std::cout.setf(std::ios::left);

  compare(EXPR1, TOSTRING(EXPR1));
  compare(EXPR2, TOSTRING(EXPR2));
  compare(EXPR3, TOSTRING(EXPR3));
  compare(EXPR4, TOSTRING(EXPR4));
  compare(EXPR5, TOSTRING(EXPR5));
  compare(EXPR6, TOSTRING(EXPR6));
  compare(EXPR7, TOSTRING(EXPR7));
  compare(EXPR8, TOSTRING(EXPR8));
  compare(EXPR9, TOSTRING(EXPR9));
  compare(EXPRa, TOSTRING(EXPRa));
  compare(EXPRb, TOSTRING(EXPRb));

  if (failed != 0)
  {
    std::cerr << failed << " test(s) failed!" << std::endl;
    return 1;
  }

  std::cout << "All tests passed successfully!" << std::endl;
  return 0;
}
