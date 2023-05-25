#include "main.h"

/**
 * _putchar - writes the character c to stdout
 *
 * @character: The character to print
 * @file_descriptor: The file descriptor to be used when writing bytes
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char character, int file_descriptor)
{
	return (write(file_descriptor, &character, 1));
}

