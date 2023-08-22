#include "main.h"
/**
 *_strlen -> Returns the length of a string
 *@s: A string pointer argument
 *Return: returns 1 or 0 based on argument
 */
int _strlen(char *s)
{
    int length = 0;

    while (s[length] != '\0')
        length++;
    return (length);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char s)
{
    return (write(1, &s, 1));
}

int _printf(const char *format, ...)
{
    int chars_printed = 0;
    char c;
    int k;
    va_list args;
    va_start(args, format);

    if (format != NULL)
    {
        while ((c = *format++) != '\0')
        {
            if (c == '%')
            {
                char next = *format++;
                if (next == 'c')
                {
                    char ch = (char)va_arg(args, int);
                    _putchar(ch);
                    chars_printed++;
                }
                else if (next == 's')
                {
                    char *str = va_arg(args, char *);
                    for (k = 0; str[k] != '\0'; k++)
                        _putchar(str[k]);

                    chars_printed += _strlen(str);
                }
                else if (next == '%')
                {
                    _putchar('%');
                    chars_printed++;
                }
            }
            else
            {
                _putchar(c);
                chars_printed++;
            }
        }
    }

    va_end(args);
    return chars_printed;
}
