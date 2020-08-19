#include "s_shell.h"


void _prompt(void)
{
	char *buffer;
	size_t buffersize = 32;

	buffer = malloc(buffersize * sizeof(char));

	if (buffer)
	{
	write(STDOUT_FILENO, "$>", 3); /*printf"$ ");*/
	}
	free(buffer);
}
