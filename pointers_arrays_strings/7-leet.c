#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to encode
 * Return: pointer to string
 */

char *leet(char *str)
{
	int i = 0;
	int j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	while (str[i] != '\0')
	{
		j = 0;
		while (j < 10)
		{
			if (str[i] == letters[j])
			{
				str[i] = numbers[j];
				break;
			}
			j++;
		}
		i++;
	}

	return (str);
}
