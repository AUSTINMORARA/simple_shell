#include "main.h"
#define MAX 240

/**
 * main - entry point, a command line interface.
 *
 * Retur`n: Command execution on success, error on failure.
 */

int main(void)
{
	char *token;
	ssize_t reading;
	char **array;
	char *buffer = NULL;
	size_t len;
	int i, status;
	pid_t process;

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
		process = fork();
		if (process == -1)
		{
			perror("Error: Fork failed!");
			exit(EXIT_FAILURE);
		}
		else if (process == 0)
		{
			char *envp[] = {NULL};

			execve(array[0], array, envp);
			perror("Error: command does not exist");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(process, &status, 0);
		}

	}
	free(buffer);
	return (0);
}
