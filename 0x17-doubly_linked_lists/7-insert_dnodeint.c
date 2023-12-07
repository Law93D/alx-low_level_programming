#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - a function that inserts a
 * new node at a given position.
 * @h: Pointer to the head of the list
 * @idx: Index of new node (starting at 0)
 * @n: Value to be inserted in the new node
 * Return: Address of the new node, or NULL if it failed.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *i = *h;
	unsigned int j = 0;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (idx == 0)
	{
		new_node->next = *h;
		if (*h != NULL)
		{
			(*h)->prev = new_node;
			*h = new_node;
		}
		return new_node;
	}

	while (i != NULL && j < idx - 1)
	{
		i = i->next;
		j++;
	}

	if (i == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = i->next;
	new_node->prev = i;

	if (i->next != NULL)
	{
		i->next->prev = new_node;
		i->next = new_node;
	}

	return (new_node);
}
