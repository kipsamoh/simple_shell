#include "main.h"

/**
 * swap_char - swaps | and & for non-printed characters
 *
 * @input: input str
 * @bool: type of swap
 * Return: swapped str
 */
char *swap_char(char *input, int bool)
{
	int x;

	if (bool == 0)
	{
		for (x = 0; input[x]; x++)
		{
			if (input[x] == '|')
			{
				if (input[x + 1] != '|')
					input[x] = 16;
				else
					x++;
			}

			if (input[x] == '&')
			{
				if (input[x + 1] != '&')
					input[x] = 12;
				else
					x++;
			}
		}
	}
	else
	{
		for (x = 0; input[x]; x++)
		{
			input[x] = (input[x] == 16 ? '|' : input[x]);
			input[x] = (input[x] == 12 ? '&' : input[x]);
		}
	}
	return (input);
}

/**
 * add_nodes - add separx_ators and comm_and lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @input: input str
 * Return: void
 */
void add_nodes(sep_list **head_s, line_list **head_l, char *input)
{
	int x;
	char *cmd;

	input = swap_char(input, 0);

	for (x = 0; input[x]; x++)
	{
		if (input[x] == ';')
			add_sep_node_end(head_s, input[x]);

		if (input[x] == '|' || input[x] == '&')
		{
			add_sep_node_end(head_s, input[x]);
			x++;
		}
	}

	cmd = _strtok(input, ";|&");
	do {
		cmd = swap_char(cmd, 1);
		add_line_node_end(head_l, cmd);
		cmd = _strtok(NULL, ";|&");
	} while (cmd != NULL);

}

/**
 * go_next - go to the next comm_and line stored
 *
 * @list_s: separ_ator list
 * @list_l: comm_and line list
 * @datash: data structure
 * Return: void
 */
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int loop_sep;
	sep_list *ls_s;
	line_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - splits com_mand lines accor_ding to
 * the separators ;, | and &, and executes them
 *
 * @datash: data structure
 * @input: input str
 * Return: 0 to exit, 1 to continue
 */
int split_commands(data_shell *datash, char *input)
{

	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = split_line(datash->input);
		loop = exec_line(datash);
		free(datash->args);

		if (loop == 0)
			break;

		go_next(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_line_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - tokenizes the input str
 *
 * @input: input str.
 * Return: str splitted.
 */
char **split_line(char *input)
{
	size_t buffsize;
	size_t x;
	char **tokens;
	char *token;

	buffsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (buffsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (x= 1; token != NULL; x++)
	{
		if (x == buffsize)
		{
			buffsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, x, sizeof(char *) * buffsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[x] = token;
	}

	return (tokens);
}
