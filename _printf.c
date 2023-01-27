#include <stdarg.h>
#include <string.h>

/**
 * _printf - function return number of string
 * @format: string
 *
 * Return: x
 */

int _printf(const char *format, ...)
{
	char *s;
	int x = 0;

	va_list(args);
	va_start(args, format);

	for (*format != '\0'; format++)
	{
		while (*format != '%' && *format != '\0')
		{
			format++;
			x++;
		}
		while (*format == '%' && *format != '\0')
		{

		format++;

		switch (*format)
		{
			case 'c':
				  x++;
				  break;

			case 's':
				  s = va_arg(args, char *);
				  x += strlen(s);
				  break;
		}
	}

	va_end(args);

	return (x);
}
}
