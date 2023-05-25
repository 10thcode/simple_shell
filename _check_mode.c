#include "main.h"

/**
 * _checkmode - Determine whether the shell is running
 * in the interactive or the non-interactive mode
 *
 * Return: INTERACTIVE_MODE if the user is in the interactive
 * mode otherwise NON_INTERACTIVE_MODE
*/
int _checkmode(void)
{
	int mode;

	mode = isatty(STDIN_FILENO);
	if (mode == 1)
	{
		return (INTERACTIVE_MODE);
	}
	return (NON_INTERACTIVE_MODE);
}
