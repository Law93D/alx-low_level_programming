#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not
 *         found or head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express, *prev;

    if (list == NULL)
        return (NULL);

    express = list->express;
    prev = list;

    while (express != NULL)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        if (express->n >= value)
        {
            printf("Value found between indexes [%lu] and [%lu]\n",
                   prev->index, express->index);

            while (prev != NULL && prev->index <= express->index)
            {
                printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
                if (prev->n == value)
                    return (prev);
                prev = prev->next;
            }
            break;
        }
        prev = express;
        express = express->express;
        if (!express)
        {
            express = prev->next;
            while (express->next != NULL)
                express = express->next;
        }
    }

    printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
    printf("Value found between indexes [%lu] and [%lu]\n",
           prev->index, express->index);
    while (prev != NULL && prev->index <= express->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }
    return (NULL);
}
