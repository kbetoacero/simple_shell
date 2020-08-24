#include "shell.h"
/**
 * prompt - print a prompt and Receive arguments form standard input
 * Return: 0
 */
char *prompt(void)
{
	char *buffer;
	int check;
	size_t length = 1;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "KBSH$ ", 6);
	buffer = malloc(sizeof(char) * length);
	if (buffer == NULL)
	{
		perror("Error");
	}
	while (1)
	{
		check = getline(&buffer, &length, stdin);
		if (check == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		return (buffer);
	}
	perror("Error");
}
