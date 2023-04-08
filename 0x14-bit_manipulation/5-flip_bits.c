#include <stdio.h>
#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bit = 0, xor = n ^ m;
	unsigned int count = 0;

	while (bit < (8* sizeof(unsigned long int)))
	{
		if (xor & 1)
			count++;
		xor = xor >> 1;
		bit++;
	}
	return (count);
}
