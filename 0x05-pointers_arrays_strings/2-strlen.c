#include <stdio.h>

/**
 * int _strlen -  a function that returns the length of a string
 * @str: lenght of a string
 * Return: 0
 */

int _strlen(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
			{
			length++;
			}
	return (length);
}
