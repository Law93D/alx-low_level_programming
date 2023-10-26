#include "main.h"
#include <stdio.h>

/**
 * clear_bit - Clears the value of a bit to 0 at a given index.
 * @n: A pointer to the unsigned long integer.
 * @index: The index of the bit to clear (0-based).
 * Return: 1 if it worked, or -1 if an error occurred.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	i = 1UL << index;
	*n = *n & ~i;

	return (1);
}
