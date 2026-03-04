#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string input
 *
 * Return: converted integer, or 0 if no digits found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int num = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (started)
		{
			break;
		}

		i++;
	}

	if (!started)
		return (0);

	return ((int)(num * sign));
}
