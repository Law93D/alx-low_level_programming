#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * create_buffer - a function that allocates 1024 bytes for buffer
 * @file: file buffer for storing characters
 * Return: pointer to new-allocated buffer
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - funtion that closes file descriptor
 * @fd: file descriptor to close
 */

void close_file(int fd)
{
	int i;

	i = close(fd);

	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - a function that copy files from one file to another
 * @argc: input number of arguments supplied
 * @argv: pointer to the argument
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int f_fr, f_to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	f_fr = open(argv[1], O_RDONLY);
	r = read(f_fr, buffer, 1024);
	f_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f_fr == 1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(f_to, buffer, r);
		if (f_to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(f_fr, buffer, 1024);
		f_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close(f_fr);
	close(f_to);

	return (0);
}
