#include "shell.h"

/**
 * c_atoi - custom atoi converts string to int
 * @s: string
 * Return: number if success, -1 if string contains non-numbers
 */
int c_atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

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
 * __exit - frees user input and then exits  with a value
 * @str: command into shell 
 * @env: evviroment variable to free at error
 * @num: nth user command line input to print in error message
 * @command: command to free
 * Return: 0 if success else 2 
 */
int __exit(char **str, list_t *env, int num, char **command)
{
	int e_value = 0;

	if (str[1] != NULL) 
		e_value = c_atoi(str[1]);

	if (e_value == -1) 
	{
		illegal_number(str[1], num, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str); 
	free_linked_list(env);
	if (command != NULL)
		free_double_ptr(command);
	exit(e_value);
}
