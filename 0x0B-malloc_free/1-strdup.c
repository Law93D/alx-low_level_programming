#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicate to new memory
 * @str: char
 * Return: 0
 */

char *_strdup(char *str)
{
	char *zzz;
	int i, m = 0;

	if (str == NULL)
	return (NULL);

	i = 0;
	while (str[i] != '\0')
	i++;

	zzz = malloc(sizeof(char) * (i + 1));

	if (zzz == NULL)
	return (NULL);

	for (m = 0; str[m]; m++)
	zzz[m] = str[m];
	return (zzz);
}
