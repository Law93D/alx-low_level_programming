#include "main.h"
#include <stdio.h>

/**
 * flip_bits - Returns the number of bits to flip to get from n to m.
 * @n: The first unsigned long integer.
 * @m: The second unsigned long integer.
 * Return: The number of bits to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x = n ^ m;
	unsigned int count = 0;

	while (x > 0)
	{
		count += x & 1;
		x >>= 1;
	}

	return (count);
}
