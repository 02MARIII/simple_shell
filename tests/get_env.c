#include "main.h"

char *_getenv(char *vr)
{
    char *temp, *env;
    char *name, *val;
    int i = 0;

    while (environ[i])
    {
        temp = _strdup(environ[i]);
        name = strtok(temp, "=");
        if (_strcmp(name, vr) == 0)
        {
            val = strtok(NULL, "\n");
            env = _strdup(val);
            free(temp);
            return (env);
        }
        free(temp);
        temp = NULL;
        i++;
    }
    return (NULL);
}