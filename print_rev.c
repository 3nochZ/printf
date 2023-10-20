#include "main.h"

/**
 * print_rev - prints a str in reverse
 * @arg: type struct va_arg where is allocated printf arguments
 * Return: the string
 */

int print_rev(va_list arg)
{
	char *s = va_arg(arg, char*);
	int i, j = 0;

	if (s == NULL)
		s = "(null)";
	while (s[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(s[i]);
	return (j);
}
