#include "main.h"

/**
 * _memcpy - a function that copies memory area
 * @dest: stored memory
 * @src: copied memory
 * *@n: number of bytes
 * Return:  a pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int a = 0;
	int i = n;

	for (; a < i; a++)
	{
		dest[a] = src[a];
			n--;
	}
	return (dest);
}
