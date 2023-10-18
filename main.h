#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct format - match conversion specifiers
 * @id: type char pointer for the specifier
 * @f: type pointer to function
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert;

int print_%();
int print_HEXA(va_list arg);
int print_char(va_list arg);

int print_ptr(va_list arg);
int print_HEXA_aux(unsigned int num);
int print_excl_str(va_list arg);
int print_HEXA(va_list arg);
int print_octal(va_list arg);
int print_unsigned(va_list arg);
int print_binary(va_list arg);
int print_rev(va_list arg);
int print_rot13(va_list arg);
int print_int(va_list arg);
int print_decimal(va_list arg);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int print_char(va_list argl);
int print_string(va_list arg);
int _putchar(char c);
int _printf(const char *format, ...);


#endif
