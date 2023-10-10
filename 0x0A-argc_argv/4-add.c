#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main -  program that adds positive numbers
 * @argc: input
 * @argv: input
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int a = 1;
	unsigned int b, sum = 0;
	char *e;

	if (argc > 1)
	{
		for (a = 1; a < argc; a++)
		{
			e = argv[a];
			
			for (b = 0; b < strlen(e); b++)
			{
				if (e[b] < 48 || e[b] > 57)
				{
					printf("Error\n");
					return (1);
				}
			}
			sum += atoi(e);
			e++;
		}
		printf("%d\n", sum);
	}
	else
	{
		printf("0\n");
	}
	return (0);
}
