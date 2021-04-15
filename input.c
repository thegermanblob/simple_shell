#include "head.h"
/**
 * dpath - link comm to path
 * @ctl: command to link
 *
 * Return: An array of strings
 */
char **dpath(char *ctl)
{
	char *path, *tok, *sub_dir, **dir;
	int count = 1, i = 0;

	path = genv("PATH");
	for (; path[i]; i++)
	{
		if (path[i] == ':')
			count++;
	}
	dir = malloc(sizeof(char *) * (count + 1));
	tok = strtok(path, ":");
	for (i = 0; tok != NULL; i++)
	{
		sub_dir = malloc(_strlen(tok) + _strlen(ctl) + 2);
		_strcpy(sub_dir, tok);
		_strcat(sub_dir, "/");
		_strcat(sub_dir, ctl);
		dir[i] = sub_dir;
		tok = strtok(NULL, ":");
	}
	free(path);
	dir[count] = NULL;
	return (dir);
}
/**
 * getcomm - gets input
 *
 * Return: command string
 */
char *getcomm(void)
{
	char *input, *line = NULL;
	size_t len = 0;
	int r, i;

	write(1, "$ ", 2);
	r = getline(&line, &len, stdin);
	if (r == -1)
	{
		free(line);
		return (0);
	}
	input = malloc(_strlen(line));
	for (i = 0; i < _strlen(line) - 1; i++)
	{
		input[i] = line[i];
	}
	input[i] = '\0';
	free(line);
	return (input);
}
/**
 * genv - search for a variable
 * @name: name of variable
 *
 * Return: pointer to variable
 */
char *genv(char *name)
{
	int i;
	char *value = NULL;
	env_t *head = NULL;

	for (i = 0; environ[i]; i++)
	{
		add_node_list_env(&head, environ[i]);
	}
	while (head != NULL)
	{
		if (!_strcmp(head->var, name))
			value = _strdup(head->value);
		head = head->next;
	}
	freenv(head);
	return (value);
}
/**
 * getarg - takes input and tokenize it
 * @input: string from command line
 * @ex1t: exit param
 *
 * Return: array of string.
 */
char **getarg(char *input, int *ex1t)
{
	int count = 0, i = 0;
	char *t, **av, *arr, **tmp;
	list_t *head = NULL;
	struct stat st;

	arr = _strdup(input);
	t = strtok(arr, " ");
	while (t != NULL)
	{
		add_node_at_end(&head, t);
		count++;
		t = strtok(NULL, " ");
	}
	free(arr);
	av = malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		av[i] = _strdup(head->str);
		head = head->next;
		i++;
	}
	free_list(head);
	av[count] = NULL;
	exebuiltin(av, ex1t);
	if (av[0][0] != '/')
	{
		tmp = dpath(av[0]);
		for (i = 0; tmp[i]; i++)
		{
			if (stat(tmp[i], &st) == 0  && st.st_mode & S_IXUSR)
			{
				free(av[0]);
				av[0] = _strdup(tmp[i]);
			}
		}
		freearr(tmp);
	}
	return (av);
}
