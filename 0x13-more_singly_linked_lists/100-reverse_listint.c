#include "lists.h"
/**
 * reverse_listint - Reverse a linked list
 * @head: The head node
 * Return: @pointer to new element
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *next = NULL;
	listint_t *previous = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = next;
	}
	*head = previous;
	return (*head);
}
