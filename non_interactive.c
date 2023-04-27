#include "shell.h"

/**
 * no_spc - custom function that remove spaces and newlines
 * @env_v: envrionmental variables
 * Return: new string
 */
char *no_spc(char *env_v)
{
	while (*env_v == ' ' || *env_v == '\n')
		env_v++;
	return (env_v);
}

/**
 * non_inv - handles pipeline comands
 * @env_v: envrionmental variables
 */
void non_inv(list_t *env_v)
{
	size_t i = 0, n = 0;
	int cmd_no = 0, fn = 0;
	char *cmd_t = NULL, *cmd_i = NULL, **ln, **cmd;

	i = get_line(&cmd_t);
	if (i == 0)
	{
		free(cmd_t);
		exit(0);
	}
	cmd_i = cmd_t;
	cmd_t = no_spc(cmd_t);
	ln = _str_tok(cmd_t, "\n"); 
	if (cmd_i != NULL)
		free(cmd_i);
	n = 0;
	while (ln[n] != NULL)
	{
		cmd_no++;
		cmd = NULL; 
		cmd = _str_tok(ln[n], " ");
		fn = built_in(cmd, env_v, cmd_no, ln);
		if (fn)
		{
			n++;
			continue;
		}
		fn = _execve(cmd, env_v, cmd_no);
		n++;
	}
	free_double_ptr(ln);
	free_linked_list(env_v);
	exit(fn);
}
