#include "shell.h"

/**
 * c_cratcat - join two strings ignoring the first character
 * @sto: string to be appended to
 * @frm: string to append
 * Return: concatenated string
 */
char *c_cratcat(char *sto, char *frm)
{
	int sze = 0;
	int sze1 = 0;
	int sze_t = 0;
	int j = 0;

	
	while (sto[sze] != '\0')
	{
		sze++;
		sze_t++;
	}
	while (frm[sze1] != '\0')
	{
		sze1++;
		sze_t++;
	}

	
	sto = _reloc(sto, sze, sizeof(char) * sze_t + 1);

	j = 1; 
	while (frm[j] != '\0')
	{
		sto[sze] = frm[j];
		sze++;
		j++;
	}
	sto[sze] = '\0';

	return (sto);
}

/**
 * set_env_v- custom func concatenating string first
 * @env_l: environment variable linked list
 * @env_n: environment variable name
 * @dir: directory path 
 * Return: 0 on success 
 */
int set_env_v (ls_env **env, char *env_n, char *dir)
{
	int pos = 0, j = 0;
	char *cat;
	ls_env *cont;

	cat = _cratdup(env_n); 
	cat = _cratcat(cat, "=");
	cat = _cratcat(cat, dir);
	pos = fn_env(*env, env_n); 

	
	cont= *env;
	while (j < pos)
	{
		cont= cont->next;
		j++;
	}
	free(cont->var);
	cont->var = _cratdup(cat);
	free(cat);
	return (0);
}

/**
 * cd_only - change directory to home
 * @env_l:hold the environment linked list to update PATH 
 * @crnt:hold the crnt working directotry
 */
void cd_only(ls_env *env, char *crnt)
{
	char *home = NULL;

	home = get_env("HOME", env);
	c_set_env_v(&env, "OLDPWD", crnt); 
	free(crnt);
	if (access(home, F_OK) == 0) 
		chdir(home);
	crnt = NULL;
	crnt = getcwd(crnt, 0);
	c_set_env_v(&env, "PWD", crnt);
	free(crnt);
	free(home);
}
/**
 * cd_execute - executes the cd
 * @env_l:hold the environment linked list to update PATH and OLDPWD
 * @crnt:hold the crnt working directotry
 * @dir:hold the directory path to change to
 * @crat:hold the the 1st argument to write out error
 * @num:hold the the line no to write out error
 * Return: 0 if success 2 for fail
 */
int cd_execute(ls_env *env, char *crnt, char *dir, char *crat, int num)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		c_set_env_v(&env, "OLDPWD", crnt); 
		free(crnt);
		chdir(dir);
		crnt = NULL;
		crnt = getcwd(crnt, 0); 
		c_set_env_v(&env, "PWD", crnt); 
		free(crnt);
	}
	else
	{
		dir_err(crat, num, env);
		free(crnt);
		i = 2;
	}
	return (i);
}

/**
 * _cd - change directory
 * @crat: cmnd typed
 * @env_l: envitoment linked list to retrieve HOME and OLDPWD paths
 * @num: nth user cmnd, to be used at error message
 * Return: 0 if success 2 if failed
 */
int _cd(char **crat, ls_env *env, int num)
{
	char *crnt = NULL, *dir = NULL;
	int fn_xt = 0;

	crnt = getcwd(crnt, 0); 
	if (crat[1] != NULL)
	{
		if (crat[1][0] == '~') 
		{
			dir = get_env("HOME", env);
			dir = c_cratcat(dir, crat[1]);
		}
		else if (crat[1][0] == '-') 
		{
			if (crat[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		else 
		{
			if (crat[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _cratcat(dir, "/");
				dir = _cratcat(dir, crat[1]);
			}
			else
				dir = _cratdup(crat[1]);
		}
		fn_xt = cd_execute(env, crnt, dir, crat[1], num);
		free(dir);
	}
	else 
		cd_only(env, crnt);
	ptr_free(crat); 
	return (fn_xt);
}
