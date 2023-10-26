#include "main.h"
#include <stdio.h>

/**
 * get_endianness - Checks the endianness of the system.
 * Return: 0 if the system is big-endian, 1 if it is little-endian.
 */

int get_endianness(void)
{
	unsigned int test_value = 1;
	unsigned char *byte_ptr = (unsigned char *)&test_value;

	if (*byte_ptr == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
