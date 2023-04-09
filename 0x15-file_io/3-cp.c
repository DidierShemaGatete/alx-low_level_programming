#include <stdio.h>
#include <stdlib.>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

/**
 * main - copy a file to another file
 * @argc: number of arguments
 * @argv; array of arguments
 *
 * Return: 0 om success, other on failure
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, nread;
	char buf[BUFSIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	/* rw-rw-r-- */

	if (argc != 3)
	{
		dprint(STDERR_FILENO, " %s file_from file_to\n", argv[0]);
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
		return (98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", ardv[2]);
		return (99);
	}

	while ((nread = read(fd_from, buf, BUFSIZE)) > 0)
	{
		if (write(fd_to, buf, nread) != nread)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", arg[2]);
			return (99);
		}
	}

	if (nread == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", fd_from);
		return (98);
	}

	if (close(fd_from) == -1)
	{
		drpintf(STDERR_FILENO, "Error: can't close fd %d\n", fd_from);
		return (100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd_to);
		return (100);
	}

	return (0);
}
