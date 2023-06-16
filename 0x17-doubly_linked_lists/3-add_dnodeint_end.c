#include <stdlib.h>
#include "lists.h"

/**
 *add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 *@head: head of the doubly linked list
 *@n: data to put in
 *Return: address to the new node
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t)), *tmp = *head;

	if (new_node == NULL)
		return (NULL);
	(*new_node).n = n;
	(*new_node).next = NULL;
	if (tmp != NULL)
	{
		while ((*tmp).next != NULL)
			tmp = (*tmp).next;
		(*tmp).next = new_node;
	}
	else
	{
		*head = new_node;
	}
	(*new_node).prev = tmp;
	return (new_node);
}
