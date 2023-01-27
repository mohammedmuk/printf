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
	int i, j, num = 0;
	char *s;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 's'
		|| format[i + 1] == 'c' || format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			if (format[i + 1] == 's')
			{
				s = va_arg(args, char *);

				for (j = 0; s[j]; j++)
				{
					fprintf(stdout, "%c", s[j]);
					num++;
				}
			}

			if (format[i + 1] == 'c')
			{
				fprintf(stdout, "%c", va_arg(args, int));
			}
		}

		else
		{
			fprintf(stdout, "%c", format[i]);
			num++;
		}
	}

	va_end(args);

	return (num);
}
