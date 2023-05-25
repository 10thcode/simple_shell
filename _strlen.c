#include "main.h"

/**
 * _strlen - Return the length for given string including the
 * NULL terminating character.
 *
 * @str: The given string
 *
 * Return: The size for the given string
 **/
int _strlen(char *str)
{
	int total_characters = 0;

	while (str[total_characters] != '\0')
	{
		total_characters++;
	}
	return (total_characters + 1);
}

