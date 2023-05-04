#include "main.h"

/**
 *_strlen - returns the length of a string
 *@s: string
 *Return: length of a string
 */

int _strlen(char *s)
{
	if (*s != '\0')
		return (_strlen(s + 1) + 1);
	else
		return (0);
}

/**
 *_pow - computes the value of x raised to the power of y.
 *@x: the base
 *@y: the exponent
 *Return: -1 if y is lower than 0. Otherwise will return the power of y.
 */

int _pow(int x, int y)
{
	if (y >= 0)
	{
		if (y == 0)
			return (1);
		else
			return (x * _pow(x, y - 1));
	}
	else
	{
		return (-1);
	}
}

/**
 *binary_to_uint - converts a binary number to an unsigned int
 *@b: binary number to be converted
 *Return: unsigned int
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0, bit = 0, decNum = 0;

	if (b == NULL || *b == '\0')
		return (0);
	i = _strlen((char *)b) - 1;
	while ((*(b + i) >= '0' && *(b + i) <= '1' && i != 0))
	{
		bit = *(b + i) - '0';
		decNum += _pow(2, _strlen((char *)b) - i - 1) * bit;
		i--;
	}
	if (i == 0)
	{
		bit = *(b + i) - '0';
		decNum += _pow(2, _strlen((char *)b) - 1) * bit;
		return (decNum);
	}
	return (0);
}
