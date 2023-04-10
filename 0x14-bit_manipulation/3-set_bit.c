#include "main.h"
#include <stdio.h>
/**
 * set_bit - sets the value of a bit to 1.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: return 1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int b;

	if (index > 63)
		return (-1);

	b = 1 << index;
	*n = (*n | b);

	return (1);
}
