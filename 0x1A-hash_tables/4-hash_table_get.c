#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key in a hash table
 * @ht: Hash table to look into
 * @key: Key string to search for
 *
 * Return: Value associated with the element, or NULL if key couldn’t be found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *temp = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	return (NULL);
}
