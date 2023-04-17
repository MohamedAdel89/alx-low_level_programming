#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
char *_strcpy(char *s);

/**
 *new_dog - creates a new dog
 *@name: name of the dog
 *@age: age of the dog
 *@owner: owner of the dog
 *Return: pointer to the structure
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
	{
		free(dog);
		return (NULL);
	}
	(*dog).name = _strcpy(name);
	if ((*dog).name == NULL)
	{
		free(dog);
		return (NULL);
	}
	(*dog).owner = _strcpy(owner);
	if ((*dog).owner == NULL)
	{
		free((*dog).name);
		free(dog);
		return (NULL);
	}
	(*dog).age = age;

	return (dog);

}

/**
 *_strcpy - copy a string
 *@s: string to copy
 *Return: pointer to copy
 */

char *_strcpy(char *s)
{
	int i = 0;
	char *cpy;

	if (s == NULL)
		return (NULL);
	while (*(s + i))
		i++;
	i++;
	cpy = malloc(i * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i--;
	for (; i >= 0; i--)
	{
		*(cpy + i) = *(s + i);
	}
	return (cpy);
}
