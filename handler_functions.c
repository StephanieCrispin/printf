#include "main.h"

unsigned char func_handle_flags(const char *flag, char *index);
unsigned char func_handle_length(const char *modifier, char *index);
int func_handle_width(va_list args, const char *modifier, char *index);
int func_handle_precision(va_list args, const char *modifier, char *index);

unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
														 unsigned char, int, int, unsigned char);

unsigned char func_handle_flags(const char *flag, char *index)
{
	int i, j;
	unsigned char ret = 0;
	flag_t flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (ret == 0)
					ret = flags[j].value;
				else
					ret |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}

	return (ret);
}

unsigned char func_handle_length(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORTINT);
	}

	else if (*modifier == 'l')
	{
		(*index)++;
		return (LONG);
	}

	return (0);
}

int func_handle_width(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier >= '0' && *modifier <= '9') || (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}

unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *,
														 unsigned char, int, int, unsigned char)
{
	int loopVar;
	converter_t converters[] = {
		{'c', convert_ch},
		{'s', convert_s},
		{'d', convert_di},
		{'i', convert_di},
		{'%', convert_percentage},
		{'b', convert_base},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_lower_x},
		{'X', convert_caps_X},
		{'S', convert_S},
		{'p', convert_p},
		{'r', convert_r},
		{'R', convert_R},
		{0, NULL}};

	for (loopVar = 0; converters[loopVar].func; loopVar++)
	{
		if (converters[loopVar].specifier == *specifier)
			return (converters[loopVar].func);
	}

	return (0);
}

int func_handle_precision(va_list args, const char *modifier, char *index)
{
	int value = 0;

	if (*modifier != '.')
		return (-1);

	modifier++;
	(*index)++;

	if ((*modifier <= '0' || *modifier > '9') &&
		*modifier != '*')
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}

	while ((*modifier >= '0' && *modifier <= '9') ||
		   (*modifier == '*'))
	{
		(*index)++;

		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}

		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}

	return (value);
}