#include "shell.h"

/**
 * fr_ptr - free allocated space through malloc
 * @astr: array of strings
 */
void fr_ptr(char **astr)
{
	int i = 0;

	while (astr[i] != NULL)
	{
		free(astr[i]);
		i++;
	}
	free(astr);
}
