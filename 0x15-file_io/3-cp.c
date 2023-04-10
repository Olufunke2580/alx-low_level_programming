#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_fun(char *file);
void close_file(int fd);

/**
 * create_fun - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */

char *create_fun(char *file)
{
	char *fun;

	fun = malloc(sizeof(char) * 1024);

	if (fun == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (fun);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */

void close_file(int fd)
{
	int f;

	f = close(fd);

	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d/n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */

int main(int argc, char *argv[])
{
	int from, to, a, b;
	char *fun;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fun = create_fun(argv[2]);
	from = open(argv[1], O_RDONLY);
	a = read(from, fun, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || a == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(fun);
			exit(98);
		}

		b = write(to, fun, a);
		if (to == -1 || b == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(fun);
			exit(99);
		}

		a = read(from, fun, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (a > 0);

	free(fun);
	close_file(from);
	close_file(to);

	return (0);
}
