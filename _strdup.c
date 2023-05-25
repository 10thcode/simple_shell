#include "main.h"

/**
 * _strdup - Creates a duplicate for the given string
 *
 * @str: The string to duplicate
 *
 * Return: A memory address to the newly allocated string.
 * Has the same contents @str
*/
char *_strdup(char *str)
{
	char *duplicate = NULL;
	int length = 0;

	length = _strlen(str);
	duplicate = malloc(sizeof(char) * length);
	_strcpy(duplicate, str);
	return (duplicate);
}
