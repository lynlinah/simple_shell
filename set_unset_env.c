#include "shell.h"

/**
 * fn_env - find given environment variable 
 * @env_l: environment variable 
 * @crat: variable name
 * Return: index of node 
 */
int fn_env(ls_env *env, char *crat)
{
	int j = 0, pos = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == crat[j]) 
			j++;
		if (crat[j] == '\0') 
			break;
		env = env->next;
		pos++;
	}
	if (env == NULL)
		return (-1);
	return (pos);
}

/**
 * unset_env_v - remove node 
 * @env_l: linked list
 * @crat: cmnd typed 
 * Return: 0 on success
 */
int unset_env_v(ls_env **env, char **crat)
{
	int pos = 0, j = 0;

	if (crat[1] == NULL)
	{
		write(STDOUT_FILENO, "less arguments provided\n", 18);
		ptr_free(crat);
		return (-1);
	}
	pos = fn_env(*env, crat[1]); 
	ptr_free(crat);
	if (pos == -1) 
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	j = del_node(env, pos); 
	if (j == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * _set_env_v - create or modify existing environment variable in linked list
 * @env_l: linked list
 * @crat: cmnd typed (e.g. "setenv USER Superman")
 * Return: 0 on success, 1 on fail
 */
int _set_env_v(ls_env **env, char **crat)
{
	int pos = 0, j = 0;
	char *cat;
	ls_env *cont;

	if (crat[1] == NULL || crat[2] == NULL)
	{
		write(STDOUT_FILENO, "less arguments provided\n", 18);
		ptr_free(crat);
		return (-1);
	}
	cat = _cratdup(crat[1]); 
	cat = _cratcat(cat, "=");
	cat = _cratcat(cat, crat[2]);
	pos = fn_env(*env, crat[1]);
	if (pos == -1)
	{
		padd_end(env, cat); 
	}
	else
	{
		cont= *env;
		while (j < pos)
		{
			cont= cont->next;
			j++;
		}
		free(cont->var); 
		cont->var = _cratdup(cat); 
	}
	free(cat);
	ptr_free(crat);
	return (0);
}
