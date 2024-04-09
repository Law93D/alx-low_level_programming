#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursive helper function for advanced_binary
 * @array: A pointer to the first element of the array to search in.
 * @left: The left index of the array to search in.
 * @right: The right index of the array to search in.
 * @value: The value to search for.
 *
 * Return: The index where the value is located.
 *         -1 if the value is not present in the array or if the array is NULL.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    size_t i;
    int idx;

    if (left > right)
        return (-1);

    printf("Searching in array:");
    for (i = left; i <= right; i++)
    {
        printf(" %d", array[i]);
        if (i < right)
            printf(",");
    }
    printf("\n");

    idx = left + (right - left) / 2;

    if (array[idx] == value)
    {
        if (idx == 0 || array[idx - 1] != value)
            return (idx);
        return (advanced_binary_recursive(array, left, idx, value));
    }
    else if (array[idx] > value)
    {
        return (advanced_binary_recursive(array, left, idx - 1, value));
    }
    else
    {
        return (advanced_binary_recursive(array, idx + 1, right, value));
    }
}

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
    if (!array || size == 0)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}
