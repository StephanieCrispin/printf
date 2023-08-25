#include "main.h"

unsigned int convert_c(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_t *output,
							 unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_percent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
unsigned int convert_percent(va_list args, buffer_t *output,
							 unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int returns = 0;

	(void)args;
	(void)prec;
	(void)len;

	returns = returns + print_width(output, returns, flags, wid);
	returns = returns + _memcpy(output, &percent, 1);
	returns = returns + print_neg_width(output, returns, flags, wid);

	return (returns);
}

/**
 * convert_c - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_c(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len)
{
	char c;
	unsigned int returns = 0;

	(void)prec;
	(void)len;

	c = va_arg(args, int);

	returns = returns + print_width(output, returns, flags, wid);
	returns = returns + _memcpy(output, &c, 1);
	returns = returns + print_neg_width(output, returns, flags, wid);

	return (returns);
}

/**
 * convert_p - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_p(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int returns = 0, nullCharacter = 0;

	(void)len;

	address = va_arg(args, unsigned long int);
	if (address == nullCharacter)
		return (_memcpy(output, null, 5));

	flags |= 32;
	returns = returns + convert_ubase(output, address, "0123456789abcdef",
									  flags, wid, prec);
	returns = returns + print_neg_width(output, returns, flags, wid);

	return (returns);
}
