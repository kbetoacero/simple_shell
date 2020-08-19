#include "s_shell.h"
/**
 * main - function for simple shell
 * Return: Always 0
*/
int main(void)
{
	char *buf = NULL;
	pid_t pid;
	char	**cmd = NULL;
	size_t len;

	while (1)
	{
		_prompt();
		if (getline(&buf, &len, stdin) == EOF)
			{
			if (isatty(0) == 1)
				{
				write(STDOUT_FILENO, "\n", 1);
				break;
				}
			}
		cmd = splt(buf, " \n\t");
		if (cmd[0] == NULL)
		{
			free(cmd);
			continue;
		}
		if (strcmp(cmd[0], "exit") == 0)
			break;
		pid = fork();
		if (pid == -1)
			perror("fork error");
		else if (pid > 0)
		{
			waitpid(pid, 0, 0);
			kill(pid, SIGTERM);
		}
		else
		{
			if (execve(rec_env(buf), cmd, NULL) == -1)
			{
				perror("shell error");
			}
			exit(EXIT_FAILURE);
			}
	}
	fflush(stdout);
	return (0);
}
