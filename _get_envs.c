#include "main.h"

/**
 * _getenvs - Get the environment variables as a list
 *
 * @env: A pointer to the system's environment variable
 *
 * Return: The memory address to a copy of the environment variables
*/
char **_getenvs(char **env)
{
	int index = 0, variables_count = 0;
	char *name = NULL, *value = NULL;
	char **env_clone = NULL;

	while (env[variables_count] != NULL)
	{
		variables_count++;
	}
	env_clone = malloc(sizeof(char *) * (variables_count + 1));
	while (env[index] != NULL)
	{
		env_clone[index] = _strdup(env[index]);
		index++;
	}
	env_clone[index] = NULL;
	index = 0;
	while (env_clone[index] != NULL)
	{
		name = strtok(env_clone[index], "=");
		value = strtok(NULL, "\n");
		_addnodeend(&head, name, value);
		index++;
	}
	index = 0;
	return (env_clone);
}

