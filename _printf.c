#include "main.h"
/**
  * specifier_check - check specifier
  * @format: format specifier
  *
  * Return: pointer to function
  */
static int (*specifier_check(const char *format))(va_list)
{
		unsigned int i;

		print_t p[] = {
			{"c", print_c},
			{"s", print_s},
			{"i", print_i},
			{"d", print_d},
		/*
		*	{"u", print_u},
		*	{"b", print_b},
		*	{"o", print_o},
		*	{"x", print_x},
		*	{"X", print_X},
		*	{"p", print_p},
		 */
			{"S", print_S},
			{"r", print_r},
		/*
		*	{"R", print_R},
		 */
			{NULL, NULL}
		};
		for (i = 0; p[i].t != NULL; i++)
		{
			if (*(p[i].t) == *format)
				break;
		}
		return (p[i].f);
}
/**
  * _printf - function that produces output according to a format.
  * @format: Character string of type
  *
  * Return: zero
  */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list valist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(valist, format);

	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = specifier_check(&format[i + 1]);
		if (f != NULL)
		{
			count += f(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(valist);
	return (count);
}
