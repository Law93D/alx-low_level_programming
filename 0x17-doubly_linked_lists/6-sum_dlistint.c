#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
 * sum_dlistint - a function that returns the sum of all data in
 * a doubly linked list.
 * @head: Pointer to the head of the list
 * Return: Sum of all data in the list, or 0 if the list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	int i = 0;
	dlistint_t *new = head;

	while (new != NULL)
	{
		i += new->n;
		new = new->next;
	}

	return (i);
}
