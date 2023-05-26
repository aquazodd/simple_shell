#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @information: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(information_t *information)
{
	if (!information->environ || information->env_changed)
	{
		information->environ = list_to_strings(information->env);
		information->env_changed = 0;
	}

	return (information->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(information_t *information, char *var)
{
	list_t *node = information->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			information->env_changed = delete_node_at_index(&(information->env), i);
			i = 0;
			node = information->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (information->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @information: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(information_t *information, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = information->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			information->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(information->env), buf, 0);
	free(buf);
	information->env_changed = 1;
	return (0);
}
