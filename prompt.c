#include "s_shell.h"
/**
 * _prompt - prompt
*/
void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "KBS$ ", 5);
}
/**
 * han_cmd_func - handle commands
 * @sig: int to handle
*/
void han_cmd_func(int sig)
{
	signal(sig, SIG_IGN);
	write(STDERR_FILENO, "\n", 1);
	_prompt();
	signal(SIGINT, han_cmd_func);
}
/**
 * main_chk - checker for main
 * @pid: to check
 * @cmd: command to check
*/
void main_chk(int pid, char **cmd)
{
	char *doc = NULL;

	doc = rec_env(cmd[0]);
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, 0, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (doc == NULL)
		{
			printf("Command not found\n");
		}
		else if (execve(doc, cmd, environ) == -1)
		{
			perror("hsh");
			fflush(stdout);
			free(cmd);
			exit(1);
		}
		exit(EXIT_FAILURE);
	}
}

