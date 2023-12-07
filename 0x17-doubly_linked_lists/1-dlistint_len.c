#include "lists.h"
#include <stddef.h>

/**
 * dlistint_len - Returns the number of elements in
 * a doubly linked list
 * @h: Pointer to the head of the list
 * Return: The number of nodes in the list
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *new = h;
	size_t n_count = 0;

	while (new != NULL)
	{
		n_count++;
		new = new->next;
	}

	return (n_count);
}
