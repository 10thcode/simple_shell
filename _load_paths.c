#include "main.h"

/**
 * _loadpaths - Retrieves the values for the PATH environment variable
 *
 * @head: The head node in the list of environment variables
 *
 * Return: A pointer to a pointer of the PATH values
*/
char **_loadpaths(env_node_t *head)
{
	char **paths = NULL;
	char *var_name = NULL, *var_value = NULL;
	env_node_t *current = NULL;
	int length = 0;

	current = head;
	while (current != NULL)
	{
		var_name = current->name;
		if (_isenvvarpath(var_name) == IS_PATH)
		{
			length = _strlen(current->value);
			var_value = malloc(sizeof(char) * length);
			_strcpy(var_value, current->value);
			break;
		}
		current = current->next;
	}
	if (var_value != NULL)
	{
		paths = _tokenize(var_value, ":");
	}
	return (paths);
}
