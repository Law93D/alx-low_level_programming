#include <stdio.h>

/**
 * int _strlen -  a function that returns the length of a string
 * @str: lenght of a string
 * Return: 0
 */

size_t _strlen(const char *str)
{
	size_t length = 0;

	while (*str++)
		length++;
	return (length);
}
