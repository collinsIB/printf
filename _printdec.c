#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _format_specifier - function that produces output
 * and handling format specifier d and i
 * @format: character to print
 *
 * Return: 0
 */

int _format_specifier(const char *format, ...)
{
	int i;
	va_list args;
	int count = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);

						count += printInteger(num);
						break;
					}
				default:
					{
						_putchar('%');
						_putchar(format[i]);
						count += 2;
						break;
					}
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}

/**
 * printInteger - main function
 * @num: integer
 *
 * Return: 0
 */

int printInteger(int num)
{
	int count = 0;
	int divisor = 1;

	if (num < 0)
	{
		_putchar('-');
		count++;

		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		return (count + 1);
	}

	while (num / divisor > 9)
		divisor *= 10;

	while (divisor > 0)
	{
		int digit = num / divisor;

		_putchar(digit + '0');
		count++;
		num %= divisor;
		divisor /= 10;
	}

	return (count);
}
