#include "monty.h"
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
	/*Tokenize the line to extract opcode and argument*/
	token = strtok(line, " \n\t");
	if (token == NULL)
		return; /*to skip empty lines*/
	*opcode = _strdup(token);/*else when token != NULL*/
	if (*opcode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*get other part ---> arg, thru arg token*/
	arg_token = strtok(NULL, " \n\t");
	if (arg_token != NULL)
		*arg = parse_arg(arg_token);/*save it into *arg*/
	else
	{
		*arg = _strdup("");/*no argument? alloc empty str*/
		if (*arg == NULL)
		{
			free(*opcode);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
}

