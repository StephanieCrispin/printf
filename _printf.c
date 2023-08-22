#include "main.h"
#include <string.h>

/**
 * _printf - Printf Function created
 * @format: format and specifier
 * Return: %% chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0;
	char c;

	va_start(args, format);
	while ((c = *format++) != '\0')
	{
		if (c == '%')
		{
			char next = *format++;
			if (next == 'c')
			{
				char ch = (char)va_arg(args, int);
				_putchar(ch);
				chars_printed++;
			}
			else if (next == 's')
			{
				int str_value = OurPutS(va_arg(args, char *));
				chars_printed += (str_value - 1);
				chars_printed += str_value;
			}
			else
			{
				_putchar(c);
				_putchar(next);
				chars_printed += 2;
			}
		}
		else
		{
			_putchar(c);
			chars_printed++;
		}
	}
	return (chars_printed);
}

/*va_list args;
	unsigned int k = 0, chars_printed = 0;
	if (format == NULL)
	{
		_putchar(' ');
		return (-1);
	}
	va_start(args, format);
	for (; format[k] != '\0'; k++)
	{

		if (format[k] != '%')
			_putchar(format[k]);
		else if (format[k] == '%' && format[k + 1] != 'c' && format[k + 1] != 's' && format[k + 1] != '%' && format[k + 1])
			_putchar(format[k]);
		else if (format[k + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			k++;
		}
		else if (format[k + 1] == 's')
		{
			int str_value = OurPutS(va_arg(args, char *));

			k++;
			chars_printed += (str_value - 1);
		}
		else if (format[k + 1] == '%')
		{
			_putchar('%');
			k++;
		}
		else if ((format[k + 1] == 'd') || (format[k + 1] == 'i'))
		{
			handle_int(va_arg(args, int));
			k++;
		}
		chars_printed += 1;
	}
	if (format[0] == '\n' || (format[0] == '%' && (!format[1])))
		chars_printed = -1;
	return (chars_printed);*/