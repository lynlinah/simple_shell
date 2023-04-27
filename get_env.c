#include "shell.h"

/** 
 * c_strdup - a custom function to duplicate a string and excludes beginning bytes
 * @str: string to duplicate 
 * @cs: no of bytes to exclude 
 * Return: string 
 */
char *c_strdup(char *str, int cs)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL) 
		return (NULL);

	
	while (*(str + len))
		len++;
	len++;

	
	duplicate_str = malloc(sizeof(char) * (len - cs));
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < (len - cs))
	{
		*(duplicate_str + i) = *(str + cs + i);
		i++;
	}
	return (duplicate_str);
}

/**
 * get_env - finds and returns the requested enviroment variable
 * @str: string to store it in
 * @env: entire set of enviroment variables
 * Return: copy of requested enviroment variable
 */
char *get_env(char *str, list_t *env)
{
	int j = 0, cs = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j]) 
			j++;
		if (str[j] == '\0' && (env->var)[j] == '=')
			break;
		env = env->next;
	}

	while (str[cs] != '\0') 
		cs++;
	cs++; 
	return (c_strdup(env->var, cs)); 
}
