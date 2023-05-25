#include "main.h"

/**
 * _printenv - Prints the environment variables on the system
*/
void _printenv(void)
{
	int length = 0;
	env_node_t *current = NULL;

	current = head;
	while (current != NULL)
	{
		length = _strlen(current->name);
		write(STDOUT_FILENO, current->name, length);
		write(STDOUT_FILENO, "=", 1);
		if (current->value != NULL)
		{
			length = _strlen(current->value);
		}
		write(STDOUT_FILENO, current->value, length);
		write(STDOUT_FILENO, "\n", 1);
		current = current->next;
	}
}
