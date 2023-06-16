#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *insert_dnodeint_at_index - inserts a new node at a given position
 *@h: head of the linked list
 *@idx: index of the node
 *@n: int to the new struct
 *Return: address of the new node.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t)), *tmp;
	unsigned int cont = 0;

	if (new == NULL || h == NULL)
		return (NULL);
	tmp = *h;
	new->n = n;
	while (cont != idx - 1 && tmp != NULL && idx != 0)
	{
		cont++;
		tmp = tmp->next;
	}
	if (*h == NULL || tmp != NULL)
	{
		if (idx == 0)
		{
			new->next = *h;
			new->prev = NULL;
			if (*h != NULL)
				(*h)->prev = new;
			*h = new;
		}
		else
		{
			new->next = tmp->next;
			new->prev = tmp;
			(tmp)->next = new;
			if (new->next != NULL)
				new->next->prev = new;
		}
		return (new);
	}
	else
	{
		free(new);
		return (NULL);
	}

}
