#include "main.h"

/**
 * execution - does the execution.
 * @array: tokenised command.
 */

void execution(char **array, char *buffer)
{
	int status;
	char *envp[] = {NULL};
	pid_t child;

	child = fork();

	if (child != 0)
	{
		wait(&status);
	}
	else
	{
		if (strncmp(array[0], "./", 2) != 0 && strncmp(array[0], "/", 1))
			path(&array[0]);

		if (execve(array[0], array, envp) == -1)
		{
			perror("Execve error!!");
			free(array);
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}
}
