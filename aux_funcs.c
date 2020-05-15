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
