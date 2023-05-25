#include "main.h"

/**
 * _freestr - Frees memory allocated to any string used in the shell that
 * needs to be freed
 *
 * @str: A string that needs to be freed
*/
void _freestr(char *str)
{
	free(str);
	str = NULL;
}
