#include "shell.h"

/**
 * _puts - print every other character starting from first one
 * @str: string passed
 * Return: void
 */
void _puts(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
