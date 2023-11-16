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
	int i; 
	for (i = 0; builtins_str[i]; i++)
	{
		if (_strcmp(comm, builtins_str[i]) == 0)
			return (1);
	}
	return (0);
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
	if (_strcmp(comm[0], "exit") == 0)
		sh_exit(comm, argv, stats, index);
	else if (_strcmp(comm[0], "env") == 0)
		sh_env(comm, stats);
}

/**
 * sh_exit - Handle the 'exit' builtin command.
 * @comm: The command to handle.
 * @argv: List of argv. Not examined.
 * @stats: Pointer to the shell status.
 * @index: The index of the command.
 */
void sh_exit(char **comm, char **argv, int *stats, int index)
{
	int exit_value = (*stats);
	char *idx, mssg[] = ": exit: Illegal number: ";

	if (comm[1])
	{
		if (is_positive_nb(comm[1]))
			exit_value = _atoi(comm[1]);
		else
		{
			idx = _itoa(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, _strlen(idx));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, comm[1], _strlen(comm[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx);
			(*stats) = 2;
			freed(comm);
			return;
		}
	}
	freed(comm);
	exit(exit_value);
}

/**
 * sh_env - Handle the 'env' builtin command.
 * @comm: The command to handle.
 * @stats: Pointer to the shell status.
 */
void sh_env(char **comm, int *stats)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freed(comm);
	(*stats) = 0;
}
