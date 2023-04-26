#include "shell.h"

/**
 * lenv - creates a linked list
 * @env: environment variables
 * Return: linked list
 */
ls_env *lenv(char **env)
{
	ls_env *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		padd_end(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * _env - prints environment variables
 * @crat: shell command 
 * @env: environment variables
 * Return: 0 on success
 */
int _env(char **crat, ls_env *env)
{
	ptr_free(crat); 
	print_list(env); 
	return (0);
}
