#include "main.h"

/**
 * print_char - prints char
 * @arg: arguments
 * Return: 1
 */

int print_char(va_list arg)
{
	char s;

	s = va_arg(arg, int);
	_putchar(s);
	return (1);
}
