#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void _sprintf(const char *str);
int _printf(const char *format, ...);
void _count(int *ptr, char *str);


#endif
