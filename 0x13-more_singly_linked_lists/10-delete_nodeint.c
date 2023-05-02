#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *delete_nodeint_at_index - deletes the node at index index of
 *a listint_t list.
 *@head: head of the linked list
 *@index: index of the node to be deleted
 *Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp = *head, *del = *head;
	unsigned int cont = 0;

	while (cont != (index - 1) && tmp != NULL && index != 0)
	{
		cont++;
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		if (index == 0)
		{
			del = tmp;
			*head = tmp->next;
			free(del);
		}
		else
		{
			del = tmp->next;
			tmp->next = tmp->next->next;
			free(del);
		}
		return (1);
	}
	else
	{
		return (-1);
	}

}
