#include "main.h"

/**
 * print_int - Prints an integer (handles INT_MIN)
 * @args: List of arguments
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int num;
	int div = 1, count = 0;
	char c;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = (unsigned int)(-n);
	}
	else
	{
		num = n;
	}

	while (num / div > 9)
		div *= 10;

	while (div > 0)
	{
		c = (num / div) + '0';
		count += write(1, &c, 1);
		num %= div;
		div /= 10;
	}

	return (count);
}

