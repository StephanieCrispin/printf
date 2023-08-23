#include "main.h"
int _write_character(char s, char buff[], int size);

int printoutChar(va_list args, char buff[], int size)
{
    char s;
    s = va_arg(args, int);
    (void)size;

    buff[0] = s;
    buff[1] = '\0';
    return write(1, buff, 1);
}

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

int printoutMod(va_list args, char buff[], int size)
{
    (void)size;
    (void)buff;
    (void)args;
    return (write(1, "%%", 1));
}

int _write_character(char s, char buff[], int size)
{
    (void)size;
    buff[0] = s;
    buff[1] = '\0';
    return (write(1, buff, 1));
}