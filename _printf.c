#include "main.h"

void cleanBuffer(va_list args, buffer_t *output);
int handlePrintf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

/**
 * handlePrintf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @output: A buffer_t struct containing a buffer.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int handlePrintf(const char *format, va_list args, buffer_t *output)
{
	int wid, prec, ret = 0, u;
	char temporaryVar, nullCount = '\0';
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_t *,
					  unsigned char, int, int, unsigned char);

	for (u = 0; format[u] != nullCount; u++)
	{
		len = 0;
		if (*(format + u) == '%')
		{
			temporaryVar = 0;
			flags = func_handle_flags(format + u + 1, &temporaryVar);
			wid = func_handle_width(args, format + u + temporaryVar + 1, &temporaryVar);
			prec = func_handle_precision(args, format + u + temporaryVar + 1,
										 &temporaryVar);
			len = func_handle_length(format + u + temporaryVar + 1, &temporaryVar);

			f = handle_specifiers(format + u + temporaryVar + 1);
			if (f != NULL)
			{
				u += temporaryVar + 1;
				ret += f(args, output, flags, wid, prec, len);
				continue;
			}
			else if (format[u] + temporaryVar + 1 == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + u), 1);
		u += (len != 0) ? 1 : 0;
	}
	cleanBuffer(args, output);
	return (ret);
}

/**
 * cleanBuffer - Peforms cleanBuffer operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void cleanBuffer(va_list args, buffer_t *output)
{
	va_end(args);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_t *output;
	va_list args;
	int ret;

	if (format == 0)
		return (-1);
	output = init_buffer();
	if (output == 0)
		return (-1);

	va_start(args, format);

	ret = handlePrintf(format, args, output);

	return (ret);
}
