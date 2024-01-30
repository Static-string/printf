#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
* print_char - Helper function to print a character.
* @c: Character to print.
* @output_count: Current count of characters printed.
*
* Return: Updated count of characters printed.
*/
static int print_char(char c, int output_count)
{
return (output_count + write(1, &c, 1));
}

/**
* print_str - Helper function to print a string.
* @str: String to print.
* @output_count: Current count of characters printed.
*
* Return: Updated count of characters printed.
*/
static int print_str(char *str, int output_count)
{
size_t str_len = strlen(str);
return (output_count + write(1, str, str_len));
}

/**
* _printf - printf function that prints to the standard output.
* @format_string: String that specifies the format of the output.
*
* Return: Return the count or number of characters printed excluding null byte.
*/
int _printf(const char *format_string, ...)
{
va_list fmt_args;
int output_count = 0;
const char *fmt_ptr;

va_start(fmt_args, format_string);
fmt_ptr = format_string;

while (*fmt_ptr != '\0')
{
if (*fmt_ptr == '%')
{
fmt_ptr++;

if (*fmt_ptr == 'c')
output_count = print_char(va_arg(fmt_args, int), output_count);
else if (*fmt_ptr == 's')
output_count = print_str(va_arg(fmt_args, char *), output_count);
else if (*fmt_ptr == '%')
output_count = print_char('%', output_count);
else
{
/* Handle unknown conversion specifier */
write(2, "Unknown conversion specifier\n", 29);
}
}
else
{
output_count = print_char(*fmt_ptr, output_count);
}

fmt_ptr++;
}

va_end(fmt_args);

return (output_count);
}
