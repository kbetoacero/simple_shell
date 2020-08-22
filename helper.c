#include "shell.h"
/**
 * builtin - Structure for builtin functions
 * @s: Char of format spec
 * Return: function
 */
int built(char *s)
{
	int i = 0;

	cmnd_t comms[] = {
		{"env", printenv},
		{"exit", exitkbshell},
		{NULL, NULL}
	};

	while (comms[i].arg != NULL)
	{
		if (_strcmp(comms[i].arg, s) == 0
				&& (_strlen(comms[i].arg) == _strlen(s)))
			return (comms[i].func());
		i++;
	}
	return (1);
}
