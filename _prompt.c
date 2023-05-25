#include "main.h"

/**
 * _prompt - Displays a prompt to the user and accept
 * the command to be executed
 *
 * @buffer: The memory address where the command would be stored
 * @bytes_read: The number of bytes written to @buffer
 *
 * Return: EXIT_SUCCESS if @buffer has a value, EOF if
 * end of file is reached
*/
int _prompt(char **buffer, size_t *bytes_read)
{
	int actual_bytes_read = 0;
	int mode = NON_INTERACTIVE_MODE;

	mode = _checkmode();
	if (mode == INTERACTIVE_MODE)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	actual_bytes_read = getline(buffer, bytes_read, stdin);
	if (actual_bytes_read == EOF)
	{
		if (mode == INTERACTIVE_MODE)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		return (EOF);
	}
	return (EXIT_SUCCESS);
}
