
#ifndef MONTY_MONTY_H
#define MONTY_MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_vars - global var structure
 * @file: stream of the read file
 * @buff: saves the content iven by the getline
 * @sz: size of the read line
 * @instuctions: the array of instructions
 * @h: head of the linked list
 * @line_number: the current line that is being read
 *
 * Description: Stores global informations for the program
 */
typedef struct global_vars
{
	FILE *file;
	char *buff;
	size_t sz;
	instruction_t *instuctions;
	stack_t *h;
	unsigned int line_number;
} gvar_t;

/* MAIN FUNCTIONS PROTOTYPES*/

void (*get_opp(char *opcode))(stack_t **stack, unsigned int line_number);

/* OPERATIONS FUNCTIONS PROTOTPYES*/

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);

/* AUXILIAR FUNCTIONS*/

int _isdigit(int caracter);
void frees(void);

#endif /* MONTY_MONTY_H */
