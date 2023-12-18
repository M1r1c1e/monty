#include "monty.h"

stack_t *head = NULL;

/**
 * main - the program entry point
 * @argc: comandline of argument
 * @argv: a string array of command-line argument
 *
 * Return: always 0.
 */

int main(int argc, char **argv)
{
	if (argc != 2)
		error_mes(1);
	to_openfile(argv[1]);
	freeing_nodememory();
	return (0);
}
