#include "main.h"

/**
 * create_array - create an array of char and initialize with a specific char
 * @size: size of array
 * @c: parameter character
 *
 * Return: NULL.
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr;

	if (size == 0)
	{
		return (NULL);
	}
	arr = (char *)malloc(size * sizeof(char));

	if (arr == NULL)
	{
		return (NULL);
	}
	for (i = 0 ; i < size ; i++)
	{
		arr[i] = c;
	}
	return (arr);
}
