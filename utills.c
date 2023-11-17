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
 * Returns:
 *  - On success, returns a dynamically allocated string representing the integer.
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

