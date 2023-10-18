#include "main.h"

/**
 * print_binary - prints binary number
 * @arg: arguments
 * Return: 1
 */

int print_binary(va_list arg)
{
	int count = 0;
	int flag = 0;
	int i;
	int a = 1, b;
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			count++;
		}
	}

	if(count == 0)
	{
		count++;
		_putchar('0');
	}

	return (count);
}
