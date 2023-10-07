#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * string_nconcat - function that concatenates two strings
 * @s1: input
 * @s2: input
 * @n: input
 * Return: 0
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, k = 0, l = 0;
	char *str;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	while (s2[i])
		i++;

	if (n >= i)
	{
		l = i + k;
	}
	else
		l = i + n;

	str = malloc(sizeof(char) * l + 1);
	if (str == NULL)
		return (NULL);

	while (j < l)
	{
		if (j <= i)
		{
			str[j] = s1[k];
		}
		if (j >= i)
		{
			str[j] = s2[k];
		}
		j++;
	}
	str[j] = '\0';
	return (str);
}
