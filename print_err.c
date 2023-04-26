#include "shell.h"

/**
 * nt_fnd - write error 
 * @crat: command
 * @c_n: nth command
 * @env:  environment variables
 */
void nt_fnd(char *crat, int c_n, ls_env *env)
{
	int cnt= 0;
	char *shell, *num;

	shell = get_env("_", env); 
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);  
	cnt= 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	cnt= 0;
	while (crat[count] != '\0')
		count++;
	write(STDOUT_FILENO, crat, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * dir_err - write error ("sh: 2: cd: can't cd to xyz")
 * @crat: user's typed argument after the cmd cd
 * @c_n: nth command
 * @env:  environment variables 
 */
void dir_err(char *crat, int c_n, ls_env *env)
{
	int cnt= 0;
	char *shell, *num;

	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	cnt= 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	cnt= 0;
	while (crat[count] != '\0')
		count++;
	write(STDOUT_FILENO, crat, count);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * nan_no - write error
 * @crat: user's typed argument after the cmd exit
 * @c_n: nth command
 * @env:  environment variables 
 */
void nan_no(char *crat, int c_n, ls_env *env)
{
	int cnt= 0;
	char *shell = NULL, *num = NULL;

	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	cnt= 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	cnt= 0;
	while (crat[count] != '\0')
		count++;
	write(STDOUT_FILENO, crat, count);
	write(STDOUT_FILENO, "\n", 1);
}
