#include <stdio.h>
#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The unsigned long integer.
 * @index: The index of the bit to get.
 *
 * Return: The value of the bit at the specified index (0 or 1),
 * or -1 if an error occurred.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int k;

	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	k = 1UL << index;

	if ((n & k) == k)
	{
		return (1);
	}

	else
	{
		return (0);
	}
}
