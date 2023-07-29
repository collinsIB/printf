#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function that handles the conversion specifiers
 * @format: the string format
 *
 * Return: 0
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'd':
				case 'i':
					{
						int n = va_arg(args, int);

						count += printf("%d", n);
						break;
					}
			}
		}
	}
	va_end(args);
	return (count);
}
