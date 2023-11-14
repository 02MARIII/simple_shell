#include "main.h"

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
    } else
    {
        waitpid(som, &stats, 0);
        freed(comm);
        free(shell), shell = NULL;
    }
    return (WEXITSTATUS(stats));
}