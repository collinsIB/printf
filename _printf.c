#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_char - print character
 * @args: Argument
 * @count: count integers
 *
 * Return: 0
 */

void print_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	_putchar(c);
	(*count)++;
}
/**
 * printf_string - print the string
 * @args: argument string
 * @count: integars to print
 *
 * Return: 0
 */

void printf_string(va_list args, int *count)
{
	const char *s = va_arg(args, const char*);

	while (*s)
	{
		_putchar(*s);
		s++;
		(*count)++;
	}
}
/**
 * print_percent - print the percentage
 * @count: percentage count
 *
 * Return: 0
 */

void print_percent(int *count)
{
	_putchar('%');
	(*count)++;
}
/**
 * _printf - function that produces output according to a format
 * @format: is a character string
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					print_char(args, &count);
					break;
				case 's':
					printf_string(args, &count);
					break;
				case '%':
					print_percent(&count);
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
/**
 * ce_main - function main
 *
 * Return: 0
 */

int ce_main(void)
{
	char c = 'B';
	const char *s = "Hello, Team collins and ezekiel!";

	int num_chars = _printf("Character: %c, String: %s, Percentage: %%\n", c, s);

	printf("\nNumber of characters printed: %d\n", num_chars);
	return (0);
}
