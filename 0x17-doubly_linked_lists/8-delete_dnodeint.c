#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - function that deletes the node at a given index
 * @index: Index node to be deleted (starting at 0)
 * @head: Pointer to the head of the list
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *new = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = new->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(new);
		return (1);
	}

	while (new != NULL && i < index)
	{
		new = new->next;
		i++;
	}

	if (new == NULL)
	{
		return (-1);
	}

	if (new ->next != NULL)
	{
		new->next->prev = new->prev;
	}
	if (new->prev != NULL)
	{
		new->prev->next = new->next;
	}

	free(new);
	return (1);
}
