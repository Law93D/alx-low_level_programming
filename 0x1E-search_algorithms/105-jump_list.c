#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list using jump search
 * @list: Pointer to the head of the list
 * @size: Number of nodes in the list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, otherwise NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t step = sqrt(size), prev = 0, i;
    listint_t *curr = list, *prev_node = NULL;

    if (list == NULL)
        return (NULL);

    while (curr != NULL && curr->n < value)
    {
        prev_node = curr;
        for (i = 0; i < step && curr->next != NULL; i++)
            curr = curr->next;

        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);

        if (curr->next == NULL)
            break;

        prev = curr->index;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, curr->index);

    while (prev_node != NULL && prev_node->index <= curr->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev_node->index, prev_node->n);
        if (prev_node->n == value)
            return (prev_node);
        prev_node = prev_node->next;
    }

    return (NULL);
}
