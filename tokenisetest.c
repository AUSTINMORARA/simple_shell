#include "main.h"

/**
 * main - testing tokenise.
 *
 * Return: 0 on success.
 */

int main()
{
	char **array;
	ssize_t line;
	size_t len;
	char *buffer;
	int i = 0;

	while(1)
	{
		printf("& ");
		line = getline(&buffer, &len, stdin);

		if (line > 0)
		{
			array = tokenise(buffer);
			if (array == NULL)
			{
				perror("Tokenise returned NULL.\n");
				return (EXIT_FAILURE);
			}
			else
			{
				printf("%s\n", array[i++]);
			}
		}
	}
	free(array);
	return (0);
}
