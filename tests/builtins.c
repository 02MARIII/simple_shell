#include "main.h"

/**
 * cmp_builtins - Compare the command with a list of builtins.
 * @comm: The command to compare.
 *
 * Return: 1 if the command is a builtin, 0 otherwise.
 */
int cmp_builtins(char *comm)
{
	char *builtins_str[] = {"env", "exit", "NULL"};

	for (size_t i = 0; builtins_str[i]; i++)
	{
		if (_strcmp(comm, builtins_str[i]) == 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * handle_builtins - Handle the execution of builtins.
 * @comm: The command to handle.
 * @argv: List of argv. Not examined.
 * @stats: Pointer to the shell status.
 * @index: The index of the command.
 */
void handle_builtins(char **comm, char **argv, int *stats, int index)
{
	(void)argv;

	if (_strcmp(comm[0], "exit") == 0)
		sh_exit(comm, stats, index);

	else if (_strcmp(comm[0], "env") == 0)
		sh_env(comm, stats);
}

/**
 * sh_exit - Handle the 'exit' builtin command.
 * @comm: The command to handle.
 * @stats: Pointer to the shell status.
 * @index: The index of the command.
 */
void sh_exit(char **comm, int *stats, int index)
{
	int exit_val = (*stats);
	char *idx, mssg[] = ": exit: Illegal number: ";

	if (comm[1])
	{
		if (is_positive_nb(comm[1]))
		{
			exit_val = _atoi(comm[1]);
		}
		else
		{
			idx = _itoa(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, comm[1], _strlen(comm[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx);
			free2DArray(comm);
			(*stats) = 2;
			return;
		}
	}
	free2DArray(comm);
	exit(*stats);
}

/**
 * sh_env - Handle the 'env' builtin command.
 * @comm: The command to handle.
 * @stats: Pointer to the shell status.
 */
void sh_env(char **comm, int *stats)
{
	int i;

	for (i = 0; environ[i], _strlen(environ[i])); // <-- Check this line
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]))
		write(STDOUT_FILENO, "\n", 1);
	}
	free2DArray(comm);
	(*stats) = 0;
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
	{
		i = 0;
	}

	for (; str[i] != '\0'; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}

	return (sign * num);
}

/**
 * free2DArray - Free memory allocated for a 2D array.
 * @array: The 2D array.
 * @rows: The number of rows in the array.
 */
void free2DArray(int **array, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		free(array[i]);
	}

	free(array);
}

