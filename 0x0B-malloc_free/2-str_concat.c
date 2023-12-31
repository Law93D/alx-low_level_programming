#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - function that concatenates two strings
 * @s1: input string
 * @s2: input string
 * Return: concat of s1 and s2
 */


char *str_concat(char *s1, char *s2)
{
	char *conct;
	int i, x;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = x = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[x] != '\0')
		x++;
	conct = malloc((i + x + 1) * sizeof(char));

	if (conct == NULL)
	return (NULL);
	i = x = 0;
	while (s1[i] != '\0')
	{
	conct[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
	conct[i] = s2[x];
		i++;
		x++;
	}
	conct[i] = '\0';
	return (conct);
}
