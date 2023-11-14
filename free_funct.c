#include "shell.h"

/**
 * free_all - free all matter
 * @arr: array
 * @n: n
 * Return: void
 */
void free_all(char **arr, char *n)
{
	int ind;

	for (ind = 0; arr[ind]; ind++)
		free(arr[ind]);
	free(arr);
	free(n);
}

/**
 * free_path - path free
 * @path: path to be freed
 * @arr: array
 * Return: void
 */

void free_path(char **path, char **arr)
{
	int ind;

	if (arr != NULL)
	{
		for (ind = 0; arr[ind]; ind++)
			if (arr[ind] != NULL)
				free(arr[ind]);
		free(arr);
	}
	if (*path != NULL)
		free(*path);
}
