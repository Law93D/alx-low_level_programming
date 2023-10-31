#include "main.h"
#include <stdio.h>

/**
 * error_file - check if a file is opened and handle errors
 * @file_from: file to copy from
 * @argv: input argument
 * @file_to: file destination
 * Return: 0
 */

void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - Copy the content of a file to another file
 * @argc: The number of arguments
 * @argv: An array of argument strings
 * Return: 0 on success, or an exit code on failure
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, nchars, err_close, wr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp fd_from fd_to");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(fd_from, fd_to, argv);
	nchars = 1024;
	while (nchars == 102)
	{
		nchars = read(fd_from, buffer, 1024);
		if (nchars == -1)
		{
			error_file(-1, 0, argv);
			wr = write(fd_to, buffer, nchars);
			if (wr == -1)
			error_file(0, -1, argv);
		}
	}

	err_close = close(fd_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	err_close = close(fd_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}
