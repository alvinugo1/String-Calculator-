# String Calculator (Arbitrary-Precision Arithmetic in C++)

## Overview

This project implements a **string-based calculator** that performs arithmetic on integers of **unbounded size**, bypassing the limitations of built-in C++ numeric types.

Instead of relying on fixed-width integers (`int`, `long`, `long long`), all values are represented internally as **strings**, and arithmetic is performed digit-by-digit. This mirrors how arbitrary-precision arithmetic libraries work at a low level and emphasizes correctness, edge-case handling, and explicit control over numeric operations.

Supported operations include:
- Addition
- Subtraction
- Multiplication
- Negative number handling
- Input normalization

---

## Motivation

While languages like Python natively support arbitrary-precision integers, C++ requires either external libraries or custom implementations.  
This project explores how large-integer arithmetic can be implemented **from first principles**, focusing on:

- Manual digit manipulation
- Carry and borrow propagation
- Sign handling
- Input validation
- Deterministic normalization of results

---

## Project Structure

The project consists of three source files:

1. **`main.cpp`**  
   Handles user input and drives execution.

2. **`string_calculator.h`**  
   Declares all arithmetic and helper functions.

3. **`string_calculator.cpp`**  
   Implements string-based arithmetic logic.

---

## Core Functions

### Digit Conversion

```cpp
unsigned int digit_to_decimal(char digit);
```
Converts a character digit ('0'–'9') to its numeric value.
- digit_to_decimal('7') → 7
- Invalid input throws std::invalid_argument
  
--

```cpp
char decimal_to_digit(unsigned int decimal);
```
Converts a numeric digit (0–9) to its character representation.
- decimal_to_digit(7) → '7'
- Invalid input throws std::invalid_argument

## Input Normalization
```cpp
std::string trim_leading_zeros(std::string num);
```
Removes unnecessary leading zeros while preserving sign and ensuring a canonical zero representation.

Examples:

"00123" → "123"

"-00123" → "-123"

"0000" → "0"

##Arithmetic Operations

All arithmetic functions operate on normalized numeric strings and return normalized results.

Addition

```cpp
std::string add(std::string lhs, std::string rhs);
```

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
