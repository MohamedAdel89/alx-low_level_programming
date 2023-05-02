#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *sum_listint - sum of all the data (n) of a listint_t linked list
 *@head: head of the list
 *Return: sum of all the data in the linked list
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head != NULL)
	{
		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
		return (sum);
	}
	else
	{
		return (0);
	}
}
