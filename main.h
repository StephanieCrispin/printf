#ifndef MAIN_H
#define MAIN_H

#define SINGLE_BUFF 1024

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct fc - Struct for operations
 * @f: Represents format specifiers
 * @func: Represents corresponding function
 */

struct fc
{
	char f;
	int (*func)(va_list, char[], int size);
};

/**
 * print_func - Typedef for struct for operations
 */
typedef struct fc print_func;

int _printf(const char *format, ...);
int controlPrint(const char *f, int *buffer_indicator,
				 va_list args, char buff[], int size);
void bufferPrint(char buff[], int *buff_indicator);

int printoutChar(va_list args, char buff[], int size);
int printoutString(va_list args, char buff[], int size);
int printoutMod(va_list args, char buff[], int size);

int _write_character(char s, char buff[], int size);
int _putchar(char s);

/**SIZE*/
int getBuff_size(const char *format, int *u);

#endif /*MAIN_H*/
