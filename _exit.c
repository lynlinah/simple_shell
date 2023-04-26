#include "shell.h"

/**
 * _c_atoi - uses custom atoi to convert string to int
 * @s: string
 * Return: number when successful, -1 for non-numbers
 */
int _c_atoi(char *s)
{
	unsigned int num = 0;
	int n = 0;

	while (s[n] != '\0')
	{
		if (s[n] >= '0' && s[n] <= '9') /* compute num */
			num = num * 10 + (s[n] - '0');
		if (s[n] > '9' || s[n] < '0') /* accommodate the non-numbers */
			return (-1);
		n++;
	}
	return (num);
}

/**
 * exit_v - used to free the input then exits the program with a value
 * @str: shell users command
 * @env: environmental variable to free at error
 * @num: th command input line to print in error message
 * @command: the implemented command
 * Always Return 0 if successful and 2 for failure
 */
int exit_v(char **str, list_t *env, int num, char **command)
{
	int exit_value = 0;

	if (str[1] != NULL) /* for null value after exit, return 0 */
		exit_value = _c_atoi(str[1]);

	if (exit_value == -1) /* for invalid value after exit, print error mg */
	{
		fprintf(stderr, "hsh: %d: exit: Illegal number: %s\n", num, str[1]);
		free_double_ptr(str);
		return (2);
	}

	/* free user input and environmental variable */
	free_double_ptr(str);
	free_linked_list(env);

	if (command != NULL) /* free command if implemented */
		free_double_ptr(command);

	exit(exit_value); /* exit program with specified exit value */
}
