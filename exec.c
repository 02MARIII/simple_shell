#include "main.h"

/**
 * _exec - Execute a command and get its exit status.
 * @comm: The command to be executed.
 * @argv: List of argv.
 * @index: The index of the command in the shell's history.
 *
 * This function executes the specified command, waits for its completion,
 * and returns the exit status of the command.
 *
 * Return:
 *  - On success, returns the exit status of the command.
 *  - If the command is not found or encounters an error, returns 127.
 */
int _exec(char **comm, char **argv, int index)
{
	char *shell;
	pid_t som;
	int stats;

	shell = _handlepath(comm[0]);
	if (!shell)
	{
		printerr(argv[0], comm[0], index);
		freed(comm);
		return (127);
	}

	som = fork();
	if (som == 0)
	{
		if (execve(shell, comm, environ) == -1)
		{
			free(shell), shell = NULL;
			freed(comm);
		}
	}
	else
	{
		waitpid(som, &stats, 0);
		freed(comm);
		free(shell), shell = NULL;
	}

	return (WEXITSTATUS(stats));
}

