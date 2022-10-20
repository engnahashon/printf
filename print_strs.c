#include "main.h"
/**
 * print_c - prints a char
 * @c: char to print
 *
 * Return: always 1
 */
int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);
	_putchar(ch);
	return (1);
}
/**
 
 * print_s - prints a string
 
 * @s: string to print
 
 *
 
 * Return: number of chars printed
 
 */
int print_s(va_list s)
{

	int n;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (n = 0; str[n]; n++)
		_putchar(str[n]);
	return (n);
}

