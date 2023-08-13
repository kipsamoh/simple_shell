#include "main.h"

/**
 * cmp_env_name - compares environment variables names
 * when the name are input.
 * @nenv:  environment name variable
 * @name: name input
 *
 * Return: 0 for equal. none 0 if different.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int x;

	for (x = 0; nenv[x] != '='; x++)
	{
		if (nenv[x] != name[x])
		{
			return (0);
		}
	}

	return (x + 1);
}

/**
 * _getenv - acquire environment variable
 * @name: environment variable name
 * @_environ: environment variable
 *
 * Return: environment variable value if found.
 * else returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int x, moving;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	moving = 0;
	/* Compares environment variables */
	/* environment is declared in the header file */
	for (x = 0; _environ[x]; x++)
	{
		/* when environments are equal */
		moving = cmp_env_name(_environ[x], name);
		if (moving)
		{
			ptr_env = _environ[x];
			break;
		}
	}

	return (ptr_env + moving);
}

/**
 * _env - output evironment variables
 *
 * @datash: relevant data.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int x, y;

	for (x = 0; datash->_environ[x]; x++)
	{

		for (y = 0; datash->_environ[x][y]; y++)
			;

		write(STDOUT_FILENO, datash->_environ[x], y);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
