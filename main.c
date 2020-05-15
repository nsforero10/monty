#include "monty.h"
gvar_t gvar;

/**
 * frees - free everything on the program
 * Return: nothing
 */
void frees(void)
{
	stack_t *crnt = gvar.h, *tmp = NULL;

	if (gvar.buff)
		free(gvar.buff);
	if (gvar.file)
		fclose(gvar.file);
	while (crnt)
	{
		tmp = crnt;
		crnt = crnt->next;
		free(tmp);
	}
}

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
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
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
 * main - main function
 * @ac: argument count
 * @av: argument values
 * Return: EXIT_SUCCESS on Success, EXIT_FAILURE on fail
 */
int main(int ac, char **av)
{
	char *opname;

	void (*funct)(stack_t **, unsigned int) = NULL;

	gvar.line_number = 1;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		frees();
		return (EXIT_FAILURE);
	}

	gvar.file = fopen(av[1], "r");

	if (!gvar.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		frees();
		return (EXIT_FAILURE);
	}
	while (getline(&gvar.buff, &gvar.sz, gvar.file) != EOF)
	{
		opname = strtok(gvar.buff, " \n\t");
		if (opname)
		{
			funct = get_opp(opname);
			if (funct != NULL)
				funct(&gvar.h, gvar.line_number);
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", gvar.line_number, opname);
				frees();
				return (EXIT_FAILURE);
			}
		}
		gvar.line_number++;
	}
	frees();
	return (EXIT_SUCCESS);
}
