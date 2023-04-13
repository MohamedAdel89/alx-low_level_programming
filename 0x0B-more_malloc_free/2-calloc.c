#include <stdlib.h>

/**
* _calloc - memory for an array.
* nmemb: number of elements
* size:  size bytes
* Return: pointer to array
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int g;

	if (nmemb == 0 || size == 0)
	return (0);
	p = malloc(size * nmemb);
	if (p == NULL)
	return (0);
	for (g = 0; g < nmemb * size; g++)
	{
		p[g] = 0;
	}
return (p);
}
