#include "shell.h"

/**
 * ctrl_c - ignore Ctrl-C input and prints pmt again
 * @n: takes in int from signal
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * blt_in - handles builtin cmnds
 * @link: cmnd input
 * @env: environment variable
 * @num: nth user cmnd typed to write error message
 * @cmnd: cmnd to free
 * Return: 1 if acted on builtin, 0 if not
 */
int blt_in(char **link, ls_env *env, int num, char **cmnd)
{
	int i = 0;

	
	if (_cratcmp(link[0], "exit") == 0)
	{
		i = __exit(link, env, num, cmnd);
	}
	
	else if (_cratcmp(link[0], "env") == 0)
	{
		_env(link, env);
		i = 1;
	}
	
	else if (_cratcmp(link[0], "cd") == 0)
	{
		i = _cd(link, env, num);
	}
	
	else if (_cratcmp(link[0], "setenv") == 0)
	{
		_set_env_v(&env, link);
		i = 1;
	}
	
	else if (_cratcmp(link[0], "unsetenv") == 0)
	{
		_unsetenv(&env, link);
		i = 1;
	}
	return (i);
}

/**
 * no_spinf - return string without spaces in front
 * @crat: string
 * Return: new string
 */
char *no_spinf(char *crat)
{
	while (*crat == ' ')
		crat++;
	return (crat);
}

/**
 * ctrl_D - exits program if input is Ctrl-D 
 * @i: characters read via get_line
 * @cmnd: cmnd input
 * @env: environment variable 
 */
void ctrl_D(int i, char *cmnd, ls_env *env)
{
	if (i == 0) 
	{
		free(cmnd); 
		free_ll(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * pmt -  executes user's cmds if applicable
 * @en: envrionmental variables
 * Return: 0 on success
 */
int pmt(char **en)
{
	ls_env *env;
	size_t i = 0, n = 0;
	int cmnd_line_no = 0, exit_stat = 0;
	char *cmnd, *n_cmnd, **link;

	env = lenv(en);
	do {
		cmnd_line_no++;
		if (isatty(STDIN_FILENO)) 
			write(STDOUT_FILENO, "$ ", 2);
		else
			pip_cmd(env);
		signal(SIGINT, ctrl_c); 
		cmnd = NULL; i = 0; 
		i = get_line(&cmnd); 
		ctrl_D(i, cmnd, env); 
		n_cmnd = cmnd;
		cmnd = no_spinf(cmnd);
		n = 0;
		while (cmnd[n] != '\n')
			n++;
		cmnd[n] = '\0';
		if (cmnd[0] == '\0') 
		{
			free(n_cmnd); continue;
		}
		link = NULL; link = _crat_tok(cmnd, " ");
		if (n_cmnd != NULL)
			free(n_cmnd);
		exit_stat = blt_in(link, env, cmnd_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(link, env, cmnd_line_no);
	} while (1); 
	return (exit_stat);
}
