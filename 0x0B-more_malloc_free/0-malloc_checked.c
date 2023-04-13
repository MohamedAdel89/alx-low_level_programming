#include <stdlib.h>

/**
* malloc_checked -  allocates memory using malloc.
* b: size
* Return: pointer
*/

void *malloc_checked(unsigned int g)
{
void *p;
p = malloc(g);
if (p == NULL)
exit(98);
return (p);
}
