#include <stdio.h>

/**
 * main - prints numbers in base 16 lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
		putchar(n + '0');

	for (n = 0; n < 6; n++)
		putchar(n + 'a');

	putchar('\n');

	return (0);
}
