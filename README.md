# printf Project

This project implements a custom version of the printf function in C.

## Description

The `_printf` function allows printing formatted output to the standard output stream. It supports the conversion specifiers `%c` for characters, `%s` for strings, and `%%` for printing a literal '%'.

## Getting Started

### Compilation

To compile the project, use the following command:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf


### Usage

To run the compiled program, execute the following command:
./printf


The program will output the results of the test cases provided in the `main.c` file.

## File Structire

- `main.h`: Header file containing function prototype.
- `_printf.c`: Source file containing the implementation of the `_printf` function.
- `main.c`: Source file containing sample test cases.
- `README.md`: This file, providing project information.

## Requirements

- The code should be compiled on Ubuntu 20.04 LTS using gcc with the specified options.
- The code should follow the Betty style guidelines.
- There should be no more than 5 functions per file.
- The program should not use global variables.
- The program should handle the conversion specifiers `%c`, `%s`, and `%%`.
- The program should write output to stdout.

## Functionality

The custom `_printf` function replicates the basic functionality of the standard `printf` function, supporting the conversion specifiers `%c`, `%s`, and `%%`. It prints the formatted output to the standard output stream.


## Examples

Here are some examples of using the `_printf` function:

#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "World");
    _printf("The value of x is: %d\n", 10);
    _printf("The character is: %c\n", 'A');
    _printf("Let's print a literal percent sign: %%\n");

    return 0;
}


##Notes
- The code should be compiled on Ubuntu 20.04 LTS using gcc with the specified options.
- The code follows the Betty style guidelines.
- Each source file should contain no more than 5 functions.
- The program does not use global variables.
- Additional conversion specifiers and formatting options are not implemented in this version.

## Authors

- [Fredrick Eneye Tania-Amanda Nkoyo](https://github.com/crystal4000)
