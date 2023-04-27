#include "shell.h"

/**
 * main - creates a simple shell
 * @arg_c: argument count
 * @arg_v: argument vectors
 * @env_v: environmental variables
 * Return: 0 when successful
 */
int main(int arg_c, char **arg_v, char **env_v)
{
	(void)arg_c;
	(void)arg_v;

	prompt(env_v);

	return (0);
}
