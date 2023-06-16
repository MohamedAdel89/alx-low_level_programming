#include <stdio.h>
#include "lists.h"

/**
 *sum_dlistint - returns the sum of all the data (n) of a dlistint_t linkedlist
 *@head: head of the linked list
 *Return: sum of all the data in the linked list
 */

int sum_dlistint(dlistint_t *head)
{
	static int sum;

	if (head != NULL)
	{
		if ((*head).next == NULL)
			return (sum + (*head).n);
		sum += (*head).n;
		return (sum_dlistint((*head).next));
	}
	return (0);
}
