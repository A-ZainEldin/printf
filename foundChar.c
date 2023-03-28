#include "main.h"

/**
 * foundChar - function print character
 *
 * @found: the character passed to this function as intger value
 *
 * Return: int
 */

int foundChar(int found)
{
	write(1, &found, 1);
	return (1);
}
