#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the exponential search algorithm.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present in array or array is NULL, -1 is returned.
 *         Otherwise, the index where value is located is returned.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t prev = 0;

    if (array == NULL || size == 0)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        prev = bound;
        bound *= 2;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, bound);

    if (bound >= size)
        bound = size - 1;

    return (binary_search(array, value, prev));
}
