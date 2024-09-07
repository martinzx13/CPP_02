
# Exercise: Fixed-Point Number Class in Orthodox Canonical Form

## Overview

In this exercise, you will implement a class that represents a **fixed-point number** in **Orthodox Canonical Form** (OCF) in C++. The class will use an integer to store the fixed-point number's raw value, and will always assume 8 fractional bits. This exercise will help you understand the **Rule of Three** (default constructor, copy constructor, copy assignment operator, and destructor) and how to manage fixed-point arithmetic in C++.

## Requirements

### Turn-in Directory

- **Directory**: `ex00/`

### Files to Submit

- **Makefile**: To compile the program.
- **Header File**: 
  - `Fixed.hpp`: The class definition.
- **Source File**: 
  - `Fixed.cpp`: The implementation of the class and its methods.
- **Test File**:
  - `main.cpp`: Test file to ensure the class works as expected.

### Forbidden Functions

- **None**: All standard C++ functions are allowed.

## Objectives

You are required to implement a class that follows the **Orthodox Canonical Form**, handling both object construction and destruction properly, with methods to get and set the raw bits of the fixed-point number.

### Class Structure

#### Private Members

- **`int _value`**: 
  - Stores the raw integer value of the fixed-point number.
  
- **`static const int _fractionalBits = 8`**: 
  - This static constant holds the number of fractional bits in the fixed-point representation. This value is always 8.

#### Public Members

- **Default Constructor**: 
  - Initializes the fixed-point number's raw value to `0`.

- **Copy Constructor**: 
  - Creates a new instance of the fixed-point number by copying an existing object.

- **Copy Assignment Operator**: 
  - Assigns one instance of the fixed-point number to another. Handles self-assignment properly.

- **Destructor**: 
  - Cleans up any resources (in this case, nothing specific, but necessary for OCF).

- **`int getRawBits(void) const`**:
  - A public member function that returns the **raw integer value** of the fixed-point number.

- **`void setRawBits(int const raw)`**:
  - A public member function that sets the **raw integer value** of the fixed-point number.

## Expected Functionality

1. **Default Constructor**:
   - Initializes `_value` to `0`.

2. **Copy Constructor**:
   - Copies the internal state (i.e., `_value`) from another instance of the class.

3. **Copy Assignment Operator**:
   - Properly handles assigning one object to another, with care for self-assignment.

4. **Destructor**:
   - Cleans up the object upon destruction, even though no dynamic resources are involved.

5. **Member Functions**:
   - `getRawBits()` returns the raw integer value of the fixed-point number.
   - `setRawBits(int const raw)` sets the raw integer value.

## Compilation and Execution

- **To compile the program**, use the `Makefile` by running the following command:

  ```bash
  make
  ```

- **To run the program**, use:

  ```bash
  ./fixed_point
  ```

- **To clean up the compiled files**, use:

  ```bash
  make clean
  ```

## Example Test Code (in `main.cpp`)

You can create a test in `main.cpp` to verify that the class behaves as expected:

```cpp
#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(a);  // Copy constructor
    Fixed c;

    c = b;  // Copy assignment

    std::cout << "a raw bits: " << a.getRawBits() << std::endl;
    std::cout << "b raw bits: " << b.getRawBits() << std::endl;
    std::cout << "c raw bits: " << c.getRawBits() << std::endl;

    a.setRawBits(10);
    std::cout << "a raw bits after setRawBits(10): " << a.getRawBits() << std::endl;

    return 0;
}
```

### Expected Output:

```plaintext
a raw bits: 0
b raw bits: 0
c raw bits: 0
a raw bits after setRawBits(10): 10
```

## Summary

In this exercise, you will create a **Fixed** class in the **Orthodox Canonical Form** that represents a fixed-point number. The class must:
- Properly implement the **Default Constructor**, **Copy Constructor**, **Copy Assignment Operator**, and **Destructor**.
- Provide methods to **get and set the raw value** of the fixed-point number.

The goal is to become comfortable with managing the lifecycle of objects in C++ and to understand how to correctly handle object copying, assignment, and destruction.

