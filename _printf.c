#include <unistd.h>
#include <stdarg.h>
#include "main.h"

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
	char ch;
	char *str;
	int num, num_digits, temp;
	char buffer[12];
	int i;

	switch (specifier)
	{
		case 'c':
			ch = (char)va_arg(args, int);
			count += write(1, &ch, 1);
			break;
		case 's':
			str = va_arg(args, char *);
			while (str && *str)
			{
				count += write(1, str, 1);
				str++;
			}
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			num_digits = 0;
			temp = num;

			if (num == 0)
			{
				count += write(1, "0", 1);
				break;
			}
			if (num < 0)
			{
				count += write(1, "-", 1);
				num = -num;
			}
			while (temp != 0)
			{
				temp /= 10;
				num_digits++;
			}
			for (i = num_digits - 1; i >= 0; i--)
			{
				buffer[i] = '0' + (num % 10);
				num /= 10;
			}
			count += write(1, buffer, num_digits);
			break;
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
