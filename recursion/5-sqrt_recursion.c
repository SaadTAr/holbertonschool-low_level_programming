#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find square root
 * Return: square root of n or -1
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 0));
}

/**
 * sqrt_helper - helper function to find sqrt
 * @n: number
 * @i: iterator
 * Return: square root or -1
 */

int sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (sqrt_helper(n, i + 1));
}
