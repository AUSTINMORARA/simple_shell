#include "main.h"

/**
 * main - tests the tokensation function.
 *
 * Return: 0 on Success.
 */

char **tokenise(char *buffer);

int main(void)
{
	char *buffer = "This is just on of those days.";
	int i;
	char *array[240];

	array = tokenise(buffer);

	for (i = 0;array != NULL;i++)
	{
		printf("%s\n", array[i]);
	}
	return (0);
}
