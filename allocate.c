#include "shell.h"

/**
 * arr_alloc - function to alloc array of given size
 * @arr: array
 * @size: size
 * @message: error message
 * Return: array on sucess
 *
 */

char **arr_alloc(char **arr, size_t size, char *message)
{
	arr = (char **)malloc(sizeof(char *) * size);
	if (arr == NULL)
	{
		perror(message);
		return (NULL);
	}
	return (arr);
}

/**
 * char_alloc - function to alloc chars
 * @s: array
 * @size: size
 * @message: error message
 * Return: char on sucess
 *
 */

char *char_alloc(char **s, size_t size, char *message)
{
	*s = (char *)malloc(sizeof(char) * size);
	if (s == NULL)
	{
		perror(message);
		return (NULL);
	}

	return (*s);
}
/**
 * arr_copy - copy array
 * @dest: destintation array
 * @src: source
 * Return: 0 on success
 */

int arr_copy(char **dest, char **src)
{
	size_t env_ind, free_env_ind;

	for (env_ind = 0; src[env_ind]; env_ind++)
	{
		dest[env_ind] = malloc(sizeof(char) * strlen(src[env_ind]));
		if (dest[env_ind] == NULL)
		{
			perror("_setenv() Error: new_environ malloc failed");
			for (free_env_ind = 0; free_env_ind < env_ind; free_env_ind++)
			{
				free(dest[free_env_ind]);
			}
			free(dest);
			return (-1);
		}
		strcpy(dest[env_ind], src[env_ind]);
	}

	return (0);
}

/**
 * name_env_found - function to find en
 * @n: env string
 * Return: index of the env
 *
 */

int name_env_found(const char *n)
{
	int env_ind, found = -1;

	for (env_ind = 0; __environ[env_ind]; env_ind++)
	{
		if (strncmp(__environ[env_ind], n, strlen(n)) == 0)
		{
			found = env_ind;
		}
	}

	return (found);
}

/**
 * strlen_env - length of env
 * Return: lenght of the env
 *
 */

int strlen_env(void)
{
	unsigned int env_len;

	for (env_len = 0; __environ[env_len]; env_len++)
	{
		;
	}

	return (env_len);
}
