#include "monty.h"
/**
 * parse_arg - parses the arg in case of NULL
 * @arg_token: the argument token to receive
 * Description: this is needed as an helper function
 * for the tokenize_line function to help manage cases when
 * argument is NULL, so that it can return an empty string
 * instead of returnning NULL
 * Return: dynamicall allocation of argument token
 */
char *parse_arg(char *arg_token)
{
	char *argument = NULL;

	if (arg_token == NULL)
	{
		argument = _strdup(""); /*retn an empty string for opt arg*/
		if (argument == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		argument = _strdup(arg_token);
		if (argument == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	return (argument);/*rtns dynamic alloc copy of arg*/
}
