#include "main.h"

/**
 * print_number - Display the given integer.
 *
 * @number: The number to be displayed
 **/
void print_number(int number)
{
	int first = number, count = 0, x = 1, i, tmp;

	tmp = number;
	if (number < 0)
	{
		_putchar('-', STDERR_FILENO);
		number = (number * -1) - 1;
	}
	while (first != 0)
	{
		first = first / 10;
		count++;
	}
	while (x <= count)
	{
		first = number;
		i = x;
		while (i < count)
		{
			first = first / 10;
			i++;
		}
		if (tmp < 0 && x == count)
		{
			_putchar(((first % 10) + 48) + 1, STDERR_FILENO);
		}
		else
		{
			_putchar((first % 10) + 48, STDERR_FILENO);
		}
		x++;
	}
	if (count == 0)
	{
		_putchar('0', STDERR_FILENO);
	}
}
