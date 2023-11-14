#include "shell.h"

/**
 * num_tokens - function to find the number of tokens
 * @arg: arg
 * @dels: dels
 * Return: count
 */

size_t num_tokens(char *arg, char *dels)
{
	char *token;
	size_t count = 0;

	token = strtok(arg, dels);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, dels);
	}

	return (count);
}

/**
 * make_arr - function to make array
 * @arg: argument
 * @dels: spaces
 * Return: array of arguments
 *
 */

char **make_arr(char *arg, char *dels)
{
	char **arr;
	char *copy, *token;
	size_t count, index, free_place;

	arr = NULL;
	char_alloc(&copy, strlen(arg) + 1, "Error: malloc failure");
	strcpy(copy, arg);
	count = num_tokens(copy, dels);
	arr = arr_alloc(arr, count + 1, "Error: malloc failure");
	strcpy(copy, arg);

	token = strtok(copy, dels);

	for (index = 0; index < count; index++)
	{
		arr[index] = (char *)malloc(sizeof(char) * strlen(token) + 1);
		if (arr[index] == NULL)
		{
			for (free_place = 0; free_place < index; free_place++)
			{
				free(arr[free_place]);
			}
			free(copy);
			free(arr);
			perror("Error: malloc failure");
			return (NULL);
		}

		strcpy(arr[index], token);
		token = strtok(NULL, dels);
	}

	free(copy);
	arr[index] = NULL;
	return (arr);
}
