#include "s_shell.h"

/**_prompt - prompt                                                                  
                                                                                     */
void _prompt(void)
{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$>", 3); /*printf"$ ");*/
}
