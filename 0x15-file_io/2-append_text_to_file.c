#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: Name of the file to append text to.
 * @text_content: NULL - terminated string to append to the file
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len = 0, wrlen;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;

		wrlen = write(fd, text_content, len);
		if (wrlen == -1 || wrlen != len)
			return (-1);
	}

	close(fd);
	return (1);
}


