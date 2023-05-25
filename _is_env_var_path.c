#include "main.h"

/**
 * _isenvvarpath - Determine whether @env_variable is the PATH
 * environment variable
 *
 * @env_variable: The given environment variable
 *
 * Return: IS_PATH when @env_variable is a pointer to the PATH
 * environment variable otherwise IS_NOT_PATH
*/
int _isenvvarpath(char *env_variable)
{
	char path[] = "PATH";
	int index = 0;

	while (index < 4)
	{
		if (env_variable[index] != path[index])
		{
			return (IS_NOT_PATH);
		}
		index++;
	}
	return (IS_PATH);
}
