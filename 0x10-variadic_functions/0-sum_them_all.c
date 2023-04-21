#include <stdarg.h>

/**
 *sum_them_all - sums all the numbers given
 *@n: number of numbers to sum
 *Return: return the sum of all the numbers
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i = 0, sum = 0;
	va_list valist;

	if (n == 0)
		return (0);
	va_start(valist, n);
	for (; i < n; i++)
	{
		sum += va_arg(valist, int);
	}
	va_end(valist);
	return (sum);

}
