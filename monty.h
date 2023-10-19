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
 * struct glob_opcode_s - global variable for opcode, value and line number
 * @args: the second argument after opcode in the bytecode i.e:push 1
 * @opcode: the actual opcode e.g: pop, push
 * @line_no: line number for each opcode
 *
 * Description: to be declared as a global variable for opcode, value & line no
 */
typedef struct glob_opcode_s
{
	char *opcode;
	char *arg;
	unsigned int line_no;
} glob_opcode_t;
/*to be declared as an external variable*/
extern glob_opcode_t g_opcode;

/*TOKENIZER FAMILY*/
char *parse_arg(char *arg_token);
void tokenize_line(char *line, char **opcode, char **arg);
void trim_whitespace(char *str);

/** function pointer*/
void get_opfunc(char *opcode, stack_t **stack, unsigned int line_number);


/*helper functions*/
char *_strdup(char *str);
#endif /*_MONTY_H*/
