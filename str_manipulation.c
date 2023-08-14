#include "main.h"

/**
 * _strcat - concats two strings
 * @dest: character pointer the dest of the copied string
 * @src: const character pointer the source of string
 * Return: the destination
 */
char *_strcat(char *dest, const char *src)
{
	int x;
	int y;

	for (x = 0; dest[x] != '\0'; x++)
		;

	for (y= 0; src[y] != '\0'; y++)
	{
		dest[x] = src[y];
		x++;
	}

	dest[x] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies the str pointed to by src.
 * @dest: Type character pointer the dest of the copied string
 * @src: Type char pointer the source of string
 * Return: the destination.
 */
char *_strcpy(char *dest, char *src)
{

	size_t m;

	for (m = 0; src[m] != '\0'; m++)
	{
		dest[m] = src[m];
	}
	dest[m] = '\0';

	return (dest);
}
/**
 * _strcmp - Function that compares two str.
 * @s1: type str compar_ed
 * @s2: type str compar_ed
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0; s1[x] == s2[x] && s1[x]; x++)
		;

	if (s1[x] > s2[x])
		return (1);
	if (s1[x] < s2[x])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a str,
 * @s: str.
 * @c: char.
 * Return: the pointer to the first occurr_ence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int x = 0;

	for (; *(s + x) != '\0'; x++)
		if (*(s + x) == c)
			return (s + x);
	if (*(s + x) == c)
		return (s + x);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int x, y, bool;

	for (x = 0; *(s + x) != '\0'; x++)
	{
		bool = 1;
		for (y = 0; *(accept + y) != '\0'; y++)
		{
			if (*(s + x) == *(accept + y))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (x);
}
