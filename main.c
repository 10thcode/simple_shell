#include "main.h"

/**
 * main - Shell intry point
 *
 * @argc: The number of arguments
 * @argv: The list of arguments given
 * @env: The environment variables received from the
 * users system
 *
 * Return: The appropriate exit code for the shell
*/
int main(int argc __attribute__((unused)), char *argv[], char *env[])
{
	char *buffer = NULL;
	char **commands = NULL,  **envpath = NULL, **env_clone = NULL;
	size_t bytes_read = 0;
	int commands_executed = 0, envpath_index = 0, index = 0;
	int exit_code = NULL_FOUND, file_info = VALID_COMMAND;

	signal(SIGINT, handle_sigint);

	env_clone = _getenvs(env);
	_setenv(SHLVL_NAME, SHLVL_VAL, IGNORE);
	envpath = _loadpaths(head);
	for (; ;)
	{
		commands_executed++;
		envpath_index = 0;
		exit_code = NULL_FOUND;
		if (_prompt(&buffer, &bytes_read) == EOF)
		{
			exit_code = signal_received;
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
			return (exit_code);
		}
		commands = _tokenize(buffer, " \t\r\n");
		_isexit(commands, buffer, envpath, signal_received, env_clone);
		if (_checkenv(commands[0]) == EXIT_SUCCESS)
		{
			_free(commands);
			continue;
		}
		file_info = _checkfile(commands[0]);
		if (file_info == IS_REL_PATH)
		{
			while (envpath != NULL &&
			envpath[envpath_index] != NULL)
			{
				exit_code = NULL_FOUND;
				commands[0] = _getfullpath(
					envpath[envpath_index], strtok(buffer, " \t\r\n"));
				if (_checkfile(commands[0]) == VALID_COMMAND)
				{
					exit_code = EXIT_SUCCESS;
					break;
				}
				exit_code = CTRL_C_SIGNAL_CODE;
				envpath_index++;
				_freestr(commands[0]);
			}
		}
		exit_code = _execute(((exit_code == CTRL_C_SIGNAL_CODE) ?
		&buffer : commands), commands_executed, argv[0], env);
		if (exit_code == EXIT_SUCCESS && file_info == IS_REL_PATH)
		{
			_freestr(commands[0]);
		}
		_free(commands);
	}
	return (exit_code);
}
