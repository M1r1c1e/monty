#include "monty.h"

/**
 * push- function that add new node to an empty stack and
 * arranging non-empty node
 * @creatednode: additional node pointer
 * @line_counter:  the number of line of an
 * opcode which is converted to integer
 */

void push(stack_t **creatednode, unsigned int line_counter)
{
	(void) line_counter;
	if (creatednode == NULL || *creatednode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *creatednode;
	}
	else
	{
		(*creatednode)->next = head;
		head->prev = *creatednode;
		head = *creatednode;
	}
}

