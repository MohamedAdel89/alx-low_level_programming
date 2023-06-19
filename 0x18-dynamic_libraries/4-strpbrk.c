#include <stdio.h>

/**
 *_strpbrk - searches a string for any of a set of bytes.
 *@s: string
 *@accept: characters to be accepted in the string
 *Return: pointer to the byte in s that matches one of the bytes in accept
 */

char *_strpbrk(char *s, char *accept)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	char *p = NULL;

	while (*(s + i) && (tmp == 0))
	{
		j = 0;
		while (*(accept + j))
		{
			if (*(s + i) == *(accept + j))
			{
				p = (s + i);
				tmp = 1;
				break;
			}
			j++;
		}
		i++;
	}
	return (p);
}
