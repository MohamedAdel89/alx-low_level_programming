#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *get_nodeint_at_index - search for the nth node of a linked list
 *@head: head of the linked list
 *@index: index of the node
 *Return: returns the nth node of a linked list
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head != NULL)
	{
		while (i != index && head != NULL)
		{
			head = head->next;
			i++;
		}
		return (head);
	}
	return (NULL);
}
