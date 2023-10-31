#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: The name of the file to append to
 * @text_content: The NULL-terminated string to add to the end of the file
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int wr;
	int len;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

		if (fd == -1)
			return (-1);
	if (text_content)
	{
		for (len = 0; text_content[len]; len++)
			;
		wr = write(fd, text_content, len);

		if (wr == -1)
			return (-1);
	}
	close(fd);

	return (1);
}
