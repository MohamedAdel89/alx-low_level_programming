#include "main.h"

/**
 *_strlen - compute the length of a string.
 *@s: string
 *Return: length of a string.
 */

int _strlen(char *s)
{
	int cont = 0;

	while (*(s + cont) != '\0')
	{
		cont++;
	}
	return (cont);
}
