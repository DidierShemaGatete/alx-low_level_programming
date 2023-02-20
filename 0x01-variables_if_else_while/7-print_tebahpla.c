#include <stdio.h>
/**
 * main - Entry point
 * Description: 'print alphabets in reverse'
 * Return: Always 0
 */
int main(void)
{
	int n = 122;

	while (n >= 97)
	{
		putchar(n);
		n--;
	}
	putchar('\n');
	return (0);
}
