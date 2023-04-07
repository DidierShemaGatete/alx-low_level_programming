#include <stdio.h>
#include <stdlib.h>

/**
 * set_bet - sets the value of a bit to 1 at a given index
 * @n: pointer to the number to modify
 * @index: index of the bit to set (starting from 0)
 *
 * Return: 1 if it worked, or -1 if an error occured
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n |= (1UL << index);

	return (1);
}


/**
 * main - tests the set_bit function
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long int n;

	n = 1024;
	set_bit(&n, 5);
	printf("%lu\n", n);

	n = 98;
	set_bit(&n, 0);
	printf("%lu\n", n);

	return (0);
}
