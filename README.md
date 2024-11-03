# NumberClassificationLibrary

## Description
**NumberClassificationLibrary** is a C project that provides functions to classify numbers based on specific properties: Armstrong numbers, Palindromes, Prime numbers, and Strong numbers. The project includes both recursive and loop-based implementations for determining these classifications. This project also emphasizes a comprehensive Makefile that handles compiling static and shared libraries, as well as various executable configurations.

## Features
- **Number Classification Functions**:
  - **isArmstrong**: Checks if a number is an Armstrong number.
  - **isPalindrome**: Checks if a number is a palindrome.
  - **isPrime**: Checks if a number is a prime number.
  - **isStrong**: Checks if a number is a strong number.
- **Makefile**: The project’s Makefile automates the compilation process, creating both static (`.a`) and shared (`.so`) libraries, and supports different builds for loop and recursive implementations.

## Compilation
To compile, run the following commands:

1. **Compile Static Libraries**:
   ```bash
   make loops    # Creates a static library for loop-based functions
   make recursives  # Creates a static library for recursive functions
   ```

2. **Compile Shared Libraries**:
   ```bash
   make loopd     # Creates a shared library for loop-based functions
   make recursived  # Creates a shared library for recursive functions
   ```

3. **Compile Executables**:
   - **mains**: Uses the recursive static library
     ```bash
     make mains
     ```
   - **maindloop**: Uses the loop-based shared library
     ```bash
     make maindloop
     ```
   - **maindrec**: Uses the recursive shared library
     ```bash
     make maindrec
     ```

4. **Clean Up**: To remove compiled files:
   ```bash
   make clean
   ```
