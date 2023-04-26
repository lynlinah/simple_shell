#include "shell.h"

/**
 * c_cratdup - custom string duplication;
 * @crat: string to duplicate 
 * @cs: number of bytes to exclude 
 * Return: string 
 */
char *c_cratdup(char *crat, int cs)
{
	char *crat_dup;
	int i, len = 0;

	if (crat == NULL) 
		return (NULL);

	
	while (*(crat + len))
		len++;
	len++;

	
	crat_dup = malloc(sizeof(char) * (len - cs));
	if (crat_dup == NULL)
		return (NULL);

	i = 0;
	while (i < (len - cs))
	{
		*(crat_dup + i) = *(crat + cs + i);
		i++;
	}
	return (crat_dup);
}

/**
 * get_env -  gets the requested environment variable
 * @crat: string to store it in
 * @env: entire set of environment variables
 * Return: copy of requested environment variable
 */
char *get_env(char *crat, ls_env *env)
{
	int j = 0, cs = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == crat[j]) 
			j++;
		if (crat[j] == '\0' && (env->var)[j] == '=')
			break;
		env = env->next;
	}

	while (crat[cs] != '\0') 
		cs++;
	cs++; /
	return (c_cratdup(env->var, cs)); 
}
