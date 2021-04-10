#include "hed.h"
/**
 *
 *
 *
 *
 */
char *genv(const char *name)
{
	extern char **environ;
	int i;
	char *var, *b;

	while(environ[i] && b == NULL)
	{
		b = strstr(environ[i], name);
		if  (b != NULL)
		{
			var = strstr(b, "=");
		}

		i++;
	}
	return (var + 1);
}

