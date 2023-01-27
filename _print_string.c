#include "main.h"

int _print_string(char *s)
{
	int m = 0;
	while (s[m] != '\0')
	{
		_putchar(s[m]);
		m++;
	}
	return (0);

}
