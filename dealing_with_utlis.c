#include "main.h"

/**
 *  can_print - Evaluates if a char is printable
 * @s: char to be evaluated
 *
 * Return: 1 if s is printable, 0 otherwise
 */
int can_print(char s)
{
	if (s < 127 && s >= 32)
	{
		return (1);
	}

	return (0);
}

/**
 * code_hexa_appendding - appenddign ascci in hexadecimal code to the buffer
 * @buffer: array of chars
 * @j: The index at which to start the appending
 * @ascii_code: ASSCI CODE
 * Return: Always 3
 */
int code_hexa_appendding(char ascii_code, char buffer[], int j)
{
	char mapping_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = mapping_to[ascii_code / 16];
	buffer[j] = mapping_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convertSizeNum - castting a number to the specified size
 * @num: the number to be casted
 * @size: number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}

	return ((unsigned int)num);
}
