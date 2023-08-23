#include "main.h"

int _printf(const char *format, ...)
{
    int u = 0, buff_indicator = 0, chars_printed = 0, printed = 0, size;

    va_list args;

    char buff[SINGLE_BUFF];

    (void)size;
    (void)printed;
    if (format == NULL)
    {
        return (-1);
    }

    va_start(args, format);

    for (; format && format[u] != '\0'; u++)
    {
        if (format[u] != '%')
        {
            buff[buff_indicator++] = format[u];
            if (buff_indicator == SINGLE_BUFF)
            {
                bufferPrint(buff, &buff_indicator);
                chars_printed += SINGLE_BUFF;
            }
            else
            {
                chars_printed++;
            }
        }
        else
        {
            bufferPrint(buff, &buff_indicator);
            size = getBuff_size(format, &u);
            ++u;
            printed = controlPrint(format, &u, args, buff, size);

            if (printed == -1)
            {
                va_end(args);
                return (-1);
            }
            chars_printed += printed;
            /*  chars_printed++;*/
        }
    }
    bufferPrint(buff, &buff_indicator);
    va_end(args);
    return (chars_printed);
}
