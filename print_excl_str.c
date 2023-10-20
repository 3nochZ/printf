#include "main.h"

/**
 * print_excl_str; prints exclusive string
 * @arg: argument
 * Return: strlen
 */

int print_excl_str(va_list arg)
{
	char *s;
	int i, len = 0, cast;

	s = va_arg(arg, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}

			len += print_HEXA_aux(cast);
		}

		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}
