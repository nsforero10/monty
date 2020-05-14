#include "monty.h"
gvar_t gvar;

/**
 * get_opp - get the function to handle the operation
 * @opcode: the operation identifier
 * Return: nothing
 */
void (*get_opp(char *opcode))(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall}
	};

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

/**
 * init_vars - sets the initial values to the global variable
 * @v: the global variable
 * Return: 0 on success, 1 on fail
 */

int init_vars(gvar_t *v)
{
	v->buff = NULL;
	v->line_number = 0;
	v->file = NULL;
	v->h = NULL;
	v->instuctions = NULL;
	v->sz = 0;
	return (0);
}

/**
 * main - main function
 * @ac: argument count
 * @av: argument values
 * Return: EXIT_SUCCESS on Success, EXIT_FAILURE on fail
 */
int main(int ac, char **av)
{
	char *opname;

	void (*funct)(stack_t **, unsigned int) = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	gvar.file = fopen(av[1], "r");

	if (!gvar.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
			/* code */
		return (EXIT_FAILURE);
	}
	while (getline(&gvar.buff, &gvar.sz, gvar.file) != EOF)
	{
		opname = strtok(gvar.buff, " \n\t\r");
		funct = get_opp(opname);

		if (funct != NULL)
		{
			funct(&gvar.h, gvar.line_number);
		}
		else
		{
			return (EXIT_FAILURE);
		}
		gvar.line_number++;
	}
	return (EXIT_SUCCESS);
}
