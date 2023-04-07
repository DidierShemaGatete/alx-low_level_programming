#include "main.h"
#include <stddef.h>

/**
 * Binary_to_unit - converts a binary number to an unsigned int
 * @b: pointer to the binary string
 *
 * Return: the converted number or 0 if there is one and more chars
 * in the string b that is not 0 or 1, or if b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (b == NULL)
		return (0);


	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);
		n <<= 1;
		if (*b == '1')
			n += 1;

		b++;

	}

	return (n);
}
