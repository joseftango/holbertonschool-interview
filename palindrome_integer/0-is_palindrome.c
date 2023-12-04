#include "palindrome.h"

/**
 * is_palindrome - checks whether an unsigned integer is a palindrome
 * @n: given integer
 * Return: 1 or 0
**/

int is_palindrome(unsigned long n)
{
	unsigned long int reversed = 0, remainder, original = n;

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	if (original == reversed)
	return (1);

	return (0);
}
