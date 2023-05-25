#include "main.h"

/**
 * _tokencount - Counts the number of tokens in the given command
 *
 * @str: The command to be executed including command line arguments if any
 * @delimiter: The delimiting character(s)
 *
 * Return: The number of tokens found in the given command
*/
int _tokencount(char *str, char *delimiter)
{
	int token_count = 0, length = 0;
	char *token = NULL, *tmp = NULL;

	length = _strlen(str);
	tmp = malloc(sizeof(char) * length);
	_strcpy(tmp, str);
	token = strtok(tmp, delimiter);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delimiter);
	}
	_freestr(tmp);
	return (token_count);
}

