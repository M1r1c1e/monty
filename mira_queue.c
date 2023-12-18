#include "monty.h"

/**
 * queue -function that adds a node to the queue.
 * @creatednode: a Pointer that points to the new node.
 * @line_counter: the line number of the opcode
 */

void queue(stack_t **creatednode, unsigned int line_counter)
{
	(void)line_counter;

	if (creatednode == NULL || *creatednode == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *creatednode;
	}
	else
	{
		stack_t *tail = head;

		while (tail->next != NULL)
			tail = tail->next;
		tail->next = *creatednode;
		(*creatednode)->prev = tail;
	}
}

