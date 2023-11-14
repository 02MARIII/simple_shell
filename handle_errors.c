#include "main.h"

void printerr(char *key, char *cmd, int i)
{
    char *tmp;
    char msg[] = ": not found\n";

    tmp = _itoa(i);
    write(STDERR_FILENO, key, _strlen(key));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, tmp, _strlen(tmp));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, msg, _strlen(msg));

    free(tmp);
}