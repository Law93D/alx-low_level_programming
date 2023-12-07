#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_dlistint - Function that frees a doubly linked list.
 * @head: Pointer to the head of the list.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	dlistint_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
