#include "shell.h"

/**
 * numlen - counts num of 0s in a decimal no
 * @n: num
 * Return: returns no of plc
 */
int numlen(int n)
{
	int trv = 0;
	int num = n;

	while (num > 9 || num < -9)
	{
		num /= 10;
		trv++;
	}
	return (trv);
}
/**
 * int_to_string - turns an int into a string
 * @num: int
 * Return: returns the int as a string. returns NULL if failed
 */

char *int_to_string(int num)
{
	int plc, tens, i = 0, t = 0, x;
	char *res;

	plc = num;
	tens = 1;

	if (num < 0)
		t = 1;
	res = malloc(sizeof(char) * (numlen(plc) + 2 + t));
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		res[i] = '-';
		i++;
	}
	for (x = 0; plc > 9 || plc < -9; x++)
	{
		plc /= 10;
		tens *= 10;
	}
	for (plc = num; x >= 0; x--)
	{
		if (plc < 0)
		{
			res[i] = (plc / tens) * -1 + '0';
			i++;
		}
		else
		{
			res[i] = (plc / tens) + '0';
			i++;
		}
		plc %= tens;
		tens /= 10;
	}
	res[i] = '\0';
	return (res);
}
