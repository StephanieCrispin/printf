#include "main.h"

/**
 * getBuff_size-> outputs the correct size of a buffer;
 * @format: First param
 * @u: Second param
 * Return: returns an int
 */
int getBuff_size(const char *format, int *u)

{
	int curr_loop = *u + 1;
	int size = 0;

	if (format[curr_loop] == 'l')
		size = 2;
	else if (format[curr_loop] == 'h')
		size = 1;

	if (size == 0)
		*u = curr_loop - 1;
	else
		*u = curr_loop;

	return (size);
}
