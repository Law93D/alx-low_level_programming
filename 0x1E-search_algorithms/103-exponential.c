#include "search_algos.h"
#include <stdio.h>

/**
 * min - Returns the minimum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The minimum of a and b
 */
size_t min(size_t a, size_t b)
{
	return (a < b ? a : b);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where value is located, or -1 if value is not present
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1, prev = 0;
    int ret;

    if (array == NULL || size == 0)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        prev = bound;
        bound *= 2;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, min(bound, size - 1));

    ret = binary_search(array, value, prev, min(bound, size - 1));

    return (ret);
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: Pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: The value to search for
 * @start: Starting index of the subarray to search
 * @end: Ending index of the subarray to search
 *
 * Return: Index where value is located, or -1 if value is not present
 */
int binary_search(int *array, int value, size_t start, size_t end)
{
    size_t left = start, right = end, mid;

    while (left <= right)
    {
        printf("Searching in array: ");
        for (size_t i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        mid = (left + right) / 2;

        if (array[mid] < value)
            left = mid + 1;
        else if (array[mid] > value)
            right = mid - 1;
        else
            return (mid);
    }

    return (-1);
}
