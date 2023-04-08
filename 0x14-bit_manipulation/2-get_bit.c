#include <stdio.h>
#include "main.h"
/**
 * get_bit - retrun the value of a bit at a given index
 * @n: the number toget the bit from
 * @index: the indez of the bit to retrieve, starting from 0
 *
 * Return: he value of the bit at index, or -1 if an error ocuured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index <= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n >> index) & 1);
}
