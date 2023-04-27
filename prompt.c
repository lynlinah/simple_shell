#include "shell.h"

/**
 * ctrl_c - restarts the pmpt
 * @sig: accepts an integer from signal
 */
void ctrl_c(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * blt_in - handles builtins 
 * @cmd: typed command
 * @env_v: enviroment variable
 * @err: gets in the command typed that bring error to display message
 * @f_cmd: bring in f_cmdcommand to free
 * Returns 1 for used builtin functions,else 0 
 */
int blt_in(char **cmd, list_t *env_v, int err, char **f_cmd)
{
	int i = 0;

	/* when user types "exit" */
	if (_strcmp(cmd[0], "exit") == 0)
	{
		i = __exit(cmd, env_v, err, f_cmd);
	}
	/* when user types "env_v" */
	else if (_strcmp(cmd[0], "env_v") == 0)
	{
		_env(cmd, env_v);
		i = 1;
	}
	/* when user types "cd" */
	else if (_strcmp(cmd[0], "cd") == 0)
	{
		i = _cd(cmd, env_v, err);
	}
	/* if user types "set_env_v" */
	else if (_strcmp(cmd[0], "set_env_v") == 0)
	{
		set_env_v(&env_v, cmd);
		i = 1;
	}
	/* if user types "unset_env_v" */
	else if (_strcmp(cmd[0], "unset_env_v") == 0)
	{
		unset_env_v(&env_v, cmd);
		i = 1;
	}
	return (i);
}

/**
 * no_spc_inf - removes spaces in front of a string 
 * @str: string input
 * Return: new string
 */
char *no_spc_inf(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * ctrl_D - exits program if input is Ctrl-D
 * @i: characters read via get_line
 * @f_cmd: user's typed in command
 * @env_v: enviroment variable linked list
 */
void ctrl_D(int i, char *f_cmd, list_t *env_v)
{
	if (i == 0)
	{
		free(f_cmd); /* exit with a newline */
		free_linked_list(env_v);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * pmpt - prompts user and executes user's cmds if applicable
 * @env_v: enviroment variables
 * Return: 0 on success
 */
int pmpt(char **env_v)
{
	list_t *env_v;
	size_t i = 0, sig = 0;
	int cmd_no = 0, fn = 0;
	char *f_cmd, *cmd_i, **cmd;

	env_v = env_linked_list(env_v);
	do {
		cmd_no++;
		if (isatty(STDIN_FILENO)) /* reprompt if in interactive shell */
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env_v);
		sig(SIGINT, ctrl_c); /* disable ctrl+c  */
		f_cmd = NULL; i = 0; 
		i = get_line(&f_cmd); 
		ctrl_D(i, f_cmd, env_v); /* exits shell */
		cmd_i = f_cmd;
		f_cmd = no_spc_inf(f_cmd);
		sig = 0;
		while (f_cmd[sig] != '\n') /* replace get_line's \n with \0 */
			sig++;
		f_cmd[sig] = '\0';
		if (f_cmd[0] == '\0') /* reprompt if user hits enter only */
		{
			free(cmd_i); continue;
		}
		cmd = NULL; cmd = _str_tok(f_cmd, " "); /*cmd user cmd*/
		if (cmd_i != NULL)
			free(cmd_i);
		fn = blt_in(cmd, env_v, cmd_no, NULL);
		if (fn)
			continue;
		fn = _execve(cmd, env_v, cmd_no);
	} while (1); 
	return (fn);
}
