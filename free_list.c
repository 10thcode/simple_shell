#include "main.h"

/**
 * free_list - frees a linked list
 *
 * @head: the head node of the list
 */
void free_list(env_node_t *head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		free(head);
		return;
	}
	free_list(head->next);
	free(head);
}
