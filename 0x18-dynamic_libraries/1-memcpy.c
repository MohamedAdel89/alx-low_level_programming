/**
 *_memcpy - copies memory area.
 *@dest: destination pointer
 *@src: source pointer
 *@n: number of bytes to be copied
 *Return: a pointer to the memory area dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	for (; n; --n)
		*(dest + (n - 1)) = *(src + (n - 1));
	*(dest + n) = *(src + n);
	return (dest);
}
