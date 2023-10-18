#include "monty.h"
/**
 * get_opfunc - gets the corresponding function for specific opcode
 * @opcode: the opcode to fetch it's corresponding function
 * @stack: the stack linked list implementation
 * @line_number: the opcode line number
 * Return: nothing
 */
void get_opfunc(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int size = sizeof(instructions) / sizeof(instructions[0]);
	int i = 0;

	for (i = 0; i < size; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	/* else error is handled*/
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
