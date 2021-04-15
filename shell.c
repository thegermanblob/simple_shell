#include "head.h"
/**
 * main - runs a Shell.
 *
 * Return: always 0.
 */

int main(void)
{
	char *in, **av;
	pid_t pid;
	int status, ex1t;


	do {
		pid = fork();
	ex1t = 1;

		if (pid == 0)
		{
			in = getcomm();
			av = getarg(in, &ex1t);
			if (_strcmp(in, "exit"))
			{
				ex1t = 0;
				exit(98);
			}
			status = execve(av[0], av, environ);

			if (status == -1)
			{
				freearr(av);
				perror("Error:");
			}
			else
				freearr(av);
			exit(98);

		}
		else if (pid == -1)
			exit(EXIT_FAILURE);
		else
			wait(NULL);

	} while (ex1t);

	return (0);
}
