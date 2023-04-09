#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * read_textfile - to read the printed file
 * @filename: the name of the file
 * @letters: the numbers of letters
 * Return: Always 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{

	char *fun;
	ssize_t a, b, c;

	a = open(filename, O_RDONLY);
	if (a == -1)
		return (0);
	fun = malloc(sizeof(char) * letters);
	if (fun == NULL)
		return (0);
	b = read(a, fun, letters);
	c = write(STDOUT_FILENO, fun, b);

	free(fun);
	close(a);
	return (c);
}
