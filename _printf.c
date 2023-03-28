#include "main.h"
/**
 *_printf- does the job of printf
 *@format: the string passed
 *Return: int of what was printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, sum;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			sum++;
		}
		else
		{
			if (format[i + 1] == 's')
			{
				sum += foundString(va_arg(args, char*));
				i++;
			}
			else if (format[i + 1] == 'c')
			{
				sum += foundChar(va_arg(args, int));
				i++;
			}
		}
	}
	return (sum);
}
