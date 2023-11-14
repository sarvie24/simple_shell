#include "shell.h"

/**
 * get_the_line - function to getline customly
 * @input: place holder for the reading
 * @num: num of bytes
 * @status: status
 * Return: number of chars of the reading line
 */
ssize_t get_the_line(char **input, size_t num, int status)
{
	ssize_t num_chars;

	prompt();
	num_chars = getline(input, &num, stdin);
	if (num_chars == -1)
	{
		free(*input);
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", strlen("\n"));
		}
		exit(status);
	}

	return (num_chars);
}
