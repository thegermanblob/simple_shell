#include "hed.h"

int main()
{
	char *var;
	printf("hi");

	_setenv("hello", "pepito", 0);
	var = malloc(sizeof(char) * strlen(genv("hello")));

	var = genv("hello");
/*	printf("%s\n", var);
	_setenv("hello", "dave", 1);
	var = getenv("hello");
	printf("%s\n", var);
*/	return(0);
}
