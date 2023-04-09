#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * append_text_to_file - appends text
 * @filename: filename.
 * @text_content: add content
 *
 * Return: 1 if the file exists. -1 if the fails does not exit
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fun, a, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	fun = open(filename, O_WRONLY | O_APPEND);
	a = write(fun, text_content, len);
	if (fun == -1 || a == -1)
		return (-1);

	close(fun);
	return (1);
}
