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
			kill(pid, SIGKILL);
			ext = 0;
		}
		else
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(instr[0],instr, NULL) == -1)
					printf("fail to exec");
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
//make a strcmp switch that checks the 0 of 0 instr for / to see if full path command or if just command then execve it


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
