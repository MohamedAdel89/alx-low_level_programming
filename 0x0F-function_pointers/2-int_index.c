#include <stdlib.h>
#include "function_pointers.h"

/**
 *int_index - checks an integer
 *@array: array to search
 *@size: size of the array
 *@cmp: function to call
 *Return: index of the first element
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL)
	{
		if (size <= 0)
			return (-1);
		for (i = 0; i < size; i++)
			if ((*cmp)(array[i]))
				return (i);
	}
		return (-1);
}
