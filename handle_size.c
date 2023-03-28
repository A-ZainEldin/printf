#include "main.h"

/**
 * handleSize - function calculates the size for casting the argument
 * that passed to _printf
 * @format: Formatted string in which to print the arguments
 * @j: the list of arguments for printing
 *
 * Return: value of precision
 */
int handleSize(const char *format, int *j)
{
	int index_j = *j + 1;
	int size = 0;

	if (format[index_j] == 'l')
	{
		size = S_LONG;
	}
	else if (format[index_j] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*j = index_j - 1;
	}
	else
	{
		*j = index_j;
	}


	return (size);
}
