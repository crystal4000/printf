#include <unistd.h>
#include <stdarg.h>
#include “main.h”

int handle_conversion_specifier(char specifier, va_list args);

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

if (format == NULL)
return (-1);

va_start(args, format);

while (*format)
{
if (*format != '%')
{
count += write(1, format, 1);
}
else
{
format++;
count += handle_conversion_specifier(*format, args);
}

format++;
}

va_end(args);

return (count);
}

/**
 * handle_conversion_specifier - Handles conversion specifier
 * @specifier: Conversion specifier character
 * @args: Variable argument list
 *
 * Return: Number of characters printed
 */
int handle_conversion_specifier(char specifier, va_list args)
{
int count = 0;
switch (specifier)
{
case 'c':

	{
char ch = (char)va_arg(args, int);
count += write(1, &ch, 1);
break;
}

case 's':
{
char *str = va_arg(args, char *);
while (str && *str)
{
count += write(1, str, 1);
str++;
}
break;
}

case '%':
count += write(1, "%", 1);
break;

default:
count += write(1, "%d", 1);
count += write(1, &specifier, 1);
break;
}

return (count);
}
