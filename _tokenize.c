#include "main.h"

/**
 * _tokenize - Create an array of tokens from @str
 * using @delimiter as the delimiting character
 *
 * @str: The command to be executed including command line arguments if any
 * @delimiter: The delimiting character(s)
 *
 * Return: An array of tokens
*/
char **_tokenize(char *str, char *delimiter)
{
	char **tokens = NULL;
	int token_count = 0, token_found = 0;
	char *token = NULL;
	int strlen = 0;

	strlen = _strlen(str);
	token = malloc(sizeof(char) * strlen);
	_strcpy(token, str);
	token_count = _tokencount(token, delimiter);
	_freestr(token);
	tokens = malloc(sizeof(char *) * (token_count + 1));
	str = strtok(str, delimiter);
	while (str != NULL)
	{
		tokens[token_found++] = str;
		str = strtok(NULL, delimiter);
	}
	tokens[token_found] = str;
	return (tokens);
}
