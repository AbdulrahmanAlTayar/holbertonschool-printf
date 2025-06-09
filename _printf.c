#include "main.h"

/**
 * handle_specifier - Handles a format specifier
 * @format: The format string
 * @args: The argument list
 * @i: Current index in format
 * Return: Number of characters printed
 */
int handle_specifier(const char *format, va_list args, int *i)
{
	int count = 0;

	switch (format[*i])
	{
	case 'c':
		count += print_char(args);
		break;
	case 's':
		count += print_string(args);
		break;
	case '%':
		count += print_percent();
		break;
	default:
		write(1, "%", 1);
		write(1, &format[*i], 1);
		count += 2;
	}
	return (count);
}

/**
 * _printf - Produces output according to a format
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			count += handle_specifier(format, args, &i);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

