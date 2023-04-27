#include "shell.h"

/**
 * env_ll - creates a linked list from enviroment variables
 * @env_v: enviroment variables
 * Return: linked list
 */
list_t *env_ll(char **env_v)
{
	list_t *strt;
	int i = 0;

	strt = NULL;
	while (env_v[i] != NULL)
	{
		add_end_node(&strt, env_v[i]);
		i++;
	}
	return (strt);
}

/**
 * env_v - prints enviroment variables
 * @cmd: user's command into shell 
 * @env_v: enviroment variables
 * Return: 0 on success
 */
int env_v(char **cmd, list_t *env_v)
{
	free_double_ptr(cmd); /* frees user input */
	print_list(env_v); /* prints env_v */
	return (0);
}
