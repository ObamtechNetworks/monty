#define _GNU_SOURCE
#include "monty.h"
glob_opcode_t g_opcode = {NULL, NULL, 1};
/**
 * read_byte_code - reads bytecodes line by line
 * @line: the line to read into
 * @length: number of lines read
 * @stream: file stream to read from
 * Return: 0 for succes, -1 for error
 */
ssize_t read_byte_code(char **line, size_t *length, FILE *stream)
{
	/*variables to hold tokens */
	ssize_t lines_read = 0;

	/*read lines from getline*/
	lines_read = getline(line, length, stream);
	/*check return value from getine, -1 for error*/
	if (lines_read == -1)
		return (-1);
	/* 0 for success*/
	/*the returns values is for error handling*/
	return (0);
}
/**
 * free_g_opcode - frees the global opcode and its args for every iteration
 * Return: nothing
 */
void free_g_opcode(void)
{
	free(g_opcode.opcode);
	free(g_opcode.arg);
	g_opcode.opcode = NULL;
	g_opcode.arg = NULL;
}
/**
 * free_stack - frees the stack before exiting the program
 * @stack: the pointer to the head of the stack
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = NULL;
	stack_t *next = NULL;

	if (stack)
	{
		temp = stack;
		while (temp->next != NULL)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		free(temp);
	}
}
/**
 * main - Entry point
 * @argc: number of commandline arguments
 * @argv: each command line arguments (each token)
 * Return: 0 Always (success)
 */
int main(int argc, char **argv)
{
	char *line = NULL, *bytecode = NULL;
	size_t len = 0;
	ssize_t bytes_read = 0;
	FILE *file = NULL; /*file poitner to open file*/
	stack_t *stack = NULL; /*the head of the stack variable*/
	/** handle input from user */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} /*set file stream to be second CLI argument*/
	bytecode = argv[1];
	file = fopen(bytecode, "r");/** open the file for reading*/
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", bytecode);
		exit(EXIT_FAILURE);
	} /*call read_byte_code function in an infinite loop*/
	while (1)
	{
		bytes_read = read_byte_code(&line, &len, file);
		if (bytes_read == -1)
			break; /* break out of loop*/
		tokenize_line(line, &g_opcode.opcode, &g_opcode.arg);
		/*check if parsing was successful*/
		if (g_opcode.opcode != NULL && g_opcode.arg != NULL)
		{ /*call the get_opfunc on the g_opcode and arg*/
			get_opfunc(g_opcode.opcode, &stack, g_opcode.line_no);
			g_opcode.line_no++;/*increments line number to read next line*/
		}
		else
			g_opcode.line_no++;/*ignore empty lines*/
		/*free before moving to next line*/
		free_g_opcode();
	}
	free(line);/*free line read from getline*/
	fclose(file);
	free_g_opcode();
	free_stack(stack); /*free the stack*/
	return (EXIT_SUCCESS);
}
