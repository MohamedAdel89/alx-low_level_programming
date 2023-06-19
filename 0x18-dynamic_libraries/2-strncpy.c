#include "main.h"
#include <stdio.h>
/**
 *_strncpy - copies a string.
 *@dest: string destination
 *@src: string to be copied to dest.
 *@n: it will use at most n bytes from src.
 *Return: pointer to the resulting string.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (*(src + i) && (i <= (n - 1)))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i <= (n - 1))
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
