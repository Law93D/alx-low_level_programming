#include "main.h"
#include <stdio.h>

/**
 * main -  program that prints all arguments it receives
 * @argc: input
 * @argv: input
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int a;

	for (a = 0; a < argc; a++)
	{
		printf("%s\n", argv[a]);
	}
	return (0);
}

