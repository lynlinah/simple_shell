#include "shell.h"

/**
 * ptr_free - free malloced arrays
 * @crat: array of strings
 */
void ptr_free(char **crat)
{
	int i = 0;

	while (crat[i] != NULL)
	{
		free(crat[i]);
		i++;
	}
	free(crat);
}

