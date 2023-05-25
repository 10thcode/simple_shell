#include "main.h"

/**
 * _strstr - Finds the first occurence of the substring
 * @needle in @haystack.
 *
 * @haystack: The string to be searched
 * @needle: The string to search for
 *
 * Return: A pointer to the memory address
 * which begins the located substring or NULL.
 *
 **/
const char *_strstr(const char *haystack, const char *needle)
{
	int count = 0, j = 0, ii = 0, s = 0;

	if (needle[ii] == '\0')
	{
		return (&haystack[ii]);
	}
	for ( ; needle[s]; s++)
	{
	}
	for ( ; needle[ii]; ii++)
	{
		j = ii;
		for ( ; haystack[j]; j++)
		{
			if (needle[ii] == haystack[j])
			{
				count++;
				j++;
				break;
			}
		}
	}
	if (count == s)
	{
		return (&haystack[j - s]);
	}
	return (NULL);
}

