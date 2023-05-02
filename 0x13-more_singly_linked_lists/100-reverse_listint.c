#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * reverse_listint - check the code for Holberton School students.
 * @head:head
 * Return: head.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *pointer1, *pointer2;

	if (!*head)
	{
		return (*head);
	}
	if ((*head)->next == NULL)
	{
		return (*head);
	}
	pointer1 = *head;
	pointer2 = pointer1->next;
	*head = pointer2->next;
	pointer1->next = NULL;
	while (pointer2->next)
	{
		pointer2->next = pointer1;
		pointer1 = pointer2;
		pointer2 = *head;
		if ((*head)->next)
		{
			*head = (*head)->next;
		}
	}
	pointer2->next = pointer1;
	*head = pointer2;
	return (*head);
}
