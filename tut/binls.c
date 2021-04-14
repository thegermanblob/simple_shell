#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 *
 *
 *
 *
 */
int main(void)
{
	int idx = 1;
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/home/", NULL};
	int status;

	do {
	pid = fork();
	idx++;
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		printf("Nah nah nah");
	}
	else
	{
		wait (&status);
		printf("Parent\n");
	}
	}while (pid != 0 && idx < 6);
	printf("papa\n");
	return (0);
}
