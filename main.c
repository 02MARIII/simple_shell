#include "main.h"

/**
 * _field - Read a line from standard input.
 *
 * Returns:
 *  - A pointer to the read line.
 *  - NULL if an error occurs or end-of-file is reached.
 */
char *_field(void)
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
	n = getline(&buffer, &len, stdin);
	if (n == EOF)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

/**
 * main - Entry point of the program.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Returns:
 *  - 0 on successful execution.
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	char **comm = NULL;
	int stats = 0, index = 0;
	(void)argc;

	while (1)
	{
		buffer = _field();
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stats);
		}
		index++;
		comm = arr_str(buffer);
		if (comm == NULL)
			continue;

		if (cmp_builtins(comm[0]))
			handle_builtins(comm, argv, &stats, index);
		else
			stats = _exec(comm, argv, index);
	}
	return (0);
}
