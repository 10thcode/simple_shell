#include "main.h"

 env_node_t *head = NULL;

/**
 * _exit_shell - Clean up memory before exiting shell
 *
 * @envpath: A pointer to the environment PATH variables
 * @env_clone: A pointer to a copy of the users environment variables
 * @buffer: The command accepted from the user
 */
int _exitshell(char **envpath, char **env_clone, char *buffer)
{
	if (envpath != NULL)
	{
		_freestr(envpath[0]);
	}
	while (env_clone[index] != NULL)
	{
		_freestr(env_clone[index++]);
	}
	_free(env_clone);
	_freestr(buffer);
	_free(envpath);
	free_list(head);
	return (signal_received);
}
