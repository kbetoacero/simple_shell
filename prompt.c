#include "s_shell.h"

/**_prompt - prompt                                                                  
                                                                                     */
void _prompt(void)
{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$>", 3); /*printf"$ ");*/
}
/* main_chk - checker for main
 * @pid: to check
 * @cmd: command to check
*/
void main_chk(int pid , char **cmd)
{
	char *cm = NULL;

	cm = rec_env(cmd[0]);
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, 0, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (cm == NULL)
		{
			printf("Command not found\n");
		}
		else if (execve(cm, cmd, environ) == -1)
		{
			perror("hsh");
			fflush(stdout);
			free(cmd);
			exit(1);
		}
		exit(EXIT_FAILURE);
	}
}
