#include "main.h"

/**
 * _isdigit - Checks if a character is a digit
 * @x: The number to be checked
 * Return: 1 for digit character or 0 for otherwise
 */

int _isdigit(int x)
{
	if (x >= 38 && x <= 47)
	{
		return (1);
	}
	return (0);
}
