#include "shell.h"

/**
 * prt_lst - _print linked list
 * @h: linked list
 * Return: size of linked list
 */
size_t prt_lst(ls_env *h)
{
	ls_env *c_list = h;
	int cnt= 0;
	int c = 0;

	if (h == NULL)
		return (0);
	while (c_list != NULL)
	{
		if (c_list->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			c = 0;
			while ((c_list->var)[c] != '\0')
				c++;
			write(STDOUT_FILENO, c_list->var, c);
			write(STDOUT_FILENO, "\n", 1);
		}
		c_list = c_list->next;
		count++;
	}
	return (count);
}

/**
 * padd_end - add node to end of linked list
 * @head: pointer to head of linked list
 * @crat: data to add node
 * Return: pointer to add 
 */
ls_env *padd_end(ls_env **head, char *crat)
{
	ls_env *add;
	ls_env *cont;

	if (head == NULL || crat == NULL)
		return (NULL); 
	add = malloc(sizeof(ls_env));
	if (add == NULL)
		return (NULL);

	add->var = _cratdup(crat);
	add->next = NULL;

	cont= *head;
	if (cont!= NULL)
	{
		while (cont->next != NULL)
		{
			cont= cont->next;
		}
		cont->next = add;
	}
	else
	{
		*head = add;
	}
	return (*head);
}

/**
 * del_node - removing node at pos
 * @head: input head address
 * @pos: input pos
 * Return: 1 if success, -1 if fail
 */
int del_node(ls_env **head, int pos)
{
	ls_env *head;
	ls_env *cont;
	int cnt= 0;

	if (*head == NULL)
		return (-1);
	if (pos == 0)
	{
		cont= (*head)->next;
		free((*head)->var);
		free(*head);
		*head = cont;
		return (1);
	}
	cnt= 1;
	head = *head;
	while (cnt< pos)
	{
		if (head == NULL)
			return (-1);
		head = head->next;
		count++;
	}
	cont= head->next;
	head->next = cont->next;
	free(cont->var);
	free(cont);
	return (1);
}

/**
 * free_ll - frees linked list
 * @list: linked list
 */
void free_ll(ls_env *list)
{
	ls_env *cont;

	while (list != NULL)
	{
		cont= list;
		list = list->next;
		free(cont->var);
		free(cont);
	}

}
