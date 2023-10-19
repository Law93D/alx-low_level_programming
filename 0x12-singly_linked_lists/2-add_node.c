#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node -  function that adds a new node at the beginning of a list_t list
 * @str: input string to be inserted
 * @head: input pointer
 * Return: pointer to the first node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	if (*head == NULL)

		new_node->next = NULL;
	else
	{
		new_node->next = *head;
	}
		new_node->str = strdup(str);
		new_node->len = strlen(str);
		*head = new_node;
	return (*head);
}

/**
 * len - length of a string
 * @str: input string
 * Return: length of string
 */

int len(const char *str)
{
	int i;

	if (str == NULL)
		return (0);

			i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
