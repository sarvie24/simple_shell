#include "shell.h"

/**
 * counter - function to count
 * @num_comm: number
 * Return: count
 *
 */

int counter(size_t num_comm)
{
	int count = 0;

	if (num_comm == 0)
		return (1);
	while (num_comm != 0)
	{
		num_comm /= 10;
		count++;
	}

	return (count);
}
