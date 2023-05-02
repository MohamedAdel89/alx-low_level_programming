#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *insert_nodeint_at_index - inserts a new node at a given position
 *@head: head of the linked list
 *@idx: index of the node
 *@n: int to the new struct
 *Return: address of the new node.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new = malloc(sizeof(listint_t)), *tmp;
	unsigned int cont = 0;

	if (new == NULL || head == NULL)
		return (NULL);
	tmp = *head;
	new->n = n;
	while (cont != idx - 1 && tmp != NULL && idx != 0)
	{
		cont++;
		tmp = tmp->next;
	}
	if (*head == NULL || tmp != NULL)
	{
		if (idx == 0)
		{
			new->next = *head;
			*head = new;
		}
		else
		{
			new->next = tmp->next;
			(tmp)->next = new;
		}
		return (new);
	}
	else
	{
		free(new);
		return (NULL);
	}

}
