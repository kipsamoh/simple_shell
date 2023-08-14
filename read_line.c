#include "main.h"

/**
 * read_line - reads the input str.
 *
 * @i_eof: return value of get_line function
 * Return: input str
 */
char *read_line(int *i_eof)
{
	char *in_put = NULL;
	size_t buffsize = 0;

	*i_eof = getline(&in_put, &buffsize, stdin);

	return (in_put);
}
