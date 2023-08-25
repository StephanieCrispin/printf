#include "main.h"

unsigned int convert_di(va_list args, buffer_t *output,
						unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_base(va_list args, buffer_t *output,
						  unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_u(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_o(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len);

unsigned int convert_u(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int returns = 0;
	unsigned long int num, empty = 0;

	if (isLengthLong(len))
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (isLengthShort(len))
		num = (unsigned short)num;

	if (!(num == empty && prec == 0))
		returns += convert_ubase(output, num, "0123456789",
								 flags, wid, prec);

	returns += print_negative_width(output, returns, flags, wid);

	return (returns);
}

unsigned int convert_di(va_list args, buffer_t *output,
						unsigned char flags, int wid, int prec, unsigned char len)
{
	long int d, copy;
	unsigned int returns = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (isLengthLong(len))
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (isLengthShort(len))
		d = (short)d;

	/* Handle space flag */
	if (SPACE_FLAG == 1 && d >= 0)
		returns += _memcpy(output, &space, 1);

	if (prec <= 0 && NEG_FLAG == 0) /* Handle width  */
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;

		/* Handle plus flag when zero flag is active */
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			returns += _memcpy(output, &plus, 1);
		/*Print negative sign when zero flag is active */
		if (ZERO_FLAG == 1 && d < 0)
			returns += _memcpy(output, &neg, 1);

		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (wid -= count; wid > 0; wid--)
			returns += _memcpy(output, &pad, 1);
	}

	/* Print negative sign when zero flag is not active */
	if (ZERO_FLAG == 0 && d < 0)
		returns += _memcpy(output, &neg, 1);
	/* Handle plus flag when zero flag is not active */
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		returns += _memcpy(output, &plus, 1);

	if (!(d == 0 && prec == 0))
		returns += convert_sbase(output, d, "0123456789",
								 flags, 0, prec);

	returns += print_negative_width(output, returns, flags, wid);

	return (returns);
}

unsigned int convert_o(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len)
{
	char zero = '0';

	unsigned long int num, empty = 0;
	unsigned int returns = 0;

	if (isLengthLong(len))
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (isLengthShort(len))
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != empty)
		returns += _memcpy(output, &zero, 1);

	if (!(num == empty && prec == 0))
		returns += convert_ubase(output, num, "01234567",
								 flags, wid, prec);

	returns += print_negative_width(output, returns, flags, wid);

	return (returns);
}

unsigned int convert_base(va_list args, buffer_t *output,
						  unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)len;

	return (convert_ubase(output, num, "01", flags, wid, prec));
}
