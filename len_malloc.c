#include "shell.h"

/**
 * t_cratlen - returns token's string length for mallocing
 * @crat: a token
 * @pos: index position command typed into shell
 * @dlm: delimeter 
 * Return: token length
 */
int t_cratlen(char *crat, int pos, char dlm)
{
	int len = 0;

	while ((crat[pos] != dlm) && (crat[pos] != '\0'))
	{
		pos++;
		len++;
	}
	return (len);
}

/**
 * t_size - returns number of delim 
 * @crat:  command typed into shell
 * @dlm: delimeter 
 * Return: number of delims 
 */
int t_size(char *crat, char dlm)
{
	int i = 0, num_dlm = 0;

	while (crat[i] != '\0')
	{
		if ((crat[i] == dlm) && (crat[i + 1] != dlm))
		{
			
			num_dlm++;
		}
		if ((crat[i] == dlm) && (crat[i + 1] == '\0'))
		{
			
			num_dlm--;
		}
		i++;
	}
	return (num_dlm);
}

/**
 * ignore_dlm - returns a version of string without preceeding delims
 * @crat: string
 * @dlm: delimiter (e.g. " ")
 * Return: new string (e.g. "    ls -l" --> "ls -l")
 */
char *ignore_dlm(char *crat, char dlm)
{
	while (*crat == dlm)
		crat++;
	return (crat);
}

/**
 * _crat_tok - tokenizes a string and returns an array of tokens
 * @crat: user's command typed into shell
 * @dlm: delimeter 
 * Return: an array of tokens 
 */
char **_crat_tok(char *crat, char *dlm)
{
	int bufs = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **links = NULL, d_ch;

	d_ch = dlm[0];
	
	crat = ignore_dlm(crat, d_ch);
	
	bufs = t_size(crat, d_ch);
	links = malloc(sizeof(char *) * (bufs + 2));
	if (links == NULL)
		return (NULL);
	while (crat[se] != '\0')	
		se++;
	while (si < se)
	{ 
		if (crat[si] != d_ch)
		{
			len = t_cratlen(crat, si, d_ch);
			links[p] = malloc(sizeof(char) * (len + 1));
			if (links[p] == NULL)
				return (NULL);
			i = 0;
			while ((crat[si] != d_ch) && (crat[si] != '\0'))
			{
				links[p][i] = crat[si];
				i++;
				si++;
			}
			links[p][i] = '\0'; 
			t++;
		}
		
		if (si < se && (crat[si + 1] != d_ch && crat[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	links[p] = NULL; 
	return (links);
}
