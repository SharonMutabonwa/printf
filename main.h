#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

struct convert
{

	char *sym;
	int (*f)(va_list);

};
typedef struct convert con_vert;

int _printf(const char *format, ...);



#endif
