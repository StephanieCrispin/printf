#include "main.h"

/**
 * _printf -> Replicates the standard library's printf function
 * @format: First paramter of a varaidic function
 * Return: returns the number of values outputted to stdout
 */

int _printf(const char *format, ...)
{
	int u = 0, buff_indicator = 0, chars_printed = 0, printed = 0, size;
	va_list args;
	char buff[SINGLE_BUFF];

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (; format && format[u] != '\0'; u++)
	{
		if (format[u] == '%' && format[u + 1] == ' ' && format[u + 2] == '%')
			chars_printed = 1;
		if (format[u] != '%')
		{
			buff[buff_indicator++] = format[u];
			if (buff_indicator == SINGLE_BUFF)
			{
				bufferPrint(buff, &buff_indicator);
				chars_printed += SINGLE_BUFF;
			}
			else
				chars_printed++;
		}
		else
		{
			bufferPrint(buff, &buff_indicator);
			size = getBuff_size(format, &u);
			++u;
			printed = controlPrint(format, &u, args, buff, size);

			if (printed == -1)
			{
				va_end(args);
				return (-1);
			}
			chars_printed += printed;
		}
	}
	bufferPrint(buff, &buff_indicator);
	va_end(args);

	/*if ((format[0] == '%' && format[1] == ' '))
		chars_printed = -1;*/

	return (chars_printed);
}
