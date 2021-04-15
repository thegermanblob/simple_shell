#include "head.h"
/**
 * exebuiltin - executes builtins
 * @comm: command
 * @ex1t: exit param
 *
 * Return: nothing.
 *
 */
void exebuiltin(char **comm, int *ex1t)
{
	int i = 0;

	if (_strcmp(comm[0], "exit") == 0)
	{
		freearr(comm);
		*ex1t = 0;
		exit(1);
	}
	else
		*ex1t = 1;

	if (_strcmp(comm[0], "env") == 0)
	{
		while (environ[i])
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		freearr(comm);
		exit(0);
	}
}
/**
 * add_node_list_env - add node at end of env
 * @head: head of list
 * @str: string with env
 *
 * Return: pointer to new node
 */
env_t *add_node_list_env(env_t **head, char *str)
{
	env_t *new, *tmp;
	char *tok1, *tok2;

	tok1 = strtok(str, "=");
	tok2 = strtok(NULL, "\0");
	new = malloc(sizeof(env_t));
	if (!new)
		return (NULL);
	tmp = *head;
	new->var = _strdup(tok1);
	new->value = _strdup(tok2);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}
/**
 * add_node_at_end - add new node
 * @head: head of list
 * @str: string
 *
 * Return: pointer to new node
 */
list_t *add_node_at_end(list_t **head,char *str)
{
	list_t *new, *temp;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	temp = *head;
	new->str = _strdup(str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (new);
}
