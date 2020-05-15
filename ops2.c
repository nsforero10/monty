#include "monty.h"

/**
 * add - adds the first to elements of the stack
 * @stack: double linked list for the stack
 * @line_number: the number of the current line
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *crnt = *stack;

	(void) line_number;
	if (!*stack || !crnt->next)
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number),
			frees(), exit(EXIT_FAILURE);
	while (crnt->next)
		crnt = crnt->next;
	crnt->prev->n += crnt->n;
	crnt->prev->next = NULL;
	free(crnt);
}

/**
 * nop - does nothing
 * @stack: double linked list for the stack
 * @line_number: the number of the current line
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub - substracts the first to elements of the stack
 * @stack: double linked list for the stack
 * @line_number: the number of the current line
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *crnt = *stack;

	(void) line_number;
	if (!*stack || !crnt->next)
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number),
			frees(), exit(EXIT_FAILURE);
	while (crnt->next)
		crnt = crnt->next;
	crnt->prev->n -= crnt->n;
	crnt->prev->next = NULL;
	free(crnt);
}

/**
 * divide - substracts the first to elements of the stack
 * @stack: double linked list for the stack
 * @line_number: the number of the current line
 * Return: nothing
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *crnt = *stack;

	(void) line_number;
	if (!*stack || !crnt->next)
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number),
			frees(), exit(EXIT_FAILURE);
	while (crnt->next)
		crnt = crnt->next;
	if (crnt->n == 0)
		fprintf(stderr, "L%u: division by zero\n", line_number),
		frees(), exit(EXIT_FAILURE);
	crnt->prev->n /= crnt->n;
	crnt->prev->next = NULL;
	free(crnt);
}

/**
 * mul - multiplies the first to elements of the stack
 * @stack: double linked list for the stack
 * @line_number: the number of the current line
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *crnt = *stack;

	(void) line_number;
	if (!*stack || !crnt->next)
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number),
			frees(), exit(EXIT_FAILURE);
	while (crnt->next)
		crnt = crnt->next;
	crnt->prev->n *= crnt->n;
	crnt->prev->next = NULL;
	free(crnt);
}
