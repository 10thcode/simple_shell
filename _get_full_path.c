#include "main.h"

/**
 * _getfullpath - Obtain the full PATH to @command
 *
 * @path: A path in the PATH environment variable
 * @command: The given command to be executed
 *
 * Return: The full path to @command
*/
char *_getfullpath(char *path, char *command)
{
	return (_pathbuilder(3, path, "/", command));
}
