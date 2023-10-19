#include "monty.h"
/**
 * free_globals - frees the global opcode and its args for every iteration
 * Return: nothing
 */
void free_globals(void)
{
	/*free opcode alloc*/
	if (glob_var.opcode != NULL)
		free(glob_var.opcode);

	/*free arg alloc*/
	if (glob_var.arg != NULL)
		free(glob_var.arg);

	/*reset values*/
	glob_var.opcode = NULL;
	glob_var.arg = NULL;
}
/**
 * free_stack - frees the stack before exiting the program
 * @stack: the pointer to the head of the stack
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	/** free the stack*/
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
 * free_ln_cls_fd - frees line read and closes file
 * Return: nothing
 */
void free_ln_cls_fd(void)
{
	/*free line read from getline*/
	if (glob_var.rd_line != NULL)
		free(glob_var.rd_line);

	/*close file stream*/
	if (glob_var.file != NULL)
	{
		fclose(glob_var.file);
	}
}
