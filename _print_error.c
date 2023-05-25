#include "main.h"

/**
 * _printerror - Display an error message to stderr
 *
 * @commands_executed: The number of commands executed from the shell
 * @param_count: The number of arguments to be displayed
*/
void _printerror(int commands_executed, int param_count, ...)
{
	int size = 0, param_found = 0;
	va_list params;
	char *print_message;

	va_start(params, param_count);
	while (param_found < param_count)
	{
		print_message = va_arg(params, char *);
		size = _strlen(print_message) - 1;
		write(STDERR_FILENO, print_message, size);
		if (param_found == 1)
		{
			print_number(commands_executed);
		}
		param_found++;
	}
}
