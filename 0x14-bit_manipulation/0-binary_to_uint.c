#include "main.h"
#include <stddef.h>
/**
 * binary_to_unit - converts a binary number in a string to an unsigned int
 * @b: pointer to the binary string to convert
 *
 * Return: the converted number, or 0 if b is NULL or contains non-binary chars
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
