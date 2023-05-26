#include "shell.h"

/**
 * interact - returns true if shell is interactive mode
 * @information: struct address
 *
 * Return: 1 if interact mode, 0 otherwise
 */
int interact(information_t *information)
{
	return (isatty(STDIN_FILENO) && information->readfd <= 2);
}

/**
 * isdelim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int isdelim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha1 - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha1(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *z)
{
	int i, zign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (z[i] == '-')
			sign *= -1;

		if (z[i] >= '0' && z[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (z[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (zign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
