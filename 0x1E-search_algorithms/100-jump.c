#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array using jump search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, otherwise -1
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size), prev = 0, i;

    if (array == NULL)
        return (-1);

    for (i = 0; i < size; i += step)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] >= value || i + step >= size)
        {
            printf("Value found between indexes [%lu] and [%lu]\n", prev, i);
            printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
            while (prev <= i && array[prev] < value)
            {
                printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
                prev++;
            }
            if (prev < size && array[prev] == value)
                return (prev);
            else
                return (-1);
        }
        prev = i;
    }

    return (-1);
}
