#include "main.h"

/**
 * get_len - Get the lenght of a num.
 * @n: type int num.
 * Return: num lenght.
 */
int get_len(int n)
{
	unsigned int n_1;
	int len_ght = 1;

	if (n < 0)
	{
		len_ght++;
		n_1 = n * -1;
	}
	else
	{
		n_1 = n;
	}
	while (n_1 > 9)
	{
		len_ght++;
		n_1 = n_1 / 10;
	}

	return (len_ght);
}
/**
 * aux_itoa - function converts int to str.
 * @n: type int num
 * Return: Str.
 */
char *aux_itoa(int n)
{
	unsigned int n_1;
	int len_ght = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (len_ght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + len_ght) = '\0';

	if (n < 0)
	{
		n_1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n_1 = n;
	}

	len_ght--;
	do {
		*(buffer + len_ght) = (n_1 % 10) + '0';
		n_1 = n_1 / 10;
		len_ght--;
	}
	while (n_1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a str to an int.
 * @s: input str.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, o_i = 0, pn = 1, y = 1, x;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (x = count - size; x < count; x++)
	{
		o_i = o_i + ((*(s + x) - 48) * y);
		y /= 10;
	}
	return (o_i * pn);
}
