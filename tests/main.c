#include "main.h"

char *_field(void)
{
    char *buffer = NULL;
    size_t len = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO) == 1)
            write(STDOUT_FILENO, "$ ", 2);
    n = getline(&buffer, &len, stdin);
    if(n == EOF)
    {
        free(buffer);
        return (NULL);
    }
    return (buffer);
}

int main(int argc, char *argv[])
{
    char *buffer = NULL;
    char **comm = NULL;
    int stats = 0;
    (void) argc;

    while (1)
    {
        buffer = _field();
        if (buffer == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (stats);
        }
        comm = arr_str(buffer);
        if (comm == NULL)
            continue;
        stats = _exec(comm, argv); 
    }
    return (0);
}