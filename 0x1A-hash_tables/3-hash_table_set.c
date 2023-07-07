#include <string.h>
#include "hash_tables.h"
hash_node_t *add_node(hash_node_t **head, const char *str);

/**
 *hash_table_set - adds an element to the hash table.
 *@ht: hash table
 *@key: key
 *@value: value of the key
 *Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new = NULL, *node = NULL;

	if (ht == NULL || strcmp(key, "") == 0 || key == NULL || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
		node = node->next;
	}
	new = add_node(&(ht->array[index]), value);
	if (new == NULL)
		return (0);
	new->key = strdup(key);
	return (1);
}

/**
 *add_node - add a node at the beginning of the list
 *@head: pointer to a linked list
 *@str: string to be added
 *Return: address of the new element
 */

hash_node_t *add_node(hash_node_t **head, const char *str)
{
	hash_node_t *new = NULL;

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (NULL);
	(*new).value = strdup(str);
	if ((*new).value == NULL)
	{
		free(new);
		return (NULL);
	}
	(*new).next = *head;
	*head = new;
	return (new);
}
