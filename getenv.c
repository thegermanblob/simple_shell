#include "head.h"
/**
 *
 *
 *
 *
 */
char *genv(char *name)
{
	extern char **environ;
	int i;
	char *var, *b;

	while(environ[i] && b == NULL)
	{
		b = _strstr(environ[i], name);
		if  (b != NULL)
		{
			var = _strstr(b, "=");
		}

		i++;
	}
	return (var + 1);
}

