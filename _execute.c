#include "main.h"

/**
 * _execute - Execute the given command
 *
 * @commands: The given command to be executed along with its
 * arguments (if any)
 * @commands_executed: The number of commands executed from the shell
 * @program: The name for the shell
 * @env: The memory address to the cloned copy of the environment
 * variables
 *
 * Return: The exit code for the child process created.
 * Would also return an appropriate exit code should an error occur
*/
int _execute(char **commands, int commands_executed, char *program, char **env)
{
	char *pathname = NULL;
	int status = 0;
	pid_t pid;
	int file_info = VALID_COMMAND;

	pathname = commands[0];
	file_info = _checkfile(pathname);
	if (file_info == VALID_COMMAND)
	{
		pid = fork();
		if (pid == -1)
		{
			return (errno);
		}
		if (pid == 0)
			{
			signal_received = EXIT_SUCCESS;
			if (execve(pathname, commands, env) == ERROR_OCCURED)
			{
				signal_received = status;
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
		if (WIFEXITED(status))
		{
			signal_received = (WEXITSTATUS(status));
			return (WEXITSTATUS(status));
		}
	}
	else if (file_info == INVALID_COMMAND || file_info == IS_REL_PATH)
	{
		_printerror(commands_executed, 5, program, ": ",
		": ", pathname, ": not found\n");
		signal_received = INVALID_COMMAND;
		return (INVALID_COMMAND);
	}
	return (status);
}

