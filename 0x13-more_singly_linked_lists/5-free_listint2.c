#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - frees a listint_t and sets the head to NULL
 * @head: a pointer to a pointer to the head of the list
 */

void free_listint2(listint_t **head)
{
	listint_t *current, *tmp;

	if (head == NULL || *head == NULL)
		return;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}

	*head = NULL;
}
