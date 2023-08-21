#include "main.h"
#include <stdio.h>
int _putchar(char s)
{
    return (write(1, &s, 1));
}

int printCharStringMod(const char *format, ...)
{
    va_list arguments;
    int len = 0, i;

    va_start(arguments, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                char ch = va_arg(arguments, int);
                putchar(ch);
                len++;
            }

            if (format[i] == 's')
            {
                char *str = va_arg(arguments, char *);
                int k;
                for (k = 0; str[k] != '\0'; k++)
                {
                    putchar(str[k] + 0);
                    len++;
                }
            }
        }
        _putchar(format[i]);
        len++;
    }
    va_end(arguments);

    return (len);
}