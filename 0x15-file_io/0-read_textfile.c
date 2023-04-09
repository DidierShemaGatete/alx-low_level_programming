#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the posix standard
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: number of letters read an printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (!filename)
		return (0);

	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	char *buffer = malloc(letters);

	if (!buffer)
	{
		close(fd);
		return (0);
	}

	ssize_t n_read = read(fd, buffer, letters);

	if (n_read == -1)
	{

		free(buffer);
		close(fd);

		return (0);
	}

	ssize_t n_written = write(STDOUT_FILENO, buffer, n_read);
	
	if (n_written == -1 || n_written != n_read)
	{

		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (n_written);

}
