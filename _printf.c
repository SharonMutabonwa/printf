#include "main.h"

/**
 * _printf - function that prints output according to format
 * @format: string that determines the conversion,
 * specifiers.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list vl;
	int n, start, end, len, pos, prev;

	int (*funcs[6])(va_list *) = {
		print_char, print_string, print_dec, print_int, print_double, print_perct};

	va_start(vl, format);

	n = start = len = prev = 0;
	while (n >= 0)
	{
		n = search_spec(format, n);

		if (n > 0)
		{
			if (prev > 0)
			start = prev;
			end = n - 1;
			len += print_to(format, start, end);
			pos = valid_spec(*(format + n));
			len += funcs[pos](&vl);
		}
		else
		len += print_to(format, prev, _strlen(format));

		prev = n + 1;

	}
	va_end(vl);
	return (len);
}

/**
 * count_specifiers - function that counts and returns the numbers,
 * of specifiers found.
 * @s: string to count specifiers
 * Return: the number of specifiers found
 */

int count_specifiers(const char *s)
{
	int n = 0, c = 0;

	while (n != -1)
	{
		n = search_spec(s, n);
		if (n > 0)
		c++;
	}

	return (c);
}

/**
 * get_specifiers - function that extract specifiers and return,
 * the specifier types.
 * @s: string to extract specifiers
 * @n: number of specifiers
 * @dst: pointer to string destination
 * Return: void
 */

void get_specifiers(const char *s, int n, char *dst)
{
	int c, d = 0;

	for (c = 0; c < n; c++)
	{
		d = search_spec(s, d);
		*(dst + c) = *(s + d);
	}
	*(dst + c) = '\0';
}

/**
 * print_perct - function that extracts and returns char argument
 * @v: va_list type to extract char argument
 * Return: lenght of printed string
 */

int print_perct(va_list __attribute__((__unused__)) *v)
{
	_putchar('%');

	return (1);
}


/**
 * valid_spec - function that checks if c is a valid specifier
 * @c: character to search
 * Return: 1 or -1
 */

int valid_spec(char c)
{
	char *s = VAL_SPEC;
	int i = 0;

	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		return (i);
		i++;
	}
	return (-1);
}

