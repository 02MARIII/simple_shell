#include "main.h"

/**
 * freed - Free memory allocated for a 2D array.
 * @frr: The 2D array to be freed.
 */
void freed(char **frr)
{
	int i = 0;

	if (frr == NULL)
		return;

	for (i = 0; frr[i]; i++)
		free(frr[i]), frr[i] = NULL;

	free(frr);
	frr = NULL;
}

/**
 * _itoa - Convert an integer to a string.
 * @n: The integer to be converted.
 *
 * Return:
 *  - On success, returns a dynamically,
 *   allocated string representing the integer.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	str_rev(buffer, i);
	return (_strdup(buffer));
}

/**
 * str_rev - Reverse a string.
 * @str: The string to be reversed.
 * @len: The length of the string.
 */
void str_rev(char *str, int len)
{
	char temp;
	int s = 0;
	int f = len - 1;

	while (s < f)
	{
		temp = str[s];
		str[s] = str[f];
		str[f] = temp;
		s++;
		f--;
	}
}

/**
 * _atoi - Convert a string to an integer.
 * @str: The string to convert.
 *
 * Return: The converted integer.
 */
int _atoi(char *str)
{
	int i, num = 0;
	int sign = 1;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	else
		i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (sign * num);
}

/**
 * is_positive_nb - Check if a string represents a positive number.
 * @str: The string to check.
 *
 * Return: 1 if the string is a positive number, 0 otherwise.
 */
int is_positive_nb(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

