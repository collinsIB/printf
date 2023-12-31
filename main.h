#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/********** FUNCTIONS *********/

int _putchar(char o);
int _print_str(char *s);
int _printf(const char *format, ...);
int _format(char form_specifier, va_list arg_ptr);
int _print_my_digit(int value, int base);
void print_char(va_list args, int *count);
void printf_strings(va_list args, int *count);
void print_percent(int *count);
int _printf(const char *format, ...);
int main(void);
int ce_main(void);
int _print_main(void);
void print_binary(unsigned int n);

#endif /* MAIN_H */
