#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: accepted bytes
 * Return: number of bytes in the initial segment
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i;

	while (s[count] != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (s[count] == accept[i])
				break;
		}

		if (accept[i] == '\0')
			break;

		count++;
	}

	return (count);
}
