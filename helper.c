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
/**
 * fndpath - Find the path for a specific command
 * @name: Command
 * Return: Path name ending in command
 */
char *fndpath(char *name)
{
        const char *path = "PATH";
        char *value, *tok;
        char *dir[8];
        struct stat statbuff;
        int num = 0;

        value = _getenv(path);
        tok = strtok(value, TOK_DELIM);
        do {
                dir[num] = NULL;
                dir[num] = _strdup(tok);
                dir[num] = str_concat(dir[num], name);
                if (name[0] == '/')
                        break;
                if (_strcmp(name, "./") == 0)
                        break;
                if (stat(dir[num], &statbuff) == 0)
                {
                        free(value);
                        return (dir[num]);
                }
                else
                        num++;
                tok = strtok(NULL, TOK_DELIM);
        } while (tok != NULL);
        free(dir[num]);
        free(value);
        return (name);
}
