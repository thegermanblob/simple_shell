#ifndef _SHELL
#define _SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

list_t *add_node_end(list_t **head, const char *str);
char *splitpath();
size_t print_list(const list_t *h);
int _setenv(const char *name, const char *value, int overwrite);
char *genv(const char *name);
#endif
