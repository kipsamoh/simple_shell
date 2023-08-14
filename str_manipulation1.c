#include "main.h"

/**
 * _strdup - duplicates a string in the heap memory.
 * @s: Type char pointer string
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Returns the lenght of a string.
 * @s: Type character pointer
 * Return: Always 0.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - compares characters of string
 * @str: input str.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int x, y, z;

	for (x = 0, z = 0; str[x]; x++)
	{
		for (y = 0; delim[y]; y++)
		{
			if (str[x] == delim[y])
			{
				z++;
				break;
			}
		}
	}
	if (x == z)
		return (1);
	return (0);
}

/**
 * _strtok - splits a str by some delimiter.
 * @str: input str.
 * @delim: delimiter.
 *
 * Return: str splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int x, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		x = _strlen(str);
		str_end = &str[x]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (x = 0; delim[x]; x++)
		{
			if (*splitted == delim[x])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defines if str passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int x;

	for (x = 0; s[x]; x++)
	{
		if (s[x] < 48 || s[x] > 57)
			return (0);
	}
	return (1);
}
