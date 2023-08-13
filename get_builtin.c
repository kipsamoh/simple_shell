#include "main.h"

/**
 * get_builtin - pair the builtin to args
 * @cmd: command argument
 * Return: function ptr of the builtin cmd
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int x;

	for (x = 0; builtin[x].name; x++)
	{
		if (_strcmp(builtin[x].name, cmd) == 0)
			break;
	}

	return (builtin[x].f);
}
