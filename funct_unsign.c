#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_binary - spcifier to print
 * @n: integer value
 *
 * Return: 0
 */
void print_binary(unsigned int n)
{
	if (n > 1)
		print_binary(n >> 1);
	_putchar((n & 1) + '0');
}
/**
 * _printf - function that produces output
 * @format: format specifier
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{

	int count = 0;

	int i;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'b':
					{
						unsigned int num = va_arg(args, unsigned int);

						print_binary(num);
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
 * Return: 0
 */
int main(void)
{
	_printf("The number in binary is: %b\n", 42);
	return (0);
}
