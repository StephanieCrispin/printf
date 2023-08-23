#include "main.h"
/**
 * controlPrint -> Controls outputting the values are written to stdout
 * @f: First param
 * @buffer_indicator: Second param
 * @args: Third Param
 * @buff: Fourth param
 * @size: Fifth param
 * Return: an integer value
 */

int controlPrint(const char *f, int *buffer_indicator,
				 va_list args, char buff[], int size)
{
	int u = 0, chars_printed = -1;
	int length_unknown = 0;

	print_func funcs[] = {
		{'c', printoutChar},
		{'s', printoutString},
		{'%', printoutMod},
		{'\0', NULL}};

	(void)chars_printed;

	while (funcs[u].f != '\0')
	{
		if (f[*buffer_indicator] == funcs[u].f)
			return (funcs[u].func(args, buff, size));
		u++;
	}

	if (funcs[u].f == '\0')
	{
		if (f[*buffer_indicator] == '\0')
			return (-1);
		length_unknown += write(1, "%%", 1);

		if (f[*buffer_indicator - 1] == ' ')
			length_unknown += write(1, " ", 1);

		length_unknown += write(1, &f[*buffer_indicator], 1);
		return (length_unknown);
	}
	return (funcs[u].func(args, buff, size));
}
