#include "main.h"

/**
 * tokenise - parses and creates array.
 * @buffer: buffer to be tokenised.
 *
 * Return: Array result.
 */

char **tokenise(char *buffer)
{
	char * token;
	char * delim = " ";
	char **array = NULL;
	int i = 0;
	
	if (buffer == NULL)
		return (NULL);

	token = strtok(buffer, delim);

	while (token != NULL)
	{
		array[i++] = token;
		token = strtok(NULL, delim);
	}
	/* array[i] = NULL; */
	return (array);
}
