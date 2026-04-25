#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void close_fd(int fd);
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to);

/**
 * main - copies content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}

	copy_file(fd_from, fd_to, av[1], av[2]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}

/**
 * copy_file - copies data between files
 */
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	int r, w;
	char buffer[BUF_SIZE];

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * close_fd - closes file descriptor
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
