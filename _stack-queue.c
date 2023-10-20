#include "monty.h"
/**
 * _stack - sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * @stack: pointr to the head of the stack
 * @line_number: opcode line number
 * Return: nothing
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/*set data format to LIFO*/
	glob_var.LIFO_FIFO = 1;
}
/**
 * _queue - sets the format of the data to a queue (FIFO).
 * Order of data become first in first out
 * @stack: pointr to the head of the stack dbly linked list
 * @line_number: opcode line number
 * Return: nothing
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/*set data format to FIFO*/
	glob_var.LIFO_FIFO = 0;
}
