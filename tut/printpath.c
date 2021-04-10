#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *
 *
 *
 *
 */
char *splitpath()
{
	extern char **environ;
	int i;
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
 */
int main()
{
	char *token, *var;


	var = splitpath();
	token = strtok(var, ":");
	while (token != NULL)
	{
		printf("%s\n",token);
		token = strtok(NULL, ":");
	}


	return (0);
}
