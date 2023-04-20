#include "shell.h"
/**
 * exit_shell - exits the shell
 * @info: contains potential arguments used to
 * maintain constant function prototype
 * Return: exits with a given status
 * (0) if info.argv[0] != "exit"
 */
int exit_shell(info_t *info)
{
	int exit_status = 0;
	
	if (info->argv[1])
	{
		int exit_arg = _erratoi(info->argv[1]);
		
		if (exit_arg == -1)
		{
			info->status = 3;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			exit_status = 1;
		}
		else
		{
			exit_status = exit_arg;
		}
	}
	exit(exit_status);
}

/**
 * change_directory - changes the current directory
 * @info: contains otential arguments
 * Return: Always 0
 */
int change_directory(info_t *info)
{
	char *dir, buffer[1024];
	int cdir_ret;

	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME");
		if (!dir)
		{
			cdir_ret = cdir("/");
		}
		else
		{
			cdir_ret = cdir(dir);
		}
	}
	else if (_strmcp(info->argv[1], " - ") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			 _puts(buffer);
			 _putchar('\n');
			 return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		cdir_ret = cdir(_getenv(info, "OLDPWD="));
	}
	else
	{
		cdir_ret = cdir(info->argv[1]);
	}
	if (cdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
	
/**
 * display_help - displays help information
 * @info: contains potential arguments
 * Return: Always 0
 */
int display_help(info_t *info)
{
	char **arg_array;
	
	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	/* temp att_unused workaround */
	if (0)
		_puts(*arg_array);
	return (0);
}	 
