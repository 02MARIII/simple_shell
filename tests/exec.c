#include "main.h"

int _exec(char **comm, char **argv)
{
    pid_t som;
    int stats;

    som = fork();
    if (som == 0)
    {
        if (exceve(comm[0], comm, environ) == -1)
        {
            perror(argv[0]);
            freed(comm);
            exit(0);
        }
    } else
    {
        waitpid(som, &stats, 0);
        freed(comm);
    }
    return (WEXITSTATUS(stats));
}