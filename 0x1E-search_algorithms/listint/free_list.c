#include "search_algos.h"
#include <stdlib.h>

/**
 * free_list - Frees a linked list
 * @head: Pointer to the head of the list
 */
void free_list(listint_t *head)
{
    listint_t *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
