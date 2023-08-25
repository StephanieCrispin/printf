#include "main.h"

unsigned int convert_s(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_S(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_r(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_R(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len);

/**
 * isStringNull-> Checks of length is long
 * @len:first param
 * Return: an int
 */
int isStringNull(char *string)
{
	return string == NULL;
}

unsigned int convert_s(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len)
{
	int size;
	char *string, *null = "(null)";
	unsigned int returns = 0;

	(void)flags;
	(void)len;

	string = va_arg(args, char *);
	if (isStringNull(string))
		return (_memcpy(output, null, 6));

	for (size = 0; *(string + size);)
		size++;

	returns = returns + print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	while (*string != '\0' && prec > 0)
	{
		returns += _memcpy(output, string, 1);
		prec--;
		string++;
	}

	returns = returns + print_neg_width(output, returns, flags, wid);

	return (returns);
}

unsigned int convert_S(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len)
{
	char *string, *null = "(null)", *hex = "\\x", zero = '0';
	unsigned int returns = 0;
	int size, index;

	(void)len;
	string = va_arg(args, char *);
	if (isStringNull(string))
		return (_memcpy(output, null, 6));

	for (size = 0; string[size];)
		size++;

	returns = returns + print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (index = 0; *(string + index) != '\0' && index < prec; index++)
	{
		if (*(string + index) < 32 || *(string + index) >= 127)
		{
			returns = returns + _memcpy(output, hex, 2);
			if (*(string + index) < 16)
				returns = returns + _memcpy(output, &zero, 1);
			returns = returns + convert_ubase(output, *(string + index),
											  "0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		returns = returns + _memcpy(output, (string + index), 1);
	}

	returns = returns + print_neg_width(output, returns, flags, wid);

	return (returns);
}

unsigned int convert_R(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len)
{

	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *string, *null = "(null)";
	unsigned int returns = 0;
	int i, j, size;

	(void)len;
	(void)flags;

	string = va_arg(args, char *);
	if (isStringNull(string))
		return (_memcpy(output, null, 6));

	for (size = 0; *(string + size);)
		size++;

	returns += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (i = 0; *(string + i) != '\0' && i < prec; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(string + i) == *(alpha + j))
			{
				returns += _memcpy(output, (rot13 + j), 1);
				break;
			}
		}
		if (j == 52)
			returns += _memcpy(output, (string + i), 1);
	}

	returns += print_neg_width(output, returns, flags, wid);

	return (returns);
}

unsigned int convert_r(va_list args, buffer_t *output,
					   unsigned char flags, int wid, int prec, unsigned char len)
{
	char *string, *null = "(null)";
	int size, end, i;

	unsigned int returns = 0;

	(void)len;
	(void)flags;

	string = va_arg(args, char *);
	if (isStringNull(string))
		return (_memcpy(output, null, 6));

	for (size = 0; *(string + size);)
		size++;

	returns = returns + print_string_width(output, flags, wid, prec, size);

	end = size - 1;
	prec = (prec == -1) ? size : prec;
	for (i = 0; end >= 0 && i < prec; i++)
	{
		returns = returns + _memcpy(output, (string + end), 1);
		end--;
	}

	returns = returns + print_neg_width(output, returns, flags, wid);

	return (returns);
}
