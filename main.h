#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

extern char **env;
char **tokenise(char *buffer);
void path(char **command);
char *fullpath(char *dir, char *cmd);
int _strlen(char *c);
char *_strcat(char *dest, char *source);
void execution(char **array, char *buffer);

#endif
