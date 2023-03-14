#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer of an array of chars
 */
char *_strdup(char *str)
{
	char *ptr;
	int length = 0, n = 0;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
	{
		length++;
	}

	ptr = (char *) malloc(length + 1 * sizeof(char));

	if (ptr == NULL)
		return (NULL);

	for (; n <= length; n++)
	{
		ptr[n] = str[n];
	}
	ptr[length] = '\0';
	return (ptr);
}
