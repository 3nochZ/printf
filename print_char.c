#include "main.h"

/**
 * print_char - prints char
 * @arg: arguments
 * Return: 1
 */

int print_char(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	_putchar(c);
	return (1);
}
