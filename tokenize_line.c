#include "monty.h"
char *_strndup(const char *str, size_t n);
/**
 * tokenize_line - tokenizes the line read from getline
 * @line: the line read
 * @opcode: the opcode from strtok
 * @arg: the argument from strtok
 * Return: void
 */
void tokenize_line(char *line, char **opcode, char **arg)
{
	char *token = NULL, *arg_token = NULL;
	/* RESET g_opcode struct members*/
	if (*opcode != NULL)
	{
		free(*opcode);
		*opcode = NULL;
	}
	if (*arg != NULL)
	{
		free(*arg);
		*arg = NULL;
	}
	while (*line && isspace(*line))
		line++;

	token = line;
	while (*line && !isspace(*line))
		line++;
	*opcode = _strndup(token, line - token);

	while (*line && isspace(*line))
		line++;
	if (*line)
	{
		arg_token = line;
		while (*line && !isspace(*line))
			line++;
		*arg = _strndup(arg_token, line - arg_token);
	}
	else
		*arg = _strdup("");
}
/**
 * _strndup - duplicates n portion of a string
 * @str: the string to duplicate in memory
 * @n: number of bytes to collect from orig. str
 * Return: pointer to the duplicated bytes
 */
char *_strndup(const char *str, size_t n)
{
	char *dup = NULL;
	size_t len = strlen(str);

	if (n < len)
		len = n;

	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);

	strncpy(dup, str, len);
	dup[len] = '\0';

	return (dup);
}
