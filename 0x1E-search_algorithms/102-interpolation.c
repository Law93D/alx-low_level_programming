#include <stdio.h>
#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * using the Interpolation search algorithm
 * @array: Pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: Index where value is located, or -1 if value is not present
 */
int interpolation_search(int *array, size_t size, int value)
{
    size_t low = 0, high = size - 1;
    size_t pos;

    if (array == NULL || size == 0)
        return (-1);

    while (low <= high && value >= array[low] && value <= array[high])
    {
        if (low == high)
        {
            if (array[low] == value)
                return (low);
            return (-1);
        }

        pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));

        printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

        if (array[pos] == value)
            return (pos);
        if (array[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }

    printf("Value checked array[%lu] is out of range\n", pos);
    return (-1);
}
