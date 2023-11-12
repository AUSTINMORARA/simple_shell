#include "main.h"

/**
 * main - entry point, program to pass betty.
 *
 * Return: 0 on success.
 */

int main(void)
{
	char *language = "C programming";

	if (language != NULL)
	{
	printf("Welcome to %s, the memory language.\n", language);
	}
	else
	{
		printf("Space not allocated.\n");
	}
	return (0);
}
