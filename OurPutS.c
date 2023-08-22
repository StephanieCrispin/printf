#include "main.h"

int OurPutS(char *string)
{
    int gedd = 0, str_value = 0;

    if (string)
    {
        while (string[gedd] != '\0')
        {
            _putchar(string[gedd]);
            str_value += 1;
            gedd++;
        }
    }

    return (str_value);
}
