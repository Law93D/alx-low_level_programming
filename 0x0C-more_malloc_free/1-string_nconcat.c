#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * string_nconcat - function that concatenates two strings
 * @s1: input
 * @s2: input
 * @n: input number of bytes from s2 to concatenate to s1
 * Return: 0
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, len = 0, len = 0;
	char *str;

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;

	if (n < len2)
		s = malloc(sizeof(char) * (len1 + n + 1));
	else
		s = malloc(sizeof(char) * (len1 + len2 + 1));

	if (!s)
		return(NULL);

	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}

	while (n < len2 && i < (len1 + n))
		s[i++] = s2[j++];

	while (n >= len && i < (len1 + len2))
		s[i++] = s2[j++];

	s[i] = '\0';

	return (str);
}
