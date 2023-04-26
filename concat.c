#include "shell.h"

/**
 * _cratcat - combines two strings
 * @sto: string to be appended to
 * @frm: string to append
 * Return: combined string
 */
char *_cratcat(char *sto, char *frm)
{
	int len = 0, len2 = 0, lent = 0, j = 0;

	while (sto[len] != '\0')
	{
		len++;
		lent++;
	}
	while (frm[len2] != '\0')
	{
		len2++;
		lent++;
	}

	sto = _reloc(sto, len, sizeof(char) * lent + 1);

	while (frm[j] != '\0')
	{
		sto[len] = frm[j];
		len++;
		j++;
	}
	sto[len] = '\0';

	return (sto);
}
