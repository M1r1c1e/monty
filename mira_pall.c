#include "monty.h"
#include <stdio.h>
#include "stdlib.h"
/**
 * pall - printing all element in a stack.
 * @prog_stack: a pointer that is pointing to another pointer
 *pointing to the top node of a prog_stack
 * @line_counter: the number of line of an opcode
 * which is converted to integer
 */

void pall(stack_t **prog_stack, unsigned int line_counter)
{
	stack_t *tempo_p;

	tempo_p = *prog_stack;
	(void)line_counter;

	if (prog_stack == NULL)
	{
		exit(EXIT_FAILURE); /*exit program*/
	}
	while (1)
	{
		if (tempo_p == NULL)
		{
			break; /*exit loop*/
		}
		fprintf(stdout, "%d\n", tempo_p->n);
		tempo_p = tempo_p->next;
	}
}

