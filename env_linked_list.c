#include "shell.h"

/**
 * env_linked_list - creates a linked list from enviroment variables
 * @env: enviroment variables
 * Return: linked list
 */
list_t *env_linked_list(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * _env - prints enviroment variables
 * @str: command into shell 
 * @env: enviroment variables
 * Return: 0 on success
 */
int _env(char **str, list_t *env)
{
	free_double_ptr(str); 
	print_list(env); 
	return (0);
}
