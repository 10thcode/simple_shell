#include "main.h"

/**
 * _addnodeend - Add a new environment variable to the list of environment
 * variables.
 *
 * @head: The head node in the list.
 * @name: The name for the environment variable to be added as the tail
 * @value: The value for the environment variable to be added
 *
 * Return: The address to the newly added node at the end of the list
*/
env_node_t *_addnodeend(env_node_t **head, char *name, char *value)
{
	env_node_t *tail, *current;

	tail = malloc(sizeof(env_node_t));
	tail->name = name;
	tail->value = value;
	tail->next = NULL;

	if (*head == NULL)
	{
		*head = tail;
		return (tail);
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tail;
	return (tail);
}

