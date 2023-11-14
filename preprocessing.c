#include "shell.h"

/**
 * preprocessing - function to fork the code
 * @command: commands to be excuted
 * @arr: array of commands
 * Return: status of the process
 *
 */
int preprocessing(char *command, char **arr)
{
	int status, error;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork child failed");
	}
	if (pid == 0)
	{
		error = execve(command, arr, __environ);
		if (error == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		if (!isatty(STDIN_FILENO))
		{
			return (status);
		}
	}
	return (0);
}
