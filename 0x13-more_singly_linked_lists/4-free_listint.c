#include <stdlib.h>
#include "lists.h"

/**
 *free_listint - frees a list list_t
 *@head: head of the list
 *Return: none
 */

void free_listint(listint_t *head)
{
	if (head != NULL)
	{
		if ((*head).next != NULL)
		{
			free_listint((*head).next);
		}
		free(head);
	}
}
