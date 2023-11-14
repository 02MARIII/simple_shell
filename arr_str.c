#include "main.h"
char **arr_str(char *buffer)
{
    char *token = NULL;
    char *temp = NULL;
    char **comm = NULL;
    int mov = 0;
    int i = 0;

    if (buffer == NULL)
        return (NULL);
    temp = _strdup(buffer);
    token = strtok(temp, " \t\n");
    if (!token)
    {
        free(temp);
        temp = NULL;
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    while (token)
    {
        mov++;
        token = strtok(NULL, " \t\n");
    }
    free(temp);
    temp = NULL;
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
    buffer = NULL;
    comm[i] = NULL;
    return (comm);
}