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
	va_list args;

	int i, j, num = 0;
	char *s;
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%' && format[i] != '\0')
		{
			fprintf(stdout, "%c", format[i]);
			num++;
		}

		else if(format[i] == '%' && format[i] != '\0')
		{
			if (format[i + 1] == 's')
			{
				s  = va_arg(args, char *);

				for (j = 0; s[j] != '\0'; j++)
				{
					fprintf(stdout, "%c", s[j]);
					num++;
				}
			}

			if (format[i + 1] == 'c')
			{
				fprintf(stdout, "%c", format[i]);
				num++;
			}
		}
	}

	va_end(args);

	return(num);
}
