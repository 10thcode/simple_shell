#include "main.h"

/**
 * _strcpy - Copy the string specified as source to the
 * specified destination. Appends the NULL terminating
 * character to @dest
 *
 * @src: The source string
 * @dest: The destination string
 *
 * Return: A pointer to the destination string
 **/
char *_strcpy(char *dest, char *src)
{
	int index_of_src = 0;

	while (src[index_of_src] != '\0')
	{
		dest[index_of_src] = src[index_of_src];
		index_of_src++;
	}
	dest[index_of_src] = '\0';
	return (dest);
}

