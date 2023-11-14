#include "shell.h"

/**
 * reverse_string - function to
 * @str: string
 * Return: void
 *
 *
 */

void reverse_string(char *str)
{
	int i, len = 0;
	char tmp;

	while (str[len] != '\0')
	{
		len++;
	}
	len -= 1;

	for (i = 0; i < len; i++, len--)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
}

/**
 * atoi_reverse - function
 * @num: num
 * Return: reversed number string
 */

char *atoi_reverse(size_t num)
{
	char *string = malloc(sizeof(char) * (32 + 1));
	int i = 0;

	while (num > 0)
	{
		string[i++] = num % 10 + '0';
		num /= 10;
	}
	string[i] = '\0';
	reverse_string(string);

	return (string);
}
