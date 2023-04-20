#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>

/*constants*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * struct map - commands a name to a function
 *
 * @command_name: name of the command
 * @func: executes the command
 */

typedef struct map
{
	char *command_name;
	void(*func)(char **command);
} function_map;

extern int status;
extern char *line;
extern char *shell_name;
extern char **commands;
extern char **environ;

/*helpers1*/
void _strcpy(char *, char *);
void remove_newline(char *);
char **tokenizer(char *, char *);
int _strlen(char *);
void print(char *, int);

/*helpers2*/
int _strcmp(char *, char *);
char *_strcat(char *, char *);
int _strspn(char *, char *);
int _strcspn(char *, char *);
char *_strchr(char *, char);

/*helpers3*/
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int);
void remove_comment(char *);

/*built_in*/
void env(char **);
void quit(char **);

/*main*/
extern void non_interactive(void);
extern void initializer(char **current_command, int type_command);

/*utils*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

#endif /*SHELL_H*/
