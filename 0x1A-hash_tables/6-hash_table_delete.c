#include "hash_tables.h"
void free_list(hash_node_t *head);

/**
 *hash_table_delete - deletes a hash table.
 *@ht: hash table
 *Return: none
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *node;

	if (ht != NULL)
	{
		while (i < ht->size)
		{
			node = ht->array[i];
			free_list(node);
			i++;
		}
	}
	free(ht->array);
	free(ht);
}

/**
 *free_list - frees a list list_t
 *@head: head of the list
 *Return: none
 */

void free_list(hash_node_t *head)
{
	if (head != NULL)
	{
		if ((*head).next != NULL)
		{
			free_list((*head).next);
		}
		free((*head).key);
		free((*head).value);
		free(head);
	}
}
