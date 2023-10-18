# Monty Project | C - Stacks, Queues - LIFO, FIFO
Welcome to our GitHub project focused on mastering fundamental data structures in C programming: Stacks and Queues. In this collaborative effort between two dedicated developers, we explore the intricacies of Last In, First Out (LIFO) and First In, First Out (FIFO) data structures. But that's not all - our real challenge lies in the creation of a custom Monty interpreter, where the worlds of stacks, queues, and interpreting code collide.

# What to Expect:

### Stacks and Queues Mastery:
Here we delve deep into the world of stacks (Last In, First Out) and queues (First In, First Out). Learnt and understood implementation using *doubly linked lists*, advantages, and use cases in various scenarios.

### Monty Interpreter: Witness the magic of interpreting code!
We are crafting a custom Monty interpreter, a tool that reads and executes Monty bytecode files. With stacks and queues at its core, this interpreter promises to be a powerful tool for understanding and executing Monty code effortlessly.

### Collaborative Excellence:
This project represents the synergy between two passionate developers. Despite the challenges, our dedication to mastering C, data structures, and interpreters drives us forward. **Through collaboration and shared knowledge, we are building something exceptional.**

### Why This Project Matters:

Understanding data structures and interpreters is pivotal in computer science. With a solid grasp of stacks, queues, and interpreter design, you gain the ability to solve complex problems efficiently. By exploring and contributing to this project, you are not just enhancing your skills; you are also shaping the future of computing.

# AUTHORS
- [Ipadeola Michael Bamidele](https://github.com/ObamtechNetworks)
- [Josephine Wahu Wamiti](https://github.com/wahujos)

# DATA STRUCTURES
```
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
```
```
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
```

# Compilation & Output
Code is to be compiled this way:
`$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`

# How to use
`$ ./monty [*bytecodes.m*]`

# About the Monty Language:
Monty is an interpreted scripting language designed for simplicity and readability. Named after the legendary comedian Monty Python, it emphasizes code readability and clear syntax. Monty's code structure relies heavily on indentation, which enhances the readability of the language.

Developed by a community of programming enthusiasts, Monty combines elements from several programming languages, making it versatile and easy to learn. It supports object-oriented, imperative, and functional programming paradigms, offering developers the flexibility to choose their preferred style.

Monty's straightforward syntax and focus on readability make it an excellent choice for beginners and experienced developers alike. Its elegant design and ease of use have contributed to its popularity among programmers looking for a language that balances simplicity and functionality.

# How does Monty byte code files look like?

Files containing Monty byte codes usually have the *.m extension*. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
user@ubuntu~$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
user@ubuntu~$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
user@ubuntu~$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
user@ubuntu~$
```
### Instruction given by our school (ALX SE) as guide to building this project

# The monty program
### Usage: *[monty]* [file]
where *file* is the path to the file containing Monty byte code
If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
where <file> is the name of the file
If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number where the instruction appears.
Line numbers always start at 1
The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file
it finds an error in the file
an error occured
If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

*Thank You! :)*
