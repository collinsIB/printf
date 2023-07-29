#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - handle conversion specifiers
 * @format: string format
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
				case 'u':
					{
						unsigned int n = va_arg(args, unsigned int);

						count += printf("%u", n);
					{
					case 'o':
					{
						unsigned int n = va_arg(args, unsigned int);

						count += printf("%o", n);
						break;

					}
				case 'x':
					{
						unsigned int n = va_arg(args, unsined int);

						count += printf("%x", n);
						break;
					}
				case 'X':
					{
						unasigned int n = va_arg(args, unsigned int);

						count += printf("%X", n);
						break;
					}
			}
		}
	}
	va_end(args);
	return (count);
}
