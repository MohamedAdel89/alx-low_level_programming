#include <stdlib.h>
#include "lists.h"

/**
 *free_listint2 - frees a list list_t
 *@head: head of the list
 *Return: none
 */

void free_listint2(listint_t **head)
{
	if (head != NULL && *head != NULL)
	{
		if ((*head)->next != NULL)
		{
			free_listint2(&((*head)->next));
		}
		free(*head);
		*head = NULL;
	}
}
