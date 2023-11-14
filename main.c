#include "shell.h"

/**
 * main - shell function
 * @argc: len of arguments
 * @argv: arguments of the compile time
 * @envp: environ variables
 * Return: 0 on success
 */
int main(int argc, char **argv, char **envp)
{
	char **commands;
	char *one_comm, *dels = " \n", *path;
	int status = 0;
	size_t num_bytes = 0, comm_num = 0;

	(void)argc;
	(void)argv;
	(void)envp;
	signal(SIGINT, is_signal);
	one_comm = NULL;
	while (1)
	{
		comm_num++;
		get_the_line(&one_comm, num_bytes, status);
		commands = make_arr(one_comm, dels);
		if (!(*commands))
			status = 0;
		else
		{
			if (builtin_check(commands))
			{
				if (builtin_expo(commands) == CODE)
				{
					free_all(commands, one_comm);
					exit(status);
				}
			}
			else
			{
				path = _path_finder(commands[0]);
				if (path != NULL)
					status = preprocessing(path, commands);
				else
					status = not_found(argv, commands, comm_num);
			}
		}
		free_all(commands, one_comm);
		one_comm = NULL;
	}
	return (0);
}
