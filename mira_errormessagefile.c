#include "monty.h"
#include <stdarg.h>
/**
 * error_mes - Printing the error messages for monty program
 * @proerror_arg: list the proerror_arg
 */
void error_mes(unsigned int proerror_arg, ...)
{
	va_list ag;
	char *stropcode;
	unsigned int line_counter;

	va_start(ag, proerror_arg);

	switch (proerror_arg)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			line_counter = va_arg(ag, unsigned int);
			stropcode = va_arg(ag, char *);
			fprintf(stderr, "L%u: unknown instruction %s\n", line_counter, stropcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%u: usage: push integer\n", va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	freeing_nodememory();
	exit(EXIT_FAILURE);
}

