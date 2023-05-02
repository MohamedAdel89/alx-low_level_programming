#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *pop_listint - deletes the head node of a listint_t linked list
 *@head: head of the list
 *Return: the head node’s data.
 */

int pop_listint(listint_t **head)
{
	listint_t *tmpStruct;
	int tmp;

	if (head != NULL && *head != NULL)
	{
		tmp  = (*head)->n;
		tmpStruct = (*head)->next;
		free(*head);
		*head = tmpStruct;
		return (tmp);
	}
	else
	{
		return (0);
	}
}
