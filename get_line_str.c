#include "main.h"

/**
 * bring_line - assigns the line variable 4 get_line
 * @lineptr: Buf that store the in_put string
 * @buffer: string which has been called to line
 * @n: size of line
 * @j: size of buf
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - read string in_put
 * @lineptr: buf that stores the in_put
 * @n: size of line pointer
 * @stream: string to read from
 * Return: size of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int x;
	static ssize_t in_put;
	ssize_t retreaval;
	char *buffer;
	char t = 'z';

	if (in_put == 0)
		fflush(stream);
	else
		return (-1);
	in_put = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		x = read(STDIN_FILENO, &t, 1);
		if (x == -1 || (x == 0 && in_put == 0))
		{
			free(buffer);
			return (-1);
		}
		if (x == 0 && in_put != 0)
		{
			in_put++;
			break;
		}
		if (in_put >= BUFSIZE)
			buffer = _realloc(buffer, in_put, in_put + 1);
		buffer[in_put] = t;
		in_put++;
	}
	buffer[in_put] = '\0';
	bring_line(lineptr, n, buffer, in_put);
	retreaval = in_put;
	if (x != 0)
		in_put = 0;
	return (retreaval);
}
