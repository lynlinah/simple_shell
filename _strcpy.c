#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src,
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of original source
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)
		;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}
