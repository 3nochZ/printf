#include "main.h"

/**
 * print_rot13 - printf str to ROT13 place into buffer
 * @arg: type struct va_arg where is allocated printf arguments
 * Return: count
 */

int print_rot13(va_list arg)
{
	int i, j, count = 0, k = 0;
	char *s = va_arg(arg, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		k = 0;
		for (j = 0; alpha[j] && !k; j++)
		{
			if (s[i] == alpha[j])
			{
				_putchar(beta[j]);
				count++;
				k = 1;
			}
		}

		if (!k)
		{
			_putchar(s[i]);
			count++;
		}
	}
	return (count);
}
