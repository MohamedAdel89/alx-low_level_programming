#include <stdlib.h>
#include "function_pointers.h"

/**
 *array_iterator - executes a function given as a parameter on each element
 *@array: pointer to the array
 *@size: size of the array
 *@action: function to execute
 *Return: none
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array != NULL && action != NULL && size != 0)
	{
		for (i = 0; i < size; i++)
			(*action)(array[i]);
	}
}
