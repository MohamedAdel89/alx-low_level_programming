#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *add_nodeint_end - add a node at the end of the list
 *@head: pointer to a linked list
 *@n: int to be added
 *Return: address of the new element
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new = NULL, *tmp = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	(*new).n = n;
	(*new).next = NULL;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while ((*tmp).next != NULL)
			tmp = (*tmp).next;
		(*tmp).next = new;
	}
	return (new);
}
