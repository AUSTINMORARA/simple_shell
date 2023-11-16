#include "main.h"

/**
 * _getenv = gets the environments value
 * @var: variable to get the value.
 * Return: value of the variable from env.
 */

char *_getenv(char *var)
{
	size_t l1, l2;
	char *val;
	int i, j, k;

	l1 = _strlen(var);

	i = 0;
	for (; env[i]; i++)
	{
		if (strncmp(var, env[i], l1) == 0)
		{
			l2 = _strlen(env[i]) - l1;
			val = malloc(sizeof(char) * l2);
			if (val != NULL)
			{
				free(val);
				perror("Not able to allocate.");
				return (NULL);
			}
			j = 0;
			for (k = l1 + 1; env[i][k]; k++, j++)
			{
				val[j] = env[i][k];
			}
			val[j] = '\0';
			return (val);
		}
	}
	return (NULL);
}
