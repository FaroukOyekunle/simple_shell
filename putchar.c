#include  "shell.h"
/**
 * _putchar - print char
 * @c: character
 *
 * Return: write
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

