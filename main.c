#include "head.h"
/**
 *
 *
 *
 */
int main()
{
	char **instr;
	int ext = 1;
	int i = 0;
	pid_t pid, pidm;
	int stat;

	pidm = getpid();
	instr = inarr();
	while (ext)
	{
		print_dir();

		input(instr);
		if (_strcmp(instr[0], "exit\n") == 0)
		{
			ext = 0;
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				for (i = 0; instr[i]; i++)
					printf("%s", instr[i]);
				if (execve(instr[0],instr, environ) == -1)
					printf("fail to exec\n");
				exit(98);
			}
			else
			{
				wait(&stat);
			}
		}



	}
	/*	for(i = 1000; i >= 0; i--)
			free(instr[i]);
		free(instr);*/


	return(0);
}
/**
 *
 *
 *
 */
char **inarr()
{
	char **instr;
	int i;


	instr = malloc(1000 * sizeof(char *));
	if (instr == NULL)
	{
		free(instr);
		return(NULL);
	}
	for(i = 0; i < 1000; i++)
	{
		instr[i] = malloc(1000 * sizeof(char));
		if (instr[i] == NULL)
		{
			for(; i >= 0; i--)
				free(instr[i]);
			free(instr);
			return(NULL);
		}
	}



	return(instr);
}
