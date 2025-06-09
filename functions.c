#include "main.h"

/**
 * print_char - Prints a character
 * @args: List of arguments
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		write(1, &str[i++], 1);

	return (i);
}

/**
 * print_percent - Prints a percent sign
 * Return: Number of characters printed
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}

