#include "shell.h"

/**
 * _cratcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: int
 */

int _cratcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
		i++;

	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	else
		return (0);
}
