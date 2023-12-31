#include "main.h"
char *_handlepath(char *comm)
{
    char *blassa, *shll, *folder;
    int i = 0;
    struct stat nd;

    while (comm[i])
    {
        if (comm[i] == '/')
        {
            if (stat(comm, &nd) == 0)
                return (_strdup(comm));
            return (NULL);            
        }
        i++;
    }
    blassa = _getenv("PATH");
    if (!blassa)
        return (NULL);
    folder = strtok(blassa, ":");
    while (folder != NULL)
    {
        shll = malloc(_strlen(folder) + _strlen(comm) + 2);
        if (shll != NULL)
        {
            _strcpy(shll, folder);
            _strcat(shll, "/");
            _strcat(shll, comm);
            if (stat(shll, &nd) == 0)
            {
                free(blassa);
                return (shll);
            }
            free(shll), shll = NULL;
            folder = strtok(NULL, ":");
        }
    }
    free(blassa);
    return (NULL);
}