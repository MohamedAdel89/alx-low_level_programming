#include "main.h"

/**
 *get_endianness - checks the endianness
 *Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int tmp = 0xFF00FF00, real = 0xFF00FF00, i;
	unsigned int *num = &real;
	char *mov = (char *)num;

	for (i = 0; i < 4; i++)
	{
		if (((unsigned int)*(mov + i)) >> 24 != (tmp & 0xFF))
			return (0);
		tmp = tmp >> 8;
	}
	return (1);

}
