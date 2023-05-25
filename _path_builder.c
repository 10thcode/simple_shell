#include "main.h"

/**
 * _pathbuilder - Appends the given string @str to @src
 * forming a file path
 *
 * @argc: The number of strings to be appended to @src
 *
 * Return: A pointer to a new memory address with the newly combines
 * path
*/
char *_pathbuilder(int argc, ...)
{
	va_list args;
	char *str = NULL, *newstr = NULL;
	int args_found = 0, index = 0, str_index = 0, length = 0;

	va_start(args, argc);
	while (args_found < argc)
	{
		str = va_arg(args, char *);
		length += _strlen(str);
		args_found++;
	}
	va_end(args);
	args_found = 0;
	newstr = malloc(sizeof(char) * length);
	va_start(args, argc);
	while (args_found < argc)
	{
		str = va_arg(args, char *);
		str_index = 0;
		while (str[str_index] != '\0')
		{
			newstr[index++] = str[str_index++];
		}
		args_found++;
	}
	va_end(args);
	newstr[index] = '\0';
	return (newstr);
}
