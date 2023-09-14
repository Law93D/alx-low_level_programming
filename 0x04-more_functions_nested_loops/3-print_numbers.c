#include "main.h"

/**
 * print_number - Print the numbers from 0 to 9
 * Return: The numbers from 0 to 9
 */

void print_numbera(void)
{
	int c;

	for (c = '0'; c <= '9'; c++)
	{
		_putchar(c + '0');
	}
	_putchar('\n');
}
