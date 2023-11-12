#include "main.h"

/**
 * main - entry point, a command line interface.
 *
 * Return: Command execution on success, error on failure.
 */

int main()
{
	char *argv[1024];
	char *token, *delim, *buffer = NULL;
	size_t len;
	int i, read, ex, waiting, status;
	pid_t process;

	while(1)
	{
		printf("$ ");
		read = getline(&buffer, &len, stdin);
		printf("Going great\n");
		
		if (read == -1)
		{
                        perror("Error: Getline failed");
			continue;
                }
		else
		{
			if (buffer[read - 1] == '\n')
				buffer[read - 1] = '\0';
			
			process = fork();
			if (process == -1)
                        {
                                perror("Error: Fork failed!");
                        }
			else if (process == 0)
			{
				ex = execve(argv[0], argv, NULL);
				if (ex == -1)
				{
					perror("Error: command does not exist");
					exit(1);
				}
				else
				{
					printf("Function working");
				}
			}
			else if (process > 0)
			{
				waiting = wait(&status);
				if (waiting == -1)
					printf("Error:Wait failed");
			}
		}
	}
		free(buffer);
	}
	return (0);

}
