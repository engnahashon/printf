#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

void _putchar(char c);
int _printf(const char *format, ...);
static int (*specifier_check(const char *format))(va_list);
int print_c(va_list c);
int print_s(va_list s);

#endif
