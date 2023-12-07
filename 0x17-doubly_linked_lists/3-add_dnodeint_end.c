#include "lists.h"
#include <stdlib.h>

/**
 *  add_dnodeint_end - Function that adds a new node at
 *  the end of a doubly linked list
 *  @head: Pointer to the head of the list
 *  @n: Value to be inserted
 *  Return: Address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *last;

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;

		return (new_node);
	}

	for (last = *head; last->next != NULL; last = last->next);

	last->next = new_node;
	new_node->prev = last;

	return (new_node);
}
