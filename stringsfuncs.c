/**
 * _strlen - length of a string
 * @c: string whose length we are checking.
 * Return: Number of characters in a string.
 */

int _strlen(char *c)
{
	int i;

	for (i = 0; c[i] != '\0'; i++)
		c++;

	return (i);
}
/**
 * _strcat - appends source string to the destination string
 * @source: string 1
 * @dest: string 2
 *
 * Return: pointer to concatenated string.
 */

char *_strcat(char *dest, char *source)
{
	int dest_len = 0, source_len = 0;

	for (; dest[dest_len] != '\0'; dest_len++)
		;

	for (; source[source_len] != '\0' ;)
		dest[dest_len++] = source[source_len++];

	dest[dest_len] = '\0';

	return (dest);
}
