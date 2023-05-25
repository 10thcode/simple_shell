#include "main.h"

/**
 * _findnode - Locate the node with the name @name from the list of
 * environment variables
 *
 * @head: The head node in the list of environment variables
 * @name: The name for the variable searched for
 *
 * Return: The node with the name value same as @name
*/
env_node_t *_findnode(env_node_t *head, char *name)
{
	env_node_t *current = NULL;

	current = head;
	while (current->next != NULL)
	{
		if (_strcmp(current->name, name) == EQUAL_STRING)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

