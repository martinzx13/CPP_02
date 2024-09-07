# Exercise 01: Towards a More Useful Fixed-Point Number Class

## Overview

This exercise is a continuation of the previous task where you implemented a fixed-point number class in C++. In this part, you’ll make the class more functional by adding constructors that allow converting from integer and floating-point numbers, as well as functions to convert the fixed-point number back into integer and floating-point representations. Additionally, you’ll implement an overloaded insertion operator (`<<`) to output the fixed-point number as a floating-point value.

## Objectives

1. **Extend the Fixed-Point Class** to include:
   - Constructors that accept both integer and floating-point numbers.
   - Member functions to convert the fixed-point number back to integer or floating-point numbers.
   
2. **Overload the Insertion Operator (`<<`)**:
   - To print the fixed-point number as a floating-point value.

### Key Features to Implement:

1. **Constructors**:
   - A constructor that takes a constant integer and converts it to a fixed-point value.
   - A constructor that takes a constant floating-point number and converts it to a fixed-point value.
   
2. **Member Functions**:
   - `float toFloat(void) const`: Converts the fixed-point number to a floating-point number.
   - `int toInt(void) const`: Converts the fixed-point number to an integer by discarding the fractional bits.

3. **Operator Overloading**:
   - Overload the insertion operator (`<<`) to allow printing the fixed-point number as a floating-point value in output streams (`std::cout`).

### Requirements:

- **Turn-in Directory**: `ex01/`
- **Files to Submit**: 
  - `Makefile`
  - `main.cpp`
  - `Fixed.h` or `Fixed.hpp`
  - `Fixed.cpp`
  
- **Allowed Functions**:
  - `roundf()` from the `<cmath>` library for rounding floating-point numbers.

---

## Class Structure

### Private Members:
- **`int _value`**: Stores the fixed-point number’s raw value.
- **`static const int _fractionalBits = 8`**: A constant that defines the number of fractional bits, always initialized to 8.

### Public Constructors:

1. **Default Constructor**:
   - Initializes the fixed-point value to `0`.
   
2. **Integer Constructor**:
   - Takes a constant integer as a parameter and converts it to the corresponding fixed-point value by multiplying it by \( 2^8 \).
   
3. **Floating-Point Constructor**:
   - Takes a constant floating-point number as a parameter and converts it to the corresponding fixed-point value by multiplying it by \( 2^8 \) and rounding the result.

### Public Member Functions:

1. **`float toFloat(void) const`**:
   - Converts the fixed-point value to a floating-point number by dividing the raw value by \( 2^8 \).
   
2. **`int toInt(void) const`**:
   - Converts the fixed-point value to an integer by simply shifting out the fractional bits.

### Operator Overloading:

1. **Insertion Operator (`<<`)**:
   - Overload the insertion operator to allow printing the fixed-point number as a floating-point value.

---

## Example Usage in `main.cpp`:

```cpp
#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b(10);  // Integer constructor
    Fixed const c(42.42f);  // Floating-point constructor
    Fixed const d(b);  // Copy constructor
    
    a = Fixed(1234.4321f);  // Copy assignment operator

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
```

### Expected Output:
```plaintext
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
a is 1234.43
b is 10.00
c is 42.42
d is 10.00
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
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

This exercise improves the **Fixed** class by adding support for integer and floating-point conversions, both when constructing the object and when outputting it. The overloaded insertion operator (`<<`) will print the floating-point representation of the fixed-point number, making it more user-friendly. Additionally, the exercise reinforces the use of the **Orthodox Canonical Form** by ensuring that the class has a default constructor, copy constructor, copy assignment operator, and destructor.

