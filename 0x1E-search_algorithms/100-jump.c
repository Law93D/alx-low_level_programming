#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: Pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where value is located, or -1 if value is not present
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size);
    size_t prev = 0;

    if (array == NULL || size == 0)
        return (-1);

    while (array[prev] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
        prev += step;
        if (prev >= size)
            break;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);
    prev = (prev < size) ? prev : size - 1;

    for (size_t i = prev - step; i <= prev; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return (i);
    }

    return (-1);
}
