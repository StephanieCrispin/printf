#include "main.h"
#include <string.h>
/**
 * _printf - Printf Function created
 * @format: format and specifier
 * Return: %% chars printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    char *str = NULL;
    unsigned k = 0, chars_printed = 0;
    char c;
    (void)c;
    (void)str;

    va_start(args, format);
    for (; format[k] != '\0'; k++)
    {
        if (format[k] != '%')
        {
            _putchar(format[k]);
        }
        else if (format[k] == '%' && format[k + 1] != 'c' && format[k + 1] != 's' && format[k + 1] != '%')
        {
            if (format[k + 1] == 'v' || format[k + 1] == 'V')
                _putchar(format[k]);
        }
        else if (format[k + 1] == 'c')
        {
            _putchar(va_arg(args, int));
            k++;
        }
        else if (format[k + 1] == 's')
        {

            int str_value = OurPutS(va_arg(args, char *));
            k++;
            chars_printed += (str_value - 1);
        }
        else if (format[k + 1] == '%')
        {
            _putchar('%');
            k++;
        }
        else if ((format[k + 1] == 'd') || (format[k + 1] == 'i'))
        {
            handle_int(va_arg(args, int));
            k++;
        }
        chars_printed += 1;
    }
    return (chars_printed);
}
