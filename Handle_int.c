#include "main.h"

void handle_int(int digit)
{
    int b, str_value;
    (void)str_value;

    if (digit == 0)
        return;
    b = digit / 10;

    handle_int(b);
    _putchar(digit % 10 + '0');

    return;
}