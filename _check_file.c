#include "main.h"

/**
 * _checkfile - Check for the exisitence of the file specified at @path
 *
 * @path: The path to the file to be executed
 *
 * Return: VALID_COMMAND if @path is a valid file,
 * NULL_FOUND if @path is NULL otherwise
 * INVALID_COMMAND
*/
int _checkfile(char *path)
{
	if (path == NULL)
	{
		return (NULL_FOUND);
	}
	if (_isexec(path) == IS_EXEC)
	{
		if (access(path, F_OK) == VALID_COMMAND)
		{
			return (VALID_COMMAND);
		}
		return (INVALID_COMMAND);
	}
	if (_isrelpath(path) == IS_REL_PATH)
	{
		return (IS_REL_PATH);
	}
	if (access(path, F_OK) == VALID_COMMAND)
	{
		return (VALID_COMMAND);
	}
	return (INVALID_COMMAND);
}

