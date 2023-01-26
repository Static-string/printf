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
	int n_displayed = 0;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
		_putchar(format[i]);
		}
		else
		{
			if (format[i + 1] == 'c')
			{
				_putchar(va_arg(args, int));
				i++;
			}
		}

		i++;
		n_displayed += 1;
	}

	va_end(args);
	return (n_displayed);
}
