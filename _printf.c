#include "main.h"


int _printf(const char *format, ...)
{
	va_list arg;
	int i = 0, j = 0, len = 0;
	char *dest;

	while (format[len] != '\0')
		len++;

	dest = malloc(sizeof(char) * len);
	if(dest == NULL)
		exit(1);

	va_start(arg, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				dest[i] = (char)va_arg(arg, int);
				j++;
			}
		}
		else
		{
			dest[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, dest, i++);
	va_end(arg);
	free(dest);
	return (i);
}
