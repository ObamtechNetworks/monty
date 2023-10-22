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
		if (!isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
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
	stack_t *new_node = NULL, *last_node = NULL;
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
		free_globals();
		free_ln_cls_fd();
		free_stack(*stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (glob_var.LIFO_FIFO == 1)
	{
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		if (*stack == NULL)
			*stack = new_node;
		else
		{
			last_node = *stack;
			while (last_node->next != NULL)
				last_node = last_node->next;
			last_node->next = new_node;
			new_node->prev = last_node;
		}
	}
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
/**
 * pchar - prints the ascii value of the integer at the top of the stack
 * @stack: pointer to the doubly linked list
 * @line_number: the line number in the opcode
 * Usage: pchar
 * Description: the integer stored at the top of the
 * stack is treated as the ascii value
 * of the character to be printed
 * EDGE CASE: caters for -->empty stack, invalid ascii value
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	/*check if teh stack is empty*/
	if (stack == NULL || *stack == NULL)
	{
		free_globals();/*free the global variables*/
		free_stack(*stack);/*free the stack*/
		free_ln_cls_fd();/*close the file stream descriptor*/
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	/** check the integer at the stack if within valid ascii range*/
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		/*print the ascii equivalent of the int at stack top*/
		printf("%c\n", (*stack)->n);
	}
	else
	{
		free_globals();/*free the global variables*/
		free_stack(*stack);/*free the stack*/
		free_ln_cls_fd();/*close the file stream descriptor*/

		/*throw the error at the given line*/
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}
}
