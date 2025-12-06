*This project has been created as part of the 42 curriculum by jleclerc.*

# Libft42

## Description

Libft42 is a reimplementation of a subset of the C standard library as required by the 42 school's Libft project. The goal is to recreate commonly used C functions (string manipulation, memory management, list utilities, etc.) with clean, portable, and well-tested code.

This repository contains the source files (.c) implementing the functions, the public header (`libft.h`), the Makefile and the generated static library (`libft.a`).

### Mandatory Functions

| **Functions** | **Descriptions** |
| ------------- | ---------------- |
| **ft_islapha** | checks for an alphabetic characer. |
| **ft_isdigit** | checks for a digit (0 through 9). |
| **ft_isalnum** | checks for an alphanumeric character. |
| **ft_isascii** | checks wether `c` is an ascii character (in the range 0 to 127). |
| **ft_isprint** | checks for an printable character. |
| **ft_strlen** | calculates the length of the string pointed to by `s`, including the null byte. |
| **ft_memset** | fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c`. |
| **ft_bzero** | erases the data in the `n` bytes of the memory starting at the location pointed to by `s`. |
| **ft_memcpy** | copies `n` bytes from memory area `src` to memory area `dest`. The memory areas must not overlap.
| **ft_memmove** | copies `n` bytes from memory area `src` to memory area `dest`. The memory area may overlap. |
| **ft_strlcpy** | copies up to `size` - 1 characters from the NUL-terminated string `src` to `dst`</dst>. NUL-terminating the string. |
| **ft_strlcat** | functions appends the NUL-terminated string `src` to the end of `dst`. it will append at most `size` - strlen(dst) - 1 bytes, NUL-terminating the result. |
| **ft_toupper** | if `c` is a lowercase letter, returns its uppercase equivalent, otherwise it returns `c`. |
| **ft_tolwer** | if `c` is an uppercase, retuns its lowercase equivalent, otherwise it returns `c`. |
| **ft_strchr** | returns a pointer to the first occurence of the `c` character in string `s`. |
| **ft_strrchr** | returns a pointer to the last occurence of the `c` character in string `s`. |
| **ft_strncmp** | compares the two strings `s1` and `s2`. It returns an int les than, equal to, or greater than 0 if `s1` is found, respectively, to be less than, to match, or be greater than `s2`. |
| **ft_memchr** | function scans the initial `n` bytes of the memory are pointed to by `s` for the first instance of `c`. Both `c` and the bytes of the memory area pointed to by `s` are interpretes as `unsigned char`. |
| **ft_memcmp** | compares the first `n` bytes of the memory areas `s1` and `s2`. |
| **ft_strnstr** | this function locates the first occurrence of the null-terminated string `little` in the null-terminated string `big`. |
| **ft_atoi** | converts the initial portion of the string pointed to by `nptr` to `int` |
| **ft_calloc** | allocates memory for the an array of `nmemb` elements of `size` bytes each and returns a pointer to the allocated memory. The memory is set to 0. |
| **ft_strdup** | returns a pointer to a new string which is a duplicate of the string `s`. |


### Additional Functions

| **Functions** | **Descriptions** |
| ------------- | ---------------- |
| **ft_substr**| returns a substring from the string `s` beginning at index `start` and of maximum size `len`. |
| **ft_strjoin** | returns a new string, which is the result of the concatenation of `s1` and `s2`. |
| **ft_strtrim** | returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string. |
| **ft_split** | returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. |
| **ft_itoa** | returns a string representing the integer received as an argument. |
| **ft_strmapi** | applies the function `f` to each character of the string `s`, passing its first arguments and the character itself  as the second. |
| **ft_striteri** | applies the function `f` on each character of the string passed as argument, passing its index as first argument. |
| **ft_putchar_fd** | outputs the character `c` to the given file descriptor. |
| **ft_putstr_fd** | outputs the string `s` to the given file descriptor. |
| **ft_putnbr_fd** | outputs the integer `n` to the given file descriptor. |


### Linked List

| **Functions** | **Descriptions** |
| ------------- | ---------------- |
| **ft_lstnew** | returns a new node. |
| **ft_lstadd_front** | adds the node `new` at the beginning of the list. |
| **ft_lstlast** | returns the last node of the list. |
| **ft_lstadd_back** | adds the node `new` at the end of the list. |
| **ft_lstdelone** | takes a node as parameter and frees its content using the function `del`. |
| **ft_lstclear** | deletes and frees the given node and all its successors, using the function `del` and free. |
| **ft_lstiter** | iterates through the list `lst` and applies the function `f` to the content of each node. |
| **ft_lstmap** | iterates through the list `lst`, applies the function `f` to each node's content, and creates a new list resulting of the succesive applications of the function `f`. |

## Instructions

### Installation

Clone the repository and build the library using the provided Makefile:

```bash
git clone git@github.com:MisterJMAL/Libft_42.git
cd Libft_42
make
```

The `make` target should compile the sources and produce `libft.a`.

### Usage

To use the library in your C project, include `libft.h` and link against `libft.a`:

```c
#include "libft.h"

// Example compile command:
// gcc -I. main.c libft.a -o my_program
```

## Resources

- 42 school Libft subject and rules.
- man pages for standard C functions (e.g., `man 3 strcpy`, `man 3 malloc`) to compare behavior.
- Testers:
	- Tripouille — libftTester: https://github.com/Tripouille/libftTester
	- Blaeste — libfterator: https://github.com/Blaeste/libfterator
	- jtoty — Libftest: https://github.com/jtoty/Libftest
- Guide for writing good READMEs: https://www.makeareadme.com/
- Note: AI was used only to generate the initial README template.
- Thanks to my peers for their help when I couldn't find an issue.