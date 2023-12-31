#include "main.h"

unsigned int print_out_width(buffer_t *output, unsigned int printed,
							 unsigned char flags, int wid);
unsigned int print_out_string_width(buffer_t *output,
									unsigned char flags, int wid, int prec, int size);
unsigned int print_out_negative_width(buffer_t *output, unsigned int printed,
									  unsigned char flags, int wid);

/**
 * shouldPrintPtr-> conditionally prints out pointer
 * @flags: FIrst argument
 */
int isNegativeFlag(int flags)
{
	return (NEG_FLAG == 0);
}

/**
 * print_out_width - Stores leading spaces to a buffer for a width modifier.
 * @output: A buffer_t struct containing a character array.
 * @printed: The current number of characters already printed to output
 *           for a given number specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_out_width(buffer_t *output, unsigned int printed,
							 unsigned char flags, int wid)
{
	char width = ' ';

	unsigned int ret = 0;

	if (isNegativeFlag(flags))
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_out_string_width - Stores leading spaces to a buffer for a width modifier.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @size: The size of the string.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_out_string_width(buffer_t *output,
									unsigned char flags, int wid, int prec, int size)
{
	char width = ' ';
	unsigned int ret = 0;

	if (isNegativeFlag(flags))
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_out_negative_width - Stores trailing spaces to a buffer for a '-' flag.
 * @output: A buffer_t struct containing a character array.
 * @printed: The current number of bytes already stored to output
 *           for a given specifier.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int print_out_negative_width(buffer_t *output, unsigned int printed,
									  unsigned char flags, int wid)
{
	char width = ' ';

	unsigned int returns = 0;

	if (isNegativeFlag(flags))
	{
		for (wid -= printed; wid > 0; wid--)
			returns += _memcpy(output, &width, 1);
	}

	return (returns);
}
