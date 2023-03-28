#include "main.h"

/**
 * get_value_precision - make calculatatio for the precision  for printing
 * @format: Formatt string that will print the arguments
 * @i: List of arguments to be printed.
 * @list: list of variable arguments
 *
 * Return: Precision intger
 */
int get_value_precision(const char *format, int *i, va_list list)
{
	int index_i = *i + 1;
	int value_precision = -1;

	if (format[index_i] != '.')
		return (value_precision);

	value_precision = 0;

	for (index_i += 1; format[index_i] != '\0'; index_i++)
	{
		if (is_digit(format[index_i]))
		{
			value_precision *= 10;
			value_precision += format[index_i] - '0';
		}
		else if (format[index_i] == '*')
		{
			index_i++;
			value_precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = index_i - 1;
	return (value_precision);
}
