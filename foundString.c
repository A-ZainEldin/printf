#include "main.h"

/**
 * foundString - function print string passed from printf
 *
 * @string: string argument
 *
 * Return: intger
 */

int foundString(char *string)
{
	int i = 0, count = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		write(1, &string[i], 1);
		count++;
	}
	return (count);
}
