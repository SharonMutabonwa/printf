#include "main.h"

/**
 * _printf - Function to work like a printf function
 * @format: the format of printing character
 * Return: result.
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j = 0;
	int list;
	char *str;

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
		_putchar(format[i]);
		list++;
		}
		else if (format[i + 1] == 'c')
		{
		_putchar(va_arg(ap, int));
		i++;
		list++;
		}
		else if (format[i + 1] == 's')
		{

		str = va_arg(ap, char *);
		while (str[j] != '\0')
		{
			_putchar(str[j]);
			j++;
			list++;
		}
		else if (format[i + 1] == '%')
		{
			i++;
			_putchar('%');
			list++;
		}
	}
	va_end(ap);
	return (list);
}
