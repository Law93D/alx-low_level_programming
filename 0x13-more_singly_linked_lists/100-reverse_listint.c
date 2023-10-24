#include <stddef.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to a pointer to the head of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *new_head;
	listint_t *tmp;

	if (head == NULL || *head == NULL)
	{
		return (NULL);
	}
	tmp = *head;
	*head = tmp->next;
	tmp->next = NULL;

	while (*head != NULL)
	{
		new_head = (*head)->next;
		(*head)->next = tmp;
		tmp = *head;
		if (new_head == NULL)
			return (*head);
		*head = new_head;
	}
	if (*head == NULL)
	{
		*head = tmp;
		return (new_head);
	}
	return (NULL);
}
