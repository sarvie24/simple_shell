#include "shell.h"

/**
 * getenv_builtin - function to getenv
 * @n: name
 * Return: env
 *
 */

char *getenv_builtin(const char *n)
{
	unsigned int env_ind, env_len;
	char *env, *env_cpy;

	for (env_ind = 0; __environ[env_ind]; env_ind++)
	{
		if (strncmp(__environ[env_ind], n, strlen(n)) == 0)
		{
			env_len = strlen(__environ[env_ind]) - (strlen(n));
			env = malloc(sizeof(char) * env_len);
			if (env == NULL)
			{
				perror("Error: env malloc failed");
				return (NULL);
			}
			char_alloc(&env_cpy, strlen(__environ[env_ind]) + 1, "getenv: malloc fail");
			strcpy(env_cpy, __environ[env_ind]);
			strncpy(env, env_cpy += (strlen(n) + 1), env_len);
			free(env_cpy -= (strlen(n) + 1));
			return (env);
		}
	}

	return (NULL);
}

/**
 * print_env - function
 * Return: number
 *
 *
 *
 */

int print_env(void)
{
	unsigned int env_ind;

	for (env_ind = 0; __environ[env_ind]; env_ind++)
		printf("%s\n", __environ[env_ind]);
	return (0);
}
