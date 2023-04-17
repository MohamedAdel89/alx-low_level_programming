#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *free_dog - release the dog
 *@d: pointer to structure
 *Return: none
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free((*d).name);
		free((*d).owner);
		free(d);
	}
}
