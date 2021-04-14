#include "head.h"
/**
 * *_strstr - finds string inside string
 * @haystack: string with all goodies
 * @needle: string to be found
 * Return: matching substring, else null
 */
char *_strstr(char *haystack, char *needle)
{
	char *start;
	char *search;

	while (*haystack != '\0')
	{
		start = haystack;
		search = needle;
		while (*needle != '\0' && *search != '\0' && *search == *haystack)
		{
			haystack++;
			search++;
		}
		if (*search == '\0')
			return (start);
		haystack = start + 1;
	}
	return (0);
}
/**
 * _strlen - checks length
 * @s: string to mesure
 *
 * Return: length of string
 *
 */
int _strlen(char *s)
{
	int i = 0;
	char c = 'n';

	while (c != '\0')
	{
		c = s[i];
		i++;

	}
	return (i - 1);
}
/**
 * _strcpy - copies given string and returns it
 * @dest: destination for copied string
 * @src: string to be copied
 * Return: copy of string
 */

char *_strcpy(char *dest, char *src)
{
	int i, count;

	i = _strlen(src);
	for (count = 0; count <= i; count++)
	{
		dest[count] = src[count];
	}
	return (dest);
}
/**
 * _strcmp - compares
 * @s1: string 1
 * @s2: string 2
 * Return: diference in ascii val
 *
 *
 */
int _strcmp(char *s1, char *s2)
{
	int i, r;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
	{
		i++;
	}
	r = s1[i] - s2[i];
	return (r);
}
/**
 * _strdup - returns pointer to new string duplicate
 * of string str
 * @str: string to duplicate
 * Return: On success, _strdup function returns pointer to duplicated
 * string, returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	int len;
	char *dup;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
	{
		;
	}
	dup = malloc((sizeof(char) * (len + 1)));
	if (dup == NULL)
		return (NULL);

	while (len >= 0)
	{
		dup[len] = str[len];
		len--;
	}
	return (dup);
}
