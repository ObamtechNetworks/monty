#ifndef _MONTY_H
#define _MONTY_H

/** C standard libary **/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_vars - global variable for opcode, value and line number
 * @arg: the second argument after opcode in the bytecode i.e:push 1
 * @file: file stream
 * @rd_line: to store lines read from geline()
 * @opcode: the actual opcode e.g: pop, push
 * @line_no: line number for each opcode
 *
 * Description: to be declared as a global variable for opcode, value & line no
 */
typedef struct glob_vars
{
	char *opcode;
	char *arg;
	char *rd_line;
	FILE *file;
	unsigned int line_no;
} glob_t;
/*to be declared as an external variable*/
extern glob_t glob_var;

/** opcode functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void trim_whitespace(char *str);

/** more opcode functions */
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/*TOKENIZER FAMILY*/
char *parse_arg(char *arg_token);
void tokenize_line(char *line, char **opcode, char **arg);
void trim_whitespace(char *str);

/** function pointer*/
void get_opfunc(char *opcode, stack_t **stack, unsigned int line_number);

/*helper functions*/
char *_strdup(char *str);

/** FREE RESOURCES */
void free_globals(void);
void free_ln_cls_fd(void);
void free_stack(stack_t *stack);
#endif /*_MONTY_H*/
