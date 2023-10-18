#include <stdio.h>
#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
#include <stdio.h>
#include <stdarg.h>

int handle_print(const char *format, int *index, va_list list, char buffer[], int flags, int width, int precision, int size)
{
    char ch;
    char *str;
    int num;

    switch (format[*index])
    {
        case 'c':
            ch = (char)va_arg(list, int);
            buffer[0] = ch;
            return 1;

        case 's':
            str = va_arg(list, char *);
            {
                int len = 0;
                while (*str != '\0') {
                    buffer[len++] = *str++;
                }
                return len;
            }

        case 'd':
            num = va_arg(list, int);
            {
                char temp[20]; // Assuming a maximum of 20 digits
                int len = 0;
                if (num < 0) {
                    buffer[0] = '-';
                    num = -num;
                    len++;
                }
                do {
                    temp[len++] = (num % 10) + '0';
                    num /= 10;
                } while (num > 0);
                for (int i = len - 1, j = 0; i >= 0; i--, j++) {
                    buffer[j] = temp[i];
                }
                return len;
            }

        case 'f':
            /* Handle floating-point numbers */
            // Example: num = va_arg(list, double);
            // Implement your own logic to convert and store the floating-point number in the buffer
            break;

        /* Handle other format specifiers as needed */

        default:
            /* Unsupported format specifier */
            break;
    }

    return -1;  // Error: Unsupported format specifier
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

int main()
{
	_printf("Let's print a simple sentence.\n");
	_printf("%c", 'S');
	_printf("A char inside a sentence: %c. Did it work?\n", 'F');
	_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	_printf("%s", "This sentence is retrieved from va_args!\n");
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	_printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	_printf("%%");
	_printf("Should print a single percent sign: %%\n");
	_printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	_printf("css%ccs%scscscs", 'T', "Test");
	_printf(NULL);
	_printf("%c", '\0');
	_printf("%");
	_printf("%!\n");
	_printf("%K\n");
}
