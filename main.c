#include "main.h"

void handle_sigint(int signum);

int signal_received = 0;
env_node_t *head = NULL;

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
	int commands_executed = 0;
	int exit_code = NULL_FOUND, file_info = VALID_COMMAND;

	signal(SIGINT, handle_sigint);
	env_clone = _getenvs(env);
	_setenv(SHLVL_NAME, SHLVL_VAL, IGNORE);
	envpath = _loadpaths(head);
	for (; ;)
	{
		commands_executed++;
		exit_code = NULL_FOUND;
		if (_prompt(&buffer, &bytes_read) == EOF)
			return (_exitshell(envpath, env_clone, buffer));
		commands = _tokenize(buffer, " \t\r\n");
		_isexit(commands, buffer, envpath, signal_received, env_clone);
		if (_checkenv(commands[0]) == EXIT_SUCCESS)
		{
			_free(commands);
			continue;
		}
		file_info = _checkfile(commands[0]);
		_relpath(&file_info, envpath, commands, buffer, &exit_code);
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
