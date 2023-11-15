#include "main.h"

/**
 * tokenise - parses and creates array.
 * @buffer: buffer to be tokenised.
 *
 * Return: Array result.
 */

char **tokenise(char *buffer)
{
	char *token;
	char *delim = " ";
	char **array;
	int i;

	if (buffer == NULL)
		return (NULL);

	token = strtok(buffer, delim);

	if (!token)
		return (NULL);

	array = malloc(sizeof(char *) * 1024);

	i = 0;
	while (token != NULL)
	{
		array[i++] = token;
		token = strtok(NULL, delim);
	}
	array[i] = NULL;
	return (array);
}
