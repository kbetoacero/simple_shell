#include "s_shell.h"

/**
* _prompt - display a prompt and wait for user input
* Return: Void
*/


void _prompt(void)
{

	if (isatty(STDIN_FILENO))
		write(1, "KBS$> ", 6); /*printf"$ ");*/
}
