#include "shell.h"
/**
 * prompt - print a prompt and Receive arguments form standard input
 * Return: 0
 */
char *prompt(void)
{
	char *buffer;
	int check;
	size_t length = 1;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "KBSH$ ", 6);
	buffer = malloc(sizeof(char) * length);
	if (buffer == NULL)
	{
		perror("Error");
	}
	while (1)
	{
		check = getline(&buffer, &length, stdin);
		if (check == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		return (buffer);
	}
	perror("Error");
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
