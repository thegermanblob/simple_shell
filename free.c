#include "head.h"
/**
* free_list - free list
 * @head: head of list
 *
 * Return: nothing
 */
void free_list(list_t *head)
{

	while (head != NULL)
	{
		free(head->str);
		free(head);
		head = head->next;
	}
}
/**
* freenv - free list
 * @head: head of list
 *
 * Return: nothing
 */
void freenv(env_t *head)
{
	while (head != NULL)
	{
		free(head->var);
		free(head->value);
		free(head);
		head = head->next;
	}
}
/**
 * free_array - free an array
 * @arr: array
 *
 * Return: nothing
 */
void freearr(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
