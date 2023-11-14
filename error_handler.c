#include "shell.h"

/**
 * not_found - function for errors
 * @argv: system name
 * @commands: comam
 * @num_comm: number of commands
 * Return: 127
 */

int not_found(char **argv, char **commands, size_t num_comm)
{
	char *error;
	char *str = atoi_reverse(num_comm);
	int size = (strlen(argv[0]) + (2 * strlen(": ")) +
			counter(num_comm) +
			strlen(commands[0]) + strlen(": not found\n") + 1);

	char_alloc(&error, size, "Error: malloc error");
	strcpy(error, argv[0]);
	strcat(error, ": ");
	strcat(error, str);
	strcat(error, ": ");
	strcat(error, commands[0]);
	strcat(error, ": not found\n");
	strcat(error, "\0");

	write(STDERR_FILENO, error, strlen(error));
	free(error);
	free(str);
	return (127);
}
