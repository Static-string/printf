#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 *_printf - A function that works as the default printf program in c
 *@format: the character supplied
 * Return: void.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	size_t m;
	char *str = NULL;
	int n_displayed = 0;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
		_putchar(format[i]);
		n_displayed++;
		}
		else
		{
			if (format[i + 1] == 'c')
			{
				_print_character(va_arg(args, int));
				i++;
				n_displayed++;
			}
			else if (format[i + 1] == 's')
			{
				i++;
				str = va_arg(args, char *);
				_print_string(str);
				n_displayed++;
			}
			else if (format[i + 1] == '%')
			{
				i++;
				_print_character('%');
				n_displayed++;
			}
		}

		i++;
	}

	va_end(args);
	return (n_displayed);
}
