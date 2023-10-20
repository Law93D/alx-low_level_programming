#include "lists.h"
#include <stdlib.h>

/**
 * free_list -  a function that frees a list_t list
 * @head: a pointer to the head of the list
 */

void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;

		free(current->str);
		free(current);
	}
}
