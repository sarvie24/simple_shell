#include "shell.h"

/**
 * path_creator - function to create path
 * @file: file
 * @arr: array of args
 * @index: index
 * @arg: arguments
 * Return: void
 *
 */
void path_creator(char **file, char **arr, int index, char *arg)
{
	char_alloc(file, (strlen(arr[index]) + strlen(arg) + 2),
			"Error: failed to make path");
	strcpy(*file, arr[index]);
	strcat(*file, "/");
	strcat(*file, arg);
	strcat(*file, "\0");
}

/**
 * valid_path - test validity
 * @path: path to be tested
 * Return: 1 on sucess or 0 on fail
 *
 *
 */

int valid_path(char *path)
{
	size_t len = strlen(path);

	if (len >= strlen("../"))
	{
		if (strncmp(path, "../", strlen("../")) == 0)
		{
			return (1);
		}
	}
	if (len >= strlen("./"))
	{
		if (strncmp(path, "./", strlen("./")) == 0)
		{
			return (1);
		}
	}
	if (len >= strlen("/"))
	{
		if (strncmp(path, "/", strlen("/")) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _path_finder - function for path finder
 * @name: name of the path
 * Return: path on sucess or NULL
 *
 *
 */

char *_path_finder(char *name)
{
	struct stat sub;
	char **arr;
	char *path, *dels = ":", *file;
	int ind, path_found;

	path = getenv_builtin("PATH");
	if (path != NULL)
	{
		arr = make_arr(path, dels);
		if (arr != NULL)
		{
			for (ind = 0; arr[ind]; ind++)
			{
				path_creator(&file, arr, ind, name);
				path_found = stat(file, &sub);
				if (path_found == 0)
				{
					free_path(&path, arr);
					return (file);
				}
				free(file);
			}
			free_path(&path, arr);
		}
		else
		{
			free(path);
		}
	}
	path_found = stat(name, &sub);
	if (path_found == 0 && valid_path(name))
	{
		return (name);
	}
	return (NULL);
}
