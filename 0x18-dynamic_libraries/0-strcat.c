#include "main.h"
#include <stdio.h>
/**
 *_strcat - concatenates two strings.
 *@dest: string destination
 *@src: string to be appended to dest.
 *Return: pointer to the resulting string.
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int tmp;

	/*Counting the number of characters of dest*/
	while (*(dest + i))
		i++;
	tmp = i;

	/*Appending src to dest*/
	for (; *(src + (i - tmp)); i++)
		*(dest + i) = *(src + (i - tmp));
	*(dest + i) = '\0';
	return (dest);
}
