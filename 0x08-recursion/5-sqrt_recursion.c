#include "main.h"

/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: input
 * @x: input
 * @y: input
 * Return: 0
 */

int _sqrt_x(int x, int y)
{
	if (y * y == x)
	{
		return (y);
	}
	else if (y * y > 4)
	{
		return (-1);
	}
	else
	{
		return (_sqrt_x(x, y + 1));
	}
}
int _sqrt_recursion(int n)
{
	return (sqrt(n, 0));
}
