#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the doubly linked list
 * @line_number: the line number in the opcode
 * Usage: pstr
 * Description: the integer stored at the top of the
 * stack is treated as the ascii value
 * of the character to be printed
 * EDGE CASE: caters for -->empty stack, invalid ascii value
 * string stops when either --> stack is over, value of element is 0
 * the value of the element is not in the ascii table
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	(void)line_number;
	/*check if teh stack is empty*/
	if (stack == NULL || *stack == NULL)
	{
		/*print only new line*/
		printf("\n");
		return;
	}
	temp = *stack;
	/** check the integer at the stack if within valid ascii range*/
	while (temp != NULL && temp->n != 0 &&
			temp->n >= 0 && temp->n <= 127)
	{
		/*print the ascii equivalent of the int at stack top*/
		printf("%c", temp->n);
		temp = temp->next; /*move to the next*/
	}
	printf("\n");
}
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the doubly linked list
 * @line_number: the line number for opcodes
 * Usage: rotl
 * Description: the top element of the stack
 * becomes the last one, and the second
 * top element of the stack becomes the first one
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last_node = NULL, *top = NULL, *temp_top = NULL;

	(void)line_number;

	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		last_node = *stack;
		top = *stack;
		temp_top = top->next;

		/*move to the end of the stack to get the last elem*/
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		/*change the value of the element at the top*/
		last_node->next = top;
		top->prev = last_node;
		top->next->prev = temp_top;
		top->next = NULL;
		*stack = temp_top;
	}
	else
		return;
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the doubly linked list
 * @line_number: the line number for opcodes
 * Usage: rotl
 * Description: the last element of the stack
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *current = NULL, *next = NULL;

	(void)line_number;
	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		temp = NULL;
		current = *stack;

		/*loop to reverse the stack*/
		while (current != NULL)
		{
			next = current->next;
			current->next = temp;
			current->prev = NULL;
			if (temp != NULL)
				temp->prev = current;
			temp = current;
			current = next;
		}
		/*update pointer head*/
		*stack = temp;
	}
	else
		return;
}
