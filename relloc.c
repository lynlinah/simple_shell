#include "shell.h"

/**
 * _reloc - allocate memory and set all values to 0
 * @ptr: pointer to the memory previously allocated
 * @sizeo: size previously allocated
 * @sizen: new size to reallocate
 * Return: pointer to reallocated memory
 */

void *_reloc(void *ptr, unsigned int sizeo, unsigned int sizen)
{
	void *p;
	unsigned int i;

	if (sizen == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (sizen == sizeo)
		return (ptr);

	if (ptr == NULL)
	{
		p = malloc(sizen);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}

	p = malloc(sizen);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < sizeo && i < sizen; i++)
		*((char *)p + i) = *((char *)ptr + i);
	free(ptr);
	return (p);
}
