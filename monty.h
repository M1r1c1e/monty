#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
}	stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
}	instruction_t;

extern stack_t *head;

typedef void (*operation_func)(stack_t **, unsigned int);
void pall(stack_t **prog_stack, unsigned int line_counter);
void push(stack_t **creatednode, unsigned int line_counter);
stack_t *creatednode(int n);
void freeing_nodememory(void);
void error_mes(unsigned int proerror_arg, ...);
void func_perform(operation_func f, char *opcode, char *comd,
		int line_counter, int fomat_spercifer);
void progfunction(char *opcode, char *comd,
		int line_counter, int fomat_spercifer);
void queue(stack_t **creatednode, unsigned int line_counter);
void to_openfile(char *Fname);
void readprogfile(FILE *KF);
int int_line(char *PROstring, int line_counter, int fomat_spercifer);
int main(int argc, char **argv);


#endif
