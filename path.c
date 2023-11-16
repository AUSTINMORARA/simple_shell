#include "main.h"

/**
 * path - finds the path for the command.
 * @command: the command to find.
 *
 * Return: path to be executed.
 */

void path(char **command)
{
	struct stat st;
	char *path, *cpath;
	char *dir;

	path = getenv("PATH");
	dir = strtok(path, ":");

	while (dir)
	{
		cpath = fullpath(dir, *command);
		if (stat(cpath, &st) == 0)
		{
			*command = strdup(cpath);
			free(cpath);
			break;
		}
		free(cpath);
		dir = strtok(NULL, ":");
	}
	free(path);
}

/**
 * fullpath - created the full path to be executed.
 * dir: path directory.
 * cmd: command found.
 * Return: full command.
 */

char *fullpath(char *dir, char *cmd)
{
	char *c;
	size_t len;

	len = _strlen(cmd) + _strlen(dir) + 2;
	c = malloc(sizeof(char) * len);
	
	if (c == NULL)
		return (NULL);

	memset(c, 0, len);

	c = _strcat(c, dir);
	c = _strcat(c, "/");
	c = _strcat(c, cmd);
	return (c);
}
