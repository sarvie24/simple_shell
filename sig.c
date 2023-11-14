#include "shell.h"

/**
 * is_signal - function
 * @sig: number
 * Return: void
 */
void is_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}
