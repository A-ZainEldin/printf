#include "main.h"
/**
 * deal_with_print - function to handle and print an argument based on its
 * type
 * @fmt: formatted string  to print the arguments
 * @list: the list of arguments for printing
 * @din: ind
 * @buffer: buffer array to handle the print
 * @flags: calculates active flags
 * @width: get the  width
 * @precision: the precision specification
 * @size: size specifier
 * Return: 1 or 2
 */
int deal_with_print(const char *fmt, int *din, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, lenth_unkown = 0, printed_chars = -1;
	fmt_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; format_types[i].fmt != '\0'; i++)
		if (fmt[*din] == format_types[i].fmt)
		{
			return (format_types[i].fn(list, buffer, flags, width, precision, size));
		}

	if (format_types[i].fmt == '\0')
	{
		if (fmt[*din] == '\0')
			return (-1);

		lenth_unkown += write(1, "%%", 1);

		if (fmt[*din - 1] == ' ')
			lenth_unkown += write(1, " ", 1);

		else if (width)
		{
			--(*din);
			while (fmt[*din] != ' ' && fmt[*din] != '%')
				--(*din);
			if (fmt[*din] == ' ')
				--(*din);
			return (1);
		}
		lenth_unkown += write(1, &fmt[*din], 1);
		return (lenth_unkown);
	}
	return (printed_chars);
}
