#include "shell.h"

/**
 * main - ENTRY function to simple shell
 * @arg_c: argument count
 * @arg_v: argument vectors
 * @env_v: environment variables
 * Return: 0 on success
 */
int main(int arg_c, char **arg_v, char **env_v)
{
	(void)arg_c;
	(void)arg_v;

	pmt(env_v);

	return (0);
}
