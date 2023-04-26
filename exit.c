#include "shell.h"

/**
 * c_atoi -  converts string to int
 * @s: string
 * Return: number if success, -1 if string has non-numbers
 */
int c_atoi(char *s)
{
	unsigned int num = 0;
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		i++;
	}
	return (num);
}

/**
 * ext - releases user's input and then exits main with a value
 * @crat: cmnd into shell
 * @env_l:hold the environment variable to free at error
 * @num:hold the nth user cmnd line input to print in error message
 * @cmnd:cont the cmnd to free
 * Return: 0 if success 2 if fail
 */
int ext(char **crat, ls_env *env, int num, char **cmnd)
{
	int e_value = 0;

	if (crat[1] != NULL)
		e_value = c_atoi(crat[1]);

	if (e_value == -1)
	{
		nan_no(crat[1], num, env);
		ptr_free(crat);
		return (2);
	}
	ptr_free(crat);
	free_ll(env);
	if (cmnd != NULL)
		ptr_free(cmnd);
	exit(e_value);
}
