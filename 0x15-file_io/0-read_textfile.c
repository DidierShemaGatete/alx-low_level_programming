#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the posix standard
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: number of letters read an printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_written;
	char *buffer;

	if (!filename)
		return (0);

	buffer = malloc(letters * sizeof(char));
	if (!buffer)
		return (0);


	fd = open(filename, o_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	n_read = read(fd, buffer, letters);
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
