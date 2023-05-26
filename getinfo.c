#include "shell.h"

/**
 * clear_information - initializes information_t struct
 * @information: struct address
 */
void clear_information(information_t *information)
{
	information->arg = NULL;
	information->argv = NULL;
	information->path = NULL;
	information->argc = 0;
}

/**
 * set_information - initializes information_t struct
 * @information: struct address
 * @av: argument vector
 */
void set_information(information_t *information, char **av)
{
	int i = 0;

	information->fname = av[0];
	if (information->arg)
	{
		information->argv = strtow(information->arg, " \t");
		if (!information->argv)
		{

			information->argv = malloc(sizeof(char *) * 2);
			if (information->argv)
			{
				information->argv[0] = _strdup(information->arg);
				information->argv[1] = NULL;
			}
		}
		for (i = 0; information->argv && information->argv[i]; i++)
			;
		information->argc = i;

		replace_alias(information);
		replace_vars(information);
	}
}

/**
 * free_information - frees information_t struct fields
 * @information: struct address
 * @all: true if freeing all fields
 */
void free_information(information_t *information, int all)
{
	ffree(information->argv);
	information->argv = NULL;
	information->path = NULL;
	if (all)
	{
		if (!information->cmd_buf)
			free(information->arg);
		if (information->env)
			free_list(&(information->env));
		if (information->history)
			free_list(&(information->history));
		if (information->alias)
			free_list(&(information->alias));
		ffree(information->environ);
			information->environ = NULL;
		bfree((void **)information->cmd_buf);
		if (information->readfd > 2)
			close(information->readfd);
		_putchar(BUF_FLUSH);
	}
}
