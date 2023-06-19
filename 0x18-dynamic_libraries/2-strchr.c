#include <stdio.h>

/**
 *_strchr - locates a character in a string.
 *@s: string in which a character will be located.
 *@c: character to be located in s
 *Return: pointer to the first occurrence of the character c in the string s,
 *or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	unsigned int i = 0;
	char *p;

	while (*(s + i))
	{
		if (*(s + i) == c)
		{
			p = (s + i);
			break;
		}
		else
		{
			p = NULL;
		}
		i++;
	}
	if (*(s + i) == c)
		p = (s + i);
	return (p);
}
