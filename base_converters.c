#include "main.h"

unsigned int convert_sbase(buffer_t *output, long int num, char *base,
						   unsigned char flags, int wid, int prec);
unsigned int convert_ubase(buffer_t *output,
						   unsigned long int num, char *base,
						   unsigned char flags, int wid, int prec);

/**
 * shouldPrintPtr-> conditionally prints out pointer
 * @flags: FIrst argument
 */
int shouldPrintPtr(int flags)
{
	return (flags >> 5) & 1;
}

/**
 * convert_ubase - Converts an unsigned long to an inputted base and
 *                 stores the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: An unsigned long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
						   unsigned char flags, int wid, int prec)
{
	unsigned int sz, returns;
	char *lead = "0x", dig;
	char pad = '0';
	returns = 1;

	for (sz = 0; *(base + sz);)
		sz++;

	if (!(num < sz))
		returns += convert_ubase(output, num / sz, base,
								 flags, wid - 1, prec - 1);

	else
	{
		if (shouldPrintPtr(flags)) /* Printing a ptr address */
		{
			wid = wid - 1;
			prec = prec - 2;
		}
		for (; prec > 1; prec -= 2, wid -= 2) /* Handle precision */
			returns += _memcpy(output, &pad, 1);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				returns += _memcpy(output, &pad, 1);
		}
		if (shouldPrintPtr(flags) == 1) /* Print 0x for ptr address */
			returns += _memcpy(output, lead, 2);
	}

	dig = base[(num % sz)];
	_memcpy(output, &dig, 1);

	return (returns);
}

/**
 * convert_sbase - Converts a signed long to an inputted base and stores
 *                 the result to a buffer contained in a struct.
 * @output: A buffer_t struct containing a character array.
 * @num: A signed long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
						   unsigned char flags, int wid, int prec)
{
	int size;
	char digit, pad = '0';
	unsigned int ret = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		ret += convert_sbase(output, num / size, base,
							 flags, wid - 1, prec - 1);

	else
	{
		for (; prec > 1; prec--, wid--) /* Handle precision */
			ret += _memcpy(output, &pad, 1);

		if (NEG_FLAG == 0) /* Handle width */
		{
			pad = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
	}

	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}
