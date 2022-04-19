#include "main.h"
#include <stdio.h>

/**
 * _printf - Function produces output based on a format
 *
 * @format: Character string
 * @...: Ellipses
 * Return: Number of the characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	char f;
	int i, len;
	int (*prints)(va_list *);

	va_start(args, format);
	len = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++; /* move to the next character */
			f = format[i];


			prints() = get_func(f);
			len += prints(&args);
		}
		else
		{
			len += write(1, &format[i], 1);
		}
	} /* End of for loop */
	va_end(args);
	return (len);
}

