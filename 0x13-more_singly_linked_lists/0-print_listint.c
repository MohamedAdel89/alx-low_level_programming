#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 *print_listint - prints all the elements of a listint_t list
 *@h: list to print
 *Return: number of nodes
 */

size_t print_listint(const listint_t *h)
{
	unsigned int i = 0;

	while (h != NULL)
	{
		printf("%i\n", (*h).n);
		i++;
		h = (*h).next;
	}

	return (i);
}
