#include "main.h"

/**
 * _free - Frees memory allocated to commands to be executed by the shell
 *
 * @commands: The given commands to be executed
*/
void _free(char **commands)
{
	free(commands);
	commands = NULL;
}

