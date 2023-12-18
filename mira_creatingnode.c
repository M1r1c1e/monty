#include "monty.h"

/**
 * creatednode - Creating a create_new node from data.
 * @n: data to create node from
 * Return: if successful point to a create_new node otherwise NULL.
 */
stack_t *creatednode(int n)
{
	stack_t *create_new = malloc(sizeof(stack_t));

	if (create_new == NULL)
	{
		error_mes(4);
		return (NULL); /* means failed */
	}

	create_new->next = NULL;
	create_new->prev = NULL;
	create_new->n = n;

	return (create_new);
}

/**
 * freeing_nodememory - Functin that frees a list.
 *
 */

void freeing_nodememory(void)
{
	stack_t *tempo_p = head;

	while (tempo_p != NULL)
	{
		stack_t *next = tempo_p->next;

		free(tempo_p);
		tempo_p = next;
	}
}

