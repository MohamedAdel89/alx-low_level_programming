#include "main.h"

/**
 *clear_bit - clear the value of a bit to 1 at a given index
 *@n: pointer to the long int number (8 bytes)
 *@index: index of the bit to be cleared
 *Return: 1 if it worked -1 if an error ocurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int tmp = ~(1 << index);

	if (n == NULL || index > sizeof(unsigned long int) * 8)
		return (-1);
	*n = *n & tmp;
	return (1);
}
