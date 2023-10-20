#include "monty.h"
/**
 * sub - function subtracts the top element
 *  of the stack from the second top element of the stack
 *  result = second_top - top, has no return type
 * @stack: double pointer to the top of the stack
 * @line_number: This keeps track of the line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int top, second_top, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = (*stack)->n;
		second_top = (*stack)->next->n;
		result = second_top - top;
		(*stack)->next->n = result;
		pop(stack, line_number);
	}
}
/**
 * div_op - function divides the second top element
 *  of the stack by the top element of the stack.
 *  result = second_top / top
 *  @stack: double pointer pointing to the stack
 *  @line_number: keeps track of the line number in the stack
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	int top, second_top, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = (*stack)->n;
		second_top = (*stack)->next->n;
		result = second_top / top;
		(*stack)->next->n = result;
		pop(stack, line_number);
	}
}
/**
 * mul - function multiplies the second top element
 *  of the stack with the top element of the stack
 *  result = second_top * top
 * @stack: a pointer to a pointer pointing to the stack
 * @line_number: keeps track of the line number in the stack
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int top, second_top, result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		top = (*stack)->n;
		second_top = (*stack)->next->n;
		result = second_top * top;
		(*stack)->next->n = result;
		pop(stack, line_number);
	}
}
/**
 * mod - function computes the rest of the division
 *  of the second top element of the stack by
 *   the top element of the stack.
 *   result = second_top % top
 * @stack: a double pointer to the stack
 * @line_number: this keeps track of the line number in the stack
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int top, second_top, result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	if (top == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
		second_top = (*stack)->next->n;
		result = second_top % top;
		(*stack)->next->n = result;
		pop(stack, line_number);
}
