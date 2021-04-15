#ifndef HEADER_H
#define HEADER_H
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
/**
 * struct list_s - linked list
 * @str: string
 * @next: next node in the list
 *
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct list_env - linked list
 * @var: variable name
 * @value: value for variable
 *
 * @next: next node in the list
 *
 */
typedef struct list_env
{
	char *var;
	char *value;
	struct list_env *next;

} env_t;
extern char **environ;
char *getcomm(void);
list_t *add_node_at_end(list_t **head, char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char **getarg(char *input, int *ex1t);
env_t *add_node_list_env(env_t **head, char *str);
char *genv(char *name);
char **dir_path(char *cmd);
void free_list(list_t *head);
void freenv(env_t *head);
void freearr(char **arr);
void exebuiltin(char **comm, int *ex1t);
#endif
