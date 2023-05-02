#include <stdio.h>
#include "lists.h"

/**
 *find_listint_loop - finds a loop within a linked list
 *@head: head of the linked list
 *Return: beginning of the loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle = head, *hare = head;

	while (hare != NULL && hare->next != NULL)
	{
		if (turtle == hare)
		{
			hare = head;
			while (turtle != hare)
			{
				turtle = turtle->next;
				hare = hare->next;
			}
			break;
		}
		turtle = turtle->next;
		hare = hare->next->next;
	}
	return (hare);
}
