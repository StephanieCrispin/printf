#include "main.h"

int handle_int(va_list args, char buff[], int b)
{
	int num = va_arg(args, int);
	int chars_printed = 0;
	int neg = 0;
	int tmp;
	int buff_indicator = 0;
	char tmp_buff[BUFF_SIZE] = {0};

	if (num < 0)
	{
		neg = 1;
		num *= -1;
	}

	if (num == 0)
	{
		buff[buff_indicator++] = '0';

	}

	else
	{
		while (num > 0)
		{
			tmp_buff[tmp++] = (num % 10) + '0';
			num /= 10;
		}

		while (tmp > 0)
		{
			buff[buff_indicator++] = tmp_buff[--tmp];
		}
	}

	if (neg)
	{
		buff[buff_indicator++] = '-';

	}

	bufferPrint(buff, &buff_indicator);
	chars_printed += buff_indicator;

	return (chars_printed);
}
