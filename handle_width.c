#include "main.h"

/**
 * handleWidth - function that calculates value of  width for printing
 * @format: pointer to formatted string for printing the arguments
 * @j: list of arguments for printing
 * @list: the list of the arguments
 *
 * Return: valueOfWidth.
 */
int handleWidth(const char *format, int *j, va_list list)
{
	int index_i;
	int valueOfWidth = 0;

	for (index_i = *j + 1; format[index_i] != '\0'; index_i++)
	{
		if (is_digit(format[index_i]))
		{
			valueOfWidth *= 10;

			valueOfWidth += format[index_i] - '0';
		}
		else if (format[index_i] == '*')
		{
			index_i++;

			valueOfWidth = va_arg(list, int);

			break;
		}
		else
		{
			break;
		}
	}

	*j = index_i - 1;

	return (valueOfWidth);
}
