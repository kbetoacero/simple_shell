#include "s_shell.h"
/**
 * main - function for simple shell
 * Return: 0 Always
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
		signal(SIGINT, han_cmd_func);
		if (getline(&buf, &len, stdin) == EOF)
			{
			write(STDOUT_FILENO, "\n", 1);
				break;
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
		main_chk(pid, cmd);
	}
	fflush(stdout);
	free(cmd);
	free(buf);
	return (0);
}
