#ifndef _HOLBERTON_
#define _HOLBERTON_
#include <stdarg.h>
#include <stdio.h>
int sum_them_all(const unsigned int n, ...);
int _putchar(char c);
void print_strings(const char *separator, const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 *struct fmt_t- structure for the format
 *@c: char indicating the format
 *@func_str: func string to be printed
 */

typedef struct fmt_t
{
	char *c;
	void (*func_str)(va_list);
} fmt;

#endif
