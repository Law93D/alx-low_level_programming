#include "main.h"
#include <stdio.h>

/**
 * puts_recursion - a function that prints a string,
 * followed by a new line
 * @s: string to print
 * Return: 0
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	if (*s == '\0')
	{
		_putchar('\n');
	}
}
