/**
 *_strspn - gets the length of a prefix substring.
 *@s: string
 *@accept: characters to be accepted in the string
 *Return: number of bytes in the initial segment
 */

unsigned int _strspn(char *s, char *accept)
{
	int i = 0;
	int j = 0;
	unsigned int cont = 0;
	unsigned int tmp = 0;

	while (*(s + i))
	{
		j = 0;
		tmp = cont;
		while (*(accept + j))
		{
			if (*(s + i) == *(accept + j))
				cont++;
			j++;
		}
		if (tmp == cont)
			break;
		i++;
	}
	return (cont);
}
