#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#ifndef SHELL_H
#define SHELL_H

#define MAXARGS 128
#define MAXLINE 1024

void eval(char* cmdline);
int parseline(char* cmdline,char** argv);
int builtin_command(char** argv);

#endif
