#include "lists.h"
#include <stdio.h>
#include <string.h>

/**
 * len - length of string
 * @str: input string
 * Return: length amount
 */

int len(const char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * create_node - function that creates node
 * @str: input string
 * Return: pointer to memory
 */

list_t *create_node(const char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	new_node->len = strlen(str);
	new_node->next = NULL;
	return (new_node);
}

/**
 * add_node_end - function that adds a new node at the end of a list_t list
 * @str: input string
 * @head: input pointer to first node
 * Return: pointer to head
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp;
	list_t *new_node;

	if (head == NULL || str == NULL)
		return (NULL);
	new_node = create_node(str);
	if (new_node == NULL)
		return (NULL);

	temp = *head;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	return (*head);
}
