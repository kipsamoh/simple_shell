#include "main.h"

/**
 * without_comment - removes comments from the input
 *
 * @in: input str
 * Return: in_put without comments
 */
char *without_comment(char *in)
{
	int x, maxx;

	maxx = 0;
	for (x = 0; in[x]; x++)
	{
		if (in[x] == '#')
		{
			if (x == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[x - 1] == ' ' || in[x - 1] == '\t' || in[x - 1] == ';')
				maxx = x;
		}
	}

	if (maxx != 0)
	{
		in = _realloc(in, x, maxx + 1);
		in[maxx] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash: relevant data (av, input, args)
 *
 * Return: void
 */
void shell_loop(data_shell *datash)
{
	int x, end;
	char *input;

	x = 1;
	while (x == 1)
	{
		write(STDIN_FILENO, " $ ", 4);
		input = read_line(&end);
		if (end != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			x = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			x = 0;
			free(input);
		}
	}
}
