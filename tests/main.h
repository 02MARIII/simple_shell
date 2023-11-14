#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
char *_field(void);
char *_strdup(const char *str);
char **arr_str(char *buffer);
void freed(char **frr);
int _exec(char **comm, char **argv);

#endif