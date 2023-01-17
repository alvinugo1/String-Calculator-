# String Calculator 

## Overview
Bjarne is jealous of Python’s support for arithmetic with unbounded integers. Help Bjarne to feel
better about C++ by building a calculator to do basic arithmetic operations with arbitrarily large
numbers represented internally as strings, i.e., sequences of characters .

## An example execution of the calculator
![image](https://user-images.githubusercontent.com/93239793/212794130-80b6fc17-fc3e-4bdb-a1c0-606ce526d595.png)



## Project Overview
The project contains three source files:
1. main.cpp := contains the user interface that drives the program
2. string_calculator.h := contains required function declarations.
3. string_calculator.cpp := contains function definitions

## Functions
a. unsigned int digit_to_decimal(char digit)

- digit_to_decimal(‘7’) should return 7
- digit_to_decimal('/') should throw std::invalid_argument

b. char decimal_to_digit(unsigned int decimal)

- decimal_to_digit(7) should return ‘7’
- decimal_to_digit(36) should throw std::invalid_argument

c. std::string trim_leading_zeros(std::string num)

- trim_leading_zeros(“00123”) should return 123
- trim_leading_zeros(“-00123”) should return -123

d. std::string add(std::string lhs, std::string rhs)

- add(“1”, “2”) should return “3”
- add(“1”, “-2”) should return “-1”
- add(“-1”, “2”) should return “1”
- add(“-1”, “-2”) should return “-3”

e. std::string subtract(std::string lhs, std::string rhs)

- subtract(“1”, “2”) should return “-1”
- subtract(“1”, “-2”) should return “3”
- subtract(“-1”, “2”) should return “-3”
- subtract(“-1”, “-2”) should return “1”

f. std::string multiply(std::string lhs, std::string rhs)

- multiply(“2”, “3”) should return “6”
- multiply(“2”, “-3”) should return “-6”
- multiply(“-2”, “3”) should return “-6”
- multiply(“-2”, “-3”) should return “6”
