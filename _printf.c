#include <stdio.h>
#include "main.h"

/**
 * _printf: my own printf
 * @format: identifier
 * Return: strlen
 *
 * Description: function like printf
 */

int _printf(const char  * const format, ...)
{
	convert m[] = {
		{"%s", print_string}, {"%c", print_char},
		{"%%", print_percent}, {"%i", print_int},
		{"%d", print_decimal}, {"%r", print_rev},
		{"%R", print_rot13}, {"%b", print_binary},
		{"%u", print_unsigned}, {"%o", print_octal}, {"%x", print_hexa},
		{"%X", print_HEXA}, {"%S", print_excl_str}, {"%p", print_ptr}, {"NULL", print_null}
	};

	va_list args;
	int i = 0, len = 0;
	int j;

	va_start(args, format);
	if ((format[0] == '%' && format[1] == '\0') || format == NULL)
		return (-1);

Code:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Code;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
