#include "main.h"

/**
 *flip_bits - computes the number of bits you would need to flip to get
 *from a number to another
 *@n: number to get
 *@m: number of partiture
 *Return: number of bits you would need to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int count = 0;

	while (n != m)
	{
		if ((n & 1) != (m & 1))
			count++;
		n = n >> 1;
		m = m >> 1;
	}
	return (count);
}
