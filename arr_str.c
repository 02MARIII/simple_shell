#include "main.h"

/**
 * count_tokens - Entry point
 * @buffer: param for string
 * description: the desciption
 * Return: int
*/
int count_tokens(char *buffer)
{
	char *token = NULL;
	char *temp = _strdup(buffer);
	int count = 0;

	if (temp == NULL)
		return (0);
	token = strtok(temp, " \t\n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}

	free(temp);
	return (count);
}
/**
 * arr_str - Tokenize a string into an array of strings.
 * @buffer: The string to be tokenized.
 *
 * Return:
 *  - On success, returns a dynamically allocated array of strings.
 *  - If the input string is NULL or no tokens are found, returns NULL.
 */
char **arr_str(char *buffer)
{
	int i = 0;
	int mov = 0;
	char *token = NULL;
	char **comm = NULL;

	if (buffer == NULL)
		return (NULL);

	mov = count_tokens(buffer);

	if (mov == 0)
	{
		free(buffer);
		return (NULL);
	}

	comm = malloc(sizeof(char *) * (mov + 1));

	if (!comm)
	{
		free(buffer);
		return (NULL);
	}

	token = strtok(buffer, " \t\n");

	while (token)
	{
		comm[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	free(buffer);
	comm[i] = NULL;
	return (comm);
}
