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
	free(buf);
	free(cmd);
	return (0);
}
