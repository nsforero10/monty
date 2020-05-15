#include "monty.h"

/**
 * push - push a element to the stack
 * @stack: double linked list for the stack
 * @line_number: the number of the current line
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *strnum = NULL;
	unsigned int i = 0;
	int neg = 1;
	stack_t *new = NULL, *crnt;

	strnum = strtok(NULL, " /n/r/t");
	if (!strnum)
		fprintf(stderr, "L%u: usage: push integer\n", line_number),
		frees(), exit(EXIT_FAILURE);
	if  (strnum[0] == '-')
		neg = -1, strnum++;
	while (strnum[i] != '\000' && strnum[i] != '\n')
	{
		if (_isdigit(strnum[i]) == 0)
		{
			if (i == 0)
				fprintf(stderr, "L%u: usage: push integer\n", line_number),
				frees(), exit(EXIT_FAILURE);
			else
				strnum[i] = '\000';
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
		fprintf(stderr, "Error: malloc failed\n");
	new->n = neg * atoi(strnum);
	new->next = NULL;
	if (!*stack)
		new->prev = NULL, *stack = new;
	else
	{
		crnt = *stack;
		while (crnt->next)
			crnt = crnt->next;
		new->prev = crnt;
		crnt->next = new;
	}
}

/**
 * pall - prints all elements of the stack
 * @stack: double linked list for the stack
 * @line_number: the number of the current line
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *crnt = *stack;

	(void) line_number;
	while (crnt)
		fprintf(stdout, "%d\n", crnt->n), crnt = crnt->next;
}
