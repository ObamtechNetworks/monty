#include "monty.h"
/**
 * free_arg - frees resource by push
 * @stack: frees the stack;
 * @line_no: reference line number for error
 * Return: void
 */
void free_arg(stack_t **stack, unsigned int line_no)
{
	free_globals();
	free_stack(*stack);
	free_ln_cls_fd();
	fprintf(stderr, "L%d: usage: push integer\n", line_no);
	exit(EXIT_FAILURE);
}
/**
 * check_arg - checks for validity of glob_ar
 * @arg: the global to check validity of each char during push call
 * Return: void
 */
int check_arg(char *arg)
{
	int i = 0;
	/*if arg is not digit and not neg or positive*/
	if (arg == NULL || *arg == '\0')
	{
		return (-1);
	}
	for (i = 0; arg[i] != '\0'; i++)
	{
		/*if arg is not digit and not neg or positive*/
		if (!isdigit(arg[i]) && arg[i] != '-')
		{
			return (-1);
		}
	}
	return (0);
}
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
	/*if arg is not digit and not neg or positive*/
	if (check_arg(glob_var.arg) == -1)
	{
		free_arg(stack, line_number);
	}
	value = atoi(glob_var.arg);
	/*create a new stack node and push value onto the stack*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
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
