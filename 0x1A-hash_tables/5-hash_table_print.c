#include <stdio.h>
#include "hash_tables.h"

/**
 *hash_table_print - prints a hash table.
 *@ht: hash table
 *Return: none
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *node;
	char sep[3] = "\0\0\0";
	int sw = 0;

	if (ht != NULL)
	{
		putchar('{');
		while (i < ht->size)
		{
			node = ht->array[i];
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
				node = node->next;
			}
			i++;
		}
		puts("}");
	}
}
