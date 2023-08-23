#include "main.h"
int _write_character(char s, char buff[], int size);

/**
 * printoutChar -> Prints one character
 * @args:First param
 * @buff: Second param
 * @size: Third param
 *  Return: returns an int
 */

int printoutChar(va_list args, char buff[], int size)
{
	char s;

	s = va_arg(args, int);
	(void)size;

	buff[0] = s;
	buff[1] = '\0';
	return (write(1, buff, 1));
}

/**
 * printoutString -> prints out a string
 * @args:First param
 * @buff: Second param
 * @size: Third param
 *  Return: returns an int
 */
int printoutString(va_list args, char buff[], int size)
{
	char *string;
	int len = 0;
	(void)size;
	(void)buff;
	(void)args;

	string = va_arg(args, char *);
	if (string == NULL)
		string = "(null)";

	while (string[len] != '\0')
	{
		len++;
	}
	return (write(1, string, len));
}

/**
 * printoutMod-> Prints out value for modulus format specifier
 * @args:First param
 * @buff: Second param
 * @size: Third param
 * Return: returns an int
 */
int printoutMod(va_list args, char buff[], int size)
{
	(void)size;
	(void)buff;
	(void)args;
	return (write(1, "%%", 1));
}
/**
 * _write_character-> Writes a single character to stdout
 * @s:First param
 * @buff: Second param
 * @size: Third param
 *  Return: returns an int
 */
int _write_character(char s, char buff[], int size)
{
	(void)size;
	buff[0] = s;
	buff[1] = '\0';
	return (write(1, buff, 1));
}
