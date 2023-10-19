#include "monty.h"
/**
 * push - pushes item to the top of the stack
 * @stack: the stack list
 * @line_number: line number for opcodes in the monty bytecodes.m
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value = 0;
	stack_t *new_node = NULL;
	char *arg_cpy = NULL; /*for a copy of the arg from strtok*/
	/*check if arg from byte code is valid*/
	/*if arg is not digit and not neg or positive*/
	if (g_opcode.arg == NULL || (!isdigit(g_opcode.arg[0])
				&& g_opcode.arg[0] != '-'
				&& g_opcode.arg[0] != '+'))
	{
		if (arg_cpy != NULL)
			free(arg_cpy);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	arg_cpy = _strdup(g_opcode.arg);/*makes cpy of the arg saved frm strtok*/
	if (arg_cpy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	value = atoi(arg_cpy);
	/*create a new stack node and push value onto the stack*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(arg_cpy);/*free allocated memory for arg_cpy*/
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*SET DATA FOR NEW NODE*/
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	/*set head of stack*/
	*stack = new_node;
	free(arg_cpy); /*freed the argcpy*/
}
/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: the stack linked list structure
 * @line_number: line number for opcodes in the monty bytecodes.m
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
