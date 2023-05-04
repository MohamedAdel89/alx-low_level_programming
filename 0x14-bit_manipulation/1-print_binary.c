#include "main.h"
void print_binary_rec(unsigned long int n);

/**
 *print_binary - prints the binary representation of a number.
 *@n: number to be printed in binary
 */

void print_binary(unsigned long int n)
{
	if (n != 0)
	{
		print_binary_rec(n);
	}
	else
	{
		_putchar('0');
	}
}

/**
 *print_binary_rec - prints the binary representation of a number.
 *@n: number to be printed in binary
 */

void print_binary_rec(unsigned long int n)
{
	if (n != 0)
	{
		print_binary_rec(n >> 1);
		_putchar((n & 1) + '0');
	}
}
