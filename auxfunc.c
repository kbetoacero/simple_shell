#include "shell.h"
/**
 * _strlen - Print the length of the string
 * @s: string
 * Return: lenght of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

/**
 * *_strdup - Returns a pointer to a new string
 * @str: Starting char in string
 * Return: s.
 */
char *_strdup(char *str)
{
	char *s;
	int i;

	if (str == NULL)
		return (NULL);

	s = malloc((_strlen(str) + 1) * sizeof(char));

	if (s != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
			s[i] = str[i];
		s[i] = '\0';
	}
	return (s);
}
/**
 * *str_concat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 * Return: str.
 */
char *str_concat(char *s1, char *s2)
{
	char *str;
	int i;
	int n = 0;
	int len1, len2;

	if (s1 == NULL)
		len1 = 0;
	else
		len1 = _strlen(s1);
	if (s2 == NULL)
		len2 = 0;
	else
		len2 = _strlen(s2);

	str = malloc((len1 + len2 + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		str[i] = s1[i];
	str[i] = '/';
	i++;
	for (n = 0; n < len2; n++, i++)
		str[i] = s2[n];
	str[i] = '\0';
	free(s1);
	return (str);
}

/**
 * _strcmp - Compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: string copied
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] == s2[i]) && s1[i])
		i++;
	if (s2[i])
		return (s1[i] - s2[i]);
	else
		return (0);
}
/**
 * fndpath - Find the path for a specific command
 * @name: Command
 * Return: Path name ending in command
 */
char *fndpath(char *name)
{
        const char *path = "PATH";
        char *value, *tok;
        char *dir[8];
        struct stat statbuff;
        int num = 0;

        value = _getenv(path);
        tok = strtok(value, TOK_DELIM);
        do {
                dir[num] = NULL;
                dir[num] = _strdup(tok);
                dir[num] = str_concat(dir[num], name);
                if (name[0] == '/')
                        break;
                if (_strcmp(name, "./") == 0)
                        break;
                if (stat(dir[num], &statbuff) == 0)
                {
                        free(value);
                        return (dir[num]);
                }
                else
                        num++;
                tok = strtok(NULL, TOK_DELIM);
        } while (tok != NULL);
        free(dir[num]);
        free(value);
        return (name);
}
