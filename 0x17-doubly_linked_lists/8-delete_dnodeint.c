#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *delete_dnodeint_at_index - deletes the node at index index of linked list.
 *@head: head of the linked list
 *@index: index of the node to be deleted
 *Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head, *tmp_del = NULL;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		tmp_del = tmp;
		if ((*tmp).next != NULL)
			(*tmp).next->prev = NULL;
		*head = (*tmp).next;
		free(tmp_del);
		return (1);
	}
	index--;
	while (tmp != NULL && index != 0)
	{
		tmp = (*tmp).next;
		index--;
	}
	if (index == 0)
	{
		tmp_del = (*tmp).next;
		(*tmp).next = ((*tmp).next)->next;
		if ((*tmp).next != NULL)
			(*tmp).next->prev = tmp;
		free(tmp_del);
		return (1);
	}
	else
		return (-1);

}
