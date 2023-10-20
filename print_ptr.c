#include "main.h"

/**
 * print_ptr - prints an hexgecimal number.
 * @arg: arguments.
 * Return: counter.
 */

int print_ptr(va_list arg)
{
	void *p;
	char *s = "(nil)";
	long int a;
	int i;
	int b;

	p = va_arg(arg, void*);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	a = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	b = print_hexa_aux(a);
	return (b + 2);
}
