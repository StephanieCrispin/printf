#include "main.h"

int _printf(const char *format, ...)
{
    int stringlength;
    va_list arguments;
    va_start(arguments, format);

    stringlength = printCharStringMod(format, arguments);
    return (stringlength);
}
