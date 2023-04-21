#include "variadic_functions.h"

/**
 *print_numbers - print numbers
 *@separator: spearator to be used
 *@n: number of numbers
 *Return: none
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;

	va_list(valist);
	if (n != 0)
	{
		va_start(valist, n);
		for (i = 0; i < n - 1; i++)
		{
			if (separator != NULL)
				printf("%i%s", va_arg(valist, int), separator);
			else
			  printf("%i", va_arg(valist, int));
		}
		printf("%i\n", va_arg(valist, int));
		va_end(valist);
	}
	else
	{
		printf("\n");
	}
}
