#include "main.h"

/**
 * error_env - error msg for environment in get_env.
 * @datash: relevant data(counter, arguments)
 * Return: error msg.
 */
char *error_env(data_shell *datash)
{
	int leng_th;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	leng_th = _strlen(datash->av[0]) + _strlen(ver_str);
	leng_th += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (leng_th + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - error msg for & failure denied permission.
 * @datash: relevant data (counter, arguments).
 *
 * Return: The error str.
 */
char *error_path_126(data_shell *datash)
{
	int leng_th;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(datash->counter);
	leng_th = _strlen(datash->av[0]) + _strlen(ver_str);
	leng_th += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (leng_th + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
