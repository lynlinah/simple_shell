#include "shell.h"

/**
 * _cratdup - returns a pointer to a newly allocated space in memory,
 * @crat: string to duplicate
 * Return: pointer
 */
char *_cratdup(char *crat)
{
	char *crat_dup;
	int i, len = 0;

	if (crat == NULL)
		return (NULL);

	while (*(crat + len))
		len++;
	len++;

	crat_dup = malloc(sizeof(char) * len);
	if (crat_dup == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		*(crat_dup + i) = *(crat + i);
		i++;
	}

	return (crat_dup);
}
