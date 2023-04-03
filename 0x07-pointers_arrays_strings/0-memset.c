char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
	/**
	 * This
	 * declares
	 * an
	 * unsigned
	 * int
	 */

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
