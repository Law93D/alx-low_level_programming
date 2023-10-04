#include "main.h"
#include <stdlib.h>

/**
 * create_array - array of characters
 * @size: size of array
 * @c: character
 * Return: array filled
 * /
 
 char *create_array(unsigned int size, char c)
 {
 	unsigned int i;
	char *s;

	if (size == 0)
	return (null);

	s = malloc(size * sizeof(char));

	if (s == NULL)
	return (NULL);

	for (i = 0; i < size; i++)
	{
		s[i] = c;
	}
	return (s);
}
