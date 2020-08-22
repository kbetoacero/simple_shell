#include "shell.h"
/**
 * main - Receive input and implement arguments
 * Return: 0 or 1
 */
int main(void)
{
	char *argv[5], *tok, *buffer;
	pid_t child;
	int status, x = 0;

	signal(SIGINT, _sigign);
	while (1)
	{
		argv[0] = NULL, buffer = NULL, tok = NULL, x = 0;
		buffer = prompt();
		tok = strtok(buffer, TOK_DELIM);
		do {
			argv[x] = _strdup(tok);
			x++;
			tok = strtok(NULL, TOK_DELIM);
		} while (tok != NULL);
		argv[x] = NULL;
		if (argv != NULL && argv[0] != NULL)
		{
			built(argv[0]);
			argv[0] = fndpath(argv[0]);
			child = fork();
			if (child < 0)
				perror("Error");
			if (child == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error");
					exit(1);
				}
			}
			wait(&status);
		}
		free(buffer);
		free(tok);
	}
	free(buffer);
	return (0);
}
