#include "main.h"

/**
 * print_numbers - Print the numbers 0 to 9
 * Return: void
 */

void print_numbera(void)
{
	char c;

	for (c = '0'; c <= '9'; c++)
	{
		_putchar(c + '0');
	}
	_putchar('\n');
}
