#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pritn_dlistint - Prints all elements of a doubly linked list
 * @h: Pointer to the head of the list
 * Return: The number of nodes in the list
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *new = h;
	size_t n_count = 0;

	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
		n_count++;
	}

	return (n_count);
}
