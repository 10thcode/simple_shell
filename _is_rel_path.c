#include "main.h"

/**
 * _isrelpath - Determines if @path is a relative
 * path to a command with just the command name
 *
 * @path: The path to the file to be executed
 *
 * Return: IS_ABS_PATH if @path is an absolute file path
 * otherwise IS_REL_PATH
*/
int _isrelpath(char *path)
{
	char first_character;

	first_character = *path;
	if (first_character != '/')
	{
		return (IS_REL_PATH);
	}
	return (IS_ABS_PATH);
}

