int _printf(const char *format, ...)
{
	int i, x;

	for (i = 0; format[i] != '\0'; i++)
	{
		x += 1;
	}

	return (x);
}
