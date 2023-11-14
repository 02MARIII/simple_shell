#include "main.h"

void freed(char **frr)
{
    int i = 0;

    if (frr == NULL)
        return;
    for (i = 0; frr[i]; i++)
        free(frr[i]), frr[i] = NULL;
    free(frr);
    frr = NULL;
}