#include <stdio.h>
#include "lists.h"

/**
 *get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 *@head: head of the linked list
 *@index: index of the node to be found
 *Return: pointer to the node wanted
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	if (head == NULL)
		return (NULL);
	else if (index == 0)
		return (head);
	else
		return (get_dnodeint_at_index((*head).next, --index));
}
