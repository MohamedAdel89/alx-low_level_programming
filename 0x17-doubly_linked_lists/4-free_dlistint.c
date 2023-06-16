#include <stdlib.h>
#include "lists.h"

/**
 *free_dlistint -  free a dlistint_t list.
 *@head: head of the list.
 *Return: none
 */

void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return;
	free_dlistint((*head).next);
	free(head);
}
