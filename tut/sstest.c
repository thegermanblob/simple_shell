#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 */
int main()
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	extern char** environ;
	int i;

	while (environ[i])
	{
		printf("%s\n",environ[i]);
		i++;
	}
	return (0);
}
