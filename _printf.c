#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, sum;
	char c, *s;

	va_start(args, format);
	for (i = 0, sum = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			if (format[i] == '\n')
			{
				write(1, "\n", 1); }
			else
			{write(1, &format[i], 1); }
			sum++; }
		else
		{
			switch (format[++i])
			{case 'c':
					c = (char)va_arg(args, int);
					write(1, &c, 1);
					sum++;
					break;
				case 's':
					s = va_arg(args, char *);
					while (*s != '\0')
					{
						write(1, s++, 1);
						sum++; }
					break;
				case '%':
					write(1, &format[i], 1);
					sum++;
					break;
				default:
					write(1, &format[i - 1], 2);
					sum += 2;
					break;
			} } } va_end(args);
	return (sum); }
