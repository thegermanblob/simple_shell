#include"hed.h" 
/**
 *
 *
 *
 */
int main()
{
	char *token, *var;
	list_t *head;

	head = malloc(sizeof(list_t));
	if(head == NULL)
	{
		printf("nomalloc");
		exit(98);
	}


	var = splitpath();
	token = strtok(var, ":");
	head->str = strdup(token);
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	print_list(head);
	return (0);
}
/**
 *
 *
 *
 *
 */
char *splitpath()
{
	extern char **environ;
	int i = 0;
	char *var, *b;

	while(environ[i] && b == NULL)
	{
		b = strstr(environ[i], "PATH");
		if  (b != NULL)
		{
			var = strstr(b, "=");
		}

		i++;
	}
	return (var + 1);
}
/**
 *
 *
 *
 *
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp, *last;
	int i = 0;

	last = *head;
	temp = malloc(sizeof(list_t));

	if (temp == NULL)
		return (NULL);


	if (str == NULL)
	{
		temp->str = NULL;
	}
	else
	{
		temp->str = strdup(str);
	}
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
	}
	return (*head);
}
/**
 * print_list - prints lists
 * @h: list to be printed
 * Return: returns the amount of elements printed
 */
size_t print_list(const list_t *h)
{
	const list_t *n;
	size_t i = 0;

	n = h;

	while (n != NULL)
	{
		if (n->str == NULL)
			;
		else
			printf("%s\n", n->str);
		n = n->next;
		i++;
	}


	return (i);
}


