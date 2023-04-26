#include "shell.h"

/**
 * _which - appending a command to a matching PATH directory
 * @crat: first command user typed into shell
 * @env: environmental variable
 * Always Return command
 */
char *_which(char *crat, ls_env *env)
{
	char *pth, *cat = NULL, **links;
	int i = 0;

	pth = get_env("PATH", env);
	links = c_crat_tok(pth, ":");
	free(pth);

	i = 0;
	while (links[i] != NULL)
	{
		if (links[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _cratdup(links[i]);
		cat = _cratcat(cat, "/");
		cat = _cratcat(cat, crat);
		if (access(cat, F_OK) == 0)
		{
			ptr_free(links);
			return (cat);
		}

		free(cat);
		i++;
	}
	ptr_free(links);
	return (crat);
}
