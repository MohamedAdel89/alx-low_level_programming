#include <stdlib.h>
#include "lists.h"

/**
 *free_list - frees a list list_t
 *@head: head of the list
 *Return: none
 */

void free_list(list_t *head)
{
	if (head != NULL)
	{
		if ((*head).next != NULL)
		{
			free_list((*head).next);
		}
		free((*head).str);
		free(head);
	}
}
