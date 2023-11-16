#include "main.h"

/**
 * main - entry point, a command line interface.
 *
 * Return: Command execution on success, error on failure.
 */

int main(void)
{
	ssize_t reading;
	char **array;
	char *buffer = NULL;
	size_t len;

	while (1)
	{
		printf("$ ");
		reading = getline(&buffer, &len, stdin);

		if (reading == -1)
		{
			perror("Error: Getline failed");
		}
		if (buffer[reading - 1] == '\n')
			buffer[reading - 1] = '\0';

		array = tokenise(buffer);

		if (array == NULL)
		{
			perror("Tokenisation failed");
			exit(EXIT_FAILURE);
		}
		execution(array, buffer);

	}
	return (0);
}
