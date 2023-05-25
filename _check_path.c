#include "main.h"

/**
 * _checkpath - Check whether @command_path is an absolute or
 * relative path to the command to be executed
 *
 * @command_path: The command to be executed. Could be the
 * path to the command or merely the command name
 *
 * Return: VALID_COMMAND when @command_path is a valid absolute
 * path otherwise IS_REL_PATH to signify the command
 * name was accepted
*/
int _checkpath(char *command_path)
{
	return (_checkfile(command_path));
}

