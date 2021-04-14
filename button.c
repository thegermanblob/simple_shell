/**
 * dir_path - link 'ctl' with all of directories in the enviroment
 * varible PATH.
 * @ctl: command to link.
 *
 * Return: An array of string with all link  directories with the ctl.
 */
char **dir_path(char *ctl)
{
	char *path, *token, *sub_dir, **arr_dir;
	int count = 1, i = 0;

	path = _getenv("PATH");
	for (; path[i]; i++)
	{
		if (path[i] == ':')
			count++;
	}
	arr_dir = malloc(sizeof(char *) * (count + 1));
	token = strtok(path, ":");
	for (i = 0; token != NULL; i++)
	{
		sub_dir = malloc(_strlen(token) + _strlen(ctl) + 2);
		_strcpy(sub_dir, token);
		_strcat(sub_dir, "/");
		_strcat(sub_dir, ctl);
		arr_dir[i] = sub_dir;
		token = strtok(NULL, ":");
	}
	free(path);
	arr_dir[count] = NULL;
	return (arr_dir);
}
/**
 * get_commands - takes a string from standard input.
 *
 * Return: An array of characteres which a copy of the string
 *         taken from stdin.
 */
char *get_commands(void)
{
	char *string, *line = NULL;
	size_t len = 0;
	int read, i;

	write(1, "$ ", 2);
	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (0);
	}
	string = malloc(_strlen(line));
	for (i = 0; i < _strlen(line) - 1; i++)
	{
		string[i] = line[i];
	}
	string[i] = '\0';
	free(line);
	return (string);
}
/**
 * _getenv - search a enviroment variable and returns its value.
 * @name: name of the enviroment variable to be searched.
 *
 * Return: pointer to value of the variable.
 */
char *_getenv(const char *name)
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
		if (!_strcmp(head->key, name))
			value = _strdup(head->value);
		head = head->next;
	}
	input(head);
	return (value);
}
/**
 * get_argv - takes the string from the command lines and tokenizes it
 * adding the divided string in an array of string.
 * @input: string from command line.
 *
 * Return: array of string.
 */
char **get_argv(char *input)
{
	int count = 0, i = 0;
	char *t, **av, *_array, **tmp;
	list_t *head = NULL;
	struct stat st;

	_array = _strdup(input);
	free(input);
	t = strtok(_array, " ");
	while (t != NULL)
	{
		add_node_at_end(&head, t);
		count++;
		t = strtok(NULL, " ");
	}
	free(_array);
	av = malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		av[i] = _strdup(head->str);
		head = head->next;
		i++;
	}
	input(head);
	av[count] = NULL;
	exebuiltin(av);
	if (av[0][0] != '/')
	{
		tmp = dir_path(av[0]);
		for (i = 0; tmp[i]; i++)
		{
			if (stat(tmp[i], &st) == 0  && st.st_mode & S_IXUSR)
			{
				free(av[0]);
				av[0] = _strdup(tmp[i]);
			}
		}
		free_array(tmp);
	}
	return (av);
}
/**
 * exebuiltin - executes builtins commands.
 * @vector: array of string.
 *
 * Return: nothing.
 *
 */
void exebuiltin(char **vector)
{
	int i = 0;

	if (_strcmp(vector[0], "exit") == 0)
	{
		free_array(vector);
		exit(1);
	}
	if (_strcmp(vector[0], "env") == 0)
	{
		while (environ[i])
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		free_array(vector);
		exit(0);
	}
}
