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
 * @next: next node in the list.
 *
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct list_env - linked list
 * @var: variable name.
 * @value: value for variable.
 *
 * @next: points to the next node in the linked list.
 *
 */
typedef struct list_env
{
	char *var;
	char *value;
	struct list_env *next;

} env_t;
extern char **environ;
char *input(void);
list_t *add_node_at_end(list_t **head, const char *str);
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char **get_argv(char *input);
env_t *add_node_list_env(env_t **head, char *str);
char *_getenv(const char *name);
char **dir_path(char *cmd);
void free_list(list_t *head);
void freenv(env_t *head);
void freearr(char **arr);
void exebuiltin(char **vector);
#endif
