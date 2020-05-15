#include "monty.h"

/**
 * mod - substracts the first to elements of the stack
 * @stack: double linked list for the stack
 * @line_number: the number of the current line
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *crnt = *stack;

	(void) line_number;
	if (!*stack || !crnt->next)
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number),
			frees(), exit(EXIT_FAILURE);
	while (crnt->next)
		crnt = crnt->next;
	if (crnt->n == 0)
		fprintf(stderr, "L%u: division by zero\n", line_number),
		frees(), exit(EXIT_FAILURE);
	crnt->prev->n %= crnt->n;
	crnt->prev->next = NULL;
	free(crnt);
}
