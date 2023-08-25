#include "main.h"

unsigned int convert_lower_x(va_list args, buffer_t *output,
							 unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_caps_X(va_list args, buffer_t *output,
							unsigned char flags, int wid, int prec, unsigned char len);

/**
 * isLengthLong-> Checks of length is long
 * @len:first param
 * Return: an int
 */
int isLengthLong(int len)
{
	return len == LONG;
}

/**
 * isLengthShort-> Checks of length is short
 * @len:first param
 * Return: an int
 */
int isLengthShort(int len)
{
	return len == LONG;
}

/**
 * convert_caps_X - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_caps_X(va_list args, buffer_t *output,
							unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int nums;
	unsigned int returns = 0;
	char *lead = "0X";

	if (isLengthLong(len))
		nums = va_arg(args, unsigned long);
	else
		nums = va_arg(args, unsigned int);
	if (isLengthShort(len))
		nums = (unsigned short)nums;

	if (HASH_FLAG == 1 && nums != 0)
		returns += _memcpy(output, lead, 2);

	if (!(nums == 0 && prec == 0))
		returns += convert_ubase(output, nums, "0123456789ABCDEF",
								 flags, wid, prec);

	returns += print_out_negative_width(output, returns, flags, wid);

	return (returns);
}

/**
 * convert_lower_x - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_lower_x(va_list args, buffer_t *output,
							 unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int returns = 0;
	char *lead = "0x";

	if (isLengthLong(len))
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (isLengthShort(len))
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		returns += _memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		returns += convert_ubase(output, num, "0123456789abcdef",
								 flags, wid, prec);

	returns += print_out_negative_width(output, returns, flags, wid);

	return (returns);
}
