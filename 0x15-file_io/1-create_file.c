#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

/**
 * create_file - Creates a file with the specified
 * text content and permissions.
 * @filename: The name of the file to be created.
 * @text_content: The NULL-terminated string to write to the file.
 * Return: 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int bytesWritten;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		bytesWritten = write(fd, text_content, strlen(text_content));
		close(fd);
	}

	if (bytesWritten == -1)
	{
		return (-1);
	}
	else
	{
		close(fd);
	}

	return (1);
}
