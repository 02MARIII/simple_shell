#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
char *_field(void);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char **arr_str(char *buffer);
void freed(char **frr);
int _exec(char **comm, char **argv, int index);
char *_getenv(char *vr);
char *_handlepath(char *comm);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_search_path(char *comm);
char *_itoa(int n);
void str_rev(char *str, int len);
void printerr(char *key, char *cmd, int i);
void free2DArray(char **array, int rows);
int cmp_builtins(char *comm);
void handle_builtins(char **comm, char **argv, int *stats, int index);
void sh_exit(char **comm, char **argv, int *stats, int index);
void sh_env(char **comm, int *stats);
int is_positive_nb(char *str);
int _atoi(char *str);
#endif
