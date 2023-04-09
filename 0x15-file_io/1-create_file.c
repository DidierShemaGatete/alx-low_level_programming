#include "main.h"

/**
 * create_file - creates a file and writes text content to it
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write to file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, n_write, len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
		n_write = write(fd, text_content, len);

		if (n_write == -1 || n_write != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

