#include "monty.h"
/**
 * pint - pint opcode prints the value of
 *  the top of the stack followed by a new line
 *  has no return type
 * @stack:  a double pointer to the stack
 * @line_number: used to keep track of the line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
/*
 * A few issue of concern.
 * pint should not have any argument after the command
 * pint should throw an error incase the stack is empty
 * pint should print only the value of the top of stack
 * this should be followed by a new line
 */

	if (*stack == NULL)
	{
		free_globals();
		free_ln_cls_fd();
		free_stack(*stack);
		/* throw an error */
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
/**
 * nop - nop opcode doex not do anything
 * has no return type
 * @stack: a double pointer to the stack
 * @line_number: used to keep track of the line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * pop - function removes the top element from the stack
 * @stack: a double pointer pointing to the top of the stack
 * @line_number: used to keep track of the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		free_globals();
		free_ln_cls_fd();
		free_stack(*stack);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		ptr = *stack;
		*stack = (*stack)->next;
		free(ptr);
	}
}
/**
 * swap - function that swaps the top two elements of the stack
 * @stack: a double pointer pointing to the top of the stack
 * @line_number: used to keep track of the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer;
	int temp_holder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_globals();
		free_ln_cls_fd();
		free_stack(*stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		pointer = *stack;
		temp_holder = (pointer)->n;
		(pointer)->n = (pointer)->next->n;
		(pointer)->next->n = temp_holder;
	}
}
/**
 * add - function adds the top two elements of the stack
 * @stack: a double linked list pointint to the stack
 * @line_number: used to keep track of the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int top, second_top, total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_globals();
		free_ln_cls_fd();
		free_stack(*stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = (*stack)->n;
		second_top = (*stack)->next->n;
		total = top + second_top;
		(*stack)->next->n = total;
		pop(stack, line_number);
	}
}
