#include "main.h"

/**
 * _strdup - Duplicate a string.
 * @str: The string to be duplicated.
 *
 * Return:
 *  - On success, returns a pointer to a newly allocated space in memory
 *    containing a duplicate of the given string.
 *  - If memory allocation fails or the input string is NULL, returns NULL.
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		ptr[i] = str[i];

	return (ptr);
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return:
 *  - 0 if the strings are equal.
 *  - A positive value if the first character that does not match has a greater
 *    value in s1 than in s2.
 *  - A negative value if the first character that does not match has a greater
 *    value in s2 than in s1.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

/**
 * _strlen - Calculate the length of a string.
 * @s: The string.
 *
 * Return:
 *  - The length of the string.
 */
int _strlen(char *s)
{
	int vari = 0;

	while (s[vari])
		vari++;

	return (vari);
}

/**
 * _strcpy - Copy a string.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return:
 *  - A pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;
	int y;

	while (*(src + x) != '\0')
		x++;

	for (y = 0; y < x; y++)
		dest[y] = src[y];

	dest[x] = '\0';

	return (dest);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return:
 *  - A pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}

	*p = '\0';
	return (dest);
}

