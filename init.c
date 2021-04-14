#include "head.h"
/**
 *
 *
 *
 */
void print_dir()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("#cisfun$");
}
/**
 *
 *
 */
int input(char **instr)
{
	char *buff;
	int gline = 0;
	size_t bufsize = 1024;
	char *tok;
	int i = 0;

	buff = malloc(sizeof(char) * 1024);
	if (buff == NULL)
	{
		printf("no malloc bufinput");
		return (-1);
	}
	gline = getline(&buff, &bufsize, stdin);
	if (gline > 0 )
	{
		tok = strtok(buff, " ");
		while (tok != NULL)
		{
			instr[i] =_strdup(tok);
			tok = strtok(NULL, " ");
			i++;
		}
		instr[i] = NULL;

		free(buff);
		return (1);
	}
	else
	{
		free(buff);
		return(-2);
	}
	return(1);
}

