#include "shell.h"

/**
 * c_ignore - custom ignores spaces and newlines
 * (e.g. echo "ls\n ls" | ./a.out)
 * @crat: envrionmental variables
 * Return: new string
 */
char *c_ignore(char *crat)
{
	while (*crat == ' ' || *crat == '\n')
		crat++;
	return (crat);
}

/**
 * pip_cmd - handles when user pipes commands
 * @env: envrionmental variables
 */
void pip_cmd(ls_env *env)
{
	size_t i = 0, n = 0;
	int cmd_no = 0, exit_stat = 0;
	char *command = NULL, *n_command = NULL, **n_line, **link;

	i = get_line(&command);
	if (i == 0)
	{
		free(command);
		exit(0);
	}
	n_command = command;
	command = c_ignore(command);
	n_line = _crat_tok(command, "\n");
	if (n_command != NULL)
		free(n_command);
	n = 0;
	while (n_line[n] != NULL)
	{
		cmd_no++;
		link = NULL;
		link = _crat_tok(n_line[n], " ");
		exit_stat = built_in(link, env, cmd_no, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _execve(link, env, cmd_no);
		n++;
	}
	ptr_free(n_line);
	free_ll(env);
	exit(exit_stat);
}
