#include "main.h"

/**
 * add_sep_node_end - adds a sep_arator found at the end
 * of a sep_list.
 * @head: linked list head.
 * @sep: separator found (; | &).
 * Return: head address.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - adds a cmd line at the end
 * of a line_list.
 * @head: linked list head.
 * @line: command line.
 * Return: head address.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_line_list - frees a line_list
 * @head: linked list head.
 * Return: void.
 */
void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}
