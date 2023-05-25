#include "main.h"

/**
 * _relpath - Checks wehther @commands contains a relative path
 * to the command to be executed
 *
 * @file_info: A value iindicating whether the command received
 * is a relative command. IS_REL_PATH is the value when a
 * relative command is accepted
 * @envpath: A pointer to the PATH variables
 * @commands: A pointer to string containing the command
 * to be executed with options (if provided)
 * @buffer: The input accepted from the user. This is used
 * to form the full path to the command to execute
 * @exit_code: A pointer to the exit status of the shell
 */
void _relpath(int *file_info, char **envpath, char **commands
		, char *buffer, int *exit_code)
{
	int envpath_index = 0;

	if (*file_info == IS_REL_PATH)
	{
		while (envpath != NULL &&
		envpath[envpath_index] != NULL)
		{
			*exit_code = NULL_FOUND;
			commands[0] = _getfullpath(envpath[envpath_index],
					strtok(buffer, " \t\r\n"));
			if (_checkfile(commands[0]) == VALID_COMMAND)
			{
				*exit_code = EXIT_SUCCESS;
				break;
			}
			*exit_code = CTRL_C_SIGNAL_CODE;
			envpath_index++;
			_freestr(commands[0]);
		}
	}
}
