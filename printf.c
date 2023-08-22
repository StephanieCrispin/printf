#include "main.h"

int _strlen(char *s)
{
    int length = 0;

    while (s[length] != '\0')
        length++;
    return (length);
}

int _putchar(char s)
{
    return (write(1, &s, 1));
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int chars_printed = 0;
    char c;

    while ((c = *format++) != '\0')
    {
        if (c == '%')
        {
            char next = *format++;
            if (next == 'c')
            {
                char ch = (char)va_arg(args, int);
                putchar(ch);
                chars_printed++;
            }
            else if (next == 's')
            {
                char *str = va_arg(args, char *);
                fputs(str, stdout);
                chars_printed += _strlen(str);
            }
            else if (next == '%')
            {
                putchar('%');
                chars_printed++;
            }
        }
        else
        {
            putchar(c);
            chars_printed++;
        }
    }

    va_end(args);
    return chars_printed;
}
