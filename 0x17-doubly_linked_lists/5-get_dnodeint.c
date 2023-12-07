#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_dnodeint_at_index - A function that returns the
 * nth node of a doubly linked list.
 * @index: Index of the node, starting from 0.
 * @head: Pointer to the head of the list.
 * Return: Pointer to the nth node or NULL if it doesn't exist.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *new= head;

	while (new != NULL && index > 0)
	{
		new = new->next;
		index--;
	}

	return (new);
}
