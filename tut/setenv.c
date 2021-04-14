#include "hed.h"
/**
 *
 *
 *
 *
 */
int _setenv(const char *name, const char *value, int ovewrite)
{
	extern char **environ;
	int i = 0;
	char *var, *b;
	char *n = malloc(sizeof(char) * (strlen(name) + strlen(value) + 1));/* +1 for the =*/
	if(n == NULL)
	{
		printf("nomalloc n");
		return(-1);
	}


	while(environ[i] && b == NULL) /*Cycles to end of eviron if name not found*/
	{
		b = strstr(environ[i], name);
		if (b == NULL)
			i++;
	}
	if (b == NULL) /*if name not found will add new env*/
	{
		strcat(strcat(n , "="), value);
		environ[i] = n;
		environ[i + 1] = NULL;
	}
	else if (ovewrite == 1)
	{
		strcat(strcat(n , "="), value);
		environ[i] = n;
	}

	return (0);
}
