#include "s_shell.h"


void _prompt(void)
{
	char *buffer;
	size_t buffersize = 32;

	buffer = malloc(buffersize * sizeof(char));

	if (buffer)
	{
	write(STDOUT_FILENO, "$>", 2); /*printf"$ ");*/
	}
}
