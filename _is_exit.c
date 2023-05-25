#include "main.h"

/**
 * _isexit - Determine whether the command obtained is the exit command
 *
 * @commands: A pointer to pointers containing commands obtained to be
 * freed
 * @buffer: A pointer to the buffer received after displaying the
 * prompt. This is also to be freed
 * @envpath: A pointer to a pointer of the PATH values
 * @signal_received: The exit code for the last command
 * @env_clone: The address to the temporary environment variable
 * that was created during program startup
*/
void _isexit(char **commands, char *buffer, char **envpath
, int signal_received, char **env_clone)
{
	int index = 0;

	if (commands[0] == NULL)
	{
		return;
	}
	if (EXIT)
	{
		_freestr(buffer);
		_free(commands);
		if (envpath != NULL)
		{
			_freestr(envpath[0]);
		}
		while (env_clone[index] != NULL)
		{
			_freestr(env_clone[index++]);
		}
		_free(env_clone);
		_free(envpath);
		free_list(head);
		exit(signal_received);
	}
}
