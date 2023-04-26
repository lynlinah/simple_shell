#include "shell.h"

/**
 * _cratcpy - copies the string pointed to by frm,
 * @frm: copy source to this buffer
 * @sto: this is the source to copy
 * Return: copy of original source
 */

char *_cratcpy(char *frm, char *sto)
{
	int i, len;

	for (len = 0; sto[len] != '\0'; len++)
		;

	for (i = 0; i <= len; i++)
		frm[i] = sto[i];

	return (frm);
}
