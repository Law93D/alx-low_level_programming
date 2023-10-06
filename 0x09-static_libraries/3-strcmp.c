#include "main.h"

/**
 * _strcmp - a function that compares two strings
 * @s1: first string to be compared
 * @s2: second string
 * Return: if str1 < str2, negative diff
 * if str1 == str2, 0.
 * if str1 > str2, positive diff
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
