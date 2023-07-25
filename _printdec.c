#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - function that produces output
 * and handling format specifier d and i
 * @format: character to print
 *
 * Return: 0
 */

int _printf(const char *format, ...)
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

						count += printf("%d", num);
						break;
					}
				default:
					break;
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
 * main - main function
 *
 * Return: 0
 */

int _print_main(void)
{
	_printf("the number is: %d\n", 42);
	return (0);
}
