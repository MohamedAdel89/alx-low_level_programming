#include <stdio.h>
#include "dog.h"

/**
 *print_dog - prints a struct dog
 *@d: pointer to the dog structure
 *Return: none
 */

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		if ((*d).name != NULL)
			printf("Name: %s\n", (*d).name);
		else
			printf("Name: %p\n", (*d).name);
		printf("Age: %.6f\n", (*d).age);
		if ((*d).owner != NULL)
			printf("Owner: %s\n", (*d).owner);
		else
			printf("Owner: %p\n", (*d).owner);
	}
}
