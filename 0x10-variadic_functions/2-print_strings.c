#include "variadic_functions.h"

/**
 *print_strings -  prints strings, followed by a new line.
 *@separator: separator between numbers
 *@n: number of strings
 *Return: none
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *s;

	va_list(valist);
	if (n != 0)
	{
		va_start(valist, n);
		for (i = 0; i < n - 1; i++)
		{
			s = va_arg(valist, char *);
			if (separator != NULL)
			{
				if (s != NULL)
					printf("%s%s", s, separator);
				else
					printf("%p%s", s, separator);
			}
			else if (s != NULL)
				printf("%s", s);
			else
				printf("%p", s);
		}
		s = va_arg(valist, char *);
		if (s != NULL)
			printf("%s\n", s);
		else
			printf("%p\n", s);
		va_end(valist);

	}
	else
	{
		printf("\n");
	}
}
