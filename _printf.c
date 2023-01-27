#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/**
 * _printf - function return number of string
 * @format: string
 *
 * Return: x
 */

int _printf(const char *format, ...)
{
	char *s;
	int x = 0, i;

	va_list(args);
	va_start(args, format);

	for (; *format != '\0'; format++)
	{
		while (*format != '%' && *format != '\0')
		{
			putchar(*format);
			x++;
			format++;
		}
		while (*format == '%' && *format != '\0')
		{

		format++;

		switch (*format)
		{
			case 'c':
				  i = va_arg(args, int);
				  putchar(i);
				  x++;
				  break;

			case 's':
				  s = va_arg(args, char *);
				  puts(s);
				  x += strlen(s);
				  break;
		}
		}
	}

	va_end(args);

	return (x);
       }
