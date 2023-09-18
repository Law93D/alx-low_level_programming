#include "main.h"

/**
 * _puts - a function that prints a string,
 * followed by a new line, to stdout
 * @str: print
 * Return: 0
 */

void _puts(char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
	{
		 _putchar(*str);
            str++;
	}
		_putchar('\n');
	}
}
