#include "shell.h"
#include <stdio.h>

/**
 * main - entry point
 * Description: iterate over all possible combinations
 * of the variables
 * Return: Always 0 (success)
 */
int main(void)
{
	int i = 0, j = 0;
	DIR *drp = opendir(".");

	if (drp == NULL)
	{
		return (1);
	}
	struct dirent *dr;

	while ((dr = readdir(drp)) != NULL)
	{
		i = dr->d_type - DT_DIR;
		j = 0;
		while (i <= 90)
		{
			if (i <= j)
			{
				putchar((i / 10) + '0');
				putchar((i % 10) + '0');
				putchar(' ');
				putchar((j / 10) + '0');
				putchar((j % 10) + '0');
				if (i != 90 || j != 90)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
		i++;
		if (i == 100)
		{
			j++;
			i = 0;
		}
	}
	closedir(drp);
	return (0);
}
