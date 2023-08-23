#include "main.h"
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    /*  unsigned int ui;
    void *addr; */

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("String:[%s]\n", "I am a string !");
    len2 = printf("String:[%s]\n", "I am a string !");
    printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    printf("%s\n", "%");
    printf("%s\n", "%");

    printf("%s\n", "Testing percent before null terminator %");
    printf("%s\n", "Testing percent before null terminator %");

    len = _printf("Escape characters:[\\n\\t]\n");
    len2 = printf("Escape characters:[\\n\\t]\n");
    printf("Len from escape:[%d]\n", len);
    printf("Len from escape:[%d]\n", len2);

    len = _printf("ASCII value of 'A' is: [%c]\n", 65);
    len2 = printf("ASCII value of 'A' is: [%c]\n", 65);
    printf("Len from _printf:[%d]\n", len);
    printf("Len from printf:[%d]\n", len2);

    len = _printf("Printing lower-case letter using ASCII value: [%c]\n", 97);
    len2 = printf("Printing lower-case letter using ASCII value: [%c]\n", 97);
    printf("Len from lowercase:[%d]\n", len);
    printf("Len from lowercase:[%d]\n", len2);

    len = _printf("Multiline strings:\n[%s]\n", "This string is\non multiple lines.");
    len2 = printf("Multiline strings:\n[%s]\n", "This string is\non multiple lines.");
    printf("Len from multiln:[%d]\n", len);
    printf("Len from printf:[%d]\n", len2);
    /*-------------------------------------*/
    len = _printf("% %");
    _printf("\n");
    len2 = printf("% %");
    printf("\n");
    printf("len from 2%% and midspace: %d\n", len);
    printf("len from 2%% and midspace: %d\n", len2);

    len = _printf("% ");
    _printf("\n");
    len2 = printf("% ");
    printf("\n");
    printf("len from 1%% and space: %d\n", len);
    printf("len from 1%% and space: %d\n", len2);

    len = _printf("%\0");
    _printf("\n");
    len2 = printf("%\0");
    printf("\n");
    printf("len from %% and null terminator: %d\n", len);
    printf("len from %% and null terminator: %d\n", len2);

    len = _printf("%c\n", NULL);
    len2 = printf("%c\n", NULL);
    printf("len from null char:%d\n", len);
    printf("len from null char:%d\n", len2);

    len = _printf("NULL");
    _printf("\n");
    len2 = printf("NULL");
    printf("\n");
    printf("len from NULL string: %d\n", len);
    printf("len from NULL string: %d\n", len2);

    len = _printf(NULL);
    _printf("\n");
    len2 = printf(NULL);
    printf("\n");
    printf("len from outright null: %d\n", len);
    printf("len from outright null: %d\n", len2);

    return (0);
}
