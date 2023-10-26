#include "main.h"
#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */

void print_binary(unsigned long int n)
{
	int i;
	int flag = 0;

	for (i = sizeof(n) * 8 - 1; i >= 0; i--)
	{
		unsigned long int mask = 1UL << i;

		if ((n & mask) == mask)
		{
			putchar('1');
			flag = 1;
		}

		else if (flag)
		{
			putchar('0');
		}
	}

	if (!flag)
	{
		putchar('0');  /* Handle the case when n is 0 */
	}
}
