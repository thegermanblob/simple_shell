#include "head.h"
/**
 * main - Entry point. Runs a basic command line interpreter.
 *
 * Return: always 0.
 */

int main(void)
{
	char *in, **av;
	pid_t PID;
	int status;

	while (1)
	{
		PID = fork();
		if (PID == 0)
		{
			in = input();
			av = get_argv(in);
			status = execve(av[0], av, environ);
			if (status == -1)
			{
				freearr(av);
				perror("Error:");
			}
			else
				freearr(av);
		}
		else if (PID == -1)
			exit(EXIT_FAILURE);
		else
			wait(NULL);
	}
	return (0);
}
