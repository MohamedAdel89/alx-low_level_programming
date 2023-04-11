char *_strcpy(char *dest, char *src)
{
	int c;

	for (c = 0; src[c];)
	{
		dest[c] = src[c];
		c++;
	}

	return (dest);
}
