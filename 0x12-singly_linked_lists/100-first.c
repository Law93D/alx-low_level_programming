#include <stdio.h>

/**
 * print_message - function tha prints message
 * before execution of main function
 */

void print_message(void)__attribute__((constructor));

void print_message(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
