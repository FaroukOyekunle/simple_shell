#include "shell.h"

/**
 * _strlen - finds length of a string
 * @s: str given
 * Return: ngth
 */
int _strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * _strcat - Write a function that conc two str.
 *@src: source
 *@dest: destination
 * Return: Returns a er to the resulting str dest
 */
char *_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strs
 * @s1: first str
 * @s2: second str
 * Return: integer less than or equal or greater than 0
 */
int _strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	i++;
	}
	return (0);
}
/**
 * _atoi - convert a string to an integer
 * @s: given string
 * Return: integer
 */
int _atoi(char *s)
{
	int i, j, sign;
	unsigned int n, a;

	i = 0;
	sign = 1;
	n = 0;
	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
	i++;
	}
	if (s[i] != '\0')
	{
		j = i;
		while (s[j + 1] != '\0' && (s[j + 1] >= '0' && s[j + 1] <= '9'))
			j++;
		a = 1;
		while (i <= j)
		{
			n = n + (s[j] - '0') * a;
			a *= 10;
			j--;
		}
	}
	n *= sign;
	return (n);
}
/**
 * print_number - print a given number using _putchar
 * @n: number to be printed
 * Return: void
 */
void print_number(int n)
{
	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		print_number(147483648);
	}
	else if (n < 0)
	{
		_putchar('-');
		n = -n;
		print_number(n);
	}
	else if (n > 9)
	{
		print_number(n / 10);
		print_number(n % 10);
	}
	else
		 _putchar(n + '0');
}
