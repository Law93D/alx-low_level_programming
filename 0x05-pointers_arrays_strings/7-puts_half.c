#include "main.h"

/**
 * puts_half - print half of a string
 * @str: string to print
 * Return: half of input
 */


void puts_half(char *str)
{
        int x, y, longi;

	longi = 0;

	for (x = 0; str[x] != '\0'; x++)
		longi++;

	y = (longi / 2);

	if ((longi % 2) == 1)
		y = ((longi + 1) / 2);

	for (x = y; str[x] != '\0'; x++)
		_putchar(str[x]);	
        _putchar('\n');
}
