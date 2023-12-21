#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shash_tables.h>

shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
       	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return ht;
}

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash;
}

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

shash_node_t *shash_node_create(const char *key, const char *value)
{
	shash_node_t *node = malloc(sizeof(shash_node_t));

	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
       	{
		free(node);
		return (NULL;)
	}

	node->value = strdup(value);
	if (node->value == NULL)
       	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	return node;
}

void shash_table_insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	if (ht == NULL || node == NULL)
		return;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	shash_node_t *current = ht->shead;
	shash_node_t *prev = NULL;

	while (current != NULL && strcmp(current->key, node->key) < 0)
	{
		prev = current;
		current = current->snext;
	}

	if (prev == NULL)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else if (current == NULL)
	{
		prev->snext = node;
		node->sprev = prev;
		ht->stail = node;
	}
	else
	{
		prev->snext = node;
		node->sprev = prev;
		node->snext = current;
		current->sprev = node;
	}
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	shash_node_t *new_node = shash_node_create(key, value);

	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	shash_table_insert_sorted(ht, new_node);

	return (1);
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	if (ht == NULL || key == NULL)
		return (NULL);

	unsigned long int index = key_index((const unsigned char *)key, ht->size);

	shash_node_t *current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return current->value;
		current = current->next;
	}

	return (NULL);
}

void shash_table_print(const shash_table_t *ht)
{
	if (ht == NULL)
		return;

	shash_node_t *current = ht->shead;
	while (current != NULL)
	{
		printf("{'%s': '%s'}", current->key, current->value);
		if (current->snext != NULL)
			printf(", ");
		current = current->snext;
	}

	printf("\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
	if (ht == NULL)
		return;

	shash_node_t *current = ht->stail;
	while (current != NULL)
	{
		printf("{'%s': '%s'}", current->key, current->value);
		if (current->sprev != NULL)
			printf(", ");
		current = current->sprev;
	}
	printf("\n");
}

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		shash_node_t *current = ht->array[i];
		while (current != NULL)
		{
			shash_node_t *temp = current;
			current = current->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
		ht->array[i] = NULL;
	}

	ht->shead = NULL;
	ht->stail = NULL;
	free(ht->array);
	free(ht);
}
