#include "search_algos.h"
#include <stdlib.h>

/**
 * create_list - Creates a new linked list node
 * @n: The value to be stored in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
listint_t *create_list(int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->next = NULL;

    return new_node;
}
