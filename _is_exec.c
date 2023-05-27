#include "main.h"

/**
 * _isexec - Determines if @path is a path to
 * an executable
 *
 * @path: The path to the file to be executed
 *
 * Return: IS_EXEC if @path is a path to an executable
 * otherwise IS_REL_PATH
*/
int _isexec(char *path)
{
	char first_character;

	first_character = path[0];
	if (first_character == '.')
	{
		return (IS_EXEC);
	}
	return (IS_REL_PATH);
}

