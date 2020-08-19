#include "s_shell.h"
/**
 * splt - split in tokens
 * @raw_cmd: to split
 * @limit: limit
 * Return: cmd
*/
char **splt(char *raw_cmd, char *limit)
{
	char	*ptr = NULL;
	char	**cmd = NULL;
	size_t	index = 0;

	ptr = strtok(raw_cmd, limit);
	cmd = malloc(1024);
	if (!cmd)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	while (ptr)
	{
		cmd[index] = strdup(ptr);
		ptr = strtok(NULL, limit);
		++index;
	}
	cmd[index] = NULL;
	return (cmd);
}
