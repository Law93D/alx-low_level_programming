#include "main.h"
#include <stdlib.h>

/**
 * create_array - function that creates an array of chars
 * @size: size of array
 * @c: character
 * Description: create array of size and assign char c 
 * Return: pointer to array, NULL if fail
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *str;

	s = malloc(size * sizeof(char));
	if (size == 0 || str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		str[i] = c;
	return (str);
}
