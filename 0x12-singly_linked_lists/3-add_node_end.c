#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <string.h>
int _strlen(const char *s);

/**
 *add_node_end - add a node at the beginning of the list
 *@head: pointer to a linked list
 *@str: string to be added
 *Return: address of the new element
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = NULL, *tmp = *head;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	(*new).str = strdup(str);
	if ((*new).str == NULL)
	{
		free(new);
		return (NULL);
	}
	(*new).len = _strlen(str);
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

/**
 *_strlen - compute the length of a string.
 *@s: string
 *Return: length of a string.
 */

int _strlen(const char *s)
{
	int cont = 0;

	while (*(s + cont) != '\0')
	{
		cont++;
	}
	return (cont);
}
