#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - function return number of string
 * @format: string
 *
 * Return: num
 */

int _printf(const char *format, ...)
{
	va_list valist;
	int i, j, length = 0;
	char *str;

	if (!format || (format[0] == '%' && format[1] == '\0') ||
	    format == NULL || format == 0)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 's'
		|| format[i + 1] == 'c' || format[i + 1] == 'd'
		|| format[i + 1] == 'i'))
		{
			if (format[i + 1] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				for (j = 0; str[j]; j++)
				{
					fprintf(stdout, "%c", str[j]);
					length++;
				}
				length -= 1;
			}
			if (format[i + 1] == 'c')
				fprintf(stdout, "%c", va_arg(args, int));
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				int num = va_arg(args, int);
				fprintf(stdout, "%d", num);
				if (num == 0)
					return (1);
				if (num < 0)
				{
					num *= (-1);
					num ++;
				}
				while (num > 0 || num < 0)
				{
					num = num / 10;
					length++;
				}
				length -= 1;
			}
			if (format[i + 1] == '%')
				fprintf(stdout, "%%"):
			i += 1;
		}
		else
			fprintf(stdout, "%c", format[i]);
		length++;
	}
	va_end(args);
	return (length);
}
