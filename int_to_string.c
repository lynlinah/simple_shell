#include "shell.h"

/**
 * cnt_n0 - counts num of 0s in a decimal no
 * @n: num
 * Return: returns cnt of nums
 */
int cnt_n0(int n)
{
	int cnt = 0;
	int num = n;

	while (num > 9 || num < -9)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

/**
 * int2str - turns an integer into a string
 * @num:
 * Return: returns the string. else NULL if failed
 */

char *int2str(int num)
{
	int nums, plc, i = 0, t = 0, x;
	char *res;

	nums = num;
	plc = 1;

	if (num < 0)
		t = 1;
	res = malloc(sizeof(char) * (cnt_n0(nums) + 2 + t));
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		res[i] = '-';
		i++;
	}
	for (x = 0; nums > 9 || nums < -9; x++)
	{
		nums /= 10;
		plc *= 10;
	}
	for (nums = num; x >= 0; x--)
	{
		if (nums < 0)
		{
			res[i] = (nums / plc) * -1 + '0';
			i++;
		}
		else
		{
			res[i] = (nums / plc) + '0';
			i++;
		}
		nums %= plc;
		plc /= 10;
	}
	res[i] = '\0';
	return (res);
}
