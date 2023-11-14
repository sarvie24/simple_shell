#include "shell.h"

/**
 * env_builtin - function to print env variables
 * @arr: array
 * Return: index
 *
 */
int env_builtin(char **arr)
{
	int env_index;
	(void)arr;

	for (env_index = 0; __environ[env_index]; env_index++)
	{
		write(STDOUT_FILENO, __environ[env_index], strlen(__environ[env_index]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}

	return (env_index);
}

/**
 * exit_builtin - function to exit
 * @arr: array
 * Return: CODE
 *
 */

int exit_builtin(char **arr)
{
	if (arr[1] != NULL)
	{
		exit(atoi(arr[1]));
	}
	else
	{
		return (CODE);
	}
}

/**
 * cd_builtin - change directory
 * @arr: array
 * Return: 0 on success
 *
 */

int cd_builtin(char **arr)
{
	char cwd[1024];
	char *home = getenv_builtin("HOME");

	if (arr[1] == NULL)
	{
		if (chdir(home) == -1)
			perror("cd: ");
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("getcwd: ");
	}
	else
	{
		if (chdir(arr[1]) == -1)
		{
			perror("cd: ");
		}
		else
		{
			if (getcwd(cwd, sizeof(cwd)) == NULL)
				perror("getcwd: ");
		}
	}
	free(home);
	return (0);
}
