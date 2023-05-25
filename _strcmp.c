#include "main.h"

/**
 * _strcmp - compares two strings.
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: negative number if s1 < s2,
 * positive number if s1 > s2
 * and 0 if s1 is equal to s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] || s2[i]; i++)
	{
		if (s1[i] != s2[i])
		break;
	}
	return (s1[i] - s2[i]);
}
