#include "shell.h"
/**
 * env - Print environment
 * Return: 0
 */
int env(void)
{

	int line;

	for (line = 0; environ[line] != NULL; line++)
		printf("%s\n", environ[line]);
	return (0);
}

/**
 * exitkbshell - exits kbshell
 * Return: nothing
 */

int exitkbshell(void)
{
	exit(EXIT_SUCCESS);
}
