#include "main.h"

/**
 * bufferPrint -> Writes out characters to the buffer and neccesary errors
 * @buff: First param
 * @buff_indicator: Second param
 */

void bufferPrint(char buff[], int *buff_indicator)
{
	if (*buff_indicator > 0)
	{
		int chars_written = write(1, buff, *buff_indicator);
		if (chars_written < 0)
		{
			write(2, "Error\n", sizeof("Error\n") - 1);
		}
	}
	*buff_indicator = 0;
}
