#include "shell.h"

/**
 * get_line - stores command into malloced buffer
 * @crat: buffer
 * Return: number of characters read
 */
size_t get_line(char **crat)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buf[1024];

	while (t2 == 0 && (i = read(STDIN_FILENO, buf, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buf[i] = '\0';
		n = 0;
		while (buf[n] != '\0')
		{
			if (buf[n] == '\n')
				t2 = 1;
			n++;
		}

		if (t == 0)
		{
			i++;
			*crat = malloc(sizeof(char) * i);
			*crat = _cratcpy(*crat, buf);
			size = i;
			t = 1;
		}
		else
			{
			size += i;
			*crat = _cratcat(*crat, buf);
		}
	}
	return (size);
}
