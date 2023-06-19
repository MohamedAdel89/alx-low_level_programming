/**
 *_memset - fills memory with a constant byte.
 *@s: pointer to start filling spaces
 *@b: constant byte to fill the spaces
 *@n: number of bytes to be filled
 *Return: a pointer to the memory area s.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;
	return (s);
}
