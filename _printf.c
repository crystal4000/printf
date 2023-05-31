#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
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

			if (str == NULL)
			{
				count += write(1, "(null)", 6);
			}
			else
			{
				while (*str)
				{
					count += write(1, str, 1);
					str++;
				}
			}
			break;
		}
		case 'd':
		case 'i':
		{
			int num = va_arg(args, int);
			int num_digits = 0;
			int temp = num;
			char buffer[12];
			int i;

			if (num == INT_MIN)
			{
				count += write(1, "-2147483648", 11);
			}
			else
			{
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
				buffer[num_digits] = '\0';
				count += write(1, buffer, num_digits);
			}
			break;
		}
		case '%':
		{
			count += write(1, "%", 1);
			break;
		}
		default:
		{
			count += write(1, "%d", 1);
			count += write(1, &specifier, 1);
			break;
		}
	}

	return (count);
}

