#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located.
 *         -1 if the value is not present in the array or if the array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t i;
    int idx;

    if (!array || size == 0)
        return (-1);

    printf("Searching in array:");
    for (i = 0; i < size; i++)
    {
        printf(" %d", array[i]);
        if (i < size - 1)
            printf(",");
    }
    printf("\n");

    if (size == 1 && array[0] != value)
        return (-1);

    idx = size / 2;

    if (array[idx] == value)
    {
        if (array[idx - 1] < value)
            return (idx);
        return (advanced_binary(array, idx + 1, value));
    }
    else if (array[idx] > value)
    {
        return (advanced_binary(array, idx, value));
    }
    else
    {
        int sub_result = advanced_binary(array + idx + 1, size - idx - 1, value);
        if (sub_result == -1)
            return (-1);
        return (idx + 1 + sub_result);
    }
}
