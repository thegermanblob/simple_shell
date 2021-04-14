	
#ifndef HEAD1
#define HEAD1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

char **inarr();
void init_shell();
int input(char **instr);
void print_dir();
void exec();
void help();
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int execute(char **instr);

#endif
