#include "monty.h"

/**
*_isdigit - checks is a character is lowercase
*@caracter: the character that will be checked
*
*Return: 1 if is lowercase, 0 otherwise
*/
int _isdigit(int caracter)
{
	int resultado;

	if (caracter >= '0' && caracter <= '9')
		resultado = 1;
	else
		resultado = 0;
	return (resultado);
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
