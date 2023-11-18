/**
 * printerr - Print an error message for a command not found.
 * @key: The name of the program or shell.
 * @cmd: The command that was not found.
 * @index: The index of the command in the shell's history.
 */
void printerr(char *key, char *cmd, int index)
{
	char *tmp;
	char msg[] = ": not found\n";

	tmp = _itoa(index);
	write(STDERR_FILENO, key, _strlen(key));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, tmp, _strlen(tmp));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(tmp);
}

