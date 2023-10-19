#define _GNU_SOURCE
#include "monty.h"
glob_t glob_var = {NULL, NULL, NULL, NULL, 1};
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
 * main - Entry point
 * @argc: number of commandline arguments
 * @argv: each command line arguments (each token)
 * Return: 0 Always (success)
 */
int main(int argc, char **argv)
{
	char *bytecode = NULL;
	size_t len = 0;
	ssize_t bytes_read = 0;
	stack_t *stack = NULL; /*the head of the stack variable*/
	/** handle input from user */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} /*set file stream to be second CLI argument*/
	bytecode = argv[1];
	glob_var.file = fopen(bytecode, "r");/** open the file for reading*/
	if (glob_var.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", bytecode);
		exit(EXIT_FAILURE);
	} /*call read_byte_code function in an infinite loop*/
	while (1)
	{
		bytes_read = read_byte_code(&glob_var.rd_line,
				&len, glob_var.file);
		if (bytes_read == -1)
			break; /* break out of loop*/
		tokenize_line(glob_var.rd_line,
				&glob_var.opcode, &glob_var.arg);
		/*check if parsing was successful*/
		if (glob_var.opcode != NULL && glob_var.arg != NULL)
		{ /*call the get_opfunc on the glob_opcode and arg*/
			get_opfunc(glob_var.opcode, &stack, glob_var.line_no);
			glob_var.line_no++;/*incr. line_no to read next line*/
		}
		else
			glob_var.line_no++;/*ignore empty lines*/
		/*free before moving to next line*/
		free_globals();
	}
	free_globals();
	free_ln_cls_fd();
	free_stack(stack); /*free the stack*/
	return (EXIT_SUCCESS);
}
