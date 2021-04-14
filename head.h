#ifndef HEADER_H
#define HEADER_H
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#define _GNU_SOURCE

/**
 * struct list_s - singly linked list
 * @str: string tokenized of command line arguments.
 * @next: points to the next node in the linked list.
 *
 * Description: singly linked list, the nodes are agregated at the end.
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct list_env - singly linked list
 * @key: string tokenized of command line arguments.
 * @value: string tokenized of command line arguments.
 *         Both arguments correspondig to 'KEY=value'.
 * @next: points to the next node in the linked list.
 *
 * Description: singly linked list, the nodes are agregated at the end.
 */
typedef struct list_env
{
	char *key;
	char *value;
	struct list_env *next;

} env_t;
extern char **environ;
char *get_commands(void);
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
void free_list_env(env_t *head);
void free_array(char **arr);
void exe_builtin(char **vector);
#endif
