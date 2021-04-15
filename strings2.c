#include "head.h"
/**
 * _strcat - concanates string
 * @dest: destination string
 * @src: source strin
 * Return: concanated string
 *
 */
char *_strcat(char *dest, char *src)
{
	int i, scount;

	scount = 0;
	i = _strlen(dest);

	while (src[scount] != '\0')
	{
		dest[i] = src[scount];
		scount++;
		i++;
	}
	return (dest);
}
