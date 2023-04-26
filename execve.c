#include "shell.h"

/**
 * c_exit - frees cmnd input and linked list before exiting
 * @crat: cmnd input
 * @env_l: input the linked list of envirnment
 */
void c_exit(char **crat, ls_env *env)
{
	ptr_free(crat);
	free_ll(env);
	_exit(0);
}

/**
 * _execve - execute cmnd user typed into shell
 * @s: cmnd user typed
 * @env_l: environment variable
 * @num: nth user cmnd;
 * Return: 0 on success
 */
int _execve(char **s, ls_env *env, int num)
{
	char *cont;
	int stat = 0, t = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		cont = s[0];
		t = 1;
	}
	else
		cont = _which(s[0], env);
	if(access(cont, X_OK) != 0)
	{
		nt_fnd(s[0], num, env);
		ptr_free(s);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0) 
		{
			if(execve(cont, s, NULL) == -1)
			{
				nt_fnd(s[0], num, env);
				c_exit(s, env);
			}
		}
		else 
		{
			wait(&stat);
			ptr_free(s);
			if (t == 0)
				free(cont);
		}
	}
	return (0);
}
