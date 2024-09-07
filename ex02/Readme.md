Here’s a **README** file for **Exercise 02: Now We’re Talking**, where you will extend the functionality of the `Fixed` class by overloading comparison, arithmetic, and increment/decrement operators, and adding static `min` and `max` member functions.

---

# Exercise 02: Now We’re Talking

## Overview

In this exercise, you'll expand your fixed-point number class by adding support for common operators such as **comparison**, **arithmetic**, and **increment/decrement**. You will also implement static member functions to find the minimum and maximum of two fixed-point numbers.

### Objective:

- Overload the following operators for the `Fixed` class:
  - **Comparison operators**: `>`, `<`, `>=`, `<=`, `==`, `!=`
  - **Arithmetic operators**: `+`, `-`, `*`, `/`
  - **Increment/decrement operators**: Pre-increment (++), Post-increment (++), Pre-decrement (--), Post-decrement (--)
  
- Implement the following static member functions to compare two fixed-point numbers:
  - **min()**: Returns the smallest of two numbers.
  - **max()**: Returns the largest of two numbers.
  
Each of these functions should be implemented in two forms:
  - One that accepts **two references** to non-const fixed-point numbers.
  - One that accepts **two references** to **const** fixed-point numbers.

### Requirements:

- **Turn-in Directory**: `ex02/`
- **Files to Submit**:
  - `Makefile`
  - `main.cpp`
  - `Fixed.h` or `Fixed.hpp`
  - `Fixed.cpp`
  
- **Allowed Functions**:
  - `roundf()` from the `<cmath>` library.

---

## Features to Implement:

### 1. **Overloading Comparison Operators**

You need to overload the following six comparison operators for the `Fixed` class:
- **`>` (greater than)**
- **`<` (less than)**
- **`>=` (greater than or equal to)**
- **`<=` (less than or equal to)**
- **`==` (equal to)**
- **`!=` (not equal to)**

These operators will allow you to compare two `Fixed` objects.

#### Example:
```cpp
Fixed a(10);
Fixed b(20);

if (a < b)
    std::cout << "a is less than b" << std::endl;
```

### 2. **Overloading Arithmetic Operators**

You need to overload the following arithmetic operators for the `Fixed` class:
- **`+` (addition)**
- **`-` (subtraction)**
- **`*` (multiplication)**
- **`/` (division)**

These operators will allow you to perform basic arithmetic operations on `Fixed` objects.

#### Example:
```cpp
Fixed a(10);
Fixed b(20);
Fixed result = a + b;
```

### 3. **Overloading Increment/Decrement Operators**

You need to overload the following increment and decrement operators for the `Fixed` class:
- **Pre-increment (`++a`)**
- **Post-increment (`a++`)**
- **Pre-decrement (`--a`)**
- **Post-decrement (`a--`)**

These operators will increase or decrease the fixed-point value by the smallest representable value (`ϵ`), so that `1 + ϵ > 1`.

#### Example:
```cpp
Fixed a(10);
++a;  // Pre-increment
a++;  // Post-increment
```

### 4. **Static Member Functions: `min()` and `max()`**

You will add four static member functions to find the smallest or greatest of two `Fixed` objects. These functions will come in two forms:
- **`min()`**: Returns the smaller of two `Fixed` objects.
  - One version takes two references to non-const `Fixed` objects.
  - Another version takes two references to const `Fixed` objects.
  
- **`max()`**: Returns the larger of two `Fixed` objects.
  - One version takes two references to non-const `Fixed` objects.
  - Another version takes two references to const `Fixed` objects.

#### Example:
```cpp
Fixed a(10);
Fixed b(20);

Fixed &smaller = Fixed::min(a, b);  // Returns reference to the smaller object
const Fixed &larger = Fixed::max(a, b);  // Returns reference to the larger object
```

---

## Example Usage in `main.cpp`:

```cpp
#include "Fixed.hpp"

int main() {
    Fixed a(10);
    Fixed b(20);

    // Comparison operators
    if (a < b)
        std::cout << "a is less than b" << std::endl;

    // Arithmetic operators
    Fixed result = a + b;
    std::cout << "a + b = " << result << std::endl;

    // Increment and decrement
    ++a;
    b--;

    std::cout << "a after increment: " << a << std::endl;
    std::cout << "b after decrement: " << b << std::endl;

    // Min and Max functions
    Fixed &min = Fixed::min(a, b);
    const Fixed &max = Fixed::max(a, b);

    std::cout << "min: " << min << std::endl;
    std::cout << "max: " << max << std::endl;

    return 0;
}
```

---

## Compilation and Execution:

### Compilation:
- Use the provided **Makefile** to compile the program:
  ```bash
  make
  ```

### Execution:
- After compiling, run the executable:
  ```bash
  ./fixed_point
  ```

### Clean Up:
- Use the following command to clean up the generated object files and executable:
  ```bash
  make clean
  ```

---

## Summary

In this exercise, you will add powerful functionality to the `Fixed` class by overloading comparison, arithmetic, and increment/decrement operators, and implementing static `min()` and `max()` functions. These operators will make the `Fixed` class behave like a basic numeric type, making it much more useful in mathematical expressions.
