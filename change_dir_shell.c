#include "main.h"

/**
 * cd_shell - effects changes to current directory
 *
 * @datash: relevant  data 
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *dir;
	int is_home, is_home2, is_ddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		is_home = _strcmp("$HOME", dir);
		is_home2 = _strcmp("~", dir);
		is_ddash = _strcmp("--", dir);
	}

	if (dir == NULL || !is_home || !is_home2 || !is_ddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
