#include "shell.h"

/**
 * c_t_size - returns number of delim
 * @crat: command typed into shell
 * @dlm: delim
 * Return: number of tokens
 */
int c_t_size(char *crat, char dlm)
{
	int i = 0, dlm_no = 0;

	while (crat[i] != '\0')
	{
		if (crat[i] == dlm)
		{
			dlm_no++;
		}
		i++;
	}
	return (dlm_no);
}


/**
 * c_crat_tok - tokenizes a string
 * @crat: user's command typed into shell
 * @dlm: delimeter
 * Return: an array of tokens
 */
char **c_crat_tok(char *crat, char *dlm)
{
	int bufs = 0, p = 0, si = 0, i = 0, len = 0, se = 0;
	char **links = NULL, d_ch;

	d_ch = dlm[0];
		bufs = c_t_size(crat, d_ch);
	links = malloc(sizeof(char *) * (bufs + 2));
	if (links == NULL)
		return (NULL);

	while (crat[se] != '\0')
		se++;
	while (si < se)
	{
		len = t_cratlen(crat, si, d_ch);
		links[p] = malloc(sizeof(char) * (len + 1));
		if (links[p] == NULL)
			return (NULL);
		i = 0;
		while ((crat[si] != d_ch) &&
		       (crat[si] != '\0'))
		{
			links[p][i] = crat[si];
			i++;
			si++;
		}
		links[p][i] = '\0';
		p++;
		si++;
	}
	links[p] = NULL;
	return (links);
}
