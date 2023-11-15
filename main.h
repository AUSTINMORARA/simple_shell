#ifndef MAIN_H
#define MAIN_H
#define PATH "/bin:"

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char **tokenise(char *buffer);
#endif
