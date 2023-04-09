#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * create_file - create a file
 * @filename: the name of the file
 * @text_content: a pointer to the string
 *
 * Return: return -1 if the function fails
 */

int create_file(const char *filename, char *text_content)
{
	int fun, f, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	fun = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	f = write(fun, text_content, len);
	if (fun == -1 || f == -1)
		return (-1);
	close(fun);
	return (1);
}
