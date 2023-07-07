#include <stdio.h>
#include <string.h>
#include "hash_tables.h"
void free_list(shash_node_t *head);
shash_node_t *sort_node(shash_node_t **head, shash_node_t **tail,
			shash_node_t *new);

/**
 *shash_table_create - function that creates a hash table
 *@size: size of the array
 *Return: pointer to the hash table
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table = malloc(sizeof(shash_table_t));

	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = calloc(size, sizeof(shash_node_t *));
	table->shead = NULL;
	table->stail = NULL;
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	return (table);
}

shash_node_t *sadd_node(shash_node_t **head, const char *str);

/**
 *shash_table_set - adds an element to the hash table.
 *@ht: hash table
 *@key: key
 *@value: value of the key
 *Return: 1 if it succeeded, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new = NULL, *node = NULL;

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
	new = sadd_node(&(ht->array[index]), value);
	if (new == NULL)
		return (0);
	new->key = strdup(key);
	node = sort_node(&(ht->shead), &(ht->stail), new);
	return (1);
}

/**
 *sadd_node - add a node at the beginning of the list
 *@head: pointer to a linked list
 *@str: string to be added
 *Return: address of the new element
 */

shash_node_t *sadd_node(shash_node_t **head, const char *str)
{
	shash_node_t *new = NULL;

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (NULL);
	(*new).value = strdup(str);
	if ((*new).value == NULL)
	{
		free(new);
		return (NULL);
	}
	(*new).next = *head;
	(*new).sprev = NULL;
	(*new).snext = NULL;
	*head = new;
	return (new);
}

/**
 *shash_table_print - prints a hash table.
 *@ht: hash table
 *Return: none
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char sep[3] = "\0\0\0";
	int sw = 0;

	if (ht != NULL)
	{
		putchar('{');
		node = ht->shead;
		while (node != NULL)
		{
			if (sw == 1)
			{
				sep[0] = ',';
				sep[1] = ' ';
				sep[2] = '\0';
			}
				printf("%s'%s': '%s'", sep, node->key, node->value);
				sw = 1;
				node = node->snext;
		}
		puts("}");
	}
}

/**
 *sort_node - inserts a number into a sorted singly linked list.
 *@head: head of the linked list
 *@tail: tail of the linked list
 *@new: node to sort
 *Return: the address of the new node, or NULL if it failed
 */

shash_node_t *sort_node(shash_node_t **head, shash_node_t **tail,
			shash_node_t *new)
{
	char *val = new->key;
	shash_node_t *head_cpy, *tmp;

	if (*head != NULL)
	{       head_cpy = *head;
		tmp = *head;          }
	else
	{       (*new).snext = NULL;
		(*new).sprev = NULL;
		*head = new;
		*tail = new;
		return (new);         }
	while (head_cpy != NULL)
	{
		if (strcmp((*head_cpy).key, val) > 0)
			break;
		tmp = head_cpy;
		head_cpy = (*head_cpy).snext;
	}
	if (head_cpy != NULL && tmp == *head)
	{
		if (head_cpy->sprev != NULL && head_cpy->sprev->sprev == NULL)
			goto sort_node;
		else
		{
			(*new).snext = tmp;
			(*tmp).sprev = new;
			*head = new;
		}
		return (new);
	}
sort_node:
	(*new).sprev = tmp;
	(*new).snext = (*tmp).snext;
	(*tmp).snext = new;
	if ((*new).snext == NULL)
		*tail = new;
	else
		new->snext->sprev = new;
	return (new);
}

/**
 *shash_table_print_rev - prints a hash table in reverse sorted.
 *@ht: hash table
 *Return: none
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char sep[3] = "\0\0\0";
	int sw = 0;

	if (ht != NULL)
	{
		putchar('{');
		node = ht->stail;
		while (node != NULL)
		{
			if (sw == 1)
			{
				sep[0] = ',';
				sep[1] = ' ';
				sep[2] = '\0';
			}
				printf("%s'%s': '%s'", sep, node->key, node->value);
				sw = 1;
				node = node->sprev;
		}
		puts("}");
	}
}

/**
 *shash_table_get - retrieves a value associated with a key.
 *@ht: hash table
 *@key: key of the hash table
 *Return: the value associated with the element,
 *or NULL if key couldn’t be found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t *node;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
 *shash_table_delete - deletes a hash table.
 *@ht: hash table
 *Return: none
 */

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *node;

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

void free_list(shash_node_t *head)
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

/**
 *_strcmp - compares two strings.
 *@s1: string one
 *@s2: string two
 *Return: int if zero s1 = s2, if neg s1 < s2 and if pos s2 < s1
 */

int _strcmp(char *s1, char *s2)
{
	int i1 = 0;
	int i2 = 0;
	int c = 0;

	while (c == 0 && (*(s1 + i1) || *(s2 + i2)))
	{
		c = *(s1 + i1) - *(s2 + i2);
		i1++;
		i2++;
	}
	return (c);
}
