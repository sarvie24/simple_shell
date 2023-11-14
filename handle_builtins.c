#include "shell.h"

/**
 * builtin_check - function for checking the commands
 * @arr: array
 * Return: 1 or 0
 *
 *
 */

int builtin_check(char **arr)
{
	int i;

	builtin_t functions[] = {
		{"env", env_builtin},
		{"exit", exit_builtin},
		{"cd", cd_builtin},
		{NULL, NULL}
	};

	if (arr == NULL || arr[0] == NULL)
	{
		return (0);
	}

	for (i = 0; functions[i].arg != NULL; i++)
	{
		if (strcmp(arr[0], functions[i].arg) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * builtin_expo - funciton to get builtins
 * @arr: array
 * Return: functon or NULL
 *
 *
 */

int builtin_expo(char **arr)
{
	int i;
	builtin_t functions[] = {
		{"env", env_builtin},
		{"exit", exit_builtin},
		{"cd", cd_builtin},
		{NULL, NULL}
	};

	if (arr == NULL || arr[0] == NULL)
	{
		return (0);
	}

	for (i = 0; functions[i].arg != NULL; i++)
	{
		if (strcmp(arr[0], functions[i].arg) == 0)
			return (functions[i].func(arr));
	}
	return (0);
}
