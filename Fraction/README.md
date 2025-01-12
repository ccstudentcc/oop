# Project Introduction

Write a class that represents a fraction number like `2/3`.

## Requirements

- **Default Constructor**
- **Parameterized Constructor**: Takes two integers as parameters
- **Copy Constructor**
- **Arithmetical Operators**: `+`, `-`, `*`, `/`
- **Relational Operators**: `<`, `<=`, `==`, `!=`, `>=`, `>`
- **Typecast to double**
- **To string**
- **Inserter and extractor for streams**
- **Conversion from a finite decimal string**: e.g., `1.414`

## Directory Structure

```plaintext
Fraction
│  CMakeLists.txt
│  README.md
│
├─include
│      Fraction.h
│
└─src
        Fraction.cpp
        test.cpp
```

## Instructions

Please use `CMakeLists.txt` as follows:

1. `mkdir build`
2. `cd build`
3. `cmake ..`

    If you encounter the following error:

    ```
    -- Building for: NMake Makefiles
    CMake Error at CMakeLists.txt:3 (project):
      Running
    
       'nmake' '-?'
    
      failed with:
    
       系统找不到指定的文件。
    CMake Error: CMAKE_C_COMPILER not set, after EnableLanguage
    CMake Error: CMAKE_CXX_COMPILER not set, after EnableLanguage
    -- Configuring incomplete, errors occurred!
    ```
    
    Please use:
    
    ```bash
    cmake -G "MinGW Makefiles" ..
    ```
    
    instead of `cmake ..`

4. `make`
5. `FractionTest.exe` is the final file.


## Test Suite for the Fraction class(`test.cpp`)
This program performs a series of tests to verify the correctness and functionality of the `Fraction` class. The tests include:

- **Default Constructor**: Ensures that a default `Fraction` object is initialized to `0/1`.
- **Parameterized Constructor**: Tests initialization with specific numerator and denominator.
- **Copy Constructor**: Verifies that a new `Fraction` object is a copy of an existing one.
- **String Constructor**: Checks the ability to create a `Fraction` from a decimal string.
- **Arithmetic Operations**: Validates addition, subtraction, multiplication, and division of fractions.
- **Relational Operators**: Tests comparison operators such as `<`, `<=`, `==`, `!=`, `>=`, and `>`.
- **Type Conversion**: Ensures that a `Fraction` can be correctly converted to a `double`.
- **String Representation**: Confirms that the `toString` method returns the expected string format.
- **Stream Operators**: Tests insertion (`<<`) and extraction (`>>`) operators for I/O operations.
- **Edge Cases**: Includes tests for invalid inputs and zero denominators to ensure robust error handling.
- **Invalid Input Cases**: Tests invalid input parameter types like `double`, for example `f(3.3/4)`. The constructor only permits integer types for the numerator and denominator. These tests ensure that the class correctly handles or rejects invalid type inputs, maintaining type safety and robustness.

Each test case outputs the result and checks the correctness using assertions. If all tests pass, the program will output `All tests passed!` indicating successful validation of the `Fraction` class.


