#include <stdio.h>
#include <stdarg.h>

extern int handle_print(const char *format, int *index, va_list list, char buffer[], int flags, int width, int precision, int size)
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
