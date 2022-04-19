#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct fmt - structure
 * @F: char holding the format.
 * @T: pointer function.
 */
typedef struct fmt
{
	char F;
	int (*T)(va_list);
} ft;


int _putchar(char c);
int _printf(const char *format, ...);

#endif


