#include "main.h"

/**
 * _checkenv - Check whether the prompt accepted is the env command and display
 * the environment variables
 *
 * @command: The prompt accepted from the user
 *
 * Return: EXIT_SUCCESS when @command is indeed env otherwise
 * EXIT_FAILURE
*/
int _checkenv(char *command)
{
	char env[] = "env";
	int index = 0;

	if (command == NULL)
	{
		return (EXIT_FAILURE);
	}
	while (env[index] != '\0')
	{
		if (command[index] != env[index])
		{
			return (EXIT_FAILURE);
		}
		index++;
	}
	if (command[index] != '\0')
	{
		return (EXIT_FAILURE);
	}
	_printenv();
	signal_received = EXIT_SUCCESS;
	return (EXIT_SUCCESS);
}

