#include "shell.h"

/**
 * fn_env_v - find enviroment viariable in the given linked list
 * @env_v: linked lis of environment variables
 * @var: variable name
 * Return: the index of node in the @env_v
 */
int fn_env_v(list_t *env_v, char *var)
{
	int x = 0, index = 0;

	while (env_v != NULL)
	{
		x = 0;
		while ((env_v->var)[x] == var[x]) /* get env_v variable */
			x++;
		if (var[x] == '\0') /* for a total match, break and return index */
			break;
		env_v = env_v->next;
		index++;
	}
	if (env_v == NULL)
		return (-1);
	return (index);
}

/**
 * unset_env_v - function to remove node in enviroment.
 * @env_v: linked list
 * @var: typed command by user
 * Always Return 0 if success
 */
int unset_env_v(list_t **env_v, char **var)
{
	int index = 0, x = 0;

	if (var[1] == NULL)
	{
		write(STDOUT_FILENO, "Not enough arguments provided\n", 18);
		free_double_ptr(var);
		return (-1);
	}
	index = fn_env_v(*env_v, var[1]); /* get index of node */
	free_double_ptr(var);
	if (index == -1) /* testing if index has an error */
	{
		write(STDOUT_FILENO, "NOT found!\n", 12);
		return (-1);
	}
	x = delete_nodeint_at_index(env_v, index); /* deleting the current node */
	if (x == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * set_env_v - creates and modifies the existing enviroment variable
 * @env_v: linked list
 * @var: command typed by the user
 * Always Return 0 when successful, 1 on failure
 */
int set_env_v(list_t **env_v, char **var)
{
	int index = 0, x = 0;
	char *cat;
	list_t *holder;

	if (var[1] == NULL || var[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(var);
		return (-1);
	}
	cat = _strdup(var[1]); /* joins the variables to be a new node */
	cat = _strcat(cat, "=");
	cat = _strcat(cat, var[2]);
	index = fn_env_v(*env_v, var[1]); /* get the index */
	if (index == -1)
	{
		add_end_node(env_v, cat); /* if index not found create env_v var */
	}
	else
	{
		holder = *env_v;
		while (x < index)
		{
			holder = holder->next;
			x++;
		}
		free(holder->var); /* free malloc */
		holder->var = _strdup(cat); /* initialize to new malloc */
	}
	free(cat);
	free_double_ptr(var);
	return (0);
}
