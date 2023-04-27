#include "shell.h"

/**
 * str_dup - duplicating a string
 * @str: string to duplicate 
 * @x_bt: number of bytes to exclude 
 * Return: string
 */
char *str_dup(char *str, int x_bt)
{
	char *ptr_dup;
	int i, len = 0;

	if (str == NULL) /* validate str input */
		return (NULL);

	/* calculate len + null terminator to malloc */
	while (*(str + len))
		len++;
	len++;

	/* allocate memory but exclude environmental variable (PATH) */
	ptr_dup = malloc(sizeof(char) * (len - x_bt));
	if (ptr_dup == NULL)
		return (NULL);

	i = 0;
	while (i < (len - x_bt))
	{
		*(ptr_dup + i) = *(str + x_bt + i);
		i++;
	}
	return (ptr_dup);
}

/**
 * g_env_v - finds and returns a copy of the requested environmental variable
 * @str: string to store it in
 * @env_v: entire set of environmental variables
 * Return: copy of requested environmental variable
 */
char *g_env_v(char *str, list_t *env_v)
{
	int j = 0, x_bt = 0;

	while (env_v != NULL)
	{
		j = 0;
		while ((env_v->var)[j] == str[j]) 
			j++;
		if (str[j] == '\0' && (env_v->var)[j] == '=')
			break;
		env_v = env_v->next;
	}

	while (str[x_bt] != '\0') 
		x_bt++;
	x_bt++; 
	return (str_dup(env_v->var, x_bt)); 
}
