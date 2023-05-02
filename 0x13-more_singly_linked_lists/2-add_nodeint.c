#include <stdlib.h>
#include "lists.h"
#include <string.h>

/**
 *add_nodeint - add a node at the beginning of the list
 *@head: pointer to a linked list
 *@n: int to be added
 *Return: address of the new element
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = NULL;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	(*new).n = n;
	(*new).next = *head;
	*head = new;
	return (new);
}
