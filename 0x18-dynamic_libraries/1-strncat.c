#include "main.h"
#include <stdio.h>
/**
 *_strncat - concatenates two strings.
 *@dest: string destination
 *@src: string to be appended to dest.
 *@n: it will use at most n bytes from src.
 *Return: pointer to the resulting string.
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int tmp;

	/*Counting the number of characters of dest*/
	while (*(dest + i))
		i++;
	tmp = i;

	/*Appending src to dest*/
	for (; (i - tmp) <= (n - 1); i++)
	{
		if (*(src + (i - tmp)))
			*(dest + i) = *(src + (i - tmp));
		else
			break;
	}
	*(dest + i) = '\0';
	return (dest);
}
