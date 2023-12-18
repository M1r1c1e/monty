#include "monty.h"
#include <ctype.h>
#include <stdio.h>

/**
 * progfunction - calls the execution functions.
 * @opcode: the opcode string.
 * @comd: program value.
 * @line_counter: opcode Line number.
 * @f: type of typedef
 * @fomat_spercifer: Format specifier for either stack or queue
 */

void func_perform(operation_func f, char *opcode,
		char *comd, int line_counter, int fomat_spercifer);
void progfunction(char *opcode, char *comd,
		int line_counter, int fomat_spercifer)
{
	int i = 0;

	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	while (functions[i].opcode != NULL)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
		{
			func_perform(functions[i].f, opcode, comd,
					line_counter, fomat_spercifer);
			return;
		}
		i++;
	}

	error_mes(3, line_counter, opcode);
}

/**
 * func_perform - Finding the performing function.
 * @f: function called pointer.
 * @opcode: the opcode string.
 * @comd: a String numeric value.
 * @line_counter: the Line number.
 * @fomat_spercifer: program format specifier.
 */
void func_perform(operation_func f, char *opcode,
		char *comd, int line_counter, int fomat_spercifer)
{
	stack_t *node;
	int val = atoi(comd);

	if (strcmp(opcode, "push") == 0)
	{
		if (comd == NULL || !isdigit(*comd))
		{
			error_mes(5, line_counter);
		}

		if (comd[0] == '-')
		{
			val *= -1;
		}

		node = creatednode(val);

		if (fomat_spercifer == 0)
			f(&node, line_counter);
		else if (fomat_spercifer == 1)
			queue(&node, line_counter);
	}
	else
	{
		f(&head, line_counter);
	}
}

