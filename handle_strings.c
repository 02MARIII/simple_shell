#include "main.h"
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
int _strlen(char *s)
{
	int vari;

	for (vari = 0; *s != '\0'; s++)
		vari++;
	return (vari);
}
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
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i++] = src[j];
		j++;
	}
	return (dest);
}